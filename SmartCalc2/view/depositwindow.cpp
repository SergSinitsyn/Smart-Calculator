#include "depositwindow.h"

#include "../controller/controller.h"
#include "ui_depositwindow.h"

DepositWindow::DepositWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::DepositWindow) {
  ui->setupUi(this);
  //    ui->tableWidget->setRowCount(0);
  //    ui->tableWidget->setColumnCount(3);

  //    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "№" <<
  //    "Date" << "Deposit");
}

DepositWindow::~DepositWindow() { delete ui; }

void DepositWindow::SetController(Controller *d) { controller_deposit_ = d; }

// int count =0;

void DepositWindow::on_pushButton_addReplenishment_clicked() {
  //    ui->tableWidget->setRowCount(count);
  //    QTableWidgetItem *tbl1 = new QTableWidgetItem(QString::number(count));
  //    ui->tableWidget->setItem(count,0,tbl1);
  //    QTableWidgetItem *tbl2 = new QTableWidgetItem(ui->dateEdit_2);
  //    count++;
}
