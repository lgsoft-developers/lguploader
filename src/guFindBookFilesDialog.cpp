#include "guFindBookFilesDialog.h"
#include "ui_guFindBookFilesDialog.h"
#include <QFileDialog>
#include <QTextCodec>
#include <QMessageBox>
guFindBookFilesDialog::guFindBookFilesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guFindBookFilesDialog)
{
    ui->setupUi(this);
    extGroup = new QButtonGroup(this);
    extGroup->setExclusive(false);
    extGroup->addButton(ui->checkBoxPDF);ui->checkBoxPDF->setProperty("ext","*.pdf");
    extGroup->addButton(ui->checkBoxDJVU);ui->checkBoxDJVU->setProperty("ext","*.djvu");
    extGroup->addButton(ui->checkBoxCHM);ui->checkBoxCHM->setProperty("ext","*.chm");
    extGroup->addButton(ui->checkBoxCBZ);ui->checkBoxCBZ->setProperty("ext","*.cbz");
    extGroup->addButton(ui->checkBoxDOC);ui->checkBoxDOC->setProperty("ext","*.doc");
    extGroup->addButton(ui->checkBoxDOCX);ui->checkBoxDOCX->setProperty("ext","*.docx");
    extGroup->addButton(ui->checkBoxEXE);ui->checkBoxEXE->setProperty("ext","*.exe");
    extGroup->addButton(ui->checkBoxFB2);ui->checkBoxFB2->setProperty("ext","*.fb2");
    extGroup->addButton(ui->checkBoxHTM);ui->checkBoxHTM->setProperty("ext","*.htm");
    extGroup->addButton(ui->checkBoxHTML);ui->checkBoxHTML->setProperty("ext","*.html");
    extGroup->addButton(ui->checkBoxISO);ui->checkBoxISO->setProperty("ext","*.iso");
    extGroup->addButton(ui->checkBoxMHT);ui->checkBoxMHT->setProperty("ext","*.mht");

    extGroup->addButton(ui->checkBoxPS);ui->checkBoxPS->setProperty("ext","*.ps");
    extGroup->addButton(ui->checkBoxPSGZ);ui->checkBoxPSGZ->setProperty("ext","*.ps.gz");
    extGroup->addButton(ui->checkBoxRAR);ui->checkBoxRAR->setProperty("ext","*.rar");
    extGroup->addButton(ui->checkBoxRTF);ui->checkBoxRTF->setProperty("ext","*.rtf");
    extGroup->addButton(ui->checkBoxTXT);ui->checkBoxTXT->setProperty("ext","*.txt");
    extGroup->addButton(ui->checkBoxZIP);ui->checkBoxZIP->setProperty("ext","*.zip");
    extGroup->addButton(ui->checkBoxHA);ui->checkBoxHA->setProperty("ext","*.ha");
    extGroup->addButton(ui->checkBoxXHTML);ui->checkBoxXHTML->setProperty("ext","*.xhtml");

    loadSettings();
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));
    connect(ui->pushButtonExit, SIGNAL(clicked()), this, SLOT(reject()));
    connect(ui->pushButtonSet, SIGNAL(clicked()), this, SLOT(onSaveSettings()));

    connect(ui->pushButtonSelectFolder, SIGNAL(clicked()), this, SLOT(onSelectFolderClicked()));
}

guFindBookFilesDialog::~guFindBookFilesDialog()
{
    delete ui;
}

void guFindBookFilesDialog::changeEvent(QEvent *e)
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
void guFindBookFilesDialog::onSelectFolderClicked()
{
    QString resultFolder;
    resultFolder = QFileDialog::getExistingDirectory(this, tr("Выберите директорию для поиска файлов"),
                                                             searchPath,
                                                             QFileDialog::ShowDirsOnly
                                                             | QFileDialog::DontResolveSymlinks);
    if (resultFolder != "")
    {
        searchPath = resultFolder;
        ui->lineEditSearchPath->setText(searchPath);
    }
}
void guFindBookFilesDialog::loadSettings()
{

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, "Irbis.Soft", "Library Genesis uploader (beta)");
    ui->checkBoxFindRecursive->setChecked(settings.value("searchSubdirs", false).toBool());
    //настройки извлечения ИСБН из файла
    ui->checkBoxExtractIsbnFromFile->setChecked(settings.value("extractIsbnFromFile", true).toBool());
    //настройки извлечения ИСБН из имени файла
    ui->checkBoxExtractIsbnFromFileName->setChecked(settings.value("extractIsbnFromFileName", true).toBool());

    this->searchPath = settings.value("searchPath", qApp->applicationDirPath()).toString();
    ui->lineEditSearchPath->setText(searchPath);

    QStringList defaultSearchExtensions;
    defaultSearchExtensions << "*.pdf" << "*.chm" << "*.djvu";
    searchExtensions = settings.value("searchExtensions", defaultSearchExtensions).value<QStringList>();
    for(int i = 0 ; i < extGroup->buttons().count() ; i++ )
    {
        QString ext = extGroup->buttons().at(i)->property("ext").toString();
        if (searchExtensions.contains(ext))
        {
            extGroup->buttons().at(i)->setChecked(true);
        }

    }

}
void guFindBookFilesDialog::onSaveSettings()
{
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, "Irbis.Soft", "Library Genesis uploader (beta)");
    //настройка папки для поиска
    settings.setValue("searchPath", searchPath);
    //настройка поиска в подпапках
    settings.setValue("searchSubdirs", ui->checkBoxFindRecursive->isChecked());
    //настройки извлечения ИСБН из файла
    settings.setValue("extractIsbnFromFile", ui->checkBoxExtractIsbnFromFile->isChecked());
    //настройки извлечения ИСБН из имени файла
    settings.setValue("extractIsbnFromFileName", ui->checkBoxExtractIsbnFromFileName->isChecked());
    //настройки перемещения в папку файлов, не удовлетворяющих маске поиска
    searchExtensions.clear();
    for(int i = 0 ; i < extGroup->buttons().count() ; i++ )
    {
        if (extGroup->buttons().at(i)->isChecked())
        {
           searchExtensions <<  extGroup->buttons().at(i)->property("ext").toString();
        }
    }
    if (searchExtensions.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText(tr("Выберите хотя бы одно расширение для поиска."));
         msgBox.exec();
        return;
    }
    settings.setValue("searchExtensions", searchExtensions);

    settings.sync();
    accept();
}
