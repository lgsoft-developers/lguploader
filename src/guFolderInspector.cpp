#include "guFolderInspector.h"
#include <QCoreApplication>
#include <QDirIterator>
#include <QByteArray>
#include <QCryptographicHash>
#include "isbnMethods.h"
guFolderInspector::guFolderInspector()
{
    //первоначальна€ инициализаци€ (защита от дурака)
    toSearchInSubFolders = true;
    nameFilters << "*.pdf" << "*.chm" << "*.djvu";
    searchPath = qApp->applicationDirPath();
    dbFilePath = qApp->applicationDirPath() +"/"+"gu.sqlite";
    checkFromLibGen = false;
    terminate = false;
    if (QFile::exists(dbFilePath))
    {
        open(dbFilePath);\
            }
    else
    {
        open(dbFilePath);
        initDb();
    }
    libGenDb = QSqlDatabase::database("libGenDB");
    if(libGenDb.isValid())
    {
        if(!libGenDb.isOpen())
        {

            if(libGenDb.open()){checkFromLibGen = true;}
            else               {checkFromLibGen = false;}
        }
        else
        {
            checkFromLibGen = true;
        }
    }
}
guFolderInspector::~guFolderInspector()
{
    if(db.isOpen())
        db.close();

}
bool guFolderInspector::initDb()
{
    QSqlQuery createQuery(db);
    QFile file(":/sql/sql/createDb.sql");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;
    QString queryText = file.readAll();
    //qDebug() << queryText;
    QStringList queryList = queryText.split("|");
    for ( int i = 0 ; i < queryList.count() ; i++)
    {
        //qDebug() << queryList.at(i);
        createQuery.exec( queryList.at(i));
    }
    file.close();
    return true;
}
void guFolderInspector::onAbortInspect()
{
    //this->terminate();
    //or try
    terminate = true;

}

bool guFolderInspector::inLib(QString MD5)
{
    //провер€ем в бд-кеш на то, есть ли така€ запись с MD5 и присутствует ли она в библиотеке
    QSqlQuery query(db);
    query.prepare("SELECT MD5 FROM ebooks WHERE MD5 = :MD5 AND inLib = :inLib;");
    query.bindValue(":MD5", MD5);
    query.bindValue(":inLib", 1);
    query.exec();
    if (query.first()) //если есть, то просто возвращаем true
    {
        //qDebug() << "in cache db";
        return true;//query.value(0).toString()
    }
    else //если нет, то готовим запрос на добавление инфо в нашу бд
    {
        QSqlQuery addMD5query(db);
        addMD5query.prepare("INSERT INTO ebooks (MD5, inLib) VALUES (:MD5, :inLib);");
        addMD5query.bindValue(":MD5", MD5);
        //но дл€ начала узнаем, есть ли в бд либгена
        if(checkFromLibGen) //(если она конечно же есть)
        {
            if(inLibGen(MD5)) //если она есть в либгене
            {
                addMD5query.bindValue(":inLib", 1); //то установим признак того, что она в либгене
                addMD5query.exec();
                return true;
            }
            else
            {
                addMD5query.bindValue(":inLib", 0); //признак того, что ее там нет
                addMD5query.exec();
                return false;
            }
        }
        else //если в либгене не провер€ем, то будем считать, что ее нет в либгене
        {
            addMD5query.bindValue(":inLib", 0); //признак того, что ее там нет
            addMD5query.exec();
            return false;
        } 
    }
}
bool guFolderInspector::inLibGen(QString MD5)
{

    QSqlQuery checkQuery(libGenDb);
    checkQuery.prepare("SELECT ID from updated WHERE MD5 = :MD5;");
    checkQuery.bindValue(":MD5", MD5);
    checkQuery.exec();
    if (checkQuery.first()) //если запись обнаружена
    {
        return true;
    }else
    {
        return false;
    }
}

bool guFolderInspector::open(QString filepath)
{
    db = QSqlDatabase::addDatabase("QSQLITE", "main");
    db.setDatabaseName(dbFilePath);
    //db.setConnectOptions("QSQLITE_BUSY_TIMEOUT"
    //QSqlQuery query(db);

    if (db.open())
    {
        //query.exec("PRAGMA temp_store = 1;");
        return true;
    }
    else
    {
        return false;
    }
}
void guFolderInspector::onSetDbFilePath( QString databaseFilePath)
{
    dbFilePath = databaseFilePath;
}
void guFolderInspector::onSetNameFilters(QStringList fileNameFilters)
{
    nameFilters = fileNameFilters;
}
void guFolderInspector::onSetSearchDirectory(QString searchPathStr)
{
    searchPath = searchPathStr;
}
void guFolderInspector::onSetSearchInSubdirs(bool toSearch)
{
    toSearchInSubFolders = toSearch;
}
void guFolderInspector::extractIsbnsFromDjvu(QString fileName, QList<QString> &ISBNList)
{
    ctx = ddjvu_context_create("lgUploader"); //ddjvu_document_create_by_filename
    doc = ddjvu_document_create_by_filename_utf8(ctx, fileName.toUtf8(), 1);
    while (! ddjvu_document_decoding_done(doc));
    int  numOfPages = ddjvu_document_get_pagenum(doc); //количество страниц - строго!
    //QByteArray b = QFile::encodeName(fileName);
    //doc = ddjvu_document_create_by_filename(ctx, b, 1);
    if(!doc)
        qDebug() << "error create doc";
    if(!ctx)
        qDebug() << "error create context";


    const char *lvl = "page";
    //начало перебора по страницам
    isbnMethods find;
    int numOfSearchPages = 15;
    //qDebug() << "num of pages " << numOfPages;
    if(numOfPages < numOfSearchPages)
    {
        numOfSearchPages = numOfPages;
    }
    for (int pageCount = 0 ; pageCount < numOfSearchPages ; pageCount++)
    {

        miniexp_t r = miniexp_nil;
        while ((r = ddjvu_document_get_pagetext(doc, pageCount ,lvl))==miniexp_dummy);
        r = miniexp_nth(5, r);
        //if ( r == miniexp_nil )
        //    qDebug() << "r = null";
        const char *pageDumpArr = miniexp_to_str( r );
        QString pageDump( QString::fromUtf8( pageDumpArr ));

        find.findIsbns(pageDump, ISBNList);

        //qDebug() << fileName << " content: \n" <<  pageDump ;
    }
    //конец перебора по страницам
    if (doc)
        ddjvu_document_release(doc); //освобождаем контекст документа
    if (ctx)
        ddjvu_context_release(ctx); //освобождаем контескт приложени€ (возможно стоит оставить)

}
void guFolderInspector::extractIsbnsFromChm(QString fileName, QList<QString> &ISBNList)
{
    chmFileImpl = new LCHMFileImpl();
    bool ok = chmFileImpl->loadFile( fileName );

    QString fileContent;
    QStringList files;
    //chmFileImpl->enumerateFiles(&files);
    //for (int i = 0 ; i < files.count() ; i++)
    //{
        //qDebug() << files.at(i);
    //}
    chmFileImpl->getFileContentAsString(&fileContent, chmFileImpl->homeUrl() ); // //"/LiB0006.htm"
    isbnMethods find;
    find.findIsbns(fileContent, ISBNList);
    //qDebug() << "loaded " << ok << chmFileImpl->homeUrl() << " content\n" << ba;
    chmFileImpl->closeAll();
    delete chmFileImpl;

}
void guFolderInspector::extractIsbnsFromPdf(QString fileName, QList<QString> &ISBNList)
{
    //PDFDoc *doc;
    //doc = new PDFDoc()
    //qDebug() << "file:" << fileName;
    Poppler::Document* document;
    document = Poppler::Document::load(fileName,0,0);


    //Poppler::Document::
    if (!document || document->isLocked()) {

        // ... error message ....
        delete document;
        return;
    }
    // Paranoid safety check
    if (!document) {
        // ... error message ...
        return;
    }

    Poppler::Page* pdfPage;
    isbnMethods find;

    // Access page of the PDF file
    int numOfPages = document->numPages(); //количество страниц
    int numOfSearchPages = 15;
    //qDebug() << "num of pages " << numOfPages;
    if(numOfPages < numOfSearchPages)
    {
        numOfSearchPages = numOfPages;
    }
    for ( int pageNumber = 0 ; pageNumber < numOfSearchPages ; pageNumber++)
    {
        pdfPage = document->page(pageNumber);  // Document starts at page 0
        if (!pdfPage) {
            // ... error message ...
            continue;
        }

        //QtMsgHandler qInstallMsgHandler ( QtMsgHandler handler )
        QString pageContent;
        pageContent = pdfPage->text(QRectF(QPointF(0,0),pdfPage->pageSizeF()));

        find.findIsbns(pageContent, ISBNList);

        // ... use image ...
        //qDebug() << pageContent;
    }

    // after the usage, the page must be deleted
    delete pdfPage;

    //Finally, don't forget to destroy the document:

    delete document;
}

void guFolderInspector::extractIsbnsFromFile(QString fileName, QList<QString> &ISBNList, QString type)
{
    if (type == "djvu")
    {
        extractIsbnsFromDjvu(fileName, ISBNList);
    }else if(type == "pdf")
    {
        extractIsbnsFromPdf(fileName, ISBNList);

    }else if(type == "chm")
    {
        extractIsbnsFromChm(fileName, ISBNList);
    }
}
void guFolderInspector::inspectFolder(QString path, QStringList searchFileExtensions,
                                      bool searchInSubFolders,
                                      bool extractIdentifiersFromFiles,
                                      bool extractIdentifiersFromFileNames)
{
    searchPath = path;
    toSearchInSubFolders = searchInSubFolders;
    nameFilters = searchFileExtensions;
    toExtractIdentifiersFromFiles = extractIdentifiersFromFiles;
    toExtractIdentifiersFromFileNames = extractIdentifiersFromFileNames;
    //qDebug() << "sub " <<searchInSubFolders << " from files " << toExtractIdentifiersFromFiles << " from file names " << toExtractIdentifiersFromFileNames;
    if (!isRunning())
    {
        start(NormalPriority);//LowPriority
    }

}

void guFolderInspector::run()
{
    isbnMethods isbnExtractor;
    QDirIterator::IteratorFlag flag;
    if (toSearchInSubFolders)
        flag = QDirIterator::Subdirectories;
    else
        flag = QDirIterator::NoIteratorFlags;

    QDirIterator it(searchPath,nameFilters, QDir::Files, flag);
    while (it.hasNext())
    {
        if(terminate)
        {
            emit inspectFinished();
            terminate = false;
            return;
        }
        it.next();
        QString filePath = it.filePath();
        QFile hashedFile(filePath);
        if (!hashedFile.open(QIODevice::ReadOnly))
            continue;
        QByteArray hashedData = hashedFile.readAll();
        hashedFile.close();
        QByteArray hashData;
        hashData = QCryptographicHash::hash( hashedData, QCryptographicHash::Md5);
        QString hashString(hashData.toHex());
        hashedData.clear();
        hashData.clear();
        ebook newEbook;
        newEbook.inLib = false;
        newEbook.inLibChecked = false;

        newEbook.fileName = it.fileName();

        if(toExtractIdentifiersFromFileNames) //если указоно, то
        {    //ищем ISBNы в имени файла
            isbnExtractor.findIsbns(newEbook.fileName, newEbook.ISBNs);
        }
        //убираем точку в конце файла и точки внутри замен€ем пробелами
        newEbook.fileExtension = it.fileInfo().suffix();
        //убираем расширение и точку
        newEbook.fileName = newEbook.fileName.left(newEbook.fileName.length() - newEbook.fileExtension.length() - 1);

        //по умолчанию заголовок - это им€ файла
        newEbook.title = newEbook.fileName.replace(".", " ");
        newEbook.title = newEbook.title.replace("_"," ");

        newEbook.filePath = filePath;

        if (toExtractIdentifiersFromFiles) //если указано, то
        {//ищем »—ЅЌы из самих файлов
            extractIsbnsFromFile(newEbook.filePath, newEbook.ISBNs, newEbook.fileExtension);
        }

        newEbook.fileSize = it.fileInfo().size();
        newEbook.inLibCheckSended = false;
        newEbook.categoryManualSetted = false;
        newEbook.inLibChecked = false;
        newEbook.inLib = false;
        newEbook.biblioSetted = false;
        newEbook.uploaded = false;
        newEbook.catogorySubjectSetted = false;

        newEbook.pubYear = 0;
        newEbook.pageNum = 0;
        newEbook.orientation = 0;
        newEbook.scanDpi = 0;
        newEbook.scanColor = 0;
        newEbook.scanCleaned = 0;

        newEbook.categoryTreeSetted = false;
        newEbook.MD5 = hashString;
        emit addNewEbook(hashString, newEbook);

    }
    emit inspectFinished();
    return;
    //exec();
}
