#ifndef SMARTCALC_MODEL_MATH_VALIDATOR_H_
#define SMARTCALC_MODEL_MATH_VALIDATOR_H_

#include <queue>

#include "token.h"

namespace MyNamespace {

class Validator {
 public:
  void CheckSequenceOfTokens(std::queue<Token> input);

 private:
  std::queue<Token> input_;
  std::queue<Token> output_;
  // kAdjacencyMatrix_[i][j]: i - token in expression, j - next token in
  // expression
  static constexpr bool kAdjacencyMatrix_[kNumTokenTypes][kNumTokenTypes] = {
      {0, 1, 0, 1, 0, 0, 1},  // kNumber
      {1, 0, 1, 0, 1, 1, 0},  // kBinaryOperator
      {1, 0, 1, 0, 1, 1, 0},  // kUnaryPrefixOperator
      {0, 1, 0, 1, 0, 0, 1},  // kUnaryPostfixOperator
      {0, 0, 0, 0, 0, 1, 0},  // kUnaryFunction
      {1, 0, 1, 0, 1, 1, 0},  // kOpenBracket
      {0, 1, 0, 1, 0, 0, 1},  // kCloseBracket
  };
  static constexpr bool kFirstToken_[kNumTokenTypes] = {1, 0, 1, 0, 1, 1, 0};
  static constexpr bool kLastToken_[kNumTokenTypes] = {1, 0, 0, 1, 0, 0, 1};

  void MoveTokenFromInputToOutput();
  void CheckFirstToken();
  void MoveAllTokensFromInputToOutput();
  void CheckLastToken();
};

}  // namespace MyNamespace

#endif  // SMARTCALC_MODEL_MATH_VALIDATOR_H_