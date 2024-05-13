#include "creditwindow.h"

#include "../../controller/controller.h"
#include "ui_creditwindow.h"

namespace MyNamespace {
CreditWindow::CreditWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::CreditWindow) {
  ui->setupUi(this);
}

CreditWindow::~CreditWindow() { delete ui; }

void CreditWindow::SetController(Controller *c) { controller_credit_ = c; }

double CreditWindow::GetTotalCreditAmount() const {
  return ui->doubleSpinBox_TotalCreditAmount->value();
}

double CreditWindow::GetInterestRate() const {
  return ui->doubleSpinBox_InterestRate->value();
}

int CreditWindow::GetTerm() const {
  int term = ui->spinBox_Term->value();
  if (ui->comboBox_Term->currentIndex() == 1)
    term *= 12;
  return term;
}

int CreditWindow::GetCreditType() const {
  return ui->comboBox_Type->currentIndex();
}

void CreditWindow::SetAnswer(double total_payment, double overpayment_on_credit,
                             std::vector<double> monthly_payment) {
  ui->listWidget_MonthlyPayment->clear();
  auto it = monthly_payment.begin();
  while (it != monthly_payment.end()) {
    ui->doubleSpinBox_TotalPayment->setValue(*it);
    ++it;
    QString itemTitle(ui->doubleSpinBox_TotalPayment->text());
    QListWidgetItem *item = new QListWidgetItem;
    item->setText(itemTitle);
    ui->listWidget_MonthlyPayment->addItem(item);
  }
  ui->doubleSpinBox_TotalPayment->setValue(total_payment);
  ui->doubleSpinBox_Overpayment->setValue(overpayment_on_credit);
}

void CreditWindow::on_pushButton_Calculate_clicked() {
  try {
    controller_credit_->CalculateCredit(this);
  } catch (const std::exception &e) {
    QMessageBox::critical(this, "Warning", e.what());
  }
}

void CreditWindow::on_pushButton_Clear_clicked() {
  SetDefault(*ui->doubleSpinBox_TotalCreditAmount);
  SetDefault(*ui->doubleSpinBox_InterestRate);
  SetDefault(*ui->doubleSpinBox_Overpayment);
  SetDefault(*ui->doubleSpinBox_TotalPayment);
  SetDefault(*ui->spinBox_Term);
  ui->listWidget_MonthlyPayment->clear();
  ui->comboBox_Term->setCurrentIndex(0);
  ui->comboBox_Type->setCurrentIndex(0);
}

void CreditWindow::on_comboBox_Term_currentIndexChanged(int index) {
  if (index == 0)
    ui->spinBox_Term->setMaximum(600);
  if (index == 1)
    ui->spinBox_Term->setMaximum(50);
}

void CreditWindow::SetDefault(QSpinBox &sb) { sb.setValue(sb.minimum()); }

void CreditWindow::SetDefault(QDoubleSpinBox &sb) { sb.setValue(sb.minimum()); }

}; // namespace MyNamespace
