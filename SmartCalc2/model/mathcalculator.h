#ifndef _MODEL_MATHCALCULATOR_H_
#define _MODEL_MATHCALCULATOR_H_

#include <algorithm>
#include <array>
#include <cmath>
#include <cstring>
#include <exception>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <regex>
#include <sstream>
#include <stack>
#include <string>
#include <variant>

#include "check.h"
#include "token.h"

using XYGraph = std::pair<std::vector<double>, std::vector<double>>;

class MathCalculator {
 public:
  MathCalculator() = default;
  ~MathCalculator() = default;

  void CalculateAnswer(std::string str);
  void CalculateAnswer(std::string str, std::string str_x);
  void CalculateGraph(std::string str, int number_of_points, double x_start,
                      double x_end);
  double GetAnswer();
  XYGraph GetGraph();

 private:
  void LoadExpression(const std::string& input_string);
  void LoadX(const std::string& input_x);
  void CalculateXY(int number_of_points, double x_start, double x_end);
  std::string ConvertToLowercase(std::string str);
  void Parsing();
  void PushToken(std::string temp);
  double ReadNumber(std::string& str, size_t& start);
  std::string ReadWord(std::string& str, size_t& start);
  void CheckSequence();
  void ShuntingYardAlgorithm();
  void FromInputToOutput();
  void FromInputToStack();
  void FromStackToOutput();
  void ReadX(std::string str);
  double PostfixNotationCalculation(double x);
  void ToResult();
  void ToResult(double x);
  double FromResult();

  double answer_{NAN};
  XYGraph answer_graph_;

  std::string input_expression_;
  std::string input_x_;
  double x_value_{NAN};
  bool correct_load_{false};
  bool correct_load_x_{false};
  std::map<std::string, Token> token_map_;
  std::queue<Token> input_;
  std::stack<Token> stack_;
  std::queue<Token> output_;
  std::stack<double> result_;

  // kAdjacencyMatrix_[i][j]: i - token, j - next token
  static constexpr bool kAdjacencyMatrix_[8][8] = {
      {0, 1, 1, 1, 0, 0, 0, 1},  // kNumber
      {1, 0, 0, 0, 1, 1, 1, 0},  // kLow
      {1, 0, 0, 0, 1, 1, 1, 0},  // kMedium
      {1, 0, 0, 0, 1, 1, 1, 0},  // kHigh
      {1, 0, 0, 0, 1, 1, 1, 0},  // kUnaryOperator
      {0, 0, 0, 0, 0, 0, 1, 0},  // kFunction
      {1, 0, 0, 0, 1, 1, 1, 0},  // kOpenBracket
      {0, 1, 1, 1, 0, 0, 0, 1},  // kCloseBracket
  };
  static constexpr bool kFirstToken_[8] = {1, 0, 0, 0, 1, 1, 1, 0};
  static constexpr bool kLastToken_[8] = {1, 0, 0, 0, 0, 0, 0, 1};
};

#endif  // _MODEL_MATHCALCULATOR_H_
