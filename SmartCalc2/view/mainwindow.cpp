#include "mainwindow.h"

#include "../controller/controller.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      Credit(new CreditWindow()),
      Deposit(new DepositWindow()),
      Graph(new GraphWindow())

{
  ui->setupUi(this);
  ConnectInputButtons();
  ConnectInputButtonsExtra();
  connect(this, &MainWindow::SendExpressionToGraph, Graph,
          &GraphWindow::TakeExpressionFromCalc);
  connect(Graph, &GraphWindow::SendExpressionToCalc, this,
          &MainWindow::TakeExpressionFromGraph);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::SetController(Controller *c) { controller_ = c; }

std::string MainWindow::GetInputString() {
  return ui->lineEdit_input->text().toStdString();
}

std::string MainWindow::GetInputStringX() {
  return ui->lineEdit_input_x->text().toStdString();
}

void MainWindow::SetAnswer(double x) {
  ui->lineEdit_output->setText(QString::number(x, 'g', 8));
}

void MainWindow::TakeExpressionFromGraph(QString expression) {
  ui->lineEdit_input->setText(expression);
}

void MainWindow::input_buttons() {
  QToolButton *button = (QToolButton *)sender();
  LineOnFocus()->insert(button->text());
}

void MainWindow::input_buttons_extra() {
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
  for (auto it = buttons.begin(); it < buttons.end(); it++) {
    connect(*it, SIGNAL(clicked()), this, SLOT(input_buttons()));
  }
}

void MainWindow::ConnectInputButtonsExtra() {
  QVector<QToolButton *> buttons_extra = {
      ui->toolButton_acos, ui->toolButton_asin, ui->toolButton_atan,
      ui->toolButton_cos,  ui->toolButton_sin,  ui->toolButton_tan,
      ui->toolButton_ln,   ui->toolButton_log,  ui->toolButton_exp,
      ui->toolButton_sqrt, ui->toolButton_qbrt,
  };
  for (auto it = buttons_extra.begin(); it < buttons_extra.end(); it++) {
    connect(*it, SIGNAL(clicked()), this, SLOT(input_buttons_extra()));
  }
}

QLineEdit *MainWindow::LineOnFocus() {
  if (ui->lineEdit_input_x->hasFocus()) {
    return ui->lineEdit_input_x;
  }
  return ui->lineEdit_input;
}

void MainWindow::HideAllWindows() {
  this->hide();
  Credit->hide();
  Graph->hide();
  Deposit->hide();
}

void MainWindow::on_toolButton_deleteAll_clicked() { LineOnFocus()->clear(); }

void MainWindow::on_toolButton_backspace_clicked() {
  LineOnFocus()->backspace();
}

void MainWindow::on_actionEngineer_Calculator_triggered() {
  HideAllWindows();
  this->show();
}

void MainWindow::on_actionCredit_Calculator_triggered() {
  Credit->SetController(this->controller_);
  HideAllWindows();
  Credit->show();
}

void MainWindow::on_actionDeposit_Calculator_triggered() {
  Deposit->SetController(this->controller_);
  HideAllWindows();
  Deposit->show();
}

void MainWindow::on_actionGraph_View_triggered() {
  Graph->SetController(this->controller_);
  HideAllWindows();
  Graph->show();
}

void MainWindow::on_lineEdit_input_textChanged(const QString &arg) {
  emit SendExpressionToGraph(arg);
}
