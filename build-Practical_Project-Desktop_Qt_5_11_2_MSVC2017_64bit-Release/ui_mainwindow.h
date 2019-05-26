/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *homePage;
    QHBoxLayout *horizontalLayout;
    QPushButton *testingPushButton;
    QPushButton *trainningPushButton;
    QWidget *testingPage;
    QTableWidget *tableWidget;
    QLabel *detectView;
    QLabel *renderLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *checkingPushButton;
    QPushButton *startTestingPushButton;
    QPushButton *pausePushButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *timeLabel;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *productLabel;
    QLineEdit *productLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *amountLabel;
    QLineEdit *amountLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *NGLabel;
    QLineEdit *NGLineEdit;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1385, 765);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QStringLiteral("../14650616_1373983492625534_4218606715525314813_n.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setCursor(QCursor(Qt::ArrowCursor));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setEnabled(true);
        stackedWidget->setGeometry(QRect(10, 20, 1361, 711));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        homePage = new QWidget();
        homePage->setObjectName(QStringLiteral("homePage"));
        homePage->setLayoutDirection(Qt::RightToLeft);
        horizontalLayout = new QHBoxLayout(homePage);
        horizontalLayout->setSpacing(80);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(300, 160, 300, 160);
        testingPushButton = new QPushButton(homePage);
        testingPushButton->setObjectName(QStringLiteral("testingPushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(testingPushButton->sizePolicy().hasHeightForWidth());
        testingPushButton->setSizePolicy(sizePolicy1);
        QPalette palette;
        QBrush brush(QColor(0, 0, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        testingPushButton->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font.setPointSize(50);
        font.setBold(true);
        font.setWeight(75);
        testingPushButton->setFont(font);
        testingPushButton->setAutoFillBackground(true);

        horizontalLayout->addWidget(testingPushButton);

        trainningPushButton = new QPushButton(homePage);
        trainningPushButton->setObjectName(QStringLiteral("trainningPushButton"));
        sizePolicy1.setHeightForWidth(trainningPushButton->sizePolicy().hasHeightForWidth());
        trainningPushButton->setSizePolicy(sizePolicy1);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        trainningPushButton->setPalette(palette1);
        trainningPushButton->setFont(font);
        trainningPushButton->setLayoutDirection(Qt::LeftToRight);
        trainningPushButton->setAutoFillBackground(true);
        trainningPushButton->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(trainningPushButton);

        stackedWidget->addWidget(homePage);
        testingPage = new QWidget();
        testingPage->setObjectName(QStringLiteral("testingPage"));
        tableWidget = new QTableWidget(testingPage);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(1050, 320, 281, 301));
        tableWidget->setFrameShape(QFrame::StyledPanel);
        tableWidget->setFrameShadow(QFrame::Sunken);
        tableWidget->setLineWidth(1);
        tableWidget->setMidLineWidth(0);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        detectView = new QLabel(testingPage);
        detectView->setObjectName(QStringLiteral("detectView"));
        detectView->setGeometry(QRect(10, 60, 1030, 560));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(detectView->sizePolicy().hasHeightForWidth());
        detectView->setSizePolicy(sizePolicy2);
        detectView->setStyleSheet(QStringLiteral("border: 1px solid black;"));
        renderLabel = new QLabel(testingPage);
        renderLabel->setObjectName(QStringLiteral("renderLabel"));
        renderLabel->setGeometry(QRect(10, -1, 1321, 41));
        renderLabel->setStyleSheet(QStringLiteral(""));
        layoutWidget = new QWidget(testingPage);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 640, 631, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkingPushButton = new QPushButton(layoutWidget);
        checkingPushButton->setObjectName(QStringLiteral("checkingPushButton"));
        sizePolicy1.setHeightForWidth(checkingPushButton->sizePolicy().hasHeightForWidth());
        checkingPushButton->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        checkingPushButton->setFont(font1);

        horizontalLayout_2->addWidget(checkingPushButton);

        startTestingPushButton = new QPushButton(layoutWidget);
        startTestingPushButton->setObjectName(QStringLiteral("startTestingPushButton"));
        sizePolicy1.setHeightForWidth(startTestingPushButton->sizePolicy().hasHeightForWidth());
        startTestingPushButton->setSizePolicy(sizePolicy1);
        startTestingPushButton->setFont(font1);

        horizontalLayout_2->addWidget(startTestingPushButton);

        pausePushButton = new QPushButton(layoutWidget);
        pausePushButton->setObjectName(QStringLiteral("pausePushButton"));
        sizePolicy1.setHeightForWidth(pausePushButton->sizePolicy().hasHeightForWidth());
        pausePushButton->setSizePolicy(sizePolicy1);
        pausePushButton->setFont(font1);

        horizontalLayout_2->addWidget(pausePushButton);

        layoutWidget1 = new QWidget(testingPage);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(1050, 60, 281, 231));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_3->setContentsMargins(0, -1, -1, -1);
        timeLabel = new QLabel(layoutWidget1);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(timeLabel->sizePolicy().hasHeightForWidth());
        timeLabel->setSizePolicy(sizePolicy3);
        timeLabel->setFont(font1);
        timeLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(timeLabel);

        dateEdit = new QDateEdit(layoutWidget1);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(dateEdit->sizePolicy().hasHeightForWidth());
        dateEdit->setSizePolicy(sizePolicy4);
        dateEdit->setFocusPolicy(Qt::NoFocus);
        dateEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dateEdit->setKeyboardTracking(false);

        horizontalLayout_3->addWidget(dateEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        productLabel = new QLabel(layoutWidget1);
        productLabel->setObjectName(QStringLiteral("productLabel"));
        sizePolicy3.setHeightForWidth(productLabel->sizePolicy().hasHeightForWidth());
        productLabel->setSizePolicy(sizePolicy3);
        productLabel->setFont(font1);
        productLabel->setLayoutDirection(Qt::LeftToRight);
        productLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(productLabel);

        productLineEdit = new QLineEdit(layoutWidget1);
        productLineEdit->setObjectName(QStringLiteral("productLineEdit"));
        sizePolicy4.setHeightForWidth(productLineEdit->sizePolicy().hasHeightForWidth());
        productLineEdit->setSizePolicy(sizePolicy4);

        horizontalLayout_4->addWidget(productLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        amountLabel = new QLabel(layoutWidget1);
        amountLabel->setObjectName(QStringLiteral("amountLabel"));
        amountLabel->setFont(font1);

        horizontalLayout_5->addWidget(amountLabel);

        amountLineEdit = new QLineEdit(layoutWidget1);
        amountLineEdit->setObjectName(QStringLiteral("amountLineEdit"));
        sizePolicy4.setHeightForWidth(amountLineEdit->sizePolicy().hasHeightForWidth());
        amountLineEdit->setSizePolicy(sizePolicy4);
        amountLineEdit->setMinimumSize(QSize(150, 0));

        horizontalLayout_5->addWidget(amountLineEdit, 0, Qt::AlignRight);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        NGLabel = new QLabel(layoutWidget1);
        NGLabel->setObjectName(QStringLiteral("NGLabel"));
        NGLabel->setFont(font1);

        horizontalLayout_6->addWidget(NGLabel);

        NGLineEdit = new QLineEdit(layoutWidget1);
        NGLineEdit->setObjectName(QStringLiteral("NGLineEdit"));
        sizePolicy4.setHeightForWidth(NGLineEdit->sizePolicy().hasHeightForWidth());
        NGLineEdit->setSizePolicy(sizePolicy4);
        NGLineEdit->setMinimumSize(QSize(150, 0));
        NGLineEdit->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_6->addWidget(NGLineEdit, 0, Qt::AlignRight);


        verticalLayout->addLayout(horizontalLayout_6);

        stackedWidget->addWidget(testingPage);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1385, 24));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\347\224\242\347\267\232\346\231\272\345\213\225\346\252\242\346\270\254\347\263\273\347\265\261", nullptr));
        testingPushButton->setText(QApplication::translate("MainWindow", "\346\252\242\346\270\254", nullptr));
        trainningPushButton->setText(QApplication::translate("MainWindow", "\350\250\223\347\267\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\351\233\266\344\273\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\346\207\211\346\234\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\345\257\246\346\234\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\347\213\200\346\205\213", nullptr));
        detectView->setText(QString());
        renderLabel->setText(QString());
        checkingPushButton->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\346\225\270\346\223\232", nullptr));
        startTestingPushButton->setText(QApplication::translate("MainWindow", "\351\226\213\345\247\213\346\252\242\346\270\254", nullptr));
        pausePushButton->setText(QApplication::translate("MainWindow", "\346\232\253\345\201\234", nullptr));
        timeLabel->setText(QApplication::translate("MainWindow", "\346\231\202\351\226\223:     ", nullptr));
        dateEdit->setDisplayFormat(QApplication::translate("MainWindow", "yyyy/M/d hh:mm:ss", nullptr));
        productLabel->setText(QApplication::translate("MainWindow", "\345\223\201\345\220\215:     ", nullptr));
        amountLabel->setText(QApplication::translate("MainWindow", "\344\273\212\346\227\245\350\250\210\346\225\270:     ", nullptr));
        NGLabel->setText(QApplication::translate("MainWindow", "NG\346\225\270:     ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
