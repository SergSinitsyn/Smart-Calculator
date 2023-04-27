#ifndef SMARTCALC_CONTROLLER_CONTROLLER_H_
#define SMARTCALC_CONTROLLER_CONTROLLER_H_

#include "../model/bank/creditcalculator.h"
#include "../model/bank/depositcalculator.h"
#include "../model/math/mathcalculator.h"
#include "../view/mainwindow.h"

namespace MyNamespace {
class Controller {
 public:
  Controller(MathCalculator* model_1, CreditCalculator* model_2,
             DepositCalculator* model_3);
  ~Controller();
  void CalculateValue(MainWindow* mw);
  void CalculateGraph(GraphWindow* gw);
  void CalculateCredit(CreditWindow* cw);
  void CalculateDeposit(DepositWindow* dw);

 private:
  MathCalculator* model_math_;
  CreditCalculator* model_credit_;
  DepositCalculator* model_deposit_;

  Date ConvertDate(QDate old) const;
  DepositCalculator::MultiMapDate ConvertDateMap(MultiMapQDate old) const;
};
};  // namespace MyNamespace

#endif  // SMARTCALC_CONTROLLER_CONTROLLER_H_
