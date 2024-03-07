#include "postfix_calculator.h"

#include <queue>
#include <stdexcept>
#include <vector>

#include "token.h"

MyNamespace::PostfixCalculator::PostfixCalculator(){};

void MyNamespace::PostfixCalculator::LoadExpression(std::queue<Token> input) {
  input_ = input;
}

void MyNamespace::PostfixCalculator::ConvertInfixToPostfix() {
  using namespace MyNamespace;
  while (!input_.empty()) {
    switch (input_.front().GetType()) {
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
            !stack_.empty() &&
            (stack_.back().GetType() == Type::kBinaryOperator ||
             stack_.back().GetType() == Type::kUnaryPrefixOperator) &&
            (stack_.back().GetPrecedence() > input_.front().GetPrecedence() ||
             (stack_.back().GetPrecedence() == input_.front().GetPrecedence() &&
              input_.front().GetAssociativity() == Associativity::kLeft))) {
          MoveTokenFromStackToOutput();
        }
        MoveTokenFromInputToStack();
        break;
      case Type::kCloseBracket:
        while (!stack_.empty() &&
               stack_.back().GetType() != Type::kOpenBracket) {
          MoveTokenFromStackToOutput();
        }
        if (!stack_.empty() && stack_.back().GetType() == Type::kOpenBracket) {
          stack_.pop_back();
        } else {
          throw std::logic_error("Open bracket missing");
        }
        if (!stack_.empty() &&
            stack_.back().GetPrecedence() == Precedence::kFunction) {
          MoveTokenFromStackToOutput();
        }
        input_.pop();
        break;
      default:
        break;
    }
  }
  while (!stack_.empty()) {
    if (stack_.back().GetType() == Type::kOpenBracket) {
      throw std::logic_error("Close bracket missing");
    }
    MoveTokenFromStackToOutput();
  }
}

void MyNamespace::PostfixCalculator::MoveTokenFromInputToOutput() {
  output_.push(input_.front());
  input_.pop();
}

void MyNamespace::PostfixCalculator::MoveTokenFromInputToStack() {
  stack_.push_back(input_.front());
  input_.pop();
}

void MyNamespace::PostfixCalculator::MoveTokenFromStackToOutput() {
  output_.push(stack_.back());
  stack_.pop_back();
}

double MyNamespace::PostfixCalculator::PostfixNotationCalculation(
    double x_value) {
  using namespace MyNamespace;
  input_ = output_;
  while (!input_.empty()) {
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
        input_.front().GetFunction());
  }
  return PopFromResult();
}
void MyNamespace::PostfixCalculator::PushToResult(double value) {
  result_.push_back(value);
  input_.pop();
}

double MyNamespace::PostfixCalculator::PopFromResult() {
  double value = result_.back();
  result_.pop_back();
  return value;
}
