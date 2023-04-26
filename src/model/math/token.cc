#include "token.h"

MyNamespace::Token::Token(const std::string& name, Precedence precedence,
                  Associativity associativity, OperationType operation_type,
                  double value, fp_variant function)
    : name_(name),
      precedence_(precedence),
      associativity_(associativity),
      operation_type_(operation_type),
      value_(value),
      function_(function){};

std::string MyNamespace::Token::GetName() const { return name_; }

MyNamespace::Precedence MyNamespace::Token::GetPrecedence() const { return precedence_; }

MyNamespace::Associativity MyNamespace::Token::GetAssociativity() const {
  return associativity_;
}

MyNamespace::OperationType MyNamespace::Token::GetOperationType() const {
  return operation_type_;
}

double MyNamespace::Token::GetValue() const { return value_; }

MyNamespace::fp_variant MyNamespace::Token::GetFunction() const { return function_; }

void MyNamespace::Token::MakeNumber(std::string name, double value) {
  Token result(name, kNumber, kNone, kOperand, value, nullptr);
  *this = result;
}

void MyNamespace::Token::MakeUnaryNegation() {
  Token result("-", kUnaryOperator, kRight, kUnary, 0, lamdas_f1arg(-));
  *this = result;
}

void MyNamespace::CreateTokenMap(std::map<std::string, MyNamespace::Token>& temp_map) {
  using namespace std;
  using namespace MyNamespace;

  initializer_list<pair<const string, Token>> list = {
      {" ", Token(" ", kNumber, kNone, kOperand, 0, nullptr)},
      {"x", Token("x", kNumber, kNone, kOperand, 0, nullptr)},
      {"(", Token("(", kOpenBracket, kNone, kOperand, 0, nullptr)},
      {")", Token(")", kCloseBracket, kNone, kOperand, 0, nullptr)},
      {"+", Token("+", kLow, kLeft, kBinary, 0, lamdas_f2arg(+))},
      {"-", Token("-", kLow, kLeft, kBinary, 0, lamdas_f2arg(-))},
      {"*", Token("*", kMedium, kLeft, kBinary, 0, lamdas_f2arg(*))},
      {"/", Token("/", kMedium, kLeft, kBinary, 0, lamdas_f2arg(/))},
      {"^", Token("^", kHigh, kRight, kBinary, 0, (fcast_2arg)&pow)},
      {"mod", Token("mod", kMedium, kLeft, kBinary, 0, (fcast_2arg)&fmod)},
      {"cos", Token("cos", kFunction, kRight, kUnary, 0, (fcast_1arg)&cos)},
      {"sin", Token("sin", kFunction, kRight, kUnary, 0, (fcast_1arg)&sin)},
      {"tan", Token("tan", kFunction, kRight, kUnary, 0, (fcast_1arg)&tan)},
      {"acos", Token("acos", kFunction, kRight, kUnary, 0, (fcast_1arg)&acos)},
      {"asin", Token("asin", kFunction, kRight, kUnary, 0, (fcast_1arg)&asin)},
      {"atan", Token("atan", kFunction, kRight, kUnary, 0, (fcast_1arg)&atan)},
      {"sqrt", Token("sqrt", kFunction, kRight, kUnary, 0, (fcast_1arg)&sqrt)},
      {"ln", Token("ln", kFunction, kRight, kUnary, 0, (fcast_1arg)&log)},
      {"log", Token("log", kFunction, kRight, kUnary, 0, (fcast_1arg)&log10)},

      {"cbrt", Token("cbrt", kFunction, kRight, kUnary, 0, (fcast_1arg)&cbrt)},
      {"exp", Token("exp", kFunction, kRight, kUnary, 0, (fcast_1arg)&exp)},
      {"abs", Token("abs", kFunction, kRight, kUnary, 0, (fcast_1arg)&fabs)},
      {"e", Token("e", kNumber, kNone, kOperand, M_E, nullptr)},
      {"pi", Token("pi", kNumber, kNone, kOperand, M_PI, nullptr)},
      {"inf", Token("inf", kNumber, kNone, kOperand, INFINITY, nullptr)},
  };
  temp_map.insert(list);
}
