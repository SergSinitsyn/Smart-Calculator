#include "model.h"

void Calculator::LoadExpression(const std::string& input_string) {
  CheckLength(input_string);
  input_expression_ = input_string;
  ConvertToLowercase();
  CreateTokenMap(token_map_);
  Parsing();
  Check();
  ShuntingYardAlgorithm();
}

double Calculator::CalculateValue(double x) {
  CheckVariable(x);
  return PostfixNotationCalculation(x);
}

XYGraph Calculator::CalculateGraph(int number_of_points, double x_start,
                                   double x_end) {
  CheckNumberOfPoints(number_of_points);
  CheckRange(x_start, x_end);
  std::vector<double> x, y;
  for (int i = 0; i < number_of_points; ++i) {
    x.push_back(x_start + (double)i * (x_end - x_start) / number_of_points);
    y.push_back(PostfixNotationCalculation(x.back()));
  }
  return make_pair(x, y);
}

void Calculator::ConvertToLowercase() {
  std::string result;
  for (size_t i = 0; i < input_expression_.size(); ++i) {
    result.push_back(tolower(input_expression_[i]));
  }
  input_expression_ = result;
}

void Calculator::Parsing() {
  size_t i = 0;
  while (i < input_expression_.size()) {
    if (isdigit(input_expression_[i])) {
      ReadNumber(input_expression_, i);
    } else if (isalpha(input_expression_[i])) {
      ReadWord(input_expression_, i);
    } else {
      std::string temp{input_expression_[i++]};
      PushToken(temp);
    }
  }
  if (input_.empty()) throw std::logic_error("Empty expression");
}

void Calculator::ReadNumber(std::string& str, size_t& start) {
  std::regex r("\\d+(([.]\\d+)?(e[+-]\\d+)?)?");
  std::sregex_iterator i =
      std::sregex_iterator(str.begin() + start, str.end(), r);
  std::smatch m = *i;
  start += m.length();
  std::stringstream ss(m.str());
  double d = 0;
  ss >> d;
  Token number;
  number.MakeNumber(m.str(), d);
  input_.push(number);
}

void Calculator::ReadWord(std::string& str, size_t& start) {
  std::regex r("([a-z]+)");
  std::sregex_iterator i =
      std::sregex_iterator(str.begin() + start, str.end(), r);
  std::smatch m = *i;
  start += m.length();
  PushToken(m.str());
}

void Calculator::PushToken(std::string temp) {
  if (auto it = token_map_.find(temp); it != token_map_.end()) {
    std::string name = it->second.GetName();
    if (name == " ") {
    } else if ((name == "+" || name == "-") &&
               (input_.empty() ||
                !(input_.back().GetPrecedence() == Precedence::kNumber ||
                  input_.back().GetName() == ")"))) {
      if (name == "-") {
        Token temp;
        temp.MakeUnaryNegation();
        input_.push(temp);
      }
    } else {
      input_.push(it->second);
    }
  } else {
    throw std::logic_error("Incorrect symbol: " + temp);  // TODO
  }
}

void Calculator::Check() {
  if (!first_token_[input_.front().GetPrecedence()]) {
    throw std::logic_error("Wrong sequence: expression starts with " +
                           input_.front().GetName());
  }
  FromInputToOutput();
  while (!input_.empty() && !output_.empty()) {
    if (!adjacency_matrix_[output_.back().GetPrecedence()]
                          [input_.front().GetPrecedence()]) {
      throw std::logic_error("Wrong sequence: " + output_.front().GetName() +
                             " " + input_.front().GetName());
    }
    FromInputToOutput();
  }
  if (!last_token_[output_.back().GetPrecedence()]) {
    throw std::logic_error("Wrong sequence: expression ends with " +
                           output_.back().GetName());
  }
  FromInputToOutput();
  input_.swap(output_);
}

void Calculator::ShuntingYardAlgorithm() {
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
    } else {
      throw std::logic_error("Incorrect token");
    }
  }
  while (!stack_.empty()) {
    if (stack_.top().GetName() == "(")
      throw std::logic_error("Close bracket missing");

    FromStackToOutput();
  }
}

void Calculator::FromInputToOutput() {
  output_.push(input_.front());
  input_.pop();
}

void Calculator::FromInputToStack() {
  stack_.push(input_.front());
  input_.pop();
}

void Calculator::FromStackToOutput() {
  output_.push(stack_.top());
  stack_.pop();
}

double Calculator::PostfixNotationCalculation(double x) {
  input_ = output_;
  while (!input_.empty()) {
    if (input_.front().GetName() == "x") {
      ToResult(x);
    } else {
      std::visit(
          overloaded{[&](fp_1arg fn) {
                       if (result_.size() > 0) {
                         ToResult(fn(FromResult()));
                       } else {
                         throw std::logic_error(
                             "Missing number for unary operator/function: " +
                             input_.front().GetName());
                       }
                     },
                     [&](fp_2arg fn) {
                       if (result_.size() > 1) {
                         double rhs = FromResult();
                         double lhs = FromResult();
                         ToResult(fn(lhs, rhs));
                       } else {
                         throw std::logic_error(
                             "Missing number for binary operator/function: " +
                             input_.front().GetName());
                       }
                     },
                     [&](auto fn) {
                       if (fn == nullptr) ToResult();
                     }},
          input_.front().GetFunction());
    }
  }
  if (result_.size() > 1) {
    throw std::logic_error("Missing binary operator/function");
  }
  return FromResult();
}

void Calculator::ToResult() {
  result_.push(input_.front().GetValue());
  input_.pop();
}

void Calculator::ToResult(double x) {
  result_.push(x);
  input_.pop();
}

double Calculator::FromResult() {
  double value = result_.top();
  result_.pop();
  return value;
}
