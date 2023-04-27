#include "depositcalculator.h"

#include <cmath>
#include <map>
#include <sstream>
#include <string>

#include "round.h"

std::string MyNamespace::FromDoubleToString(double value) {
  std::stringstream ss;
  ss << value;
  std::string str = ss.str();
  return str;
}

void MyNamespace::DepositCalculator::CalculateDeposit(
    DepositInputData InputData) {
  LoadDepositData(InputData);
  Calculation();
}

long double MyNamespace::DepositCalculator::GetAccruedInterest() const {
  return accrued_interest_;
}

long double MyNamespace::DepositCalculator::GetTaxAmount() const {
  return tax_amount_;
}

long double MyNamespace::DepositCalculator::GetDepositAmountByTheEndOfTheTerm()
    const {
  return deposit_amount_by_the_end_of_the_term_;
}

void MyNamespace::DepositCalculator::LoadDepositData(
    DepositInputData InputData) {
  deposit_amount_ = InputData.deposit_amount;
  start_deposit_ = deposit_amount_;
  start_of_term_ = InputData.start_of_term;
  end_of_term_ = InputData.start_of_term;
  switch (InputData.placement_period_type) {
    case DateType::kDays:
      end_of_term_.AddDays(InputData.placement_period);
      break;
    case DateType::kMonths:
      end_of_term_.AddMonths(InputData.placement_period);
      break;
    case DateType::kYears:
      end_of_term_.AddYears(InputData.placement_period);
      break;
  }
  interest_rate_ = InputData.interest_rate;
  tax_rate_ = InputData.tax_rate;
  periodicity_of_payments_ = InputData.periodicity_of_payments;
  capitalization_of_interest_ = InputData.capitalization_of_interest;
  replenishments_list_ = InputData.replenishments_list;
  partial_withdrawals_list_ = InputData.partial_withdrawals_list;
  minimum_balance_ = InputData.minimum_balance;
  current_date_ = InputData.start_of_term;
  payment_date_ = InputData.start_of_term;
  accrued_interest_receivable_ = 0.;
  accrued_interest_ = 0.;
  tax_amount_ = 0.;
  deposit_amount_by_the_end_of_the_term_ = 0.;
}

void MyNamespace::DepositCalculator::Calculation() {
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
  tax_amount_ = RoundToTwoDecimalPlaces((accrued_interest_)*tax_rate_ / 100.);
}

void MyNamespace::DepositCalculator::SetNextPaymentDate() {
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
  }
  if (payment_date_ > end_of_term_) {
    payment_date_ = end_of_term_;
  }
}

void MyNamespace::DepositCalculator::CheckPaymentDate() {
  if (current_date_ == payment_date_) {
    if (capitalization_of_interest_) {
      deposit_amount_ += RoundToTwoDecimalPlaces(accrued_interest_);
    } else {
      accrued_interest_receivable_ +=
          RoundToTwoDecimalPlaces(accrued_interest_);
    }
    accrued_interest_ = 0;
    SetNextPaymentDate();
  }
}

void MyNamespace::DepositCalculator::AddAccruedInterest() {
  accrued_interest_ +=
      deposit_amount_ * interest_rate_ / 100.0 / current_date_.DaysInYear();
}

void MyNamespace::DepositCalculator::CheckReplenishmentsList() {
  auto replenishment = replenishments_list_.find(current_date_);
  while (replenishment != replenishments_list_.end()) {
    Date date = replenishment->first;
    int periodicity_type = replenishment->second.first;
    double value = replenishment->second.second;
    deposit_amount_ += value;
    start_deposit_ += value;
    SetNextDate(periodicity_type, date);
    replenishments_list_.erase(replenishment);
    if (periodicity_type) {
      replenishments_list_.insert(
          std::make_pair(date, std::make_pair(periodicity_type, value)));
    }
    replenishment = replenishments_list_.find(current_date_);
  }
}

void MyNamespace::DepositCalculator::CheckPartialWithdrawalsList() {
  auto partial_withdrawal = partial_withdrawals_list_.find(current_date_);
  while (partial_withdrawal != partial_withdrawals_list_.end()) {
    Date date = partial_withdrawal->first;
    int periodicity_type = partial_withdrawal->second.first;
    double value = partial_withdrawal->second.second;
    deposit_amount_ -= value;
    if (deposit_amount_ < minimum_balance_) {
      throw std::logic_error(
          FromDoubleToString(date.GetDay()) + "/" +
          FromDoubleToString(date.GetMonth() + 1) + "/" +
          FromDoubleToString(date.GetYear()) + "\n" +
          "withdrawal in the amount of " + FromDoubleToString(value) + "\n" +
          "was not made due to" + "\n" + "the size of the minimum balance of " +
          FromDoubleToString(minimum_balance_));
    }
    start_deposit_ -= value;
    SetNextDate(periodicity_type, date);
    partial_withdrawals_list_.erase(partial_withdrawal);
    if (periodicity_type) {
      partial_withdrawals_list_.insert(
          std::make_pair(date, std::make_pair(periodicity_type, value)));
    }
    partial_withdrawal = partial_withdrawals_list_.find(current_date_);
  }
}

void MyNamespace::DepositCalculator::SetNextDate(int periodicity_type,
                                                 Date &date) {
  switch (periodicity_type) {
    case Periodicity::kOneTime:
      break;
    case Periodicity::kPerWeek:
      date.AddDays(7);
      break;
    case Periodicity::kPerMonth:
      date.AddMonths(1);
      break;
    case Periodicity::kPerYear:
      date.AddYears(1);
      break;
  }
}
