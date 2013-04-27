#include <QtGui/QApplication>
#include "guMainWindow.h"
#include "guSettDialog.h"
#include <QSettings>
#include <QCoreApplication>
#include <QFile>
#include <QMessageBox>
//#define TEST  //макрокоманда для целей тестирования
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, "Irbis.Soft", "Library Genesis uploader (beta)");
#ifdef TEST //если тестируем

    //удаляем файл базы данных
    if (QFile::exists(qApp->applicationDirPath() + "/gu.sqlite"))
        QFile::remove(qApp->applicationDirPath() + "/gu.sqlite");
#endif
    if (!settings.contains("version"))//простая проверка на то, существуют ли настройки в системе
    {

        settings.clear(); //очищаем настройки
        settings.setValue("version","0.4");
        settings.sync();
        guSettDialog settDlg;           //диалог настроек
        settDlg.setModal(true);         //делаем модальным
        settDlg.setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::WindowTitleHint| Qt::CustomizeWindowHint);
        int retCode = settDlg.exec();   //получаем код возврата
        if (retCode == 0)               //если нажато "Отмена"
        {
            return 0;                   //выходим из программы
        }
    }
    //если же настройки есть или мы их создали
    guMainWindow w;                     //создаем главное окно
    w.show();                           //показываем
    return a.exec();                    //запуск цикла обработки сообщений
}
