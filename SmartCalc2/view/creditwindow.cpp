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

void CreditWindow::on_pushButton_Calculate_clicked()
{
    QStringList a = {"1241234","124124"};
    ui->listWidget_MonthlyPayment->addItems(a);
}


void CreditWindow::on_comboBox_Term_currentIndexChanged(int index)
{
    if (index == 0) ui->spinBox_Term->setMaximum(600);
    if (index == 1) ui->spinBox_Term->setMaximum(50);
}

