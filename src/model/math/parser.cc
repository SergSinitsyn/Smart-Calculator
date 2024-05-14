#include "parser.h"

#include <algorithm>
#include <cmath>
#include <exception>
#include <functional>
#include <map>
#include <regex>
#include <sstream>
#include <string>

#include "token.h"

namespace MyNamespace {

std::map<std::string, Token> Parser::token_map_ = {
    {" ", Token("space", kDefault, kNone, kNumber, nullptr)},
    {"x", Token("x", kDefault, kNone, kNumber, nullptr)},
    {"(", Token("(", kDefault, kNone, kOpenBracket, nullptr)},
    {")", Token(")", kDefault, kNone, kCloseBracket, nullptr)},
    {"+", Token("+", kLow, kLeft, kBinaryOperator, std::plus<double>())},
    {"-", Token("-", kLow, kLeft, kBinaryOperator, std::minus<double>())},
    {"*",
     Token("*", kMedium, kLeft, kBinaryOperator, std::multiplies<double>())},
    {"/", Token("/", kMedium, kLeft, kBinaryOperator, std::divides<double>())},
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
    {"inf", Token("inf", kDefault, kNone, kNumber, INFINITY)}};

std::list<Token> Parser::Parsing(const std::string &input_expression) {
  expression_ = input_expression;
  ConvertToLowercase(expression_);
  tokens_.clear();
  current_index_ = 0;
  while (current_index_ < expression_.size()) {
    if (isdigit(expression_[current_index_])) {
      auto number = ReadNumber();
      tokens_.push_back(
          Token(number.second, kDefault, kNone, kNumber, number.first));
    } else if (isalpha(expression_[current_index_])) {
      PushToken(ReadWord());
    } else {
      std::string token{expression_[current_index_++]};
      PushToken(token);
    }
  }
  DeleteSpaces();
  CheckUnaryPlus();
  CheckUnaryNegation();
  return tokens_;
}

void Parser::ConvertToLowercase(std::string &str) {
  std::transform(str.begin(), str.end(), str.begin(), tolower);
}

std::pair<double, std::string> Parser::ReadNumber() {
  std::regex double_pattern("\\d+([.]\\d+)?(e([-+])?\\d+)?");
  std::sregex_iterator regex_iterator = std::sregex_iterator(
      expression_.begin() + current_index_, expression_.end(), double_pattern);
  std::smatch match = *regex_iterator;
  current_index_ += match.length();

  std::stringstream string_stream(match.str());
  double double_value = 0;
  string_stream >> double_value;
  return std::make_pair(double_value, match.str());
}

std::string Parser::ReadWord() {
  std::regex word_regex("([a-z]+)");
  std::sregex_iterator regex_iterator = std::sregex_iterator(
      expression_.begin() + current_index_, expression_.end(), word_regex);
  std::smatch match = *regex_iterator;
  current_index_ += match.length();
  return match.str();
}

void Parser::PushToken(const std::string &token) {
  const auto token_map_it = token_map_.find(token);
  if (token_map_it == token_map_.end()) {
    throw std::logic_error("Incorrect symbol: " + token);
  }
  tokens_.emplace_back(token_map_it->second);
}

void Parser::DeleteSpaces() {
  tokens_.remove_if([](const Token &token) { return token.name() == "space"; });
}

void MyNamespace::Parser::CheckUnaryPlus() {
  for (auto current = tokens_.begin(), previous = tokens_.begin();
       current != tokens_.end(); previous = current, ++current) {
    if (current->name() == "+" && !kLastToken_[previous->type()]) {
      auto to_delete = current;
      tokens_.erase(to_delete);
    }
  }
}

void MyNamespace::Parser::CheckUnaryNegation() {
  for (auto current = tokens_.begin(), previous = tokens_.begin();
       current != tokens_.end(); previous = current, ++current) {
    if (current->name() == "-" && !kLastToken_[previous->type()]) {
      current->TransformToUnaryNegation();
    }
  }
}

};  // namespace MyNamespace