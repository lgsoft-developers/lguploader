#ifndef dataStructures_h
#define dataStructures_h
#include <QString>
#include <QTreeWidgetItem>
struct ebook
{
    QString MD5;
    bool    inLib;              //признак, присутствует ли уже в БД
    bool    inLibCheckSended;   //проверка, отправлен ли запрос на проверку на дубли
    bool    inLibChecked;       //признак, проверено ли на дублирование
    bool    biblioSetted;       //признак, заполнена ли библиография
    bool    uploaded;           //признак, загружена ли книга на сервер
    bool    toUpload;           //признак, загружать ли книгу на сервер

    //Категории (Topics)
    QString category;                  //категория (топик)
    //1. категории, которые берутся из дерева categoryTreeSetted
    bool categoryTreeSetted;           //признак, указана ли категория из дерева категорий
    QTreeWidgetItem *categoryItem;     //указатель на итем в дереве категорий, выбранный пользователем
    //2. категории, которые берутся из онлайн источника
    bool catogorySubjectSetted;        //признак, выбрал ли пользователь категорию из списка subjects
    QStringList subjects;              //список категорий, полученных из онлайн источников subjectSetted
    int  subjectIndex;                 //номер категории в списке, выбранный пользователем
    //3. категория, которую пользователь может ввести сам
    bool categoryManualSetted;         //признак, если пользователь сам вручную ввел категорию

    //Информация о файле
    QString fileName;                  //имя файла
    QString filePath;                  //полный путь к файлу
    QString fileExtension;             //расширение файла
    int     fileSize;                  //размер файла в байтах
    //Идентификаторы
    QList<QString> ISBNs;              //ИСБНы (если список нулевой - исбн не указан)

    //Библиография
    ///! - инфа, обязательная к заполнению(если она не получена из онлайн источников)
    QString authors;            //авторы            !
    QString title;              //заголовок         !
    QString series;             //серия
    QString publisher;          //издательство      !
    QString sity;               //город
    QString periodical;         //периодика
    QString BBC;                //ББК
    QString UDC;                //УДК
    int pubYear;                //год издания (0 - не указано) !
    int pageNum;                //кол-во страниц (0 - не указано)  !
    QString issue;              //издание
    QString volume;             //том
    QString  language;          //язык TODO: сделать выбор языка из списка
    QString collection;         //импортируемая коллекция-источник
    QString collectionIssue;    //номер выпуска импортируемой коллекции-источника

    int orientation;            //ориентация книги (0 - не указано, 1 - portrait, 2 - landscape)

    int scanDpi;                //разрешение скана (0 - не указано)
    int scanColor;              //цветной скан (0 - не указано, 1 - yes, 2 - no)
    int scanCleaned;            //очищенный скан (0 - не указано, 1 - yes, 2 - no)
    QString description;        //описание (аннотация)
    QString commentary;
    //обложки
    QString coverUrl;
    QString ASIN;
    QPixmap cover;

    QTreeWidgetItem *item; //указатель на GUI в списке файлов
};

#endif // dataStructures_h
