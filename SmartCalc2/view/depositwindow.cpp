#include "depositwindow.h"

#include <QPushButton>
#include <QString>
#include <QVBoxLayout>

#include "../controller/controller.h"
#include "ui_depositwindow.h"

DepositWindow::DepositWindow(QWidget* parent)
    : QWidget(parent), ui(new Ui::DepositWindow) {
  ui->setupUi(this);
  ui->dateEdit_StartOfTerm->setDate(QDate::currentDate());
  CellNumberTotalReplenishment = 0;
  CellNumberTotalPartialWithdrawal = 0;
}

DepositWindow::~DepositWindow() { delete ui; }

void DepositWindow::SetController(Controller* d) { controller_deposit_ = d; }

void DepositWindow::on_pushButton_Calculate_clicked() { Calculate(); }

void DepositWindow::Calculate() {
  FillReplenishmentsList();
  FillPartialWithdrawalsList();
  controller_deposit_->CalculateDeposit(this);
}

void DepositWindow::AddNewCell() {
  Cell* NewCell = new Cell(this);
  ui->verticalLayout_Replenishments->addWidget(NewCell,
                                               CellNumberTotalReplenishment);

  //  connect(NewCell, SIGNAL(CloseThisCell(int)), this, SLOT(CloseCell(int)));
  NewCell->setAttribute(Qt::WA_DeleteOnClose, true);
  NewCell->CellNumber = CellNumberTotalReplenishment;
  AllCellReplenishmentPtr.append(NewCell);
  ++CellNumberTotalReplenishment;
}

void DepositWindow::CloseCell(int CellNumber) {
  AllCellReplenishmentPtr[CellNumber]->close();
  for (int i = CellNumber + 1; i < AllCellReplenishmentPtr.length(); ++i) {
    AllCellReplenishmentPtr[i]->CellNumber--;
  }
  --CellNumberTotalReplenishment;
  AllCellReplenishmentPtr.remove(CellNumber);
}

void DepositWindow::FillList(QVector<Cell*> vector,
                             std::multimap<Date, std::pair<int, double>> map) {
  map.clear();
  auto it = vector.begin();
  while (it != vector.end()) {
    QDate Temp = (*it)->GetDate();
    Date Temp2(Temp.day(), Temp.month() - 1, Temp.year());
    (*it)->GetType();
    (*it)->GetValue();
    map.insert(std::make_pair(
        Temp2, std::make_pair((*it)->GetType(), (*it)->GetValue())));
    ++it;
  }
}

void DepositWindow::FillReplenishmentsList() {
  FillList(AllCellReplenishmentPtr, replenishments_list_);
}

void DepositWindow::FillPartialWithdrawalsList() {
  FillList(AllCellPartialWithdrawalPtr, partial_withdrawals_list_);
}

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

std::multimap<Date, std::pair<int, double>>
DepositWindow::GetReplenishmentsList() {
  return replenishments_list_;
}

std::multimap<Date, std::pair<int, double>>
DepositWindow::GetPartialWithdrawalsList() {
  return partial_withdrawals_list_;
}

void DepositWindow::SetAnswer(double deposit_amount_by_the_end_of_the_term,
                              double accrued_interest, double tax_amount) {
  ui->doubleSpinBox_DepositAmountByTheEndOfTheTerm->setValue(
      deposit_amount_by_the_end_of_the_term);
  ui->doubleSpinBox_AccruedInterest->setValue(accrued_interest);
  ui->doubleSpinBox_TaxAmount->setValue(tax_amount);
}

void DepositWindow::on_pushButton_AddReplenishment_clicked() { AddNewCell(); }
