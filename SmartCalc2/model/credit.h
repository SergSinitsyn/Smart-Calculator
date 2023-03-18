#ifndef _MODEL_CREDIT_H_
#define _MODEL_CREDIT_H_

#include <vector>

class Credit {
 public:
//  Credit(double total_credit_amount, double term, double interest_rate);
   Credit() = default;
  ~Credit() = default;
  void  LoadData(double total_credit_amount, double term, double interest_rate);
  std::tuple<std::vector<double>, double, double> AnnuityCredit();
  std::tuple<std::vector<double>, double, double> DifferentiatedCredit();

 private:
  double total_credit_amount_;
  double term_;
  double interest_rate_;
  std::vector<double> monthly_payment_;
  double overpayment_on_credit_;
  double total_payment_;
};

#endif  // _MODEL_CREDIT_H_
