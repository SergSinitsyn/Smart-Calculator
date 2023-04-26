#include "controller.h"

#include <string>

namespace MyNamespace {
Controller::Controller(MathCalculator *model_1, CreditCalculator *model_2,
                       DepositCalculator *model_3)
    : model_math_(model_1), model_credit_(model_2), model_deposit_(model_3){};

Controller::~Controller(){};

void Controller::CalculateValue(MainWindow *mw) {
  model_math_->CalculateAnswer(mw->GetInputString(), mw->GetInputStringX());
  mw->SetAnswer(model_math_->GetAnswer());
}

void Controller::CalculateGraph(GraphWindow *gw) {
  model_math_->CalculateGraph(gw->GetInputString(), gw->GetResolution(),
                              gw->GetMinX(), gw->GetMaxX(), gw->GetMinY(),
                              gw->GetMaxY());
  gw->SetGraph(model_math_->GetGraph());
}

void Controller::CalculateCredit(CreditWindow *cw) {
  model_credit_->CalculateCredit(cw->GetCreditType(),
                                 cw->GetTotalCreditAmount(), cw->GetTerm(),
                                 cw->GetInterestRate());
  cw->SetAnswer(model_credit_->GetTotalPayment(),
                model_credit_->GetOverpaymentOnCredit(),
                model_credit_->GetMonthlyPayment());
}

void Controller::CalculateDeposit(DepositWindow *dw) {
  model_deposit_->CalculateDeposit(
      dw->GetDepositAmount(), ConvertDate(dw->GetStartOfTerm()),
      dw->GetPlacementPeriod(), dw->GetPlacementPeriodType(),
      dw->GetInterestRate(), dw->GetTaxRate(), dw->GetPeriodicityOfPayments(),
      dw->GetCapitalisationOfInterest(),
      ConvertDateMap(dw->GetReplenishmentsList()),
      ConvertDateMap(dw->GetPartialWithdrawalsList()), dw->GetMinimumBalance());

  dw->SetAnswer(model_deposit_->GetDepositAmountByTheEndOfTheTerm(),
                model_deposit_->GetAccruedInterest(),
                model_deposit_->GetTaxAmount());
}

Date Controller::ConvertDate(QDate old) const {
  Date result(old.day(), old.month() - 1, old.year());
  return result;
}

DepositCalculator::MultiMapDate Controller::ConvertDateMap(MultiMapQDate old) const {
  DepositCalculator::MultiMapDate result;
  for (auto it = old.begin(); it != old.end(); ++it) {
    result.insert(std::make_pair(ConvertDate(it->first), it->second));
  }
  return result;
}

};  // namespace MyNamespace
