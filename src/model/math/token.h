#ifndef SMARTCALC_MODEL_MATH_TOKEN_H_
#define SMARTCALC_MODEL_MATH_TOKEN_H_

#include <functional>
#include <string>
#include <variant>

namespace MyNamespace {

using unary_function = std::function<double(double)>;
using binary_function = std::function<double(double, double)>;
using function_variant =
    std::variant<double, unary_function, binary_function, nullptr_t>;

enum Precedence {
  kDefault,
  kLow,
  kMedium,
  kHigh,
  kUnaryOperator,
  kFunction,
};

enum Type {
  kNumber,
  kBinaryOperator,
  kUnaryPrefixOperator,
  kUnaryPostfixOperator,
  kUnaryFunction,
  kOpenBracket,
  kCloseBracket,
  kNumTokenTypes,
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
        Associativity associativity, Type type, function_variant function);
  ~Token() = default;

  std::string GetName() const;
  Precedence GetPrecedence() const;
  Associativity GetAssociativity() const;
  Type GetType() const;
  function_variant GetFunction() const;

  void MakeNumber(std::string name, double value);
  void MakeUnaryNegation();

 private:
  std::string name_;
  Precedence precedence_;
  Associativity associativity_;
  Type type_;
  function_variant function_;
};

};  // namespace MyNamespace

long double factorial(long double n);

#endif  // SMARTCALC_MODEL_MATH_TOKEN_H_
