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

}; // namespace MyNamespace

namespace MyNamespace {
class Token {
public:
  Token() = delete;
  Token(const std::string &name, Precedence precedence,
        Associativity associativity, Type type, function_variant function);
  ~Token() = default;

  std::string name() const;
  Precedence precedence() const;
  Associativity associativity() const;
  Type type() const;
  function_variant function() const;

  void TransformToUnaryNegation();

private:
  std::string name_;
  Precedence precedence_;
  Associativity associativity_;
  Type type_;
  function_variant function_;
};

}; // namespace MyNamespace

#endif // SMARTCALC_MODEL_MATH_TOKEN_H_
