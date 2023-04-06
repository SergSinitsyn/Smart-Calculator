#include "deposit.h"

#include <cmath>
#include <sstream>
#include <string>

double round_2d(double value) { return round(value * 100.) / 100.; }

std::string FromDoubleToString(double value) {
  std::stringstream ss;
  ss << value;
  std::string str = ss.str();
  return str;
}

void Deposit::CalculateDeposit(double deposit_amount, Date start_of_term,
                               int placement_period, int placement_period_type,
                               double interest_rate, double tax_rate,
                               int periodicity_of_payments,
                               bool capitalization_of_interest,
                               MAP replenishments_list,
                               MAP partial_withdrawals_list,
                               double minimum_balance) {
  LoadDepositData(deposit_amount, start_of_term, placement_period,
                  placement_period_type, interest_rate, tax_rate,
                  periodicity_of_payments, capitalization_of_interest,
                  replenishments_list, partial_withdrawals_list,
                  minimum_balance);
  Calculation();
}

long double Deposit::GetAccruedInterest() { return accrued_interest_; }
double Deposit::GetTaxAmount() { return tax_amount_; }
double Deposit::GetDepositAmountByTheEndOfTheTerm() {
  return deposit_amount_by_the_end_of_the_term_;
}

void Deposit::LoadDepositData(double deposit_amount, Date start_of_term,
                              int placement_period, int placement_period_type,
                              double interest_rate, double tax_rate,
                              int periodicity_of_payments,
                              bool capitalization_of_interest,
                              MAP replenishments_list,
                              MAP partial_withdrawals_list,
                              double minimum_balance) {
  deposit_amount_ = deposit_amount;
  start_deposit_ = deposit_amount_;
  total_withdrawal_ = 0;
  start_of_term_ = start_of_term;
  end_of_term_ = start_of_term;
  switch (placement_period_type) {
    case 0:  // days
      end_of_term_.AddDays(placement_period);
      break;
    case 1:  // months
      end_of_term_.AddMonths(placement_period);
      break;
    case 2:  // years
      end_of_term_.AddYears(placement_period);
      break;
  }
  interest_rate_ = interest_rate;
  tax_rate_ = tax_rate;
  periodicity_of_payments_ = periodicity_of_payments;
  capitalization_of_interest_ = capitalization_of_interest;
  replenishments_list_ = replenishments_list;
  partial_withdrawals_list_ = partial_withdrawals_list;
  minimum_balance_ = minimum_balance;
  current_date_ = start_of_term;
  payment_date_ = start_of_term;
  accrued_interest_receivable_ = 0.;
  accrued_interest_ = 0.;
  tax_amount_ = 0.;
  deposit_amount_by_the_end_of_the_term_ = 0.;
}

void Deposit::Calculation() {
  CheckReplenishmentsList();
  CheckPartialWithdrawalsList();
  SetNextPaymentDate();
  current_date_.AddDays(1);
  while (current_date_ <= end_of_term_) {
    AddAccruedInterest();
    CheckPaymentDate();
    CheckReplenishmentsList();
    CheckPartialWithdrawalsList();
    current_date_.AddDays(1);
  }
  accrued_interest_ =
      accrued_interest_receivable_ + deposit_amount_ - start_deposit_;
  deposit_amount_by_the_end_of_the_term_ = deposit_amount_;
  tax_amount_ =
      round_2d((accrued_interest_ + total_withdrawal_) * tax_rate_ / 100.);
}

void Deposit::SetNextPaymentDate() {
  switch (periodicity_of_payments_) {
    case kDaily:
      payment_date_.AddDays(1);
      break;
    case kWeekly:
      payment_date_.AddDays(7);
      break;
    case kMonthly:
      payment_date_.AddMonths(1);
      break;
    case kQuarterOfTheYear:
      payment_date_.AddMonths(3);
      break;
    case kHalfYear:
      payment_date_.AddMonths(6);
      break;
    case kAnnualy:
      payment_date_.AddYears(1);
      break;
    case kEndOfTerm:
      payment_date_ = end_of_term_;
      break;
  }
  if (payment_date_ > end_of_term_) {
    payment_date_ = end_of_term_;
  }
}

void Deposit::CheckPaymentDate() {
  if (current_date_ == payment_date_) {
    if (capitalization_of_interest_) {
      deposit_amount_ += round_2d(accrued_interest_);
    } else {
      accrued_interest_receivable_ += round_2d(accrued_interest_);
    }
    accrued_interest_ = 0;
    SetNextPaymentDate();
  }
}

void Deposit::AddAccruedInterest() {
  accrued_interest_ += deposit_amount_ * interest_rate_ / 100.0 /
                       (double)current_date_.DaysInYear();
}

void Deposit::CheckReplenishmentsList() {
  auto replenishment = replenishments_list_.find(current_date_);
  while (replenishment != replenishments_list_.end()) {
    Date date = replenishment->first;
    int type = replenishment->second.first;
    double value = replenishment->second.second;
    deposit_amount_ += value;
    start_deposit_ += value;
    switch (type) {
      case 0:  // one-time
        break;
      case 1:  // weekly
        date.AddDays(7);
        break;
      case 2:  // monthly
        date.AddMonths(1);
        break;
      case 3:  // annually
        date.AddYears(1);
        break;
    }
    replenishments_list_.erase(replenishment);
    if (type) {
      replenishments_list_.insert(
          std::make_pair(date, std::make_pair(type, value)));
    }
    replenishment = replenishments_list_.find(current_date_);
  }
}

void Deposit::CheckPartialWithdrawalsList() {
  auto partial_withdrawal = partial_withdrawals_list_.find(current_date_);
  while (partial_withdrawal != partial_withdrawals_list_.end()) {
    Date date = partial_withdrawal->first;
    int type = partial_withdrawal->second.first;
    double value = partial_withdrawal->second.second;
    deposit_amount_ -= value;
    if (deposit_amount_ <= minimum_balance_) {
      throw std::logic_error(
          FromDoubleToString(date.GetDay()) + "/" +
          FromDoubleToString(date.GetMonth() + 1) + "/" +
          FromDoubleToString(date.GetYear()) + "\n" +
          "withdrawal in the amount of " + FromDoubleToString(value) + "\n" +
          "was not made due to" + "\n" + "the size of the minimum balance of " +
          FromDoubleToString(minimum_balance_));
    }
    start_deposit_ -= value;
    total_withdrawal_ += value;
    switch (type) {
      case 0:  // one-time
        break;
      case 1:  // weekly
        date.AddDays(7);
        break;
      case 2:  // monthly
        date.AddMonths(1);
        break;
      case 3:  // annually
        date.AddYears(1);
        break;
    }
    partial_withdrawals_list_.erase(partial_withdrawal);
    if (type) {
      partial_withdrawals_list_.insert(
          std::make_pair(date, std::make_pair(type, value)));
    }
    partial_withdrawal = partial_withdrawals_list_.find(current_date_);
  }
}
