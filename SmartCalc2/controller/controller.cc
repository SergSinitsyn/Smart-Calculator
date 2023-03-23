#include "controller.h"

#include <string>

Controller::Controller(MathCalculator *m1, Credit *m2, Deposit *m3)
    : model_math(m1), model_credit(m2), model_deposit(m3){};

Controller::~Controller(){};

void Controller::CalculateValue(MainWindow *w) {
  model_math->CalculateAnswer(w->GetInputString(), w->GetInputStringX());
  w->SetAnswer(model_math->GetAnswer());
}

void Controller::CalculateCredit(CreditWindow *c) {
  model_credit->CalculateCredit(c->GetCreditType(), c->GetTotalCreditAmount(),
                                c->GetTerm(), c->GetInterestRate());
  c->SetAnswer(model_credit->GetTotalPayment(),
               model_credit->GetOverpaymentOnCredit(),
               model_credit->GetMonthlyPayment());
}
