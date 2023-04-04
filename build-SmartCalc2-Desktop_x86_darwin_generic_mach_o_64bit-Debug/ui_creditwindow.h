/********************************************************************************
** Form generated from reading UI file 'creditwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDITWINDOW_H
#define UI_CREDITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreditWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *label_TotalPayment;
    QLabel *label_InterestRate;
    QComboBox *comboBox_Term;
    QSpinBox *spinBox_Term;
    QLabel *label_Type;
    QLabel *label_MonthlyPayment;
    QDoubleSpinBox *doubleSpinBox_InterestRate;
    QDoubleSpinBox *doubleSpinBox_TotalCreditAmount;
    QLabel *label_Term;
    QLabel *label_Overpayment;
    QLabel *label_prc;
    QComboBox *comboBox_Type;
    QLabel *label_TotalCreditAmount;
    QListWidget *listWidget_MonthlyPayment;
    QDoubleSpinBox *doubleSpinBox_TotalPayment;
    QDoubleSpinBox *doubleSpinBox_Overpayment;
    QPushButton *pushButton_Calculate;
    QPushButton *pushButton_Clear;

    void setupUi(QWidget *CreditWindow)
    {
        if (CreditWindow->objectName().isEmpty())
            CreditWindow->setObjectName(QString::fromUtf8("CreditWindow"));
        CreditWindow->resize(396, 329);
        gridLayout = new QGridLayout(CreditWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_TotalPayment = new QLabel(CreditWindow);
        label_TotalPayment->setObjectName(QString::fromUtf8("label_TotalPayment"));

        gridLayout->addWidget(label_TotalPayment, 5, 0, 1, 1);

        label_InterestRate = new QLabel(CreditWindow);
        label_InterestRate->setObjectName(QString::fromUtf8("label_InterestRate"));

        gridLayout->addWidget(label_InterestRate, 2, 0, 1, 1);

        comboBox_Term = new QComboBox(CreditWindow);
        comboBox_Term->addItem(QString());
        comboBox_Term->addItem(QString());
        comboBox_Term->setObjectName(QString::fromUtf8("comboBox_Term"));

        gridLayout->addWidget(comboBox_Term, 1, 2, 1, 1);

        spinBox_Term = new QSpinBox(CreditWindow);
        spinBox_Term->setObjectName(QString::fromUtf8("spinBox_Term"));
        QFont font;
        font.setPointSize(13);
        spinBox_Term->setFont(font);
        spinBox_Term->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_Term->setMinimum(1);
        spinBox_Term->setMaximum(600);

        gridLayout->addWidget(spinBox_Term, 1, 1, 1, 1);

        label_Type = new QLabel(CreditWindow);
        label_Type->setObjectName(QString::fromUtf8("label_Type"));

        gridLayout->addWidget(label_Type, 3, 0, 1, 1);

        label_MonthlyPayment = new QLabel(CreditWindow);
        label_MonthlyPayment->setObjectName(QString::fromUtf8("label_MonthlyPayment"));

        gridLayout->addWidget(label_MonthlyPayment, 7, 0, 1, 1, Qt::AlignTop);

        doubleSpinBox_InterestRate = new QDoubleSpinBox(CreditWindow);
        doubleSpinBox_InterestRate->setObjectName(QString::fromUtf8("doubleSpinBox_InterestRate"));
        doubleSpinBox_InterestRate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_InterestRate->setMinimum(0.010000000000000);

        gridLayout->addWidget(doubleSpinBox_InterestRate, 2, 1, 1, 1);

        doubleSpinBox_TotalCreditAmount = new QDoubleSpinBox(CreditWindow);
        doubleSpinBox_TotalCreditAmount->setObjectName(QString::fromUtf8("doubleSpinBox_TotalCreditAmount"));
        doubleSpinBox_TotalCreditAmount->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_TotalCreditAmount->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_TotalCreditAmount->setMaximum(1000000000000000000.000000000000000);

        gridLayout->addWidget(doubleSpinBox_TotalCreditAmount, 0, 1, 1, 2);

        label_Term = new QLabel(CreditWindow);
        label_Term->setObjectName(QString::fromUtf8("label_Term"));

        gridLayout->addWidget(label_Term, 1, 0, 1, 1);

        label_Overpayment = new QLabel(CreditWindow);
        label_Overpayment->setObjectName(QString::fromUtf8("label_Overpayment"));

        gridLayout->addWidget(label_Overpayment, 6, 0, 1, 1);

        label_prc = new QLabel(CreditWindow);
        label_prc->setObjectName(QString::fromUtf8("label_prc"));

        gridLayout->addWidget(label_prc, 2, 2, 1, 1);

        comboBox_Type = new QComboBox(CreditWindow);
        comboBox_Type->addItem(QString());
        comboBox_Type->addItem(QString());
        comboBox_Type->setObjectName(QString::fromUtf8("comboBox_Type"));

        gridLayout->addWidget(comboBox_Type, 3, 1, 1, 1);

        label_TotalCreditAmount = new QLabel(CreditWindow);
        label_TotalCreditAmount->setObjectName(QString::fromUtf8("label_TotalCreditAmount"));

        gridLayout->addWidget(label_TotalCreditAmount, 0, 0, 1, 1);

        listWidget_MonthlyPayment = new QListWidget(CreditWindow);
        listWidget_MonthlyPayment->setObjectName(QString::fromUtf8("listWidget_MonthlyPayment"));
        listWidget_MonthlyPayment->setFont(font);
        listWidget_MonthlyPayment->setLayoutDirection(Qt::RightToLeft);
        listWidget_MonthlyPayment->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        listWidget_MonthlyPayment->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

        gridLayout->addWidget(listWidget_MonthlyPayment, 7, 1, 1, 2);

        doubleSpinBox_TotalPayment = new QDoubleSpinBox(CreditWindow);
        doubleSpinBox_TotalPayment->setObjectName(QString::fromUtf8("doubleSpinBox_TotalPayment"));
        doubleSpinBox_TotalPayment->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_TotalPayment->setReadOnly(true);
        doubleSpinBox_TotalPayment->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_TotalPayment->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_TotalPayment->setMaximum(1000000000000000000.000000000000000);

        gridLayout->addWidget(doubleSpinBox_TotalPayment, 5, 1, 1, 2);

        doubleSpinBox_Overpayment = new QDoubleSpinBox(CreditWindow);
        doubleSpinBox_Overpayment->setObjectName(QString::fromUtf8("doubleSpinBox_Overpayment"));
        doubleSpinBox_Overpayment->setFont(font);
        doubleSpinBox_Overpayment->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_Overpayment->setReadOnly(true);
        doubleSpinBox_Overpayment->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Overpayment->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_Overpayment->setMaximum(1000000000000000000.000000000000000);

        gridLayout->addWidget(doubleSpinBox_Overpayment, 6, 1, 1, 2);

        pushButton_Calculate = new QPushButton(CreditWindow);
        pushButton_Calculate->setObjectName(QString::fromUtf8("pushButton_Calculate"));

        gridLayout->addWidget(pushButton_Calculate, 4, 0, 1, 2);

        pushButton_Clear = new QPushButton(CreditWindow);
        pushButton_Clear->setObjectName(QString::fromUtf8("pushButton_Clear"));

        gridLayout->addWidget(pushButton_Clear, 4, 2, 1, 1);

        QWidget::setTabOrder(doubleSpinBox_TotalCreditAmount, spinBox_Term);
        QWidget::setTabOrder(spinBox_Term, comboBox_Term);
        QWidget::setTabOrder(comboBox_Term, doubleSpinBox_InterestRate);
        QWidget::setTabOrder(doubleSpinBox_InterestRate, comboBox_Type);
        QWidget::setTabOrder(comboBox_Type, pushButton_Calculate);
        QWidget::setTabOrder(pushButton_Calculate, doubleSpinBox_TotalPayment);
        QWidget::setTabOrder(doubleSpinBox_TotalPayment, doubleSpinBox_Overpayment);

        retranslateUi(CreditWindow);

        QMetaObject::connectSlotsByName(CreditWindow);
    } // setupUi

    void retranslateUi(QWidget *CreditWindow)
    {
        CreditWindow->setWindowTitle(QCoreApplication::translate("CreditWindow", "Credit Calculator", nullptr));
        label_TotalPayment->setText(QCoreApplication::translate("CreditWindow", "Total Payment", nullptr));
        label_InterestRate->setText(QCoreApplication::translate("CreditWindow", "Interest Rate", nullptr));
        comboBox_Term->setItemText(0, QCoreApplication::translate("CreditWindow", "Months", nullptr));
        comboBox_Term->setItemText(1, QCoreApplication::translate("CreditWindow", "Years", nullptr));

        label_Type->setText(QCoreApplication::translate("CreditWindow", "Type", nullptr));
        label_MonthlyPayment->setText(QCoreApplication::translate("CreditWindow", "Monthly payment", nullptr));
        label_Term->setText(QCoreApplication::translate("CreditWindow", "Term", nullptr));
        label_Overpayment->setText(QCoreApplication::translate("CreditWindow", "Overtayment on credit", nullptr));
        label_prc->setText(QCoreApplication::translate("CreditWindow", "%", nullptr));
        comboBox_Type->setItemText(0, QCoreApplication::translate("CreditWindow", "Annuity", nullptr));
        comboBox_Type->setItemText(1, QCoreApplication::translate("CreditWindow", "Differentiated", nullptr));

        label_TotalCreditAmount->setText(QCoreApplication::translate("CreditWindow", "Total Credit Amount", nullptr));
#if QT_CONFIG(whatsthis)
        listWidget_MonthlyPayment->setWhatsThis(QCoreApplication::translate("CreditWindow", "<html><head/><body><p align=\"right\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_Calculate->setText(QCoreApplication::translate("CreditWindow", "Calculate", nullptr));
        pushButton_Clear->setText(QCoreApplication::translate("CreditWindow", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreditWindow: public Ui_CreditWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDITWINDOW_H
