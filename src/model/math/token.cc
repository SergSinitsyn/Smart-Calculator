#include "token.h"

#include <cmath>
#include <functional>
#include <stdexcept>

MyNamespace::Token::Token(const std::string& name, Precedence precedence,
                          Associativity associativity, Type type, double value,
                          function_variant function)
    : name_(name),
      precedence_(precedence),
      associativity_(associativity),
      type_(type),
      value_(value),
      function_(function){};

std::string MyNamespace::Token::GetName() const { return name_; }

MyNamespace::Precedence MyNamespace::Token::GetPrecedence() const {
  return precedence_;
}

MyNamespace::Associativity MyNamespace::Token::GetAssociativity() const {
  return associativity_;
}

MyNamespace::Type MyNamespace::Token::GetType() const { return type_; }

double MyNamespace::Token::GetValue() const { return value_; }

MyNamespace::function_variant MyNamespace::Token::GetFunction() const {
  return function_;
}

void MyNamespace::Token::MakeNumber(std::string name, double value) {
  Token result(name, kDefault, kNone, kNumber, value, nullptr);
  *this = result;
}

void MyNamespace::Token::MakeUnaryNegation() {
  Token result("negate", kUnaryOperator, kRight, kUnaryPrefixOperator, 0,
               std::negate<double>());
  *this = result;
}

void MyNamespace::CreateTokenMap(
    std::map<std::string, MyNamespace::Token>& token_map) {
  using std::initializer_list;
  using std::pair;
  using std::string;
  using namespace MyNamespace;
  initializer_list<pair<const string, Token>> list = {
      {" ", Token("space", kDefault, kNone, kNumber, 0, nullptr)},
      {"x", Token("x", kDefault, kNone, kNumber, 0, nullptr)},
      {"(", Token("(", kDefault, kNone, kOpenBracket, 0, nullptr)},
      {")", Token(")", kDefault, kNone, kCloseBracket, 0, nullptr)},
      {"+", Token("+", kLow, kLeft, kBinaryOperator, 0, std::plus<double>())},
      {"-", Token("-", kLow, kLeft, kBinaryOperator, 0, std::minus<double>())},
      {"*", Token("*", kMedium, kLeft, kBinaryOperator, 0,
                  std::multiplies<double>())},
      {"/",
       Token("/", kMedium, kLeft, kBinaryOperator, 0, std::divides<double>())},
      {"^", Token("^", kHigh, kRight, kBinaryOperator, 0, powl)},
      {"mod", Token("mod", kMedium, kLeft, kBinaryOperator, 0, fmodl)},
      {"cos", Token("cos", kFunction, kRight, kUnaryFunction, 0, cosl)},
      {"sin", Token("sin", kFunction, kRight, kUnaryFunction, 0, sinl)},
      {"tan", Token("tan", kFunction, kRight, kUnaryFunction, 0, tanl)},
      {"acos", Token("acos", kFunction, kRight, kUnaryFunction, 0, acosl)},
      {"asin", Token("asin", kFunction, kRight, kUnaryFunction, 0, asinl)},
      {"atan", Token("atan", kFunction, kRight, kUnaryFunction, 0, atanl)},
      {"sqrt", Token("sqrt", kFunction, kRight, kUnaryFunction, 0, sqrtl)},
      {"ln", Token("ln", kFunction, kRight, kUnaryFunction, 0, logl)},
      {"log", Token("log", kFunction, kRight, kUnaryFunction, 0, log10l)},
      {"cbrt", Token("cbrt", kFunction, kRight, kUnaryFunction, 0, cbrtl)},
      {"exp", Token("exp", kFunction, kRight, kUnaryFunction, 0, expl)},
      {"abs", Token("abs", kFunction, kRight, kUnaryFunction, 0, fabsl)},
      {"round", Token("round", kFunction, kRight, kUnaryFunction, 0, roundl)},
      {"e", Token("e", kDefault, kNone, kNumber, M_E, nullptr)},
      {"pi", Token("pi", kDefault, kNone, kNumber, M_PI, nullptr)},
      {"inf", Token("inf", kDefault, kNone, kNumber, INFINITY, nullptr)},
      {"!",
       Token("!", kUnaryOperator, kLeft, kUnaryPostfixOperator, 0, factorial)},
  };
  token_map.insert(list);
}

long double factorial(long double n) {
  if (std::floor(n) != n) {
    throw std::logic_error("Not integer number for factorial");
  }
  long double result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}