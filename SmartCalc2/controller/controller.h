#ifndef _CONTROLLER_CONTROLLER_H_
#define _CONTROLLER_CONTROLLER_H_

#include "../model/credit.h"
#include "../model/deposit.h"
#include "../model/mathcalculator.h"
#include "../view/mainwindow.h"

class Controller {
 public:
  Controller(MathCalculator* m1, Credit* m2, Deposit* m3);
  ~Controller();
  void CalculateValue(MainWindow* w);
  void CalculateGraph(GraphWindow* g);
  void CalculateCredit(CreditWindow* c);
  void CalculateDeposit(DepositWindow* d);

 private:
  MathCalculator* model_math;
  Credit* model_credit;
  Deposit* model_deposit;
};

#endif  // _CONTROLLER_CONTROLLER_H_
