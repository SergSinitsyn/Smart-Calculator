#ifndef SMARTCALC_MODEL_MATH_POSTFIX_CALCULATOR_H_
#define SMARTCALC_MODEL_MATH_POSTFIX_CALCULATOR_H_

#include <queue>
#include <vector>

#include "token.h"

namespace MyNamespace {

/// @brief template class for redefining lambda expressions in std::visit
/// @tparam ...Ts - accepted type of lambda expression
template <class... Ts>
struct overloaded : Ts... {
  using Ts::operator()...;
};

/// @brief method of redefining the list of arguments of the overloaded method
/// into classes
/// @tparam ...Ts - accepted type of lambda expression
template <class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;

class PostfixCalculator {
 public:
  PostfixCalculator();
  ~PostfixCalculator() = default;

  void LoadExpression(std::queue<Token> input);
  void ConvertInfixToPostfix();
  double PostfixNotationCalculation(double x_value);

 private:
  std::queue<Token> input_;
  std::vector<Token> stack_;
  std::queue<Token> output_;
  std::vector<double> result_;
  void MoveTokenFromInputToOutput();
  void MoveTokenFromInputToStack();
  void MoveTokenFromStackToOutput();
  void PushToResult(double value);
  double PopFromResult();
};

}  // namespace MyNamespace

#endif  // SMARTCALC_MODEL_MATH_POSTFIX_CALCULATOR_H_