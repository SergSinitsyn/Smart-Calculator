#include "credit.h"

#include <cmath>
#include <tuple>

void MyNamespace::Credit::LoadData(int type, double total_credit_amount,
                                   int term, double interest_rate) {
  type_ = type;
  total_credit_amount_ = total_credit_amount;
  term_ = term;
  interest_rate_ = interest_rate;
  monthly_payment_.clear();
  overpayment_on_credit_ = 0;
  total_payment_ = 0;
}

void MyNamespace::Credit::CalculateAnnuityCredit() {
  double interest_rate_temp = interest_rate_ / 12.0 / 100.0;
  double core = powl((1.0 + interest_rate_temp), term_);

  monthly_payment_.push_back(RoundToTwoDecimalPlaces(
      total_credit_amount_ * ((interest_rate_temp * core) / (core - 1.0))));
  total_payment_ = monthly_payment_.back() * term_;
  overpayment_on_credit_ = total_payment_ - total_credit_amount_;
}

void MyNamespace::Credit::CalculateDifferentiatedCredit() {
  double interest_rate_temp = interest_rate_ / 12.0 / 100.0;
  double core = total_credit_amount_ / term_;

  for (int i = 0; i < term_; ++i) {
    monthly_payment_.push_back(RoundToTwoDecimalPlaces(
        core + ((total_credit_amount_ - core * i) * interest_rate_temp)));
    total_payment_ += monthly_payment_.back();
  }

  overpayment_on_credit_ = total_payment_ - total_credit_amount_;
}

void MyNamespace::Credit::CalculateCredit(int type, double total_credit_amount,
                                          int term, double interest_rate) {
  LoadData(type, total_credit_amount, term, interest_rate);
  if (type_) {
    CalculateDifferentiatedCredit();
  } else {
    CalculateAnnuityCredit();
  }
}

std::vector<double> MyNamespace::Credit::GetMonthlyPayment() const {
  return monthly_payment_;
}

double MyNamespace::Credit::GetTotalPayment() const { return total_payment_; }

double MyNamespace::Credit::GetOverpaymentOnCredit() const {
  return overpayment_on_credit_;
}
