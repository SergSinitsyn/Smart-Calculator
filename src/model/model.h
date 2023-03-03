#ifndef _MODEL_MODEL_H_
#define _MODEL_MODEL_H_

#include <array>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>  // for scientific notation
#include <stack>
#include <string>
#include <variant>

#include "check.h"
#include "other.h"
#include "token.h"

enum error_list {
  no_errors,
  empty_input_string,
  character_limit_exceeded,
  incorrect_symbol,
  incrorrect_lexem,
  uncorrect_function_name,
  more_then_one_dot_in_number,
  empty_brackets,
  open_bracket_missing,
  close_bracket_missing,
  functions_braket_missing,
  missing_binary_operator,
  missing_value_for_binary_operator,
  missing_value_for_unary_operator,
  binary_operation_after_opening_bracket,
  dot_is_not_a_number,
  not_a_plot,
  x_start_equals_x_end,
  exceeded_max_size_of_vector,
  x_is_nan,
  sss,
};

class Calculator {
 public:
  //   Calculator();
  Calculator(const std::string input_string);
  //   Calculator(const Calculator &other);
  //   Calculator(Calculator &&other);
  //   Calculator &operator=(const Calculator &other);
  //   Calculator &operator=(Calculator &&other);
  ~Calculator();
  //! rule of 5

  double CalculateValue(double x);
  std::pair<std::vector<double>, std::vector<double>> CalculateGraph(
      int number_of_points, double x_start, double x_end);

 private:
  void ConvertToPostfixNotation();
  double PostfixNotationCalculation(double x);

  void Parsing();
  void PushNumber(std::string temp);
  void PushToken(std::string temp);
  //   void CheckBrackets();  //!
  void UnarySigns();  //!

  void ShuntingYardAlgorithm();
  void FromInputToOutput();
  void FromInputToStack();
  void FromStackToOutput();

  void ToResult();
  void ToResult(double x);
  double FromResult();

  double calc(double x);  //!
  int error_code_;
  std::string input_expression_;
  std::map<std::string, Token> token_map_;
  std::queue<Token> input_;
  std::stack<Token> stack_;
  std::queue<Token> output_;
  std::stack<double> result_;
};

#endif  // MODEL_MODEL_H_