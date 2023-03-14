#include "credit.h"

#include <cmath>
#include <tuple>

double round_2dd(double value) { return round(value * 100) / 100.; }

Credit::Credit(double total_credit_amount, double term, double interest_rate)
    : total_credit_amount_{total_credit_amount},
      term_{term},
      interest_rate_{interest_rate},
      monthly_payment_{},
      overpayment_on_credit_{},
      total_payment_{} {}

std::tuple<double, double, double> Credit::AnnuityCredit() {
  double interest_rate_temp = interest_rate_ / 12.0 / 100.0;
  double core = powl((1.0 + interest_rate_temp), term_);

  monthly_payment_ = round_2dd(total_credit_amount_ *
                               ((interest_rate_temp * core) / (core - 1.0)));
  total_payment_ = monthly_payment_ * term_;
  overpayment_on_credit_ = total_payment_ - total_credit_amount_;
  return std::make_tuple(monthly_payment_, overpayment_on_credit_,
                         total_payment_);
}

std::tuple<std::vector<double>, double, double> Credit::DifferentiatedCredit() {
  double interest_rate_temp = interest_rate_ / 12.0 / 100.0;
  double core = total_credit_amount_ / term_;

  for (int i = 0; i < term_; ++i) {
    monthly_payment_diff_[i] = round_2dd(
        core + ((total_credit_amount_ - core * i) * interest_rate_temp));
  }
  total_payment_ = 0;
  for (int i = 0; i < term_; ++i) {
    total_payment_ += monthly_payment_diff_[i];
  }
  overpayment_on_credit_ = total_payment_ - total_credit_amount_;
  return std::make_tuple(monthly_payment_diff_, overpayment_on_credit_,
                         total_payment_);
}