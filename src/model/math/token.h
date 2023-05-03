#ifndef SMARTCALC_MODEL_MATH_TOKEN_H_
#define SMARTCALC_MODEL_MATH_TOKEN_H_

#include <functional>
#include <map>
#include <string>
#include <variant>

namespace MyNamespace {

using unary_function = std::function<double(double)>;

using binary_function = std::function<double(double, double)>;

using function_variant =
    std::variant<unary_function, binary_function, nullptr_t>;

enum Precedence {
  kNumber,
  kLow,
  kMedium,
  kHigh,
  kUnaryOperator,
  kFunction,
  kOpenBracket,
  kCloseBracket,
  kNumTokenTypes,
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

};  // namespace MyNamespace

namespace MyNamespace {
class Token {
 public:
  Token() = default;
  Token(const std::string& name, Precedence precedence,
        Associativity associativity, OperationType operation_type, double value,
        function_variant function);
  ~Token() = default;

  std::string GetName() const;
  Precedence GetPrecedence() const;
  Associativity GetAssociativity() const;
  OperationType GetOperationType() const;
  double GetValue() const;
  function_variant GetFunction() const;

  void MakeNumber(std::string name, double value);
  void MakeUnaryNegation();

 private:
  std::string name_;
  Precedence precedence_;
  Associativity associativity_;
  OperationType operation_type_;
  double value_;
  function_variant function_;
};

void CreateTokenMap(std::map<std::string, MyNamespace::Token>& temp_map);

};  // namespace MyNamespace

#endif  // SMARTCALC_MODEL_MATH_TOKEN_H_
