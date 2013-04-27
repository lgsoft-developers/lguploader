#ifndef GUABOUTDIALOG_H
#define GUABOUTDIALOG_H

#include <QDialog>

namespace Ui {
    class guAboutDialog;
}

class guAboutDialog : public QDialog {
    Q_OBJECT
public:
    guAboutDialog(QWidget *parent = 0);
    ~guAboutDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::guAboutDialog *ui;
};

#endif // GUABOUTDIALOG_H
