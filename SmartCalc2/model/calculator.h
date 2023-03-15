#ifndef _MODEL_CALCULATOR_H_
#define _MODEL_CALCULATOR_H_

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

class Calculator {
 public:
  Calculator() = default;
  ~Calculator() = default;

  void LoadExpression(const std::string& input_string);

  double CalculateValue(double x);
  double CalculateValue();
  XYGraph CalculateGraph(int number_of_points, double x_start, double x_end);

 private:
  void ConvertToLowercase();
  void Parsing();
  void PushToken(std::string temp);
  void ReadNumber(std::string& str, size_t& start);
  void ReadWord(std::string& str, size_t& start);
  void CheckSequence();

  void ShuntingYardAlgorithm();
  void FromInputToOutput();
  void FromInputToStack();
  void FromStackToOutput();

  double PostfixNotationCalculation(double x);
  void ToResult();
  void ToResult(double x);
  double FromResult();

  std::string input_expression_;
  std::map<std::string, Token> token_map_;
  std::queue<Token> input_;
  std::stack<Token> stack_;
  std::queue<Token> output_;
  std::stack<double> result_;

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
   static constexpr  bool kFirstToken_[8] = {1, 0, 0, 0, 1, 1, 1, 0};
   static constexpr  bool kLastToken_[8] = {1, 0, 0, 0, 0, 0, 0, 1};
};

#endif  // _MODEL_CALCULATOR_H_
