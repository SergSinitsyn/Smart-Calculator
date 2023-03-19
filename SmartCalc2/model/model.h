#ifndef _MODEL_MODEL_H_
#define _MODEL_MODEL_H_

#include "credit.h"
#include "deposit.h"
#include "mathcalculator.h"

class Model {
 public:
  Model() {}
  explicit Model(const MathCalculator& math_calc_, const Credit& credit_calc_,
                 const Deposit& deposit_calc_)
      : math_calc_{math_calc_},
        credit_calc_{credit_calc_},
        deposit_calc_{deposit_calc_} {}

  double CalcMath(std::string& str_from_label, std::string& str_x) {
    math_calc_.CalculateAnswer(str_from_label, str_x);
    return math_calc_.GetAnswer();
  }

  //   double GetResultMathExpression(std::string& str_from_label,
  //                                  std::string& str_x) {
  //     if (math_calc_.input_expression_ != str_from_label ||
  //         !math_calc_.correct_load_) {
  //       math_calc_.LoadExpression(str_from_label);
  //     }
  //     return math_calc_.CalculateValue(str_x);
  //   }

  //   std::pair<std::vector<double>, std::vector<double>> GetGraph(std::string&
  //   str_from_label,int number_of_points, double start, double end ) {
  //       if (math_calc_.input_expression_ != str_from_label ||
  //       !math_calc_.correct_load_) {
  //           math_calc_.LoadExpression(str_from_label);
  //       }
  //       return math_calc_.CalculateGraph(number_of_points,start,end);
  //   }

  // std::tuple<std::vector<double>, double, double> CalculateCredit(double
  // total_credit_amount, int term, double interest_rate, int type) {
  //     credit_calc_.LoadData(total_credit_amount,  term,  interest_rate);
  //     return type ? credit_calc_.AnnuityCredit() :
  //     credit_calc_.DifferentiatedCredit();
  // }

  //  std::pair<XYGraph, std::string> Calculate(std::string str, int size,
  //                                            double start, double end);

 private:
  MathCalculator math_calc_;
  Credit credit_calc_;
  Deposit deposit_calc_;
};

#endif  // _MODEL_MODEL_H_
