#include "validator.h"

#include <algorithm>
#include <queue>
#include <stdexcept>
#include <string>

#include "token.h"

namespace MyNamespace {

void MyNamespace::Validator::CheckSequenceOfTokens(std::queue<Token> input) {
  input_ = input;
  output_ = {};

  CheckFirstToken();
  MoveAllTokensFromInputToOutput();
  CheckLastToken();
}

void MyNamespace::Validator::CheckFirstToken() {
  if (!kFirstToken_[input_.front().GetType()]) {
    throw std::logic_error("Wrong sequence: expression starts with " +
                           input_.front().GetName());
  }
}

void MyNamespace::Validator::MoveAllTokensFromInputToOutput() {
  MoveTokenFromInputToOutput();
  while (!input_.empty()) {
    if (!kAdjacencyMatrix_[output_.back().GetType()]
                          [input_.front().GetType()]) {
      throw std::logic_error("Wrong sequence: " + output_.back().GetName() +
                             " " + input_.front().GetName());
    }
    MoveTokenFromInputToOutput();
  }
}

void MyNamespace::Validator::CheckLastToken() {
  if (!kLastToken_[output_.back().GetType()]) {
    throw std::logic_error("Wrong sequence: expression ends with " +
                           output_.back().GetName());
  }
}

void MyNamespace::Validator::MoveTokenFromInputToOutput() {
  output_.push(input_.front());
  input_.pop();
}

}  // namespace MyNamespace
