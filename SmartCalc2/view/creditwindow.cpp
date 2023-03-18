#include "creditwindow.h"
#include "ui_creditwindow.h"

CreditWindow::CreditWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreditWindow)
{
    ui->setupUi(this);

}

CreditWindow::~CreditWindow()
{
    delete ui;
}

void CreditWindow::on_comboBox_Term_currentIndexChanged(int index)
{
    if (index == 0) ui->spinBox_Term->setMaximum(600);
    if (index == 1) ui->spinBox_Term->setMaximum(50);
}

void CreditWindow::on_pushButton_Calculate_clicked()
{
//    QStringList a = {"1241234","124124"};
//    ui->listWidget_MonthlyPayment->addItems(a);

    Calculate();
}

void CreditWindow::Calculate() {
double TotalCreditAmount = ui->doubleSpinBox_TotalCreditAmount->value();
double InterestRate = ui->doubleSpinBox_InterestRate->value();
int Term = ui->spinBox_Term->value();
if (ui->comboBox_Term->currentIndex() == 1) Term *= 12;
// controller_

}

