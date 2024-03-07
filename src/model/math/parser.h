#ifndef SMARTCALC_MODEL_MATH_PARSER_H_
#define SMARTCALC_MODEL_MATH_PARSER_H_

#include <exception>
#include <map>
#include <queue>
#include <regex>
#include <sstream>
#include <string>

#include "token.h"

namespace MyNamespace {

class Parser {
 public:
  Parser();
  std::queue<Token> Parsing(std::string input_expression);
  double ReadX(std::string str);

 private:
  std::queue<Token> input_;
  std::queue<Token> output_;
  const std::map<std::string, Token> token_map_;
  static constexpr bool kLastToken_[kNumTokenTypes] = {1, 0, 0, 1, 0, 0, 1};

  std::string ConvertToLowercase(std::string str);
  std::pair<double, std::string> ReadNumber(std::string& input,
                                            size_t& start_index) const;
  std::string ReadWord(std::string& input, size_t& start_index) const;
  void PushToken(std::string temp);
  void FindUnarySigns();
  void DeleteSpaces();
  void MoveTokenFromInputToOutput();
};

}  // namespace MyNamespace

#endif  // SMARTCALC_MODEL_MATH_PARSER_H_