#include "other.h"

#include <cmath>

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

Token Number_("", kNumber, kNone, kOperand, 0, nullptr);
Token UnaryNegation_("-", kUnaryOperator, kLeft, kUnary, 0, lamdas_f1arg(-));

bool is_letter(char c) { return (c >= 'a' && c <= 'z'); }
bool is_E(char c) { return (c == 'E' || c == 'e'); }
bool is_pm(char c) { return (c == '+' || c == '-'); }
bool is_number(char c) { return (c == '.' || (c >= '0' && c <= '9')); }
bool is_symbol(char c) {
  return (c == ' ' || (c >= '(' && c <= '+') || c == '-' || c == '/' ||
          c == '^' || c == 'x');
}

double Addition(double a, double b) { return a + b; }
double Subtraction(double a, double b) { return a - b; }
double Multiplication(double a, double b) { return a * b; }
double Division(double a, double b) { return a / b; }
double UnaryPlus(double a) { return a; }
double UnaryNegation(double a) { return -a; }