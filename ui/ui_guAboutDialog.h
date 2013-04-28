/********************************************************************************
** Form generated from reading UI file 'guAboutDialog.ui'
**
** Created: Sun 28. Apr 10:51:02 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUABOUTDIALOG_H
#define UI_GUABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_guAboutDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *guAboutDialog)
    {
        if (guAboutDialog->objectName().isEmpty())
            guAboutDialog->setObjectName(QString::fromUtf8("guAboutDialog"));
        guAboutDialog->resize(400, 261);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        guAboutDialog->setWindowIcon(icon);
        guAboutDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        buttonBox = new QDialogButtonBox(guAboutDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 220, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        label = new QLabel(guAboutDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 10, 141, 131));
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icons/Dinosaur.png")));
        label_2 = new QLabel(guAboutDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 60, 241, 111));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        label_2->setWordWrap(true);
        label_3 = new QLabel(guAboutDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 170, 311, 31));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        label_3->setWordWrap(true);
        label_4 = new QLabel(guAboutDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(130, 10, 261, 41));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        label_4->setWordWrap(true);

        retranslateUi(guAboutDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), guAboutDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), guAboutDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(guAboutDialog);
    } // setupUi

    void retranslateUi(QDialog *guAboutDialog)
    {
        guAboutDialog->setWindowTitle(QApplication::translate("guAboutDialog", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QApplication::translate("guAboutDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \320\277\320\276\320\270\321\201\320\272\320\260 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\275\320\275\321\213\321\205 \320\272\320\275\320\270\320\263 \320\275\320\260 \320\273\320\276\320\272\320\260\320\273\321\214\320\275\320\276\320\274 \320\264\320\270\321\201\320\272\320\265, \320\270\320\267\320\262\320\273\320\265\321\207\320\265\320\275\320\270\321\217 ISBN, \320\277\320\276\320\273\321\203\321\207\320\265"
                        "\320\275\320\270\321\217 \320\261\320\270\320\261\320\273\320\270\320\276\320\263\321\200\320\260\321\204\320\270\321\207\320\265\321\201\320\272\320\276\320\271 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\270, \320\267\320\260\320\263\321\200\321\203\320\267\320\272\320\270 \320\275\320\260 \321\201\320\265\321\200\320\262\320\265\321\200 </span><a href=\"http://free-books.dontexist.com\"><span style=\" font-size:8pt; text-decoration: underline; color:#0000ff;\">Library Genesis</span></a><span style=\" font-size:8pt;\"> \320\270 \321\200\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217<br /> \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\270 \320\276 \320\272\320\275\320\270\320\263\320\260\321\205 \320\262 \320\261\320\270\320\261\320\273\320\270\320\276\321\202\320\265\320\272\320\265</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; marg"
                        "in-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("guAboutDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\320\244\320\276\321\200\321\203\320\274 library genesis:         </span><a href=\"http://gen.lib.rus.ec/forum/\"><span style=\" font-size:8pt; text-decoration: underline; color:#0000ff;\">http://gen.lib.rus.ec/forum/</span></a></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("guAboutDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:600;\">Genesis Uploader ver 0.4 (beta)</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class guAboutDialog: public Ui_guAboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUABOUTDIALOG_H
