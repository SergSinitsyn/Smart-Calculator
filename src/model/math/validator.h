#ifndef SMARTCALC_MODEL_MATH_VALIDATOR_H_
#define SMARTCALC_MODEL_MATH_VALIDATOR_H_

#include <list>

#include "token.h"

namespace MyNamespace {

class Validator {
public:
  void CheckSequenceOfTokens(std::list<Token> &);
  void CheckX(std::list<Token> &);

private:
  // kAdjacencyMatrix_[i][j]: i - token in expression, j - next token in
  // expression
  static constexpr bool kAdjacencyMatrix_[kNumTokenTypes][kNumTokenTypes] = {
      {0, 1, 0, 1, 0, 0, 1}, // kNumber
      {1, 0, 1, 0, 1, 1, 0}, // kBinaryOperator
      {1, 0, 1, 0, 1, 1, 0}, // kUnaryPrefixOperator
      {0, 1, 0, 1, 0, 0, 1}, // kUnaryPostfixOperator
      {0, 0, 0, 0, 0, 1, 0}, // kUnaryFunction
      {1, 0, 1, 0, 1, 1, 0}, // kOpenBracket
      {0, 1, 0, 1, 0, 0, 1}, // kCloseBracket
  };

  void CheckFirstToken(std::list<Token> &);
  void CheckTokens(std::list<Token> &);
  void CheckLastToken(std::list<Token> &);
};

} // namespace MyNamespace

#endif // SMARTCALC_MODEL_MATH_VALIDATOR_H_