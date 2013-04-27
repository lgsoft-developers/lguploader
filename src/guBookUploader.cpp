#include "guBookUploader.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QByteArray>
#include <QFile>
#include <QString>
#include <QUrl>
#include <QAuthenticator>
#include <QDebug>
#include <QDateTime>
#include <QCoreApplication>
#include <QTime>
#include <QtXml>
#include <QMessageBox>


////////////////////////////////////////////////////////////////////////////////
//                      CLASS uploadEbookReply
////////////////////////////////////////////////////////////////////////////////
uploadEbookReply::uploadEbookReply( QNetworkReply *reply, QString MD5, QObject *parent) : QObject(parent)
{
    this->reply = reply;
    this->MD5 = MD5;
    connect(this->reply, SIGNAL(uploadProgress(qint64,qint64)), this, SLOT(onUploadProgress(qint64,qint64)));
    //connect(this->reply, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
    //connect(this->reply, SIGNAL(aboutToClose()), this, SLOT(slotAboutToClose()));
}
void uploadEbookReply::onUploadProgress(qint64 bytesSent, qint64 bytesTotal)
{
    int percent = (bytesSent * 100)/bytesTotal;
    emit onUploadEbookProcess(MD5, percent);
}
////////////////////////////////////////////////////////////////////////////////
//                       CLASS guBookUploader
////////////////////////////////////////////////////////////////////////////////
guBookUploader::guBookUploader(QObject *parent) :
        QObject(parent)
{
    httpUploadFilesManager = new QNetworkAccessManager(this);
    connect(this->httpUploadFilesManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(processUploadEbookReply(QNetworkReply*)));
    maxUploadFileSize = 200000000;
}
void guBookUploader::onUploadProgress( QString MD5,int percent)
{
    emit ebookUploadProcess(MD5, percent);
}
void guBookUploader::setNumOfSimultaneouslyUpload(int num)
{

}
int guBookUploader::getQueueSize()
{
    return 1;
}
void guBookUploader::setServiceUrl(QString url)
{
    serviceUrl = url;
}
void guBookUploader::setAuthInfo(QString user, QString password)
{
    this->user = user;
    this->password = password;
}
//1. Начало загрузки - посылаем запрос на аутентификацию
void guBookUploader::uplEbookFromQueue()
{
    if(uploadQueue.isEmpty())
    {
        //испустить сигнал о том, что очередь пуста
        emit allEbooksUploaded();
        return;//и уйти

    }
    uplEbook = uploadQueue.head();
    uploadEbookData(this->uplEbook);
}
void guBookUploader::uploadEbook(ebook ebookToUpload)
{
    if(!uploadQueue.isEmpty()) //если очередь не пуста
    {
        uploadQueue.enqueue(ebookToUpload); //то только помещаем в очередь
    }
    else //если же очередь заполнена
    {
        uploadQueue.enqueue(ebookToUpload); //помещаем в очередь
        uplEbookFromQueue(); //и начинаем загружать из очереди
    }
}
//3. общий слот обработки ответов
void guBookUploader::processUploadEbookReply(QNetworkReply* reply)
{
    //1. получаем MD5 ответа
    QString MD5ofRequest = reply->property("MD5").toString(); //извлечение MD5
    //проверка на ошибку
    if (reply->error())
    {
        QMessageBox msgBox;
        msgBox.setText(tr("Network error upload ebook: ") +
                       reply->errorString());
        msgBox.exec();
        //отправить сигнал о том, что загрузка MD5ofRequest провалилась
        qDebug() << "error " << reply->errorString();
        reply->close();
        reply->deleteLater();
        return;
    }
    //2. создаем объект xml ответа
    QDomDocument doc("LGWS");
    //3. пробуем установить контент из ответа
    QString errMsg;
    int errorLine, errorColumn;
    if(!doc.setContent(reply, &errMsg, &errorLine, &errorColumn))
    {
        QMessageBox msgBox;
        msgBox.setText(tr("Error while parsing xml:") +
                       errMsg + tr(" in line ") +
                       QString::number(errorLine) + tr(" column ") +
                       QString::number(errorColumn));
        msgBox.exec();
    }
    //проверка ошибок в ответе
    QDomElement domRequest = doc.documentElement();
    QString replyType = domRequest.attribute("type");
    if (replyType == "error")
    {
        QMessageBox msgBox;
        msgBox.setText(tr("Error while uploading:") +
                       domRequest.attribute("code"));
        msgBox.exec();
    }
    //закрываем ответ и удаляем
    reply->close();
    reply->deleteLater();
    //посылаем сигнал о том, что книга успешно загружена с кодом возврата
    //0 ошибка
    //1 загружено и информация установлена
    //2 уже присутствует
    emit uploadEbookFinished(MD5ofRequest);
    uploadQueue.dequeue();    //убираем из очереди
    uplEbookFromQueue();      //загружаем остальные
    return;
}
void  guBookUploader::appendDomParam(QDomDocument *document ,QDomElement *element, QString type, QVariant valueVar)
{
    QString value = valueVar.toString();
    if (value.isEmpty()) //если конвертнуть не удалось, или пустой параметр, то параметр не добавляем
        return;
    QDomElement param = document->createElement(type);
    QDomText paramValue = document->createTextNode(value);
    param.appendChild(paramValue);
    element->appendChild(param);
    //QDomCDATASection QDomDocument::createCDATASection ( const QString & value )
}

QString guBookUploader::sendEbookInfoXML(ebook Ebook) //отправка информации о книге для ее загрузки
{
    //Common rules
    //1. если поле пустое, то оно не отсылается
    //2. если значение не валидное, то оно не отсылается (для интовых)
    //form xml
    QDomDocument doc;
    QDomElement root = doc.createElement("request");
    root.setAttribute("md5", Ebook.MD5);
    if(Ebook.inLib)
    {
        root.setAttribute("type", "edit");
    }
    else
    {
        root.setAttribute("type", "upload");
        root.setAttribute("ext", Ebook.fileExtension);
        root.setAttribute("size", Ebook.fileSize);
    }



    doc.appendChild(root);
    //аутентификация
    QDomElement Auth = doc.createElement("auth");
    Auth.setAttribute("user", "upload");
    Auth.setAttribute("pass", "genesis");
    root.appendChild(Auth);
    //Идентификаторы
    QDomElement Identifiers = doc.createElement("identifiers");
    root.appendChild(Identifiers);
    for (int i = 0 ; i < Ebook.ISBNs.count() ; i++)
    {
        QDomElement Identifier = doc.createElement("identifier");
        QString type;
        if(uplEbook.ISBNs.at(i).length() == 10)
            type = "ISBN10";
        if(uplEbook.ISBNs.at(i).length() == 13)
            type = "ISBN13";
        Identifier.setAttribute("type", type);
        Identifier.setAttribute("value", uplEbook.ISBNs.at(i));
        Identifiers.appendChild(Identifier);
    }
    //Прочие параметры
    appendDomParam(&doc ,&root, "title", Ebook.title);
    appendDomParam(&doc ,&root, "year", Ebook.pubYear);
    appendDomParam(&doc ,&root, "publisher", Ebook.publisher);
    appendDomParam(&doc ,&root, "topic", Ebook.category);
    appendDomParam(&doc ,&root, "author", Ebook.authors);
    appendDomParam(&doc ,&root, "volume", Ebook.volume);
    appendDomParam(&doc ,&root, "edition", Ebook.issue);
    appendDomParam(&doc ,&root, "series", Ebook.series);
    appendDomParam(&doc ,&root, "city", Ebook.sity);
    appendDomParam(&doc ,&root, "coverUrl", Ebook.coverUrl);
    appendDomParam(&doc ,&root, "periodical", Ebook.periodical);
    appendDomParam(&doc ,&root, "pages", Ebook.pageNum);
    appendDomParam(&doc ,&root, "language", Ebook.language);
    appendDomParam(&doc ,&root, "collection", Ebook.collection);
    appendDomParam(&doc ,&root, "issue", Ebook.collectionIssue);
    appendDomParam(&doc ,&root, "orientation", Ebook.orientation);
    appendDomParam(&doc ,&root, "dpi", Ebook.scanDpi);
    appendDomParam(&doc ,&root, "color", Ebook.scanColor);
    appendDomParam(&doc ,&root, "cleaned", Ebook.scanCleaned);
    appendDomParam(&doc ,&root, "comment", Ebook.commentary);
    appendDomParam(&doc ,&root, "description", Ebook.description);
    appendDomParam(&doc ,&root, "UDC", Ebook.UDC);
    appendDomParam(&doc ,&root, "LBC", Ebook.BBC);
    appendDomParam(&doc ,&root, "ASIN", Ebook.ASIN);

    //end form xml and output as string
    return  doc.toString();//"<?xml version=\"1.0\" encoding=\"UTF-8\"?>" +
}
//загрузка файла
void guBookUploader::uploadEbookData(ebook uploadEbook)
{
    QString uploadedMd5 = uploadEbook.MD5;
    //test
    serviceUrl = "http://localhost/lgws/service.php";
    QNetworkRequest *uploadEbookRequest;
    //TODO: вести лог
    uploadEbookRequest = new QNetworkRequest(QUrl(serviceUrl));
    QByteArray fileToSend; // byte array to be sent in POST
    if(!uploadEbook.inLib)
    {
        QFile uploadFile(uploadEbook.filePath);
        if (!uploadFile.open(QIODevice::ReadOnly))
        {
            //TODO: дать сигнал о том, что закачка провалилась так как не удалось открыть файл
            return;
        }

        fileToSend = uploadFile.readAll();
        uploadFile.close(); //расскомментировать
    }

    ////////////////////начало кода, взятого из "formpost"
    QString encodingS;
    encodingS = "utf-8";
    QString userAgentS;
    QString refererS;
    QStringList fieldNames;
    QStringList fieldValues;
    QStringList fileFieldNames;
    QStringList fileNames;
    QStringList fileMimes;
    QList<QByteArray> files;

    fieldNames << "xml";
    fieldValues << sendEbookInfoXML(uploadEbook);


    if(!uploadEbook.inLib)
    {
        fieldNames << "MAX_FILE_SIZE";
        fieldValues << QString::number(maxUploadFileSize);

        fileFieldNames << "uploadedfile";
        fileNames << uploadEbook.fileName +"."+ uploadEbook.fileExtension;

        fileMimes << "application/octet-stream";
        files << fileToSend;
    }
    QString crlf="\r\n";
    qsrand(QDateTime::currentDateTime().toTime_t());
    QString b=QVariant(qrand()).toString()+QVariant(qrand()).toString()+QVariant(qrand()).toString();
    QString boundary="---------------------------"+b;
    QString endBoundary=crlf+"--"+boundary+"--"+crlf;
    QString contentType="multipart/form-data; boundary="+boundary;
    boundary="--"+boundary+crlf;
    QByteArray bond=boundary.toAscii();
    QByteArray send;
    bool first=true;
    for (int i=0; i<fieldNames.size(); i++) {
        send.append(bond);
        if (first) {
            boundary=crlf+boundary;
            bond=boundary.toAscii();
            first=false;
        }
        send.append(QString("Content-Disposition: form-data; name=\""+fieldNames.at(i)+"\""+crlf).toAscii());
        if (encodingS=="utf-8") send.append(QString("Content-Transfer-Encoding: 8bit"+crlf).toAscii());
        send.append(crlf.toAscii());
        send.append(strToEnc(fieldValues.at(i),encodingS));
    }
    for (int i=0; i<files.size(); i++) {
        send.append(bond);
        send.append(QString("Content-Disposition: form-data; name=\""+fileFieldNames.at(i)+"\"; filename=\""+fileNames.at(i)+"\""+crlf).toAscii());
        send.append(QString("Content-Type: "+fileMimes.at(i)+crlf+crlf).toAscii());
        send.append(files.at(i));
    }

    send.append(endBoundary.toAscii());
    uploadEbookRequest->setHeader(QNetworkRequest::ContentLengthHeader, QVariant(send.size()).toString());
    uploadEbookRequest->setHeader(QNetworkRequest::ContentTypeHeader, contentType.toAscii());
    uploadEbookRequest->setRawHeader("Accept","text/html,text/xml,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
    uploadEbookRequest->setRawHeader("Accept-Charset","windows-1251,utf-8;q=0.7,*;q=0.7");
    uploadEbookRequest->setRawHeader("Accept-Encoding", "gzip,deflate");//,qcompress
    uploadEbookRequest->setRawHeader("Authorization", "Basic " + QByteArray(QString("%1:%2").arg("genesis").arg("upload").toAscii()).toBase64());

    uploadEbookRequest->setRawHeader("Connection","keep-alive");
    uploadEbookRequest->setRawHeader("Keep-Alive","115");
    uploadEbookRequest->setRawHeader("User-Agent","Mozilla/5.0 (Windows; U; Windows NT 6.1; ru; rv:1.9.2) Gecko/20100115 Firefox/3.6");
    QString host("free-books.dontexist.org");
    uploadEbookRequest->setRawHeader("Host",host.toAscii());
    uploadEbookRequest->setRawHeader("Referer","http://free-books.dontexist.com/librarian/");

    uploadEbookReply  *uplEbookReplyManager;
    QNetworkReply  *uplEbookReply;

    //    QFile file("out.txt");
    //        if (!file.open(QIODevice::WriteOnly))
    //            return;
    //        file.write(send);
    //        file.close();
    uplEbookReply = httpUploadFilesManager->post(*uploadEbookRequest, send);
    //send.clear();
    uplEbookReplyManager = new uploadEbookReply(uplEbookReply , uploadedMd5, this);
    connect(uplEbookReplyManager, SIGNAL(onUploadEbookProcess(QString,int)), this, SLOT(onUploadProgress(QString,int)));
    //log(uploadEbookRequest->rawHeaderList());
    uplEbookReply->setProperty("MD5",uploadedMd5);
    qDebug() << "MD5 setted";
    if(uploadEbook.inLib)
    {
         uplEbookReply->setProperty("type", "edit");
    }
    else
    {
         uplEbookReply->setProperty("type", "upload");
    }

    // // connections
    //connect(reply,SIGNAL(uploadProgress(qint64,qint64)),SLOT(mySetValue(qint64,qint64)));
    //connect(reply,SIGNAL(finished()),SLOT(replyFinished())); // reply finished - close file
    //fillBibliographyReply->setProperty("dataSource",dataSource);
    //numOfFillBibliographyConnections++;
}
QByteArray guBookUploader::strToEnc(QString s, QString encodingS) {
    if (encodingS=="utf-8") {
        return s.toUtf8();
    } else {
        return s.toAscii();
    }
}
