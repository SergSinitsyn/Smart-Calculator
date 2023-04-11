#include "controller.h"

#include <string>

Controller::Controller(MathCalculator *model_1, Credit *model_2,
                       Deposit *model_3)
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
  Date start_of_term(dw->GetStartOfTerm().day(),
                     dw->GetStartOfTerm().month() - 1,
                     dw->GetStartOfTerm().year());
  model_deposit_->CalculateDeposit(
      dw->GetDepositAmount(), start_of_term, dw->GetPlacementPeriod(),
      dw->GetPlacementPeriodType(), dw->GetInterestRate(), dw->GetTaxRate(),
      dw->GetPeriodicityOfPayments(), dw->GetCapitalisationOfInterest(),
      dw->GetReplenishmentsList(), dw->GetPartialWithdrawalsList(),
      dw->GetMinimumBalance());

  dw->SetAnswer(model_deposit_->GetDepositAmountByTheEndOfTheTerm(),
                model_deposit_->GetAccruedInterest(),
                model_deposit_->GetTaxAmount());
}
