#include "deposit.h"

#include <cmath>

double round_2d(double value) { return round(value * 100) / 100.; }

void Deposit::CalculateDeposit(
    double deposit_amount, Date start_of_term, int placement_period,
    int placement_period_type, double interest_rate, double tax_rate,
    int periodicity_of_payments, bool capitalization_of_interest,
    std::multimap<Date, double> replenishments_list,
    std::multimap<Date, double> partial_withdrawals_list) {
  LoadDepositData(deposit_amount, start_of_term, placement_period,
                  placement_period_type, interest_rate, tax_rate,
                  periodicity_of_payments, capitalization_of_interest,
                  replenishments_list, partial_withdrawals_list);
  Calculation();
}

double Deposit::GetAccruedInterest() { return accrued_interest_; }
double Deposit::GetTaxAmount() { return tax_amount_; }
double Deposit::GetDepositAmountByTheEndOfTheTerm() {
  return deposit_amount_by_the_end_of_the_term_;
}

void Deposit::LoadDepositData(
    double deposit_amount, Date start_of_term, int placement_period,
    int placement_period_type, double interest_rate, double tax_rate,
    int periodicity_of_payments, bool capitalization_of_interest,
    std::multimap<Date, double> replenishments_list,
    std::multimap<Date, double> partial_withdrawals_list) {
  deposit_amount_ = deposit_amount;
  start_of_term_ = start_of_term;
  end_of_term_ = start_of_term_;
  switch (placement_period_type) {
    case 0:
      end_of_term_.AddDays(placement_period);
      break;
    case 1:
      end_of_term_.AddMonths(placement_period);
      break;
    case 2:
      end_of_term_.AddYears(placement_period);
      break;
  }
  interest_rate_ = interest_rate;
  tax_rate_ = tax_rate;
  periodicity_of_payments_ = periodicity_of_payments;
  capitalization_of_interest_ = capitalization_of_interest;
  replenishments_list_ = replenishments_list;
  partial_withdrawals_list_ = partial_withdrawals_list;
  current_date_ = start_of_term;
  payment_date_ = start_of_term;
  accrued_interest_receivable_ = 0;
  accrued_interest_ = 0;
  tax_amount_ = 0;
  deposit_amount_by_the_end_of_the_term_ = 0;
}

void Deposit::Calculation() {
  double start_deposit = deposit_amount_;
  current_date_.AddDays(1);
  SetNextPaymentDate();
  while (current_date_ <= end_of_term_) {
    CheckPaymentDate();
    AddAccruedInterest();
    CheckReplenishmentsList();
    CheckPartialWithdrawalsList();
    current_date_.AddDays(1);
  }
  accrued_interest_ =
      accrued_interest_receivable_ + deposit_amount_ - start_deposit;
  deposit_amount_by_the_end_of_the_term_ = deposit_amount_;
  tax_amount_ = round_2d(accrued_interest_ * tax_rate_ / 100.);
}

void Deposit::SetNextPaymentDate() {
  switch (periodicity_of_payments_) {
    case PeriodicityOfPayments::kDaily:
      payment_date_.AddDays(1);
      break;
    case PeriodicityOfPayments::kWeekly:
      payment_date_.AddDays(7);
      break;
    case PeriodicityOfPayments::kMonthly:
      payment_date_.AddMonths(1);
      break;
    case PeriodicityOfPayments::kQuarterOfTheYear:
      payment_date_.AddMonths(3);
      break;
    case PeriodicityOfPayments::kHalfYear:
      payment_date_.AddMonths(6);
      break;
    case PeriodicityOfPayments::kAnnualy:
      payment_date_.AddYears(1);
      break;
    case PeriodicityOfPayments::kEndOfTerm:
      payment_date_ = end_of_term_;
      break;
    default:
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
      deposit_amount_ += accrued_interest_;
    } else {
      accrued_interest_receivable_ += accrued_interest_;
    }
    accrued_interest_ = 0;
    SetNextPaymentDate();
  }
}

void Deposit::AddAccruedInterest() {
  accrued_interest_ += round_2d(deposit_amount_ * interest_rate_ / 100.0 /
                                current_date_.DaysInYear());
}

void Deposit::CheckReplenishmentsList() {
  auto it = replenishments_list_.find(current_date_);
  while (it != replenishments_list_.end()) {
    deposit_amount_ += it->second;
    replenishments_list_.erase(it);
    it = replenishments_list_.find(current_date_);
  }
}

void Deposit::CheckPartialWithdrawalsList() {
  auto it = partial_withdrawals_list_.find(current_date_);
  while (it != partial_withdrawals_list_.end()) {
    deposit_amount_ -= it->second;
    if (deposit_amount_ < 0) {
      deposit_amount_ = 0;  //!
    }
    partial_withdrawals_list_.erase(it);
    it = partial_withdrawals_list_.find(current_date_);
  }
}
