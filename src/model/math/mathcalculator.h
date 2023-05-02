#ifndef SMARTCALC_MODEL_MATH_MATHCALCULATOR_H_
#define SMARTCALC_MODEL_MATH_MATHCALCULATOR_H_

#include <queue>
#include <stack>

#include "check.h"
#include "token.h"

namespace MyNamespace {
/// @brief template class for redefining lambda expressions in std::visit
/// @tparam ...Ts - accepted type of lambda expression
template <class... Ts>
struct overloaded : Ts... {
  using Ts::operator()...;
};

/// @brief method of redefining the list of arguments of the overloaded method
/// into classes
/// @tparam ...Ts - accepted type of lambda expression
template <class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;
};  // namespace MyNamespace

namespace MyNamespace {
class MathCalculator {
 public:
  using XYGraph = std::pair<std::vector<double>, std::vector<double>>;
  MathCalculator();
  ~MathCalculator() = default;

  void CalculateAnswer(const std::string& str, const std::string& str_x);
  void CalculateAnswer(const std::string& str);
  void CalculateGraph(const std::string& str, int number_of_points,
                      double x_start, double x_end, double y_min, double y_max);
  double GetAnswer() const;
  XYGraph GetGraph() const;

 private:
  void LoadExpression(const std::string& input_string);
  void LoadX(const std::string& input_x);
  std::string ConvertToLowercase(std::string str);
  void Parsing();
  std::pair<double, std::string> ReadNumber(std::string& str,
                                            size_t& start) const;
  std::string ReadWord(std::string& str, size_t& start) const;
  void TryToPushToken(std::string temp);
  void FindSpacesAndUnarySigns();
  void CheckSequenceOfTokens();
  void ShuntingYardAlgorithm();
  void FromInputToOutput();
  void FromInputToStack();
  void FromStackToOutput();
  void ReadX(std::string str);
  double PostfixNotationCalculation(double x_value);
  void PushToResult();
  void PushToResult(double x_value);
  double PopFromResult();
  void CalculateXY(int number_of_points, double x_start, double x_end,
                   double y_min, double y_max);

  double answer_{NAN};
  XYGraph answer_graph_;

  std::string raw_input_expression_;
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
};  // namespace MyNamespace

#endif  // SMARTCALC_MODEL_MATH_MATHCALCULATOR_H_
