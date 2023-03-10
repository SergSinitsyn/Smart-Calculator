#include "deposit.h"

#include <cmath>

double round_2d(double value) { return round(value * 100) / 100.; }

void Deposit::SetNextCapitalizationDate() {
  Date temp = capitalisation_date_;
  switch (periodicity_of_payments_) {
    case PeriodicityOfPayments::kDaily:
      temp.Add(1, 0, 0);
      break;
    case PeriodicityOfPayments::kWeekly:
      temp.Add(7, 0, 0);
      break;
    case PeriodicityOfPayments::kMonthly:
      temp.Add(0, 1, 0);
      while (temp.GetMonth() % 12 !=
             (capitalisation_date_.GetMonth() + 1) % 12) {
        temp.Add(-1, 0, 0);
      }
      break;
    case PeriodicityOfPayments::kQuarterOfTheYear:
      temp.Add(0, 3, 0);
      while (temp.GetMonth() % 12 !=
             (capitalisation_date_.GetMonth() + 3) % 12) {
        temp.Add(-1, 0, 0);
      }
      break;
    case PeriodicityOfPayments::kHalfYear:
      temp.Add(0, 6, 0);
      while (temp.GetMonth() % 12 !=
             (capitalisation_date_.GetMonth() + 6) % 12) {
        temp.Add(-1, 0, 0);
      }
      break;
    case PeriodicityOfPayments::kAnnualy:
      temp.Add(0, 0, 1);
      while (temp.GetMonth() != capitalisation_date_.GetMonth()) {
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

  capitalisation_date_ = temp;
  if (capitalisation_date_ > end_date_) {
    capitalisation_date_ = end_date_;
  }
}

void Deposit::CalculateDeposit() {
  current_date_.Add(1, 0, 0);
  double start_deposit_ = deposit_amount_;
  SetNextCapitalizationDate();

  while (current_date_ <= end_date_) {
    // сheck capitalisation_date_
    if (current_date_ == capitalisation_date_) {
      deposit_amount_ += accrued_interest_;
      accrued_interest_ = 0;
      SetNextCapitalizationDate();
    }

    // add % every day
    accrued_interest_ += round_2d(deposit_amount_ * interest_rate_ / 100.0 /
                                  current_date_.DaysInYear());

    // сheck replenishments_list_ and partial_withdrawals_list_
    if (auto it = replenishments_list_.find(current_date_);
        it != replenishments_list_.end()) {
      deposit_amount_ += it->second;
      replenishments_list_.erase(it);
    }
    if (auto it = partial_withdrawals_list_.find(current_date_);
        it != partial_withdrawals_list_.end()) {
      deposit_amount_ -= it->second;
      if (deposit_amount_ < 0) deposit_amount_ = 0;  //!
      partial_withdrawals_list_.erase(it);
    }

    // add day
    current_date_.Add(1, 0, 0);
  }

  accrued_interest_ = deposit_amount_ - start_deposit_;
  deposit_amount_by_the_end_of_the_term_ = deposit_amount_;
  tax_amount_ = round_2d(accrued_interest_ * tax_rate_ / 100.);
}