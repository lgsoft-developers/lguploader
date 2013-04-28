#include "guMainWindow.h"
#include "ui_guMainWindow.h"
#include <QDebug>
#include <QFile>
#include <QCryptographicHash>
#include <QByteArray>
#include <QDirIterator>
#include <QStringList>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObjectUserData>
#include <QSettings>
#include <QMetaType>
#include <QTextCodec>
#include <QRectF>
#include <QtXml>
#include <QTreeWidgetItemIterator>
#include <QAuthenticator>
#include <QIcon>
#include <QPixmap>
#include <QDesktopServices>
#include <QMessageBox>
#include <QtPlugin>
#include <QDateTime>
#include <QApplication>
#include <QClipboard>
#include "guSettDialog.h"
#include "isbnMethods.h"
#include "guAboutDialog.h"
#include "guBookTreeItem.h"
#include "guFindBookFilesDialog.h"
#include <QDir>
//#define TEST


guMainWindow::guMainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::guMainWindow)
{
    qRegisterMetaType<ebook>("ebook"); //регистрируем тип "ebook" для передачи его в сигналах/слотах
    uploader = new guBookUploader(this);
    initBaseSettings(); //первым делом загрузим настройки приложения
    logger = new guLogger("log.txt");

    //toSearchInSubFolders = true;
    //inspectOnStartUp = true;
    //logFile = new QFile("log.txt");
    //logFile->open(QIODevice::WriteOnly);
    processTimer = new QTimer(this);
    connect(processTimer, SIGNAL(timeout()),this, SLOT(onTimerTimeout()));
    inspector = new guFolderInspector();

    connect(inspector, SIGNAL(addNewEbook(QString,ebook)), this, SLOT(onAddNewEbook(QString,ebook)));
    connect(inspector, SIGNAL(dublicateFinded()), this, SLOT(onDublicateFinded()));
    connect(inspector, SIGNAL(inspectFinished()), this, SLOT(onInspectFinished()));
    connect(this, SIGNAL(abortInspectProcess()), inspector, SLOT(onAbortInspect()));


    ui->setupUi(this);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));
    ui->treeWidgetFiles->setIndentation(0);
    numOfCheckDublicateConnections = 0;
    numOfFillBibliographyConnections = 0;
    numOfUploaded = 0;


    connect(uploader, SIGNAL(ebookUploadProcess(QString,int)), this, SLOT(onUploadEbookProgress(QString,int)));
    connect(uploader, SIGNAL(uploadEbookFinished(QString)), this, SLOT(onUploadEbookFinished(QString)));
    connect(uploader, SIGNAL(allEbooksUploaded()), this, SLOT(onAllEbooksUploaded()));

    httpCheckDublicatesManager = new QNetworkAccessManager(this);
    connect(httpCheckDublicatesManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(processCheckDublicateReply(QNetworkReply*)));
    httpFillBibliographyManager = new QNetworkAccessManager(this);
    connect(httpFillBibliographyManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(processFillBibliographyReply(QNetworkReply*)));

    coverLoaderManager = new QNetworkAccessManager(this);

    connect(coverLoaderManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(processLoadCoverReply(QNetworkReply*)));

    ui->treeWidgetCategories->setCurrentItem(ui->treeWidgetCategories->topLevelItem(0));

    connect(ui->treeWidgetFiles , SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)), this, SLOT(onCurrentFileChanged(QTreeWidgetItem*,QTreeWidgetItem*)));
    connect(ui->treeWidgetFiles, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), this , SLOT(onFilesTreeDoubleClicked(QTreeWidgetItem*,int)));
    connect(ui->treeWidgetCategories , SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)), this, SLOT(onCurrentCategoryChanged(QTreeWidgetItem*,QTreeWidgetItem*)));
    connect(ui->treeWidgetCategories , SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)), this, SLOT(onCurrentCategoryChangedFillStr(QTreeWidgetItem*,QTreeWidgetItem*)));

    //connect ui signals
    connect(ui->actionInspectFolder, SIGNAL(triggered()), this, SLOT(onInspectFolder()));
    connect(ui->actionGetBiblioInfo, SIGNAL(triggered()), this, SLOT(onGetBiblioInfo()));
    connect(ui->actionUploadToServer, SIGNAL(triggered()), this, SLOT(onUploadToServer()));
    connect(ui->actionShowSettingsDialog, SIGNAL(triggered()), this, SLOT(onShowSettingsDialog()));
    connect(ui->actionSelectAllForUpload, SIGNAL(toggled(bool)), this, SLOT(onSelectAllToUploadToogled(bool)));

    connect(ui->actionToogleShowDublicates, SIGNAL(toggled(bool)), this, SLOT(onToogleShowDublicates(bool)));
    connect(ui->actionToogleShowWithISBN, SIGNAL(toggled(bool)), this, SLOT(onToogleShowWithISBN(bool)));
    connect(ui->actionToogleShowWithBibliography, SIGNAL(toggled(bool)), this, SLOT(onToogleShowWithBibliography(bool)));
    connect(ui->actionToogleShowUploaded, SIGNAL(toggled(bool)), this, SLOT(onToogleShowUploaded(bool)));
    connect(ui->actionAbortInspectProcess, SIGNAL(triggered()), this, SLOT(onAbortInspectProcess()));
    connect(ui->toolButtonCopyMD5toClipboard,SIGNAL(clicked()), this, SLOT(onCopyMD5ToClipboard()));
    //установка данных сразу для всех записей
    connect(ui->toolButtonSetForAllLibrary, SIGNAL(clicked()), this, SLOT(onSetLibraryForAllBooks()));
    connect(ui->toolButtonSetForAllLibraryIssue, SIGNAL(clicked()), this, SLOT(onSetLibraryIssueForAllBooks()));
    connect(ui->toolButtonSetForAllTitle, SIGNAL(clicked()), this, SLOT(onSetTitleForAllBooks()));
    connect(ui->toolButtonSetForAllAuthors, SIGNAL(clicked()), this, SLOT(onSetAuthorsForAllBooks()));
    connect(ui->toolButtonSetForAllSeries, SIGNAL(clicked()), this, SLOT(onSetSeriesForAllBooks()));
    connect(ui->toolButtonSetForAllPublisher, SIGNAL(clicked()), this, SLOT(onSetPublisherForAllBooks()));
    connect(ui->toolButtonSetForAllSity, SIGNAL(clicked()), this, SLOT(onSetSityForAllBooks()));
    connect(ui->toolButtonSetForAllPeriodical, SIGNAL(clicked()), this, SLOT(onSetPeriodicalForAllBooks()));
    connect(ui->toolButtonSetForAllUdc, SIGNAL(clicked()), this, SLOT(onSetUdcForAllBooks()));
    connect(ui->toolButtonSetForAllPubYear, SIGNAL(clicked()), this, SLOT(onSetPubYearForAllBooks()));
    connect(ui->toolButtonSetForAllBbc, SIGNAL(clicked()), this, SLOT(onSetBbcForAllBooks()));
    connect(ui->toolButtonSetForAllLanguage, SIGNAL(clicked()), this, SLOT(onSetLanguageForAllBooks()));
    connect(ui->toolButtonSetForAllOrientation, SIGNAL(clicked()), this, SLOT(onSetOrientationForAllBooks()));
    connect(ui->toolButtonSetForAllScanDpi, SIGNAL(clicked()), this, SLOT(onSetScanDpiForAllBooks()));
    connect(ui->toolButtonSetForAllColorScan, SIGNAL(clicked()), this, SLOT(onSetColorScanForAllBooks()));
    connect(ui->toolButtonSetForAllCleanScan, SIGNAL(clicked()), this, SLOT(onSetCleanScanForAllBooks()));

    connect(ui->toolButtonSetCategoryForAllBooks, SIGNAL(clicked()), this, SLOT(onSetCategoryForAllBooks()));

    connect(ui->toolButtonSetCommentForAllBooks, SIGNAL(clicked()), this, SLOT(onSetCommentaryForAllBooks()) );
    connect(ui->actionHelp, SIGNAL(triggered()), this, SLOT(onHelp()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(onShowAbout()));

    connect(ui->actionFileListLeft, SIGNAL(triggered()), this, SLOT(onFileListLeft()));
    connect(ui->actionFileListRight, SIGNAL(triggered()), this, SLOT(onFileListRight()));

    connect(ui->toolButtonGetBiblioForItem, SIGNAL(clicked()), this, SLOT(onGetBiblioForCurrentEbook()));

    //обработка ввода текста
    connect(ui->lineEditTitle, SIGNAL(textChanged(QString)), this, SLOT(onTitleTextChanged(QString)));
    connect(ui->lineEditAuthors, SIGNAL(textChanged(QString)), this, SLOT(onAuthorsTextChanged(QString)));
    connect(ui->lineEditSeries, SIGNAL(textChanged(QString)), this, SLOT(onSeriesTextChanged(QString)));
    connect(ui->lineEditPublisher, SIGNAL(textChanged(QString)), this, SLOT(onPublisherTextChanged(QString)));
    connect(ui->lineEditUDC, SIGNAL(textChanged(QString)), this, SLOT(onUdcTextChanged(QString)));
    connect(ui->lineEditBBC, SIGNAL(textChanged(QString)), this, SLOT(onBbcTextChanged(QString)));
    connect(ui->lineEditPubYear, SIGNAL(textChanged(QString)), this, SLOT(onPubYearTextChanged(QString)));
    connect(ui->lineEditPageNum, SIGNAL(textChanged(QString)), this, SLOT(onPageNumTextChanged(QString)));
    connect(ui->lineEditIssue, SIGNAL(textChanged(QString)), this, SLOT(onIssueTextChanged(QString)));
    connect(ui->lineEditVolume, SIGNAL(textChanged(QString)), this, SLOT(onVolumeTextChanged(QString)));
    connect(ui->lineEditSity, SIGNAL(textChanged(QString)), this, SLOT(onSityTextChanged(QString)));
    connect(ui->lineEditPeriodical, SIGNAL(textChanged(QString)), this, SLOT(onPeriodicalTextChanged(QString)));
    connect(ui->lineEditLanguage, SIGNAL(textChanged(QString)), this, SLOT(onLanguageTextChanged(QString)));
    connect(ui->textEditDescription, SIGNAL(textChanged()), this, SLOT(onDescriptionTextChanged()));
    connect(ui->lineEditCategory, SIGNAL(textChanged(QString)), this, SLOT(onCategoryTextChanged(QString)));
    connect(ui->lineEditCommentary, SIGNAL(textChanged(QString)), this, SLOT(onCommentaryTextChanged(QString)));
    connect(ui->listWidgetSubjects, SIGNAL(currentRowChanged(int)), this, SLOT(onSubjectIndexChanged(int)));


    //fin
    connect(ui->comboBoxOrientation, SIGNAL(currentIndexChanged (int)), this, SLOT(onOrientationIndexChanged(int)));

    connect(ui->lineEditBiblio, SIGNAL(textChanged(QString)), this, SLOT(onBiblioTextChanged(QString)));
    connect(ui->lineEditDpi, SIGNAL(textChanged(QString)), this, SLOT(onDpiTextChanged(QString)));
    connect(ui->lineEditDVDNum, SIGNAL(textChanged(QString)), this, SLOT(onDvdNumTextChanged(QString)));

    connect(ui->checkBoxColorScan, SIGNAL(stateChanged (int )), this, SLOT(onColorScanStateChanged(int)));
    connect(ui->checkBoxClearScan, SIGNAL(stateChanged (int )), this, SLOT(onClearScanStateChanged(int)));

    connect(ui->toolButtonSaveChanges, SIGNAL(clicked()), this, SLOT(onSaveChangesForBook()));
    connect(ui->toolButtonBookOpen, SIGNAL(clicked()), this, SLOT(onOpenCurrentEbook()));

    //обработка ввода ИСБН
    connect(ui->lineEditIsbn, SIGNAL(textChanged(QString)), this, SLOT(onIsbnFieldChanged(QString)));
    connect(ui->listWidgetISBNs, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onIsbnsListItemActivated()));
    connect(ui->toolButtonAddIsbn, SIGNAL(clicked()), this, SLOT(onAddIsbn()));
    connect(ui->toolButtonRemoveIsbn, SIGNAL(clicked()), this, SLOT(onRemoveIsbn()));
    //connect(&soap, SIGNAL(responseReady()), this, SLOT(onGetSoapResponse()));
    //TEST
    coverScene = new QGraphicsScene(this);
    graphicsView = new GraphicsViewEx(coverScene);

    //graphicsViewCover = new QGraphicsView(frame_3);graphicsView
    //graphicsView->setObjectName(QString::fromUtf8("graphicsViewCover"));
    graphicsView->setMinimumSize(QSize(100, 160));
    graphicsView->setMaximumSize(QSize(16777215, 16777215));
    graphicsView->setSizeIncrement(QSize(9, 9));
    graphicsView->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
    graphicsView->setFrameShape(QFrame::NoFrame);
    QBrush brush(QColor(0, 0, 0, 255));
    brush.setStyle(Qt::NoBrush);
    graphicsView->setBackgroundBrush(brush);

    ui->horizontalLayout->addWidget(graphicsView);

    //ui->graphicsViewCover->setScene(coverScene);
    QGraphicsPixmapItem *pixItem = graphicsView->scene()->addPixmap(QPixmap(":/icons/no_cover.jpg","JPG"));
    //coverScene->setSceneRect(0,0,100,160);//pixItem->boundingRect()
    //coverScene->setSceneRect(0,0,graphicsView->width(),graphicsView->height());
    //graphicsView->centerOn((QGraphicsItem*)pixItem);
    graphicsView->fitInView(pixItem,Qt::KeepAspectRatio);
    graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //testWebService();

    ui->treeWidgetFiles->setSortingEnabled(true);
    //coverScene->setSceneRect(graphicsView->rect());
    //еще нужно центрировать и скалировать

}
void guMainWindow::testWebService()
{
    //QtSoapMessage request;

       // Set the method and add one argument.
       //request.setMethod("getPeopleByFirstLastName", "urn:ExampleAPI");
       //request.addMethodArgument("first", "first", "j*");
       //request.addMethodArgument("last", "first", "*");
       //qDebug() << request.toXmlString(1);
       // Submit the request the the web service.
       //soap.setHost("free-books.dontexist.org");
       //soap.setAction("http://www.abundanttech.com/WebServices/Population/getPeopleByFirstLastName");
       //soap.submitRequest(request, "webService.php");


    //'http://free-books.dontexist.org/lgws.wsdl'
}
void guMainWindow::onGetSoapResponse()
{
    //const QtSoapMessage &message = soap.getResponse();
    //qDebug() << "error" << message.toXmlString(1);

        // Check if the response is a SOAP Fault message
        //if (message.isFault()) {
          //  qDebug("Error: %s", message.faultString().value().toString().toLatin1().constData());
        //}
        //else {
            // Get the return value, and print the result.
          //  const QtSoapType &response = message.returnValue();
            //qDebug() << " first " << response["first"].value().toString() << " last "<< response["last"].value().toString();
        //}

}

void guMainWindow::onFileListRight()
{
    //ui->dockWidgetDescription->move();
    //this->removeDockWidget(ui->dockWidgetDescription);
    ui->dockWidgetDescription->setFloating(false);
    this->addDockWidget(Qt::LeftDockWidgetArea, ui->dockWidgetDescription);

    //Qt::LeftDockWidgetArea	0x1
    //Qt::RightDockWidgetArea	0x2
    //Qt::TopDockWidgetArea	0x4
    //Qt::BottomDockWidgetArea	0x8
    //Qt::AllDockWidgetAreas	DockWidgetArea_Mask
    //Qt::NoDockWidgetArea	0
}
void guMainWindow::closeEvent(QCloseEvent *event)
 {
    QMessageBox msgBox;
     msgBox.setText(tr("Действительно хотите завершить работу?"));
     msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
     msgBox.setDefaultButton(QMessageBox::Cancel);
     int ret = msgBox.exec();
     if (ret == QMessageBox::Ok)
     {
         QMainWindow::closeEvent(event);
     }

 }
void guMainWindow::onFileListLeft()
{
    //this->removeDockWidget(ui->dockWidgetDescription);
    ui->dockWidgetDescription->setFloating(false);
    this->addDockWidget(Qt::RightDockWidgetArea, ui->dockWidgetDescription);


}
void guMainWindow::onSetCommentaryForAllBooks()
{
            if (MD52EbookMap.isEmpty())
                return;
            QMapIterator<QString, ebook> i(MD52EbookMap);
            while (i.hasNext()) {
                i.next();
                //если еще не загружено и если не в библиотеке
                if(!i.value().uploaded &&!i.value().inLib)
                {
                    MD52EbookMap[i.key()].commentary = ui->lineEditCommentary->text();
                }

            }
            MD52EbookMap[getMd5ofCurrentItem()].commentary = ui->lineEditCommentary->text();
}

//установка библиотеки-источника для всех книг
void guMainWindow::onSetLibraryForAllBooks()
{
    if (MD52EbookMap.isEmpty())
        return;
    QMapIterator<QString, ebook> i(MD52EbookMap);
    while (i.hasNext()) {
        i.next();
        //если еще не загружено и если не в библиотеке
        if(!i.value().uploaded &&!i.value().inLib)
        {
            MD52EbookMap[i.key()].collection = ui->lineEditBiblio->text();
        }

    }
    MD52EbookMap[getMd5ofCurrentItem()].collection = ui->lineEditBiblio->text();
}
//установка издания библиотеки для всех книг
void guMainWindow::onSetLibraryIssueForAllBooks()
{
    if (MD52EbookMap.isEmpty())
        return;
    QMapIterator<QString, ebook> i(MD52EbookMap);
    while (i.hasNext()) {
        i.next();
        //если еще не загружено и если не в библиотеке
        if(!i.value().uploaded &&!i.value().inLib)
        {
            MD52EbookMap[i.key()].collectionIssue =  ui->lineEditDVDNum->text();
        }

    }
    MD52EbookMap[getMd5ofCurrentItem()].collectionIssue =  ui->lineEditDVDNum->text();
}
//установка названия для всех книг
void guMainWindow::onSetTitleForAllBooks()
{
    if (MD52EbookMap.isEmpty())
        return;
    QMapIterator<QString, ebook> i(MD52EbookMap);
    while (i.hasNext()) {
        i.next();
        //если еще не загружено и если не в библиотеке
        if(!i.value().uploaded &&!i.value().inLib)
        {
            MD52EbookMap[i.key()].title =  ui->lineEditTitle->text();
        }

    }
    MD52EbookMap[getMd5ofCurrentItem()].title =  ui->lineEditTitle->text();
}
//установка авторов для всех книг
void guMainWindow::onSetAuthorsForAllBooks()
{
    if (MD52EbookMap.isEmpty())
        return;
    QMapIterator<QString, ebook> i(MD52EbookMap);
    while (i.hasNext()) {
        i.next();
        //если еще не загружено и если не в библиотеке
        if(!i.value().uploaded &&!i.value().inLib)
        {
            MD52EbookMap[i.key()].authors =  ui->lineEditAuthors->text();
        }

    }
    MD52EbookMap[getMd5ofCurrentItem()].authors =  ui->lineEditAuthors->text();
}
//установка серии для всех книг
void guMainWindow::onSetSeriesForAllBooks()
{
    if (MD52EbookMap.isEmpty())
        return;
    QMapIterator<QString, ebook> i(MD52EbookMap);
    while (i.hasNext()) {
        i.next();
        //если еще не загружено и если не в библиотеке
        if(!i.value().uploaded &&!i.value().inLib)
        {
            MD52EbookMap[i.key()].series =  ui->lineEditSeries->text();
        }

    }
    MD52EbookMap[getMd5ofCurrentItem()].series =  ui->lineEditSeries->text();
}
//установка издателя  для всех книг
void guMainWindow::onSetPublisherForAllBooks()
{
    if (MD52EbookMap.isEmpty())
        return;
    QMapIterator<QString, ebook> i(MD52EbookMap);
    while (i.hasNext()) {
        i.next();
        //если еще не загружено и если не в библиотеке
        if(!i.value().uploaded &&!i.value().inLib)
        {
            MD52EbookMap[i.key()].publisher =  ui->lineEditPublisher->text();
        }

    }
    MD52EbookMap[getMd5ofCurrentItem()].publisher =  ui->lineEditPublisher->text();
}
//установка журнала для всех книг
void guMainWindow::onSetPeriodicalForAllBooks()
{
    if (MD52EbookMap.isEmpty())
        return;
    QMapIterator<QString, ebook> i(MD52EbookMap);
    while (i.hasNext()) {
        i.next();
        //если еще не загружено и если не в библиотеке
        if(!i.value().uploaded &&!i.value().inLib)
        {
            MD52EbookMap[i.key()].periodical =  ui->lineEditPeriodical->text();
        }

    }
    MD52EbookMap[getMd5ofCurrentItem()].periodical =  ui->lineEditPeriodical->text();
}

//установка города для всех книг
void guMainWindow::onSetSityForAllBooks()
{
    if (MD52EbookMap.isEmpty())
        return;
    QMapIterator<QString, ebook> i(MD52EbookMap);
    while (i.hasNext()) {
        i.next();
        //если еще не загружено и если не в библиотеке
        if(!i.value().uploaded &&!i.value().inLib)
        {
            MD52EbookMap[i.key()].sity =  ui->lineEditSity->text();
        }
    }
    MD52EbookMap[getMd5ofCurrentItem()].sity =  ui->lineEditSity->text();
}
//установка УДК для всех книг
void guMainWindow::onSetUdcForAllBooks()
{
    if (MD52EbookMap.isEmpty())
        return;
    QMapIterator<QString, ebook> i(MD52EbookMap);
    while (i.hasNext()) {
        i.next();
        //если еще не загружено и если не в библиотеке
        if(!i.value().uploaded &&!i.value().inLib)
        {
            MD52EbookMap[i.key()].UDC =  ui->lineEditUDC->text();
        }

    }
    MD52EbookMap[getMd5ofCurrentItem()].UDC =  ui->lineEditUDC->text();
}
//установка года издания для всех книг
void guMainWindow::onSetPubYearForAllBooks()
{
    if (MD52EbookMap.isEmpty())
        return;
    QString yearStr(ui->lineEditPubYear->text());
    bool convertOk;
    int year = yearStr.toInt(&convertOk);
    if(!(yearStr.length() == 4) || !convertOk)
        return;
    QMapIterator<QString, ebook> i(MD52EbookMap);
    while (i.hasNext()) {
        i.next();
        //если еще не загружено и если не в библиотеке
        if(!i.value().uploaded &&!i.value().inLib)
        {
            MD52EbookMap[i.key()].pubYear =  year;
        }

    }
    MD52EbookMap[getMd5ofCurrentItem()].pubYear =  year;
}
//установка BBC для всех книг
void guMainWindow::onSetBbcForAllBooks()
{
    if (MD52EbookMap.isEmpty())
        return;
    QMapIterator<QString, ebook> i(MD52EbookMap);
    while (i.hasNext()) {
        i.next();
        //если еще не загружено и если не в библиотеке
        if(!i.value().uploaded &&!i.value().inLib)
        {
            MD52EbookMap[i.key()].BBC =  ui->lineEditBBC->text();
        }

    }
    MD52EbookMap[getMd5ofCurrentItem()].BBC =  ui->lineEditBBC->text();
}
//установка языка для всех книг
void guMainWindow::onSetLanguageForAllBooks()
{
    if (MD52EbookMap.isEmpty())
        return;
    QMapIterator<QString, ebook> i(MD52EbookMap);
    while (i.hasNext()) {
        i.next();
        //если еще не загружено и если не в библиотеке
        if(!i.value().uploaded &&!i.value().inLib)
        {
            MD52EbookMap[i.key()].language =  ui->lineEditLanguage->text();
        }

    }
    MD52EbookMap[getMd5ofCurrentItem()].language =  ui->lineEditLanguage->text();
}
//установка ориентации  для всех книг
void guMainWindow::onSetOrientationForAllBooks()
{
    if (MD52EbookMap.isEmpty())
        return;
    QMapIterator<QString, ebook> i(MD52EbookMap);
    while (i.hasNext()) {
        i.next();
        //если еще не загружено и если не в библиотеке
        if(!i.value().uploaded &&!i.value().inLib)
        {
            MD52EbookMap[i.key()].orientation =  ui->comboBoxOrientation->currentIndex();
        }

    }
    MD52EbookMap[getMd5ofCurrentItem()].orientation =  ui->comboBoxOrientation->currentIndex();
}
//+ установка разрешения скана для всех книг
void guMainWindow::onSetScanDpiForAllBooks()
{
    if (MD52EbookMap.isEmpty())
        return;
    QString dpiStr(ui->lineEditDpi->text());
    bool convertOk;
    int dpi = dpiStr.toInt(&convertOk);
    if(!convertOk)
        return;

    QMapIterator<QString, ebook> i(MD52EbookMap);
    while (i.hasNext()) {
        i.next();
        //если еще не загружено и если не в библиотеке
        if(!i.value().uploaded &&!i.value().inLib)
        {
            MD52EbookMap[i.key()].scanDpi =  dpi;
        }

    }
    MD52EbookMap[getMd5ofCurrentItem()].scanDpi =  dpi;
}
//установка цветности скана для всех книг
void guMainWindow::onSetColorScanForAllBooks()
{
    if (MD52EbookMap.isEmpty())
        return;
    int checkState;
    if (ui->checkBoxColorScan->isChecked())
    {
        checkState = 2;
    }
    else
    {
        checkState = 1;
    }
    QMapIterator<QString, ebook> i(MD52EbookMap);
    while (i.hasNext()) {
        i.next();
        //если еще не загружено и если не в библиотеке
        if(!i.value().uploaded &&!i.value().inLib)
        {

            MD52EbookMap[i.key()].scanColor = checkState;
        }

    }
    MD52EbookMap[getMd5ofCurrentItem()].scanColor =  checkState;
}
//установка данных о том, очищен ли скан для всех книг
void guMainWindow::onSetCleanScanForAllBooks()
{
    if (MD52EbookMap.isEmpty())
        return;
    int checkState;
    if (ui->checkBoxClearScan->isChecked())
    {
        checkState = 2;
    }
    else
    {
        checkState = 1;
    }
    QMapIterator<QString, ebook> i(MD52EbookMap);
    while (i.hasNext()) {
        i.next();
        //если еще не загружено и если не в библиотеке
        if(!i.value().uploaded &&!i.value().inLib)
        {
            MD52EbookMap[i.key()].scanCleaned =  checkState;
        }

    }
    MD52EbookMap[getMd5ofCurrentItem()].scanCleaned =  checkState;
}
//установка  категории для всех книг
void guMainWindow::onSetCategoryForAllBooks()
{
    if (MD52EbookMap.isEmpty())
        return;
    QMapIterator<QString, ebook> i(MD52EbookMap);
    while (i.hasNext()) {
        i.next();
        //если еще не загружено и если не в библиотеке
        if(!i.value().uploaded &&!i.value().inLib)
        {
            MD52EbookMap[i.key()].category = ui->lineEditCategory->text();
            MD52EbookMap[i.key()].categoryManualSetted = true;
        }

    }
    MD52EbookMap[getMd5ofCurrentItem()].category = ui->lineEditCategory->text();
    MD52EbookMap[getMd5ofCurrentItem()].categoryManualSetted = true;
}

void guMainWindow::onOpenCurrentEbook()
{
    if(!getMd5ofCurrentItem().isEmpty())
        QDesktopServices::openUrl(QUrl::fromLocalFile( MD52EbookMap[getMd5ofCurrentItem()].filePath));
}

void guMainWindow::onCopyMD5ToClipboard()
{
    QApplication::clipboard()->setText(ui->labelCurrentMD5->text());
}

void guMainWindow::onAbortInspectProcess()
{
    emit abortInspectProcess();
    //у всех установить опять "0%"
}

void guMainWindow::onAllEbooksUploaded()
{
    this->onEndProcess();
    QMessageBox msgBox;
    msgBox.setWindowTitle(tr("Загрузка завершена"));
    msgBox.setText(tr("Всего загружено: ") + QString::number(this->numOfUploaded));
    msgBox.exec();
    qDebug() << "upload finished";
}

void guMainWindow::show()
{
    this->showMaximized();
    //onShowMainWindow();
    //QMainWindow::show();
}

void guMainWindow::onToogleShowDublicates(bool show)
{
    if (MD52EbookMap.isEmpty())
        return;
    QMapIterator<QString, ebook> i(MD52EbookMap);
    while (i.hasNext()) {
        i.next();
        if(i.value().inLib)
        {
            if(show){i.value().item->setHidden(false);}
            else{i.value().item->setHidden(true);}
        }
    }
}
void guMainWindow::onToogleShowUploaded(bool show)
{
    if (MD52EbookMap.isEmpty())
        return;
    QMapIterator<QString, ebook> i(MD52EbookMap);
    while (i.hasNext()) {
        i.next();
        if(i.value().uploaded)
        {
            if(show){i.value().item->setHidden(false);}
            else{i.value().item->setHidden(true);}
        }
    }
}
void guMainWindow::onToogleShowWithISBN(bool show)
{
    if (MD52EbookMap.isEmpty())
        return;
    QMapIterator<QString, ebook> i(MD52EbookMap);
    while (i.hasNext()) {
        i.next();
        if(!i.value().ISBNs.isEmpty() && !i.value().uploaded && !i.value().biblioSetted && !i.value().inLib)
        {
            if(show){i.value().item->setHidden(false);}
            else{i.value().item->setHidden(true);}
        }
    }
}
void guMainWindow::onToogleShowWithBibliography(bool show)
{
    if (MD52EbookMap.isEmpty())
        return;
    QMapIterator<QString, ebook> i(MD52EbookMap);
    while (i.hasNext()) {
        i.next();
        if(!i.value().uploaded && i.value().biblioSetted && !i.value().inLib)
        {
            if(show){i.value().item->setHidden(false);}
            else{i.value().item->setHidden(true);}
        }
    }
}
void guMainWindow::onSubjectIndexChanged(int index)
{
    if(index < 0)
        return;
    qDebug() << "index" << index;
    MD52EbookMap[getMd5ofCurrentItem()].subjectIndex = index;
    MD52EbookMap[getMd5ofCurrentItem()].catogorySubjectSetted = true;
    ui->lineEditCategory->setText(ui->listWidgetSubjects->item(index)->text());
}

void guMainWindow::onSelectAllToUploadToogled(bool select)
{

    if (MD52EbookMap.isEmpty())
        return;
    QMapIterator<QString, ebook> i(MD52EbookMap);
    while (i.hasNext()) {
        i.next();
        //проверка на загрузку
        if(!i.value().uploaded && i.value().biblioSetted && !i.value().inLib)
        {
            if(select)
            {
                i.value().item->setCheckState(0, Qt::Checked);
            }
            else
            {
                i.value().item->setCheckState(0, Qt::Unchecked);
            }
        }

    }
}

void guMainWindow::onShowSettingsDialog()
{
    guSettDialog settDlg;
    settDlg.setModal(true);
    settDlg.setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::WindowTitleHint| Qt::CustomizeWindowHint);
    int retCode = settDlg.exec();
    //qDebug() << "ret code is "<< retCode;
    if (retCode == 0)
    {
        return;
    }else
    {
        initBaseSettings();
    }
}

void guMainWindow::onIsbnsListItemActivated()
{
    ui->toolButtonRemoveIsbn->setEnabled(true);
}

void guMainWindow::onCategoryTextChanged(QString)
{
    MD52EbookMap[getMd5ofCurrentItem()].categoryManualSetted = true;
    ui->toolButtonSaveChanges->setEnabled(true);
}
void guMainWindow::onIsbnFieldChanged(QString isbn)
{
    if(isbn.length() >= 10)
    {
        ui->toolButtonAddIsbn->setEnabled(true);
    }else
    {
        ui->toolButtonAddIsbn->setEnabled(false);
    }
}

void guMainWindow::onDescriptionTextChanged()
{
    ui->toolButtonSaveChanges->setEnabled(true);
}

void guMainWindow::onAuthorsTextChanged(QString)
{


    if (ui->lineEditAuthors->text().length() > 4)
    {
        ui->labelAuthors->setStyleSheet("color: rgb(0, 0, 0);");
        ui->toolButtonSaveChanges->setEnabled(true);
    }
    else
    {
        ui->labelAuthors->setStyleSheet("color: rgb(255, 0, 0);");
    }
}
void guMainWindow::onSeriesTextChanged(QString)
{
    ui->toolButtonSaveChanges->setEnabled(true);
}
void guMainWindow::onPublisherTextChanged(QString)
{


    if (ui->lineEditPublisher->text().length() > 4)
    {
        ui->labelPublisher->setStyleSheet("color: rgb(0, 0, 0);");
        ui->toolButtonSaveChanges->setEnabled(true);
    }
    else
    {
        ui->labelPublisher->setStyleSheet("color: rgb(255, 0, 0);");
    }
}
void guMainWindow::onUdcTextChanged(QString)
{
    ui->toolButtonSaveChanges->setEnabled(true);
}
void guMainWindow::onBbcTextChanged(QString)
{
    ui->toolButtonSaveChanges->setEnabled(true);
}
void guMainWindow::onPubYearTextChanged(QString)
{
    if (ui->lineEditPubYear->text().length() == 4)
    {
        ui->labelPubYear->setStyleSheet("color: rgb(0, 0, 0);");
        ui->toolButtonSaveChanges->setEnabled(true);
    }
    else
    {
        ui->labelPubYear->setStyleSheet("color: rgb(255, 0, 0);");
    }
}
void guMainWindow::onPageNumTextChanged(QString)
{
    if (ui->lineEditPageNum->text().length() != 0)
    {
        ui->labelPageNum->setStyleSheet("color: rgb(0, 0, 0);");
        ui->toolButtonSaveChanges->setEnabled(true);
    }
    else
    {
        ui->labelPageNum->setStyleSheet("color: rgb(255, 0, 0);");
    }
}
void guMainWindow::onIssueTextChanged(QString)
{
    ui->toolButtonSaveChanges->setEnabled(true);
}
void guMainWindow::onVolumeTextChanged(QString)
{
    ui->toolButtonSaveChanges->setEnabled(true);
}
void guMainWindow::onSityTextChanged(QString sity)
{
    ui->toolButtonSaveChanges->setEnabled(true);
}
void guMainWindow::onPeriodicalTextChanged(QString periodical)
{
    ui->toolButtonSaveChanges->setEnabled(true);
}
void guMainWindow::onLanguageTextChanged(QString)
{

    if (ui->lineEditLanguage->text().length() > 3)
    {
        ui->labelLanguage->setStyleSheet("color: rgb(0, 0, 0);");
        ui->toolButtonSaveChanges->setEnabled(true);
    }
    else
    {
        ui->labelLanguage->setStyleSheet("color: rgb(255, 0, 0);");
    }
}
void guMainWindow::guMainWindow::onOrientationIndexChanged(int index)
{
    ui->toolButtonSaveChanges->setEnabled(true);
}
void guMainWindow::onBiblioTextChanged(QString biblio)
{
    ui->toolButtonSaveChanges->setEnabled(true);
}
void guMainWindow::onDpiTextChanged(QString dpi)
{
    ui->toolButtonSaveChanges->setEnabled(true);
}
void guMainWindow::onDvdNumTextChanged(QString dvdNum)
{
    ui->toolButtonSaveChanges->setEnabled(true);
}

void guMainWindow::onColorScanStateChanged(int scanState)
{
    ui->toolButtonSaveChanges->setEnabled(true);
}
void guMainWindow::onClearScanStateChanged(int clearState)
{
    ui->toolButtonSaveChanges->setEnabled(true);
}

void guMainWindow::onUploadEbookFinished(QString MD5)
{
    //TODO: добавить проверку успешности загрузки
    //MD52EbookMap[MD5].item->setCheckState(4, Qt::PartiallyChecked);
    //MD52EbookMap[MD5].item->setDisabled(true);
    //MD52EbookMap[MD5].item->setFlags(Qt::ItemIsUserCheckable);
    MD52EbookMap[MD5].item->setData(4, Qt::CheckStateRole, QVariant());
    MD52EbookMap[MD5].item->setText(4, tr("загружено"));
    MD52EbookMap[MD5].uploaded = true;
    if(!ui->actionToogleShowUploaded->isChecked())
        MD52EbookMap[MD5].item->setHidden(true);
    numOfUploaded++;
    ui->labelNumOfUploaded->setNum(numOfUploaded);
    ((guBookTreeItem*)MD52EbookMap[MD5].item)->setBook(MD52EbookMap[MD5]);
}

void guMainWindow::onUploadEbookProgress(QString MD5OfUpload,int persent)
{
    ((guBookTreeItem*)(MD52EbookMap[MD5OfUpload].item))->setUploadProgress(persent);
}
void guMainWindow::onAddIsbnToEbook(QString MD5, QString ISBN)
{
    //заменить установку более интеллектуальным способом
    MD52EbookMap[MD5].ISBNs.append(ISBN);
    if(!MD52EbookMap[MD5].uploaded && !MD52EbookMap[MD5].biblioSetted )
        ((guBookTreeItem*)MD52EbookMap[MD5].item)->setBook(MD52EbookMap[MD5]);
    if(!ui->actionToogleShowWithISBN->isChecked())
        MD52EbookMap[MD5].item->setHidden(true);
}
void guMainWindow::onRemoveIsbnFromEbook(QString MD5, QString ISBN)
{
    MD52EbookMap[MD5].ISBNs.removeOne(ISBN);
    if(MD52EbookMap[MD5].ISBNs.isEmpty())
    {
        if(!MD52EbookMap[MD5].uploaded && !MD52EbookMap[MD5].biblioSetted )
            ((guBookTreeItem*)MD52EbookMap[MD5].item)->setBook(MD52EbookMap[MD5]);
    }
}

void guMainWindow::onAddIsbn()
{
    isbnMethods check;
    QString isbn(check.cleanIsbn(ui->lineEditIsbn->text()));
    if(this->MD52EbookMap[getMd5ofCurrentItem()].ISBNs.contains(isbn))
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle(tr("Повтор"));
        msgBox.setText(tr("Данный ISBN уже есть в списке"));
        msgBox.exec();
        return;
    }
    if(check.isbnOk(isbn))
    {
        //добавляем
        QListWidgetItem isbnItem;
        isbnItem.setText(isbn);
        isbnItem.setCheckState(Qt::Unchecked);
        onAddIsbnToEbook(getMd5ofCurrentItem(), isbn);
        ui->listWidgetISBNs->addItem(&isbnItem);

        ui->lineEditIsbn->clear();

    }else//иначе
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle(tr("Вы ввели неправильный ISBN"));
        msgBox.setText(tr("Введите только 10 или 13 символов с тире или без.\n\nНапример:\n 012466606X \n978-0-7506-6919-1"));
        msgBox.exec();
    }
}

void guMainWindow::onRemoveIsbn()
{
    if(!ui->listWidgetISBNs->currentItem())
        return;
    qDebug() << "gogo";
    QString isbn(ui->listWidgetISBNs->currentItem()->text());
    ui->listWidgetISBNs->removeItemWidget(ui->listWidgetISBNs->currentItem());
    delete ui->listWidgetISBNs->takeItem(ui->listWidgetISBNs->row(ui->listWidgetISBNs->currentItem()));
    onRemoveIsbnFromEbook(getMd5ofCurrentItem(), isbn);
    ui->toolButtonRemoveIsbn->setEnabled(false);
}
void guMainWindow::onCommentaryTextChanged(QString)
{
    ui->toolButtonSaveChanges->setEnabled(true);
}

void guMainWindow::onTitleTextChanged(const QString newText)
{
    if (newText.length() > 4)
    {
        ui->labelTitle->setStyleSheet("color: rgb(0, 0, 0);");
        ui->toolButtonSaveChanges->setEnabled(true);
    }
    else
    {
        ui->labelTitle->setStyleSheet("color: rgb(255, 0, 0);");
    }
}

void guMainWindow::onDublicateFinded()
{
    numOfDublicates++;
    numOfInspected++;
    this->updateStatusLabels();
}
void guMainWindow::onTimerTimeout()
{
    if (ui->progressBarProcess->value() == 100)
        ui->progressBarProcess->setValue(0);
    else
        ui->progressBarProcess->setValue(ui->progressBarProcess->value() + 1);
}
void guMainWindow::onCurrentCategoryChangedFillStr(QTreeWidgetItem * current, QTreeWidgetItem * previous)
{
    if (current->text(0) == "None")
    {
        ui->lineEditCategory->setText("");
    }
    else
    {
        QString catStr;
        QTreeWidgetItem *currentIt;
        currentIt = current;
        catStr = currentIt->text(0);
        while(currentIt->parent())
        {
            currentIt = currentIt->parent();
            catStr = currentIt->text(0) +"/"+ catStr;
        }
        ui->lineEditCategory->setText(catStr);
    }

}
QString guMainWindow::getMd5ofCurrentItem()
{
    if(ui->treeWidgetFiles->currentItem())
    {
        return ((guBookTreeItem*)(ui->treeWidgetFiles->currentItem()))->getMD5();
    }
    else
        return QString();
}

void guMainWindow::onCurrentCategoryChanged(QTreeWidgetItem * current, QTreeWidgetItem * previous)
{

    QString currentMD5(getMd5ofCurrentItem());
    MD52EbookMap[currentMD5].categoryManualSetted = false;
    if (currentMD5.isEmpty())
        return;
    previous->setBackgroundColor(0,Qt::transparent);
    previous->setBackgroundColor(1,Qt::transparent);
    current->setBackgroundColor(0, this->categorySelectedColor);
    current->setBackgroundColor(1, this->categorySelectedColor);
    MD52EbookMap[currentMD5].categoryItem = current;
    MD52EbookMap[currentMD5].categoryTreeSetted = true;
}
void guMainWindow::clearEditFields()
{
    //добавить правильную обработку
    ui->lineEditIsbn->clear();
    ui->listWidgetISBNs->clear();
    ui->listWidgetSubjects->clear();
    if (false)
    {
        ui->lineEditCommentary->clear();
        ui->lineEditTitle->clear();
        ui->lineEditAuthors->clear();
        ui->lineEditSeries->clear();
        ui->lineEditPublisher->clear();
        ui->lineEditUDC->clear();
        ui->lineEditBBC->clear();
        ui->lineEditPubYear->setText("");
        ui->lineEditPageNum->setText("");
        ui->lineEditIssue->clear();
        ui->lineEditVolume->clear();
        ui->lineEditLanguage->clear();
        ui->comboBoxOrientation->setCurrentIndex(0);

        ui->lineEditBiblio->clear();
        ui->lineEditDpi->clear();
        ui->lineEditDVDNum->clear();
        ui->checkBoxColorScan->setChecked(false);
        ui->checkBoxClearScan->setChecked(false);

        ui->lineEditCategory->clear();
        ui->listWidgetSubjects->clear();
        ui->textEditDescription->clear();
    }
}
//получение библиографии для текущей книги
void guMainWindow::onGetBiblioForCurrentEbook()
{
    if(getMd5ofCurrentItem().isEmpty())
        return;
    fillBibliography(this->getMd5ofCurrentItem(), "amazon");  //amazon isbndb
}

void guMainWindow::onSaveChangesForBook()
{
    QString currentMD5(getMd5ofCurrentItem());
    MD52EbookMap[currentMD5].title          = ui->lineEditTitle->text();
    MD52EbookMap[currentMD5].authors        = ui->lineEditAuthors->text();
    MD52EbookMap[currentMD5].publisher      = ui->lineEditPublisher->text();
    MD52EbookMap[currentMD5].pubYear        = ui->lineEditPubYear->text().toInt();
    MD52EbookMap[currentMD5].pageNum        = ui->lineEditPageNum->text().toInt();
    MD52EbookMap[currentMD5].series         = ui->lineEditSeries->text();
    MD52EbookMap[currentMD5].UDC            = ui->lineEditUDC->text();
    MD52EbookMap[currentMD5].BBC            = ui->lineEditBBC->text();
    MD52EbookMap[currentMD5].language       = ui->lineEditLanguage->text();
    MD52EbookMap[currentMD5].orientation    = ui->comboBoxOrientation->currentIndex();
    MD52EbookMap[currentMD5].collection     = ui->lineEditBiblio->text();
    MD52EbookMap[currentMD5].volume         = ui->lineEditVolume->text();
    MD52EbookMap[currentMD5].issue          = ui->lineEditIssue->text();
    MD52EbookMap[currentMD5].collectionIssue = ui->lineEditDVDNum->text();
    MD52EbookMap[currentMD5].scanDpi        = ui->lineEditDpi->text().toInt();
    MD52EbookMap[currentMD5].sity           = ui->lineEditSity->text();
    MD52EbookMap[currentMD5].periodical     = ui->lineEditPeriodical->text();
    if (ui->checkBoxClearScan->isChecked())
    {
        MD52EbookMap[currentMD5].scanCleaned = 2;
    }
    else
    {
        MD52EbookMap[currentMD5].scanCleaned = 1;
    }
    if (ui->checkBoxColorScan->isChecked())
    {
        MD52EbookMap[currentMD5].scanColor = 2;
    }
    else
    {
        MD52EbookMap[currentMD5].scanColor = 1;
    }
    MD52EbookMap[currentMD5].category = ui->lineEditCategory->text();
    MD52EbookMap[currentMD5].description = ui->textEditDescription->toPlainText();
    MD52EbookMap[currentMD5].commentary = ui->lineEditCommentary->text();

    ui->toolButtonSaveChanges->setEnabled(false);
    if(MD52EbookMap[currentMD5].item->checkState(4) != Qt::Checked)
    {
        MD52EbookMap[currentMD5].item->setData ( 4, Qt::CheckStateRole, Qt::Unchecked );
    }


    setBiblioStateForItem(currentMD5, isBiblioFull(currentMD5));
}
//TODO: дописать остальное
bool guMainWindow::isBiblioFull(QString MD5)
{
    if(MD52EbookMap[MD5].title.length() < 4)
        return false;
    if(MD52EbookMap[MD5].pageNum == 0)
        return false;
    if(MD52EbookMap[MD5].publisher.length() < 2)
        return false;
    return true;
}

void guMainWindow::setGuiEditForCurrentItem()
{
    clearEditFields();
    QString currentMD5(getMd5ofCurrentItem());
    //сначала загрузим обложку
    if(!MD52EbookMap[currentMD5].coverUrl.isEmpty())
        loadCover(currentMD5, MD52EbookMap[currentMD5].coverUrl);
    else
    {
        coverScene->clear();
        this->graphicsView->fitInView((QGraphicsItem*)coverScene->addPixmap(QPixmap(":/icons/no_cover.jpg","JPG")),Qt::KeepAspectRatio);
        graphicsView->update();
    }
    //вывод isbn'ов
    ui->labelCurrentMD5->setText(currentMD5);
    ui->toolButtonSaveChanges->setEnabled(false);
    ui->listWidgetISBNs->addItems(MD52EbookMap[currentMD5].ISBNs);
    if(!MD52EbookMap[currentMD5].ISBNs.isEmpty())
    {
        ui->toolButtonGetBiblioForItem->setEnabled(true);
    }
    ui->lineEditTitle->setText(MD52EbookMap[currentMD5].title);
    ui->lineEditTitle->setCursorPosition(0);

    ui->lineEditAuthors->setText(MD52EbookMap[currentMD5].authors);
    ui->lineEditAuthors->setCursorPosition(0);

    ui->textEditDescription->setHtml(MD52EbookMap[currentMD5].description);
    //ui->textEditDescription->setCursorPosition(0);

    ui->lineEditPublisher->setText(MD52EbookMap[currentMD5].publisher);
    ui->lineEditPublisher->setCursorPosition(0);
    QString pubYear;
    if(MD52EbookMap[currentMD5].pubYear !=0)
    {
        ui->lineEditPubYear->setText(QString::number(MD52EbookMap[currentMD5].pubYear));
        ui->lineEditPubYear->setCursorPosition(0);
    }
    if(!MD52EbookMap[currentMD5].subjects.isEmpty())
    {
        ui->listWidgetSubjects->addItems(MD52EbookMap[currentMD5].subjects);
    }
    if(MD52EbookMap[currentMD5].pageNum != 0 )
    {
        ui->lineEditPageNum->setText(QString::number(MD52EbookMap[currentMD5].pageNum));
        ui->lineEditPageNum->setCursorPosition(0);
    }
    ui->lineEditCommentary->setText(MD52EbookMap[currentMD5].commentary); ui->lineEditCommentary->setCursorPosition(0);

    ui->lineEditSeries->setText(MD52EbookMap[currentMD5].series); ui->lineEditSeries->setCursorPosition(0);
    ui->lineEditUDC->setText(MD52EbookMap[currentMD5].UDC); ui->lineEditUDC->setCursorPosition(0);
    ui->lineEditBBC->setText(MD52EbookMap[currentMD5].BBC); ui->lineEditBBC->setCursorPosition(0);
    ui->lineEditIssue->setText(MD52EbookMap[currentMD5].issue); ui->lineEditIssue->setCursorPosition(0);
    ui->lineEditVolume->setText(MD52EbookMap[currentMD5].volume); ui->lineEditVolume->setCursorPosition(0);
    ui->lineEditBiblio->setText(MD52EbookMap[currentMD5].collection); ui->lineEditBiblio->setCursorPosition(0);
    if(MD52EbookMap[currentMD5].scanDpi != 0 )
    {
         ui->lineEditDpi->setText(QString::number(MD52EbookMap[currentMD5].scanDpi)); ui->lineEditDpi->setCursorPosition(0);
    }
    ui->lineEditDpi->setText(QString::number(MD52EbookMap[currentMD5].scanDpi)); ui->lineEditDpi->setCursorPosition(0);
    ui->lineEditDVDNum->setText(MD52EbookMap[currentMD5].collectionIssue); ui->lineEditDVDNum->setCursorPosition(0);
    ui->lineEditLanguage->setText(MD52EbookMap[currentMD5].language); ui->lineEditLanguage->setCursorPosition(0);
    ui->comboBoxOrientation->setCurrentIndex(MD52EbookMap[currentMD5].orientation);

    switch ( MD52EbookMap[currentMD5].scanCleaned)
    {
    case 0:
        ui->checkBoxClearScan->setChecked(false);
        break;
    case 1:
        ui->checkBoxClearScan->setChecked(false);
        break;
    case 2:
        ui->checkBoxClearScan->setChecked(true);
        break;
    }
    switch ( MD52EbookMap[currentMD5].scanColor)
    {
    case 0:
        ui->checkBoxColorScan->setChecked(false);
        break;
    case 1:
        ui->checkBoxColorScan->setChecked(false);
        break;
    case 2:
        ui->checkBoxColorScan->setChecked(true);
        break;
    }

    ui->toolButtonAddIsbn->setEnabled(false);
    ui->toolButtonRemoveIsbn->setEnabled(false);

    //отсоединяем слот, чтобы его не зациклило
    //disconnect(ui->treeWidgetCategories , SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)), this, SLOT(onCurrentCategoryChanged(QTreeWidgetItem*,QTreeWidgetItem*)));

    //ui->treeWidgetCategories->currentItem()->setBackgroundColor(0,QColor::fromRgb(200,10,200));
    //ui->treeWidgetCategories->currentItem()->setBackgroundColor(1,QColor::fromRgb(200,10,200));
    if (MD52EbookMap[currentMD5].catogorySubjectSetted)
    {
        ui->listWidgetSubjects->setCurrentRow(MD52EbookMap[currentMD5].subjectIndex);
    }


    if (MD52EbookMap[currentMD5].categoryTreeSetted)
    {

        ui->treeWidgetCategories->setCurrentItem(MD52EbookMap[currentMD5].categoryItem);
    }
    else
    {
        ui->treeWidgetCategories->setCurrentItem(ui->treeWidgetCategories->topLevelItem(0));
    }
    //if(MD52EbookMap[currentMD5].categoryManualSetted)
    //{
    ui->lineEditCategory->setText(MD52EbookMap[currentMD5].category);
    ui->lineEditCategory->setCursorPosition(0);

    ui->lineEditPeriodical->setText(MD52EbookMap[currentMD5].periodical);
    ui->lineEditPeriodical->setCursorPosition(0);

    ui->lineEditSity->setText(MD52EbookMap[currentMD5].sity);
    ui->lineEditSity->setCursorPosition(0);
    //}
    //ui->treeWidgetCategories->currentItem()->setBackgroundColor(0, QColor::fromRgb(200,200,200));
    //ui->treeWidgetCategories->currentItem()->setBackgroundColor(1, QColor::fromRgb(200,200,200));
    //снова присоединяем
    //connect(ui->treeWidgetCategories , SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)), this, SLOT(onCurrentCategoryChanged(QTreeWidgetItem*,QTreeWidgetItem*)));
}

void guMainWindow::onCurrentFileChanged(QTreeWidgetItem * current, QTreeWidgetItem * previous)
{
    QString currentMD5(getMd5ofCurrentItem());
    //проверяем, есть ли книга в библиотеке, и проверена ли эта информация
    if(MD52EbookMap[currentMD5].inLib && MD52EbookMap[currentMD5].inLibChecked)
    {

//#ifndef TEST //если не тест, то показываем сообщение о том, что книга уже есть в либе
//        ui->stackedWidget->setCurrentIndex(1);
//        ui->toolButtonGetBiblioForItem->setEnabled(false);
//        ui->toolButtonSaveChanges->setEnabled(false);
//#endif

//#ifdef TEST //если тест, то отображаем информацию даже по книгам, которые есть в библиотеке
        setGuiEditForCurrentItem();
//#endif
        return;
    }
    else
    {
        //если ее нет в библиотеке, то отображаем информацию для книги
        setGuiEditForCurrentItem();
        ui->toolButtonSaveChanges->setEnabled(false);
        ui->stackedWidget->setCurrentIndex(0);
    }
}
guMainWindow::~guMainWindow()
{
    inspector->deleteLater();
    delete ui;
}

void guMainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
void guMainWindow::onAddNewEbook(QString MD5, ebook newEbook)
{
    if(this->MD52EbookMap.contains(MD5))
    {
        numOfInspected++;
        return;
    }
    //ebook *guiEbook = new eb;
    //QStringList treeWidgetItemRow;
    //QString fileSizeStr;
    //fileSizeStr.setNum(guiEbook.fileSize);
    //treeWidgetItemRow << guiEbook.fileName.remove(guiEbook.fileExtension) <<  "" << fileSizeStr << MD5 << "";
    guBookTreeItem *newItem = new guBookTreeItem(newEbook);

//    QString iconFileName;
//    if(guiEbook.fileExtension == "pdf")
//    {
//        iconFileName = ":/file_types/file_types/pdf_22.png";
//    }else if (guiEbook.fileExtension == "chm")
//    {
//        iconFileName = ":/file_types/file_types/help-contents.png";
//    }else if (guiEbook.fileExtension == "djvu")
//    {
//        iconFileName = ":/file_types/file_types/djvu_22.png";
//    }else
//    {
//        iconFileName = ":/file_types/file_types/unknown_file_22.png";
//    }
//    newItem->setIcon(1, QIcon(QPixmap(iconFileName, "PNG")));
    ui->treeWidgetFiles->insertTopLevelItem(MD52EbookMap.count(),newItem);
    newEbook.item = newItem;
    MD52EbookMap[MD5] = newEbook;
    //if (!newEbook.ISBNs.isEmpty()) //если есть ИСБНы, то подсвечиваем
    //{
    //    setColorForItemByMd5(MD5, withIsbnColor);
    //}

    //onTimerTimeout();
    //ui->labelProcessStatus->setText(tr("Идет рассчёт MD5..."));


    for (int i = 0 ; i < ui->treeWidgetFiles->columnCount() ; i++)
    {
        ui->treeWidgetFiles->resizeColumnToContents(i);
    }
    checkEbookDublicate(MD5);
    //обновляем статистику
    if(!newEbook.ISBNs.isEmpty())
    {numOfWithIsbn++;}
    numOfInspected++;
    numOfNew++;

    updateStatusLabels();
    ui->stackedWidget->setCurrentIndex(0);
    ui->treeWidgetFiles->setCurrentItem(newItem);

}
void guMainWindow::updateStatusLabels()
{
    ui->labelNumOfInspected->setNum(numOfInspected);
    ui->labelNumOfDublicates->setNum(numOfDublicates);
    ui->labelNumOfWithIsbn->setNum(numOfWithIsbn);
    ui->labelNumOfWithBiblio->setNum(numOfWithBiblio);
    ui->labelNumOfUploaded->setNum(numOfUploaded);
}

void guMainWindow::onStartProcess()
{
    processTimer->start(2000);
}
void guMainWindow::onEndProcess()
{
    processTimer->stop();
    ui->progressBarProcess->setValue(0);
    ui->labelProcessStatus->setText(tr(""));
}

void guMainWindow::fillBibliography(QString MD5, QString dataSource)
{
    if(MD52EbookMap[MD5].ISBNs.empty())
        return;
    QNetworkRequest *fillBibliographyRequest;
    //добавить запросы по всем исбнам
    QString ISBNstr = MD52EbookMap[MD5].ISBNs.at(0);
    QString url;
    if (dataSource == "amazon")
    {
        url =  "http://status.calibre-ebook.com/aws/metadata/" + ISBNstr;
    } else if ( dataSource == "isbndb")
    {
        //using key
        url ="http://isbndb.com/api/books.xml?access_key=SKNCGPYT&index1=isbn&value1=" + ISBNstr;
        //using only http
        //url = "http://isbndb.com/search-all.html?kw=" + ISBNstr;
    }
    fillBibliographyRequest = new QNetworkRequest(QUrl(url));
    fillBibliographyRequest->setRawHeader("User-Agent","Libgen Uploader (beta)");
    //log(fillBibliographyRequest->url().toString() + "  requested");
    QNetworkReply  *fillBibliographyReply;
    //ui->labelProcessStatus->setText(tr("Поиск по ИСБН ") + ISBNstr + "...");
    //MD52EbookMap[MD5].inLibCheckSended = true;
    fillBibliographyReply = this->httpFillBibliographyManager->get(*fillBibliographyRequest);
    fillBibliographyReply->setProperty("MD5",MD5);
    fillBibliographyReply->setProperty("dataSource",dataSource);
    numOfFillBibliographyConnections++;
}

void guMainWindow::checkEbookDublicate(QString MD5)
{
        QNetworkRequest *checkDublicateRequest;
        //QString checkUrl = "http://localhost/lgws/?md5="+ MD5;
        QString checkUrl = serviceUrl + "/book/?md5=" + MD5;
        checkDublicateRequest = new QNetworkRequest(QUrl(checkUrl));
        checkDublicateRequest->setRawHeader("User-Agent","Libgen Uploader (beta)");
        checkDublicateRequest->setRawHeader("Connection","close");

        //log(checkDublicateRequest->url().toString() + "  requested");
        qDebug() << (checkDublicateRequest->url().toString() + "  requested");

        QNetworkReply  *checkDublicateReply;
        MD52EbookMap[MD5].inLibCheckSended = true;
        checkDublicateReply = httpCheckDublicatesManager->get(*checkDublicateRequest);
        checkDublicateReply->setProperty("MD5",MD5);
        numOfCheckDublicateConnections++;
}
void guMainWindow::processLoadCoverReply(QNetworkReply* reply)
{
    QString MD5ofRequest = reply->property("MD5").toString();
    QString pathToSaveCover(reply->url().encodedPath());
    QString hostToSaveCover(reply->url().encodedHost());
    pathToSaveCover = qApp->applicationDirPath() + "/covers/" + hostToSaveCover + pathToSaveCover;
    QByteArray coverBa;
    coverBa = reply->readAll();
    reply->deleteLater();
    QPixmap cover;
    qDebug() << reply->header(QNetworkRequest::ContentTypeHeader).toString(); //text/html; charset=iso-8859-1
    //qDebug() << reply->readAll();
    if (reply->header(QNetworkRequest::ContentTypeHeader).toString() == "image/jpeg")
    {
        qDebug() << "true header";

        if( cover.loadFromData(coverBa,"JPG"))
        {
            qDebug() << "path to save" << pathToSaveCover;
            QFileInfo coverPathInfo(pathToSaveCover);
            QDir appDir(coverPathInfo.path());
            if(!appDir.exists())
            {
                appDir.mkpath ( coverPathInfo.path() );
            }

            //qDebug() << "path to create" << dirPath;
            //QDir appDir(qApp->applicationDirPath());
            //appDir.mkpath ( qApp->applicationDirPath()+ dirPath );
            //qApp->applicationDirPath();
            //if(cover.save("covers/testcov.jpg","JPG"))
            //{
            //    qDebug() << "file saved 1";
            //}
            if(cover.save(pathToSaveCover ,"JPG"))
            {
                qDebug() << "file" << pathToSaveCover << "saved";
            }
        }

        if (this->getMd5ofCurrentItem() == MD5ofRequest)
        {
            qDebug() << "clean scene";
            coverScene->clear();
            this->graphicsView->fitInView((QGraphicsItem*)coverScene->addPixmap(cover),Qt::KeepAspectRatio);
            graphicsView->update();
        }
    }
}
void guMainWindow::loadCover(QString MD5, QString coverUrl)
{
    QUrl covUrl;
    QByteArray urlArray;
    urlArray.append(coverUrl);
    covUrl.setEncodedUrl(urlArray);

    QString pathToLoadCover(covUrl.encodedPath());
    QString hostToLoadCover(covUrl.encodedHost());
    pathToLoadCover = qApp->applicationDirPath() + "/covers/" + hostToLoadCover + pathToLoadCover;
    if(QFile::exists(pathToLoadCover))
    {
        qDebug() << "file exists";
        QPixmap cover;
        cover.load(pathToLoadCover);
        coverScene->clear();
        this->graphicsView->fitInView((QGraphicsItem*)coverScene->addPixmap(cover),Qt::KeepAspectRatio);
        graphicsView->update();
        return;
    }
    QNetworkRequest *loadCoverRequest;
    //QUrl encodedUrl;
    //encodedUrl

    loadCoverRequest = new QNetworkRequest(covUrl);
    loadCoverRequest->setRawHeader("User-Agent","Mozilla/5.0 (Windows; U; Windows NT 6.1; ru; rv:1.9.2) Gecko/20100115 Firefox/3.6");
    loadCoverRequest->setRawHeader("Host","ecx.images-amazon.com");
    //loadCoverRequest->setRawHeader("Host","ecx.images-amazon.com");
    loadCoverRequest->setRawHeader("Accept-Encoding","gzip,deflate");
    loadCoverRequest->setRawHeader("Keep-Alive","115");

    loadCoverRequest->setRawHeader("Connection","keep-alive");

    QNetworkReply  *loadCoverReply;
    //ui->labelProcessStatus->setText(tr("Поиск по ИСБН ") + ISBNstr + "...");
    //MD52EbookMap[MD5].inLibCheckSended = true;
    loadCoverReply = coverLoaderManager->get(*loadCoverRequest);
    loadCoverReply->setProperty("MD5",MD5);
    //loadCoverReply->setProperty("dataSource",dataSource);
}

void guMainWindow::processFillBibliographyReply(QNetworkReply* reply)
{
    //ошибка в обработке ответа от серв
    if (reply->error() != QNetworkReply::NoError)
    {
        //TODO: проверка на ошибку запроса библиографии
    }


    QString MD5ofRequest = reply->property("MD5").toString(); //извлечение MD5
    QString dataSource = reply->property("dataSource").toString();
    //qDebug() << MD5ofRequest;

    //log("MD5:" + MD5ofRequest + " error:" + reply->errorString() + " content type: " + reply->header(QNetworkRequest::ContentTypeHeader).toString());

    //qDebug() << "MD5:" + MD5ofRequest + " error:" + reply->errorString();
    //qDebug() << reply->header(QNetworkRequest::ContentTypeHeader).toString();

    if (dataSource == "amazon")
    {
        qDebug() << "reply type from amazon " << reply->header(QNetworkRequest::ContentTypeHeader).toString();
        if (reply->header(QNetworkRequest::ContentTypeHeader).toString() == "text/html")
        {
            MD52EbookMap[MD5ofRequest].biblioSetted = false;
            reply->deleteLater();
            return;
        }else
        {

            if (dataSource == "amazon")
            {
                QByteArray xmlBa;
                xmlBa = reply->readAll();
                qDebug() << xmlBa.data();
                QDomDocument xml("amazonXml");
                xml.setContent(xmlBa);
                reply->deleteLater();
                //qDebug() << xml.toString();
                //проверяем на ошибку
                //QString error  =
                QDomNodeList respErrors = xml.elementsByTagName("Error");//.at(0).firstChild().nodeValue()
                if(!respErrors.isEmpty())
                {
                    MD52EbookMap[MD5ofRequest].biblioSetted = false;
                    return;
                }
                //AWS.InvalidParameterValue
                        //QDomNodeList creatorList = xml.elementsByTagName("Author");
                        MD52EbookMap[MD5ofRequest].title = xml.elementsByTagName("Title").at(0).firstChild().nodeValue();
                //перебираем всех авторов
                QDomNodeList authors = xml.elementsByTagName("Author");
                QString AuthorStr;
                for( int sNum = 0; sNum < authors.count() ; sNum++)
                {
                    AuthorStr += authors.at(sNum).firstChild().nodeValue();
                    if(sNum != authors.count() -1)
                    {
                        AuthorStr += ", ";
                    }
                }
                QDomNodeList creators = xml.elementsByTagName("Creator");
                QString CreatorStr;
                for( int sNum = 0; sNum < creators.count() ; sNum++)
                {
                    CreatorStr += creators.at(sNum).firstChild().nodeValue();
                    if(sNum != creators.count() -1)
                    {
                        CreatorStr += ", ";
                    }
                }
                //<Creator Role="Editor">Masoud Nikravesh</Creator>
                //QString AuthorStr = xml.elementsByTagName("Author").at(0).firstChild().nodeValue();
                //QString EditorStr =  xml.elementsByTagName("Author").at(0).firstChild().nodeValue();
                if(!AuthorStr.isEmpty() && !CreatorStr.isEmpty())
                {
                    CreatorStr = ", " +CreatorStr;
                }
                MD52EbookMap[MD5ofRequest].authors = AuthorStr + CreatorStr;//AuthorStr + " " + EditorStr;
                MD52EbookMap[MD5ofRequest].issue =  xml.elementsByTagName("Edition").at(0).firstChild().nodeValue();
                MD52EbookMap[MD5ofRequest].publisher = xml.elementsByTagName("Publisher").at(0).firstChild().nodeValue();
                //qDebug() << "page num" << xml.elementsByTagName("NumberOfPages").at(0).firstChild().nodeValue();
                MD52EbookMap[MD5ofRequest].pageNum  = xml.elementsByTagName("NumberOfPages").at(0).firstChild().nodeValue().toInt();
                MD52EbookMap[MD5ofRequest].language  = xml.elementsByTagName("Language").at(0).firstChild().firstChild().nodeValue();
                QString pubYear = xml.elementsByTagName("PublicationDate").at(0).firstChild().nodeValue().left(4);
                //qDebug() << "pub date" << xml.elementsByTagName("PublicationDate").at(0).firstChild().nodeValue();
                MD52EbookMap[MD5ofRequest].pubYear  = pubYear.toInt();
                //qDebug()  << "int pub year" << MD52EbookMap[MD5ofRequest].pubYear;
                MD52EbookMap[MD5ofRequest].description  = xml.elementsByTagName("Content").at(0).firstChild().nodeValue();

                MD52EbookMap[MD5ofRequest].ASIN = xml.elementsByTagName("ASIN").at(0).firstChild().nodeValue();
                qDebug() << "ASIN" << MD52EbookMap[MD5ofRequest].ASIN;

                MD52EbookMap[MD5ofRequest].coverUrl  = xml.elementsByTagName("LargeImage").at(0).firstChild().firstChild().nodeValue();//MediumImage
                if(!MD52EbookMap[MD5ofRequest].coverUrl.isEmpty())
                    loadCover(MD5ofRequest, MD52EbookMap[MD5ofRequest].coverUrl);

                QDomNodeList subjects = xml.elementsByTagName("Subject");
                for( int sNum = 0; sNum < subjects.count() ; sNum++)
                {
                    MD52EbookMap[MD5ofRequest].subjects.append(subjects.at(sNum).firstChild().nodeValue());
                }

                //qDebug() << xml.elementsByTagName("Author").at(0).nodeValue();
                //qDebug() << xml.elementsByTagName("Publisher").at(0).firstChild().nodeValue();
                //            for(int i = 0; i < creatorList.count() ; i++)
                //            {
                //                qDebug() << creatorList.at(i).nodeValue();
                //            }
                //QDomElement element
                //                    domElementForItem.value(item);
                //                 if (!element.isNull()) {
                //                     if (column == 0) {
                //                         QDomElement oldTitleElement = element.firstChildElement("title");
                //Language>
                //<Name>
                //English
                //</Name>
                //NumberOfPages
                //<PublicationDate>
                //            2009-09-01
                //            </PublicationDate>
                //            <Publisher>
                //            Oxford University Press, USA
                //            </Publisher>
                //            <Studio>
                //            Oxford University Press, USA
                //            </Studio>
                //            <Title>
                //            Mental Actions
                //            </Title>
                //            //<Subjects>
                //            <Subject>
                //            Philosophy of mind
                //            </Subject>
                //            <Subject>
                //            Philosophy
                //            </Subject>
                //            <EditorialReview>
                //            <Source>
                //            Product Description
                //            </Source>
                //            <Content>
                //            This volume investigates the neglected topic of mental action, and shows its importance for the metaphysics, epistemology, and phenomenology of mind. Twelve specially written essays address such questions as the following: Which phenomena should we count as mental actions--imagining, remembering, judging, for instance? How should we explain our knowledge of our mental actions, and what light does that throw on self-knowledge in general? What contributions do mental actions make to our consciousness? What is the relationship between the voluntary and the active, in the mental sphere? What are the similarities and differences between mental and physical action, and what can we learn about each from the other?
                //            </Content>
                //            </EditorialReview>
                //            </EditorialReviews>

            }
            setBiblioStateForItem(MD5ofRequest, true);

        }
        //MD52EbookMap[MD5ofRequest].b = true;
        if(this->getMd5ofCurrentItem() == MD5ofRequest )
        {
            setGuiEditForCurrentItem();
        }
    } if (dataSource == "isbndb")
    {
    //SKNCGPYT
        qDebug() << reply->readAll();
        qDebug() << reply->header(QNetworkRequest::LocationHeader);
    }
    //reply->abort();
    reply->close();
    reply->deleteLater();
    numOfFillBibliographyConnections--;
    if(numOfFillBibliographyConnections == 0)
    {
        this->onEndProcess();
    }
    ((guBookTreeItem*)MD52EbookMap[MD5ofRequest].item)->setBook(MD52EbookMap[MD5ofRequest]);
}
void guMainWindow::setBiblioStateForItem(QString MD5, bool setted)
{
    if(setted)
    {
        MD52EbookMap[MD5].biblioSetted = true;
        MD52EbookMap[MD5].item->setCheckState(4, Qt::Unchecked);
        MD52EbookMap[MD5].item->setText(4, "0%");
        //numOfDublicates++;
        //ui->labelNumOfDublicates->setNum(numOfDublicates);
        //добавить в БД инфу о том, что файл в библиотеке
        //setColorForItemByMd5(MD5, withBibliographyColor);

    }
    else
    {
        MD52EbookMap[MD5].biblioSetted = false;
        MD52EbookMap[MD5].item->setData(4, Qt::CheckStateRole, QVariant());
        MD52EbookMap[MD5].item->setText(4, "");
        //numOfDublicates++;
        //ui->labelNumOfDublicates->setNum(numOfDublicates);
        //добавить в БД инфу о том, что файл в библиотеке
        //if(!MD52EbookMap[MD5].ISBNs.isEmpty())
        //{
        //    setColorForItemByMd5(MD5, this->withIsbnColor);
        //}
        //else
        //{
        //    setColorForItemByMd5(MD5, Qt::transparent);
       // }
    }
    if(!ui->actionToogleShowWithBibliography->isChecked())
        MD52EbookMap[MD5].item->setHidden(true);
    else
    {
        MD52EbookMap[MD5].item->setHidden(false);
    }
}
QString guMainWindow::getParamValue(QDomDocument *document, QString param)
{
    QDomNodeList elementsList = document->elementsByTagName ( param );
    if(elementsList.count() != 0)
    {
        return elementsList.at(0).firstChild().nodeValue();
    }else
    {
        return "";
    }
}

void guMainWindow::processCheckDublicateReply(QNetworkReply* reply)
{
    //ошибка в обработке ответа от серв
    if (reply->error())
    {
        QMessageBox msgBox;
        msgBox.setText(tr("Ошибка сети: ") + reply->errorString() +
                       tr(" проверьте настройки соединения"));
         msgBox.exec();
        //отослать сигнал об ошибке
    }
    //{


    QString MD5ofRequest = reply->property("MD5").toString(); //извлечение MD5
    //qDebug() << MD5ofRequest;

    //log("MD5:" + MD5ofRequest + " error:" + reply->errorString() + " content type: " + reply->header(QNetworkRequest::ContentTypeHeader).toString());

    //qDebug() << "MD5:" + MD5ofRequest + " error:" + reply->errorString();

    //получение xml

    //2. создаем объект xml ответа
    QDomDocument doc("LGWS");
    //3. пробуем установить контент из ответа
    QString errMsg;
    int errorLine, errorColumn;
    if(!doc.setContent(reply, &errMsg, &errorLine, &errorColumn))
    {
        QMessageBox msgBox;
        msgBox.setText(tr("Error while parsing responce xml:") +
                       errMsg + tr(" in line ") +
                       QString::number(errorLine) + tr(" column ") +
                       QString::number(errorColumn) + reply->readAll());
         msgBox.exec();
         //закрываем ответ, удаляем
         reply->close();
          reply->deleteLater();
         return; //и выходим
    }
    qDebug() << "check responce" << doc.toString();
    QDomElement root = doc.documentElement();
    QString respType = root.attribute("type");

    if (respType == "error")
    {
        QString errCode = root.attribute("code");
        QMessageBox msgBox;
        msgBox.setText(tr("Error in responce code: ") +errCode);
        msgBox.exec();
        //закрываем ответ, удаляем
        reply->close();
        reply->deleteLater();
        return; //и выходим
    }
    if (respType == "new")
    {
        MD52EbookMap[MD5ofRequest].inLib = false;
        //установить все значения для книги

    }else
    {

        MD52EbookMap[MD5ofRequest].inLib = true;
        //strings
        MD52EbookMap[MD5ofRequest].title = getParamValue(&doc, "title");
        MD52EbookMap[MD5ofRequest].authors = getParamValue(&doc, "author");
        MD52EbookMap[MD5ofRequest].category = getParamValue(&doc, "topic");
        if(!MD52EbookMap[MD5ofRequest].category.isEmpty())
            MD52EbookMap[MD5ofRequest].categoryManualSetted = true;
        MD52EbookMap[MD5ofRequest].volume = getParamValue(&doc, "volumeInfo");
        MD52EbookMap[MD5ofRequest].publisher = getParamValue(&doc, "publisher");
        MD52EbookMap[MD5ofRequest].sity = getParamValue(&doc, "city");
        MD52EbookMap[MD5ofRequest].issue = getParamValue(&doc, "edition");

        QStringList identifiers = getParamValue(&doc, "identifier").split(";");
        for(int i = 0 ; i < identifiers.count(); i++)
        {
            QStringList isbnLst = identifiers.at(i).split(":");
            if(isbnLst.count() > 1)
            {
                isbnMethods check;
                QString isbn(check.cleanIsbn(isbnLst.at(1)));
                if(!this->MD52EbookMap[MD5ofRequest].ISBNs.contains(isbn))
                {
                    MD52EbookMap[MD5ofRequest].ISBNs.append(isbn);
                }

            }

        }
        //MD52EbookMap[MD5ofRequest].authors = getParamValue(&doc, "identifier");
        MD52EbookMap[MD5ofRequest].language = getParamValue(&doc, "language");
        MD52EbookMap[MD5ofRequest].collection = getParamValue(&doc, "library");
        MD52EbookMap[MD5ofRequest].collectionIssue = getParamValue(&doc, "issue");

        MD52EbookMap[MD5ofRequest].series = getParamValue(&doc, "series");
        MD52EbookMap[MD5ofRequest].periodical = getParamValue(&doc, "periodical");
        MD52EbookMap[MD5ofRequest].coverUrl = getParamValue(&doc, "coverUrl");
        MD52EbookMap[MD5ofRequest].UDC = getParamValue(&doc, "UDC");
        MD52EbookMap[MD5ofRequest].BBC = getParamValue(&doc, "LBC");
        MD52EbookMap[MD5ofRequest].ASIN = getParamValue(&doc, "ASIN");

        MD52EbookMap[MD5ofRequest].commentary = getParamValue(&doc, "comment");
        MD52EbookMap[MD5ofRequest].description = getParamValue(&doc, "description");
        //numbers
        MD52EbookMap[MD5ofRequest].pageNum = getParamValue(&doc, "pages").toInt();
        MD52EbookMap[MD5ofRequest].scanDpi = getParamValue(&doc, "dpi").toInt();
        //strings to ints
        //QString orientation = getParamValue(&doc, "orientation");
        MD52EbookMap[MD5ofRequest].orientation = getParamValue(&doc, "orientation").toInt();
        MD52EbookMap[MD5ofRequest].scanColor = getParamValue(&doc, "color").toInt();
        MD52EbookMap[MD5ofRequest].scanCleaned = getParamValue(&doc, "cleaned").toInt();

        numOfDublicates++;
        ui->labelNumOfDublicates->setNum(numOfDublicates);

        //добавить в БД инфу о том, что файл в библиотеке
        if(!ui->actionToogleShowDublicates->isChecked())
            MD52EbookMap[MD5ofRequest].item->setHidden(true);
        else
        {
            MD52EbookMap[MD5ofRequest].item->setHidden(false);
        }
    }
    MD52EbookMap[MD5ofRequest].inLibChecked = true;
    reply->close();
    reply->deleteLater();
    numOfCheckDublicateConnections--;
    if(numOfCheckDublicateConnections == 0)
    {
        //this->onEndProcess();
    }
    ((guBookTreeItem*)MD52EbookMap[MD5ofRequest].item)->setBook(MD52EbookMap[MD5ofRequest]);

}
void guMainWindow::initSearchFilesSettings()
{
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, "Irbis.Soft", "Library Genesis uploader (beta)");
    searchFilePath = settings.value("searchPath").toString();
    toSearchInSubFolders = settings.value("searchSubdirs",true).toBool();
    extractIsbnFromFiles = settings.value("extractIsbnFromFile",false).toBool();
    extractIsbnFromFileNames = settings.value("extractIsbnFromFileName",true).toBool();
    QStringList defaultSearchExtensions;
    defaultSearchExtensions << "*.chm" << "*.pdf" << "*.djvu";
    searchExtensions.clear();
    searchExtensions = settings.value("searchExtensions", defaultSearchExtensions).value<QStringList>();
}

//TODO реализовать добавление всех настроек
void guMainWindow::initBaseSettings()
{
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, "Irbis.Soft", "Library Genesis uploader (beta)");

    //serviceUrl = settings.value("serviceUrl", "http://free-books.dontexist.com/lgws").toString();
    serviceUrl = settings.value("serviceUrl", "http://libgen.org/").toString();
    uploader->setServiceUrl(serviceUrl);
    uploader->setAuthInfo("genesis", "upload");

    dublicateColor = settings.value("dublicateColor").value<QColor>();
    withIsbnColor = settings.value("isbnColor").value<QColor>();
    withBibliographyColor = settings.value("biblioColor").value<QColor>();
    uploadedColor = settings.value("uploadedColor").value<QColor>();
    categorySelectedColor = settings.value("catSelectColor").value<QColor>();

    //прокси сервер (пока не используется)
    useApplicationProxy = settings.value("useMainProxy", false).toBool();
    if(useApplicationProxy)
    {
        qDebug() << "use proxy";
        //this->applicationProxy = new QNetworkProxy(QNetworkProxy::HttpProxy,"192.168.192.1", 3128, "", "");
        applicationProxy.setType(QNetworkProxy::HttpProxy);
        applicationProxy.setHostName("192.168.192.1");
        applicationProxy.setPort(3128);
        applicationProxy.setUser("");
        applicationProxy.setPassword("");
        QNetworkProxy::setApplicationProxy(applicationProxy);
    }
    //setColumnHidden ( int, bool )
}
//-----------------------------------------------------------------------
// onInspectFolder() - функция запуска процесса инспектирования папки
//
//-----------------------------------------------------------------------
void guMainWindow::onInspectFolder()
{
    guFindBookFilesDialog findDialog;
    findDialog.setModal(true);
    findDialog.setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::WindowTitleHint| Qt::CustomizeWindowHint);
    int retCode = findDialog.exec();
    //qDebug() << "ret code is "<< retCode;
    if (retCode == 0)
    {
        return;
    }
    initSearchFilesSettings();
    //else
   // {
    //    initSettings();
    //}


    //очищаем все дерево файлов
    ui->treeWidgetFiles->clear();
    MD52EbookMap.clear();

    ui->stackedWidget->setCurrentIndex(2);


    onStartProcess();
    ui->labelProcessStatus->setText(tr("Идет поиск книг..."));
    //устанавливаем счетчики в ноль
    //TODO: когда инфа будет загружаться из бд - вынести отсюда, чтобы не все обнулялось
    numOfInspected = 0;  //количество проверенных
    numOfDublicates = 0; //количество дубликатов
    numOfNew = 0;        //количество новых
    numOfWithIsbn = 0;   //количество с ISBN
    numOfUploaded = 0;   //количество загруженных на сервер

    numOfWithBiblio = 0; //количество с библиографией
    //деактивируем команды для работы со списком книг:
    ui->actionGetBiblioInfo->setEnabled(false); //нам НЕ нужно в это время получать биб. инф. для книг
    ui->actionUploadToServer->setEnabled(false); //нам НЕ нужно в это время загружать на сервер книги
    //активируем функцию прерывания инспектирования
    ui->actionAbortInspectProcess->setEnabled(true); //мы можем прервать процесс инспектирования
    inspector->inspectFolder(searchFilePath,
                  searchExtensions,
                  toSearchInSubFolders,
                  extractIsbnFromFiles,
                  extractIsbnFromFileNames);
}
//-----------------------------------------------------------------------
// onInspectFinished() - обработка сигнала о завершении процесса
//                       инспектирования
//-----------------------------------------------------------------------
void guMainWindow::onInspectFinished()
{
    onEndProcess();
    //Активируем команды для работы со списком книг:
    ui->actionGetBiblioInfo->setEnabled(true); //мы уже можем получать биб. инф. для книг
    ui->actionUploadToServer->setEnabled(true); //мы уже можем загружать на сервер книги
    //Деактивируем функцию прерывания инспектирования
    ui->actionAbortInspectProcess->setEnabled(false); //процесс закончился, нам нечего прерывать
    //теперь сообщим пользователю, что процесс окончен
    QMessageBox msgBox;
    QString msgText;
    msgText += tr("Проинспектирована директория: \n");
    msgText += searchFilePath + "\n";
    msgText += tr("Всего файлов найдено: ") + QString::number(numOfInspected) + "\n";
    msgText += tr("Из них в библиотеке: ") + QString::number(numOfDublicates) + "\n";
    msgText += tr("Новых: ") + QString::number(numOfNew) + "\n";
    msgText += tr("Для ") + QString::number(numOfWithIsbn) + tr(" найдены ISBN.");
    msgBox.setText(msgText);
    msgBox.setWindowTitle(tr("Процесс инспектирования завершен."));
    msgBox.exec();

}

//-----------------------------------------------------------------------
// onGetBiblioInfo() - функция получения биб. данных для всех записей,
//                     у которых имеется ISBN
//-----------------------------------------------------------------------
void guMainWindow::onGetBiblioInfo()
{
    QMapIterator<QString, ebook> i(MD52EbookMap);
    while (i.hasNext()) {
        i.next();
        //проверяем не дубль ли это, не загружена ли уже библиография и есть ли ИСБН(ы)
        if (!i.value().inLib && !i.value().biblioSetted && !i.value().ISBNs.empty())
        {
            fillBibliography(i.key(), "amazon"); //"amazon" isbndb
        }
    }
}

void guMainWindow::onUploadToServer()
{
    if (MD52EbookMap.isEmpty())
        return;



    qDebug() << "map size " << MD52EbookMap.count();
    QMapIterator<QString, ebook> i(MD52EbookMap);
    while (i.hasNext()) {
        i.next();
        //проверка на загрузку
        //TODO убрать лишний код
        if(i.value().item->checkState(0) == Qt::Checked)
        {
            if(i.value().fileSize > (209715200))
            {
                //i.value().item->setData(0, Qt::CheckStateRole, QVariant());
                //i.value().item->setText(0,tr("> 200 Мб"));
            }
            else
            {
                ui->labelProcessStatus->setText(tr("Идет загрузка книг..."));
                onStartProcess();
                i.value().item->setData(0, Qt::CheckStateRole, QVariant());
                i.value().item->setText(0,tr("в очереди"));

                ((guBookTreeItem*)(i.value().item))->setUploadStarted();
                uploader->uploadEbook(i.value());
            }
            //uploadEbook(i.value());
        }
    }
    //    QTreeWidgetItemIterator it(ui->treeWidgetFiles);
    //        while (*it) {
    //            if ((*it)-> == itemText)
    //                (*it)->setSelected(true);
    //            ++it;
    //        }

}
void guMainWindow::onFilesTreeDoubleClicked(QTreeWidgetItem* item,int column)
{
    if (column == 1)//изображение файла
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile( MD52EbookMap[getMd5ofCurrentItem()].filePath));
    }
}
//справка и поддержка
void guMainWindow::onShowAbout()
{
    //guAboutDialog
    guAboutDialog aboutDlg;
    aboutDlg.setModal(true);
    aboutDlg.setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::WindowTitleHint| Qt::CustomizeWindowHint);
    aboutDlg.exec();
}
void guMainWindow::onHelp()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile( qApp->applicationDirPath() + "/tutorial.chm"));
}
