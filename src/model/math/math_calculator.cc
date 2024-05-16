#include "math_calculator.h"

#include <algorithm>
#include <cmath>
#include <exception>
#include <stdexcept>
#include <string>

#include "parameter_checker.h"
#include "parser.h"
#include "postfix_calculator.h"
#include "token.h"
#include "validator.h"

void MyNamespace::MathCalculator::CalculateAnswer(
    const std::string &input_expression, const std::string &input_x) {
  parameter_checker_.CheckLength(input_expression);

  std::list<Token> x_expression = parser_.Parsing(input_x);
  std::list<Token> expression = parser_.Parsing(input_expression);

  validator_.CheckX(x_expression);
  validator_.CheckSequenceOfTokens(x_expression);
  validator_.CheckSequenceOfTokens(expression);

  double x_value = postfix_calculator_.PostfixNotationCalculation(
      postfix_calculator_.ConvertInfixToPostfix(x_expression));

  std::list<Token> postfix =
      postfix_calculator_.ConvertInfixToPostfix(expression);

  answer_ = postfix_calculator_.PostfixNotationCalculation(postfix, x_value);
}

void MyNamespace::MathCalculator::CalculateAnswer(
    const std::string &input_expression) {
  CalculateAnswer(input_expression, "0");
}

void MyNamespace::MathCalculator::CalculateGraph(
    const std::string &input_expression, int number_of_points, double x_start,
    double x_end, double y_min, double y_max) {
  parameter_checker_.CheckLength(input_expression);
  parameter_checker_.CheckNumberOfPoints(number_of_points);
  parameter_checker_.CheckRange(x_start, x_end);

  std::list<Token> expression = parser_.Parsing(input_expression);

  validator_.CheckSequenceOfTokens(expression);

  postfix_calculator_.ConvertInfixToPostfix(expression);
  CalculateXY(number_of_points, x_start, x_end, y_min, y_max);
}

double MyNamespace::MathCalculator::GetAnswer() const { return answer_; }

MyNamespace::MathCalculator::XYGraph MyNamespace::MathCalculator::GetGraph()
    const {
  return answer_graph_;
}

void MyNamespace::MathCalculator::CalculateXY(int number_of_points,
                                              double x_start, double x_end,
                                              double y_min, double y_max) {
  if (y_min > y_max) {
    std::swap(y_min, y_max);
  }
  std::vector<double> x_values;
  std::vector<double> y_values;
  double step = (x_end - x_start) / (number_of_points - 1);

  for (int i = 0; i < number_of_points; ++i) {
    x_values.push_back(x_start + step * i);
    y_values.push_back(
        postfix_calculator_.PostfixNotationCalculation(x_values.back()));
  }

  double y_max_area = y_max + y_max - y_min;
  double y_min_area = y_min + y_min - y_max;

  for (auto &point : y_values) {
    if (point > y_max_area || point < y_min_area) {
      point = std::numeric_limits<double>::quiet_NaN();
    }
  }

  answer_graph_ = std::make_pair(x_values, y_values);
}
