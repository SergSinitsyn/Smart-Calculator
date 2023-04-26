#include "deposit.h"

std::string MyNamespace::FromDoubleToString(double value) {
  std::stringstream ss;
  ss << value;
  std::string str = ss.str();
  return str;
}

void MyNamespace::Deposit::CalculateDeposit(
    double deposit_amount, const Date &start_of_term, int placement_period,
    int placement_period_type, double interest_rate, double tax_rate,
    int periodicity_of_payments, bool capitalization_of_interest,
    const MultiMapDate &replenishments_list,
    const MultiMapDate &partial_withdrawals_list, double minimum_balance) {
  LoadDepositData(deposit_amount, start_of_term, placement_period,
                  placement_period_type, interest_rate, tax_rate,
                  periodicity_of_payments, capitalization_of_interest,
                  replenishments_list, partial_withdrawals_list,
                  minimum_balance);
  Calculation();
}

long double MyNamespace::Deposit::GetAccruedInterest() const {
  return accrued_interest_;
}

long double MyNamespace::Deposit::GetTaxAmount() const { return tax_amount_; }

long double MyNamespace::Deposit::GetDepositAmountByTheEndOfTheTerm() const {
  return deposit_amount_by_the_end_of_the_term_;
}

void MyNamespace::Deposit::LoadDepositData(
    double deposit_amount, const Date &start_of_term, int placement_period,
    int placement_period_type, double interest_rate, double tax_rate,
    int periodicity_of_payments, bool capitalization_of_interest,
    const MultiMapDate &replenishments_list,
    const MultiMapDate &partial_withdrawals_list, double minimum_balance) {
  deposit_amount_ = deposit_amount;
  start_deposit_ = deposit_amount_;
  start_of_term_ = start_of_term;
  end_of_term_ = start_of_term;
  switch (placement_period_type) {
    case DateType::kDays:
      end_of_term_.AddDays(placement_period);
      break;
    case DateType::kMonths:
      end_of_term_.AddMonths(placement_period);
      break;
    case DateType::kYears:
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

void MyNamespace::Deposit::Calculation() {
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

void MyNamespace::Deposit::SetNextPaymentDate() {
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

void MyNamespace::Deposit::CheckPaymentDate() {
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

void MyNamespace::Deposit::AddAccruedInterest() {
  accrued_interest_ += deposit_amount_ * interest_rate_ / 100.0 /
                       (double)current_date_.DaysInYear();
}

void MyNamespace::Deposit::CheckReplenishmentsList() {
  auto replenishment = replenishments_list_.find(current_date_);
  while (replenishment != replenishments_list_.end()) {
    Date date = replenishment->first;
    int type = replenishment->second.first;
    double value = replenishment->second.second;
    deposit_amount_ += value;
    start_deposit_ += value;
    SetNextDate(type, date);
    replenishments_list_.erase(replenishment);
    if (type) {
      replenishments_list_.insert(
          std::make_pair(date, std::make_pair(type, value)));
    }
    replenishment = replenishments_list_.find(current_date_);
  }
}

void MyNamespace::Deposit::CheckPartialWithdrawalsList() {
  auto partial_withdrawal = partial_withdrawals_list_.find(current_date_);
  while (partial_withdrawal != partial_withdrawals_list_.end()) {
    Date date = partial_withdrawal->first;
    int type = partial_withdrawal->second.first;
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
    SetNextDate(type, date);
    partial_withdrawals_list_.erase(partial_withdrawal);
    if (type) {
      partial_withdrawals_list_.insert(
          std::make_pair(date, std::make_pair(type, value)));
    }
    partial_withdrawal = partial_withdrawals_list_.find(current_date_);
  }
}

void MyNamespace::Deposit::SetNextDate(int type, Date &date) {
  switch (type) {
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