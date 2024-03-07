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