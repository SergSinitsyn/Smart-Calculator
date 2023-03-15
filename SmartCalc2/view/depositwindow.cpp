#include "depositwindow.h"
#include "ui_depositwindow.h"

DepositWindow::DepositWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DepositWindow)
{
    ui->setupUi(this);
}

DepositWindow::~DepositWindow()
{
    delete ui;
}

