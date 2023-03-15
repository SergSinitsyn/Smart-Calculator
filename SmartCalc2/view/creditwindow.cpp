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

}


void CreditWindow::on_comboBox_Term_currentIndexChanged(int index)
{
    if (index == 0) ui->spinBox_term->setMaximum(600);
    if (index == 1) ui->spinBox_term->setMaximum(50);
}

