/********************************************************************************
** Form generated from reading UI file 'datawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAWINDOW_H
#define UI_DATAWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataWindow
{
public:
    QAction *actionset;
    QAction *actionabout;
    QAction *actionadd;
    QAction *actionminus;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_7;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *statusChoose;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *allRadioButton;
    QRadioButton *goodRadioButton;
    QRadioButton *defectRadioButton;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_2;
    QComboBox *pidComboBox;
    QLabel *label;
    QLabel *productName;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *detectedImageLineEdit;
    QPushButton *detectedImageChoser;
    QPushButton *detectImagePlusViewButton;
    QLineEdit *sidLineEdit;
    QLabel *sidLabel;
    QPushButton *statusPushButton;
    QLabel *statusLabel;
    QLabel *imageNameLabel;
    QLabel *label_5;
    QLineEdit *productNameLineEdit;
    QLabel *pidLabel;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *imageLineEdit;
    QPushButton *imageChoser;
    QPushButton *imagePlusViewButton;
    QDateTimeEdit *stuffProductTime;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *dataGridLayout;
    QTabWidget *tabWidget;
    QWidget *formTab;
    QHBoxLayout *horizontalLayout_6;
    QTableView *tableView;
    QWidget *chartTab;
    QHBoxLayout *horizontalLayout_12;
    QGridLayout *produceGridLayout;
    QStackedWidget *stackedWidget_2;
    QWidget *page_13;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QDateTimeEdit *currentTimeEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *dateLabel;
    QDateTimeEdit *startDateTimeEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QDateTimeEdit *endDateTimeEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QComboBox *comboBox;
    QWidget *page_14;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_6;
    QComboBox *comboBox_2;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_7;
    QDateEdit *dateEdit;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QMenu *menuEdit;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DataWindow)
    {
        if (DataWindow->objectName().isEmpty())
            DataWindow->setObjectName(QStringLiteral("DataWindow"));
        DataWindow->resize(806, 814);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/action/window.png"), QSize(), QIcon::Normal, QIcon::Off);
        DataWindow->setWindowIcon(icon);
        actionset = new QAction(DataWindow);
        actionset->setObjectName(QStringLiteral("actionset"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/action/tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionset->setIcon(icon1);
        actionabout = new QAction(DataWindow);
        actionabout->setObjectName(QStringLiteral("actionabout"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/action/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionabout->setIcon(icon2);
        actionadd = new QAction(DataWindow);
        actionadd->setObjectName(QStringLiteral("actionadd"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/action/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionadd->setIcon(icon3);
        actionminus = new QAction(DataWindow);
        actionminus->setObjectName(QStringLiteral("actionminus"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/action/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionminus->setIcon(icon4);
        centralWidget = new QWidget(DataWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_7 = new QVBoxLayout(centralWidget);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setMinimumSize(QSize(350, 0));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(page->sizePolicy().hasHeightForWidth());
        page->setSizePolicy(sizePolicy1);
        layoutWidget = new QWidget(page);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 352, 501));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        statusChoose = new QGroupBox(layoutWidget);
        statusChoose->setObjectName(QStringLiteral("statusChoose"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(statusChoose->sizePolicy().hasHeightForWidth());
        statusChoose->setSizePolicy(sizePolicy2);
        horizontalLayout_7 = new QHBoxLayout(statusChoose);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        allRadioButton = new QRadioButton(statusChoose);
        allRadioButton->setObjectName(QStringLiteral("allRadioButton"));
        allRadioButton->setChecked(true);

        horizontalLayout_7->addWidget(allRadioButton);

        goodRadioButton = new QRadioButton(statusChoose);
        goodRadioButton->setObjectName(QStringLiteral("goodRadioButton"));

        horizontalLayout_7->addWidget(goodRadioButton);

        defectRadioButton = new QRadioButton(statusChoose);
        defectRadioButton->setObjectName(QStringLiteral("defectRadioButton"));

        horizontalLayout_7->addWidget(defectRadioButton);


        verticalLayout_3->addWidget(statusChoose);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(350, 0));
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pidComboBox = new QComboBox(groupBox_2);
        pidComboBox->setObjectName(QStringLiteral("pidComboBox"));

        gridLayout_2->addWidget(pidComboBox, 3, 1, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 5, 0, 1, 1);

        productName = new QLabel(groupBox_2);
        productName->setObjectName(QStringLiteral("productName"));

        gridLayout_2->addWidget(productName, 4, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        detectedImageLineEdit = new QLineEdit(groupBox_2);
        detectedImageLineEdit->setObjectName(QStringLiteral("detectedImageLineEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(100);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(detectedImageLineEdit->sizePolicy().hasHeightForWidth());
        detectedImageLineEdit->setSizePolicy(sizePolicy3);

        horizontalLayout_8->addWidget(detectedImageLineEdit);

        detectedImageChoser = new QPushButton(groupBox_2);
        detectedImageChoser->setObjectName(QStringLiteral("detectedImageChoser"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(10);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(detectedImageChoser->sizePolicy().hasHeightForWidth());
        detectedImageChoser->setSizePolicy(sizePolicy4);
        detectedImageChoser->setMinimumSize(QSize(10, 0));

        horizontalLayout_8->addWidget(detectedImageChoser);

        detectImagePlusViewButton = new QPushButton(groupBox_2);
        detectImagePlusViewButton->setObjectName(QStringLiteral("detectImagePlusViewButton"));
        sizePolicy4.setHeightForWidth(detectImagePlusViewButton->sizePolicy().hasHeightForWidth());
        detectImagePlusViewButton->setSizePolicy(sizePolicy4);
        detectImagePlusViewButton->setMinimumSize(QSize(10, 0));

        horizontalLayout_8->addWidget(detectImagePlusViewButton);


        gridLayout_2->addLayout(horizontalLayout_8, 1, 1, 1, 1);

        sidLineEdit = new QLineEdit(groupBox_2);
        sidLineEdit->setObjectName(QStringLiteral("sidLineEdit"));

        gridLayout_2->addWidget(sidLineEdit, 2, 1, 1, 1);

        sidLabel = new QLabel(groupBox_2);
        sidLabel->setObjectName(QStringLiteral("sidLabel"));

        gridLayout_2->addWidget(sidLabel, 2, 0, 1, 1);

        statusPushButton = new QPushButton(groupBox_2);
        statusPushButton->setObjectName(QStringLiteral("statusPushButton"));

        gridLayout_2->addWidget(statusPushButton, 6, 1, 1, 1);

        statusLabel = new QLabel(groupBox_2);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));

        gridLayout_2->addWidget(statusLabel, 6, 0, 1, 1);

        imageNameLabel = new QLabel(groupBox_2);
        imageNameLabel->setObjectName(QStringLiteral("imageNameLabel"));

        gridLayout_2->addWidget(imageNameLabel, 0, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        productNameLineEdit = new QLineEdit(groupBox_2);
        productNameLineEdit->setObjectName(QStringLiteral("productNameLineEdit"));

        gridLayout_2->addWidget(productNameLineEdit, 4, 1, 1, 1);

        pidLabel = new QLabel(groupBox_2);
        pidLabel->setObjectName(QStringLiteral("pidLabel"));

        gridLayout_2->addWidget(pidLabel, 3, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        imageLineEdit = new QLineEdit(groupBox_2);
        imageLineEdit->setObjectName(QStringLiteral("imageLineEdit"));
        sizePolicy3.setHeightForWidth(imageLineEdit->sizePolicy().hasHeightForWidth());
        imageLineEdit->setSizePolicy(sizePolicy3);

        horizontalLayout_10->addWidget(imageLineEdit);

        imageChoser = new QPushButton(groupBox_2);
        imageChoser->setObjectName(QStringLiteral("imageChoser"));
        sizePolicy4.setHeightForWidth(imageChoser->sizePolicy().hasHeightForWidth());
        imageChoser->setSizePolicy(sizePolicy4);
        imageChoser->setMinimumSize(QSize(10, 0));

        horizontalLayout_10->addWidget(imageChoser);

        imagePlusViewButton = new QPushButton(groupBox_2);
        imagePlusViewButton->setObjectName(QStringLiteral("imagePlusViewButton"));
        sizePolicy4.setHeightForWidth(imagePlusViewButton->sizePolicy().hasHeightForWidth());
        imagePlusViewButton->setSizePolicy(sizePolicy4);
        imagePlusViewButton->setMinimumSize(QSize(10, 0));

        horizontalLayout_10->addWidget(imagePlusViewButton);


        gridLayout_2->addLayout(horizontalLayout_10, 0, 1, 1, 1);

        stuffProductTime = new QDateTimeEdit(groupBox_2);
        stuffProductTime->setObjectName(QStringLiteral("stuffProductTime"));

        gridLayout_2->addWidget(stuffProductTime, 5, 1, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_9->addWidget(pushButton);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_9->addWidget(pushButton_2);


        gridLayout_2->addLayout(horizontalLayout_9, 7, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_2);


        verticalLayout_3->addWidget(groupBox_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout_2 = new QVBoxLayout(page_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        dataGridLayout = new QGridLayout();
        dataGridLayout->setSpacing(6);
        dataGridLayout->setObjectName(QStringLiteral("dataGridLayout"));

        verticalLayout_2->addLayout(dataGridLayout);

        stackedWidget->addWidget(page_2);

        gridLayout->addWidget(stackedWidget, 1, 1, 2, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy5);
        formTab = new QWidget();
        formTab->setObjectName(QStringLiteral("formTab"));
        horizontalLayout_6 = new QHBoxLayout(formTab);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        tableView = new QTableView(formTab);
        tableView->setObjectName(QStringLiteral("tableView"));
        sizePolicy5.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy5);

        horizontalLayout_6->addWidget(tableView);

        tabWidget->addTab(formTab, QString());
        chartTab = new QWidget();
        chartTab->setObjectName(QStringLiteral("chartTab"));
        horizontalLayout_12 = new QHBoxLayout(chartTab);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        produceGridLayout = new QGridLayout();
        produceGridLayout->setSpacing(6);
        produceGridLayout->setObjectName(QStringLiteral("produceGridLayout"));

        horizontalLayout_12->addLayout(produceGridLayout);

        tabWidget->addTab(chartTab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 3, 1);

        stackedWidget_2 = new QStackedWidget(centralWidget);
        stackedWidget_2->setObjectName(QStringLiteral("stackedWidget_2"));
        sizePolicy2.setHeightForWidth(stackedWidget_2->sizePolicy().hasHeightForWidth());
        stackedWidget_2->setSizePolicy(sizePolicy2);
        page_13 = new QWidget();
        page_13->setObjectName(QStringLiteral("page_13"));
        verticalLayout_8 = new QVBoxLayout(page_13);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        groupBox = new QGroupBox(page_13);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        groupBox->setMinimumSize(QSize(350, 175));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(11, 30, 331, 128));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        currentTimeEdit = new QDateTimeEdit(layoutWidget1);
        currentTimeEdit->setObjectName(QStringLiteral("currentTimeEdit"));
        currentTimeEdit->setLayoutDirection(Qt::LeftToRight);
        currentTimeEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        currentTimeEdit->setReadOnly(true);
        currentTimeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        currentTimeEdit->setCurrentSection(QDateTimeEdit::YearSection);
        currentTimeEdit->setCalendarPopup(false);

        horizontalLayout_5->addWidget(currentTimeEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        dateLabel = new QLabel(layoutWidget1);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));

        horizontalLayout_2->addWidget(dateLabel);

        startDateTimeEdit = new QDateTimeEdit(layoutWidget1);
        startDateTimeEdit->setObjectName(QStringLiteral("startDateTimeEdit"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(startDateTimeEdit->sizePolicy().hasHeightForWidth());
        startDateTimeEdit->setSizePolicy(sizePolicy6);
        startDateTimeEdit->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        startDateTimeEdit->setCurrentSection(QDateTimeEdit::YearSection);
        startDateTimeEdit->setCalendarPopup(true);

        horizontalLayout_2->addWidget(startDateTimeEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        endDateTimeEdit = new QDateTimeEdit(layoutWidget1);
        endDateTimeEdit->setObjectName(QStringLiteral("endDateTimeEdit"));
        sizePolicy6.setHeightForWidth(endDateTimeEdit->sizePolicy().hasHeightForWidth());
        endDateTimeEdit->setSizePolicy(sizePolicy6);
        endDateTimeEdit->setCurrentSection(QDateTimeEdit::YearSection);
        endDateTimeEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(endDateTimeEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        comboBox = new QComboBox(layoutWidget1);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        sizePolicy6.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy6);

        horizontalLayout_4->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_3->addLayout(verticalLayout);


        verticalLayout_8->addWidget(groupBox);

        stackedWidget_2->addWidget(page_13);
        page_14 = new QWidget();
        page_14->setObjectName(QStringLiteral("page_14"));
        verticalLayout_4 = new QVBoxLayout(page_14);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox_3 = new QGroupBox(page_14);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_9 = new QVBoxLayout(groupBox_3);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy7);

        horizontalLayout_11->addWidget(label_6);

        comboBox_2 = new QComboBox(groupBox_3);
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        horizontalLayout_11->addWidget(comboBox_2);


        verticalLayout_6->addLayout(horizontalLayout_11);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy7.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy7);

        horizontalLayout_13->addWidget(label_7);

        dateEdit = new QDateEdit(groupBox_3);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setCalendarPopup(true);

        horizontalLayout_13->addWidget(dateEdit);

        pushButton_3 = new QPushButton(groupBox_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_13->addWidget(pushButton_3);


        verticalLayout_6->addLayout(horizontalLayout_13);


        verticalLayout_9->addLayout(verticalLayout_6);


        verticalLayout_4->addWidget(groupBox_3);

        stackedWidget_2->addWidget(page_14);

        gridLayout->addWidget(stackedWidget_2, 0, 1, 1, 1);


        verticalLayout_7->addLayout(gridLayout);

        DataWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DataWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 806, 24));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        DataWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DataWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DataWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DataWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DataWindow->setStatusBar(statusBar);

        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuEdit->addAction(actionadd);
        menuEdit->addAction(actionminus);
        menuEdit->addAction(actionset);
        menuAbout->addAction(actionabout);
        mainToolBar->addAction(actionadd);
        mainToolBar->addAction(actionminus);
        mainToolBar->addAction(actionset);
        mainToolBar->addAction(actionabout);

        retranslateUi(DataWindow);

        stackedWidget->setCurrentIndex(1);
        tabWidget->setCurrentIndex(1);
        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DataWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DataWindow)
    {
        DataWindow->setWindowTitle(QApplication::translate("DataWindow", "\347\224\237\347\224\242\346\225\270\346\223\232", nullptr));
        actionset->setText(QApplication::translate("DataWindow", "\350\250\255\345\256\232", nullptr));
        actionabout->setText(QApplication::translate("DataWindow", "about", nullptr));
        actionadd->setText(QApplication::translate("DataWindow", "\346\226\260\345\242\236\346\225\270\346\223\232", nullptr));
        actionminus->setText(QApplication::translate("DataWindow", "\345\210\252\351\231\244\346\225\270\346\223\232", nullptr));
        statusChoose->setTitle(QApplication::translate("DataWindow", "\347\213\200\346\205\213", nullptr));
        allRadioButton->setText(QApplication::translate("DataWindow", "All", nullptr));
        goodRadioButton->setText(QApplication::translate("DataWindow", "Good", nullptr));
        defectRadioButton->setText(QApplication::translate("DataWindow", "Defect", nullptr));
        groupBox_2->setTitle(QApplication::translate("DataWindow", "\347\224\237\347\224\242\346\225\270\346\223\232", nullptr));
        label->setText(QApplication::translate("DataWindow", "\347\224\237\347\224\242\346\231\202\351\226\223:", nullptr));
        productName->setText(QApplication::translate("DataWindow", "\347\224\242\345\223\201\345\220\215\347\250\261:", nullptr));
        detectedImageChoser->setText(QApplication::translate("DataWindow", "...", nullptr));
        detectImagePlusViewButton->setText(QApplication::translate("DataWindow", "+", nullptr));
        sidLabel->setText(QApplication::translate("DataWindow", "SID:", nullptr));
        statusPushButton->setText(QString());
        statusLabel->setText(QApplication::translate("DataWindow", "\347\213\200\346\205\213:", nullptr));
        imageNameLabel->setText(QApplication::translate("DataWindow", "\345\234\226\347\211\207:", nullptr));
        label_5->setText(QApplication::translate("DataWindow", "\350\276\250\350\255\230\345\234\226\347\211\207:", nullptr));
        pidLabel->setText(QApplication::translate("DataWindow", "PID:", nullptr));
        imageChoser->setText(QApplication::translate("DataWindow", "...", nullptr));
        imagePlusViewButton->setText(QApplication::translate("DataWindow", "+", nullptr));
        stuffProductTime->setDisplayFormat(QApplication::translate("DataWindow", "yyyy/M/d hh:mm:ss.zzz", nullptr));
        pushButton->setText(QApplication::translate("DataWindow", "\347\242\272\345\256\232", nullptr));
        pushButton_2->setText(QApplication::translate("DataWindow", "\345\217\226\346\266\210", nullptr));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tabWidget->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        tabWidget->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        tabWidget->setTabText(tabWidget->indexOf(formTab), QApplication::translate("DataWindow", "\346\225\270\346\223\232\350\241\250\345\226\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(chartTab), QApplication::translate("DataWindow", "\346\225\270\346\223\232\345\234\226", nullptr));
        groupBox->setTitle(QApplication::translate("DataWindow", "\347\257\204\345\234\215\350\250\255\345\256\232", nullptr));
        label_4->setText(QApplication::translate("DataWindow", "<html><head/><body><p>\347\217\276\345\234\250\346\231\202\351\226\223:</p></body></html>", nullptr));
        currentTimeEdit->setDisplayFormat(QApplication::translate("DataWindow", "yyyy/M/d hh:mm:ss", nullptr));
        dateLabel->setText(QApplication::translate("DataWindow", "\351\226\213\345\247\213\346\231\202\351\226\223:", nullptr));
        startDateTimeEdit->setDisplayFormat(QApplication::translate("DataWindow", "yyyy/M/d hh:mm:ss", nullptr));
        label_2->setText(QApplication::translate("DataWindow", "\347\265\220\346\235\237\346\231\202\351\226\223:", nullptr));
        endDateTimeEdit->setDisplayFormat(QApplication::translate("DataWindow", "yyyy/M/d hh:mm:ss", nullptr));
        label_3->setText(QApplication::translate("DataWindow", "\347\224\242\345\223\201:", nullptr));
        groupBox_3->setTitle(QApplication::translate("DataWindow", "\346\225\270\346\223\232\345\234\226\350\241\250", nullptr));
        label_6->setText(QApplication::translate("DataWindow", "\351\201\270\351\240\205:", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("DataWindow", "\347\225\266\346\227\245\346\225\270\346\223\232", nullptr));

        label_7->setText(QApplication::translate("DataWindow", "\346\227\245\346\234\237:", nullptr));
        pushButton_3->setText(QApplication::translate("DataWindow", "Refresh", nullptr));
        menuEdit->setTitle(QApplication::translate("DataWindow", "\347\267\250\350\274\257", nullptr));
        menuAbout->setTitle(QApplication::translate("DataWindow", "\351\227\234\346\226\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataWindow: public Ui_DataWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAWINDOW_H
