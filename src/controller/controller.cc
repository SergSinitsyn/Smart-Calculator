#include "controller.h"

#include <string>

namespace MyNamespace {
Controller::Controller(MathCalculator *model_1, CreditCalculator *model_2,
                       DepositCalculator *model_3)
    : model_math_(model_1), model_credit_(model_2), model_deposit_(model_3){};

Controller::~Controller(){};

void Controller::CalculateValue(MainWindow *main_window) {
  model_math_->CalculateAnswer(main_window->GetInputString(),
                               main_window->GetInputStringX());
  main_window->SetAnswer(model_math_->GetAnswer());
}

void Controller::CalculateGraph(GraphWindow *graph_window) {
  model_math_->CalculateGraph(graph_window->GetInputString(),
                              graph_window->GetResolution(),
                              graph_window->GetMinX(), graph_window->GetMaxX(),
                              graph_window->GetMinY(), graph_window->GetMaxY());
  graph_window->SetGraph(model_math_->GetGraph());
}

void Controller::CalculateCredit(CreditWindow *credit_window) {
  model_credit_->CalculateCredit(
      credit_window->GetCreditType(), credit_window->GetTotalCreditAmount(),
      credit_window->GetTerm(), credit_window->GetInterestRate());
  credit_window->SetAnswer(model_credit_->GetTotalPayment(),
                           model_credit_->GetOverpaymentOnCredit(),
                           model_credit_->GetMonthlyPayment());
}

void Controller::CalculateDeposit(DepositWindow *deposit_window) {
  model_deposit_->CalculateDeposit(DepositCalculator::DepositInputData{
      deposit_window->GetDepositAmount(),
      ConvertDate(deposit_window->GetStartOfTerm()),
      deposit_window->GetPlacementPeriod(),
      deposit_window->GetPlacementPeriodType(),
      deposit_window->GetInterestRate(), deposit_window->GetTaxRate(),
      deposit_window->GetPeriodicityOfPayments(),
      deposit_window->GetCapitalisationOfInterest(),
      ConvertDateMap(deposit_window->GetReplenishmentsList()),
      ConvertDateMap(deposit_window->GetPartialWithdrawalsList()),
      deposit_window->GetMinimumBalance()});
  deposit_window->SetAnswer(model_deposit_->GetDepositAmountByTheEndOfTheTerm(),
                            model_deposit_->GetAccruedInterest(),
                            model_deposit_->GetTaxAmount());
}

Date Controller::ConvertDate(QDate old) const {
  Date result(old.day(), old.month() - 1, old.year());
  return result;
}

DepositCalculator::MultiMapDate Controller::ConvertDateMap(
    MultiMapQDate old) const {
  DepositCalculator::MultiMapDate result;
  for (auto it = old.begin(); it != old.end(); ++it) {
    result.insert(std::make_pair(ConvertDate(it->first), it->second));
  }
  return result;
}

};  // namespace MyNamespace
