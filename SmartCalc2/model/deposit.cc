#include "deposit.h"

#include <cmath>

double round_2d(double value) { return round(value * 100) / 100.; }

// Deposit::Deposit(double deposit_amount, Date start_date, Date end_date,
//                  double interest_rate, double tax_rate,
//                  PeriodicityOfPayments periodicity_of_payments,
//                  bool capitalization_of_interest,
//                  std::map<Date, double> replenishments_list,
//                  std::map<Date, double> partial_withdrawals_list)
//     : deposit_amount_{deposit_amount},
//       start_date_{start_date},
//       end_date_{end_date},
//       interest_rate_{interest_rate},
//       tax_rate_{tax_rate},
//       periodicity_of_payments_{periodicity_of_payments},
//       capitalization_of_interest_{capitalization_of_interest},
//       replenishments_list_{replenishments_list},
//       partial_withdrawals_list_{partial_withdrawals_list},
//       current_date_{start_date},
//       capitalisation_date_{start_date},
//       accrued_interest_{0},
//       tax_amount_{0},
//       deposit_amount_by_the_end_of_the_term_{0} {};

void Deposit::CalculateDeposit(
    double deposit_amount, Date start_of_term, int placement_period,
    int placement_period_type, double interest_rate, double tax_rate,
    PeriodicityOfPayments periodicity_of_payments,
    bool capitalization_of_interest,
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
    PeriodicityOfPayments periodicity_of_payments,
    bool capitalization_of_interest,
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
  capitalisation_date_ = start_of_term;
  accrued_interest_ = 0;
  tax_amount_ = 0;
  deposit_amount_by_the_end_of_the_term_ = 0;
}

void Deposit::SetNextCapitalizationDate() {
  switch (periodicity_of_payments_) {
    case PeriodicityOfPayments::kDaily:
      capitalisation_date_.AddDays(1);
      break;
    case PeriodicityOfPayments::kWeekly:
      capitalisation_date_.AddDays(7);
      break;
    case PeriodicityOfPayments::kMonthly:
      capitalisation_date_.AddMonths(1);
      break;
    case PeriodicityOfPayments::kQuarterOfTheYear:
      capitalisation_date_.AddMonths(3);
      break;
    case PeriodicityOfPayments::kHalfYear:
      capitalisation_date_.AddMonths(6);
      break;
    case PeriodicityOfPayments::kAnnualy:
      capitalisation_date_.AddYears(1);
      break;
    case PeriodicityOfPayments::kEndOfTerm:
      capitalisation_date_ = end_of_term_;
      break;
    default:
      capitalisation_date_ = end_of_term_;
      break;
  }
  if (capitalisation_date_ > end_of_term_) {
    capitalisation_date_ = end_of_term_;
  }
}

void Deposit::Calculation() {
  if (!capitalization_of_interest_) {
    periodicity_of_payments_ = PeriodicityOfPayments::kEndOfTerm;
  }
  double start_deposit_ = deposit_amount_;
  current_date_.AddDays(1);
  SetNextCapitalizationDate();
  while (current_date_ <= end_of_term_) {
    // сheck capitalisation_date_
    CheckCapitalisationDate();  //!
    if (current_date_ == capitalisation_date_) {
      deposit_amount_ += accrued_interest_;
      accrued_interest_ = 0;
      SetNextCapitalizationDate();
    }

    // add accrued interest every day
    AddAccruedInterest();  //!
    accrued_interest_ += round_2d(deposit_amount_ * interest_rate_ / 100.0 /
                                  current_date_.DaysInYear());
    // сheck replenishments_list_
    CheckReplenishmentsList();  //!
    auto it1 = replenishments_list_.find(current_date_);
    while (it1 != replenishments_list_.end()) {
      deposit_amount_ += it1->second;
      replenishments_list_.erase(it1);
      it1 = replenishments_list_.find(current_date_);
    }
    // сheck partial_withdrawals_list_
    CheckPartialWithdrawalsList();  //!
    auto it2 = partial_withdrawals_list_.find(current_date_);
    while (it2 != partial_withdrawals_list_.end()) {
      deposit_amount_ -= it2->second;
      if (deposit_amount_ < 0) {
        deposit_amount_ = 0;  //!
      }
      partial_withdrawals_list_.erase(it2);
      it2 = partial_withdrawals_list_.find(current_date_);
    }
    // go to next day
    current_date_.AddDays(1);
  }
  accrued_interest_ = deposit_amount_ - start_deposit_;
  deposit_amount_by_the_end_of_the_term_ = deposit_amount_;
  tax_amount_ = round_2d(accrued_interest_ * tax_rate_ / 100.);
}
