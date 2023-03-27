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
  connect(ui->toolButton_x, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_0, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_1, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_2, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_3, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_4, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_5, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_6, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_7, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_8, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_9, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_point, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_E, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_add, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_sub, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_mult, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_div, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_acos, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_asin, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_atan, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_cos, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_sin, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_tan, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_pi, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_ln, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_log, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_exp, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_mod, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_power, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_sqrt, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_qbrt, SIGNAL(clicked()), this, SLOT(input_buttons()));
  connect(ui->toolButton_openBracket, SIGNAL(clicked()), this,
          SLOT(input_buttons()));
  connect(ui->toolButton_closeBracket, SIGNAL(clicked()), this,
          SLOT(input_buttons()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::SetController(Controller *c) { controller_ = c; }

std::string MainWindow::GetInputString() {
  return ui->lineEdit_iuput->text().toStdString();
}

std::string MainWindow::GetInputStringX() {
  return ui->lineEdit_input_x->text().toStdString();
}

void MainWindow::SetAnswer(double x) {
  ui->lineEdit_output->setText(QString::number(x, 'g', 8));
}

void MainWindow::input_buttons() {
  QToolButton *button = (QToolButton *)sender();
  ui->lineEdit_iuput->insert(button->text());
}

void MainWindow::on_toolButton_equal_clicked() { Calculate(); }

void MainWindow::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Return) Calculate();
}

void MainWindow::Calculate() {
  try {
    controller_->CalculateValue(this);
  } catch (const std::exception &e) {
    QMessageBox::critical(this, "Warning", e.what());
  }
}

void MainWindow::on_toolButton_deleteAll_clicked() {
  ui->lineEdit_iuput->clear();
}

void MainWindow::on_toolButton_backspace_clicked() {
  ui->lineEdit_iuput->backspace();
}

void MainWindow::on_actionEngineer_Calculator_triggered() {
  Credit->hide();
  Graph->hide();
  Deposit->hide();
  this->show();
}

void MainWindow::on_actionCredit_Calculator_triggered() {
  Credit->SetController(this->controller_);
  this->hide();
  Graph->hide();
  Deposit->hide();
  Credit->show();
}

void MainWindow::on_actionDeposit_Calculator_triggered() {
  Deposit->SetController(this->controller_);
  this->hide();
  Graph->hide();
  Credit->hide();
  Deposit->show();
}

void MainWindow::on_actionGraph_View_triggered() {
  Graph->SetExpression(ui->lineEdit_iuput->text());  // TODO connect
  Graph->SetController(this->controller_);
  this->hide();
  Deposit->hide();
  Credit->hide();
  Graph->show();
}

void MainWindow::SetExpression(QString expression) {
  ui->lineEdit_iuput->setText(expression);
}
