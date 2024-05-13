#include "creditcalculator.h"

#include <cmath>
#include <vector>

#include "round.h"

void MyNamespace::CreditCalculator::LoadData(int type_of_monthly_payments,
                                             double total_credit_amount,
                                             int term, double interest_rate) {
  type_of_monthly_payments_ = type_of_monthly_payments;
  total_credit_amount_ = total_credit_amount;
  term_ = term;
  interest_rate_ = interest_rate;
  monthly_payment_.clear();
  overpayment_on_credit_ = 0;
  total_payment_ = 0;
}

void MyNamespace::CreditCalculator::CalculateAnnuityCredit() {
  double interest_rate_temp = interest_rate_ / 12.0 / 100.0;
  double core = powl((1.0 + interest_rate_temp), term_);

  monthly_payment_.push_back(RoundToTwoDecimalPlaces(
      total_credit_amount_ * ((interest_rate_temp * core) / (core - 1.0))));
  total_payment_ = monthly_payment_.back() * term_;
  overpayment_on_credit_ = total_payment_ - total_credit_amount_;
}

void MyNamespace::CreditCalculator::CalculateDifferentiatedCredit() {
  double interest_rate_temp = interest_rate_ / 12.0 / 100.0;
  double core = total_credit_amount_ / term_;

  for (int i = 0; i < term_; ++i) {
    monthly_payment_.push_back(RoundToTwoDecimalPlaces(
        core + ((total_credit_amount_ - core * i) * interest_rate_temp)));
    total_payment_ += monthly_payment_.back();
  }

  overpayment_on_credit_ = total_payment_ - total_credit_amount_;
}

void MyNamespace::CreditCalculator::CalculateCredit(
    int type_of_monthly_payments, double total_credit_amount, int term,
    double interest_rate) {
  LoadData(type_of_monthly_payments, total_credit_amount, term, interest_rate);
  if (type_of_monthly_payments_ ==
      MyNamespace::TypeOfMonthlyPayments::kAnnuity) {
    CalculateAnnuityCredit();
  } else {
    CalculateDifferentiatedCredit();
  }
}

std::vector<double> MyNamespace::CreditCalculator::GetMonthlyPayment() const {
  return monthly_payment_;
}

double MyNamespace::CreditCalculator::GetTotalPayment() const {
  return total_payment_;
}

double MyNamespace::CreditCalculator::GetOverpaymentOnCredit() const {
  return overpayment_on_credit_;
}
