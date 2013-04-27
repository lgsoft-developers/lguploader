#include "guSettDialog.h"
#include "ui_guSettDialog.h"
#include <QFileDialog>
#include <QTextCodec>
#include <QSettings>
#include <QObject>
#include <QColorDialog>
#include <QDebug>

//#define TEST
guSettDialog::guSettDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guSettDialog)
{
    ui->setupUi(this);
    initColors();
    inLibFileActions = new QButtonGroup(this);
    inLibFileActions->addButton(ui->radioButtonInLibNoAction, 0);
    inLibFileActions->addButton(ui->radioButtonInLibRemove, 1);
    inLibFileActions->addButton(ui->radioButtonInLibMoveToRep, 2);
    inLibFileActions->addButton(ui->radioButtonInLibCopyToRep, 3);

    loadSettings();
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));
    connect(ui->pushButtonExit, SIGNAL(clicked()), this, SLOT(reject()));
    connect(ui->pushButtonSet, SIGNAL(clicked()), this, SLOT(onSaveSettings()));


    connect(ui->listWidgetSettGroup, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)), this, SLOT(currentSettGroupChanged(QListWidgetItem*,QListWidgetItem*)));
    connect(ui->listWidgetSettGroup, SIGNAL(currentRowChanged(int)), this, SLOT(currentSettGroupChanged(int)));
    ui->listWidgetSettGroup->setCurrentRow(0);
    connect(ui->pushButtonDublicate, SIGNAL(clicked()), this, SLOT(onChangeDublicateColor()));
    connect(ui->pushButtonIsbn, SIGNAL(clicked()), this, SLOT(onChangeIsbnColor()));
    connect(ui->pushButtonBiblio, SIGNAL(clicked()), this, SLOT(onChangeBiblioColor()));
    connect(ui->pushButtonUploaded, SIGNAL(clicked()), this, SLOT(onChangeUploadColor()));
    connect(ui->pushButtonCategory, SIGNAL(clicked()), this, SLOT(onChangeCategoryColor()));

    ui->pushButtonDublicate->setStyleSheet(colorToStyle(dublicateColor));
    ui->pushButtonIsbn->setStyleSheet(colorToStyle(isbnColor));
    ui->pushButtonBiblio->setStyleSheet(colorToStyle(biblioColor));
    ui->pushButtonUploaded->setStyleSheet(colorToStyle(uploadedColor));
    ui->pushButtonCategory->setStyleSheet(colorToStyle(categoryColor));


}
void guSettDialog::loadSettings()
{

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, "Irbis.Soft", "Library Genesis uploader (beta)");

    ui->lineEditServiceUrl->setText(settings.value("serviceUrl", "http://free-books.dontexist.org/lgws").toString());

    dublicateColor = settings.value("dublicateColor", dublicateColor).value<QColor>();
    isbnColor = settings.value("isbnColor", isbnColor).value<QColor>();
    biblioColor = settings.value("biblioColor", biblioColor).value<QColor>();
    uploadedColor = settings.value("uploadedColor", uploadedColor).value<QColor>();
    categoryColor = settings.value("catSelectColor", categoryColor).value<QColor>();

    //настройки переноса файлов после загрузки
    int inLibActionId = settings.value("inLibFileAction", 0).toInt();
    inLibFileActions->button(inLibActionId)->setChecked(true);
//    QString dataSources;
//    for(int i = 0; i < ui->listWidgetUsedDataSources->count() ; i++)
//    {
//        dataSources += ui->listWidgetUsedDataSources->item(i)->text() + ";";
//    }
//    settings.value("dataSources", dataSources);
}

void guSettDialog::initColors()
{
    dublicateColor = QColor(245, 152, 157, 255);
    isbnColor      = QColor(131, 147, 202, 255);
    biblioColor    = QColor(28,  187, 180, 255);
    uploadedColor  = QColor(163, 211, 156, 255);
    categoryColor  = QColor(32, 139, 181, 255);
}

guSettDialog::~guSettDialog()
{
    delete ui;
}
void guSettDialog::onSaveSettings()
{
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, "Irbis.Soft", "Library Genesis uploader (beta)");

    settings.setValue("serviceUrl",ui->lineEditServiceUrl->text());
    settings.setValue("dublicateColor", dublicateColor);
    settings.setValue("isbnColor", isbnColor);
    settings.setValue("biblioColor", biblioColor);
    settings.setValue("uploadedColor", uploadedColor);
    settings.setValue("catSelectColor", categoryColor);
    QString dataSources;
    for(int i = 0; i < ui->listWidgetUsedDataSources->count() ; i++)
    {
        dataSources += ui->listWidgetUsedDataSources->item(i)->text() + ";";
    }
    settings.setValue("dataSources", dataSources);

    settings.sync();
    accept();
}


void guSettDialog::currentSettGroupChanged(int currentIndex)
{
    ui->stackedWidgetSettTabs->setCurrentIndex(currentIndex);
}

void guSettDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
void guSettDialog::onChangeDublicateColor()
{
    QColor color;
    color = QColorDialog::getColor(dublicateColor,this, tr("Выберите цвет индикации дубликатов"));
    if(color.isValid())
    {
        ui->pushButtonDublicate->setStyleSheet(colorToStyle(color));
        dublicateColor = color;

    }
}
void guSettDialog::onChangeIsbnColor()
{
    QColor color;
    color = QColorDialog::getColor(isbnColor,this, tr("Выберите цвет индикации книг с ИСБН"));
    if(color.isValid())
    {
        ui->pushButtonDublicate->setStyleSheet(colorToStyle(color));
        isbnColor = color;

    }
}
void guSettDialog::onChangeBiblioColor()
{
    QColor color;
    color = QColorDialog::getColor(biblioColor,this, tr("Выберите цвет индикации книг с библиографией"));
    if(color.isValid())
    {
        ui->pushButtonBiblio->setStyleSheet(colorToStyle(color));
        biblioColor = color;

    }
}
void guSettDialog::onChangeUploadColor()
{
    QColor color;
    color = QColorDialog::getColor(dublicateColor,this, tr("Выберите цвет индикации загруженных книг"));
    if(color.isValid())
    {
        ui->pushButtonUploaded->setStyleSheet(colorToStyle(color));
        dublicateColor = color;

    }
}

void guSettDialog::onChangeCategoryColor()
{
    QColor color;
    color = QColorDialog::getColor(categoryColor,this, tr("Выберите цвет индикации выбранной категории"));
    if(color.isValid())
    {
        ui->pushButtonCategory->setStyleSheet(colorToStyle(color));
        categoryColor = color;

    }
}
QString guSettDialog::colorToStyle(QColor color)
{
    QString strColor("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(");
    strColor += QString::number(color.red()) +", " +
               QString::number(color.green()) +", " +
               QString::number(color.blue()) +", " +
               QString::number(color.alpha()) +"))";
    return strColor;
}

