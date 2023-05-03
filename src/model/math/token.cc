#include "token.h"

#include <cmath>
#include <functional>

MyNamespace::Token::Token(const std::string& name, Precedence precedence,
                          Associativity associativity,
                          OperationType operation_type, double value,
                          function_variant function)
    : name_(name),
      precedence_(precedence),
      associativity_(associativity),
      operation_type_(operation_type),
      value_(value),
      function_(function){};

std::string MyNamespace::Token::GetName() const { return name_; }

MyNamespace::Precedence MyNamespace::Token::GetPrecedence() const {
  return precedence_;
}

MyNamespace::Associativity MyNamespace::Token::GetAssociativity() const {
  return associativity_;
}

MyNamespace::OperationType MyNamespace::Token::GetOperationType() const {
  return operation_type_;
}

double MyNamespace::Token::GetValue() const { return value_; }

MyNamespace::function_variant MyNamespace::Token::GetFunction() const {
  return function_;
}

void MyNamespace::Token::MakeNumber(std::string name, double value) {
  Token result(name, kNumber, kNone, kOperand, value, nullptr);
  *this = result;
}

void MyNamespace::Token::MakeUnaryNegation() {
  Token result("negate", kUnaryOperator, kRight, kUnary, 0,
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
      {" ", Token("space", kNumber, kNone, kOperand, 0, nullptr)},
      {"x", Token("x", kNumber, kNone, kOperand, 0, nullptr)},
      {"(", Token("(", kOpenBracket, kNone, kOperand, 0, nullptr)},
      {")", Token(")", kCloseBracket, kNone, kOperand, 0, nullptr)},
      {"+", Token("+", kLow, kLeft, kBinary, 0, std::plus<double>())},
      {"-", Token("-", kLow, kLeft, kBinary, 0, std::minus<double>())},
      {"*", Token("*", kMedium, kLeft, kBinary, 0, std::multiplies<double>())},
      {"/", Token("/", kMedium, kLeft, kBinary, 0, std::divides<double>())},
      {"^", Token("^", kHigh, kRight, kBinary, 0, powl)},
      {"mod", Token("mod", kMedium, kLeft, kBinary, 0, fmodl)},
      {"cos", Token("cos", kFunction, kRight, kUnary, 0, cosl)},
      {"sin", Token("sin", kFunction, kRight, kUnary, 0, sinl)},
      {"tan", Token("tan", kFunction, kRight, kUnary, 0, tanl)},
      {"acos", Token("acos", kFunction, kRight, kUnary, 0, acosl)},
      {"asin", Token("asin", kFunction, kRight, kUnary, 0, asinl)},
      {"atan", Token("atan", kFunction, kRight, kUnary, 0, atanl)},
      {"sqrt", Token("sqrt", kFunction, kRight, kUnary, 0, sqrtl)},
      {"ln", Token("ln", kFunction, kRight, kUnary, 0, logl)},
      {"log", Token("log", kFunction, kRight, kUnary, 0, log10l)},
      {"cbrt", Token("cbrt", kFunction, kRight, kUnary, 0, cbrtl)},
      {"exp", Token("exp", kFunction, kRight, kUnary, 0, expl)},
      {"abs", Token("abs", kFunction, kRight, kUnary, 0, fabsl)},
      {"round", Token("round", kFunction, kRight, kUnary, 0, roundl)},
      {"e", Token("e", kNumber, kNone, kOperand, M_E, nullptr)},
      {"pi", Token("pi", kNumber, kNone, kOperand, M_PI, nullptr)},
      {"inf", Token("inf", kNumber, kNone, kOperand, INFINITY, nullptr)},
  };
  token_map.insert(list);
}
