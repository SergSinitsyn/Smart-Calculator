#include "model.h"

std::pair<double, std::string> Model::Calculate(std::string str) {
  return this->Calculate(str, 0.);
}

std::pair<double, std::string> Model::Calculate(std::string str, double x) {
  Calculator A;
  double result = 777;
  std::string error_message = "";
  try {
    A.LoadExpression(str);
    result = A.CalculateValue(x);
  } catch (const std::exception& e) {
    error_message = e.what();
  }
  return make_pair(result, error_message);
}

std::pair<XYGraph, std::string> Model::CalculateGraph(std::string str, int size,
                                                      double start,
                                                      double end) {
  Calculator A;
  XYGraph result{0, 0};
  std::string error_message = "";
  try {
    A.LoadExpression(str);
    result = A.CalculateGraph(size, start, end);
  } catch (const std::exception& e) {
    error_message = e.what();
  }
  return make_pair(result, error_message);
}

std::tuple<std::vector<double>, double, double> Model::CalculateCredit(
    double total_credit_amount, double term, double interest_rate, int type) {
  Credit C(total_credit_amount, term, interest_rate);
  return type ? C.DifferentiatedCredit() : C.AnnuityCredit();
}

std::pair<std::tuple<double, double, double>, std::string>
Model::CalculateDeposit(double deposit_amount_, Date start_date_,
                        Date end_date_, double interest_rate_, double tax_rate_,
                        PeriodicityOfPayments periodicity_of_payments_,
                        bool capitalization_of_interest_,
                        std::map<Date, double> replenishments_list_,
                        std::map<Date, double> partial_withdrawals_list_) {
  Deposit D(deposit_amount_, start_date_, end_date_, interest_rate_, tax_rate_,
            periodicity_of_payments_, capitalization_of_interest_,
            replenishments_list_, partial_withdrawals_list_);
  std::tuple<double, double, double> result = {0, 0, 0};
  std::string error_message = "";

  try {
    result = D.CalculateDeposit();
  } catch (const std::exception& e) {
    error_message = e.what();
  }
  return make_pair(result, error_message);
}
