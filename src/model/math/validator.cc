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

void MyNamespace::Validator::CheckX(std::list<Token> &tokens) {
  if (std::any_of(tokens.begin(), tokens.end(),
                  [](const Token &token) { return token.name() == "x"; })) {
    throw std::logic_error("Incorrect variable! Use 'x' only in expression.");
  }
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
  auto current = tokens.begin();
  auto next = tokens.begin();
  ++next;
  for (; next != tokens.end(); ++current, ++next) {
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

} // namespace MyNamespace
