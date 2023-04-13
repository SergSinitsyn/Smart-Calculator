#include "cell.h"

#include "ui_cell.h"

namespace MyNamespace {
Cell::Cell(QWidget *parent) : QWidget(parent), ui(new Ui::Cell) {
  ui->setupUi(this);
  ui->dateEdit->setDate(QDate::currentDate());
}

Cell::~Cell() { delete ui; }

int Cell::GetPeriodicity() const { return ui->comboBox->currentIndex(); }

QDate Cell::GetDate() const { return ui->dateEdit->date(); }

double Cell::GetValue() const { return ui->doubleSpinBox->value(); }

int Cell::GetNumber() const { return number_; }

int Cell::GetType() const { return type_; }

void Cell::SetNumber(int newNumber) { number_ = newNumber; }

void Cell::SetType(int newType) { type_ = newType; }

void Cell::SetMinimumDate(QDate date) { ui->dateEdit->setMinimumDate(date); }

void Cell::on_toolButton_delete_clicked() {
  emit CloseThisCell(number_, type_);
  this->close();
}
};  // namespace MyNamespace
