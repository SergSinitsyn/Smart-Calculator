#include "mathcalculator.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <exception>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <regex>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <variant>

MyNamespace::MathCalculator::MathCalculator() { CreateTokenMap(token_map_); }

void MyNamespace::MathCalculator::CalculateAnswer(
    const std::string& input_expression, const std::string& input_x) {
  if (input_expression != raw_input_expression_ || !correct_load_)
    LoadExpression(input_expression);
  if (input_x != raw_input_x_ || !correct_load_x_) LoadX(input_x);
  if (correct_load_ && correct_load_x_)
    answer_ = PostfixNotationCalculation(x_value_);
}

void MyNamespace::MathCalculator::CalculateAnswer(
    const std::string& input_expression) {
  CalculateAnswer(input_expression, "");
}

void MyNamespace::MathCalculator::CalculateGraph(
    const std::string& input_expression, int number_of_points, double x_start,
    double x_end, double y_min, double y_max) {
  if (input_expression != raw_input_expression_ || !correct_load_)
    LoadExpression(input_expression);
  if (correct_load_)
    CalculateXY(number_of_points, x_start, x_end, y_min, y_max);
}

double MyNamespace::MathCalculator::GetAnswer() const { return answer_; }

MyNamespace::MathCalculator::XYGraph MyNamespace::MathCalculator::GetGraph()
    const {
  return answer_graph_;
}

void MyNamespace::MathCalculator::LoadExpression(
    const std::string& input_expression) {
  correct_load_ = false;
  input_ = {};
  stack_ = {};
  output_ = {};
  result_ = {};
  raw_input_expression_ = input_expression;
  CheckLength(raw_input_expression_);
  input_expression_ = ConvertToLowercase(raw_input_expression_);
  Parsing();
  FindSpacesAndUnarySigns();
  CheckSequenceOfTokens();
  ShuntingYardAlgorithm();
  correct_load_ = true;
}

void MyNamespace::MathCalculator::LoadX(const std::string& input_x) {
  correct_load_x_ = false;
  raw_input_x_ = input_x;
  input_x_ = ConvertToLowercase(raw_input_x_);
  ReadX(input_x_);
  correct_load_x_ = true;
}

std::string MyNamespace::MathCalculator::ConvertToLowercase(std::string str) {
  std::string result;
  for (size_t i = 0; i < str.size(); ++i) {
    result.push_back(tolower(str[i]));
  }
  return result;
}

void MyNamespace::MathCalculator::Parsing() {
  size_t i = 0;
  while (i < input_expression_.size()) {
    if (isdigit(input_expression_[i])) {
      Token number;
      auto new_number = ReadNumber(input_expression_, i);
      number.MakeNumber(new_number.second, new_number.first);
      input_.push(number);
    } else if (isalpha(input_expression_[i])) {
      TryToPushToken(ReadWord(input_expression_, i));
    } else {
      std::string temp{input_expression_[i++]};
      TryToPushToken(temp);
    }
  }
  if (input_.empty()) throw std::logic_error("Empty expression");
}

std::pair<double, std::string> MyNamespace::MathCalculator::ReadNumber(
    std::string& str, size_t& start) const {
  std::regex r("\\d+(([.]\\d+)?(e([+-])?\\d+)?)?");
  std::sregex_iterator i =
      std::sregex_iterator(str.begin() + start, str.end(), r);
  std::smatch match = *i;
  start += match.length();
  std::stringstream ss(match.str());
  double d = 0;
  ss >> d;
  return make_pair(d, match.str());
}

std::string MyNamespace::MathCalculator::ReadWord(std::string& str,
                                                  size_t& start) const {
  std::regex r("([a-z]+)");
  std::sregex_iterator i =
      std::sregex_iterator(str.begin() + start, str.end(), r);
  std::smatch match = *i;
  start += match.length();
  return match.str();
}

void MyNamespace::MathCalculator::TryToPushToken(std::string temp) {
  if (auto it = token_map_.find(temp); it != token_map_.end()) {
    input_.push(it->second);
  } else {
    throw std::logic_error("Incorrect symbol: " + temp);
  }
}

void MyNamespace::MathCalculator::FindSpacesAndUnarySigns() {
  using namespace MyNamespace;
  while (!input_.empty()) {
    std::string name = input_.front().GetName();
    if (name == " ") {
      input_.pop();
    } else if ((name == "+" || name == "-") &&
               (output_.empty() ||
                !kLastToken_[output_.back().GetPrecedence()])) {
      if (name == "-") {
        Token temp;
        temp.MakeUnaryNegation();
        output_.push(temp);
      }
      input_.pop();
    } else {
      FromInputToOutput();
    }
  }
  input_.swap(output_);
  if (input_.empty()) throw std::logic_error("Empty expression");
}

void MyNamespace::MathCalculator::CheckSequenceOfTokens() {
  using namespace MyNamespace;
  if (!kFirstToken_[input_.front().GetPrecedence()]) {
    throw std::logic_error("Wrong sequence: expression starts with " +
                           input_.front().GetName());
  }
  FromInputToOutput();
  while (!output_.empty() && !input_.empty()) {
    if (!kAdjacencyMatrix_[output_.back().GetPrecedence()]
                          [input_.front().GetPrecedence()]) {
      throw std::logic_error("Wrong sequence: " + output_.back().GetName() +
                             " " + input_.front().GetName());
    }
    FromInputToOutput();
  }
  if (!output_.empty()) {
    if (!kLastToken_[output_.back().GetPrecedence()]) {
      throw std::logic_error("Wrong sequence: expression ends with " +
                             output_.back().GetName());
    }
  }
  input_.swap(output_);
}

void MyNamespace::MathCalculator::ShuntingYardAlgorithm() {
  using namespace MyNamespace;
  while (!input_.empty()) {
    if (input_.front().GetPrecedence() == Precedence::kNumber) {
      FromInputToOutput();
    } else if (input_.front().GetOperationType() == OperationType::kUnary) {
      FromInputToStack();
    } else if (input_.front().GetOperationType() == OperationType::kBinary) {
      while (!stack_.empty() &&
             (stack_.top().GetOperationType() == OperationType::kBinary ||
              stack_.top().GetPrecedence() == Precedence::kUnaryOperator) &&
             (stack_.top().GetPrecedence() > input_.front().GetPrecedence() ||
              (stack_.top().GetPrecedence() == input_.front().GetPrecedence() &&
               input_.front().GetAssociativity() == Associativity::kLeft))) {
        FromStackToOutput();
      }
      FromInputToStack();
    } else if (input_.front().GetName() == "(") {
      FromInputToStack();
    } else if (input_.front().GetName() == ")") {
      while (!stack_.empty() && stack_.top().GetName() != "(") {
        FromStackToOutput();
      }
      if (!stack_.empty() && stack_.top().GetName() == "(") {
        stack_.pop();
      } else {
        throw std::logic_error("Open bracket missing");
      }
      if (!stack_.empty() &&
          stack_.top().GetPrecedence() == Precedence::kFunction) {
        FromStackToOutput();
      }
      input_.pop();
    }
  }
  while (!stack_.empty()) {
    if (stack_.top().GetName() == "(")
      throw std::logic_error("Close bracket missing");
    FromStackToOutput();
  }
}

void MyNamespace::MathCalculator::FromInputToOutput() {
  output_.push(input_.front());
  input_.pop();
}

void MyNamespace::MathCalculator::FromInputToStack() {
  stack_.push(input_.front());
  input_.pop();
}

void MyNamespace::MathCalculator::FromStackToOutput() {
  output_.push(stack_.top());
  stack_.pop();
}

void MyNamespace::MathCalculator::ReadX(std::string str) {
  using namespace MyNamespace;
  std::string origin_str = str;
  if (!str.size()) {
    x_value_ = NAN;
    return;
  }
  int sign = 1;
  if (str[0] == '-') {
    sign = -1;
    str.erase(str.begin(), str.begin() + 1);
  }
  if (isdigit(str[0])) {
    std::regex r("([-])?\\d+(([.]\\d+)?(e([+-])?\\d+)?)?");
    std::smatch match;
    std::regex_match(str, match, r);
    if (match.empty()) throw std::logic_error("Incorrect x: " + origin_str);
    std::stringstream ss(match.str());
    ss >> x_value_;
    x_value_ *= sign;
  } else if (isalpha(str[0])) {
    auto it = token_map_.find(str);
    if (it != token_map_.end() && it->second.GetValue()) {
      x_value_ = it->second.GetValue();
      x_value_ *= sign;
    } else {
      throw std::logic_error("Incorrect x: " + origin_str);
    }
  } else {
    throw std::logic_error("Incorrect x: " + origin_str);
  }
}

double MyNamespace::MathCalculator::PostfixNotationCalculation(double x_value) {
  using namespace MyNamespace;
  input_ = output_;
  while (!input_.empty()) {
    std::visit(
        overloaded{[&](unary_function function) {
                     PushToResult(function(PopFromResult()));
                   },
                   [&](binary_function function) {
                     double right_argument = PopFromResult();
                     double left_argument = PopFromResult();
                     PushToResult(function(left_argument, right_argument));
                   },
                   [&](auto) {
                     if (input_.front().GetName() == "x") {
                       PushToResult(x_value);
                     } else {
                       PushToResult();
                     }
                   }},
        input_.front().GetFunction());
  }
  return PopFromResult();
}

void MyNamespace::MathCalculator::PushToResult() {
  result_.push(input_.front().GetValue());
  input_.pop();
}

void MyNamespace::MathCalculator::PushToResult(double x_value) {
  result_.push(x_value);
  input_.pop();
}

double MyNamespace::MathCalculator::PopFromResult() {
  double value = result_.top();
  result_.pop();
  return value;
}

void MyNamespace::MathCalculator::CalculateXY(int number_of_points,
                                              double x_start, double x_end,
                                              double y_min, double y_max) {
  CheckNumberOfPoints(number_of_points);
  CheckRange(x_start, x_end);
  if (y_min > y_max) {
    std::swap(y_min, y_max);
  }
  y_min *= 1.2;
  y_max *= 1.2;

  std::vector<double> x, y;
  double step = (x_end - x_start) / (number_of_points - 1);
  long double threshold = fabs(step * 1000.0);

  for (int i = 0; i < number_of_points; ++i) {
    x.push_back(x_start + step * i);
    double y_value = PostfixNotationCalculation(x.back());
    long double delta = 0;
    if (i && !std::isnan(y.back())) {
      delta = fabs((y_value - y.back()) / step);
    }
    if (y_value > y_max || y_value < y_min) {
      y.push_back(std::numeric_limits<double>::quiet_NaN());
    } else if (delta > threshold && (y_value * y.back()) < 0) {
      y.push_back(std::numeric_limits<double>::quiet_NaN());
    } else {
      y.push_back(y_value);
    }
  }
  answer_graph_ = std::make_pair(x, y);
}
