#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "../model/model.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_toolButton_equal_clicked()
{
    std::string input = ui->lineEdit_iuput->text().toStdString();


    QString qstr = QString::fromStdString(input);
    ui->statusbar->showMessage(qstr);


Model C;
C.Calculate(input, 0);
//double result = a.first;
//std::string error_code =  a.second;

//QString q_error = QString::fromStdString(error_code);
//ui->statusbar->showMessage(q_error);
//QString q_result = QString::number(result, 'g', 8);
//ui->lineEdit_output->setText(q_result);


}

