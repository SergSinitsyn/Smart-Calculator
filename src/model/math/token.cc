#include "token.h"

#include <cmath>
#include <functional>
#include <stdexcept>

MyNamespace::Token::Token(const std::string& name, Precedence precedence,
                          Associativity associativity, Type type,
                          function_variant function)
    : name_(name),
      precedence_(precedence),
      associativity_(associativity),
      type_(type),
      function_(function){};

std::string MyNamespace::Token::GetName() const { return name_; }

MyNamespace::Precedence MyNamespace::Token::GetPrecedence() const {
  return precedence_;
}

MyNamespace::Associativity MyNamespace::Token::GetAssociativity() const {
  return associativity_;
}

MyNamespace::Type MyNamespace::Token::GetType() const { return type_; }

MyNamespace::function_variant MyNamespace::Token::GetFunction() const {
  return function_;
}

void MyNamespace::Token::MakeNumber(std::string name, double value) {
  Token result(name, kDefault, kNone, kNumber, value);
  *this = result;
}

void MyNamespace::Token::MakeUnaryNegation() {
  Token result("negate", kUnaryOperator, kRight, kUnaryPrefixOperator,
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
      {" ", Token("space", kDefault, kNone, kNumber, nullptr)},
      {"x", Token("x", kDefault, kNone, kNumber, nullptr)},
      {"(", Token("(", kDefault, kNone, kOpenBracket, nullptr)},
      {")", Token(")", kDefault, kNone, kCloseBracket, nullptr)},
      {"+", Token("+", kLow, kLeft, kBinaryOperator, std::plus<double>())},
      {"-", Token("-", kLow, kLeft, kBinaryOperator, std::minus<double>())},
      {"*",
       Token("*", kMedium, kLeft, kBinaryOperator, std::multiplies<double>())},
      {"/",
       Token("/", kMedium, kLeft, kBinaryOperator, std::divides<double>())},
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
      {"!",
       Token("!", kUnaryOperator, kLeft, kUnaryPostfixOperator, factorial)},
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