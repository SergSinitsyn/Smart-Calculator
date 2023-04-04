#include "cell.h"

#include "ui_cell.h"

Cell::Cell(QWidget *parent) : QWidget(parent), ui(new Ui::Cell) {
  ui->setupUi(this);
  ui->dateEdit->setDate(QDate::currentDate());
}

Cell::~Cell() { delete ui; }

int Cell::GetType() { return ui->comboBox->currentIndex(); }

QDate Cell::GetDate() { return ui->dateEdit->date(); }

double Cell::GetValue() { return ui->doubleSpinBox->value(); }

void Cell::on_pushButton_clicked() {
  emit CloseThisCell(CellNumber);
  this->close();
}
