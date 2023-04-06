#include "controller.h"

#include <string>

Controller::Controller(MathCalculator *m1, Credit *m2, Deposit *m3)
    : model_math(m1), model_credit(m2), model_deposit(m3){};

Controller::~Controller(){};

void Controller::CalculateValue(MainWindow *w) {
  model_math->CalculateAnswer(w->GetInputString(), w->GetInputStringX());
  w->SetAnswer(model_math->GetAnswer());
}

void Controller::CalculateGraph(GraphWindow *g) {
  model_math->CalculateGraph(g->GetInputString(), 10000, g->GetMinX(),
                             g->GetMaxX());
  g->SetGraph(model_math->GetGraph());
}

void Controller::CalculateCredit(CreditWindow *c) {
  model_credit->CalculateCredit(c->GetCreditType(), c->GetTotalCreditAmount(),
                                c->GetTerm(), c->GetInterestRate());
  c->SetAnswer(model_credit->GetTotalPayment(),
               model_credit->GetOverpaymentOnCredit(),
               model_credit->GetMonthlyPayment());
}

void Controller::CalculateDeposit(DepositWindow *d) {
  Date start_of_term(d->GetStartOfTerm().day(), d->GetStartOfTerm().month() - 1,
                     d->GetStartOfTerm().year());
  model_deposit->CalculateDeposit(
      d->GetDepositAmount(), start_of_term, d->GetPlacementPeriod(),
      d->GetPlacementPeriodType(), d->GetInterestRate(), d->GetTaxRate(),
      d->GetPeriodicityOfPayments(), d->GetCapitalisationOfInterest(),
      d->GetReplenishmentsList(), d->GetPartialWithdrawalsList(),
      d->GetMinimumBalance());

  d->SetAnswer(model_deposit->GetDepositAmountByTheEndOfTheTerm(),
               model_deposit->GetAccruedInterest(),
               model_deposit->GetTaxAmount());
}
