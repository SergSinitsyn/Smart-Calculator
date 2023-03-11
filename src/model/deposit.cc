#include "deposit.h"

#include <cmath>
#include <string>

double round_2digit(double value) { return round(value * 100) / 100.; }

Deposit::Deposit(double deposit_amount, Date start_date, Date end_date,
                 double interest_rate, double tax_rate,
                 PeriodicityOfPayments periodicity_of_payments,
                 bool capitalization_of_interest,
                 std::map<Date, double> replenishments_list,
                 std::map<Date, double> partial_withdrawals_list)
    : deposit_amount_{deposit_amount},
      start_date_{start_date},
      end_date_{end_date},
      interest_rate_{interest_rate},
      tax_rate_{tax_rate},
      periodicity_of_payments_{periodicity_of_payments},
      capitalization_of_interest_{capitalization_of_interest},
      replenishments_list_{replenishments_list},
      partial_withdrawals_list_{partial_withdrawals_list},
      current_date_{start_date},
      capitalisation_date_{start_date},
      accrued_interest_{0},
      tax_amount_{0},
      deposit_amount_by_the_end_of_the_term_{0} {};

std::tuple<double, double, double> Deposit::CalculateDeposit() {
  if (!capitalization_of_interest_) {
    periodicity_of_payments_ = PeriodicityOfPayments::kEndOfTerm;
  }
  double start_deposit_ = deposit_amount_;
  current_date_.Add(1, 0, 0);
  int count = 1;  // capitalisation count
  SetNextCapitalizationDate(count);
  while (current_date_ <= end_date_) {
    // сheck capitalisation_date_
    if (current_date_ == capitalisation_date_) {
      deposit_amount_ += accrued_interest_;
      accrued_interest_ = 0;
      SetNextCapitalizationDate(count);
    }
    // add accrued interest every day
    accrued_interest_ += round_2digit(deposit_amount_ * interest_rate_ / 100.0 /
                                      current_date_.DaysInYear());
    // сheck replenishments_list_
    if (auto it = replenishments_list_.find(current_date_);
        it != replenishments_list_.end()) {
      deposit_amount_ += it->second;
      replenishments_list_.erase(it);
    }
    // сheck partial_withdrawals_list_
    if (auto it = partial_withdrawals_list_.find(current_date_);
        it != partial_withdrawals_list_.end()) {
      deposit_amount_ -= it->second;
      if (deposit_amount_ < 0) {
        throw std::logic_error("The withdrawal amount " +
                               std::to_string(it->second) +
                               " exceeds the current deposit amount by " +
                               std::to_string(deposit_amount_));
      }
      partial_withdrawals_list_.erase(it);
    }
    // go to next day
    current_date_.Add(1, 0, 0);
  }
  accrued_interest_ = deposit_amount_ - start_deposit_;
  deposit_amount_by_the_end_of_the_term_ = deposit_amount_;
  tax_amount_ = round_2digit(accrued_interest_ * tax_rate_ / 100.);
  return std::make_tuple(accrued_interest_, tax_amount_,
                         deposit_amount_by_the_end_of_the_term_);
}

void Deposit::SetNextCapitalizationDate(int& count) {
  Date temp = start_date_;
  switch (periodicity_of_payments_) {
    case PeriodicityOfPayments::kDaily:
      temp.Add(count, 0, 0);
      break;
    case PeriodicityOfPayments::kWeekly:
      temp.Add(7 * count, 0, 0);
      break;
    case PeriodicityOfPayments::kMonthly:
      temp.Add(0, count, 0);
      while (temp.GetMonth() % 12 != (start_date_.GetMonth() + 1) % 12) {
        temp.Add(-1, 0, 0);
      }
      break;
    case PeriodicityOfPayments::kQuarterOfTheYear:
      temp.Add(0, 3 * count, 0);
      while (temp.GetMonth() % 12 != (start_date_.GetMonth() + 3) % 12) {
        temp.Add(-1, 0, 0);
      }
      break;
    case PeriodicityOfPayments::kHalfYear:
      temp.Add(0, 6 * count, 0);
      while (temp.GetMonth() % 12 != (start_date_.GetMonth() + 6) % 12) {
        temp.Add(-1, 0, 0);
      }
      break;
    case PeriodicityOfPayments::kAnnualy:  //!
      temp.Add(0, 0, count);
      while (temp.GetMonth() != start_date_.GetMonth()) {
        temp.Add(-1, 0, 0);
      }
      break;
    case PeriodicityOfPayments::kEndOfTerm:
      temp = end_date_;
      break;
    default:
      temp = end_date_;
      break;
  }
  count++;
  capitalisation_date_ = temp;
  if (capitalisation_date_ > end_date_) {
    capitalisation_date_ = end_date_;
  }
}