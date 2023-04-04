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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DepositWindow
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_addReplenishment;
    QComboBox *comboBox_PeriodicityOfPayments;
    QDateEdit *dateEdit_StartOfTerm;
    QLabel *label_6;
    QComboBox *comboBox_3;
    QComboBox *comboBox_PlacementPeriod;
    QLabel *label_8;
    QLabel *label_4;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_AccruedInterest;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox_DepositAmount;
    QLabel *label_13;
    QLabel *label_3;
    QSpinBox *spinBox_PlacementPeriod;
    QCheckBox *checkBox_Capitalisation;
    QLabel *label_10;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_TaxRate;
    QPushButton *pushButton_Calculate;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_DepositAmountByTheEndOfTheTerm;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_TaxAmount;
    QDoubleSpinBox *doubleSpinBox_InterestRate;
    QLabel *label;
    QDateEdit *dateEdit_2;
    QLabel *label_9;
    QPushButton *pushButton;

    void setupUi(QWidget *DepositWindow)
    {
        if (DepositWindow->objectName().isEmpty())
            DepositWindow->setObjectName(QString::fromUtf8("DepositWindow"));
        DepositWindow->resize(600, 453);
        gridLayout = new QGridLayout(DepositWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
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

        comboBox_PeriodicityOfPayments = new QComboBox(DepositWindow);
        comboBox_PeriodicityOfPayments->addItem(QString());
        comboBox_PeriodicityOfPayments->addItem(QString());
        comboBox_PeriodicityOfPayments->addItem(QString());
        comboBox_PeriodicityOfPayments->addItem(QString());
        comboBox_PeriodicityOfPayments->addItem(QString());
        comboBox_PeriodicityOfPayments->addItem(QString());
        comboBox_PeriodicityOfPayments->addItem(QString());
        comboBox_PeriodicityOfPayments->setObjectName(QString::fromUtf8("comboBox_PeriodicityOfPayments"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_PeriodicityOfPayments->sizePolicy().hasHeightForWidth());
        comboBox_PeriodicityOfPayments->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(comboBox_PeriodicityOfPayments, 5, 1, 1, 1);

        dateEdit_StartOfTerm = new QDateEdit(DepositWindow);
        dateEdit_StartOfTerm->setObjectName(QString::fromUtf8("dateEdit_StartOfTerm"));
        dateEdit_StartOfTerm->setAccelerated(true);
        dateEdit_StartOfTerm->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit_StartOfTerm, 1, 1, 1, 1);

        label_6 = new QLabel(DepositWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 3, 2, 1, 1);

        comboBox_3 = new QComboBox(DepositWindow);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        sizePolicy1.setHeightForWidth(comboBox_3->sizePolicy().hasHeightForWidth());
        comboBox_3->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(comboBox_3, 7, 1, 1, 1);

        comboBox_PlacementPeriod = new QComboBox(DepositWindow);
        comboBox_PlacementPeriod->addItem(QString());
        comboBox_PlacementPeriod->addItem(QString());
        comboBox_PlacementPeriod->addItem(QString());
        comboBox_PlacementPeriod->setObjectName(QString::fromUtf8("comboBox_PlacementPeriod"));
        sizePolicy1.setHeightForWidth(comboBox_PlacementPeriod->sizePolicy().hasHeightForWidth());
        comboBox_PlacementPeriod->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(comboBox_PlacementPeriod, 2, 2, 1, 1);

        label_8 = new QLabel(DepositWindow);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 13, 0, 1, 1);

        label_4 = new QLabel(DepositWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_2 = new QLabel(DepositWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        doubleSpinBox_AccruedInterest = new QDoubleSpinBox(DepositWindow);
        doubleSpinBox_AccruedInterest->setObjectName(QString::fromUtf8("doubleSpinBox_AccruedInterest"));
        doubleSpinBox_AccruedInterest->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_AccruedInterest->setReadOnly(true);
        doubleSpinBox_AccruedInterest->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_AccruedInterest->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_AccruedInterest->setMaximum(1000000000000000.000000000000000);

        gridLayout->addWidget(doubleSpinBox_AccruedInterest, 13, 1, 1, 1);

        frame = new QFrame(DepositWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer = new QSpacerItem(198, 3, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 0, 1, 1);


        gridLayout->addWidget(frame, 9, 1, 2, 4);

        label_12 = new QLabel(DepositWindow);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 7, 0, 1, 1);

        doubleSpinBox_5 = new QDoubleSpinBox(DepositWindow);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));

        gridLayout->addWidget(doubleSpinBox_5, 7, 3, 1, 1);

        doubleSpinBox_DepositAmount = new QDoubleSpinBox(DepositWindow);
        doubleSpinBox_DepositAmount->setObjectName(QString::fromUtf8("doubleSpinBox_DepositAmount"));
        doubleSpinBox_DepositAmount->setLayoutDirection(Qt::LeftToRight);
        doubleSpinBox_DepositAmount->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_DepositAmount->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_DepositAmount->setMaximum(1000000000000000.000000000000000);

        gridLayout->addWidget(doubleSpinBox_DepositAmount, 0, 1, 1, 1);

        label_13 = new QLabel(DepositWindow);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 5, 3, 1, 1);

        label_3 = new QLabel(DepositWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        spinBox_PlacementPeriod = new QSpinBox(DepositWindow);
        spinBox_PlacementPeriod->setObjectName(QString::fromUtf8("spinBox_PlacementPeriod"));
        spinBox_PlacementPeriod->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_PlacementPeriod->setMinimum(1);
        spinBox_PlacementPeriod->setMaximum(1000000);

        gridLayout->addWidget(spinBox_PlacementPeriod, 2, 1, 1, 1);

        checkBox_Capitalisation = new QCheckBox(DepositWindow);
        checkBox_Capitalisation->setObjectName(QString::fromUtf8("checkBox_Capitalisation"));
        checkBox_Capitalisation->setAcceptDrops(false);
        checkBox_Capitalisation->setInputMethodHints(Qt::ImhNone);
        checkBox_Capitalisation->setTristate(false);

        gridLayout->addWidget(checkBox_Capitalisation, 5, 2, 1, 1);

        label_10 = new QLabel(DepositWindow);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAcceptDrops(false);
        label_10->setAutoFillBackground(false);
        label_10->setScaledContents(false);
        label_10->setWordWrap(true);

        gridLayout->addWidget(label_10, 15, 0, 1, 1);

        label_5 = new QLabel(DepositWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        doubleSpinBox_TaxRate = new QDoubleSpinBox(DepositWindow);
        doubleSpinBox_TaxRate->setObjectName(QString::fromUtf8("doubleSpinBox_TaxRate"));
        doubleSpinBox_TaxRate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_TaxRate->setMinimum(0.000000000000000);
        doubleSpinBox_TaxRate->setValue(0.000000000000000);

        gridLayout->addWidget(doubleSpinBox_TaxRate, 4, 1, 1, 1);

        pushButton_Calculate = new QPushButton(DepositWindow);
        pushButton_Calculate->setObjectName(QString::fromUtf8("pushButton_Calculate"));

        gridLayout->addWidget(pushButton_Calculate, 12, 1, 1, 4);

        label_7 = new QLabel(DepositWindow);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 5, 0, 1, 1);

        doubleSpinBox_DepositAmountByTheEndOfTheTerm = new QDoubleSpinBox(DepositWindow);
        doubleSpinBox_DepositAmountByTheEndOfTheTerm->setObjectName(QString::fromUtf8("doubleSpinBox_DepositAmountByTheEndOfTheTerm"));
        doubleSpinBox_DepositAmountByTheEndOfTheTerm->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_DepositAmountByTheEndOfTheTerm->setReadOnly(true);
        doubleSpinBox_DepositAmountByTheEndOfTheTerm->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_DepositAmountByTheEndOfTheTerm->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_DepositAmountByTheEndOfTheTerm->setMaximum(1000000000000000.000000000000000);

        gridLayout->addWidget(doubleSpinBox_DepositAmountByTheEndOfTheTerm, 15, 1, 1, 1);

        label_11 = new QLabel(DepositWindow);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 4, 2, 1, 1);

        doubleSpinBox_TaxAmount = new QDoubleSpinBox(DepositWindow);
        doubleSpinBox_TaxAmount->setObjectName(QString::fromUtf8("doubleSpinBox_TaxAmount"));
        doubleSpinBox_TaxAmount->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_TaxAmount->setReadOnly(true);
        doubleSpinBox_TaxAmount->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_TaxAmount->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_TaxAmount->setMaximum(1000000000000000.000000000000000);

        gridLayout->addWidget(doubleSpinBox_TaxAmount, 14, 1, 1, 1);

        doubleSpinBox_InterestRate = new QDoubleSpinBox(DepositWindow);
        doubleSpinBox_InterestRate->setObjectName(QString::fromUtf8("doubleSpinBox_InterestRate"));
        doubleSpinBox_InterestRate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_InterestRate->setMinimum(0.010000000000000);

        gridLayout->addWidget(doubleSpinBox_InterestRate, 3, 1, 1, 1);

        label = new QLabel(DepositWindow);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        dateEdit_2 = new QDateEdit(DepositWindow);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));
        dateEdit_2->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit_2, 7, 2, 1, 1);

        label_9 = new QLabel(DepositWindow);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 14, 0, 1, 1);

        pushButton = new QPushButton(DepositWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 8, 1, 1, 1);


        retranslateUi(DepositWindow);

        QMetaObject::connectSlotsByName(DepositWindow);
    } // setupUi

    void retranslateUi(QWidget *DepositWindow)
    {
        DepositWindow->setWindowTitle(QCoreApplication::translate("DepositWindow", "Deposit Calculator", nullptr));
        pushButton_addReplenishment->setText(QCoreApplication::translate("DepositWindow", "X", nullptr));
        comboBox_PeriodicityOfPayments->setItemText(0, QCoreApplication::translate("DepositWindow", "Daily", nullptr));
        comboBox_PeriodicityOfPayments->setItemText(1, QCoreApplication::translate("DepositWindow", "Weekly", nullptr));
        comboBox_PeriodicityOfPayments->setItemText(2, QCoreApplication::translate("DepositWindow", "Monthly", nullptr));
        comboBox_PeriodicityOfPayments->setItemText(3, QCoreApplication::translate("DepositWindow", "Every three months", nullptr));
        comboBox_PeriodicityOfPayments->setItemText(4, QCoreApplication::translate("DepositWindow", "Semiannually", nullptr));
        comboBox_PeriodicityOfPayments->setItemText(5, QCoreApplication::translate("DepositWindow", "Annualy", nullptr));
        comboBox_PeriodicityOfPayments->setItemText(6, QCoreApplication::translate("DepositWindow", "At the end of the term", nullptr));

        dateEdit_StartOfTerm->setDisplayFormat(QCoreApplication::translate("DepositWindow", "dd/MM/yyyy", nullptr));
        label_6->setText(QCoreApplication::translate("DepositWindow", "%", nullptr));
        comboBox_PlacementPeriod->setItemText(0, QCoreApplication::translate("DepositWindow", "Days", nullptr));
        comboBox_PlacementPeriod->setItemText(1, QCoreApplication::translate("DepositWindow", "Months", nullptr));
        comboBox_PlacementPeriod->setItemText(2, QCoreApplication::translate("DepositWindow", "Years", nullptr));

        label_8->setText(QCoreApplication::translate("DepositWindow", "Accrued Interest", nullptr));
        label_4->setText(QCoreApplication::translate("DepositWindow", "Placement Period", nullptr));
        label_2->setText(QCoreApplication::translate("DepositWindow", "Start of Term", nullptr));
        label_12->setText(QCoreApplication::translate("DepositWindow", "TextLabel", nullptr));
        label_13->setText(QCoreApplication::translate("DepositWindow", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("DepositWindow", "Interest Rate", nullptr));
        checkBox_Capitalisation->setText(QCoreApplication::translate("DepositWindow", "Capitalisation", nullptr));
        label_10->setText(QCoreApplication::translate("DepositWindow", "Deposit Amount by the End of the Term", nullptr));
        label_5->setText(QCoreApplication::translate("DepositWindow", "Tax Rate", nullptr));
        pushButton_Calculate->setText(QCoreApplication::translate("DepositWindow", "Calcilate Deposit", nullptr));
        label_7->setText(QCoreApplication::translate("DepositWindow", "Periodicity of Payments", nullptr));
        label_11->setText(QCoreApplication::translate("DepositWindow", "%", nullptr));
        label->setText(QCoreApplication::translate("DepositWindow", "Deposit Amount", nullptr));
        dateEdit_2->setDisplayFormat(QCoreApplication::translate("DepositWindow", "dd/MM/yyyy", nullptr));
        label_9->setText(QCoreApplication::translate("DepositWindow", "Tax Amount", nullptr));
        pushButton->setText(QCoreApplication::translate("DepositWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DepositWindow: public Ui_DepositWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSITWINDOW_H
