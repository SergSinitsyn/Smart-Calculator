#ifndef MODEL_MODEL_H_
#define MODEL_MODEL_H_

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

#define MAX 256

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
};

enum precedence {
  p_number,
  p_bin_low,
  p_bin_med,
  p_bin_hig,
  p_unary,
  p_function,
  p_bracket,
};

enum operation_type {
  ot_none,
  ot_unary,
  ot_binary,
};

enum associativity {
  a_none,
  a_left,
  a_right,
};

using function_1arg = std::function<double(double)>;
using function_2arg = std::function<double(double, double)>;
using function_cast_1arg = double (*)(double);
using function_cast_2arg = double (*)(double, double);
using function_variant = std::variant<nullptr_t, function_1arg, function_2arg>;

double Addition(double a, double b);        //!
double Subtraction(double a, double b);     //!
double Multiplication(double a, double b);  //!
double Division(double a, double b);        // !
double UnaryPlus(double a);                 //!
double UnaryNegation(double a);             //!

bool is_number(char c);
bool is_symbol(char c);
bool is_letter(char c);
bool is_E(char c);
bool is_pm(char c);

class Token {
 public:
  Token();
  Token(std::string type, int precedence, double value, int associativity,
        int operation_type, function_variant function);
  Token(const Token& other);

  //! rule of 5
  ~Token();

  std::string GetType();
  int GetPrecedence();
  double GetValue();
  int GetAssociativity();
  int GetOperationType();
  function_variant GetFunction();
  void SetValue(double value);

 private:
  std::string type_;
  int precedence_;
  double value_;
  int associativity_;
  int operation_type_;
  function_variant function_;
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

  void CheckVariable(double x);
  void CheckLength();
  void CheckNumberOfPoints(int size);
  void CheckRange(double x_start, double x_end);

  void CreateTokenMap();
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

  int error_code_;
  std::string input_expression_;
  std::map<std::string, Token> token_map_;
  std::queue<Token> input_;
  std::stack<Token> stack_;
  std::queue<Token> output_;
  std::stack<double> result_;

  //   Token Number_;
  //   Token UnaryPlus_;
  //   Token UnaryNegation_;
};

#endif  // MODEL_MODEL_H_