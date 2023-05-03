#include <QApplication>

#include "controller/controller.h"
#include "model/bank/creditcalculator.h"
#include "model/bank/depositcalculator.h"
#include "model/math/mathcalculator.h"
#include "view/math/mainwindow.h"

int main(int argc, char *argv[]) {
  using namespace MyNamespace;
  QApplication application(argc, argv);
  MathCalculator model_math;
  CreditCalculator model_credit;
  DepositCalculator model_deposit;
  Controller controller(&model_math, &model_credit, &model_deposit);
  MainWindow main_window;
  main_window.SetController(&controller);
  main_window.show();
  return application.exec();
}
