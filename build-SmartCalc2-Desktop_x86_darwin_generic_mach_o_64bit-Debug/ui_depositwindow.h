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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DepositWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label;
    QLabel *label_2;
    QCheckBox *checkBox;
    QSpinBox *spinBox_3;
    QDoubleSpinBox *doubleSpinBox_2;
    QSpinBox *spinBox;
    QLabel *label_8;
    QComboBox *comboBox;
    QLabel *label_9;
    QComboBox *comboBox_2;
    QLabel *label_6;
    QSpinBox *spinBox_2;
    QLabel *label_11;
    QDateEdit *dateEdit;
    QPushButton *pushButton;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_7;
    QTableWidget *tableWidget;

    void setupUi(QWidget *DepositWindow)
    {
        if (DepositWindow->objectName().isEmpty())
            DepositWindow->setObjectName(QString::fromUtf8("DepositWindow"));
        DepositWindow->resize(863, 704);
        gridLayout = new QGridLayout(DepositWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_10 = new QLabel(DepositWindow);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAcceptDrops(false);
        label_10->setAutoFillBackground(false);
        label_10->setScaledContents(false);
        label_10->setWordWrap(true);

        gridLayout->addWidget(label_10, 10, 0, 1, 1);

        doubleSpinBox_4 = new QDoubleSpinBox(DepositWindow);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_4->setReadOnly(true);
        doubleSpinBox_4->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout->addWidget(doubleSpinBox_4, 10, 1, 1, 2);

        label = new QLabel(DepositWindow);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(DepositWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        checkBox = new QCheckBox(DepositWindow);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setAcceptDrops(false);
        checkBox->setInputMethodHints(Qt::ImhNone);
        checkBox->setTristate(false);

        gridLayout->addWidget(checkBox, 5, 2, 1, 1);

        spinBox_3 = new QSpinBox(DepositWindow);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(spinBox_3, 4, 1, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(DepositWindow);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_2->setReadOnly(true);
        doubleSpinBox_2->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout->addWidget(doubleSpinBox_2, 8, 1, 1, 2);

        spinBox = new QSpinBox(DepositWindow);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(spinBox, 2, 1, 1, 1);

        label_8 = new QLabel(DepositWindow);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 8, 0, 1, 1);

        comboBox = new QComboBox(DepositWindow);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 2, 2, 1, 1);

        label_9 = new QLabel(DepositWindow);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 9, 0, 1, 1);

        comboBox_2 = new QComboBox(DepositWindow);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 5, 1, 1, 1);

        label_6 = new QLabel(DepositWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 3, 2, 1, 1);

        spinBox_2 = new QSpinBox(DepositWindow);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(spinBox_2, 3, 1, 1, 1);

        label_11 = new QLabel(DepositWindow);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 4, 2, 1, 1);

        dateEdit = new QDateEdit(DepositWindow);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit, 1, 1, 1, 1);

        pushButton = new QPushButton(DepositWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 7, 0, 1, 3);

        label_4 = new QLabel(DepositWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_5 = new QLabel(DepositWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_3 = new QLabel(DepositWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(DepositWindow);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setLayoutDirection(Qt::LeftToRight);
        doubleSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(doubleSpinBox, 0, 1, 1, 2);

        doubleSpinBox_3 = new QDoubleSpinBox(DepositWindow);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_3->setReadOnly(true);
        doubleSpinBox_3->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout->addWidget(doubleSpinBox_3, 9, 1, 1, 2);

        label_7 = new QLabel(DepositWindow);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 5, 0, 1, 1);

        tableWidget = new QTableWidget(DepositWindow);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout->addWidget(tableWidget, 6, 1, 1, 1);

        QWidget::setTabOrder(doubleSpinBox, dateEdit);
        QWidget::setTabOrder(dateEdit, spinBox);
        QWidget::setTabOrder(spinBox, comboBox);
        QWidget::setTabOrder(comboBox, spinBox_2);
        QWidget::setTabOrder(spinBox_2, spinBox_3);
        QWidget::setTabOrder(spinBox_3, comboBox_2);
        QWidget::setTabOrder(comboBox_2, checkBox);
        QWidget::setTabOrder(checkBox, pushButton);
        QWidget::setTabOrder(pushButton, doubleSpinBox_2);
        QWidget::setTabOrder(doubleSpinBox_2, doubleSpinBox_3);
        QWidget::setTabOrder(doubleSpinBox_3, doubleSpinBox_4);

        retranslateUi(DepositWindow);

        QMetaObject::connectSlotsByName(DepositWindow);
    } // setupUi

    void retranslateUi(QWidget *DepositWindow)
    {
        DepositWindow->setWindowTitle(QCoreApplication::translate("DepositWindow", "Deposit Calculator", nullptr));
        label_10->setText(QCoreApplication::translate("DepositWindow", "Deposit Amount by the End of the Term", nullptr));
        label->setText(QCoreApplication::translate("DepositWindow", "Deposit Amount", nullptr));
        label_2->setText(QCoreApplication::translate("DepositWindow", "Start of Term", nullptr));
        checkBox->setText(QCoreApplication::translate("DepositWindow", "Capitalisation", nullptr));
        label_8->setText(QCoreApplication::translate("DepositWindow", "Accrued Interest", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("DepositWindow", "Days", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("DepositWindow", "Months", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("DepositWindow", "Years", nullptr));

        label_9->setText(QCoreApplication::translate("DepositWindow", "Tax Amount", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("DepositWindow", "Daily", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("DepositWindow", "Monthly", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("DepositWindow", "Annualy", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("DepositWindow", "\320\235\320\276\320\262\321\213\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("DepositWindow", "\320\235\320\276\320\262\321\213\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        comboBox_2->setItemText(5, QCoreApplication::translate("DepositWindow", "\320\235\320\276\320\262\321\213\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));

        label_6->setText(QCoreApplication::translate("DepositWindow", "%", nullptr));
        label_11->setText(QCoreApplication::translate("DepositWindow", "%", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("DepositWindow", "dd/MM/yyyy", nullptr));
        pushButton->setText(QCoreApplication::translate("DepositWindow", "Calcilate Deposit", nullptr));
        label_4->setText(QCoreApplication::translate("DepositWindow", "Placement Period", nullptr));
        label_5->setText(QCoreApplication::translate("DepositWindow", "Tax Rate", nullptr));
        label_3->setText(QCoreApplication::translate("DepositWindow", "Interest Rate", nullptr));
        label_7->setText(QCoreApplication::translate("DepositWindow", "Periodicity of Payments", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DepositWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DepositWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DepositWindow: public Ui_DepositWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSITWINDOW_H
