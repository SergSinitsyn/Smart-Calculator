#ifndef SMARTCALC_MODEL_MATH_POSTFIX_CALCULATOR_H_
#define SMARTCALC_MODEL_MATH_POSTFIX_CALCULATOR_H_

#include <list>
#include <stack>

#include "token.h"

namespace MyNamespace {

/// @brief template class for redefining lambda expressions in std::visit
/// @tparam ...Ts - accepted type of lambda expression
template <class... Ts> struct overloaded : Ts... { using Ts::operator()...; };

/// @brief method of redefining the list of arguments of the overloaded method
/// into classes
/// @tparam ...Ts - accepted type of lambda expression
template <class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

class PostfixCalculator {
public:
  PostfixCalculator(){};
  ~PostfixCalculator() = default;

  std::list<MyNamespace::Token> ConvertInfixToPostfix(std::list<Token> &);
  double PostfixNotationCalculation(std::list<Token> &, double);
  double PostfixNotationCalculation(std::list<Token> &);
  double PostfixNotationCalculation(double);

private:
  std::list<Token> input_;
  std::stack<Token> operator_stack_;
  std::list<Token> postfix_;
  std::stack<double> result_;

  void MoveTokenFromInputToOutput();
  void MoveTokenFromInputToStack();
  void MoveTokenFromStackToOutput();
  double PopFromResult();
};

} // namespace MyNamespace

#endif // SMARTCALC_MODEL_MATH_POSTFIX_CALCULATOR_H_