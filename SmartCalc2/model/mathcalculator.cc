#include "mathcalculator.h"

MathCalculator::MathCalculator() { CreateTokenMap(token_map_); }

void MathCalculator::CalculateAnswer(std::string str) {
  if (raw_input_expression_ != str || !correct_load_) LoadExpression(str);
  if ("" != input_x_ || !correct_load_x_) LoadX("");
  if (correct_load_ && correct_load_x_)
    answer_ = PostfixNotationCalculation(x_value_);
}

void MathCalculator::CalculateAnswer(std::string str, std::string str_x) {
  if (raw_input_expression_ != str || !correct_load_) LoadExpression(str);
  if (str_x != input_x_ || !correct_load_x_) LoadX(str_x);
  if (correct_load_ && correct_load_x_)
    answer_ = PostfixNotationCalculation(x_value_);
}

void MathCalculator::CalculateGraph(std::string str, int number_of_points,
                                    double x_start, double x_end, double y_min,
                                    double y_max) {
  if (raw_input_expression_ != str || !correct_load_) LoadExpression(str);
  if (correct_load_)
    CalculateXY(number_of_points, x_start, x_end, y_min, y_max);
}

double MathCalculator::GetAnswer() const { return answer_; }

MathCalculator::XYGraph MathCalculator::GetGraph() const {
  return answer_graph_;
}

void MathCalculator::LoadExpression(const std::string& input_string) {
  correct_load_ = false;
  input_ = {};
  stack_ = {};
  output_ = {};
  result_ = {};
  raw_input_expression_ = input_string;
  CheckLength(raw_input_expression_);
  input_expression_ = ConvertToLowercase(raw_input_expression_);
  Parsing();
  FindSpacesAndUnarySigns();
  CheckSequenceOfTokens();
  ShuntingYardAlgorithm();
  correct_load_ = true;
}

void MathCalculator::LoadX(const std::string& input_x) {
  correct_load_x_ = false;
  input_x_ = input_x;
  input_x_ = ConvertToLowercase(input_x_);
  ReadX(input_x_);
  correct_load_x_ = true;
}

std::string MathCalculator::ConvertToLowercase(std::string str) {
  std::string result;
  for (size_t i = 0; i < str.size(); ++i) {
    result.push_back(tolower(str[i]));
  }
  return result;
}

void MathCalculator::Parsing() {
  size_t i = 0;
  while (i < input_expression_.size()) {
    if (isdigit(input_expression_[i])) {
      Token number;
      auto new_number = ReadNumber(input_expression_, i);
      number.MakeNumber(new_number.second, new_number.first);
      input_.push(number);
    } else if (isalpha(input_expression_[i])) {
      PushToken(ReadWord(input_expression_, i));
    } else {
      std::string temp{input_expression_[i++]};
      PushToken(temp);
    }
  }
  if (input_.empty()) throw std::logic_error("Empty expression");
}

std::pair<double, std::string> MathCalculator::ReadNumber(std::string& str,
                                                          size_t& start) const {
  std::regex r("\\d+(([.]\\d+)?(e([+-])?\\d+)?)?");
  std::sregex_iterator i =
      std::sregex_iterator(str.begin() + start, str.end(), r);
  std::smatch match = *i;
  start += match.length();
  std::stringstream ss(match.str());
  double d = 0;
  ss >> d;
  return make_pair(d, match.str());
}

std::string MathCalculator::ReadWord(std::string& str, size_t& start) const {
  std::regex r("([a-z]+)");
  std::sregex_iterator i =
      std::sregex_iterator(str.begin() + start, str.end(), r);
  std::smatch match = *i;
  start += match.length();
  return match.str();
}

void MathCalculator::PushToken(std::string temp) {
  if (auto it = token_map_.find(temp); it != token_map_.end()) {
    input_.push(it->second);
  } else {
    throw std::logic_error("Incorrect symbol: " + temp);
  }
}

void MathCalculator::FindSpacesAndUnarySigns() {
  while (!input_.empty()) {
    std::string name = input_.front().GetName();
    if (name == " ") {
      input_.pop();
    } else if ((name == "+" || name == "-") &&
               (output_.empty() ||
                !kLastToken_[output_.back().GetPrecedence()])) {
      if (name == "-") {
        Token temp;
        temp.MakeUnaryNegation();
        output_.push(temp);
      }
      input_.pop();
    } else {
      FromInputToOutput();
    }
  }
  input_.swap(output_);
  if (input_.empty()) throw std::logic_error("Empty expression");
}

void MathCalculator::CheckSequenceOfTokens() {
  if (!kFirstToken_[input_.front().GetPrecedence()]) {
    throw std::logic_error("Wrong sequence: expression starts with " +
                           input_.front().GetName());
  }
  FromInputToOutput();
  while (!output_.empty() && !input_.empty()) {
    if (!kAdjacencyMatrix_[output_.back().GetPrecedence()]
                          [input_.front().GetPrecedence()]) {
      throw std::logic_error("Wrong sequence: " + output_.back().GetName() +
                             " " + input_.front().GetName());
    }
    FromInputToOutput();
  }
  if (!output_.empty()) {
    if (!kLastToken_[output_.back().GetPrecedence()]) {
      throw std::logic_error("Wrong sequence: expression ends with " +
                             output_.back().GetName());
    }
  }
  input_.swap(output_);
}

void MathCalculator::ShuntingYardAlgorithm() {
  while (!input_.empty()) {
    if (input_.front().GetPrecedence() == Precedence::kNumber) {
      FromInputToOutput();
    } else if (input_.front().GetOperationType() == OperationType::kUnary) {
      FromInputToStack();
    } else if (input_.front().GetOperationType() == OperationType::kBinary) {
      while (!stack_.empty() &&
             (stack_.top().GetOperationType() == OperationType::kBinary ||
              stack_.top().GetPrecedence() == Precedence::kUnaryOperator) &&
             (stack_.top().GetPrecedence() > input_.front().GetPrecedence() ||
              (stack_.top().GetPrecedence() == input_.front().GetPrecedence() &&
               input_.front().GetAssociativity() == Associativity::kLeft))) {
        FromStackToOutput();
      }
      FromInputToStack();
    } else if (input_.front().GetName() == "(") {
      FromInputToStack();
    } else if (input_.front().GetName() == ")") {
      while (!stack_.empty() && stack_.top().GetName() != "(") {
        FromStackToOutput();
      }
      if (!stack_.empty() && stack_.top().GetName() == "(") {
        stack_.pop();
      } else {
        throw std::logic_error("Open bracket missing");
      }
      if (!stack_.empty() &&
          stack_.top().GetPrecedence() == Precedence::kFunction) {
        FromStackToOutput();
      }
      input_.pop();
    }
  }
  while (!stack_.empty()) {
    if (stack_.top().GetName() == "(")
      throw std::logic_error("Close bracket missing");
    FromStackToOutput();
  }
}

void MathCalculator::FromInputToOutput() {
  output_.push(input_.front());
  input_.pop();
}

void MathCalculator::FromInputToStack() {
  stack_.push(input_.front());
  input_.pop();
}

void MathCalculator::FromStackToOutput() {
  output_.push(stack_.top());
  stack_.pop();
}

void MathCalculator::ReadX(std::string str) {
  std::string origin_str = str;
  if (!str.size()) {
    x_value_ = NAN;
    return;
  }
  int sign = 1;
  if (str[0] == '-') {
    sign = -1;
    str.erase(str.begin(), str.begin() + 1);
  }
  if (isdigit(str[0])) {
    std::regex r("([-])?\\d+(([.]\\d+)?(e([+-])?\\d+)?)?");
    std::smatch match;
    std::regex_match(str, match, r);
    if (match.empty()) throw std::logic_error("Incorrect x: " + origin_str);
    std::stringstream ss(match.str());
    ss >> x_value_;
    x_value_ *= sign;
  } else if (isalpha(str[0])) {
    auto it = token_map_.find(str);
    if (it != token_map_.end() && it->second.GetValue()) {
      x_value_ = it->second.GetValue();
      x_value_ *= sign;
    } else {
      throw std::logic_error("Incorrect x: " + origin_str);
    }
  } else {
    throw std::logic_error("Incorrect x: " + origin_str);
  }
}

double MathCalculator::PostfixNotationCalculation(double x) {
  input_ = output_;
  while (!input_.empty()) {
    std::visit(
        overloaded{[&](fp_1arg fn) { PushToResult(fn(PopFromResult())); },
                   [&](fp_2arg fn) {
                     double rhs = PopFromResult();
                     double lhs = PopFromResult();
                     PushToResult(fn(lhs, rhs));
                   },
                   [&](auto) {
                     if (input_.front().GetName() == "x") {
                       PushToResult(x);
                     } else {
                       PushToResult();
                     }
                   }},
        input_.front().GetFunction());
  }
  return PopFromResult();
}

void MathCalculator::PushToResult() {
  result_.push(input_.front().GetValue());
  input_.pop();
}

void MathCalculator::PushToResult(double x) {
  result_.push(x);
  input_.pop();
}

double MathCalculator::PopFromResult() {
  double value = result_.top();
  result_.pop();
  return value;
}

void MathCalculator::CalculateXY(int number_of_points, double x_start,
                                 double x_end, double y_min, double y_max) {
  CheckNumberOfPoints(number_of_points);
  CheckRange(x_start, x_end);

  if (y_min > y_max) {
    std::swap(y_min, y_max);
  }
  y_min *= 1.2;
  y_max *= 1.2;

  std::vector<double> x, y;
  double step = (x_end - x_start) / (number_of_points - 1);
  long double threshold = fabs(step * 1000.0);
  long double delta = 0;
  for (int i = 0; i < number_of_points; ++i) {
    x.push_back(x_start + step * i);
    double y_value = PostfixNotationCalculation(x.back());
    if (i && !std::isnan(y.back())) {
      delta = fabs((y_value - y.back()) / step);
    } else {
      delta = 0;
    }
    if (y_value > y_max || y_value < y_min) {
      y.push_back(std::numeric_limits<double>::quiet_NaN());
    } else if (delta > threshold && (y_value * y.back()) < 0) {
      y.push_back(std::numeric_limits<double>::quiet_NaN());
    } else {
      y.push_back(y_value);
    }
  }
  answer_graph_ = std::make_pair(x, y);
}
