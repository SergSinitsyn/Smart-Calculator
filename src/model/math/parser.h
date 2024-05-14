#ifndef SMARTCALC_MODEL_MATH_PARSER_H_
#define SMARTCALC_MODEL_MATH_PARSER_H_

#include <exception>
#include <list>
#include <map>
#include <regex>
#include <sstream>
#include <string>

#include "token.h"

namespace MyNamespace {

class Parser {
 public:
  Parser(){};
  std::list<Token> Parsing(const std::string &);

 private:
  size_t current_index_ = 0;
  std::string expression_{};
  std::list<Token> tokens_;

  static std::map<std::string, Token> token_map_;
  static constexpr bool kLastToken_[kNumTokenTypes] = {
      1, 0, 0, 1, 0, 0, 1};  // TODO replace this

  void ConvertToLowercase(std::string &);
  std::pair<double, std::string> ReadNumber();
  std::string ReadWord();
  void PushToken(const std::string &);
  void DeleteSpaces();
  void CheckUnaryPlus();
  void CheckUnaryNegation();
};

};  // namespace MyNamespace

#endif  // SMARTCALC_MODEL_MATH_PARSER_H_