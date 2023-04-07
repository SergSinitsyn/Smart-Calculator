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
  cell_number_total_replenishment_ = 0;
  cell_number_total_partial_withdrawal_ = 0;
}

DepositWindow::~DepositWindow() { delete ui; }

void DepositWindow::SetController(Controller* d) { controller_deposit_ = d; }

void DepositWindow::on_pushButton_Calculate_clicked() { Calculate(); }

void DepositWindow::Calculate() {
  FillReplenishmentsList();
  FillPartialWithdrawalsList();
  try {
    controller_deposit_->CalculateDeposit(this);
  } catch (const std::exception& e) {
    QMessageBox::critical(this, "Warning", e.what());
  }
}

void DepositWindow::AddNewCellReplenishment() {
  Cell* NewCell = new Cell(this);
  ui->verticalLayout_Replenishments->insertWidget(
      cell_number_total_replenishment_, NewCell);
  connect(NewCell, SIGNAL(CloseThisCell(int, int)), this,
          SLOT(CloseCell(int, int)));
  NewCell->setAttribute(Qt::WA_DeleteOnClose, true);
  NewCell->CellNumber = cell_number_total_replenishment_;
  NewCell->CellType = 1;
  all_cell_replenishment_ptr_.append(NewCell);
  ++cell_number_total_replenishment_;
}

void DepositWindow::AddNewCellPartialWithdrawal() {
  Cell* NewCell = new Cell(this);
  ui->verticalLayout_PartialWithdrawals->insertWidget(
      cell_number_total_partial_withdrawal_, NewCell);
  connect(NewCell, SIGNAL(CloseThisCell(int, int)), this,
          SLOT(CloseCell(int, int)));
  NewCell->setAttribute(Qt::WA_DeleteOnClose, true);
  NewCell->CellNumber = cell_number_total_partial_withdrawal_;
  NewCell->CellType = -1;
  all_cell_partial_withdrawal_ptr_.append(NewCell);
  ++cell_number_total_partial_withdrawal_;
}

void DepositWindow::CloseCell(int CellNumber, int CellType) {
  if (CellType == 1) {
    all_cell_replenishment_ptr_[CellNumber]->close();
    for (int i = CellNumber + 1; i < all_cell_replenishment_ptr_.length();
         ++i) {
      all_cell_replenishment_ptr_[i]->CellNumber--;
    }
    --cell_number_total_replenishment_;
    all_cell_replenishment_ptr_.remove(CellNumber);
  }
  if (CellType == -1) {
    all_cell_partial_withdrawal_ptr_[CellNumber]->close();
    for (int i = CellNumber + 1; i < all_cell_partial_withdrawal_ptr_.length();
         ++i) {
      all_cell_partial_withdrawal_ptr_[i]->CellNumber--;
    }
    --cell_number_total_partial_withdrawal_;
    all_cell_partial_withdrawal_ptr_.remove(CellNumber);
  }
}

void DepositWindow::FillList(QVector<Cell*> vector,
                             std::multimap<Date, std::pair<int, double>>& map) {
  map.clear();
  auto it = vector.begin();
  while (it != vector.end()) {
    QDate Temp = (*it)->GetDate();
    Date date(Temp.day(), Temp.month() - 1, Temp.year());
    (*it)->GetType();
    (*it)->GetValue();
    map.insert(std::make_pair(
        date, std::make_pair((*it)->GetType(), (*it)->GetValue())));
    ++it;
  }
}

void DepositWindow::FillReplenishmentsList() {
  FillList(all_cell_replenishment_ptr_, replenishments_list_);
}

void DepositWindow::FillPartialWithdrawalsList() {
  FillList(all_cell_partial_withdrawal_ptr_, partial_withdrawals_list_);
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

double DepositWindow::GetMinimumBalance() {
  return ui->doubleSpinBox_MinimumBalance->value();
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

void DepositWindow::on_pushButton_AddReplenishment_clicked() {
  AddNewCellReplenishment();
}

void DepositWindow::on_pushButton_AddPartialWithdrawal_clicked() {
  AddNewCellPartialWithdrawal();
}
