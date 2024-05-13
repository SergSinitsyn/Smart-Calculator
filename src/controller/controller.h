#ifndef SMARTCALC_CONTROLLER_CONTROLLER_H_
#define SMARTCALC_CONTROLLER_CONTROLLER_H_

#include "../model/bank/creditcalculator.h"
#include "../model/bank/depositcalculator.h"
#include "../model/math/math_calculator.h"
#include "../view//math/mainwindow.h"

namespace MyNamespace {
class Controller {
public:
  Controller(MathCalculator *model_1, CreditCalculator *model_2,
             DepositCalculator *model_3);
  ~Controller();
  void CalculateValue(MainWindow *main_window);
  void CalculateGraph(GraphWindow *graph_window);
  void CalculateCredit(CreditWindow *credit_window);
  void CalculateDeposit(DepositWindow *deposit_window);

private:
  MathCalculator *model_math_;
  CreditCalculator *model_credit_;
  DepositCalculator *model_deposit_;

  Date ConvertDate(QDate old) const;
  DepositCalculator::MultiMapDate ConvertDateMap(MultiMapQDate old) const;
};
}; // namespace MyNamespace

#endif // SMARTCALC_CONTROLLER_CONTROLLER_H_
