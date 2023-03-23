#include "credit.h"

#include <cmath>
#include <tuple>

double round_2dd(double value) { return round(value * 100) / 100.; }

void Credit::LoadData(int type, double total_credit_amount, int term,
                      double interest_rate) {
  type_ = type;
  total_credit_amount_ = total_credit_amount;
  term_ = term;
  interest_rate_ = interest_rate;
  monthly_payment_.clear();
  overpayment_on_credit_ = 0;
  total_payment_ = 0;
}

void Credit::AnnuityCredit() {
  double interest_rate_temp = interest_rate_ / 12.0 / 100.0;
  double core = powl((1.0 + interest_rate_temp), term_);

  monthly_payment_.push_back(round_2dd(
      total_credit_amount_ * ((interest_rate_temp * core) / (core - 1.0))));
  total_payment_ = monthly_payment_.back() * term_;
  overpayment_on_credit_ = total_payment_ - total_credit_amount_;
}

void Credit::DifferentiatedCredit() {
  double interest_rate_temp = interest_rate_ / 12.0 / 100.0;
  double core = total_credit_amount_ / term_;

  for (int i = 0; i < term_; ++i) {
    monthly_payment_.push_back(round_2dd(
        core + ((total_credit_amount_ - core * i) * interest_rate_temp)));
    total_payment_ += monthly_payment_.back();
  }

  overpayment_on_credit_ = total_payment_ - total_credit_amount_;
}

void Credit::CalculateCredit(int type, double total_credit_amount, int term,
                             double interest_rate) {
  LoadData(type, total_credit_amount, term, interest_rate);
  if (type) {
    DifferentiatedCredit();
  } else {
    AnnuityCredit();
  }
}

std::vector<double> Credit::GetMonthlyPayment() { return monthly_payment_; }

double Credit::GetTotalPayment() { return total_payment_; }

double Credit::GetOverpaymentOnCredit() { return overpayment_on_credit_; }
