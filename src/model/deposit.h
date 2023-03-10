#ifndef _MODEL_DEPOSIT_H_
#define _MODEL_DEPOSIT_H_

#include <map>

#include "date.h"

enum PeriodicityOfPayments {
  kDaily,
  kWeekly,
  kMonthly,
  kQuarterOfTheYear,
  kHalfYear,
  kAnnualy,
  kEndOfTerm,
};

class Deposit {
 public:
  Deposit() = default;
  ~Deposit() = default;

  void SetNextCapitalizationDate();
  void CalculateDeposit();

 private:
  double deposit_amount_;                          // in
  double interest_rate_;                           // in
  double tax_rate_;                                // in
  PeriodicityOfPayments periodicity_of_payments_;  // in
  bool capitalization_of_interest_;                // in
  // true(periodicity_of_payments_)
  // fasle(periodicity_of_payments_ = kEndOfTerm)

  Date start_date_;  // in
  Date end_date_;    // in

  std::map<Date, double> replenishments_list_;
  std::map<Date, double> partial_withdrawals_list_;

  Date current_date_;
  Date capitalisation_date_;

  double accrued_interest_{};                       // out
  double tax_amount_{};                             // out
  double deposit_amount_by_the_end_of_the_term_{};  // out
};

#endif  // _MODEL_DEPOSIT_H_
