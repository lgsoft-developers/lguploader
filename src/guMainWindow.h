#ifndef guMainWindow_h
#define guMainWindow_h
//заголовочные файлы Qt
#include <QtCore>                   //Модуль ядра приложения
#include <QtGui>                    //Модуль GUI - интерфейс
#include <QtNetwork>                //Модуль сетевого взаимодействия
#include <QtSql>                    //Модуль работы с базами данных

//#include "qtsoap/qtsoap.h"
//заголовочные файлы программы
#include "guFolderInspector.h" //код поиска книг, извлечения идентификаторов вынесенный в поток
#include "dataStructures.h"    //структуры данных для хранения информации о книгах
#include "guBookUploader.h"    //загрузка книги, вынесена в отдельный класс
#include "guLogger.h"          //запись в лог

namespace Ui {
    class guMainWindow;
}

//класс, переопределяющий resizeEvent класса QGraphicsView для отображения обложки
//на всю доступную область
class GraphicsViewEx : public QGraphicsView
{
public:
    GraphicsViewEx(QGraphicsScene *scene)
        : QGraphicsView(scene)
    {}
protected:
    //событие, возникающее каждый раз при изменении размеров виджета
    void resizeEvent(QResizeEvent *event)
    {
            if (this->scene()->items().count() == 0)//если на сцене еще нет элементов
                return;//выходим
            //иначе получаем первый элемент (так как он всего один - обложка книги)
            QGraphicsItem *item = this->scene()->items().at(0);
            //и масштабируем View под обложку с сохранением пропорций
            this->fitInView(item,Qt::KeepAspectRatio);
    }
};
//класс главного окна
class guMainWindow : public QMainWindow {
    Q_OBJECT
public:
    guMainWindow(QWidget *parent = 0);
    ~guMainWindow();
protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *event);

private:
    Ui::guMainWindow *ui;               //GUI интерфейс
    GraphicsViewEx *graphicsView;       //графический виджет для отображения обложек
    QGraphicsScene *coverScene;         //графическая сцена на которой будут выводиться обложки

    QMap<QString, ebook> MD52EbookMap;  //набор MD5 - объект "книга" из dataStructures.h

    //ПОИСК ФАЙЛОВ
    guFolderInspector *inspector;       //поток, в котором инспектируются директории
    bool toSearchInSubFolders;          //признак, осуществлять ли поиск в поддиректориях
    QString searchFilePath;             //папка, в которой осущетсвляется поиск книг
    QStringList searchExtensions;       //расширения файлов для поиска
    bool extractIsbnFromFiles;          //признак, извлекать ли ISBN из файлов
    bool extractIsbnFromFileNames;      //признак, извлекать ли ISBN из имен файлов

    //СЕТЬ (пока не используется)
    bool useApplicationProxy;          //используем ли прокси
    QNetworkProxy applicationProxy;    //прокси для всего приложения

    //SOAP (задел на случай использования soap)
    //QtSoapHttpTransport soap;
    //ПРОВЕРКА НА ДУБЛИКАТЫ
    //2. Проверка посредством HTTP запросов
    QNetworkAccessManager *httpCheckDublicatesManager;      //проверка на дубликаты через HTTP
    int numOfCheckDublicateConnections;           //количество HTTP отправленных запросов для проверки на дубль

    //ЗАГРУЗКА (UPLOADING)
    //
    QString serviceUrl;
    guBookUploader *uploader;           //загрузчик на сервер

    //ЛОГИРОВАНИЕ
    guLogger      *logger;              //логгер

    //ПОИСК БИБЛИОГРАФИЧЕСКОЙ ИНФОРМАЦИИ
    int numOfFillBibliographyConnections;                   //кол-во запросов, отправленных на поиск инфо
    QNetworkAccessManager *httpFillBibliographyManager;     //поиск в онлайн источниках биб. данных
    QNetworkAccessManager *coverLoaderManager;

    //СТАТИСТИКА
    int numOfInspected;  //количество проверенных
    int numOfDublicates; //количество дубликатов
    int numOfNew;        //количество новых
    int numOfWithIsbn;   //количество с ISBN
    int numOfWithBiblio;
    int numOfUploaded;   //количество загруженных на сервер

    //ИНТЕРФЕЙС
    //отображение процесса выполнения задачи
    QTimer *processTimer;           //таймер
    //цвета индикации записей
    QColor dublicateColor;          //цвет дубликата
    QColor withIsbnColor;           //цвет книги с хотя бы одним ISBN
    QColor withBibliographyColor;   //цвет книги с заполненной библиографией
    QColor uploadedColor;           //цвет книги, загруженной на сервер
    //дополнительные значения цвета
    QColor categorySelectedColor;   //подсветка выбранной категории в дереве категорий


    void checkEbookDublicate(QString MD5);      //проверить книгу на дубль
    void fillBibliography(QString MD5, QString dataSource);//получить библиографию для книги с указанного источника

    QString getMd5ofCurrentItem();  //получение MD5 текущего item в списке книг
    //установить статус "с библиографией" или "без" для итема по его MD5
    void setBiblioStateForItem(QString MD5, bool setted);
    //проверка, все ли поля достаточно заполнены
    bool isBiblioFull(QString MD5);
    void updateStatusLabels();
public slots:
    void show();
private slots:
    //TEST
    void onGetSoapResponse();
    void testWebService();

    void loadCover(QString MD5, QString coverUrl);
    void onCopyMD5ToClipboard();
    void onOpenCurrentEbook();                          //открыть книгу
    //установка значений для всех найденных книг
    //TODO: заменить - объединить в группу и по id устанавливать значения
    void onSetLibraryForAllBooks();
    void onSetLibraryIssueForAllBooks();
    void onSetPeriodicalForAllBooks();
    void onSetTitleForAllBooks();
    void onSetAuthorsForAllBooks();
    void onSetSeriesForAllBooks();
    void onSetPublisherForAllBooks();
    void onSetSityForAllBooks();
    void onSetUdcForAllBooks();
    void onSetPubYearForAllBooks();
    void onSetBbcForAllBooks();
    void onSetLanguageForAllBooks();
    void onSetOrientationForAllBooks();
    void onSetScanDpiForAllBooks();
    void onSetColorScanForAllBooks();
    void onSetCleanScanForAllBooks();

    //для работы с DOM
    QString getParamValue(QDomDocument *document, QString param);
    void onSetCategoryForAllBooks();
    void onSetCommentaryForAllBooks();
    void onAbortInspectProcess();
    void onAllEbooksUploaded();     //обработка сигнала от аплодера о том, что его очередь загрузок пуста
    void onShowAbout();
    void onHelp();

    void initBaseSettings();           //загрузка параметров из сохраненных настроек программы
    void initSearchFilesSettings();

    void processCheckDublicateReply(QNetworkReply* reply); //обработчик ответов от проверки на дубликат
    void processFillBibliographyReply(QNetworkReply* reply);//обработчик ответов от заполнения биб. данных
    void processLoadCoverReply(QNetworkReply *reply);
    //обработка сигналов от списка файлов
    void onCurrentFileChanged(QTreeWidgetItem * current, QTreeWidgetItem * previous); //обработка вывода инфо о файле
    void onFilesTreeDoubleClicked(QTreeWidgetItem* item,int column);

    //обработка сигналов от инспектора
    void onAddNewEbook(QString MD5, ebook newEbook); //добавление новой книги
    void onDublicateFinded();                        //найден дубль
    void onInspectFinished();                        //инспектирование завершено

    void onStartProcess(); //
    void onEndProcess();   //
    void onTimerTimeout(); //

    //обработка сигналов от дерева категорий
    void onCurrentCategoryChanged(QTreeWidgetItem * current, QTreeWidgetItem * previous);//обработка изменения категории(тематики) файла
    void onCurrentCategoryChangedFillStr(QTreeWidgetItem * current, QTreeWidgetItem * previous);

    //очистка полей ввода
    void clearEditFields();

    //gui actions
    //1. Для всего списка книг
    void onInspectFolder(); //команда - инспектировать папку
    void onGetBiblioInfo(); //команда - получить биб. инф-ю для всех книг, у которых есть ISBN
    void onUploadToServer();//команда - загрузить на сервер все отмеченные книги и инф-ю
    void onFileListRight();
    void onFileListLeft();


    //2. Для конкретной книги
    void onGetBiblioForCurrentEbook(); //команда - получить биб. информацию для текущей книги
    void setGuiEditForCurrentItem();                             //задание значения полей ввода для текущей книги
    void onSaveChangesForBook();                                 //обработка сохранения биб. инфо

    //ЗАГРУЗКА (UPLOADING)
    void onUploadEbookProgress(QString MD5OfUpload,int persent); //обработка инфо о процессе загрузки файла
    void onUploadEbookFinished(QString MD5);                     //обработка завершения загрузки файла

    void onShowSettingsDialog();  //команда - вызов диалога настроек

    //обработка сигналов о ручном вводе-удалении ИСБН
    void onIsbnFieldChanged(QString isbn); //обработка ввода ISBN
    void onIsbnsListItemActivated();       //выбор ISBNа из списка
    void onAddIsbn();                      //вызов добавления ISBNа из lineEdit а
    void onRemoveIsbn();                   //вызов удаления ISBNа из списка

    void onAddIsbnToEbook(QString MD5, QString ISBN);      //обработка добавления ISBNа для книги
    void onRemoveIsbnFromEbook(QString MD5, QString ISBN); //обработка удаления ISBNа для книги

    //обработка сигналов о вводе в поля библиографической информации
    void onCommentaryTextChanged(QString);
    void onTitleTextChanged(const QString newText);
    void onAuthorsTextChanged(QString);
    void onSeriesTextChanged(QString);
    void onPublisherTextChanged(QString);
    void onUdcTextChanged(QString);
    void onBbcTextChanged(QString);
    void onPubYearTextChanged(QString);
    void onPageNumTextChanged(QString);
    void onIssueTextChanged(QString);
    void onVolumeTextChanged(QString);
    void onLanguageTextChanged(QString);
    void onDescriptionTextChanged();
    void onSityTextChanged(QString sity);
    void onPeriodicalTextChanged(QString periodical);
    void onCategoryTextChanged(QString);
    void onOrientationIndexChanged(int index);
    void onBiblioTextChanged(QString biblio);
    void onDpiTextChanged(QString dpi);
    void onDvdNumTextChanged(QString dvdNum);
    void onColorScanStateChanged(int scanState);
    void onClearScanStateChanged(int clearState);
    void onSelectAllToUploadToogled(bool select);
    void onSubjectIndexChanged(int index);

    //изменение списка отображаемых item'ов
    void onToogleShowDublicates(bool show);       //показать/скрыть записи - дубли
    void onToogleShowUploaded(bool show);         //показать/скрыть загруженные книги
    void onToogleShowWithISBN(bool show);         //показать/скрыть записи с ISBN
    void onToogleShowWithBibliography(bool show); //показать/скрыть записи с биб. информацией
signals:
    void abortInspectProcess();
};
#endif // guMainWindow_h
