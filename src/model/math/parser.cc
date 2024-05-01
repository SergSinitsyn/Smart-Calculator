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
    {"inf", Token("inf", kDefault, kNone, kNumber, INFINITY)},
    {"!", Token("!", kUnaryOperator, kLeft, kUnaryPostfixOperator, factorial)}};

std::list<Token> Parser::Parsing(std::string expression) {
  ConvertToLowercase(expression);
  tokens_.clear();
  size_t index = 0;
  while (index < expression.size()) {
    if (isdigit(expression[index])) {
      Token number;
      auto new_number = ReadNumber(expression, index);
      number.MakeNumber(new_number.second, new_number.first);
      tokens_.push_back(number);
    } else if (isalpha(expression[index])) {
      PushToken(ReadWord(expression, index));
    } else {
      std::string token{expression[index++]};
      PushToken(token);
    }
  }
  DeleteSpaces();
  CheckUnaryPlus();
  CheckUnaryNegation();
  return tokens_;
}

void Parser::ConvertToLowercase(std::string& str) {
  std::transform(str.begin(), str.end(), str.begin(), tolower);
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
  const auto token_map_it = token_map_.find(token);
  if (token_map_it == token_map_.end()) {
    throw std::logic_error("Incorrect symbol: " + token);
  }
  tokens_.emplace_back(token_map_it->second);
}

void Parser::DeleteSpaces() {
  tokens_.remove_if([](const Token& token) { return token.name() == "space"; });
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