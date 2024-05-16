#include "validator.h"

#include <algorithm>
#include <iostream>
#include <queue>
#include <stdexcept>
#include <string>

#include "token.h"

namespace MyNamespace {

void MyNamespace::Validator::CheckSequenceOfTokens(std::list<Token> &tokens) {
  if (tokens.empty()) {
    throw std::logic_error("Incorrect expression!");
  }
  CheckFirstToken(tokens);
  CheckTokens(tokens);
  CheckLastToken(tokens);
}

bool MyNamespace::Validator::FindX(std::list<Token> &tokens) {
  if (std::any_of(tokens.begin(), tokens.end(),
                  [](const Token &token) { return token.name() == "x"; })) {
    return true;
  }
  return false;
}

void MyNamespace::Validator::CheckFirstToken(std::list<Token> &tokens) {
  if (!kAdjacencyMatrix_[kOpenBracket][tokens.front().type()]) {
    throw std::logic_error("Wrong sequence: expression starts with " +
                           tokens.front().name());
  }
}

void MyNamespace::Validator::CheckTokens(std::list<Token> &tokens) {
  if (tokens.size() < 2) {
    return;
  }

  for (auto current = tokens.begin(), next = ++tokens.begin();
       next != tokens.end(); ++current, ++next) {
    if (!kAdjacencyMatrix_[current->type()][next->type()]) {
      throw std::logic_error("Wrong sequence: " + current->name() + " " +
                             next->name());
    }
  }
}

void MyNamespace::Validator::CheckLastToken(std::list<Token> &tokens) {
  if (!kAdjacencyMatrix_[tokens.back().type()][kCloseBracket]) {
    throw std::logic_error("Wrong sequence: expression ends with " +
                           tokens.back().name());
  }
}

}  // namespace MyNamespace
