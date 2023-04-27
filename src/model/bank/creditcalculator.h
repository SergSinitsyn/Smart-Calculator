#ifndef _MODEL_CREDIT_H_
#define _MODEL_CREDIT_H_

#include <vector>

#include "round.h"
namespace MyNamespace {

enum TypeOfMonthlyPayments {
  kAnnuity = 0,
  kDifferentiated,
};

class CreditCalculator {
 public:
  CreditCalculator() = default;
  ~CreditCalculator() = default;
  void CalculateCredit(int type_of_monthly_payments, double total_credit_amount,
                       int term, double interest_rate);
  std::vector<double> GetMonthlyPayment() const;
  double GetTotalPayment() const;
  double GetOverpaymentOnCredit() const;

 private:
  void LoadData(int type_of_monthly_payments, double total_credit_amount,
                int term, double interest_rate);
  void CalculateAnnuityCredit();
  void CalculateDifferentiatedCredit();

  int type_of_monthly_payments_;
  double total_credit_amount_;
  double term_;
  double interest_rate_;
  std::vector<double> monthly_payment_;
  double overpayment_on_credit_;
  double total_payment_;
};
};  // namespace MyNamespace

#endif  // _MODEL_CREDIT_H_
