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
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *formTab;
    QHBoxLayout *horizontalLayout_6;
    QTableView *tableView;
    QWidget *chartTab;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
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
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *statusChoose;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *allRadioButton;
    QRadioButton *goodRadioButton;
    QRadioButton *defectRadioButton;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_2;
    QLabel *productName;
    QLineEdit *productNameLineEdit;
    QPushButton *statusPushButton;
    QLabel *label;
    QLineEdit *sidLineEdit;
    QLabel *pictureView;
    QLabel *imageNameLabel;
    QComboBox *pidComboBox;
    QDateTimeEdit *stuffProductTime;
    QLabel *pidLabel;
    QLabel *sidLabel;
    QLabel *statusLabel;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *imageLineEdit;
    QPushButton *imageChoser;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *page_2;
    QMenuBar *menuBar;
    QMenu *menuEdit;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DataWindow)
    {
        if (DataWindow->objectName().isEmpty())
            DataWindow->setObjectName(QStringLiteral("DataWindow"));
        DataWindow->resize(760, 814);
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
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        formTab = new QWidget();
        formTab->setObjectName(QStringLiteral("formTab"));
        horizontalLayout_6 = new QHBoxLayout(formTab);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        tableView = new QTableView(formTab);
        tableView->setObjectName(QStringLiteral("tableView"));
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(tableView);

        tabWidget->addTab(formTab, QString());
        chartTab = new QWidget();
        chartTab->setObjectName(QStringLiteral("chartTab"));
        tabWidget->addTab(chartTab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 3, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(350, 175));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 30, 331, 128));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
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
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        currentTimeEdit = new QDateTimeEdit(layoutWidget);
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
        dateLabel = new QLabel(layoutWidget);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));

        horizontalLayout_2->addWidget(dateLabel);

        startDateTimeEdit = new QDateTimeEdit(layoutWidget);
        startDateTimeEdit->setObjectName(QStringLiteral("startDateTimeEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(startDateTimeEdit->sizePolicy().hasHeightForWidth());
        startDateTimeEdit->setSizePolicy(sizePolicy2);
        startDateTimeEdit->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        startDateTimeEdit->setCurrentSection(QDateTimeEdit::YearSection);
        startDateTimeEdit->setCalendarPopup(true);

        horizontalLayout_2->addWidget(startDateTimeEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        endDateTimeEdit = new QDateTimeEdit(layoutWidget);
        endDateTimeEdit->setObjectName(QStringLiteral("endDateTimeEdit"));
        sizePolicy2.setHeightForWidth(endDateTimeEdit->sizePolicy().hasHeightForWidth());
        endDateTimeEdit->setSizePolicy(sizePolicy2);
        endDateTimeEdit->setCurrentSection(QDateTimeEdit::YearSection);
        endDateTimeEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(endDateTimeEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        sizePolicy2.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_3->addLayout(verticalLayout);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy3);
        stackedWidget->setMinimumSize(QSize(350, 0));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(page->sizePolicy().hasHeightForWidth());
        page->setSizePolicy(sizePolicy4);
        verticalLayout_4 = new QVBoxLayout(page);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        statusChoose = new QGroupBox(page);
        statusChoose->setObjectName(QStringLiteral("statusChoose"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(statusChoose->sizePolicy().hasHeightForWidth());
        statusChoose->setSizePolicy(sizePolicy5);
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

        groupBox_2 = new QGroupBox(page);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy6);
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        productName = new QLabel(groupBox_2);
        productName->setObjectName(QStringLiteral("productName"));

        gridLayout_2->addWidget(productName, 6, 0, 1, 1);

        productNameLineEdit = new QLineEdit(groupBox_2);
        productNameLineEdit->setObjectName(QStringLiteral("productNameLineEdit"));

        gridLayout_2->addWidget(productNameLineEdit, 6, 1, 1, 1);

        statusPushButton = new QPushButton(groupBox_2);
        statusPushButton->setObjectName(QStringLiteral("statusPushButton"));

        gridLayout_2->addWidget(statusPushButton, 8, 1, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 7, 0, 1, 1);

        sidLineEdit = new QLineEdit(groupBox_2);
        sidLineEdit->setObjectName(QStringLiteral("sidLineEdit"));

        gridLayout_2->addWidget(sidLineEdit, 4, 1, 1, 1);

        pictureView = new QLabel(groupBox_2);
        pictureView->setObjectName(QStringLiteral("pictureView"));
        sizePolicy.setHeightForWidth(pictureView->sizePolicy().hasHeightForWidth());
        pictureView->setSizePolicy(sizePolicy);
        pictureView->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(pictureView, 0, 0, 1, 2);

        imageNameLabel = new QLabel(groupBox_2);
        imageNameLabel->setObjectName(QStringLiteral("imageNameLabel"));

        gridLayout_2->addWidget(imageNameLabel, 1, 0, 1, 1);

        pidComboBox = new QComboBox(groupBox_2);
        pidComboBox->setObjectName(QStringLiteral("pidComboBox"));

        gridLayout_2->addWidget(pidComboBox, 5, 1, 1, 1);

        stuffProductTime = new QDateTimeEdit(groupBox_2);
        stuffProductTime->setObjectName(QStringLiteral("stuffProductTime"));

        gridLayout_2->addWidget(stuffProductTime, 7, 1, 1, 1);

        pidLabel = new QLabel(groupBox_2);
        pidLabel->setObjectName(QStringLiteral("pidLabel"));

        gridLayout_2->addWidget(pidLabel, 5, 0, 1, 1);

        sidLabel = new QLabel(groupBox_2);
        sidLabel->setObjectName(QStringLiteral("sidLabel"));

        gridLayout_2->addWidget(sidLabel, 4, 0, 1, 1);

        statusLabel = new QLabel(groupBox_2);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));

        gridLayout_2->addWidget(statusLabel, 8, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        imageLineEdit = new QLineEdit(groupBox_2);
        imageLineEdit->setObjectName(QStringLiteral("imageLineEdit"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(100);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(imageLineEdit->sizePolicy().hasHeightForWidth());
        imageLineEdit->setSizePolicy(sizePolicy7);

        horizontalLayout_10->addWidget(imageLineEdit);

        imageChoser = new QPushButton(groupBox_2);
        imageChoser->setObjectName(QStringLiteral("imageChoser"));
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(10);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(imageChoser->sizePolicy().hasHeightForWidth());
        imageChoser->setSizePolicy(sizePolicy8);
        imageChoser->setMinimumSize(QSize(10, 0));

        horizontalLayout_10->addWidget(imageChoser);


        gridLayout_2->addLayout(horizontalLayout_10, 1, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_9->addWidget(pushButton);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_9->addWidget(pushButton_2);


        verticalLayout_5->addLayout(horizontalLayout_9);


        verticalLayout_3->addWidget(groupBox_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);

        gridLayout->addWidget(stackedWidget, 1, 1, 2, 1);


        verticalLayout_2->addLayout(gridLayout);

        DataWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DataWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 760, 24));
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

        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DataWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DataWindow)
    {
        DataWindow->setWindowTitle(QApplication::translate("DataWindow", "\347\224\237\347\224\242\346\225\270\346\223\232", nullptr));
        actionset->setText(QApplication::translate("DataWindow", "\350\250\255\345\256\232", nullptr));
        actionabout->setText(QApplication::translate("DataWindow", "about", nullptr));
        actionadd->setText(QApplication::translate("DataWindow", "\346\226\260\345\242\236\346\225\270\346\223\232", nullptr));
        actionminus->setText(QApplication::translate("DataWindow", "\345\210\252\351\231\244\346\225\270\346\223\232", nullptr));
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
        statusChoose->setTitle(QApplication::translate("DataWindow", "\347\213\200\346\205\213", nullptr));
        allRadioButton->setText(QApplication::translate("DataWindow", "All", nullptr));
        goodRadioButton->setText(QApplication::translate("DataWindow", "Good", nullptr));
        defectRadioButton->setText(QApplication::translate("DataWindow", "Defect", nullptr));
        groupBox_2->setTitle(QApplication::translate("DataWindow", "\347\224\237\347\224\242\346\225\270\346\223\232", nullptr));
        productName->setText(QApplication::translate("DataWindow", "\347\224\242\345\223\201\345\220\215\347\250\261:", nullptr));
        statusPushButton->setText(QString());
        label->setText(QApplication::translate("DataWindow", "\347\224\237\347\224\242\346\231\202\351\226\223:", nullptr));
        pictureView->setText(QString());
        imageNameLabel->setText(QApplication::translate("DataWindow", "\345\234\226\347\211\207:", nullptr));
        stuffProductTime->setDisplayFormat(QApplication::translate("DataWindow", "yyyy/M/d hh:mm:ss.zzz", nullptr));
        pidLabel->setText(QApplication::translate("DataWindow", "PID:", nullptr));
        sidLabel->setText(QApplication::translate("DataWindow", "SID:", nullptr));
        statusLabel->setText(QApplication::translate("DataWindow", "\347\213\200\346\205\213:", nullptr));
        imageChoser->setText(QApplication::translate("DataWindow", "...", nullptr));
        pushButton->setText(QApplication::translate("DataWindow", "Submit", nullptr));
        pushButton_2->setText(QApplication::translate("DataWindow", "Cancel", nullptr));
        menuEdit->setTitle(QApplication::translate("DataWindow", "\347\267\250\350\274\257", nullptr));
        menuAbout->setTitle(QApplication::translate("DataWindow", "\351\227\234\346\226\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataWindow: public Ui_DataWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAWINDOW_H
