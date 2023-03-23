#ifndef _CONTROLLER_CONTROLLER_H_
#define _CONTROLLER_CONTROLLER_H_

#include "../view/mainwindow.h"
#include "../model/mathcalculator.h"
#include "../model/credit.h"
#include "../model/deposit.h"

class Controller {
public:
  Controller(MathCalculator* m1, Credit* m2, Deposit* m3);
 ~Controller();
  void CalculateValue(MainWindow* w);
  void CalculateCredit(CreditWindow* c);

private:
    MathCalculator* model_math;
    Credit* model_credit;
    Deposit* model_deposit;
};



#endif // _CONTROLLER_CONTROLLER_H_
