/********************************************************************************
** Form generated from reading UI file 'guMainWindow.ui'
**
** Created: Sun 28. Apr 10:51:02 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUMAINWINDOW_H
#define UI_GUMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDockWidget>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guMainWindow
{
public:
    QAction *actionInspectFolder;
    QAction *actionUploadToServer;
    QAction *actionGetBiblioInfo;
    QAction *actionShowSettingsDialog;
    QAction *actionSelectAllForUpload;
    QAction *actionToogleShowDublicates;
    QAction *actionToogleShowWithISBN;
    QAction *actionToogleShowWithBibliography;
    QAction *actionToogleShowUploaded;
    QAction *actionAbortInspectProcess;
    QAction *actionHelp;
    QAction *actionAbout;
    QAction *actionFileListLeft;
    QAction *actionFileListRight;
    QAction *action_8;
    QAction *action_9;
    QAction *actionExportToCSV;
    QAction *action;
    QAction *action_2;
    QAction *actionISBN;
    QAction *action_3;
    QAction *action_4;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_13;
    QVBoxLayout *verticalLayout_9;
    QTreeWidget *treeWidgetFiles;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_17;
    QLabel *labelNumOfInspected;
    QLabel *label_18;
    QLabel *labelNumOfDublicates;
    QLabel *label_20;
    QLabel *labelNumOfWithIsbn;
    QLabel *label_22;
    QLabel *labelNumOfWithBiblio;
    QLabel *label_24;
    QLabel *labelNumOfUploaded;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelProcessStatus;
    QProgressBar *progressBarProcess;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_4;
    QMenu *menu_5;
    QMenu *menu_7;
    QMenu *menu_6;
    QMenu *menu_3;
    QMenu *menu_8;
    QToolBar *mainToolBar;
    QDockWidget *dockWidgetDescription;
    QWidget *dockWidgetContents_3;
    QVBoxLayout *verticalLayout_14;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_12;
    QFrame *frame_10;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_25;
    QLabel *labelCurrentMD5;
    QToolButton *toolButtonCopyMD5toClipboard;
    QToolButton *toolButtonBookOpen;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *toolButtonGetBiblioForItem;
    QToolButton *toolButtonSaveChanges;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_8;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_10;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEditIsbn;
    QListWidget *listWidgetISBNs;
    QSpacerItem *verticalSpacer_4;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_2;
    QToolButton *toolButtonAddIsbn;
    QToolButton *toolButtonRemoveIsbn;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout;
    QLabel *labelTitle;
    QLineEdit *lineEditTitle;
    QLabel *labelAuthors;
    QLineEdit *lineEditAuthors;
    QLabel *label_5;
    QLineEdit *lineEditIssue;
    QLabel *label_6;
    QLineEdit *lineEditSeries;
    QLabel *labelPublisher;
    QLineEdit *lineEditPublisher;
    QLabel *labelLanguage;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *lineEditUDC;
    QLineEdit *lineEditBBC;
    QLineEdit *lineEditLanguage;
    QLineEdit *lineEditSity;
    QLabel *label_7;
    QLabel *labelPubYear;
    QLineEdit *lineEditPubYear;
    QLabel *labelPageNum;
    QComboBox *comboBoxOrientation;
    QLabel *label_13;
    QLineEdit *lineEditVolume;
    QLabel *label_29;
    QLineEdit *lineEditPageNum;
    QToolButton *toolButtonSetForAllPublisher;
    QToolButton *toolButtonSetForAllUdc;
    QToolButton *toolButtonSetForAllSity;
    QToolButton *toolButtonSetForAllSeries;
    QToolButton *toolButtonSetForAllAuthors;
    QToolButton *toolButtonSetForAllTitle;
    QToolButton *toolButtonSetForAllOrientation;
    QToolButton *toolButtonSetForAllLanguage;
    QToolButton *toolButtonSetForAllBbc;
    QToolButton *toolButtonSetForAllPubYear;
    QLabel *label_8;
    QLineEdit *lineEditPeriodical;
    QToolButton *toolButtonSetForAllPeriodical;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_3;
    QLabel *label_11;
    QLineEdit *lineEditBiblio;
    QLabel *label_12;
    QLineEdit *lineEditDVDNum;
    QToolButton *toolButtonSetForAllLibrary;
    QToolButton *toolButtonSetForAllLibraryIssue;
    QSpacerItem *verticalSpacer_5;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_2;
    QLabel *label_14;
    QLineEdit *lineEditDpi;
    QCheckBox *checkBoxColorScan;
    QCheckBox *checkBoxClearScan;
    QToolButton *toolButtonSetForAllColorScan;
    QToolButton *toolButtonSetForAllScanDpi;
    QToolButton *toolButtonSetForAllCleanScan;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelTitle_2;
    QLabel *labelTitle_3;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_27;
    QFrame *frame_9;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEditCategory;
    QToolButton *toolButtonSetCategoryForAllBooks;
    QLabel *label_19;
    QListWidget *listWidgetSubjects;
    QLabel *label_26;
    QTreeWidget *treeWidgetCategories;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_7;
    QLabel *label;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEditCommentary;
    QToolButton *toolButtonSetCommentForAllBooks;
    QLabel *label_3;
    QTextEdit *textEditDescription;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_2;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_28;

    void setupUi(QMainWindow *guMainWindow)
    {
        if (guMainWindow->objectName().isEmpty())
            guMainWindow->setObjectName(QString::fromUtf8("guMainWindow"));
        guMainWindow->resize(1138, 1762);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(guMainWindow->sizePolicy().hasHeightForWidth());
        guMainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Dinosaur.png"), QSize(), QIcon::Normal, QIcon::Off);
        guMainWindow->setWindowIcon(icon);
        actionInspectFolder = new QAction(guMainWindow);
        actionInspectFolder->setObjectName(QString::fromUtf8("actionInspectFolder"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/find_ebook.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInspectFolder->setIcon(icon1);
        actionInspectFolder->setAutoRepeat(true);
        actionInspectFolder->setVisible(true);
        actionInspectFolder->setMenuRole(QAction::TextHeuristicRole);
        actionInspectFolder->setIconVisibleInMenu(true);
        actionUploadToServer = new QAction(guMainWindow);
        actionUploadToServer->setObjectName(QString::fromUtf8("actionUploadToServer"));
        actionUploadToServer->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/commit_128.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUploadToServer->setIcon(icon2);
        actionGetBiblioInfo = new QAction(guMainWindow);
        actionGetBiblioInfo->setObjectName(QString::fromUtf8("actionGetBiblioInfo"));
        actionGetBiblioInfo->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/linguist-phrasebookopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGetBiblioInfo->setIcon(icon3);
        actionShowSettingsDialog = new QAction(guMainWindow);
        actionShowSettingsDialog->setObjectName(QString::fromUtf8("actionShowSettingsDialog"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/configure.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowSettingsDialog->setIcon(icon4);
        actionSelectAllForUpload = new QAction(guMainWindow);
        actionSelectAllForUpload->setObjectName(QString::fromUtf8("actionSelectAllForUpload"));
        actionSelectAllForUpload->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/books_preferences.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectAllForUpload->setIcon(icon5);
        actionToogleShowDublicates = new QAction(guMainWindow);
        actionToogleShowDublicates->setObjectName(QString::fromUtf8("actionToogleShowDublicates"));
        actionToogleShowDublicates->setCheckable(true);
        actionToogleShowDublicates->setChecked(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/dublicate.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionToogleShowDublicates->setIcon(icon6);
        actionToogleShowWithISBN = new QAction(guMainWindow);
        actionToogleShowWithISBN->setObjectName(QString::fromUtf8("actionToogleShowWithISBN"));
        actionToogleShowWithISBN->setCheckable(true);
        actionToogleShowWithISBN->setChecked(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/with_isbn.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionToogleShowWithISBN->setIcon(icon7);
        actionToogleShowWithBibliography = new QAction(guMainWindow);
        actionToogleShowWithBibliography->setObjectName(QString::fromUtf8("actionToogleShowWithBibliography"));
        actionToogleShowWithBibliography->setCheckable(true);
        actionToogleShowWithBibliography->setChecked(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/with_with_biblio.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionToogleShowWithBibliography->setIcon(icon8);
        actionToogleShowUploaded = new QAction(guMainWindow);
        actionToogleShowUploaded->setObjectName(QString::fromUtf8("actionToogleShowUploaded"));
        actionToogleShowUploaded->setCheckable(true);
        actionToogleShowUploaded->setChecked(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/uploaded.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionToogleShowUploaded->setIcon(icon9);
        actionAbortInspectProcess = new QAction(guMainWindow);
        actionAbortInspectProcess->setObjectName(QString::fromUtf8("actionAbortInspectProcess"));
        actionAbortInspectProcess->setEnabled(false);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/abort_find.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbortInspectProcess->setIcon(icon10);
        actionHelp = new QAction(guMainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon11);
        actionAbout = new QAction(guMainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icons/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon12);
        actionFileListLeft = new QAction(guMainWindow);
        actionFileListLeft->setObjectName(QString::fromUtf8("actionFileListLeft"));
        actionFileListRight = new QAction(guMainWindow);
        actionFileListRight->setObjectName(QString::fromUtf8("actionFileListRight"));
        action_8 = new QAction(guMainWindow);
        action_8->setObjectName(QString::fromUtf8("action_8"));
        action_9 = new QAction(guMainWindow);
        action_9->setObjectName(QString::fromUtf8("action_9"));
        actionExportToCSV = new QAction(guMainWindow);
        actionExportToCSV->setObjectName(QString::fromUtf8("actionExportToCSV"));
        action = new QAction(guMainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(guMainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        actionISBN = new QAction(guMainWindow);
        actionISBN->setObjectName(QString::fromUtf8("actionISBN"));
        action_3 = new QAction(guMainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        action_3->setCheckable(true);
        action_3->setChecked(true);
        action_4 = new QAction(guMainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        centralWidget = new QWidget(guMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_13 = new QVBoxLayout(centralWidget);
        verticalLayout_13->setSpacing(1);
        verticalLayout_13->setContentsMargins(1, 1, 1, 1);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        treeWidgetFiles = new QTreeWidget(centralWidget);
        treeWidgetFiles->setObjectName(QString::fromUtf8("treeWidgetFiles"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(treeWidgetFiles->sizePolicy().hasHeightForWidth());
        treeWidgetFiles->setSizePolicy(sizePolicy1);

        verticalLayout_9->addWidget(treeWidgetFiles);


        verticalLayout_13->addLayout(verticalLayout_9);

        frame_7 = new QFrame(centralWidget);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_7->sizePolicy().hasHeightForWidth());
        frame_7->setSizePolicy(sizePolicy2);
        frame_7->setFrameShape(QFrame::NoFrame);
        frame_7->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_7);
        horizontalLayout_4->setSpacing(3);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(1, 1, 3, 3);
        label_17 = new QLabel(frame_7);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_4->addWidget(label_17);

        labelNumOfInspected = new QLabel(frame_7);
        labelNumOfInspected->setObjectName(QString::fromUtf8("labelNumOfInspected"));

        horizontalLayout_4->addWidget(labelNumOfInspected);

        label_18 = new QLabel(frame_7);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_4->addWidget(label_18);

        labelNumOfDublicates = new QLabel(frame_7);
        labelNumOfDublicates->setObjectName(QString::fromUtf8("labelNumOfDublicates"));

        horizontalLayout_4->addWidget(labelNumOfDublicates);

        label_20 = new QLabel(frame_7);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_4->addWidget(label_20);

        labelNumOfWithIsbn = new QLabel(frame_7);
        labelNumOfWithIsbn->setObjectName(QString::fromUtf8("labelNumOfWithIsbn"));

        horizontalLayout_4->addWidget(labelNumOfWithIsbn);

        label_22 = new QLabel(frame_7);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_4->addWidget(label_22);

        labelNumOfWithBiblio = new QLabel(frame_7);
        labelNumOfWithBiblio->setObjectName(QString::fromUtf8("labelNumOfWithBiblio"));

        horizontalLayout_4->addWidget(labelNumOfWithBiblio);

        label_24 = new QLabel(frame_7);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_4->addWidget(label_24);

        labelNumOfUploaded = new QLabel(frame_7);
        labelNumOfUploaded->setObjectName(QString::fromUtf8("labelNumOfUploaded"));

        horizontalLayout_4->addWidget(labelNumOfUploaded);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        labelProcessStatus = new QLabel(frame_7);
        labelProcessStatus->setObjectName(QString::fromUtf8("labelProcessStatus"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelProcessStatus->sizePolicy().hasHeightForWidth());
        labelProcessStatus->setSizePolicy(sizePolicy3);
        labelProcessStatus->setMinimumSize(QSize(0, 15));
        labelProcessStatus->setMaximumSize(QSize(16777215, 16777215));
        labelProcessStatus->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(labelProcessStatus);

        progressBarProcess = new QProgressBar(frame_7);
        progressBarProcess->setObjectName(QString::fromUtf8("progressBarProcess"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(50);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(progressBarProcess->sizePolicy().hasHeightForWidth());
        progressBarProcess->setSizePolicy(sizePolicy4);
        progressBarProcess->setMinimumSize(QSize(0, 0));
        progressBarProcess->setMaximumSize(QSize(300, 16777215));
        progressBarProcess->setValue(0);
        progressBarProcess->setTextVisible(false);

        horizontalLayout_4->addWidget(progressBarProcess);


        verticalLayout_13->addWidget(frame_7);

        guMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(guMainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1138, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_4 = new QMenu(menu_2);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        menu_5 = new QMenu(menu_2);
        menu_5->setObjectName(QString::fromUtf8("menu_5"));
        menu_7 = new QMenu(menu_2);
        menu_7->setObjectName(QString::fromUtf8("menu_7"));
        menu_6 = new QMenu(menu_2);
        menu_6->setObjectName(QString::fromUtf8("menu_6"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_8 = new QMenu(menuBar);
        menu_8->setObjectName(QString::fromUtf8("menu_8"));
        guMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(guMainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setIconSize(QSize(34, 34));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        guMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        dockWidgetDescription = new QDockWidget(guMainWindow);
        dockWidgetDescription->setObjectName(QString::fromUtf8("dockWidgetDescription"));
        dockWidgetDescription->setFloating(false);
        dockWidgetDescription->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        verticalLayout_14 = new QVBoxLayout(dockWidgetContents_3);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(1, 1, 1, 1);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        stackedWidget = new QStackedWidget(dockWidgetContents_3);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy5);
        stackedWidget->setMaximumSize(QSize(410, 16777215));
        stackedWidget->setLineWidth(1);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_12 = new QVBoxLayout(page);
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 1, 0, 0);
        frame_10 = new QFrame(page);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setFrameShape(QFrame::NoFrame);
        frame_10->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_10);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(1, 3, 2, 3);
        label_25 = new QLabel(frame_10);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_25);

        labelCurrentMD5 = new QLabel(frame_10);
        labelCurrentMD5->setObjectName(QString::fromUtf8("labelCurrentMD5"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(labelCurrentMD5->sizePolicy().hasHeightForWidth());
        labelCurrentMD5->setSizePolicy(sizePolicy6);
        labelCurrentMD5->setMinimumSize(QSize(205, 0));

        horizontalLayout_7->addWidget(labelCurrentMD5);

        toolButtonCopyMD5toClipboard = new QToolButton(frame_10);
        toolButtonCopyMD5toClipboard->setObjectName(QString::fromUtf8("toolButtonCopyMD5toClipboard"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icons/clipboard.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonCopyMD5toClipboard->setIcon(icon13);
        toolButtonCopyMD5toClipboard->setIconSize(QSize(22, 22));

        horizontalLayout_7->addWidget(toolButtonCopyMD5toClipboard);

        toolButtonBookOpen = new QToolButton(frame_10);
        toolButtonBookOpen->setObjectName(QString::fromUtf8("toolButtonBookOpen"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icons/book_open.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonBookOpen->setIcon(icon14);
        toolButtonBookOpen->setIconSize(QSize(22, 22));

        horizontalLayout_7->addWidget(toolButtonBookOpen);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        toolButtonGetBiblioForItem = new QToolButton(frame_10);
        toolButtonGetBiblioForItem->setObjectName(QString::fromUtf8("toolButtonGetBiblioForItem"));
        toolButtonGetBiblioForItem->setIcon(icon3);
        toolButtonGetBiblioForItem->setIconSize(QSize(22, 22));

        horizontalLayout_7->addWidget(toolButtonGetBiblioForItem);

        toolButtonSaveChanges = new QToolButton(frame_10);
        toolButtonSaveChanges->setObjectName(QString::fromUtf8("toolButtonSaveChanges"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/icons/dialog-ok-apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonSaveChanges->setIcon(icon15);
        toolButtonSaveChanges->setIconSize(QSize(22, 22));

        horizontalLayout_7->addWidget(toolButtonSaveChanges);


        verticalLayout_12->addWidget(frame_10);

        tabWidget = new QTabWidget(page);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy7);
        tabWidget->setMaximumSize(QSize(410, 16777215));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setInputMethodHints(Qt::ImhNoAutoUppercase);
        verticalLayout_8 = new QVBoxLayout(tab);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(4, 4, 4, 4);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        frame_3 = new QFrame(tab);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        sizePolicy5.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy5);
        frame_3->setMaximumSize(QSize(16777215, 16777215));
        frame_3->setFrameShape(QFrame::NoFrame);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_3);
        horizontalLayout->setSpacing(1);
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame_5 = new QFrame(frame_3);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFrameShape(QFrame::NoFrame);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_5);
        verticalLayout_3->setSpacing(1);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(1, 4, 1, 1);
        label_10 = new QLabel(frame_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_10);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout->addWidget(frame_5);

        frame_2 = new QFrame(frame_3);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setSpacing(3);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(4, 1, 4, 1);
        lineEditIsbn = new QLineEdit(frame_2);
        lineEditIsbn->setObjectName(QString::fromUtf8("lineEditIsbn"));
        lineEditIsbn->setMinimumSize(QSize(144, 0));
        lineEditIsbn->setMaximumSize(QSize(144, 16777215));

        verticalLayout->addWidget(lineEditIsbn);

        listWidgetISBNs = new QListWidget(frame_2);
        listWidgetISBNs->setObjectName(QString::fromUtf8("listWidgetISBNs"));
        listWidgetISBNs->setMinimumSize(QSize(144, 0));
        listWidgetISBNs->setMaximumSize(QSize(144, 100));

        verticalLayout->addWidget(listWidgetISBNs);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);


        horizontalLayout->addWidget(frame_2);

        frame_4 = new QFrame(frame_3);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::NoFrame);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_4);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 0, -1, -1);
        toolButtonAddIsbn = new QToolButton(frame_4);
        toolButtonAddIsbn->setObjectName(QString::fromUtf8("toolButtonAddIsbn"));
        toolButtonAddIsbn->setMinimumSize(QSize(24, 24));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/icons/add_22.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonAddIsbn->setIcon(icon16);
        toolButtonAddIsbn->setIconSize(QSize(16, 16));

        verticalLayout_2->addWidget(toolButtonAddIsbn);

        toolButtonRemoveIsbn = new QToolButton(frame_4);
        toolButtonRemoveIsbn->setObjectName(QString::fromUtf8("toolButtonRemoveIsbn"));
        toolButtonRemoveIsbn->setMinimumSize(QSize(24, 24));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/icons/list_remove_22.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonRemoveIsbn->setIcon(icon17);
        toolButtonRemoveIsbn->setIconSize(QSize(16, 16));

        verticalLayout_2->addWidget(toolButtonRemoveIsbn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addWidget(frame_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        verticalLayout_8->addWidget(frame_3);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, -1, 0, -1);
        labelTitle = new QLabel(tab);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        labelTitle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelTitle, 0, 0, 1, 1);

        lineEditTitle = new QLineEdit(tab);
        lineEditTitle->setObjectName(QString::fromUtf8("lineEditTitle"));

        gridLayout->addWidget(lineEditTitle, 0, 1, 1, 5);

        labelAuthors = new QLabel(tab);
        labelAuthors->setObjectName(QString::fromUtf8("labelAuthors"));
        labelAuthors->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        labelAuthors->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelAuthors, 1, 0, 1, 1);

        lineEditAuthors = new QLineEdit(tab);
        lineEditAuthors->setObjectName(QString::fromUtf8("lineEditAuthors"));

        gridLayout->addWidget(lineEditAuthors, 1, 1, 1, 5);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 7, 0, 1, 1);

        lineEditIssue = new QLineEdit(tab);
        lineEditIssue->setObjectName(QString::fromUtf8("lineEditIssue"));

        gridLayout->addWidget(lineEditIssue, 7, 1, 1, 2);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        lineEditSeries = new QLineEdit(tab);
        lineEditSeries->setObjectName(QString::fromUtf8("lineEditSeries"));

        gridLayout->addWidget(lineEditSeries, 2, 1, 1, 5);

        labelPublisher = new QLabel(tab);
        labelPublisher->setObjectName(QString::fromUtf8("labelPublisher"));
        labelPublisher->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        labelPublisher->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelPublisher, 4, 0, 1, 1);

        lineEditPublisher = new QLineEdit(tab);
        lineEditPublisher->setObjectName(QString::fromUtf8("lineEditPublisher"));

        gridLayout->addWidget(lineEditPublisher, 4, 1, 1, 2);

        labelLanguage = new QLabel(tab);
        labelLanguage->setObjectName(QString::fromUtf8("labelLanguage"));
        labelLanguage->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        labelLanguage->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelLanguage, 8, 0, 1, 1);

        label_15 = new QLabel(tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_15, 5, 0, 1, 1);

        label_16 = new QLabel(tab);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_16, 6, 0, 1, 1);

        lineEditUDC = new QLineEdit(tab);
        lineEditUDC->setObjectName(QString::fromUtf8("lineEditUDC"));

        gridLayout->addWidget(lineEditUDC, 5, 1, 1, 2);

        lineEditBBC = new QLineEdit(tab);
        lineEditBBC->setObjectName(QString::fromUtf8("lineEditBBC"));

        gridLayout->addWidget(lineEditBBC, 6, 1, 1, 2);

        lineEditLanguage = new QLineEdit(tab);
        lineEditLanguage->setObjectName(QString::fromUtf8("lineEditLanguage"));

        gridLayout->addWidget(lineEditLanguage, 8, 1, 1, 2);

        lineEditSity = new QLineEdit(tab);
        lineEditSity->setObjectName(QString::fromUtf8("lineEditSity"));
        lineEditSity->setMinimumSize(QSize(90, 0));

        gridLayout->addWidget(lineEditSity, 4, 5, 1, 1);

        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 4, 4, 1, 1);

        labelPubYear = new QLabel(tab);
        labelPubYear->setObjectName(QString::fromUtf8("labelPubYear"));
        labelPubYear->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        labelPubYear->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelPubYear, 5, 4, 1, 1);

        lineEditPubYear = new QLineEdit(tab);
        lineEditPubYear->setObjectName(QString::fromUtf8("lineEditPubYear"));
        lineEditPubYear->setMaximumSize(QSize(35, 16777215));
        lineEditPubYear->setMaxLength(4);
        lineEditPubYear->setCursorPosition(4);

        gridLayout->addWidget(lineEditPubYear, 5, 5, 1, 1);

        labelPageNum = new QLabel(tab);
        labelPageNum->setObjectName(QString::fromUtf8("labelPageNum"));
        labelPageNum->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        labelPageNum->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelPageNum, 6, 4, 1, 1);

        comboBoxOrientation = new QComboBox(tab);
        comboBoxOrientation->setObjectName(QString::fromUtf8("comboBoxOrientation"));

        gridLayout->addWidget(comboBoxOrientation, 8, 5, 1, 1);

        label_13 = new QLabel(tab);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_13, 8, 4, 1, 1);

        lineEditVolume = new QLineEdit(tab);
        lineEditVolume->setObjectName(QString::fromUtf8("lineEditVolume"));

        gridLayout->addWidget(lineEditVolume, 7, 5, 1, 1);

        label_29 = new QLabel(tab);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_29, 7, 4, 1, 1);

        lineEditPageNum = new QLineEdit(tab);
        lineEditPageNum->setObjectName(QString::fromUtf8("lineEditPageNum"));
        lineEditPageNum->setMaximumSize(QSize(35, 16777215));

        gridLayout->addWidget(lineEditPageNum, 6, 5, 1, 1);

        toolButtonSetForAllPublisher = new QToolButton(tab);
        toolButtonSetForAllPublisher->setObjectName(QString::fromUtf8("toolButtonSetForAllPublisher"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/icons/document-save-all.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonSetForAllPublisher->setIcon(icon18);
        toolButtonSetForAllPublisher->setIconSize(QSize(20, 20));
        toolButtonSetForAllPublisher->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout->addWidget(toolButtonSetForAllPublisher, 4, 3, 1, 1);

        toolButtonSetForAllUdc = new QToolButton(tab);
        toolButtonSetForAllUdc->setObjectName(QString::fromUtf8("toolButtonSetForAllUdc"));
        toolButtonSetForAllUdc->setIcon(icon18);
        toolButtonSetForAllUdc->setIconSize(QSize(20, 20));
        toolButtonSetForAllUdc->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout->addWidget(toolButtonSetForAllUdc, 5, 3, 1, 1);

        toolButtonSetForAllSity = new QToolButton(tab);
        toolButtonSetForAllSity->setObjectName(QString::fromUtf8("toolButtonSetForAllSity"));
        toolButtonSetForAllSity->setIcon(icon18);
        toolButtonSetForAllSity->setIconSize(QSize(20, 20));
        toolButtonSetForAllSity->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout->addWidget(toolButtonSetForAllSity, 4, 6, 1, 1);

        toolButtonSetForAllSeries = new QToolButton(tab);
        toolButtonSetForAllSeries->setObjectName(QString::fromUtf8("toolButtonSetForAllSeries"));
        toolButtonSetForAllSeries->setIcon(icon18);
        toolButtonSetForAllSeries->setIconSize(QSize(20, 20));
        toolButtonSetForAllSeries->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout->addWidget(toolButtonSetForAllSeries, 2, 6, 1, 1);

        toolButtonSetForAllAuthors = new QToolButton(tab);
        toolButtonSetForAllAuthors->setObjectName(QString::fromUtf8("toolButtonSetForAllAuthors"));
        toolButtonSetForAllAuthors->setIcon(icon18);
        toolButtonSetForAllAuthors->setIconSize(QSize(20, 20));
        toolButtonSetForAllAuthors->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout->addWidget(toolButtonSetForAllAuthors, 1, 6, 1, 1);

        toolButtonSetForAllTitle = new QToolButton(tab);
        toolButtonSetForAllTitle->setObjectName(QString::fromUtf8("toolButtonSetForAllTitle"));
        toolButtonSetForAllTitle->setIcon(icon18);
        toolButtonSetForAllTitle->setIconSize(QSize(20, 20));
        toolButtonSetForAllTitle->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout->addWidget(toolButtonSetForAllTitle, 0, 6, 1, 1);

        toolButtonSetForAllOrientation = new QToolButton(tab);
        toolButtonSetForAllOrientation->setObjectName(QString::fromUtf8("toolButtonSetForAllOrientation"));
        toolButtonSetForAllOrientation->setIcon(icon18);
        toolButtonSetForAllOrientation->setIconSize(QSize(20, 20));
        toolButtonSetForAllOrientation->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout->addWidget(toolButtonSetForAllOrientation, 8, 6, 1, 1);

        toolButtonSetForAllLanguage = new QToolButton(tab);
        toolButtonSetForAllLanguage->setObjectName(QString::fromUtf8("toolButtonSetForAllLanguage"));
        toolButtonSetForAllLanguage->setIcon(icon18);
        toolButtonSetForAllLanguage->setIconSize(QSize(20, 20));
        toolButtonSetForAllLanguage->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout->addWidget(toolButtonSetForAllLanguage, 8, 3, 1, 1);

        toolButtonSetForAllBbc = new QToolButton(tab);
        toolButtonSetForAllBbc->setObjectName(QString::fromUtf8("toolButtonSetForAllBbc"));
        toolButtonSetForAllBbc->setIcon(icon18);
        toolButtonSetForAllBbc->setIconSize(QSize(20, 20));
        toolButtonSetForAllBbc->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout->addWidget(toolButtonSetForAllBbc, 6, 3, 1, 1);

        toolButtonSetForAllPubYear = new QToolButton(tab);
        toolButtonSetForAllPubYear->setObjectName(QString::fromUtf8("toolButtonSetForAllPubYear"));
        toolButtonSetForAllPubYear->setIcon(icon18);
        toolButtonSetForAllPubYear->setIconSize(QSize(20, 20));
        toolButtonSetForAllPubYear->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout->addWidget(toolButtonSetForAllPubYear, 5, 6, 1, 1);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        lineEditPeriodical = new QLineEdit(tab);
        lineEditPeriodical->setObjectName(QString::fromUtf8("lineEditPeriodical"));

        gridLayout->addWidget(lineEditPeriodical, 3, 1, 1, 5);

        toolButtonSetForAllPeriodical = new QToolButton(tab);
        toolButtonSetForAllPeriodical->setObjectName(QString::fromUtf8("toolButtonSetForAllPeriodical"));
        toolButtonSetForAllPeriodical->setIcon(icon18);
        toolButtonSetForAllPeriodical->setIconSize(QSize(20, 20));
        toolButtonSetForAllPeriodical->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout->addWidget(toolButtonSetForAllPeriodical, 3, 6, 1, 1);


        verticalLayout_8->addLayout(gridLayout);

        frame = new QFrame(tab);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        groupBox_2 = new QGroupBox(frame);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(-1, 4, -1, 4);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(1);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_11, 0, 0, 1, 1);

        lineEditBiblio = new QLineEdit(groupBox_2);
        lineEditBiblio->setObjectName(QString::fromUtf8("lineEditBiblio"));
        lineEditBiblio->setMaxLength(32767);

        gridLayout_3->addWidget(lineEditBiblio, 0, 1, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_12, 1, 0, 1, 1);

        lineEditDVDNum = new QLineEdit(groupBox_2);
        lineEditDVDNum->setObjectName(QString::fromUtf8("lineEditDVDNum"));

        gridLayout_3->addWidget(lineEditDVDNum, 1, 1, 1, 1);

        toolButtonSetForAllLibrary = new QToolButton(groupBox_2);
        toolButtonSetForAllLibrary->setObjectName(QString::fromUtf8("toolButtonSetForAllLibrary"));
        toolButtonSetForAllLibrary->setIcon(icon18);
        toolButtonSetForAllLibrary->setIconSize(QSize(20, 20));
        toolButtonSetForAllLibrary->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout_3->addWidget(toolButtonSetForAllLibrary, 0, 2, 1, 1);

        toolButtonSetForAllLibraryIssue = new QToolButton(groupBox_2);
        toolButtonSetForAllLibraryIssue->setObjectName(QString::fromUtf8("toolButtonSetForAllLibraryIssue"));
        toolButtonSetForAllLibraryIssue->setIcon(icon18);
        toolButtonSetForAllLibraryIssue->setIconSize(QSize(20, 20));
        toolButtonSetForAllLibraryIssue->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout_3->addWidget(toolButtonSetForAllLibraryIssue, 1, 2, 1, 1);


        verticalLayout_5->addLayout(gridLayout_3);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_5);


        horizontalLayout_2->addWidget(groupBox_2);

        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, 4, -1, 4);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_14, 0, 0, 1, 1);

        lineEditDpi = new QLineEdit(groupBox);
        lineEditDpi->setObjectName(QString::fromUtf8("lineEditDpi"));
        lineEditDpi->setMaxLength(7);

        gridLayout_2->addWidget(lineEditDpi, 0, 1, 1, 1);

        checkBoxColorScan = new QCheckBox(groupBox);
        checkBoxColorScan->setObjectName(QString::fromUtf8("checkBoxColorScan"));
        sizePolicy3.setHeightForWidth(checkBoxColorScan->sizePolicy().hasHeightForWidth());
        checkBoxColorScan->setSizePolicy(sizePolicy3);
        checkBoxColorScan->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(checkBoxColorScan, 1, 0, 1, 1);

        checkBoxClearScan = new QCheckBox(groupBox);
        checkBoxClearScan->setObjectName(QString::fromUtf8("checkBoxClearScan"));
        checkBoxClearScan->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(checkBoxClearScan, 2, 0, 1, 1);

        toolButtonSetForAllColorScan = new QToolButton(groupBox);
        toolButtonSetForAllColorScan->setObjectName(QString::fromUtf8("toolButtonSetForAllColorScan"));
        toolButtonSetForAllColorScan->setIcon(icon18);
        toolButtonSetForAllColorScan->setIconSize(QSize(20, 20));
        toolButtonSetForAllColorScan->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout_2->addWidget(toolButtonSetForAllColorScan, 1, 1, 1, 1);

        toolButtonSetForAllScanDpi = new QToolButton(groupBox);
        toolButtonSetForAllScanDpi->setObjectName(QString::fromUtf8("toolButtonSetForAllScanDpi"));
        toolButtonSetForAllScanDpi->setIcon(icon18);
        toolButtonSetForAllScanDpi->setIconSize(QSize(20, 20));
        toolButtonSetForAllScanDpi->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout_2->addWidget(toolButtonSetForAllScanDpi, 0, 2, 1, 1);

        toolButtonSetForAllCleanScan = new QToolButton(groupBox);
        toolButtonSetForAllCleanScan->setObjectName(QString::fromUtf8("toolButtonSetForAllCleanScan"));
        toolButtonSetForAllCleanScan->setIcon(icon18);
        toolButtonSetForAllCleanScan->setIconSize(QSize(20, 20));
        toolButtonSetForAllCleanScan->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout_2->addWidget(toolButtonSetForAllCleanScan, 2, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_2);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_6);


        horizontalLayout_2->addWidget(groupBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_8->addWidget(frame);

        frame_8 = new QFrame(tab);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setFrameShape(QFrame::NoFrame);
        frame_8->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_8);
        horizontalLayout_5->setSpacing(4);
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        labelTitle_2 = new QLabel(frame_8);
        labelTitle_2->setObjectName(QString::fromUtf8("labelTitle_2"));
        labelTitle_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        labelTitle_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(labelTitle_2);

        labelTitle_3 = new QLabel(frame_8);
        labelTitle_3->setObjectName(QString::fromUtf8("labelTitle_3"));
        labelTitle_3->setStyleSheet(QString::fromUtf8(""));
        labelTitle_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(labelTitle_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_8->addWidget(frame_8);

        verticalSpacer_3 = new QSpacerItem(20, 1000, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_8->addItem(verticalSpacer_3);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_6 = new QVBoxLayout(tab_2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_27 = new QLabel(tab_2);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        verticalLayout_6->addWidget(label_27);

        frame_9 = new QFrame(tab_2);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setFrameShape(QFrame::NoFrame);
        frame_9->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_9);
        horizontalLayout_6->setSpacing(3);
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lineEditCategory = new QLineEdit(frame_9);
        lineEditCategory->setObjectName(QString::fromUtf8("lineEditCategory"));

        horizontalLayout_6->addWidget(lineEditCategory);

        toolButtonSetCategoryForAllBooks = new QToolButton(frame_9);
        toolButtonSetCategoryForAllBooks->setObjectName(QString::fromUtf8("toolButtonSetCategoryForAllBooks"));
        toolButtonSetCategoryForAllBooks->setIcon(icon18);
        toolButtonSetCategoryForAllBooks->setIconSize(QSize(20, 20));
        toolButtonSetCategoryForAllBooks->setToolButtonStyle(Qt::ToolButtonIconOnly);

        horizontalLayout_6->addWidget(toolButtonSetCategoryForAllBooks);


        verticalLayout_6->addWidget(frame_9);

        label_19 = new QLabel(tab_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        verticalLayout_6->addWidget(label_19);

        listWidgetSubjects = new QListWidget(tab_2);
        listWidgetSubjects->setObjectName(QString::fromUtf8("listWidgetSubjects"));

        verticalLayout_6->addWidget(listWidgetSubjects);

        label_26 = new QLabel(tab_2);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        verticalLayout_6->addWidget(label_26);

        treeWidgetCategories = new QTreeWidget(tab_2);
        new QTreeWidgetItem(treeWidgetCategories);
        new QTreeWidgetItem(treeWidgetCategories);
        new QTreeWidgetItem(treeWidgetCategories);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidgetCategories);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(treeWidgetCategories);
        new QTreeWidgetItem(treeWidgetCategories);
        new QTreeWidgetItem(treeWidgetCategories);
        new QTreeWidgetItem(treeWidgetCategories);
        new QTreeWidgetItem(treeWidgetCategories);
        new QTreeWidgetItem(treeWidgetCategories);
        new QTreeWidgetItem(treeWidgetCategories);
        new QTreeWidgetItem(treeWidgetCategories);
        treeWidgetCategories->setObjectName(QString::fromUtf8("treeWidgetCategories"));

        verticalLayout_6->addWidget(treeWidgetCategories);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_7 = new QVBoxLayout(tab_3);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label = new QLabel(tab_3);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_7->addWidget(label);

        frame_6 = new QFrame(tab_3);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_6);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lineEditCommentary = new QLineEdit(frame_6);
        lineEditCommentary->setObjectName(QString::fromUtf8("lineEditCommentary"));

        horizontalLayout_3->addWidget(lineEditCommentary);

        toolButtonSetCommentForAllBooks = new QToolButton(frame_6);
        toolButtonSetCommentForAllBooks->setObjectName(QString::fromUtf8("toolButtonSetCommentForAllBooks"));
        toolButtonSetCommentForAllBooks->setIcon(icon18);
        toolButtonSetCommentForAllBooks->setIconSize(QSize(20, 20));
        toolButtonSetCommentForAllBooks->setToolButtonStyle(Qt::ToolButtonIconOnly);

        horizontalLayout_3->addWidget(toolButtonSetCommentForAllBooks);


        verticalLayout_7->addWidget(frame_6);

        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_7->addWidget(label_3);

        textEditDescription = new QTextEdit(tab_3);
        textEditDescription->setObjectName(QString::fromUtf8("textEditDescription"));
        sizePolicy1.setHeightForWidth(textEditDescription->sizePolicy().hasHeightForWidth());
        textEditDescription->setSizePolicy(sizePolicy1);
        textEditDescription->setMinimumSize(QSize(0, 100));

        verticalLayout_7->addWidget(textEditDescription);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_12->addWidget(tabWidget);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_10 = new QVBoxLayout(page_2);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_2);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        verticalLayout_11 = new QVBoxLayout(page_3);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        label_28 = new QLabel(page_3);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label_28);

        stackedWidget->addWidget(page_3);

        verticalLayout_14->addWidget(stackedWidget);

        dockWidgetDescription->setWidget(dockWidgetContents_3);
        guMainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidgetDescription);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_8->menuAction());
        menu->addAction(actionInspectFolder);
        menu->addAction(actionAbortInspectProcess);
        menu->addSeparator();
        menu->addAction(actionGetBiblioInfo);
        menu->addAction(actionUploadToServer);
        menu->addSeparator();
        menu->addAction(actionShowSettingsDialog);
        menu_2->addAction(menu_4->menuAction());
        menu_2->addAction(menu_5->menuAction());
        menu_2->addAction(menu_7->menuAction());
        menu_2->addAction(menu_6->menuAction());
        menu_4->addAction(actionFileListLeft);
        menu_4->addAction(actionFileListRight);
        menu_5->addAction(action_8);
        menu_5->addAction(action_9);
        menu_7->addAction(actionToogleShowDublicates);
        menu_7->addAction(actionToogleShowWithISBN);
        menu_7->addAction(actionToogleShowWithBibliography);
        menu_7->addAction(actionToogleShowUploaded);
        menu_6->addAction(action);
        menu_6->addAction(action_2);
        menu_6->addAction(actionISBN);
        menu_6->addAction(action_3);
        menu_6->addAction(action_4);
        menu_3->addAction(actionHelp);
        menu_3->addAction(actionAbout);
        menu_8->addAction(actionExportToCSV);
        mainToolBar->addAction(actionInspectFolder);
        mainToolBar->addAction(actionAbortInspectProcess);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionGetBiblioInfo);
        mainToolBar->addAction(actionUploadToServer);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionToogleShowDublicates);
        mainToolBar->addAction(actionToogleShowWithISBN);
        mainToolBar->addAction(actionToogleShowWithBibliography);
        mainToolBar->addAction(actionToogleShowUploaded);
        mainToolBar->addAction(actionSelectAllForUpload);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionShowSettingsDialog);
        mainToolBar->addAction(actionHelp);
        mainToolBar->addAction(actionAbout);

        retranslateUi(guMainWindow);

        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(guMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *guMainWindow)
    {
        guMainWindow->setWindowTitle(QApplication::translate("guMainWindow", "Genesis Uploader v 0.4 (beta)", 0, QApplication::UnicodeUTF8));
        actionInspectFolder->setText(QApplication::translate("guMainWindow", "\320\230\321\201\320\272\320\260\321\202\321\214 \320\272\320\275\320\270\320\263\320\270", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionInspectFolder->setToolTip(QApplication::translate("guMainWindow", "\320\230\321\201\320\272\320\260\321\202\321\214 \320\272\320\275\320\270\320\263\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionUploadToServer->setText(QApplication::translate("guMainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\275\320\260 \321\201\320\265\321\200\320\262\320\265\321\200", 0, QApplication::UnicodeUTF8));
        actionGetBiblioInfo->setText(QApplication::translate("guMainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \320\261\320\270\320\261\320\273\320\270\320\276\320\263\321\200\320\260\321\204\320\270\321\216", 0, QApplication::UnicodeUTF8));
        actionShowSettingsDialog->setText(QApplication::translate("guMainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionShowSettingsDialog->setToolTip(QApplication::translate("guMainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSelectAllForUpload->setText(QApplication::translate("guMainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\262\321\201\320\265 \320\264\320\273\321\217 \320\267\320\260\320\263\321\200\321\203\320\267\320\272\320\270 \320\275\320\260 \321\201\320\265\321\200\320\262\320\265\321\200", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSelectAllForUpload->setToolTip(QApplication::translate("guMainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\262\321\201\320\265 \320\264\320\273\321\217 \320\267\320\260\320\263\321\200\321\203\320\267\320\272\320\270 \320\275\320\260 \321\201\320\265\321\200\320\262\320\265\321\200", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionToogleShowDublicates->setText(QApplication::translate("guMainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214/\321\201\320\272\321\200\321\213\321\202\321\214  \320\264\321\203\320\261\320\273\320\270\320\272\320\260\321\202\321\213", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionToogleShowDublicates->setToolTip(QApplication::translate("guMainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214/\321\201\320\272\321\200\321\213\321\202\321\214  \320\264\321\203\320\261\320\273\320\270\320\272\320\260\321\202\321\213", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionToogleShowWithISBN->setText(QApplication::translate("guMainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214/\321\201\320\272\321\200\321\213\321\202\321\214 \320\272\320\275\320\270\320\263\320\270 \321\201 ISBN", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionToogleShowWithISBN->setToolTip(QApplication::translate("guMainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214/\321\201\320\272\321\200\321\213\321\202\321\214 \320\272\320\275\320\270\320\263\320\270 \321\201 ISBN", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionToogleShowWithBibliography->setText(QApplication::translate("guMainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214/\321\201\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273\321\213 \321\201 \320\267\320\260\320\277\320\276\320\273\320\275\320\265\320\275\320\275\320\276\320\271 \320\261\320\270\320\261\320\273\320\270\320\276\320\263\321\200\320\260\321\204\320\270\320\265\320\271", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionToogleShowWithBibliography->setToolTip(QApplication::translate("guMainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214/\321\201\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273\321\213 \321\201 \320\267\320\260\320\277\320\276\320\273\320\275\320\265\320\275\320\275\320\276\320\271 \320\261\320\270\320\261\320\273\320\270\320\276\320\263\321\200\320\260\321\204\320\270\320\265\320\271", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionToogleShowUploaded->setText(QApplication::translate("guMainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214/\321\201\320\272\321\200\321\213\321\202\321\214 \320\267\320\260\320\263\321\200\321\203\320\266\320\265\320\275\320\275\321\213\320\265 \320\275\320\260 \321\201\320\265\321\200\320\262\320\265\321\200", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionToogleShowUploaded->setToolTip(QApplication::translate("guMainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214/\321\201\320\272\321\200\321\213\321\202\321\214 \320\267\320\260\320\263\321\200\321\203\320\266\320\265\320\275\320\275\321\213\320\265 \320\275\320\260 \321\201\320\265\321\200\320\262\320\265\321\200", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionAbortInspectProcess->setText(QApplication::translate("guMainWindow", "\320\237\321\200\320\265\320\272\321\200\320\260\321\202\320\270\321\202\321\214 \320\277\320\276\320\270\321\201\320\272", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAbortInspectProcess->setToolTip(QApplication::translate("guMainWindow", "\320\237\321\200\320\265\320\272\321\200\320\260\321\202\320\270\321\202\321\214 \320\277\320\276\320\270\321\201\320\272", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionHelp->setText(QApplication::translate("guMainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionHelp->setToolTip(QApplication::translate("guMainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionAbout->setText(QApplication::translate("guMainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("guMainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionFileListLeft->setText(QApplication::translate("guMainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213 \320\277\320\276\320\270\321\201\320\272\320\260 \321\201\320\273\320\265\320\262\320\260", 0, QApplication::UnicodeUTF8));
        actionFileListRight->setText(QApplication::translate("guMainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213 \320\277\320\276\320\270\321\201\320\272\320\260 \321\201\320\277\321\200\320\260\320\262\320\260", 0, QApplication::UnicodeUTF8));
        action_8->setText(QApplication::translate("guMainWindow", "\320\240\321\203\321\201\321\201\320\272\320\270\320\271", 0, QApplication::UnicodeUTF8));
        action_9->setText(QApplication::translate("guMainWindow", "\320\220\320\275\320\263\320\273\320\270\320\271\321\201\320\272\320\270\320\271", 0, QApplication::UnicodeUTF8));
        actionExportToCSV->setText(QApplication::translate("guMainWindow", "CSV ...", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("guMainWindow", "\320\230\320\274\321\217 \321\204\320\260\320\271\320\273\320\260", 0, QApplication::UnicodeUTF8));
        action_2->setText(QApplication::translate("guMainWindow", "\320\240\320\260\321\201\321\210\320\270\321\200\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        actionISBN->setText(QApplication::translate("guMainWindow", "ISBN(\321\213)", 0, QApplication::UnicodeUTF8));
        action_3->setText(QApplication::translate("guMainWindow", "\320\220\320\262\321\202\320\276\321\200\321\213", 0, QApplication::UnicodeUTF8));
        action_4->setText(QApplication::translate("guMainWindow", "\320\223\320\276\320\264 \320\270\320\267\320\264\320\260\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidgetFiles->headerItem();
        ___qtreewidgetitem->setText(3, QApplication::translate("guMainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("guMainWindow", "\320\242\320\270\320\277", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("guMainWindow", "\320\244\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("guMainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("guMainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\265\320\275\320\276: ", 0, QApplication::UnicodeUTF8));
        labelNumOfInspected->setText(QApplication::translate("guMainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("guMainWindow", "\320\222 \320\261\320\270\320\261\320\273\320\270\320\276\321\202\320\265\320\272\320\265:", 0, QApplication::UnicodeUTF8));
        labelNumOfDublicates->setText(QApplication::translate("guMainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("guMainWindow", "\321\201 ISBN:", 0, QApplication::UnicodeUTF8));
        labelNumOfWithIsbn->setText(QApplication::translate("guMainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("guMainWindow", " \320\221\320\270\320\261\320\273\320\270\320\276\320\263\321\200\320\260\321\204\320\270\321\217:", 0, QApplication::UnicodeUTF8));
        labelNumOfWithBiblio->setText(QApplication::translate("guMainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("guMainWindow", "\320\227\320\260\320\263\321\200\321\203\320\266\320\265\320\275\320\276:", 0, QApplication::UnicodeUTF8));
        labelNumOfUploaded->setText(QApplication::translate("guMainWindow", "0", 0, QApplication::UnicodeUTF8));
        labelProcessStatus->setText(QString());
        menu->setTitle(QApplication::translate("guMainWindow", "\320\244\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("guMainWindow", "\320\222\320\270\320\264", 0, QApplication::UnicodeUTF8));
        menu_4->setTitle(QApplication::translate("guMainWindow", "\320\240\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\277\320\260\320\275\320\265\320\273\320\265\320\271", 0, QApplication::UnicodeUTF8));
        menu_5->setTitle(QApplication::translate("guMainWindow", "\320\257\320\267\321\213\320\272", 0, QApplication::UnicodeUTF8));
        menu_7->setTitle(QApplication::translate("guMainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200", 0, QApplication::UnicodeUTF8));
        menu_6->setTitle(QApplication::translate("guMainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\266\320\260\320\265\320\274\321\213\320\265 \320\272\320\276\320\273\320\276\320\275\320\272\320\270", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("guMainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
        menu_8->setTitle(QApplication::translate("guMainWindow", "\320\255\320\272\321\201\320\277\320\276\321\200\321\202", 0, QApplication::UnicodeUTF8));
        dockWidgetDescription->setWindowTitle(QApplication::translate("guMainWindow", "   \320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("guMainWindow", "   MD5:", 0, QApplication::UnicodeUTF8));
        labelCurrentMD5->setText(QString());
#ifndef QT_NO_TOOLTIP
        toolButtonCopyMD5toClipboard->setToolTip(QApplication::translate("guMainWindow", "\320\241\320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214 MD5 \320\262 \320\261\321\203\321\204\320\265\321\200 \320\276\320\261\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonCopyMD5toClipboard->setText(QApplication::translate("guMainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonBookOpen->setToolTip(QApplication::translate("guMainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonBookOpen->setText(QApplication::translate("guMainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonGetBiblioForItem->setToolTip(QApplication::translate("guMainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \320\261\320\270\320\261\320\273\320\270\320\276\320\263\321\200\320\260\321\204\320\270\321\216 \320\264\320\273\321\217 \320\272\320\275\320\270\320\263\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonGetBiblioForItem->setText(QApplication::translate("guMainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonSaveChanges->setToolTip(QApplication::translate("guMainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonSaveChanges->setText(QApplication::translate("guMainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("guMainWindow", "ISBN", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonAddIsbn->setToolTip(QApplication::translate("guMainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 ISBN \320\262 \321\201\320\277\320\270\321\201\320\276\320\272", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonAddIsbn->setText(QApplication::translate("guMainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonRemoveIsbn->setToolTip(QApplication::translate("guMainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 ISBN \320\270\320\267 \321\201\320\277\320\270\321\201\320\272\320\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonRemoveIsbn->setText(QApplication::translate("guMainWindow", "...", 0, QApplication::UnicodeUTF8));
        labelTitle->setText(QApplication::translate("guMainWindow", "\320\227\320\260\320\263\320\276\320\273\320\276\320\262\320\276\320\272:", 0, QApplication::UnicodeUTF8));
        labelAuthors->setText(QApplication::translate("guMainWindow", "\320\220\320\262\321\202\320\276\321\200\321\213:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("guMainWindow", "\320\230\320\267\320\264\320\260\320\275\320\270\320\265:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("guMainWindow", "\320\241\320\265\321\200\320\270\321\217:", 0, QApplication::UnicodeUTF8));
        labelPublisher->setText(QApplication::translate("guMainWindow", "\320\230\320\267\320\264-\320\262\320\276:", 0, QApplication::UnicodeUTF8));
        labelLanguage->setText(QApplication::translate("guMainWindow", "\320\257\320\267\321\213\320\272:", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("guMainWindow", "\320\243\320\224\320\232:", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("guMainWindow", "\320\221\320\221\320\232:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("guMainWindow", "\320\223\320\276\321\200\320\276\320\264:", 0, QApplication::UnicodeUTF8));
        labelPubYear->setText(QApplication::translate("guMainWindow", "\320\223\320\276\320\264 \320\270\320\267\320\264\320\260\320\275\320\270\321\217:", 0, QApplication::UnicodeUTF8));
        lineEditPubYear->setInputMask(QApplication::translate("guMainWindow", "D999; ", 0, QApplication::UnicodeUTF8));
        lineEditPubYear->setText(QString());
        labelPageNum->setText(QApplication::translate("guMainWindow", "\320\241\321\202\321\200\320\260\320\275\320\270\321\206:", 0, QApplication::UnicodeUTF8));
        comboBoxOrientation->clear();
        comboBoxOrientation->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("guMainWindow", "portrait", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("guMainWindow", "landscape", 0, QApplication::UnicodeUTF8)
        );
        label_13->setText(QApplication::translate("guMainWindow", "\320\236\321\200\320\270\320\265\320\275\321\202\320\260\321\206\320\270\321\217:", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("guMainWindow", "\320\242\320\276\320\274:", 0, QApplication::UnicodeUTF8));
        lineEditPageNum->setInputMask(QApplication::translate("guMainWindow", "D000000; ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonSetForAllPublisher->setToolTip(QApplication::translate("guMainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\264\320\273\321\217 \320\262\321\201\320\265\321\205 \320\272\320\275\320\270\320\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonSetForAllPublisher->setText(QApplication::translate("guMainWindow", "\320\224\320\273\321\217 \320\262\321\201\320\265\321\205              ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonSetForAllUdc->setToolTip(QApplication::translate("guMainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\264\320\273\321\217 \320\262\321\201\320\265\321\205 \320\272\320\275\320\270\320\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonSetForAllUdc->setText(QApplication::translate("guMainWindow", "\320\224\320\273\321\217 \320\262\321\201\320\265\321\205              ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonSetForAllSity->setToolTip(QApplication::translate("guMainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\264\320\273\321\217 \320\262\321\201\320\265\321\205 \320\272\320\275\320\270\320\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonSetForAllSity->setText(QApplication::translate("guMainWindow", "\320\224\320\273\321\217 \320\262\321\201\320\265\321\205              ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonSetForAllSeries->setToolTip(QApplication::translate("guMainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\264\320\273\321\217 \320\262\321\201\320\265\321\205 \320\272\320\275\320\270\320\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonSetForAllSeries->setText(QApplication::translate("guMainWindow", "\320\224\320\273\321\217 \320\262\321\201\320\265\321\205              ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonSetForAllAuthors->setToolTip(QApplication::translate("guMainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\264\320\273\321\217 \320\262\321\201\320\265\321\205 \320\272\320\275\320\270\320\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonSetForAllAuthors->setText(QApplication::translate("guMainWindow", "\320\224\320\273\321\217 \320\262\321\201\320\265\321\205              ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonSetForAllTitle->setToolTip(QApplication::translate("guMainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\264\320\273\321\217 \320\262\321\201\320\265\321\205 \320\272\320\275\320\270\320\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonSetForAllTitle->setText(QApplication::translate("guMainWindow", "\320\224\320\273\321\217 \320\262\321\201\320\265\321\205              ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonSetForAllOrientation->setToolTip(QApplication::translate("guMainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\264\320\273\321\217 \320\262\321\201\320\265\321\205 \320\272\320\275\320\270\320\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonSetForAllOrientation->setText(QApplication::translate("guMainWindow", "\320\224\320\273\321\217 \320\262\321\201\320\265\321\205              ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonSetForAllLanguage->setToolTip(QApplication::translate("guMainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\264\320\273\321\217 \320\262\321\201\320\265\321\205 \320\272\320\275\320\270\320\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonSetForAllLanguage->setText(QApplication::translate("guMainWindow", "\320\224\320\273\321\217 \320\262\321\201\320\265\321\205              ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonSetForAllBbc->setToolTip(QApplication::translate("guMainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\264\320\273\321\217 \320\262\321\201\320\265\321\205 \320\272\320\275\320\270\320\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonSetForAllBbc->setText(QApplication::translate("guMainWindow", "\320\224\320\273\321\217 \320\262\321\201\320\265\321\205              ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonSetForAllPubYear->setToolTip(QApplication::translate("guMainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\264\320\273\321\217 \320\262\321\201\320\265\321\205 \320\272\320\275\320\270\320\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonSetForAllPubYear->setText(QApplication::translate("guMainWindow", "\320\224\320\273\321\217 \320\262\321\201\320\265\321\205              ", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("guMainWindow", "\320\226\321\203\321\200\320\275\320\260\320\273:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonSetForAllPeriodical->setToolTip(QApplication::translate("guMainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\264\320\273\321\217 \320\262\321\201\320\265\321\205 \320\272\320\275\320\270\320\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonSetForAllPeriodical->setText(QApplication::translate("guMainWindow", "\320\224\320\273\321\217 \320\262\321\201\320\265\321\205              ", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("guMainWindow", "\320\232\320\276\320\273\320\273\320\265\320\272\321\206\320\270\321\217-\320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("guMainWindow", "\320\221\320\270\320\261\320\273\320\270\320\276\321\202\320\265\320\272\320\260:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("guMainWindow", "\320\230\320\267\320\264\320\260\320\275\320\270\320\265:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonSetForAllLibrary->setToolTip(QApplication::translate("guMainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\264\320\273\321\217 \320\262\321\201\320\265\321\205 \320\272\320\275\320\270\320\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonSetForAllLibrary->setText(QApplication::translate("guMainWindow", "\320\224\320\273\321\217 \320\262\321\201\320\265\321\205              ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonSetForAllLibraryIssue->setToolTip(QApplication::translate("guMainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\264\320\273\321\217 \320\262\321\201\320\265\321\205 \320\272\320\275\320\270\320\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonSetForAllLibraryIssue->setText(QApplication::translate("guMainWindow", "\320\224\320\273\321\217 \320\262\321\201\320\265\321\205              ", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("guMainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\201\320\272\320\260\320\275\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("guMainWindow", "\320\240\320\260\320\267\321\200\320\265\321\210\320\265\320\275\320\270\320\265 \321\201\320\272\320\260\320\275\320\260:", 0, QApplication::UnicodeUTF8));
        lineEditDpi->setInputMask(QApplication::translate("guMainWindow", "D000000; ", 0, QApplication::UnicodeUTF8));
        checkBoxColorScan->setText(QApplication::translate("guMainWindow", "\320\246\320\262\320\265\321\202\320\275\320\276\320\271 \321\201\320\272\320\260\320\275", 0, QApplication::UnicodeUTF8));
        checkBoxClearScan->setText(QApplication::translate("guMainWindow", "\320\236\320\261\321\200\320\265\320\267\320\260\320\275\321\213\320\271 \321\201\320\272\320\260\320\275", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonSetForAllColorScan->setToolTip(QApplication::translate("guMainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\264\320\273\321\217 \320\262\321\201\320\265\321\205 \320\272\320\275\320\270\320\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonSetForAllColorScan->setText(QApplication::translate("guMainWindow", "\320\224\320\273\321\217 \320\262\321\201\320\265\321\205              ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonSetForAllScanDpi->setToolTip(QApplication::translate("guMainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\264\320\273\321\217 \320\262\321\201\320\265\321\205 \320\272\320\275\320\270\320\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonSetForAllScanDpi->setText(QApplication::translate("guMainWindow", "\320\224\320\273\321\217 \320\262\321\201\320\265\321\205              ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonSetForAllCleanScan->setToolTip(QApplication::translate("guMainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\264\320\273\321\217 \320\262\321\201\320\265\321\205 \320\272\320\275\320\270\320\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonSetForAllCleanScan->setText(QApplication::translate("guMainWindow", "\320\224\320\273\321\217 \320\262\321\201\320\265\321\205              ", 0, QApplication::UnicodeUTF8));
        labelTitle_2->setText(QApplication::translate("guMainWindow", "* \320\272\321\200\320\260\321\201\320\275\321\213\320\274", 0, QApplication::UnicodeUTF8));
        labelTitle_3->setText(QApplication::translate("guMainWindow", "\320\276\320\261\320\276\320\267\320\275\320\260\321\207\320\265\320\275\321\213 \320\277\320\276\320\273\321\217, \320\276\320\261\321\217\320\267\320\260\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \320\272 \320\267\320\260\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\216", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("guMainWindow", "\320\221\320\270\320\261\320\273\320\270\320\276\320\263\321\200\320\260\321\204\320\270\321\217", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("guMainWindow", "\320\243\320\272\320\260\320\267\320\260\321\202\321\214 \321\201\320\260\320\274\320\276\321\201\321\202\320\276\321\217\321\202\320\265\320\273\321\214\320\275\320\276:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonSetCategoryForAllBooks->setToolTip(QApplication::translate("guMainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\264\320\273\321\217 \320\262\321\201\320\265\321\205 \320\272\320\275\320\270\320\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonSetCategoryForAllBooks->setText(QApplication::translate("guMainWindow", "\320\224\320\273\321\217 \320\262\321\201\320\265\321\205", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("guMainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\270\320\267 \321\201\320\277\320\270\321\201\320\272\320\260:", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("guMainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\270\320\267 \320\264\320\265\321\200\320\265\320\262\320\260 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\271:", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidgetCategories->headerItem();
        ___qtreewidgetitem1->setText(1, QApplication::translate("guMainWindow", "\320\232\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\271", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(0, QApplication::translate("guMainWindow", "\320\242\320\265\320\274\320\260\321\202\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = treeWidgetCategories->isSortingEnabled();
        treeWidgetCategories->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidgetCategories->topLevelItem(0);
        ___qtreewidgetitem2->setText(1, QApplication::translate("guMainWindow", "\320\235\320\265 \320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(0, QApplication::translate("guMainWindow", "None", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidgetCategories->topLevelItem(1);
        ___qtreewidgetitem3->setText(1, QApplication::translate("guMainWindow", "\320\221\320\270\320\276\320\273\320\276\320\263\320\270\321\217", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem3->setText(0, QApplication::translate("guMainWindow", "Biology", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidgetCategories->topLevelItem(2);
        ___qtreewidgetitem4->setText(1, QApplication::translate("guMainWindow", "\320\245\320\270\320\274\320\270\321\217", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem4->setText(0, QApplication::translate("guMainWindow", "Chemistry", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem5 = treeWidgetCategories->topLevelItem(3);
        ___qtreewidgetitem5->setText(1, QApplication::translate("guMainWindow", "\320\232\320\276\320\274\320\277\321\214\321\216\321\202\320\265\321\200\320\275\321\213\320\265 \320\275\320\260\321\203\320\272\320\270", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem5->setText(0, QApplication::translate("guMainWindow", "Computer science", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem5->child(0);
        ___qtreewidgetitem6->setText(1, QApplication::translate("guMainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274\321\213", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem6->setText(0, QApplication::translate("guMainWindow", "Algorithms", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem5->child(1);
        ___qtreewidgetitem7->setText(1, QApplication::translate("guMainWindow", "\320\230\321\201\320\272\321\203\321\201\321\201\321\202\320\262\320\265\320\275\320\275\321\213\320\271 \320\270\320\275\321\202\320\265\320\273\320\273\320\265\320\272\321\202", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem7->setText(0, QApplication::translate("guMainWindow", "Artificial Intelligence", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem5->child(2);
        ___qtreewidgetitem8->setText(1, QApplication::translate("guMainWindow", "\320\221\320\270\320\276\320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\202\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem8->setText(0, QApplication::translate("guMainWindow", "Bioinformatics", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem5->child(3);
        ___qtreewidgetitem9->setText(1, QApplication::translate("guMainWindow", "\320\241\320\262\321\217\320\267\321\214", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem9->setText(0, QApplication::translate("guMainWindow", "Communications", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem5->child(4);
        ___qtreewidgetitem10->setText(1, QApplication::translate("guMainWindow", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\320\274\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem10->setText(0, QApplication::translate("guMainWindow", "Computability", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem5->child(5);
        ___qtreewidgetitem11->setText(1, QApplication::translate("guMainWindow", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\320\265\320\273\321\214\320\275\320\260\321\217 \320\263\320\265\320\276\320\274\320\265\321\202\321\200\320\270\321\217", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem11->setText(0, QApplication::translate("guMainWindow", "Computational geometry", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem5->child(6);
        ___qtreewidgetitem12->setText(1, QApplication::translate("guMainWindow", "\320\232\320\276\320\274\320\277\321\214\321\216\321\202\320\265\321\200\320\275\320\260\321\217 \320\260\320\273\320\263\320\265\320\261\321\200\320\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem12->setText(0, QApplication::translate("guMainWindow", "Computer algebra", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem13 = ___qtreewidgetitem5->child(7);
        ___qtreewidgetitem13->setText(1, QApplication::translate("guMainWindow", "\320\232\321\200\320\270\320\277\321\202\320\276\320\263\321\200\320\260\321\204\320\270\321\217", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem13->setText(0, QApplication::translate("guMainWindow", "Cryptography", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem14 = ___qtreewidgetitem5->child(8);
        ___qtreewidgetitem14->setText(1, QApplication::translate("guMainWindow", "\320\221\320\260\320\267\321\213 \320\264\320\260\320\275\320\275\321\213\321\205", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem14->setText(0, QApplication::translate("guMainWindow", "Databases", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem15 = ___qtreewidgetitem5->child(9);
        ___qtreewidgetitem15->setText(1, QApplication::translate("guMainWindow", "\320\224\320\270\321\201\320\272\321\200\320\265\321\202\320\275\320\260\321\217 \320\274\320\260\321\202\320\265\320\274\320\260\321\202\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem15->setText(0, QApplication::translate("guMainWindow", "Discrete Mathematics", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem16 = ___qtreewidgetitem5->child(10);
        ___qtreewidgetitem16->setText(1, QApplication::translate("guMainWindow", "\320\240\320\260\320\267\321\200\320\260\320\261\320\276\321\202\320\272\320\260 \320\270\320\263\321\200", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem16->setText(0, QApplication::translate("guMainWindow", "Game Programming", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem17 = treeWidgetCategories->topLevelItem(4);
        ___qtreewidgetitem17->setText(1, QApplication::translate("guMainWindow", "\320\255\320\275\321\206\320\270\320\272\320\273\320\276\320\277\320\265\320\264\320\270\320\270 \320\236\320\261\321\211\320\270\320\265", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem17->setText(0, QApplication::translate("guMainWindow", "Encyclopaediae General", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem18 = treeWidgetCategories->topLevelItem(5);
        ___qtreewidgetitem18->setText(1, QApplication::translate("guMainWindow", "\320\230\320\275\320\266\320\265\320\275\320\265\321\200\320\275\321\213\320\265 \320\275\320\260\321\203\320\272\320\270", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem18->setText(0, QApplication::translate("guMainWindow", "Engineering Sciences", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem19 = treeWidgetCategories->topLevelItem(6);
        ___qtreewidgetitem19->setText(1, QApplication::translate("guMainWindow", "\320\235\320\260\321\203\320\272\320\270 \320\276 \320\267\320\265\320\274\320\273\320\265", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem19->setText(0, QApplication::translate("guMainWindow", "GeoSciences", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem20 = treeWidgetCategories->topLevelItem(7);
        ___qtreewidgetitem20->setText(1, QApplication::translate("guMainWindow", "\320\245\320\276\320\261\320\261\320\270", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem20->setText(0, QApplication::translate("guMainWindow", "Hobby", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem21 = treeWidgetCategories->topLevelItem(8);
        ___qtreewidgetitem21->setText(1, QApplication::translate("guMainWindow", "\320\223\321\203\320\274\320\260\320\275\320\270\321\202\320\260\321\200\320\275\321\213\320\265 \320\275\320\260\321\203\320\272\320\270", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem21->setText(0, QApplication::translate("guMainWindow", "Humanities", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem22 = treeWidgetCategories->topLevelItem(9);
        ___qtreewidgetitem22->setText(1, QApplication::translate("guMainWindow", "\320\234\320\260\321\202\320\265\320\274\320\260\321\202\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem22->setText(0, QApplication::translate("guMainWindow", "Mathematics", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem23 = treeWidgetCategories->topLevelItem(10);
        ___qtreewidgetitem23->setText(1, QApplication::translate("guMainWindow", "\320\234\320\265\320\264\320\270\321\206\320\270\320\275\320\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem23->setText(0, QApplication::translate("guMainWindow", "Medical", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem24 = treeWidgetCategories->topLevelItem(11);
        ___qtreewidgetitem24->setText(1, QApplication::translate("guMainWindow", "\320\244\320\270\320\267\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem24->setText(0, QApplication::translate("guMainWindow", "Physics", 0, QApplication::UnicodeUTF8));
        treeWidgetCategories->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("guMainWindow", "\320\242\320\265\320\274\320\260\321\202\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("guMainWindow", "\320\232\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\271 \320\267\320\260\320\263\321\200\321\203\320\266\320\260\321\216\321\211\320\265\320\263\320\276:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButtonSetCommentForAllBooks->setToolTip(QApplication::translate("guMainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\264\320\273\321\217 \320\262\321\201\320\265\321\205 \320\272\320\275\320\270\320\263", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButtonSetCommentForAllBooks->setText(QApplication::translate("guMainWindow", "\320\224\320\273\321\217 \320\262\321\201\320\265\321\205", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("guMainWindow", "\320\220\320\275\320\275\320\276\321\202\320\260\321\206\320\270\321\217:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("guMainWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("guMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">\320\244\320\260\320\271\320\273 </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">\320\277\321\200\320\270\321\201\321\203\321\202\321\201\321\202\320\262\321\203\320\265\321\202 </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">\320\262"
                        " \320\272\320\276\320\273\320\273\320\265\320\272\321\206\320\270\320\270</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("guMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class guMainWindow: public Ui_guMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUMAINWINDOW_H
