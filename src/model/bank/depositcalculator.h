#ifndef SMARTCALC_MODEL_BANK_DEPOSITCALCULATOR_H_
#define SMARTCALC_MODEL_BANK_DEPOSITCALCULATOR_H_

#include <map>
#include <string>

#include "date.h"

namespace MyNamespace {
std::string FromDoubleToString(double value);

enum DateType {
  kDays,
  kMonths,
  kYears,
};

enum PeriodicityOfPayments {
  kDaily,
  kWeekly,
  kMonthly,
  kQuarterOfTheYear,
  kHalfYear,
  kAnnualy,
  kEndOfTerm,
};

enum Periodicity {
  kOneTime,
  kPerWeek,
  kPerMonth,
  kPerYear,
};

class DepositCalculator {
public:
  using MultiMapDate = std::multimap<Date, std::pair<int, double>>;
  struct DepositInputData {
    double deposit_amount;
    const Date &start_of_term;
    int placement_period;
    int placement_period_type;
    double interest_rate;
    double tax_rate;
    int periodicity_of_payments;
    bool capitalization_of_interest;
    const MultiMapDate &replenishments_list;
    const MultiMapDate &partial_withdrawals_list;
    double minimum_balance;
  };

  DepositCalculator() = default;
  ~DepositCalculator() = default;
  void CalculateDeposit(const DepositInputData &InputData);
  long double GetAccruedInterest() const;
  long double GetTaxAmount() const;
  long double GetDepositAmountByTheEndOfTheTerm() const;

private:
  void LoadDepositData(const DepositInputData &InputData);
  void Calculation();
  void SetNextPaymentDate();
  void CheckPaymentDate();
  void AddAccruedInterest();
  void CheckReplenishmentsList();
  void CheckPartialWithdrawalsList();
  void SetNextDate(int type, Date &date);

  // input data
  double deposit_amount_{};
  Date start_of_term_{};
  double interest_rate_{};
  double tax_rate_{};
  int periodicity_of_payments_{};
  bool capitalization_of_interest_{};
  MultiMapDate replenishments_list_{};
  MultiMapDate partial_withdrawals_list_{};
  double minimum_balance_{};

  // temp data
  Date end_of_term_{};
  Date current_date_{};
  Date payment_date_{};
  long double accrued_interest_receivable_{};
  double start_deposit_{};

  // output data
  long double accrued_interest_{};
  long double tax_amount_{};
  long double deposit_amount_by_the_end_of_the_term_{};
};

}; // namespace MyNamespace

#endif // SMARTCALC_MODEL_BANK_DEPOSITCALCULATOR_H_
