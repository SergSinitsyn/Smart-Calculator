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

void DepositWindow::on_pushButton_Calculate_clicked() { Calculate(); }

void DepositWindow::Calculate() { controller_deposit_->CalculateDeposit(this); }

double DepositWindow::GetDepositAmount() {
  return ui->doubleSpinBox_DepositAmount->value();
}

QDate DepositWindow::GetStartOfTerm() {
  return ui->dateEdit_StartOfTerm->date();
}

int DepositWindow::GetPlacementPeriod() {
  return ui->spinBox_PlacementPeriod->value();
}

// 0-daily 1-monthly 2-annually
int DepositWindow::GetPlacementPeriodType() {
  return ui->comboBox_PlacementPeriod->currentIndex();
}

double DepositWindow::GetInterestRate() {
  return ui->doubleSpinBox_InterestRate->value();
}

double DepositWindow::GetTaxRate() {
  return ui->doubleSpinBox_TaxRate->value();
}

int DepositWindow::GetPeriodicityOfPayments() {
  return ui->comboBox_PeriodicityOfPayments->currentIndex();
}

bool DepositWindow::GetCapitalisationOfInterest() {
  return ui->checkBox_Capitalisation->checkState();
}

void DepositWindow::SetAnswer(double deposit_amount_by_the_end_of_the_term,
                              double accrued_interest, double tax_amount) {
  ui->doubleSpinBox_DepositAmountByTheEndOfTheTerm->setValue(
      deposit_amount_by_the_end_of_the_term);
  ui->doubleSpinBox_AccruedInterest->setValue(accrued_interest);
  ui->doubleSpinBox_TaxAmount->setValue(tax_amount);
}
