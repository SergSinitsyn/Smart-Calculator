#include "depositwindow.h"

#include "../controller/controller.h"
#include "ui_depositwindow.h"

namespace MyNamespace {
DepositWindow::DepositWindow(QWidget* parent)
    : QWidget(parent), ui(new Ui::DepositWindow) {
  ui->setupUi(this);
  ui->dateEdit_StartOfTerm->setDate(QDate::currentDate());
  cell_number_total_replenishment_ = 0;
  cell_number_total_partial_withdrawal_ = 0;
}

DepositWindow::~DepositWindow() { delete ui; }

void DepositWindow::SetController(Controller* d) { controller_deposit_ = d; }

double DepositWindow::GetDepositAmount() const {
  return ui->doubleSpinBox_DepositAmount->value();
}

QDate DepositWindow::GetStartOfTerm() const {
  return ui->dateEdit_StartOfTerm->date();
}

int DepositWindow::GetPlacementPeriod() const {
  return ui->spinBox_PlacementPeriod->value();
}

int DepositWindow::GetPlacementPeriodType() const {
  return ui->comboBox_PlacementPeriod->currentIndex();
}

double DepositWindow::GetInterestRate() const {
  return ui->doubleSpinBox_InterestRate->value();
}

double DepositWindow::GetTaxRate() const {
  return ui->doubleSpinBox_TaxRate->value();
}

int DepositWindow::GetPeriodicityOfPayments() const {
  return ui->comboBox_PeriodicityOfPayments->currentIndex();
}

bool DepositWindow::GetCapitalisationOfInterest() const {
  return ui->checkBox_Capitalisation->checkState();
}

double DepositWindow::GetMinimumBalance() const {
  return ui->doubleSpinBox_MinimumBalance->value();
}

MultiMapQDate DepositWindow::GetReplenishmentsList() const {
  return replenishments_list_;
}

MultiMapQDate DepositWindow::GetPartialWithdrawalsList() const {
  return partial_withdrawals_list_;
}

void DepositWindow::SetAnswer(double deposit_amount_by_the_end_of_the_term,
                              double accrued_interest, double tax_amount) {
  SetValueToLine(deposit_amount_by_the_end_of_the_term,
                 ui->lineEdit_DepositAmountByTheEndOfTheTerm);
  SetValueToLine(tax_amount, ui->lineEdit_TaxAmount);
  SetValueToLine(accrued_interest, ui->lineEdit_AccruedInterest);
}

void DepositWindow::AddNewCellReplenishment() {
  Cell* NewCell = new Cell(this);
  ui->verticalLayout_Replenishments->insertWidget(
      cell_number_total_replenishment_, NewCell);
  connect(NewCell, SIGNAL(CloseThisCell(int, int)), this,
          SLOT(CloseCell(int, int)));
  NewCell->setAttribute(Qt::WA_DeleteOnClose, true);
  NewCell->SetNumber(cell_number_total_replenishment_);
  NewCell->SetType(1);
  NewCell->SetMinimumDate(ui->dateEdit_StartOfTerm->date());
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
  NewCell->SetNumber(cell_number_total_partial_withdrawal_);

  NewCell->SetType(-1);
  NewCell->SetMinimumDate(ui->dateEdit_StartOfTerm->date());
  all_cell_partial_withdrawal_ptr_.append(NewCell);
  ++cell_number_total_partial_withdrawal_;
}

void DepositWindow::FillList(
    QVector<Cell*> vector, std::multimap<QDate, std::pair<int, double>>& map) {
  map.clear();
  auto it = vector.begin();
  while (it != vector.end()) {
    map.insert(std::make_pair(
        (*it)->GetDate(),
        std::make_pair((*it)->GetPeriodicity(), (*it)->GetValue())));
    ++it;
  }
}

void DepositWindow::FillReplenishmentsList() {
  FillList(all_cell_replenishment_ptr_, replenishments_list_);
}

void DepositWindow::FillPartialWithdrawalsList() {
  FillList(all_cell_partial_withdrawal_ptr_, partial_withdrawals_list_);
}

void DepositWindow::SetGroupSeparators(QString& srt) {
  int i = 0;
  int t = 3 * (2 + i) + i;
  while (t < srt.size()) {
    srt.insert(srt.size() - t, ",");
    ++i;
    t = 3 * (2 + i) + i;
  }
}

void DepositWindow::SetValueToLine(double value, QLineEdit* line) {
  QString word = QString::number(value, 'f', 2);
  SetGroupSeparators(word);
  line->setText(word);
}

void DepositWindow::on_pushButton_Calculate_clicked() {
  FillReplenishmentsList();
  FillPartialWithdrawalsList();
  try {
    controller_deposit_->CalculateDeposit(this);
  } catch (const std::exception& e) {
    QMessageBox::critical(this, "Warning", e.what());
  }
}

void DepositWindow::on_pushButton_AddReplenishment_clicked() {
  if (cell_number_total_replenishment_ == kMaxCellNumber_) {
    QMessageBox::warning(
        this, "Warning",
        "The maximum length of the replenishment list has been reached");
    return;
  }
  AddNewCellReplenishment();
}

void DepositWindow::on_pushButton_AddPartialWithdrawal_clicked() {
  if (cell_number_total_partial_withdrawal_ == kMaxCellNumber_) {
    QMessageBox::warning(
        this, "Warning",
        "The maximum length of the partial withdrawal list has been reached");
    return;
  }
  AddNewCellPartialWithdrawal();
}

void DepositWindow::on_comboBox_PlacementPeriod_currentIndexChanged(int index) {
  if (index == 0) ui->spinBox_PlacementPeriod->setMaximum(18250);
  if (index == 1) ui->spinBox_PlacementPeriod->setMaximum(600);
  if (index == 2) ui->spinBox_PlacementPeriod->setMaximum(50);
}

void DepositWindow::on_dateEdit_StartOfTerm_userDateChanged(const QDate& date) {
  for (int i = 0; i < all_cell_replenishment_ptr_.length(); ++i) {
    all_cell_replenishment_ptr_.at(i)->SetMinimumDate(date);
  }
  for (int i = 0; i < all_cell_partial_withdrawal_ptr_.length(); ++i) {
    all_cell_partial_withdrawal_ptr_.at(i)->SetMinimumDate(date);
  }
}

void DepositWindow::CloseCell(int CellNumber, int CellType) {
  if (CellType == 1) {
    all_cell_replenishment_ptr_[CellNumber]->close();
    for (int i = CellNumber + 1; i < all_cell_replenishment_ptr_.length();
         ++i) {
      all_cell_replenishment_ptr_[i]->SetNumber(
          all_cell_replenishment_ptr_[i]->GetNumber() - 1);
    }
    --cell_number_total_replenishment_;
    all_cell_replenishment_ptr_.remove(CellNumber);
  }
  if (CellType == -1) {
    all_cell_partial_withdrawal_ptr_[CellNumber]->close();
    for (int i = CellNumber + 1; i < all_cell_partial_withdrawal_ptr_.length();
         ++i) {
      all_cell_partial_withdrawal_ptr_[i]->SetNumber(
          all_cell_partial_withdrawal_ptr_[i]->GetNumber() - 1);
    }
    --cell_number_total_partial_withdrawal_;
    all_cell_partial_withdrawal_ptr_.remove(CellNumber);
  }
}

};  // namespace MyNamespace
