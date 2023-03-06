#include "token.h"

Token::Token(){};
Token::Token(std::string name, Precedence precedence,
             Associativity associativity, OperationType operation_type,
             double value, fp_variant function)
    : name_(name),
      precedence_(precedence),
      value_(value),
      associativity_(associativity),
      operation_type_(operation_type),
      function_(function){};

std::string Token::GetName() { return name_; }
Precedence Token::GetPrecedence() { return precedence_; }
Associativity Token::GetAssociativity() { return associativity_; }
OperationType Token::GetOperationType() { return operation_type_; }
double Token::GetValue() { return value_; }
fp_variant Token::GetFunction() { return function_; }

void Token::MakeNumber(double value) {
  Token result("", kNumber, kNone, kOperand, value, nullptr);
  *this = result;
}

void Token::MakeUnaryNegation() {
  Token result("un", kUnaryOperator, kRight, kUnary, 0, lamdas_f1arg(-));
  *this = result;
}

std::map<std::string, Token> CreateTokenMap() {
  using namespace std;
  initializer_list<pair<const string, Token>> list = {
      {" ", Token(" ", kNumber, kNone, kOperand, 0, nullptr)},
      {"x", Token("x", kNumber, kNone, kOperand, 0, nullptr)},
      {"(", Token("(", kBracket, kNone, kOperand, 0, nullptr)},
      {")", Token(")", kBracket, kNone, kOperand, 0, nullptr)},
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
      {"exp", Token("exp", kFunction, kRight, kUnary, 0, (fcast_1arg)&exp)},
      {"e", Token("e", kNumber, kNone, kOperand, M_E, nullptr)},
      {"pi", Token("pi", kNumber, kNone, kOperand, M_PI, nullptr)},
      {"inf", Token("inf", kNumber, kNone, kOperand, INFINITY, nullptr)},
  };

  std::map<std::string, Token> temp_map;
  temp_map.insert(list);
  return temp_map;
}