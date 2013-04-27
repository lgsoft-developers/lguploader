#ifndef guBookUploader_h
#define guBookUploader_h

#include <QObject>
#include <QQueue>
#include "dataStructures.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QByteArray>
#include <QQueue>
#include <QtXml>

class uploadEbookReply : public QObject
{
    Q_OBJECT
public:
    uploadEbookReply(QNetworkReply *reply, QString MD5, QObject * parent = 0 );
private:
    QNetworkReply *reply;
    QString MD5;
public slots:
    void onUploadProgress(qint64 bytesSent, qint64 bytesTotal);
signals:
    void onUploadEbookProcess(QString MD5, int percent);
};

class guBookUploader : public QObject
{
Q_OBJECT
public:
    explicit guBookUploader(QObject *parent = 0);
    void uploadEbook(ebook upBook);
    void setNumOfSimultaneouslyUpload(int num);
    int getQueueSize();
    void setServiceUrl(QString serviceUrl);
    void setAuthInfo(QString user, QString password);

signals:
    void ebookUploadProcess(QString MD5ofUpload, int percent);
    void uploadEbookFinished(QString MD5ofUploaded);
    void uploadEbookError(QString MD5ofUploaded, int error);
    void allEbooksUploaded();
    //TODO: добавить/изменить сигнал о том, что закачка провалилась
public slots:

    void uplEbookFromQueue();
    void processUploadEbookReply(QNetworkReply* reply);
    void onUploadProgress( QString MD5,int percent);

private:
    //функции для формирования xml запросов к серверу
    void  appendDomParam(QDomDocument *document ,QDomElement *element, QString type, QVariant value);
    QString getEbookInfoXML(QString MD5); //запрос информации о книге
    QString sendEbookInfoXML(ebook uploadEbook); //отправка информации о книге для ее загрузки
    void uploadEbookData(ebook uploadEbook);
    void uploadEbookDataOld(ebook uploadEbook);
    QQueue<ebook> uploadQueue;
    QByteArray strToEnc(QString s, QString encodingS);
    //network related
    QNetworkAccessManager *httpUploadFilesManager;
    QString user;              //имя пользователя для сервиса
    QString password;          //пароль для сервиса
    QString serviceUrl;        //адрес сервиса для загрузки книги
    int     maxUploadFileSize; //максимально возможный размер для загрузки


    ebook uplEbook;            //временная - загружаемая книга

    QQueue<ebook> queue;       //очередь загружаемых файлов
    int queueSize;             //размер очереди загружаемых файлов (не используется)
    int numOfSimultaneouslyUpload; //настройка - количество одновременно загружаемых (не используется)

};

#endif // guBookUploader_h
