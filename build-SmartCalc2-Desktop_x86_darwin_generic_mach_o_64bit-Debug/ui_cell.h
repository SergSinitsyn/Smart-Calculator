/********************************************************************************
** Form generated from reading UI file 'cell.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CELL_H
#define UI_CELL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cell
{
public:
    QGridLayout *gridLayout;
    QComboBox *comboBox;
    QDateEdit *dateEdit;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *pushButton;

    void setupUi(QWidget *Cell)
    {
        if (Cell->objectName().isEmpty())
            Cell->setObjectName(QString::fromUtf8("Cell"));
        Cell->resize(440, 38);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Cell->sizePolicy().hasHeightForWidth());
        Cell->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(Cell);
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(Cell);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 0, 0, 1, 1);

        dateEdit = new QDateEdit(Cell);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setMinimumSize(QSize(120, 0));
        dateEdit->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit, 0, 1, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(Cell);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(doubleSpinBox->sizePolicy().hasHeightForWidth());
        doubleSpinBox->setSizePolicy(sizePolicy1);
        doubleSpinBox->setLayoutDirection(Qt::LeftToRight);
        doubleSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox->setAccelerated(true);
        doubleSpinBox->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox->setMaximum(1000000000.000000000000000);

        gridLayout->addWidget(doubleSpinBox, 0, 2, 1, 1);

        pushButton = new QPushButton(Cell);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pushButton, 0, 3, 1, 1);

        QWidget::setTabOrder(comboBox, dateEdit);
        QWidget::setTabOrder(dateEdit, doubleSpinBox);
        QWidget::setTabOrder(doubleSpinBox, pushButton);

        retranslateUi(Cell);

        QMetaObject::connectSlotsByName(Cell);
    } // setupUi

    void retranslateUi(QWidget *Cell)
    {
        Cell->setWindowTitle(QCoreApplication::translate("Cell", "Form", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Cell", "One-time", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Cell", "Weekly", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Cell", "Monthly", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Cell", "Annually", nullptr));

        dateEdit->setDisplayFormat(QCoreApplication::translate("Cell", "dd/MM/yyyy", nullptr));
        pushButton->setText(QCoreApplication::translate("Cell", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Cell: public Ui_Cell {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CELL_H
