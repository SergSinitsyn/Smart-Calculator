#include "mainwindow.h"

#include "../../controller/controller.h"
#include "ui_mainwindow.h"

namespace MyNamespace {
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      credit_view_(new CreditWindow()),
      deposit_view_(new DepositWindow()),
      graph_view_(new GraphWindow()) {
  ui->setupUi(this);
  ConnectInputButtons();
  ConnectInputButtonsExtra();
  connect(this, &MainWindow::SendExpressionToGraph, graph_view_,
          &GraphWindow::TakeExpressionFromCalc);
  connect(graph_view_, &GraphWindow::SendExpressionToCalc, this,
          &MainWindow::TakeExpressionFromGraph);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::SetController(MyNamespace::Controller *c) { controller_ = c; }

std::string MainWindow::GetInputString() const {
  return ui->lineEdit_input->text().toStdString();
}

std::string MainWindow::GetInputStringX() const {
  return ui->lineEdit_input_x->text().toStdString();
}

void MainWindow::SetAnswer(double x) {
  ui->lineEdit_output->setText(QString::number(x, 'g', 16));
}

void MainWindow::ConnectInputButtons() {
  QVector<QToolButton *> buttons = {
      ui->toolButton_x,           ui->toolButton_0,
      ui->toolButton_1,           ui->toolButton_2,
      ui->toolButton_3,           ui->toolButton_4,
      ui->toolButton_5,           ui->toolButton_6,
      ui->toolButton_7,           ui->toolButton_8,
      ui->toolButton_9,           ui->toolButton_point,
      ui->toolButton_E,           ui->toolButton_add,
      ui->toolButton_sub,         ui->toolButton_mult,
      ui->toolButton_div,         ui->toolButton_pi,
      ui->toolButton_mod,         ui->toolButton_power,
      ui->toolButton_openBracket, ui->toolButton_closeBracket};
  for (auto it = buttons.begin(); it != buttons.end(); ++it) {
    connect(*it, SIGNAL(clicked()), this, SLOT(InputButtons()));
  }
}

void MainWindow::ConnectInputButtonsExtra() {
  QVector<QToolButton *> buttons_extra = {
      ui->toolButton_acos, ui->toolButton_asin, ui->toolButton_atan,
      ui->toolButton_cos,  ui->toolButton_sin,  ui->toolButton_tan,
      ui->toolButton_ln,   ui->toolButton_log,  ui->toolButton_exp,
      ui->toolButton_sqrt, ui->toolButton_cbrt};
  for (auto it = buttons_extra.begin(); it != buttons_extra.end(); it++) {
    connect(*it, SIGNAL(clicked()), this, SLOT(InputButtonsWithBrakets()));
  }
}

void MainWindow::HideAllWindows() {
  this->hide();
  graph_view_->hide();
  credit_view_->hide();
  deposit_view_->hide();
}

QLineEdit *MainWindow::LineOnFocus() {
  if (ui->lineEdit_input_x->hasFocus()) {
    return ui->lineEdit_input_x;
  }
  return ui->lineEdit_input;
}

void MainWindow::TakeExpressionFromGraph(QString expression) {
  ui->lineEdit_input->blockSignals(true);
  ui->lineEdit_input->setText(expression);
  ui->lineEdit_input->blockSignals(false);
}

void MainWindow::InputButtons() {
  QToolButton *button = (QToolButton *)sender();
  LineOnFocus()->insert(button->text());
}

void MainWindow::InputButtonsWithBrakets() {
  QToolButton *button = (QToolButton *)sender();
  LineOnFocus()->insert(button->text() + "()");
  LineOnFocus()->setCursorPosition(LineOnFocus()->cursorPosition() - 1);
}

void MainWindow::on_toolButton_equal_clicked() {
  try {
    controller_->CalculateValue(this);
  } catch (const std::exception &e) {
    QMessageBox::critical(this, "Warning", e.what());
  }
}

void MainWindow::on_toolButton_all_clean_clicked() { LineOnFocus()->clear(); }

void MainWindow::on_toolButton_backspace_clicked() {
  LineOnFocus()->backspace();
}

void MainWindow::on_actionEngineer_Calculator_triggered() {
  HideAllWindows();
  this->show();
}

void MainWindow::on_actionGraph_View_triggered() {
  graph_view_->SetController(this->controller_);
  HideAllWindows();
  graph_view_->show();
}

void MainWindow::on_actionCredit_Calculator_triggered() {
  credit_view_->SetController(this->controller_);
  HideAllWindows();
  credit_view_->show();
}

void MainWindow::on_actionDeposit_Calculator_triggered() {
  deposit_view_->SetController(this->controller_);
  HideAllWindows();
  deposit_view_->show();
}

void MainWindow::on_lineEdit_input_textChanged(const QString &arg) {
  emit SendExpressionToGraph(arg);
}
};  // namespace MyNamespace
