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
  //  Deposit(double deposit_amount, Date start_date, Date end_date,
  //          double interest_rate, double tax_rate,
  //          PeriodicityOfPayments periodicity_of_payments,
  //          bool capitalization_of_interest,
  //          std::map<Date, double> replenishments_list,
  //          std::map<Date, double> partial_withdrawals_list);
  ~Deposit() = default;

  void CalculateDeposit(double deposit_amount, Date start_of_term,
                        int placement_period, int placement_period_type,
                        double interest_rate, double tax_rate,
                        PeriodicityOfPayments periodicity_of_payments,
                        bool capitalization_of_interest,
                        std::multimap<Date, double> replenishments_list,
                        std::multimap<Date, double> partial_withdrawals_list);

  double GetAccruedInterest();
  double GetTaxAmount();
  double GetDepositAmountByTheEndOfTheTerm();

 private:
  void LoadDepositData(double deposit_amount, Date start_date,
                       int placement_period, int placement_period_type,
                       double interest_rate, double tax_rate,
                       PeriodicityOfPayments periodicity_of_payments,
                       bool capitalization_of_interest,
                       std::multimap<Date, double> replenishments_list,
                       std::multimap<Date, double> partial_withdrawals_list);
  void Calculation();
  void SetNextCapitalizationDate();
  void CheckCapitalisationDate();      //!
  void AddAccruedInterest();           //!
  void CheckReplenishmentsList();      //!
  void CheckPartialWithdrawalsList();  //!

  // input data
  double deposit_amount_;
  Date start_of_term_;
  Date end_of_term_;
  double interest_rate_;
  double tax_rate_;
  PeriodicityOfPayments periodicity_of_payments_;
  bool capitalization_of_interest_;
  std::multimap<Date, double> replenishments_list_;
  std::multimap<Date, double> partial_withdrawals_list_;

  // temp data
  Date current_date_;
  Date capitalisation_date_;

  // output data
  double accrued_interest_;
  double tax_amount_;
  double deposit_amount_by_the_end_of_the_term_;
};

#endif  // _MODEL_DEPOSIT_H_
