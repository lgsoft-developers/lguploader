#include "guAboutDialog.h"
#include "ui_guAboutDialog.h"

guAboutDialog::guAboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guAboutDialog)
{
    ui->setupUi(this);
}

guAboutDialog::~guAboutDialog()
{
    delete ui;
}

void guAboutDialog::changeEvent(QEvent *e)
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
