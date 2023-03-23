/********************************************************************************
** Form generated from reading UI file 'depositwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSITWINDOW_H
#define UI_DEPOSITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DepositWindow
{
public:
    QGridLayout *gridLayout;
    QComboBox *comboBox;
    QLabel *label_2;
    QSpinBox *spinBox;
    QDateEdit *dateEdit;
    QCheckBox *checkBox;
    QLabel *label_9;
    QPushButton *pushButton_addReplenishment;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QPushButton *pushButton;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QLabel *label_8;
    QLabel *label_12;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_21;
    QDoubleSpinBox *doubleSpinBox_4;
    QDoubleSpinBox *doubleSpinBox_5;
    QDateEdit *dateEdit_2;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox_31;
    QPushButton *pushButton_2;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *DepositWindow)
    {
        if (DepositWindow->objectName().isEmpty())
            DepositWindow->setObjectName(QString::fromUtf8("DepositWindow"));
        DepositWindow->resize(566, 453);
        gridLayout = new QGridLayout(DepositWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        comboBox = new QComboBox(DepositWindow);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 2, 2, 1, 1);

        label_2 = new QLabel(DepositWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spinBox = new QSpinBox(DepositWindow);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox->setMinimum(1);
        spinBox->setMaximum(1000000);

        gridLayout->addWidget(spinBox, 2, 1, 1, 1);

        dateEdit = new QDateEdit(DepositWindow);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit, 1, 1, 1, 1);

        checkBox = new QCheckBox(DepositWindow);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setAcceptDrops(false);
        checkBox->setInputMethodHints(Qt::ImhNone);
        checkBox->setTristate(false);

        gridLayout->addWidget(checkBox, 5, 2, 1, 1);

        label_9 = new QLabel(DepositWindow);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 11, 0, 1, 1);

        pushButton_addReplenishment = new QPushButton(DepositWindow);
        pushButton_addReplenishment->setObjectName(QString::fromUtf8("pushButton_addReplenishment"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_addReplenishment->sizePolicy().hasHeightForWidth());
        pushButton_addReplenishment->setSizePolicy(sizePolicy);
        pushButton_addReplenishment->setMinimumSize(QSize(0, 0));
        pushButton_addReplenishment->setMaximumSize(QSize(20, 16777215));

        gridLayout->addWidget(pushButton_addReplenishment, 7, 4, 1, 1);

        label_3 = new QLabel(DepositWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(DepositWindow);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setLayoutDirection(Qt::LeftToRight);
        doubleSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(doubleSpinBox, 0, 1, 1, 2);

        doubleSpinBox_2 = new QDoubleSpinBox(DepositWindow);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_2->setMinimum(0.010000000000000);

        gridLayout->addWidget(doubleSpinBox_2, 3, 1, 1, 1);

        pushButton = new QPushButton(DepositWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 9, 1, 1, 4);

        comboBox_2 = new QComboBox(DepositWindow);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 5, 1, 1, 1);

        comboBox_3 = new QComboBox(DepositWindow);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        gridLayout->addWidget(comboBox_3, 7, 1, 1, 1);

        label_8 = new QLabel(DepositWindow);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 10, 0, 1, 1);

        label_12 = new QLabel(DepositWindow);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 7, 0, 1, 1);

        label = new QLabel(DepositWindow);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_6 = new QLabel(DepositWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 3, 2, 1, 1);

        label_11 = new QLabel(DepositWindow);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 4, 2, 1, 1);

        doubleSpinBox_21 = new QDoubleSpinBox(DepositWindow);
        doubleSpinBox_21->setObjectName(QString::fromUtf8("doubleSpinBox_21"));
        doubleSpinBox_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_21->setReadOnly(true);
        doubleSpinBox_21->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout->addWidget(doubleSpinBox_21, 10, 2, 1, 1);

        doubleSpinBox_4 = new QDoubleSpinBox(DepositWindow);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_4->setReadOnly(true);
        doubleSpinBox_4->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout->addWidget(doubleSpinBox_4, 12, 2, 1, 1);

        doubleSpinBox_5 = new QDoubleSpinBox(DepositWindow);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));

        gridLayout->addWidget(doubleSpinBox_5, 7, 3, 1, 1);

        dateEdit_2 = new QDateEdit(DepositWindow);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));

        gridLayout->addWidget(dateEdit_2, 7, 2, 1, 1);

        label_10 = new QLabel(DepositWindow);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAcceptDrops(false);
        label_10->setAutoFillBackground(false);
        label_10->setScaledContents(false);
        label_10->setWordWrap(true);

        gridLayout->addWidget(label_10, 12, 0, 1, 1);

        doubleSpinBox_3 = new QDoubleSpinBox(DepositWindow);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_3->setMinimum(0.000000000000000);
        doubleSpinBox_3->setValue(0.000000000000000);

        gridLayout->addWidget(doubleSpinBox_3, 4, 1, 1, 1);

        doubleSpinBox_31 = new QDoubleSpinBox(DepositWindow);
        doubleSpinBox_31->setObjectName(QString::fromUtf8("doubleSpinBox_31"));
        doubleSpinBox_31->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_31->setReadOnly(true);
        doubleSpinBox_31->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout->addWidget(doubleSpinBox_31, 11, 2, 1, 1);

        pushButton_2 = new QPushButton(DepositWindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 8, 1, 1, 1);

        label_7 = new QLabel(DepositWindow);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 5, 0, 1, 1);

        label_4 = new QLabel(DepositWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_5 = new QLabel(DepositWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        QWidget::setTabOrder(pushButton, doubleSpinBox_4);

        retranslateUi(DepositWindow);

        QMetaObject::connectSlotsByName(DepositWindow);
    } // setupUi

    void retranslateUi(QWidget *DepositWindow)
    {
        DepositWindow->setWindowTitle(QCoreApplication::translate("DepositWindow", "Deposit Calculator", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("DepositWindow", "Days", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("DepositWindow", "Weeks", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("DepositWindow", "Months", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("DepositWindow", "Years", nullptr));

        label_2->setText(QCoreApplication::translate("DepositWindow", "Start of Term", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("DepositWindow", "dd/MM/yyyy", nullptr));
        checkBox->setText(QCoreApplication::translate("DepositWindow", "Capitalisation", nullptr));
        label_9->setText(QCoreApplication::translate("DepositWindow", "Tax Amount", nullptr));
        pushButton_addReplenishment->setText(QCoreApplication::translate("DepositWindow", "X", nullptr));
        label_3->setText(QCoreApplication::translate("DepositWindow", "Interest Rate", nullptr));
        pushButton->setText(QCoreApplication::translate("DepositWindow", "Calcilate Deposit", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("DepositWindow", "Daily", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("DepositWindow", "Weekly", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("DepositWindow", "Monthly", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("DepositWindow", "Every three months", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("DepositWindow", "Semiannually", nullptr));
        comboBox_2->setItemText(5, QCoreApplication::translate("DepositWindow", "Annualy", nullptr));
        comboBox_2->setItemText(6, QCoreApplication::translate("DepositWindow", "At the end of the term", nullptr));

        label_8->setText(QCoreApplication::translate("DepositWindow", "Accrued Interest", nullptr));
        label_12->setText(QCoreApplication::translate("DepositWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("DepositWindow", "Deposit Amount", nullptr));
        label_6->setText(QCoreApplication::translate("DepositWindow", "%", nullptr));
        label_11->setText(QCoreApplication::translate("DepositWindow", "%", nullptr));
        label_10->setText(QCoreApplication::translate("DepositWindow", "Deposit Amount by the End of the Term", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DepositWindow", "PushButton", nullptr));
        label_7->setText(QCoreApplication::translate("DepositWindow", "Periodicity of Payments", nullptr));
        label_4->setText(QCoreApplication::translate("DepositWindow", "Placement Period", nullptr));
        label_5->setText(QCoreApplication::translate("DepositWindow", "Tax Rate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DepositWindow: public Ui_DepositWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSITWINDOW_H
