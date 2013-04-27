#ifndef GUFINDBOOKFILESDIALOG_H
#define GUFINDBOOKFILESDIALOG_H

#include <QDialog>
#include <QSettings>
#include <QButtonGroup>

namespace Ui {
    class guFindBookFilesDialog;
}

class guFindBookFilesDialog : public QDialog {
    Q_OBJECT
public:
    guFindBookFilesDialog(QWidget *parent = 0);
    ~guFindBookFilesDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::guFindBookFilesDialog *ui;

    QString searchPath;    //путь к папке, где будет осуществляться поиск
    QStringList searchExtensions;
    QButtonGroup *extGroup;

public slots:
    //обработчики событий интерфейса
    void onSelectFolderClicked();      //выбор папки для сканирования
    void onSaveSettings();
    void loadSettings();
signals:
};

#endif // GUFINDBOOKFILESDIALOG_H
