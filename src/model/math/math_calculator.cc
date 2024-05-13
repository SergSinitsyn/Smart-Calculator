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

  std::list<Token> x_postfix =
      postfix_calculator_.ConvertInfixToPostfix(x_expression);
  double x_value = postfix_calculator_.PostfixNotationCalculation(x_postfix);

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

MyNamespace::MathCalculator::XYGraph
MyNamespace::MathCalculator::GetGraph() const {
  return answer_graph_;
}

void MyNamespace::MathCalculator::CalculateXY(int number_of_points,
                                              double x_start, double x_end,
                                              double y_min, double y_max) {
  if (y_min > y_max) {
    std::swap(y_min, y_max);
  }

  std::vector<double> x_values, y_values;
  double step = (x_end - x_start) / (number_of_points - 1);
  long double threshold = fabs(step * 1000.0);
  bool in_range = true;

  for (int i = 0; i < number_of_points; ++i) {
    x_values.push_back(x_start + step * i);

    double y_value =
        postfix_calculator_.PostfixNotationCalculation(x_values.back());

    long double delta = 0;
    if (i && !std::isnan(y_values.back())) {
      delta = fabs((y_value - y_values.back()) / step);
    }

    if (delta > threshold && (y_value * y_values.back()) < 0) {
      in_range = false;
    } else if (y_value > y_max || y_value < y_min) {
      if (in_range) {
        y_values.push_back(y_value);
      } else {
        y_values.push_back(std::numeric_limits<double>::quiet_NaN());
      }
      in_range = false;
    } else {
      y_values.push_back(y_value);
      in_range = true;
    }
  }
  answer_graph_ = std::make_pair(x_values, y_values);
}
