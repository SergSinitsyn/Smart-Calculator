#ifndef _MODEL_TOKEN_H_
#define _MODEL_TOKEN_H_

#include <functional>
#include <string>
#include <variant>

enum Precedence {
  kNumber,
  kLow,
  kMedium,
  kHigh,
  kUnaryOperator,
  kFunction,
  kBracket,
};

enum OperationType {
  kOperand,
  kUnary,
  kBinary,
};

enum Associativity {
  kNone,
  kLeft,
  kRight,
};

using function_1arg = std::function<double(double)>;
using function_2arg = std::function<double(double, double)>;
using function_cast_1arg = double (*)(double);
using function_cast_2arg = double (*)(double, double);
using function_variant = std::variant<nullptr_t, function_1arg, function_2arg>;

class Token {
 public:
  Token();
  Token(std::string type, Precedence precedence, Associativity associativity,
        OperationType operation_type, double value, function_variant function);
  Token(const Token& other);

  //! rule of 5
  ~Token();

  std::string GetType();
  int GetPrecedence();
  double GetValue();
  int GetAssociativity();
  int GetOperationType();
  function_variant GetFunction();
  void SetValue(double value);

 private:
  std::string type_;
  Precedence precedence_;
  Associativity associativity_;
  OperationType operation_type_;
  double value_;
  function_variant function_;
};

#endif  // _MODEL_TOKEN_H_