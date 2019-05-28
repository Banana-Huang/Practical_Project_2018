/********************************************************************************
** Form generated from reading UI file 'settingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGDIALOG_H
#define UI_SETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settingDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *productNumberLabel;
    QComboBox *productComboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *weightLabel;
    QLineEdit *weightLineEdit;
    QPushButton *weightPushButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *settingLabel;
    QLineEdit *settingLineEdit;
    QPushButton *settingPushButton;
    QHBoxLayout *horizontalLayout_5;
    QLabel *dateLabel;
    QLineEdit *dataLineEdit;
    QPushButton *dataPushButton;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QComboBox *cameraComboBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *confirmPushButton;
    QPushButton *cancelPushButton;

    void setupUi(QDialog *settingDialog)
    {
        if (settingDialog->objectName().isEmpty())
            settingDialog->setObjectName(QStringLiteral("settingDialog"));
        settingDialog->resize(383, 281);
        QIcon icon;
        icon.addFile(QStringLiteral("../14650616_1373983492625534_4218606715525314813_n.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        settingDialog->setWindowIcon(icon);
        widget = new QWidget(settingDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 12, 365, 261));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        productNumberLabel = new QLabel(widget);
        productNumberLabel->setObjectName(QStringLiteral("productNumberLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(productNumberLabel->sizePolicy().hasHeightForWidth());
        productNumberLabel->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        productNumberLabel->setFont(font);
        productNumberLabel->setLayoutDirection(Qt::LeftToRight);
        productNumberLabel->setLineWidth(1);
        productNumberLabel->setTextFormat(Qt::AutoText);
        productNumberLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(productNumberLabel);

        productComboBox = new QComboBox(widget);
        productComboBox->setObjectName(QStringLiteral("productComboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(productComboBox->sizePolicy().hasHeightForWidth());
        productComboBox->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(productComboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        weightLabel = new QLabel(widget);
        weightLabel->setObjectName(QStringLiteral("weightLabel"));
        weightLabel->setFont(font);
        weightLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(weightLabel);

        weightLineEdit = new QLineEdit(widget);
        weightLineEdit->setObjectName(QStringLiteral("weightLineEdit"));
        sizePolicy1.setHeightForWidth(weightLineEdit->sizePolicy().hasHeightForWidth());
        weightLineEdit->setSizePolicy(sizePolicy1);
        weightLineEdit->setMinimumSize(QSize(200, 0));
        weightLineEdit->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_3->addWidget(weightLineEdit);

        weightPushButton = new QPushButton(widget);
        weightPushButton->setObjectName(QStringLiteral("weightPushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(weightPushButton->sizePolicy().hasHeightForWidth());
        weightPushButton->setSizePolicy(sizePolicy2);
        weightPushButton->setMinimumSize(QSize(0, 0));

        horizontalLayout_3->addWidget(weightPushButton);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        settingLabel = new QLabel(widget);
        settingLabel->setObjectName(QStringLiteral("settingLabel"));
        settingLabel->setMaximumSize(QSize(16777215, 16777215));
        settingLabel->setFont(font);
        settingLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(settingLabel);

        settingLineEdit = new QLineEdit(widget);
        settingLineEdit->setObjectName(QStringLiteral("settingLineEdit"));
        settingLineEdit->setMinimumSize(QSize(200, 0));

        horizontalLayout_4->addWidget(settingLineEdit);

        settingPushButton = new QPushButton(widget);
        settingPushButton->setObjectName(QStringLiteral("settingPushButton"));
        sizePolicy2.setHeightForWidth(settingPushButton->sizePolicy().hasHeightForWidth());
        settingPushButton->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(settingPushButton);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        dateLabel = new QLabel(widget);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font1.setKerning(true);
        dateLabel->setFont(font1);
        dateLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(dateLabel);

        dataLineEdit = new QLineEdit(widget);
        dataLineEdit->setObjectName(QStringLiteral("dataLineEdit"));
        dataLineEdit->setMinimumSize(QSize(200, 0));
        dataLineEdit->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_5->addWidget(dataLineEdit);

        dataPushButton = new QPushButton(widget);
        dataPushButton->setObjectName(QStringLiteral("dataPushButton"));
        sizePolicy2.setHeightForWidth(dataPushButton->sizePolicy().hasHeightForWidth());
        dataPushButton->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(dataPushButton);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);

        horizontalLayout_6->addWidget(label);

        cameraComboBox = new QComboBox(widget);
        cameraComboBox->setObjectName(QStringLiteral("cameraComboBox"));
        sizePolicy1.setHeightForWidth(cameraComboBox->sizePolicy().hasHeightForWidth());
        cameraComboBox->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(cameraComboBox);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        confirmPushButton = new QPushButton(widget);
        confirmPushButton->setObjectName(QStringLiteral("confirmPushButton"));
        sizePolicy3.setHeightForWidth(confirmPushButton->sizePolicy().hasHeightForWidth());
        confirmPushButton->setSizePolicy(sizePolicy3);
        confirmPushButton->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(confirmPushButton);

        cancelPushButton = new QPushButton(widget);
        cancelPushButton->setObjectName(QStringLiteral("cancelPushButton"));
        sizePolicy3.setHeightForWidth(cancelPushButton->sizePolicy().hasHeightForWidth());
        cancelPushButton->setSizePolicy(sizePolicy3);
        cancelPushButton->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(cancelPushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(settingDialog);

        QMetaObject::connectSlotsByName(settingDialog);
    } // setupUi

    void retranslateUi(QDialog *settingDialog)
    {
        settingDialog->setWindowTitle(QApplication::translate("settingDialog", "\350\256\212\346\225\270\347\263\273\347\265\261\345\217\203\346\225\270\350\250\255\345\256\232", nullptr));
        productNumberLabel->setText(QApplication::translate("settingDialog", "\347\224\242\345\223\201\345\272\217\350\231\237:", nullptr));
        weightLabel->setText(QApplication::translate("settingDialog", "        \346\254\212\351\207\215:", nullptr));
        weightPushButton->setText(QApplication::translate("settingDialog", "...", nullptr));
        settingLabel->setText(QApplication::translate("settingDialog", "        \350\250\255\345\256\232:", nullptr));
        settingPushButton->setText(QApplication::translate("settingDialog", "...", nullptr));
        dateLabel->setText(QApplication::translate("settingDialog", "        Data:", nullptr));
        dataPushButton->setText(QApplication::translate("settingDialog", "...", nullptr));
        label->setText(QApplication::translate("settingDialog", "    Camera:", nullptr));
        confirmPushButton->setText(QApplication::translate("settingDialog", "\347\242\272\345\256\232", nullptr));
        cancelPushButton->setText(QApplication::translate("settingDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class settingDialog: public Ui_settingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H
