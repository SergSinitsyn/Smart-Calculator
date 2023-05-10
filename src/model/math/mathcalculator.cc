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
  ConvertInfixToPostfix();
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
  for (auto c : str) {
    result.push_back(std::tolower(c));
  }
  return result;
}

void MyNamespace::MathCalculator::Parsing() {
  size_t index = 0;
  while (index < input_expression_.size()) {
    if (isdigit(input_expression_[index])) {
      Token number;
      auto new_number = ReadNumber(input_expression_, index);
      number.MakeNumber(new_number.second, new_number.first);
      input_.push(number);
    } else if (isalpha(input_expression_[index])) {
      TryToPushToken(ReadWord(input_expression_, index));
    } else {
      std::string temp{input_expression_[index++]};
      TryToPushToken(temp);
    }
  }
  if (input_.empty()) {
    throw std::logic_error("Empty expression");
  }
}

std::pair<double, std::string> MyNamespace::MathCalculator::ReadNumber(
    std::string& input, size_t& start_index) const {
  std::regex double_regex("\\d+([.]\\d+)?(e([-+])?\\d+)?");
  std::sregex_iterator regex_iterator = std::sregex_iterator(
      input.begin() + start_index, input.end(), double_regex);
  std::smatch match = *regex_iterator;
  start_index += match.length();

  std::stringstream string_stream(match.str());
  double double_value = 0;
  string_stream >> double_value;
  return std::make_pair(double_value, match.str());
}

std::string MyNamespace::MathCalculator::ReadWord(std::string& input,
                                                  size_t& start_index) const {
  std::regex word_regex("([a-z]+)");
  std::sregex_iterator regex_iterator = std::sregex_iterator(
      input.begin() + start_index, input.end(), word_regex);
  std::smatch match = *regex_iterator;
  start_index += match.length();
  return match.str();
}

void MyNamespace::MathCalculator::TryToPushToken(std::string token) {
  auto token_map_it = token_map_.find(token);
  if (token_map_it != token_map_.end()) {
    input_.push(token_map_it->second);
  } else {
    throw std::logic_error("Incorrect symbol: " + token);
  }
}

void MyNamespace::MathCalculator::FindSpacesAndUnarySigns() {
  using namespace MyNamespace;
  while (!input_.empty()) {
    std::string name = input_.front().GetName();
    if (name == "space") {
      input_.pop();
    } else if ((name == "+" || name == "-") &&
               (output_.empty() || !kLastToken_[output_.back().GetType()])) {
      if (name == "-") {
        Token temp;
        temp.MakeUnaryNegation();
        output_.push(temp);
      }
      input_.pop();
    } else {
      MoveTokenFromInputToOutput();
    }
  }
  input_.swap(output_);
  if (input_.empty()) throw std::logic_error("Empty expression");
}

void MyNamespace::MathCalculator::CheckSequenceOfTokens() {
  using namespace MyNamespace;
  if (!kFirstToken_[input_.front().GetType()]) {
    throw std::logic_error("Wrong sequence: expression starts with " +
                           input_.front().GetName());
  }
  MoveTokenFromInputToOutput();
  while (!output_.empty() && !input_.empty()) {
    if (!kAdjacencyMatrix_[output_.back().GetType()]
                          [input_.front().GetType()]) {
      throw std::logic_error("Wrong sequence: " + output_.back().GetName() +
                             " " + input_.front().GetName());
    }
    MoveTokenFromInputToOutput();
  }
  if (!kLastToken_[output_.back().GetType()]) {
    throw std::logic_error("Wrong sequence: expression ends with " +
                           output_.back().GetName());
  }
  input_.swap(output_);
}

void MyNamespace::MathCalculator::ConvertInfixToPostfix() {
  using namespace MyNamespace;
  while (!input_.empty()) {
    switch (input_.front().GetType()) {
      case Type::kNumber:
      case Type::kUnaryPostfixOperator:
        MoveTokenFromInputToOutput();
        break;
      case Type::kUnaryFunction:
      case Type::kUnaryPrefixOperator:
      case Type::kOpenBracket:
        MoveTokenFromInputToStack();
        break;
      case Type::kBinaryOperator:
        while (
            !stack_.empty() &&
            (stack_.top().GetType() == Type::kBinaryOperator ||
             stack_.top().GetType() == Type::kUnaryPrefixOperator) &&
            (stack_.top().GetPrecedence() > input_.front().GetPrecedence() ||
             (stack_.top().GetPrecedence() == input_.front().GetPrecedence() &&
              input_.front().GetAssociativity() == Associativity::kLeft))) {
          MoveTokenFromStackToOutput();
        }
        MoveTokenFromInputToStack();
        break;
      case Type::kCloseBracket:
        while (!stack_.empty() &&
               stack_.top().GetType() != Type::kOpenBracket) {
          MoveTokenFromStackToOutput();
        }
        if (!stack_.empty() && stack_.top().GetType() == Type::kOpenBracket) {
          stack_.pop();
        } else {
          throw std::logic_error("Open bracket missing");
        }
        if (!stack_.empty() &&
            stack_.top().GetPrecedence() == Precedence::kFunction) {
          MoveTokenFromStackToOutput();
        }
        input_.pop();
        break;
      default:
        break;
    }
  }
  while (!stack_.empty()) {
    if (stack_.top().GetType() == Type::kOpenBracket) {
      throw std::logic_error("Close bracket missing");
    }
    MoveTokenFromStackToOutput();
  }
}

void MyNamespace::MathCalculator::MoveTokenFromInputToOutput() {
  output_.push(input_.front());
  input_.pop();
}

void MyNamespace::MathCalculator::MoveTokenFromInputToStack() {
  stack_.push(input_.front());
  input_.pop();
}

void MyNamespace::MathCalculator::MoveTokenFromStackToOutput() {
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
  if (str.front() == '-') {
    sign = -1;
    str.erase(0, 1);
  }
  if (isdigit(str.front())) {
    static const std::regex double_regex("([-])?\\d+([.]\\d+)?(e([-+])?\\d+)?");
    std::smatch match;
    std::regex_match(str, match, double_regex);
    if (match.empty()) throw std::logic_error("Incorrect x: " + origin_str);
    std::stringstream ss(match.str());
    ss >> x_value_;
    x_value_ *= sign;
  } else if (isalpha(str.front())) {
    const auto it = token_map_.find(str);
    if (it != token_map_.end() && it->second.GetType() == Type::kNumber &&
        it->second.GetName() != "x") {
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

void MyNamespace::MathCalculator::PushToResult(double value) {
  result_.push(value);
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
