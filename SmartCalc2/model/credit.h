#ifndef _MODEL_CREDIT_H_
#define _MODEL_CREDIT_H_

#include <vector>

class Credit {
 public:
  Credit() = default;
  ~Credit() = default;
  void CalculateCredit(int type, double total_credit_amount, int term,
                       double interest_rate);
  std::vector<double> GetMonthlyPayment();
  double GetTotalPayment();
  double GetOverpaymentOnCredit();

 private:
  void LoadData(int type, double total_credit_amount, int term,
                double interest_rate);
  void AnnuityCredit();
  void DifferentiatedCredit();

  int type_;
  double total_credit_amount_;
  double term_;
  double interest_rate_;
  std::vector<double> monthly_payment_;
  double overpayment_on_credit_;
  double total_payment_;
};

#endif  // _MODEL_CREDIT_H_
