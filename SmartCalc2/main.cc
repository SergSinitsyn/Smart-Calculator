#include <QApplication>

#include "controller/controller.h"
#include "model/credit.h"
#include "model/deposit.h"
#include "model/mathcalculator.h"
#include "view/mainwindow.h"

int main(int argc, char *argv[]) {
  using namespace MyNamespace;
  QApplication a(argc, argv);
  MathCalculator model_math;
  Credit model_credit;
  Deposit model_deposit;
  Controller ctrl(&model_math, &model_credit, &model_deposit);
  MainWindow main_window;
  main_window.SetController(&ctrl);
  main_window.show();
  return a.exec();
}
