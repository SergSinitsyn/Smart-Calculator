#include "token.h"

#include <cmath>
#include <functional>
#include <stdexcept>

MyNamespace::Token::Token(const std::string &name, Precedence precedence,
                          Associativity associativity, Type type,
                          function_variant function)
    : name_(name), precedence_(precedence), associativity_(associativity),
      type_(type), function_(function){};

std::string MyNamespace::Token::name() const { return name_; }

MyNamespace::Precedence MyNamespace::Token::precedence() const {
  return precedence_;
}

MyNamespace::Associativity MyNamespace::Token::associativity() const {
  return associativity_;
}

MyNamespace::Type MyNamespace::Token::type() const { return type_; }

MyNamespace::function_variant MyNamespace::Token::function() const {
  return function_;
}

void MyNamespace::Token::TransformToUnaryNegation() {
  name_ = "negate";
  precedence_ = kUnaryOperator;
  associativity_ = kRight;
  type_ = kUnaryPrefixOperator;
  function_ = std::negate<double>();
}
