#ifndef SMARTCALC_MODEL_MATH_MATHCALCULATOR_H_
#define SMARTCALC_MODEL_MATH_MATHCALCULATOR_H_

#include <limits>
#include <string>

#include "parameter_checker.h"
#include "parser.h"
#include "postfix_calculator.h"
#include "validator.h"

namespace MyNamespace {
class MathCalculator {
 public:
  using XYGraph = std::pair<std::vector<double>, std::vector<double>>;
  MathCalculator(){};
  ~MathCalculator() = default;

  void CalculateAnswer(const std::string& input_expression,
                       const std::string& input_x);
  void CalculateAnswer(const std::string& input_expression);
  void CalculateGraph(const std::string& input_expression, int number_of_points,
                      double x_start, double x_end, double y_min, double y_max);
  double GetAnswer() const;
  XYGraph GetGraph() const;

 private:
  ParameterChecker parameter_checker_;
  Parser parser_;
  Validator validator_;
  PostfixCalculator postfix_calculator_;

  double answer_{std::numeric_limits<double>::quiet_NaN()};
  XYGraph answer_graph_;
  void CalculateXY(int number_of_points, double x_start, double x_end,
                   double y_min, double y_max);
};

};  // namespace MyNamespace

#endif  // SMARTCALC_MODEL_MATH_MATHCALCULATOR_H_
