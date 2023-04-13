#ifndef _CONTROLLER_CONTROLLER_H_
#define _CONTROLLER_CONTROLLER_H_

#include "../model/credit.h"
#include "../model/deposit.h"
#include "../model/mathcalculator.h"
#include "../view/mainwindow.h"

namespace MyNamespace {
class Controller {
 public:
  Controller(MathCalculator* model_1, Credit* model_2, Deposit* model_3);
  ~Controller();
  void CalculateValue(MainWindow* mw);
  void CalculateGraph(GraphWindow* gw);
  void CalculateCredit(CreditWindow* cw);
  void CalculateDeposit(DepositWindow* dw);

 private:
  MathCalculator* model_math_;
  Credit* model_credit_;
  Deposit* model_deposit_;

  Date ConvertDate(QDate old) const;
  Deposit::MultiMapDate ConvertDateMap(MultiMapQDate old) const;
};
};  // namespace MyNamespace

#endif  // _CONTROLLER_CONTROLLER_H_
