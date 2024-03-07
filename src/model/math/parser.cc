#include "parser.h"

#include <algorithm>
#include <cmath>
#include <exception>
#include <functional>
#include <map>
#include <queue>
#include <regex>
#include <sstream>
#include <string>

#include "token.h"

namespace MyNamespace {
Parser::Parser()
    : token_map_(
          {{" ", Token("space", kDefault, kNone, kNumber, nullptr)},
           {"x", Token("x", kDefault, kNone, kNumber, nullptr)},
           {"(", Token("(", kDefault, kNone, kOpenBracket, nullptr)},
           {")", Token(")", kDefault, kNone, kCloseBracket, nullptr)},
           {"+", Token("+", kLow, kLeft, kBinaryOperator, std::plus<double>())},
           {"-",
            Token("-", kLow, kLeft, kBinaryOperator, std::minus<double>())},
           {"*", Token("*", kMedium, kLeft, kBinaryOperator,
                       std::multiplies<double>())},
           {"/", Token("/", kMedium, kLeft, kBinaryOperator,
                       std::divides<double>())},
           {"^", Token("^", kHigh, kRight, kBinaryOperator, powl)},
           {"mod", Token("mod", kMedium, kLeft, kBinaryOperator, fmodl)},
           {"cos", Token("cos", kFunction, kRight, kUnaryFunction, cosl)},
           {"sin", Token("sin", kFunction, kRight, kUnaryFunction, sinl)},
           {"tan", Token("tan", kFunction, kRight, kUnaryFunction, tanl)},
           {"acos", Token("acos", kFunction, kRight, kUnaryFunction, acosl)},
           {"asin", Token("asin", kFunction, kRight, kUnaryFunction, asinl)},
           {"atan", Token("atan", kFunction, kRight, kUnaryFunction, atanl)},
           {"sqrt", Token("sqrt", kFunction, kRight, kUnaryFunction, sqrtl)},
           {"ln", Token("ln", kFunction, kRight, kUnaryFunction, logl)},
           {"log", Token("log", kFunction, kRight, kUnaryFunction, log10l)},
           {"cbrt", Token("cbrt", kFunction, kRight, kUnaryFunction, cbrtl)},
           {"exp", Token("exp", kFunction, kRight, kUnaryFunction, expl)},
           {"abs", Token("abs", kFunction, kRight, kUnaryFunction, fabsl)},
           {"round", Token("round", kFunction, kRight, kUnaryFunction, roundl)},
           {"e", Token("e", kDefault, kNone, kNumber, M_E)},
           {"pi", Token("pi", kDefault, kNone, kNumber, M_PI)},
           {"inf", Token("inf", kDefault, kNone, kNumber, INFINITY)},
           {"!", Token("!", kUnaryOperator, kLeft, kUnaryPostfixOperator,
                       factorial)}}){};

std::queue<Token> Parser::Parsing(std::string input_expression) {
  input_expression = ConvertToLowercase(input_expression);
  input_ = {};
  output_ = {};
  size_t index = 0;
  while (index < input_expression.size()) {
    if (isdigit(input_expression[index])) {
      Token number;
      auto new_number = ReadNumber(input_expression, index);
      number.MakeNumber(new_number.second, new_number.first);
      input_.push(number);
    } else if (isalpha(input_expression[index])) {
      PushToken(ReadWord(input_expression, index));
    } else {
      std::string temp{input_expression[index++]};
      PushToken(temp);
    }
  }
  DeleteSpaces();
  FindUnarySigns();
  return input_;
}

double Parser::ReadX(std::string str) {
  str = ConvertToLowercase(str);
  double x_value = 0;
  std::string origin_str = str;
  if (!str.size()) {
    return NAN;
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
    ss >> x_value;
    x_value *= sign;
  } else if (isalpha(str.front())) {
    const auto it = token_map_.find(str);
    if (it != token_map_.end() && it->second.GetType() == Type::kNumber &&
        it->second.GetName() != "x") {
      x_value = std::get<double>(it->second.GetFunction());
      x_value *= sign;
    } else {
      throw std::logic_error("Incorrect x: " + origin_str);
    }
  } else {
    throw std::logic_error("Incorrect x: " + origin_str);
  }
  return x_value;
}

std::string Parser::ConvertToLowercase(std::string str) {
  std::transform(str.begin(), str.end(), str.begin(), ::tolower);
  return str;
}

std::pair<double, std::string> Parser::ReadNumber(std::string& input,
                                                  size_t& start_index) const {
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

std::string Parser::ReadWord(std::string& input, size_t& start_index) const {
  std::regex word_regex("([a-z]+)");
  std::sregex_iterator regex_iterator = std::sregex_iterator(
      input.begin() + start_index, input.end(), word_regex);
  std::smatch match = *regex_iterator;
  start_index += match.length();
  return match.str();
}

void Parser::PushToken(std::string token) {
  auto token_map_it = token_map_.find(token);
  if (token_map_it == token_map_.end()) {
    throw std::logic_error("Incorrect symbol: " + token);
  }
  input_.push(token_map_it->second);
}

void Parser::DeleteSpaces() {
  while (!input_.empty()) {
    std::string name = input_.front().GetName();
    if (name == "space") {
      input_.pop();
    } else {
      MoveTokenFromInputToOutput();
    }
  }
  std::swap(input_, output_);
}

void MyNamespace::Parser::FindUnarySigns() {
  while (!input_.empty()) {
    std::string name = input_.front().GetName();
    if ((name == "+" || name == "-") &&
        (output_.empty() || !kLastToken_[output_.back().GetType()])) {
      input_.pop();
      if (name == "-") {
        Token temp;
        temp.MakeUnaryNegation();
        output_.push(temp);
      }
    } else {
      MoveTokenFromInputToOutput();
    }
  }
  std::swap(input_, output_);
}

void Parser::MoveTokenFromInputToOutput() {
  output_.push(input_.front());
  input_.pop();
}

};  // namespace MyNamespace