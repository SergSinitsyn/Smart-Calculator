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
  std::list<Token> Parsing(std::string input_expression);

private:
  std::list<Token> tokens_;

  static std::map<std::string, Token> token_map_;
  static constexpr bool kLastToken_[kNumTokenTypes] = {
      1, 0, 0, 1, 0, 0, 1}; // TODO replace this

  void ConvertToLowercase(std::string &str);
  std::pair<double, std::string> ReadNumber(std::string &input,
                                            size_t &start_index) const;
  std::string ReadWord(std::string &input, size_t &start_index) const;
  void PushToken(std::string temp);
  void CheckUnaryPlus();
  void CheckUnaryNegation();
  void DeleteSpaces();
};

} // namespace MyNamespace

#endif // SMARTCALC_MODEL_MATH_PARSER_H_