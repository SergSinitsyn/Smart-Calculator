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
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DepositWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *label_DepositAmount;
    QDoubleSpinBox *doubleSpinBox_DepositAmount;
    QSpinBox *spinBox_PlacementPeriod;
    QLabel *label_Percent2;
    QDoubleSpinBox *doubleSpinBox_AccruedInterest;
    QComboBox *comboBox_PeriodicityOfPayments;
    QDoubleSpinBox *doubleSpinBox_TaxAmount;
    QDoubleSpinBox *doubleSpinBox_InterestRate;
    QLabel *label_TaxRate;
    QLabel *label_TaxAmount;
    QCheckBox *checkBox_Capitalisation;
    QLabel *label_StartOfTerm;
    QLabel *label;
    QLabel *label_PlacementPeriod;
    QLabel *label_Replenishments;
    QLabel *label_InterestRate;
    QLabel *label_AccruedInterest;
    QLabel *label_DepositAmountByTheEndOfTheTerm;
    QLabel *label_PeriodicityOfPayments;
    QDoubleSpinBox *doubleSpinBox_DepositAmountByTheEndOfTheTerm;
    QPushButton *pushButton_Calculate;
    QComboBox *comboBox_PlacementPeriod;
    QDoubleSpinBox *doubleSpinBox_TaxRate;
    QDateEdit *dateEdit_StartOfTerm;
    QPushButton *pushButton_AddPartialWithdrawal;
    QScrollArea *scrollArea_Replenishments;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_Replenishments;
    QLabel *label_Percent;
    QScrollArea *scrollArea_PartialWithdrawals;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_PartialWithdrawals;
    QPushButton *pushButton_AddReplenishment;

    void setupUi(QWidget *DepositWindow)
    {
        if (DepositWindow->objectName().isEmpty())
            DepositWindow->setObjectName(QString::fromUtf8("DepositWindow"));
        DepositWindow->resize(604, 784);
        gridLayout = new QGridLayout(DepositWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_DepositAmount = new QLabel(DepositWindow);
        label_DepositAmount->setObjectName(QString::fromUtf8("label_DepositAmount"));

        gridLayout->addWidget(label_DepositAmount, 0, 0, 1, 1);

        doubleSpinBox_DepositAmount = new QDoubleSpinBox(DepositWindow);
        doubleSpinBox_DepositAmount->setObjectName(QString::fromUtf8("doubleSpinBox_DepositAmount"));
        doubleSpinBox_DepositAmount->setLayoutDirection(Qt::LeftToRight);
        doubleSpinBox_DepositAmount->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_DepositAmount->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_DepositAmount->setMaximum(1000000000000000.000000000000000);

        gridLayout->addWidget(doubleSpinBox_DepositAmount, 0, 1, 1, 2);

        spinBox_PlacementPeriod = new QSpinBox(DepositWindow);
        spinBox_PlacementPeriod->setObjectName(QString::fromUtf8("spinBox_PlacementPeriod"));
        spinBox_PlacementPeriod->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_PlacementPeriod->setMinimum(1);
        spinBox_PlacementPeriod->setMaximum(1000000);

        gridLayout->addWidget(spinBox_PlacementPeriod, 2, 1, 1, 1);

        label_Percent2 = new QLabel(DepositWindow);
        label_Percent2->setObjectName(QString::fromUtf8("label_Percent2"));

        gridLayout->addWidget(label_Percent2, 4, 2, 1, 1);

        doubleSpinBox_AccruedInterest = new QDoubleSpinBox(DepositWindow);
        doubleSpinBox_AccruedInterest->setObjectName(QString::fromUtf8("doubleSpinBox_AccruedInterest"));
        doubleSpinBox_AccruedInterest->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_AccruedInterest->setReadOnly(true);
        doubleSpinBox_AccruedInterest->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_AccruedInterest->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_AccruedInterest->setMaximum(1000000000000000.000000000000000);

        gridLayout->addWidget(doubleSpinBox_AccruedInterest, 12, 1, 1, 1);

        comboBox_PeriodicityOfPayments = new QComboBox(DepositWindow);
        comboBox_PeriodicityOfPayments->addItem(QString());
        comboBox_PeriodicityOfPayments->addItem(QString());
        comboBox_PeriodicityOfPayments->addItem(QString());
        comboBox_PeriodicityOfPayments->addItem(QString());
        comboBox_PeriodicityOfPayments->addItem(QString());
        comboBox_PeriodicityOfPayments->addItem(QString());
        comboBox_PeriodicityOfPayments->addItem(QString());
        comboBox_PeriodicityOfPayments->setObjectName(QString::fromUtf8("comboBox_PeriodicityOfPayments"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_PeriodicityOfPayments->sizePolicy().hasHeightForWidth());
        comboBox_PeriodicityOfPayments->setSizePolicy(sizePolicy);

        gridLayout->addWidget(comboBox_PeriodicityOfPayments, 5, 1, 1, 1);

        doubleSpinBox_TaxAmount = new QDoubleSpinBox(DepositWindow);
        doubleSpinBox_TaxAmount->setObjectName(QString::fromUtf8("doubleSpinBox_TaxAmount"));
        doubleSpinBox_TaxAmount->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_TaxAmount->setReadOnly(true);
        doubleSpinBox_TaxAmount->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_TaxAmount->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_TaxAmount->setMaximum(1000000000000000.000000000000000);

        gridLayout->addWidget(doubleSpinBox_TaxAmount, 13, 1, 1, 1);

        doubleSpinBox_InterestRate = new QDoubleSpinBox(DepositWindow);
        doubleSpinBox_InterestRate->setObjectName(QString::fromUtf8("doubleSpinBox_InterestRate"));
        doubleSpinBox_InterestRate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_InterestRate->setMinimum(0.010000000000000);

        gridLayout->addWidget(doubleSpinBox_InterestRate, 3, 1, 1, 1);

        label_TaxRate = new QLabel(DepositWindow);
        label_TaxRate->setObjectName(QString::fromUtf8("label_TaxRate"));

        gridLayout->addWidget(label_TaxRate, 4, 0, 1, 1);

        label_TaxAmount = new QLabel(DepositWindow);
        label_TaxAmount->setObjectName(QString::fromUtf8("label_TaxAmount"));

        gridLayout->addWidget(label_TaxAmount, 13, 0, 1, 1);

        checkBox_Capitalisation = new QCheckBox(DepositWindow);
        checkBox_Capitalisation->setObjectName(QString::fromUtf8("checkBox_Capitalisation"));
        checkBox_Capitalisation->setAcceptDrops(false);
        checkBox_Capitalisation->setInputMethodHints(Qt::ImhNone);
        checkBox_Capitalisation->setTristate(false);

        gridLayout->addWidget(checkBox_Capitalisation, 5, 2, 1, 1);

        label_StartOfTerm = new QLabel(DepositWindow);
        label_StartOfTerm->setObjectName(QString::fromUtf8("label_StartOfTerm"));

        gridLayout->addWidget(label_StartOfTerm, 1, 0, 1, 1);

        label = new QLabel(DepositWindow);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 9, 0, 1, 1);

        label_PlacementPeriod = new QLabel(DepositWindow);
        label_PlacementPeriod->setObjectName(QString::fromUtf8("label_PlacementPeriod"));

        gridLayout->addWidget(label_PlacementPeriod, 2, 0, 1, 1);

        label_Replenishments = new QLabel(DepositWindow);
        label_Replenishments->setObjectName(QString::fromUtf8("label_Replenishments"));

        gridLayout->addWidget(label_Replenishments, 6, 0, 1, 1);

        label_InterestRate = new QLabel(DepositWindow);
        label_InterestRate->setObjectName(QString::fromUtf8("label_InterestRate"));

        gridLayout->addWidget(label_InterestRate, 3, 0, 1, 1);

        label_AccruedInterest = new QLabel(DepositWindow);
        label_AccruedInterest->setObjectName(QString::fromUtf8("label_AccruedInterest"));

        gridLayout->addWidget(label_AccruedInterest, 12, 0, 1, 1);

        label_DepositAmountByTheEndOfTheTerm = new QLabel(DepositWindow);
        label_DepositAmountByTheEndOfTheTerm->setObjectName(QString::fromUtf8("label_DepositAmountByTheEndOfTheTerm"));
        label_DepositAmountByTheEndOfTheTerm->setAcceptDrops(false);
        label_DepositAmountByTheEndOfTheTerm->setAutoFillBackground(false);
        label_DepositAmountByTheEndOfTheTerm->setScaledContents(false);
        label_DepositAmountByTheEndOfTheTerm->setWordWrap(true);

        gridLayout->addWidget(label_DepositAmountByTheEndOfTheTerm, 14, 0, 1, 1);

        label_PeriodicityOfPayments = new QLabel(DepositWindow);
        label_PeriodicityOfPayments->setObjectName(QString::fromUtf8("label_PeriodicityOfPayments"));

        gridLayout->addWidget(label_PeriodicityOfPayments, 5, 0, 1, 1);

        doubleSpinBox_DepositAmountByTheEndOfTheTerm = new QDoubleSpinBox(DepositWindow);
        doubleSpinBox_DepositAmountByTheEndOfTheTerm->setObjectName(QString::fromUtf8("doubleSpinBox_DepositAmountByTheEndOfTheTerm"));
        doubleSpinBox_DepositAmountByTheEndOfTheTerm->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_DepositAmountByTheEndOfTheTerm->setReadOnly(true);
        doubleSpinBox_DepositAmountByTheEndOfTheTerm->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_DepositAmountByTheEndOfTheTerm->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_DepositAmountByTheEndOfTheTerm->setMaximum(1000000000000000.000000000000000);

        gridLayout->addWidget(doubleSpinBox_DepositAmountByTheEndOfTheTerm, 14, 1, 1, 1);

        pushButton_Calculate = new QPushButton(DepositWindow);
        pushButton_Calculate->setObjectName(QString::fromUtf8("pushButton_Calculate"));

        gridLayout->addWidget(pushButton_Calculate, 11, 0, 1, 3);

        comboBox_PlacementPeriod = new QComboBox(DepositWindow);
        comboBox_PlacementPeriod->addItem(QString());
        comboBox_PlacementPeriod->addItem(QString());
        comboBox_PlacementPeriod->addItem(QString());
        comboBox_PlacementPeriod->setObjectName(QString::fromUtf8("comboBox_PlacementPeriod"));
        sizePolicy.setHeightForWidth(comboBox_PlacementPeriod->sizePolicy().hasHeightForWidth());
        comboBox_PlacementPeriod->setSizePolicy(sizePolicy);

        gridLayout->addWidget(comboBox_PlacementPeriod, 2, 2, 1, 1);

        doubleSpinBox_TaxRate = new QDoubleSpinBox(DepositWindow);
        doubleSpinBox_TaxRate->setObjectName(QString::fromUtf8("doubleSpinBox_TaxRate"));
        doubleSpinBox_TaxRate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_TaxRate->setMinimum(0.000000000000000);
        doubleSpinBox_TaxRate->setValue(0.000000000000000);

        gridLayout->addWidget(doubleSpinBox_TaxRate, 4, 1, 1, 1);

        dateEdit_StartOfTerm = new QDateEdit(DepositWindow);
        dateEdit_StartOfTerm->setObjectName(QString::fromUtf8("dateEdit_StartOfTerm"));
        dateEdit_StartOfTerm->setAccelerated(true);
        dateEdit_StartOfTerm->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit_StartOfTerm, 1, 1, 1, 1);

        pushButton_AddPartialWithdrawal = new QPushButton(DepositWindow);
        pushButton_AddPartialWithdrawal->setObjectName(QString::fromUtf8("pushButton_AddPartialWithdrawal"));

        gridLayout->addWidget(pushButton_AddPartialWithdrawal, 9, 1, 1, 1);

        scrollArea_Replenishments = new QScrollArea(DepositWindow);
        scrollArea_Replenishments->setObjectName(QString::fromUtf8("scrollArea_Replenishments"));
        scrollArea_Replenishments->setLineWidth(1);
        scrollArea_Replenishments->setWidgetResizable(true);
        scrollArea_Replenishments->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 578, 161));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_Replenishments = new QVBoxLayout();
#ifndef Q_OS_MAC
        verticalLayout_Replenishments->setSpacing(-1);
#endif
        verticalLayout_Replenishments->setObjectName(QString::fromUtf8("verticalLayout_Replenishments"));
        verticalLayout_Replenishments->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout_Replenishments->setContentsMargins(0, -1, 0, 0);

        verticalLayout->addLayout(verticalLayout_Replenishments);

        scrollArea_Replenishments->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea_Replenishments, 8, 0, 1, 3);

        label_Percent = new QLabel(DepositWindow);
        label_Percent->setObjectName(QString::fromUtf8("label_Percent"));

        gridLayout->addWidget(label_Percent, 3, 2, 1, 1);

        scrollArea_PartialWithdrawals = new QScrollArea(DepositWindow);
        scrollArea_PartialWithdrawals->setObjectName(QString::fromUtf8("scrollArea_PartialWithdrawals"));
        scrollArea_PartialWithdrawals->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 578, 160));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_PartialWithdrawals = new QVBoxLayout();
        verticalLayout_PartialWithdrawals->setObjectName(QString::fromUtf8("verticalLayout_PartialWithdrawals"));
        verticalLayout_PartialWithdrawals->setSizeConstraint(QLayout::SetMaximumSize);

        verticalLayout_2->addLayout(verticalLayout_PartialWithdrawals);

        scrollArea_PartialWithdrawals->setWidget(scrollAreaWidgetContents_2);

        gridLayout->addWidget(scrollArea_PartialWithdrawals, 10, 0, 1, 3);

        pushButton_AddReplenishment = new QPushButton(DepositWindow);
        pushButton_AddReplenishment->setObjectName(QString::fromUtf8("pushButton_AddReplenishment"));

        gridLayout->addWidget(pushButton_AddReplenishment, 6, 1, 1, 1);


        retranslateUi(DepositWindow);

        QMetaObject::connectSlotsByName(DepositWindow);
    } // setupUi

    void retranslateUi(QWidget *DepositWindow)
    {
        DepositWindow->setWindowTitle(QCoreApplication::translate("DepositWindow", "Deposit Calculator", nullptr));
        label_DepositAmount->setText(QCoreApplication::translate("DepositWindow", "Deposit Amount", nullptr));
        label_Percent2->setText(QCoreApplication::translate("DepositWindow", "%", nullptr));
        comboBox_PeriodicityOfPayments->setItemText(0, QCoreApplication::translate("DepositWindow", "Daily", nullptr));
        comboBox_PeriodicityOfPayments->setItemText(1, QCoreApplication::translate("DepositWindow", "Weekly", nullptr));
        comboBox_PeriodicityOfPayments->setItemText(2, QCoreApplication::translate("DepositWindow", "Monthly", nullptr));
        comboBox_PeriodicityOfPayments->setItemText(3, QCoreApplication::translate("DepositWindow", "Every three months", nullptr));
        comboBox_PeriodicityOfPayments->setItemText(4, QCoreApplication::translate("DepositWindow", "Semiannually", nullptr));
        comboBox_PeriodicityOfPayments->setItemText(5, QCoreApplication::translate("DepositWindow", "Annualy", nullptr));
        comboBox_PeriodicityOfPayments->setItemText(6, QCoreApplication::translate("DepositWindow", "At the end of the term", nullptr));

        label_TaxRate->setText(QCoreApplication::translate("DepositWindow", "Tax Rate", nullptr));
        label_TaxAmount->setText(QCoreApplication::translate("DepositWindow", "Tax Amount", nullptr));
        checkBox_Capitalisation->setText(QCoreApplication::translate("DepositWindow", "Capitalisation", nullptr));
        label_StartOfTerm->setText(QCoreApplication::translate("DepositWindow", "Start of Term", nullptr));
        label->setText(QCoreApplication::translate("DepositWindow", "Partial Withdrawals", nullptr));
        label_PlacementPeriod->setText(QCoreApplication::translate("DepositWindow", "Placement Period", nullptr));
        label_Replenishments->setText(QCoreApplication::translate("DepositWindow", "Replenishments", nullptr));
        label_InterestRate->setText(QCoreApplication::translate("DepositWindow", "Interest Rate", nullptr));
        label_AccruedInterest->setText(QCoreApplication::translate("DepositWindow", "Accrued Interest", nullptr));
        label_DepositAmountByTheEndOfTheTerm->setText(QCoreApplication::translate("DepositWindow", "Deposit Amount by the End of the Term", nullptr));
        label_PeriodicityOfPayments->setText(QCoreApplication::translate("DepositWindow", "Periodicity of Payments", nullptr));
        pushButton_Calculate->setText(QCoreApplication::translate("DepositWindow", "Calcilate Deposit", nullptr));
        comboBox_PlacementPeriod->setItemText(0, QCoreApplication::translate("DepositWindow", "Days", nullptr));
        comboBox_PlacementPeriod->setItemText(1, QCoreApplication::translate("DepositWindow", "Months", nullptr));
        comboBox_PlacementPeriod->setItemText(2, QCoreApplication::translate("DepositWindow", "Years", nullptr));

        dateEdit_StartOfTerm->setDisplayFormat(QCoreApplication::translate("DepositWindow", "dd/MM/yyyy", nullptr));
        pushButton_AddPartialWithdrawal->setText(QCoreApplication::translate("DepositWindow", "Add Partial Withdrawal", nullptr));
        label_Percent->setText(QCoreApplication::translate("DepositWindow", "%", nullptr));
        pushButton_AddReplenishment->setText(QCoreApplication::translate("DepositWindow", "Add Replenishment", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DepositWindow: public Ui_DepositWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSITWINDOW_H
