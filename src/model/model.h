#ifndef _MODEL_MODEL_H_
#define _MODEL_MODEL_H_

#include "calculator.h"
#include "credit.h"
#include "deposit.h"

class Model {
 public:
  Model() = default;
  ~Model() = default;

  std::pair<double, std::string> Calculate(std::string str);
  std::pair<double, std::string> Calculate(std::string str, double x);
  std::pair<XYGraph, std::string> CalculateGraph(std::string str, int size,
                                                 double start, double end);

  std::tuple<std::vector<double>, double, double> CalculateCredit(
      double total_credit_amount, double term, double interest_rate, int type);

  std::pair<std::tuple<double, double, double>, std::string> CalculateDeposit(
      double deposit_amount_, Date start_date_, Date end_date_,
      double interest_rate_, double tax_rate_,
      PeriodicityOfPayments periodicity_of_payments_,
      bool capitalization_of_interest_,
      std::map<Date, double> replenishments_list_,
      std::map<Date, double> partial_withdrawals_list_);
};

#endif  // _MODEL_MODEL_H_
