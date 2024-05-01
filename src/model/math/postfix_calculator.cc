#include "postfix_calculator.h"

#include <list>
#include <stdexcept>

#include "token.h"

std::list<MyNamespace::Token>
MyNamespace::PostfixCalculator::ConvertInfixToPostfix(std::list<Token>& input) {
  input_ = input;
  using namespace MyNamespace;
  while (!input_.empty()) {
    switch (input_.front().type()) {
      case Type::kNumber:
      case Type::kUnaryPostfixOperator:
        MoveTokenFromInputToOutput();
        break;
      case Type::kUnaryFunction:
      case Type::kUnaryPrefixOperator:
      case Type::kOpenBracket:
        MoveTokenFromInputToStack();
        break;

      case Type::kBinaryOperator:
        while (
            !operator_stack_.empty() &&
            (operator_stack_.top().type() == Type::kBinaryOperator ||
             operator_stack_.top().type() == Type::kUnaryPrefixOperator) &&
            (operator_stack_.top().precedence() > input_.front().precedence() ||
             (operator_stack_.top().precedence() ==
                  input_.front().precedence() &&
              input_.front().associativity() == Associativity::kLeft))) {
          MoveTokenFromStackToOutput();
        }
        MoveTokenFromInputToStack();
        break;

      case Type::kCloseBracket:
        while (!operator_stack_.empty() &&
               operator_stack_.top().type() != Type::kOpenBracket) {
          MoveTokenFromStackToOutput();
        }
        if (!operator_stack_.empty() &&
            operator_stack_.top().type() == Type::kOpenBracket) {
          operator_stack_.pop();
        } else {
          throw std::logic_error("Open bracket missing");
        }
        if (!operator_stack_.empty() &&
            operator_stack_.top().precedence() == Precedence::kFunction) {
          MoveTokenFromStackToOutput();
        }
        input_.pop_front();
        break;

      default:
        throw std::logic_error("Unsupported token");
    }
  }
  while (!operator_stack_.empty()) {
    if (operator_stack_.top().type() == Type::kOpenBracket) {
      throw std::logic_error("Close bracket missing");
    }
    MoveTokenFromStackToOutput();
  }

  return postfix_;
}

void MyNamespace::PostfixCalculator::MoveTokenFromInputToOutput() {
  postfix_.push_back(input_.front());
  input_.pop_front();
  // !splice!
}

void MyNamespace::PostfixCalculator::MoveTokenFromInputToStack() {
  operator_stack_.push(input_.front());
  input_.pop_front();
  // !splice!
}

void MyNamespace::PostfixCalculator::MoveTokenFromStackToOutput() {
  postfix_.push_back(operator_stack_.top());
  operator_stack_.pop();
  // !splice!
}

double MyNamespace::PostfixCalculator::PostfixNotationCalculation(
    std::list<Token>& postfix, double x_value) {
  postfix_ = postfix;
  using namespace MyNamespace;

  for (auto& token : postfix_) {
    std::visit(
        overloaded{[&](double function) { PushToResult(function); },
                   [&](unary_function function) {
                     PushToResult(function(PopFromResult()));
                   },
                   [&](binary_function function) {
                     double right_argument = PopFromResult();
                     double left_argument = PopFromResult();
                     PushToResult(function(left_argument, right_argument));
                   },
                   [&](auto) { PushToResult(x_value); }},
        token.function());
  }

  return PopFromResult();
}

double MyNamespace::PostfixCalculator::PostfixNotationCalculation(
    std::list<Token>& postfix) {
  return PostfixNotationCalculation(postfix, 0.0);
}

double MyNamespace::PostfixCalculator::PostfixNotationCalculation(
    double x_value) {
  return PostfixNotationCalculation(postfix_, x_value);
}
void MyNamespace::PostfixCalculator::PushToResult(double value) {
  result_.push(value);
}

double MyNamespace::PostfixCalculator::PopFromResult() {
  // !splice! ??
  double value = result_.top();
  result_.pop();
  return value;
}
