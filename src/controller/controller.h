#ifndef SMARTCALC_CONTROLLER_CONTROLLER_H_
#define SMARTCALC_CONTROLLER_CONTROLLER_H_

#include "../model/bank/creditcalculator.h"
#include "../model/bank/depositcalculator.h"
#include "../model/math/math_calculator.h"
#include "../view/math/mainwindow.h"

namespace MyNamespace {
class Controller {
 public:
  Controller(MathCalculator &, CreditCalculator &, DepositCalculator &);
  ~Controller();
  void CalculateValue(MainWindow *main_window);
  void CalculateGraph(GraphWindow *graph_window);
  void CalculateCredit(CreditWindow *credit_window);
  void CalculateDeposit(DepositWindow *deposit_window);

 private:
  std::unique_ptr<MathCalculator> model_math_;
  std::unique_ptr<CreditCalculator> model_credit_;
  std::unique_ptr<DepositCalculator> model_deposit_;

  Date ConvertDate(QDate old) const;
  DepositCalculator::MultiMapDate ConvertDateMap(MultiMapQDate old) const;
};
};  // namespace MyNamespace

#endif  // SMARTCALC_CONTROLLER_CONTROLLER_H_
