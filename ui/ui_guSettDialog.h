/********************************************************************************
** Form generated from reading UI file 'guSettDialog.ui'
**
** Created: Sun 28. Apr 10:51:02 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUSETTDIALOG_H
#define UI_GUSETTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guSettDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidgetSettGroup;
    QStackedWidget *stackedWidgetSettTabs;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_8;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEditServiceUrl;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *radioButtonInLibNoAction;
    QRadioButton *radioButtonInLibRemove;
    QRadioButton *radioButtonInLibMoveToRep;
    QRadioButton *radioButtonInLibCopyToRep;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout;
    QToolButton *toolButton;
    QToolButton *toolButton_3;
    QTableWidget *tableWidget;
    QStackedWidget *stackedWidget_2;
    QWidget *page_6;
    QVBoxLayout *verticalLayout_6;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_8;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QLabel *label_7;
    QLineEdit *lineEdit_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QSpacerItem *horizontalSpacer_5;
    QWidget *page_7;
    QVBoxLayout *verticalLayout_7;
    QFrame *frame_9;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_12;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_5;
    QFrame *frame_12;
    QVBoxLayout *verticalLayout_17;
    QToolButton *toolButtonDataUp;
    QToolButton *toolButtonDataDown;
    QSpacerItem *verticalSpacer_5;
    QListWidget *listWidgetUsedDataSources;
    QFrame *frame_10;
    QVBoxLayout *verticalLayout_13;
    QToolButton *toolButtonAddDataSource;
    QToolButton *toolButtonRemoveDataSource;
    QSpacerItem *verticalSpacer_4;
    QListWidget *listWidgetExistingDataSources;
    QSpacerItem *horizontalSpacer_2;
    QWidget *page_5;
    QVBoxLayout *verticalLayout_15;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_16;
    QFormLayout *formLayout;
    QLabel *label_5;
    QPushButton *pushButtonDublicate;
    QLabel *label_11;
    QPushButton *pushButtonIsbn;
    QLabel *label_12;
    QPushButton *pushButtonBiblio;
    QLabel *label_13;
    QPushButton *pushButtonUploaded;
    QPushButton *pushButtonCategory;
    QLabel *label_14;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_19;
    QGridLayout *gridLayout_4;
    QCheckBox *checkBoxShowFileExtensionColumn;
    QCheckBox *checkBoxShowTitleColumn;
    QCheckBox *checkBoxShowAuthorsColumn;
    QCheckBox *checkBoxShowSeriesColumn;
    QCheckBox *checkBoxShowPeriodicalColumn;
    QCheckBox *checkBoxShowFileNameColumn;
    QCheckBox *checkBoxShowPublisherColumn;
    QCheckBox *checkBoxShowCityColumn;
    QCheckBox *checkBoxShowPubYearColumn;
    QCheckBox *checkBoxShowIssueColumn;
    QCheckBox *checkBoxShowVolumeColumn;
    QCheckBox *checkBoxShowPageNumColumn;
    QCheckBox *checkBoxShowLanguageColumn;
    QCheckBox *checkBoxShowUDCColumn;
    QCheckBox *checkBoxShowBBCColumn;
    QCheckBox *checkBoxShowCollectionColumn;
    QCheckBox *checkBoxShowCollectionIssueColumn;
    QCheckBox *checkBoxShowScanDpiColumn;
    QCheckBox *checkBoxShowColorScanColumn;
    QCheckBox *checkBoxShowClearScanColumn;
    QSpacerItem *verticalSpacer_8;
    QWidget *page_8;
    QVBoxLayout *verticalLayout_20;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_18;
    QCheckBox *checkBoxLogInspect;
    QCheckBox *checkBoxLogDublCheck;
    QCheckBox *checkBoxLogExtrISBN;
    QCheckBox *checkBoxLogBibFind;
    QCheckBox *checkBoxLogUpload;
    QSpacerItem *verticalSpacer_9;
    QFrame *frame_11;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonSet;
    QPushButton *pushButtonExit;

    void setupUi(QDialog *guSettDialog)
    {
        if (guSettDialog->objectName().isEmpty())
            guSettDialog->setObjectName(QString::fromUtf8("guSettDialog"));
        guSettDialog->resize(637, 517);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/configure.png"), QSize(), QIcon::Normal, QIcon::Off);
        guSettDialog->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(guSettDialog);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(guSettDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listWidgetSettGroup = new QListWidget(frame);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidgetSettGroup);
        __qlistwidgetitem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidgetSettGroup);
        __qlistwidgetitem1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidgetSettGroup);
        __qlistwidgetitem2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        new QListWidgetItem(listWidgetSettGroup);
        listWidgetSettGroup->setObjectName(QString::fromUtf8("listWidgetSettGroup"));
        listWidgetSettGroup->setMinimumSize(QSize(150, 0));
        listWidgetSettGroup->setMaximumSize(QSize(150, 16777215));
        listWidgetSettGroup->setFrameShape(QFrame::WinPanel);
        listWidgetSettGroup->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(listWidgetSettGroup);

        stackedWidgetSettTabs = new QStackedWidget(frame);
        stackedWidgetSettTabs->setObjectName(QString::fromUtf8("stackedWidgetSettTabs"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_4 = new QVBoxLayout(page_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        frame_3 = new QFrame(page_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame_3);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        frame_2 = new QFrame(frame_3);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label);

        lineEditServiceUrl = new QLineEdit(frame_2);
        lineEditServiceUrl->setObjectName(QString::fromUtf8("lineEditServiceUrl"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditServiceUrl->sizePolicy().hasHeightForWidth());
        lineEditServiceUrl->setSizePolicy(sizePolicy1);
        lineEditServiceUrl->setInputMethodHints(Qt::ImhUrlCharactersOnly);

        horizontalLayout_2->addWidget(lineEditServiceUrl);


        verticalLayout_8->addWidget(frame_2);

        groupBox_2 = new QGroupBox(frame_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        radioButtonInLibNoAction = new QRadioButton(groupBox_2);
        radioButtonInLibNoAction->setObjectName(QString::fromUtf8("radioButtonInLibNoAction"));
        radioButtonInLibNoAction->setChecked(true);

        verticalLayout_5->addWidget(radioButtonInLibNoAction);

        radioButtonInLibRemove = new QRadioButton(groupBox_2);
        radioButtonInLibRemove->setObjectName(QString::fromUtf8("radioButtonInLibRemove"));

        verticalLayout_5->addWidget(radioButtonInLibRemove);

        radioButtonInLibMoveToRep = new QRadioButton(groupBox_2);
        radioButtonInLibMoveToRep->setObjectName(QString::fromUtf8("radioButtonInLibMoveToRep"));

        verticalLayout_5->addWidget(radioButtonInLibMoveToRep);

        radioButtonInLibCopyToRep = new QRadioButton(groupBox_2);
        radioButtonInLibCopyToRep->setObjectName(QString::fromUtf8("radioButtonInLibCopyToRep"));

        verticalLayout_5->addWidget(radioButtonInLibCopyToRep);


        verticalLayout_8->addWidget(groupBox_2);

        groupBox = new QGroupBox(frame_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame_4 = new QFrame(groupBox);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        toolButton = new QToolButton(frame_4);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setMinimumSize(QSize(0, 26));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/add_22.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon1);
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton);

        toolButton_3 = new QToolButton(frame_4);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(0, 26));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/list_remove_22.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon2);
        toolButton_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_3);


        gridLayout->addWidget(frame_4, 0, 1, 1, 1);

        tableWidget = new QTableWidget(groupBox);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout);


        verticalLayout_8->addWidget(groupBox);

        stackedWidget_2 = new QStackedWidget(frame_3);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        verticalLayout_6 = new QVBoxLayout(page_6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        frame_8 = new QFrame(page_6);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        horizontalLayout_8 = new QHBoxLayout(frame_8);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_6 = new QLabel(frame_8);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        lineEdit_6 = new QLineEdit(frame_8);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        gridLayout_3->addWidget(lineEdit_6, 0, 1, 1, 1);

        label_7 = new QLabel(frame_8);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 1, 0, 1, 1);

        lineEdit_7 = new QLineEdit(frame_8);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setInputMethodHints(Qt::ImhDigitsOnly);

        gridLayout_3->addWidget(lineEdit_7, 1, 1, 1, 1);

        label_8 = new QLabel(frame_8);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 2, 0, 1, 1);

        label_9 = new QLabel(frame_8);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 3, 0, 1, 1);

        lineEdit_8 = new QLineEdit(frame_8);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setInputMethodHints(Qt::ImhNone);

        gridLayout_3->addWidget(lineEdit_8, 2, 1, 1, 1);

        lineEdit_9 = new QLineEdit(frame_8);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setInputMethodHints(Qt::ImhNone);

        gridLayout_3->addWidget(lineEdit_9, 3, 1, 1, 1);


        horizontalLayout_8->addLayout(gridLayout_3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);


        verticalLayout_6->addWidget(frame_8);

        stackedWidget_2->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        verticalLayout_7 = new QVBoxLayout(page_7);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        frame_9 = new QFrame(page_7);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_9);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, -1, 10, -1);
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 0, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_2);


        verticalLayout_7->addWidget(frame_9);

        stackedWidget_2->addWidget(page_7);

        verticalLayout_8->addWidget(stackedWidget_2);

        verticalSpacer_2 = new QSpacerItem(20, 171, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_2);


        verticalLayout_4->addWidget(frame_3);

        stackedWidgetSettTabs->addWidget(page_2);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        verticalLayout_12 = new QVBoxLayout(page_4);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        frame_5 = new QFrame(page_4);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_14 = new QVBoxLayout(frame_5);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        label_10 = new QLabel(frame_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setWordWrap(true);

        verticalLayout_14->addWidget(label_10);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, -1, 6, -1);
        frame_12 = new QFrame(frame_5);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        verticalLayout_17 = new QVBoxLayout(frame_12);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        toolButtonDataUp = new QToolButton(frame_12);
        toolButtonDataUp->setObjectName(QString::fromUtf8("toolButtonDataUp"));
        toolButtonDataUp->setMinimumSize(QSize(24, 24));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonDataUp->setIcon(icon3);

        verticalLayout_17->addWidget(toolButtonDataUp);

        toolButtonDataDown = new QToolButton(frame_12);
        toolButtonDataDown->setObjectName(QString::fromUtf8("toolButtonDataDown"));
        toolButtonDataDown->setMinimumSize(QSize(24, 24));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonDataDown->setIcon(icon4);

        verticalLayout_17->addWidget(toolButtonDataDown);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_17->addItem(verticalSpacer_5);


        horizontalLayout_5->addWidget(frame_12);

        listWidgetUsedDataSources = new QListWidget(frame_5);
        new QListWidgetItem(listWidgetUsedDataSources);
        listWidgetUsedDataSources->setObjectName(QString::fromUtf8("listWidgetUsedDataSources"));
        listWidgetUsedDataSources->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_5->addWidget(listWidgetUsedDataSources);

        frame_10 = new QFrame(frame_5);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        verticalLayout_13 = new QVBoxLayout(frame_10);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        toolButtonAddDataSource = new QToolButton(frame_10);
        toolButtonAddDataSource->setObjectName(QString::fromUtf8("toolButtonAddDataSource"));
        toolButtonAddDataSource->setMinimumSize(QSize(24, 24));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonAddDataSource->setIcon(icon5);

        verticalLayout_13->addWidget(toolButtonAddDataSource);

        toolButtonRemoveDataSource = new QToolButton(frame_10);
        toolButtonRemoveDataSource->setObjectName(QString::fromUtf8("toolButtonRemoveDataSource"));
        toolButtonRemoveDataSource->setMinimumSize(QSize(24, 24));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/forward.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonRemoveDataSource->setIcon(icon6);

        verticalLayout_13->addWidget(toolButtonRemoveDataSource);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_13->addItem(verticalSpacer_4);


        horizontalLayout_5->addWidget(frame_10);

        listWidgetExistingDataSources = new QListWidget(frame_5);
        new QListWidgetItem(listWidgetExistingDataSources);
        new QListWidgetItem(listWidgetExistingDataSources);
        new QListWidgetItem(listWidgetExistingDataSources);
        listWidgetExistingDataSources->setObjectName(QString::fromUtf8("listWidgetExistingDataSources"));
        listWidgetExistingDataSources->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_5->addWidget(listWidgetExistingDataSources);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_14->addLayout(horizontalLayout_5);


        verticalLayout_12->addWidget(frame_5);

        stackedWidgetSettTabs->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        verticalLayout_15 = new QVBoxLayout(page_5);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        frame_6 = new QFrame(page_5);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        groupBox_3 = new QGroupBox(frame_6);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_16 = new QVBoxLayout(groupBox_3);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setVerticalSpacing(2);
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        pushButtonDublicate = new QPushButton(groupBox_3);
        pushButtonDublicate->setObjectName(QString::fromUtf8("pushButtonDublicate"));
        pushButtonDublicate->setMaximumSize(QSize(30, 16777215));
        pushButtonDublicate->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255));\n"
""));

        formLayout->setWidget(0, QFormLayout::FieldRole, pushButtonDublicate);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_11);

        pushButtonIsbn = new QPushButton(groupBox_3);
        pushButtonIsbn->setObjectName(QString::fromUtf8("pushButtonIsbn"));
        pushButtonIsbn->setMaximumSize(QSize(30, 16777215));
        pushButtonIsbn->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255));\n"
""));

        formLayout->setWidget(1, QFormLayout::FieldRole, pushButtonIsbn);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_12);

        pushButtonBiblio = new QPushButton(groupBox_3);
        pushButtonBiblio->setObjectName(QString::fromUtf8("pushButtonBiblio"));
        pushButtonBiblio->setMaximumSize(QSize(30, 16777215));
        pushButtonBiblio->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255));\n"
""));

        formLayout->setWidget(2, QFormLayout::FieldRole, pushButtonBiblio);

        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_13);

        pushButtonUploaded = new QPushButton(groupBox_3);
        pushButtonUploaded->setObjectName(QString::fromUtf8("pushButtonUploaded"));
        pushButtonUploaded->setMaximumSize(QSize(30, 16777215));
        pushButtonUploaded->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255));\n"
""));

        formLayout->setWidget(3, QFormLayout::FieldRole, pushButtonUploaded);

        pushButtonCategory = new QPushButton(groupBox_3);
        pushButtonCategory->setObjectName(QString::fromUtf8("pushButtonCategory"));
        pushButtonCategory->setMaximumSize(QSize(30, 16777215));
        pushButtonCategory->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255));\n"
""));

        formLayout->setWidget(4, QFormLayout::FieldRole, pushButtonCategory);

        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_14);


        verticalLayout_16->addLayout(formLayout);


        horizontalLayout_6->addWidget(groupBox_3);


        verticalLayout_15->addWidget(frame_6);

        frame_7 = new QFrame(page_5);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_7);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        groupBox_5 = new QGroupBox(frame_7);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_19 = new QVBoxLayout(groupBox_5);
        verticalLayout_19->setObjectName(QString::fromUtf8("verticalLayout_19"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        checkBoxShowFileExtensionColumn = new QCheckBox(groupBox_5);
        checkBoxShowFileExtensionColumn->setObjectName(QString::fromUtf8("checkBoxShowFileExtensionColumn"));

        gridLayout_4->addWidget(checkBoxShowFileExtensionColumn, 1, 0, 1, 1);

        checkBoxShowTitleColumn = new QCheckBox(groupBox_5);
        checkBoxShowTitleColumn->setObjectName(QString::fromUtf8("checkBoxShowTitleColumn"));

        gridLayout_4->addWidget(checkBoxShowTitleColumn, 2, 0, 1, 1);

        checkBoxShowAuthorsColumn = new QCheckBox(groupBox_5);
        checkBoxShowAuthorsColumn->setObjectName(QString::fromUtf8("checkBoxShowAuthorsColumn"));

        gridLayout_4->addWidget(checkBoxShowAuthorsColumn, 3, 0, 1, 1);

        checkBoxShowSeriesColumn = new QCheckBox(groupBox_5);
        checkBoxShowSeriesColumn->setObjectName(QString::fromUtf8("checkBoxShowSeriesColumn"));

        gridLayout_4->addWidget(checkBoxShowSeriesColumn, 4, 0, 1, 1);

        checkBoxShowPeriodicalColumn = new QCheckBox(groupBox_5);
        checkBoxShowPeriodicalColumn->setObjectName(QString::fromUtf8("checkBoxShowPeriodicalColumn"));

        gridLayout_4->addWidget(checkBoxShowPeriodicalColumn, 5, 0, 1, 1);

        checkBoxShowFileNameColumn = new QCheckBox(groupBox_5);
        checkBoxShowFileNameColumn->setObjectName(QString::fromUtf8("checkBoxShowFileNameColumn"));

        gridLayout_4->addWidget(checkBoxShowFileNameColumn, 0, 0, 1, 1);

        checkBoxShowPublisherColumn = new QCheckBox(groupBox_5);
        checkBoxShowPublisherColumn->setObjectName(QString::fromUtf8("checkBoxShowPublisherColumn"));

        gridLayout_4->addWidget(checkBoxShowPublisherColumn, 6, 0, 1, 1);

        checkBoxShowCityColumn = new QCheckBox(groupBox_5);
        checkBoxShowCityColumn->setObjectName(QString::fromUtf8("checkBoxShowCityColumn"));

        gridLayout_4->addWidget(checkBoxShowCityColumn, 0, 1, 1, 1);

        checkBoxShowPubYearColumn = new QCheckBox(groupBox_5);
        checkBoxShowPubYearColumn->setObjectName(QString::fromUtf8("checkBoxShowPubYearColumn"));

        gridLayout_4->addWidget(checkBoxShowPubYearColumn, 1, 1, 1, 1);

        checkBoxShowIssueColumn = new QCheckBox(groupBox_5);
        checkBoxShowIssueColumn->setObjectName(QString::fromUtf8("checkBoxShowIssueColumn"));

        gridLayout_4->addWidget(checkBoxShowIssueColumn, 2, 1, 1, 1);

        checkBoxShowVolumeColumn = new QCheckBox(groupBox_5);
        checkBoxShowVolumeColumn->setObjectName(QString::fromUtf8("checkBoxShowVolumeColumn"));

        gridLayout_4->addWidget(checkBoxShowVolumeColumn, 3, 1, 1, 1);

        checkBoxShowPageNumColumn = new QCheckBox(groupBox_5);
        checkBoxShowPageNumColumn->setObjectName(QString::fromUtf8("checkBoxShowPageNumColumn"));

        gridLayout_4->addWidget(checkBoxShowPageNumColumn, 4, 1, 1, 1);

        checkBoxShowLanguageColumn = new QCheckBox(groupBox_5);
        checkBoxShowLanguageColumn->setObjectName(QString::fromUtf8("checkBoxShowLanguageColumn"));

        gridLayout_4->addWidget(checkBoxShowLanguageColumn, 5, 1, 1, 1);

        checkBoxShowUDCColumn = new QCheckBox(groupBox_5);
        checkBoxShowUDCColumn->setObjectName(QString::fromUtf8("checkBoxShowUDCColumn"));

        gridLayout_4->addWidget(checkBoxShowUDCColumn, 6, 1, 1, 1);

        checkBoxShowBBCColumn = new QCheckBox(groupBox_5);
        checkBoxShowBBCColumn->setObjectName(QString::fromUtf8("checkBoxShowBBCColumn"));

        gridLayout_4->addWidget(checkBoxShowBBCColumn, 0, 2, 1, 1);

        checkBoxShowCollectionColumn = new QCheckBox(groupBox_5);
        checkBoxShowCollectionColumn->setObjectName(QString::fromUtf8("checkBoxShowCollectionColumn"));

        gridLayout_4->addWidget(checkBoxShowCollectionColumn, 1, 2, 1, 1);

        checkBoxShowCollectionIssueColumn = new QCheckBox(groupBox_5);
        checkBoxShowCollectionIssueColumn->setObjectName(QString::fromUtf8("checkBoxShowCollectionIssueColumn"));

        gridLayout_4->addWidget(checkBoxShowCollectionIssueColumn, 2, 2, 1, 1);

        checkBoxShowScanDpiColumn = new QCheckBox(groupBox_5);
        checkBoxShowScanDpiColumn->setObjectName(QString::fromUtf8("checkBoxShowScanDpiColumn"));

        gridLayout_4->addWidget(checkBoxShowScanDpiColumn, 3, 2, 1, 1);

        checkBoxShowColorScanColumn = new QCheckBox(groupBox_5);
        checkBoxShowColorScanColumn->setObjectName(QString::fromUtf8("checkBoxShowColorScanColumn"));

        gridLayout_4->addWidget(checkBoxShowColorScanColumn, 4, 2, 1, 1);

        checkBoxShowClearScanColumn = new QCheckBox(groupBox_5);
        checkBoxShowClearScanColumn->setObjectName(QString::fromUtf8("checkBoxShowClearScanColumn"));

        gridLayout_4->addWidget(checkBoxShowClearScanColumn, 5, 2, 1, 1);


        verticalLayout_19->addLayout(gridLayout_4);


        horizontalLayout_7->addWidget(groupBox_5);


        verticalLayout_15->addWidget(frame_7);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_15->addItem(verticalSpacer_8);

        stackedWidgetSettTabs->addWidget(page_5);
        page_8 = new QWidget();
        page_8->setObjectName(QString::fromUtf8("page_8"));
        verticalLayout_20 = new QVBoxLayout(page_8);
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        groupBox_4 = new QGroupBox(page_8);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_18 = new QVBoxLayout(groupBox_4);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        checkBoxLogInspect = new QCheckBox(groupBox_4);
        checkBoxLogInspect->setObjectName(QString::fromUtf8("checkBoxLogInspect"));

        verticalLayout_18->addWidget(checkBoxLogInspect);

        checkBoxLogDublCheck = new QCheckBox(groupBox_4);
        checkBoxLogDublCheck->setObjectName(QString::fromUtf8("checkBoxLogDublCheck"));

        verticalLayout_18->addWidget(checkBoxLogDublCheck);

        checkBoxLogExtrISBN = new QCheckBox(groupBox_4);
        checkBoxLogExtrISBN->setObjectName(QString::fromUtf8("checkBoxLogExtrISBN"));

        verticalLayout_18->addWidget(checkBoxLogExtrISBN);

        checkBoxLogBibFind = new QCheckBox(groupBox_4);
        checkBoxLogBibFind->setObjectName(QString::fromUtf8("checkBoxLogBibFind"));

        verticalLayout_18->addWidget(checkBoxLogBibFind);

        checkBoxLogUpload = new QCheckBox(groupBox_4);
        checkBoxLogUpload->setObjectName(QString::fromUtf8("checkBoxLogUpload"));

        verticalLayout_18->addWidget(checkBoxLogUpload);


        verticalLayout_20->addWidget(groupBox_4);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_20->addItem(verticalSpacer_9);

        stackedWidgetSettTabs->addWidget(page_8);

        horizontalLayout->addWidget(stackedWidgetSettTabs);


        verticalLayout_2->addWidget(frame);

        frame_11 = new QFrame(guSettDialog);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setFrameShape(QFrame::StyledPanel);
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


        verticalLayout_2->addWidget(frame_11);


        retranslateUi(guSettDialog);

        stackedWidgetSettTabs->setCurrentIndex(1);
        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(guSettDialog);
    } // setupUi

    void retranslateUi(QDialog *guSettDialog)
    {
        guSettDialog->setWindowTitle(QApplication::translate("guSettDialog", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listWidgetSettGroup->isSortingEnabled();
        listWidgetSettGroup->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidgetSettGroup->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("guSettDialog", "\320\237\321\200\320\276\320\262\320\265\321\200\320\272\320\260 \320\270 \320\267\320\260\320\263\321\200\321\203\320\267\320\272\320\260", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listWidgetSettGroup->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("guSettDialog", "\320\221\320\270\320\261\320\273\320\270\320\276\320\263\321\200\320\260\321\204\320\270\321\217", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = listWidgetSettGroup->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("guSettDialog", "\320\222\320\270\320\264", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem3 = listWidgetSettGroup->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("guSettDialog", "\320\233\320\276\320\263\320\270", 0, QApplication::UnicodeUTF8));
        listWidgetSettGroup->setSortingEnabled(__sortingEnabled);

        label->setText(QApplication::translate("guSettDialog", "url \320\262\320\265\320\261 \321\201\320\265\321\200\320\262\320\270\321\201\320\260:", 0, QApplication::UnicodeUTF8));
        lineEditServiceUrl->setText(QApplication::translate("guSettDialog", "free-books.dontexist.org/lgws/", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("guSettDialog", "\320\224\320\265\320\271\321\201\321\202\320\262\320\270\321\217 \321\201 \321\204\320\260\320\271\320\273\320\260\320\274\320\270 \320\277\320\276\321\201\320\273\320\265 \320\267\320\260\320\263\321\200\321\203\320\267\320\272\320\270 \320\275\320\260 \321\201\320\265\321\200\320\262\320\265\321\200", 0, QApplication::UnicodeUTF8));
        radioButtonInLibNoAction->setText(QApplication::translate("guSettDialog", "\320\235\320\265 \321\202\321\200\320\265\320\261\321\203\321\216\321\202\321\201\321\217", 0, QApplication::UnicodeUTF8));
        radioButtonInLibRemove->setText(QApplication::translate("guSettDialog", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        radioButtonInLibMoveToRep->setText(QApplication::translate("guSettDialog", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270 \320\262 \321\200\320\265\320\277\320\276\320\267\320\270\321\202\320\276\321\200\320\270\320\271", 0, QApplication::UnicodeUTF8));
        radioButtonInLibCopyToRep->setText(QApplication::translate("guSettDialog", "\320\241\320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\262 \321\200\320\265\320\277\320\276\320\267\320\270\321\202\320\276\321\200\320\270\320\271", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("guSettDialog", "\320\237\320\260\320\277\320\272\320\270 \321\200\320\265\320\277\320\276\320\267\320\270\321\202\320\276\321\200\320\270\321\217", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("guSettDialog", "\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        toolButton_3->setText(QApplication::translate("guSettDialog", "\321\203\320\264\320\260\320\273\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("guSettDialog", "\320\237\321\203\321\202\321\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("guSettDialog", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\260\321\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("guSettDialog", "\320\232\320\276\320\275\320\265\321\207\320\275\320\260\321\217", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("guSettDialog", "host:", 0, QApplication::UnicodeUTF8));
        lineEdit_6->setText(QApplication::translate("guSettDialog", "localhost", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("guSettDialog", "port:", 0, QApplication::UnicodeUTF8));
        lineEdit_7->setText(QApplication::translate("guSettDialog", "3232", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("guSettDialog", "user:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("guSettDialog", "pass:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("guSettDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\320\224\320\276\320\261\320\260\320\262\321\214\321\202\320\265 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272\320\270 \320\262 \320\273\320\265\320\262\321\213\320\271 \321\201\320\277\320\270\321\201\320\276\320\272 \320\270 \320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\270\321\202\320\265 \320\276\321\207\320\265\321\200\320\265\320\264\320\275\320\276\321\201\321\202\321\214 \320\277\320\276\320\273\321\203\321\207\320\265\320\275\320\270\321\217 \320\261\320\270\320\261\320\273\320\270"
                        "\320\276\320\263\321\200\320\260\321\204\320\270\321\207\320\265\321\201\320\272\320\276\320\271 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\270 (\320\277\320\276\320\270\321\201\320\272 \320\276\321\201\321\203\321\211\320\265\321\201\321\202\320\262\320\273\321\217\320\265\321\202\321\201\321\217 \320\264\320\276 \320\277\320\265\321\200\320\262\320\276\320\263\320\276 \320\275\320\260\320\271\320\264\320\265\320\275\320\275\320\276\320\263\320\276)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        toolButtonDataUp->setText(QApplication::translate("guSettDialog", "...", 0, QApplication::UnicodeUTF8));
        toolButtonDataDown->setText(QApplication::translate("guSettDialog", "...", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled1 = listWidgetUsedDataSources->isSortingEnabled();
        listWidgetUsedDataSources->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem4 = listWidgetUsedDataSources->item(0);
        ___qlistwidgetitem4->setText(QApplication::translate("guSettDialog", "amazon.com", 0, QApplication::UnicodeUTF8));
        listWidgetUsedDataSources->setSortingEnabled(__sortingEnabled1);

        toolButtonAddDataSource->setText(QApplication::translate("guSettDialog", "...", 0, QApplication::UnicodeUTF8));
        toolButtonRemoveDataSource->setText(QApplication::translate("guSettDialog", "...", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled2 = listWidgetExistingDataSources->isSortingEnabled();
        listWidgetExistingDataSources->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem5 = listWidgetExistingDataSources->item(0);
        ___qlistwidgetitem5->setText(QApplication::translate("guSettDialog", "ozon.ru", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem6 = listWidgetExistingDataSources->item(1);
        ___qlistwidgetitem6->setText(QApplication::translate("guSettDialog", "isbndb.com", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem7 = listWidgetExistingDataSources->item(2);
        ___qlistwidgetitem7->setText(QApplication::translate("guSettDialog", "rsl.ru", 0, QApplication::UnicodeUTF8));
        listWidgetExistingDataSources->setSortingEnabled(__sortingEnabled2);

        groupBox_3->setTitle(QApplication::translate("guSettDialog", "\320\246\320\262\320\265\321\202\320\260 \320\270\320\275\320\264\320\270\320\272\320\260\321\206\320\270\320\270:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("guSettDialog", "\320\235\320\260 \321\201\320\265\321\200\320\262\320\265\321\200\320\265:", 0, QApplication::UnicodeUTF8));
        pushButtonDublicate->setText(QString());
        label_11->setText(QApplication::translate("guSettDialog", "\320\225\321\201\321\202\321\214 ISBN:", 0, QApplication::UnicodeUTF8));
        pushButtonIsbn->setText(QString());
        label_12->setText(QApplication::translate("guSettDialog", "\320\225\321\201\321\202\321\214 \320\261\320\270\320\261\320\273\320\270\320\276\320\263\321\200\320\260\321\204\320\270\321\217:", 0, QApplication::UnicodeUTF8));
        pushButtonBiblio->setText(QString());
        label_13->setText(QApplication::translate("guSettDialog", "\320\227\320\260\320\263\321\200\321\203\320\266\320\265\320\275 \320\275\320\260 \321\201\320\265\321\200\320\262\320\265\321\200:", 0, QApplication::UnicodeUTF8));
        pushButtonUploaded->setText(QString());
        pushButtonCategory->setText(QString());
        label_14->setText(QApplication::translate("guSettDialog", "\320\222\321\213\320\261\321\200\320\260\320\275\320\275\320\260\321\217 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217:", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("guSettDialog", "\320\237\320\276\320\273\321\217, \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\260\320\265\320\274\321\213\320\265 \320\262 \321\201\320\277\320\270\321\201\320\272\320\265 \320\272\320\275\320\270\320\263:", 0, QApplication::UnicodeUTF8));
        checkBoxShowFileExtensionColumn->setText(QApplication::translate("guSettDialog", "\320\240\320\260\321\201\321\210\320\270\321\200\320\265\320\275\320\270\320\265 \321\204\320\260\320\271\320\273\320\260", 0, QApplication::UnicodeUTF8));
        checkBoxShowTitleColumn->setText(QApplication::translate("guSettDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        checkBoxShowAuthorsColumn->setText(QApplication::translate("guSettDialog", "\320\220\320\262\321\202\320\276\321\200\321\213", 0, QApplication::UnicodeUTF8));
        checkBoxShowSeriesColumn->setText(QApplication::translate("guSettDialog", "\320\241\320\265\321\200\320\270\321\217", 0, QApplication::UnicodeUTF8));
        checkBoxShowPeriodicalColumn->setText(QApplication::translate("guSettDialog", "\320\226\321\203\321\200\320\275\320\260\320\273", 0, QApplication::UnicodeUTF8));
        checkBoxShowFileNameColumn->setText(QApplication::translate("guSettDialog", "\320\230\320\274\321\217 \321\204\320\260\320\271\320\273\320\260", 0, QApplication::UnicodeUTF8));
        checkBoxShowPublisherColumn->setText(QApplication::translate("guSettDialog", "\320\230\320\267\320\264\320\260\321\202\320\265\320\273\321\214\321\201\321\202\320\262\320\276", 0, QApplication::UnicodeUTF8));
        checkBoxShowCityColumn->setText(QApplication::translate("guSettDialog", "\320\223\320\276\321\200\320\276\320\264", 0, QApplication::UnicodeUTF8));
        checkBoxShowPubYearColumn->setText(QApplication::translate("guSettDialog", "\320\223\320\276\320\264 \320\270\320\267\320\264\320\260\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        checkBoxShowIssueColumn->setText(QApplication::translate("guSettDialog", "\320\230\320\267\320\264\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        checkBoxShowVolumeColumn->setText(QApplication::translate("guSettDialog", "\320\242\320\276\320\274", 0, QApplication::UnicodeUTF8));
        checkBoxShowPageNumColumn->setText(QApplication::translate("guSettDialog", "\320\232\320\276\320\273-\320\262\320\276 \321\201\321\202\321\200\320\260\320\275\320\270\321\206", 0, QApplication::UnicodeUTF8));
        checkBoxShowLanguageColumn->setText(QApplication::translate("guSettDialog", "\320\257\320\267\321\213\320\272", 0, QApplication::UnicodeUTF8));
        checkBoxShowUDCColumn->setText(QApplication::translate("guSettDialog", "\320\243\320\224\320\232", 0, QApplication::UnicodeUTF8));
        checkBoxShowBBCColumn->setText(QApplication::translate("guSettDialog", "\320\221\320\221\320\232", 0, QApplication::UnicodeUTF8));
        checkBoxShowCollectionColumn->setText(QApplication::translate("guSettDialog", "\320\221\320\270\320\261\320\273\320\270\320\276\321\202\320\265\320\272\320\260", 0, QApplication::UnicodeUTF8));
        checkBoxShowCollectionIssueColumn->setText(QApplication::translate("guSettDialog", "\320\230\320\267\320\264\320\260\320\275\320\270\320\265 \320\261\320\270\320\261\320\273\320\270\320\276\321\202\320\265\320\272\320\270", 0, QApplication::UnicodeUTF8));
        checkBoxShowScanDpiColumn->setText(QApplication::translate("guSettDialog", "\320\240\320\260\320\267\321\200\320\265\321\210\320\265\320\275\320\270\320\265 \321\201\320\272\320\260\320\275\320\260", 0, QApplication::UnicodeUTF8));
        checkBoxShowColorScanColumn->setText(QApplication::translate("guSettDialog", "\320\246\320\262\320\265\321\202\320\275\320\276\320\271 \321\201\320\272\320\260\320\275", 0, QApplication::UnicodeUTF8));
        checkBoxShowClearScanColumn->setText(QApplication::translate("guSettDialog", "\320\236\321\207\320\270\321\211\320\265\320\275\320\275\321\213\320\271 \321\201\320\272\320\260\320\275", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("guSettDialog", "\320\222\320\265\321\201\321\202\320\270 \320\273\320\276\320\263\320\270:", 0, QApplication::UnicodeUTF8));
        checkBoxLogInspect->setText(QApplication::translate("guSettDialog", "\320\230\320\275\321\201\320\277\320\265\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217 \320\277\320\260\320\277\320\272\320\270", 0, QApplication::UnicodeUTF8));
        checkBoxLogDublCheck->setText(QApplication::translate("guSettDialog", "\320\227\320\260\320\277\321\200\320\276\321\201\320\276\320\262 \320\275\320\260 \321\201\320\265\321\200\320\262\320\265\321\200 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\270 \320\277\320\276 md5", 0, QApplication::UnicodeUTF8));
        checkBoxLogExtrISBN->setText(QApplication::translate("guSettDialog", "\320\230\320\267\320\262\320\273\320\265\321\207\320\265\320\275\320\270\321\217 ISBN", 0, QApplication::UnicodeUTF8));
        checkBoxLogBibFind->setText(QApplication::translate("guSettDialog", "\320\237\320\276\320\270\321\201\320\272\320\260 \320\261\320\270\320\261\320\273\320\270\320\276\320\263\321\200\320\260\321\204\320\270\321\207\320\265\321\201\320\272\320\276\320\271 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
        checkBoxLogUpload->setText(QApplication::translate("guSettDialog", "\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\270 \320\275\320\260 \321\201\320\265\321\200\320\262\320\265\321\200", 0, QApplication::UnicodeUTF8));
        pushButtonSet->setText(QApplication::translate("guSettDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButtonExit->setText(QApplication::translate("guSettDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class guSettDialog: public Ui_guSettDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUSETTDIALOG_H
