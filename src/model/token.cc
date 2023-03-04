#include "token.h"

#include <map>

Token::Token(){};
Token::Token(std::string type, Precedence precedence,
             Associativity associativity, OperationType operation_type,
             double value, fp_variant function)
    : type_(type),
      precedence_(precedence),
      value_(value),
      associativity_(associativity),
      operation_type_(operation_type),
      function_(function){};

Token::Token(const Token& other)
    : type_(other.type_),
      precedence_(other.precedence_),
      value_(other.value_),
      associativity_(other.associativity_),
      operation_type_(other.operation_type_),
      function_(other.function_){};
//! 5
Token::~Token(){};

std::string Token::GetType() { return type_; }
int Token::GetPrecedence() { return precedence_; }
double Token::GetValue() { return value_; }
int Token::GetAssociativity() { return associativity_; }
int Token::GetOperationType() { return operation_type_; }
fp_variant Token::GetFunction() { return function_; }
void Token::SetValue(double value) { value_ = value; }

std::map<std::string, Token> CreateTokenMap() {
  using namespace std;
  initializer_list<pair<const string, Token>> list = {
      {"x", Token("x", kNumber, kNone, kOperand, 0, nullptr)},
      {"(", Token("(", kBracket, kNone, kOperand, 0, nullptr)},
      {")", Token(")", kBracket, kNone, kOperand, 0, nullptr)},

      {"+", Token("+", kLow, kLeft, kBinary, 0, lamdas_f2arg(+))},
      {"-", Token("-", kLow, kLeft, kBinary, 0, lamdas_f2arg(-))},
      {"*", Token("*", kMedium, kLeft, kBinary, 0, lamdas_f2arg(*))},
      {"/", Token("/", kMedium, kLeft, kBinary, 0, lamdas_f2arg(/))},
      {"^", Token("^", kHigh, kRight, kBinary, 0, (fcast_2arg)&std::pow)},

      {"mod", Token("mod", kMedium, kLeft, kBinary, 0, (fcast_2arg)&std::fmod)},
      {"cos",
       Token("cos", kFunction, kRight, kUnary, 0, (fcast_1arg)&std::cos)},
      {"sin",
       Token("sin", kFunction, kRight, kUnary, 0, (fcast_1arg)&std::sin)},
      {"tan",
       Token("tan", kFunction, kRight, kUnary, 0, (fcast_1arg)&std::tan)},
      {"acos",
       Token("acos", kFunction, kRight, kUnary, 0, (fcast_1arg)&std::acos)},
      {"asin",
       Token("asin", kFunction, kRight, kUnary, 0, (fcast_1arg)&std::asin)},
      {"atan",
       Token("atan", kFunction, kRight, kUnary, 0, (fcast_1arg)&std::atan)},
      {"sqrt",
       Token("sqrt", kFunction, kRight, kUnary, 0, (fcast_1arg)&std::sqrt)},
      {"ln", Token("ln", kFunction, kRight, kUnary, 0, (fcast_1arg)&std::log)},
      {"log",
       Token("log", kFunction, kRight, kUnary, 0, (fcast_1arg)&std::log10)},
      {"exp",
       Token("exp", kFunction, kRight, kUnary, 0, (fcast_1arg)&std::exp)},

  };
  std::map<std::string, Token> temp_map;
  temp_map.insert(list);
  return temp_map;
}

// double Addition(double a, double b) { return a + b; }
// double Subtraction(double a, double b) { return a - b; }
// double Multiplication(double a, double b) { return a * b; }
// double Division(double a, double b) { return a / b; }
// double UnaryPlus(double a) { return a; }
// double UnaryNegation(double a) { return -a; }