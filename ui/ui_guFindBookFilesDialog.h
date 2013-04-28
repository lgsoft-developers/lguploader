/********************************************************************************
** Form generated from reading UI file 'guFindBookFilesDialog.ui'
**
** Created: Sun 28. Apr 10:51:02 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUFINDBOOKFILESDIALOG_H
#define UI_GUFINDBOOKFILESDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_guFindBookFilesDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QFrame *frameFilesLocation;
    QVBoxLayout *verticalLayout;
    QLabel *label_24;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEditSearchPath;
    QPushButton *pushButtonSelectFolder;
    QGridLayout *gridLayout;
    QCheckBox *checkBoxFindRecursive;
    QCheckBox *checkBoxExtractIsbnFromFileName;
    QCheckBox *checkBoxExtractIsbnFromFile;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBoxPDF;
    QCheckBox *checkBoxDOC;
    QCheckBox *checkBoxHTM;
    QCheckBox *checkBoxDOCX;
    QCheckBox *checkBoxPSGZ;
    QCheckBox *checkBoxRTF;
    QCheckBox *checkBoxPS;
    QCheckBox *checkBoxHA;
    QCheckBox *checkBoxCBZ;
    QCheckBox *checkBoxRAR;
    QCheckBox *checkBoxZIP;
    QCheckBox *checkBoxHTML;
    QCheckBox *checkBoxXHTML;
    QCheckBox *checkBoxDJVU;
    QCheckBox *checkBoxCHM;
    QCheckBox *checkBoxFB2;
    QCheckBox *checkBoxTXT;
    QCheckBox *checkBoxMHT;
    QCheckBox *checkBoxISO;
    QCheckBox *checkBoxEXE;
    QSpacerItem *verticalSpacer;
    QFrame *frame_11;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonSet;
    QPushButton *pushButtonExit;

    void setupUi(QDialog *guFindBookFilesDialog)
    {
        if (guFindBookFilesDialog->objectName().isEmpty())
            guFindBookFilesDialog->setObjectName(QString::fromUtf8("guFindBookFilesDialog"));
        guFindBookFilesDialog->resize(525, 328);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/find_ebook.png"), QSize(), QIcon::Normal, QIcon::Off);
        guFindBookFilesDialog->setWindowIcon(icon);
        verticalLayout_3 = new QVBoxLayout(guFindBookFilesDialog);
        verticalLayout_3->setContentsMargins(1, 1, 1, 1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frameFilesLocation = new QFrame(guFindBookFilesDialog);
        frameFilesLocation->setObjectName(QString::fromUtf8("frameFilesLocation"));
        frameFilesLocation->setFrameShape(QFrame::NoFrame);
        frameFilesLocation->setFrameShadow(QFrame::Plain);
        verticalLayout = new QVBoxLayout(frameFilesLocation);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(6, -1, 6, 6);
        label_24 = new QLabel(frameFilesLocation);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        verticalLayout->addWidget(label_24);

        frame_2 = new QFrame(frameFilesLocation);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 1, 0, 1);
        lineEditSearchPath = new QLineEdit(frame_2);
        lineEditSearchPath->setObjectName(QString::fromUtf8("lineEditSearchPath"));
        lineEditSearchPath->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEditSearchPath);

        pushButtonSelectFolder = new QPushButton(frame_2);
        pushButtonSelectFolder->setObjectName(QString::fromUtf8("pushButtonSelectFolder"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSelectFolder->setIcon(icon1);

        horizontalLayout_2->addWidget(pushButtonSelectFolder);


        verticalLayout->addWidget(frame_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(0);
        checkBoxFindRecursive = new QCheckBox(frameFilesLocation);
        checkBoxFindRecursive->setObjectName(QString::fromUtf8("checkBoxFindRecursive"));
        checkBoxFindRecursive->setMinimumSize(QSize(0, 24));
        checkBoxFindRecursive->setChecked(true);

        gridLayout->addWidget(checkBoxFindRecursive, 0, 0, 1, 2);

        checkBoxExtractIsbnFromFileName = new QCheckBox(frameFilesLocation);
        checkBoxExtractIsbnFromFileName->setObjectName(QString::fromUtf8("checkBoxExtractIsbnFromFileName"));
        checkBoxExtractIsbnFromFileName->setMinimumSize(QSize(0, 24));
        checkBoxExtractIsbnFromFileName->setChecked(true);

        gridLayout->addWidget(checkBoxExtractIsbnFromFileName, 1, 0, 1, 1);

        checkBoxExtractIsbnFromFile = new QCheckBox(frameFilesLocation);
        checkBoxExtractIsbnFromFile->setObjectName(QString::fromUtf8("checkBoxExtractIsbnFromFile"));
        checkBoxExtractIsbnFromFile->setMinimumSize(QSize(0, 24));
        checkBoxExtractIsbnFromFile->setChecked(false);

        gridLayout->addWidget(checkBoxExtractIsbnFromFile, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        groupBox = new QGroupBox(frameFilesLocation);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        checkBoxPDF = new QCheckBox(groupBox);
        checkBoxPDF->setObjectName(QString::fromUtf8("checkBoxPDF"));

        gridLayout_2->addWidget(checkBoxPDF, 0, 0, 1, 1);

        checkBoxDOC = new QCheckBox(groupBox);
        checkBoxDOC->setObjectName(QString::fromUtf8("checkBoxDOC"));

        gridLayout_2->addWidget(checkBoxDOC, 0, 1, 1, 1);

        checkBoxHTM = new QCheckBox(groupBox);
        checkBoxHTM->setObjectName(QString::fromUtf8("checkBoxHTM"));

        gridLayout_2->addWidget(checkBoxHTM, 0, 2, 1, 1);

        checkBoxDOCX = new QCheckBox(groupBox);
        checkBoxDOCX->setObjectName(QString::fromUtf8("checkBoxDOCX"));

        gridLayout_2->addWidget(checkBoxDOCX, 2, 1, 1, 1);

        checkBoxPSGZ = new QCheckBox(groupBox);
        checkBoxPSGZ->setObjectName(QString::fromUtf8("checkBoxPSGZ"));

        gridLayout_2->addWidget(checkBoxPSGZ, 0, 3, 1, 1);

        checkBoxRTF = new QCheckBox(groupBox);
        checkBoxRTF->setObjectName(QString::fromUtf8("checkBoxRTF"));

        gridLayout_2->addWidget(checkBoxRTF, 1, 1, 1, 1);

        checkBoxPS = new QCheckBox(groupBox);
        checkBoxPS->setObjectName(QString::fromUtf8("checkBoxPS"));

        gridLayout_2->addWidget(checkBoxPS, 0, 4, 1, 1);

        checkBoxHA = new QCheckBox(groupBox);
        checkBoxHA->setObjectName(QString::fromUtf8("checkBoxHA"));

        gridLayout_2->addWidget(checkBoxHA, 1, 4, 1, 1);

        checkBoxCBZ = new QCheckBox(groupBox);
        checkBoxCBZ->setObjectName(QString::fromUtf8("checkBoxCBZ"));

        gridLayout_2->addWidget(checkBoxCBZ, 2, 4, 1, 1);

        checkBoxRAR = new QCheckBox(groupBox);
        checkBoxRAR->setObjectName(QString::fromUtf8("checkBoxRAR"));

        gridLayout_2->addWidget(checkBoxRAR, 1, 3, 1, 1);

        checkBoxZIP = new QCheckBox(groupBox);
        checkBoxZIP->setObjectName(QString::fromUtf8("checkBoxZIP"));

        gridLayout_2->addWidget(checkBoxZIP, 2, 3, 1, 1);

        checkBoxHTML = new QCheckBox(groupBox);
        checkBoxHTML->setObjectName(QString::fromUtf8("checkBoxHTML"));

        gridLayout_2->addWidget(checkBoxHTML, 1, 2, 1, 1);

        checkBoxXHTML = new QCheckBox(groupBox);
        checkBoxXHTML->setObjectName(QString::fromUtf8("checkBoxXHTML"));

        gridLayout_2->addWidget(checkBoxXHTML, 2, 2, 1, 1);

        checkBoxDJVU = new QCheckBox(groupBox);
        checkBoxDJVU->setObjectName(QString::fromUtf8("checkBoxDJVU"));

        gridLayout_2->addWidget(checkBoxDJVU, 1, 0, 1, 1);

        checkBoxCHM = new QCheckBox(groupBox);
        checkBoxCHM->setObjectName(QString::fromUtf8("checkBoxCHM"));

        gridLayout_2->addWidget(checkBoxCHM, 2, 0, 1, 1);

        checkBoxFB2 = new QCheckBox(groupBox);
        checkBoxFB2->setObjectName(QString::fromUtf8("checkBoxFB2"));

        gridLayout_2->addWidget(checkBoxFB2, 3, 0, 1, 1);

        checkBoxTXT = new QCheckBox(groupBox);
        checkBoxTXT->setObjectName(QString::fromUtf8("checkBoxTXT"));

        gridLayout_2->addWidget(checkBoxTXT, 3, 1, 1, 1);

        checkBoxMHT = new QCheckBox(groupBox);
        checkBoxMHT->setObjectName(QString::fromUtf8("checkBoxMHT"));

        gridLayout_2->addWidget(checkBoxMHT, 3, 2, 1, 1);

        checkBoxISO = new QCheckBox(groupBox);
        checkBoxISO->setObjectName(QString::fromUtf8("checkBoxISO"));

        gridLayout_2->addWidget(checkBoxISO, 3, 3, 1, 1);

        checkBoxEXE = new QCheckBox(groupBox);
        checkBoxEXE->setObjectName(QString::fromUtf8("checkBoxEXE"));

        gridLayout_2->addWidget(checkBoxEXE, 3, 4, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);


        verticalLayout->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_3->addWidget(frameFilesLocation);

        frame_11 = new QFrame(guFindBookFilesDialog);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setFrameShape(QFrame::NoFrame);
        frame_11->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(434, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pushButtonSet = new QPushButton(frame_11);
        pushButtonSet->setObjectName(QString::fromUtf8("pushButtonSet"));

        horizontalLayout_4->addWidget(pushButtonSet);

        pushButtonExit = new QPushButton(frame_11);
        pushButtonExit->setObjectName(QString::fromUtf8("pushButtonExit"));

        horizontalLayout_4->addWidget(pushButtonExit);


        verticalLayout_3->addWidget(frame_11);


        retranslateUi(guFindBookFilesDialog);

        QMetaObject::connectSlotsByName(guFindBookFilesDialog);
    } // setupUi

    void retranslateUi(QDialog *guFindBookFilesDialog)
    {
        guFindBookFilesDialog->setWindowTitle(QApplication::translate("guFindBookFilesDialog", "\320\236\320\277\321\206\320\270\320\270 \320\277\320\276\320\270\320\272\320\260 \320\272\320\275\320\270\320\263", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("guFindBookFilesDialog", "\320\224\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\321\217, \320\262 \320\272\320\276\321\202\320\276\321\200\320\276\320\271 \320\261\321\203\320\264\320\265\321\202 \320\277\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\270\321\202\321\214\321\201\321\217 \320\277\320\276\320\270\321\201\320\272 \320\272\320\275\320\270\320\263:", 0, QApplication::UnicodeUTF8));
        pushButtonSelectFolder->setText(QString());
        checkBoxFindRecursive->setText(QApplication::translate("guFindBookFilesDialog", "\320\230\321\201\320\272\320\260\321\202\321\214 \320\262 \320\277\320\276\320\264\320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\321\217\321\205", 0, QApplication::UnicodeUTF8));
        checkBoxExtractIsbnFromFileName->setText(QApplication::translate("guFindBookFilesDialog", "\320\230\320\267\320\262\320\273\320\265\320\272\320\260\321\202\321\214 ISBN \320\270\320\267 \320\270\320\274\320\265\320\275 \321\204\320\260\320\271\320\273\320\276\320\262", 0, QApplication::UnicodeUTF8));
        checkBoxExtractIsbnFromFile->setText(QApplication::translate("guFindBookFilesDialog", "\320\230\320\267\320\262\320\273\320\265\320\272\320\260\321\202\321\214 ISBN \320\270\320\267 \321\204\320\260\320\271\320\273\320\276\320\262", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("guFindBookFilesDialog", "\320\230\321\201\320\272\320\260\321\202\321\214 \321\204\320\260\320\271\320\273\321\213 \321\201 \321\200\320\260\321\201\321\210\320\270\321\200\320\265\320\275\320\270\321\217\320\274\320\270:", 0, QApplication::UnicodeUTF8));
        checkBoxPDF->setText(QApplication::translate("guFindBookFilesDialog", "pdf", 0, QApplication::UnicodeUTF8));
        checkBoxDOC->setText(QApplication::translate("guFindBookFilesDialog", "doc", 0, QApplication::UnicodeUTF8));
        checkBoxHTM->setText(QApplication::translate("guFindBookFilesDialog", "htm", 0, QApplication::UnicodeUTF8));
        checkBoxDOCX->setText(QApplication::translate("guFindBookFilesDialog", "docx", 0, QApplication::UnicodeUTF8));
        checkBoxPSGZ->setText(QApplication::translate("guFindBookFilesDialog", "ps.gz", 0, QApplication::UnicodeUTF8));
        checkBoxRTF->setText(QApplication::translate("guFindBookFilesDialog", "rtf", 0, QApplication::UnicodeUTF8));
        checkBoxPS->setText(QApplication::translate("guFindBookFilesDialog", "ps", 0, QApplication::UnicodeUTF8));
        checkBoxHA->setText(QApplication::translate("guFindBookFilesDialog", "ha", 0, QApplication::UnicodeUTF8));
        checkBoxCBZ->setText(QApplication::translate("guFindBookFilesDialog", "cbz", 0, QApplication::UnicodeUTF8));
        checkBoxRAR->setText(QApplication::translate("guFindBookFilesDialog", "rar", 0, QApplication::UnicodeUTF8));
        checkBoxZIP->setText(QApplication::translate("guFindBookFilesDialog", "zip", 0, QApplication::UnicodeUTF8));
        checkBoxHTML->setText(QApplication::translate("guFindBookFilesDialog", "html", 0, QApplication::UnicodeUTF8));
        checkBoxXHTML->setText(QApplication::translate("guFindBookFilesDialog", "xhtml", 0, QApplication::UnicodeUTF8));
        checkBoxDJVU->setText(QApplication::translate("guFindBookFilesDialog", "djvu", 0, QApplication::UnicodeUTF8));
        checkBoxCHM->setText(QApplication::translate("guFindBookFilesDialog", "chm", 0, QApplication::UnicodeUTF8));
        checkBoxFB2->setText(QApplication::translate("guFindBookFilesDialog", "fb2", 0, QApplication::UnicodeUTF8));
        checkBoxTXT->setText(QApplication::translate("guFindBookFilesDialog", "txt", 0, QApplication::UnicodeUTF8));
        checkBoxMHT->setText(QApplication::translate("guFindBookFilesDialog", "mht", 0, QApplication::UnicodeUTF8));
        checkBoxISO->setText(QApplication::translate("guFindBookFilesDialog", "iso", 0, QApplication::UnicodeUTF8));
        checkBoxEXE->setText(QApplication::translate("guFindBookFilesDialog", "exe", 0, QApplication::UnicodeUTF8));
        pushButtonSet->setText(QApplication::translate("guFindBookFilesDialog", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\277\320\276\320\270\321\201\320\272", 0, QApplication::UnicodeUTF8));
        pushButtonExit->setText(QApplication::translate("guFindBookFilesDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class guFindBookFilesDialog: public Ui_guFindBookFilesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUFINDBOOKFILESDIALOG_H
