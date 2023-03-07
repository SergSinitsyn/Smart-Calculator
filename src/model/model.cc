#include "model.h"

void Calculator::LoadExpression(const std::string& input_string) {
  CheckLength(input_string);
  input_expression_ = input_string;
  ConvertToLowercase();
  token_map_ = CreateTokenMap();
  Parsing();
  UnarySigns();
  CheckBrackets();
  ShuntingYardAlgorithm();
}

double Calculator::CalculateValue(double x) {
  CheckVariable(x);
  return PostfixNotationCalculation(x);
}

double Calculator::CalculateValue() { return PostfixNotationCalculation(0); }

XYGraph Calculator::CalculateGraph(int number_of_points, double x_start,
                                   double x_end) {
  CheckNumberOfPoints(number_of_points);
  CheckRange(x_start, x_end);
  std::vector<double> x, y;
  for (int i = 0; i < number_of_points; ++i) {
    x.push_back(x_start + (double)i * (x_end - x_start) / number_of_points);
    //    TODO check finite of y
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
  if (input_.empty())
    throw std::logic_error("empty expression");  // TODO print this symbol
}

void Calculator::PushToken(std::string temp) {
  if (auto it = token_map_.find(temp); it != token_map_.end()) {
    if (it->second.GetName() != " ") input_.push(it->second);
  } else {
    throw std::logic_error("incorrect symbol");  // TODO print this symbol
  }
}

void Calculator::ReadWord(std::string& str, size_t& start) {
  std::regex r("([a-z]+)");
  std::sregex_iterator i =
      std::sregex_iterator(str.begin() + start, str.end(), r);
  std::smatch m = *i;
  if (m.size()) {
    start += m.length();
    PushToken(m.str());
  } else {
    throw std::logic_error(
        "incorrect function name");  // TODO print this symbol
  }
}

void Calculator::ReadNumber(std::string& str, size_t& start) {
  std::regex r("\\d+(([.]\\d+)?(e[+-]\\d+)?)?");
  std::sregex_iterator i =
      std::sregex_iterator(str.begin() + start, str.end(), r);
  std::smatch m = *i;
  if (m.size()) {
    start += m.length();
    std::stringstream ss(m.str());
    double d = 0;
    ss >> d;
    Token number;
    number.MakeNumber(d);
    input_.push(number);
  } else {
    throw std::logic_error("incorrect number");  // TODO print this symbol
  }
}

void Calculator::UnarySigns() {
  while (!input_.empty()) {
    std::string input_name = input_.front().GetName();
    if ((input_name == "+" || input_name == "-") &&
        (output_.empty() ||
         !(output_.back().GetPrecedence() == Precedence::kNumber ||
           output_.back().GetName() == ")"))) {
      if (input_name == "-") {
        Token temp;
        temp.MakeUnaryNegation();
        output_.push(temp);
      }
      input_.pop();
    } else {
      output_.push(input_.front());
      input_.pop();
    }
  }
  if (output_.empty()) throw std::logic_error("wrong expression (only +++)");
  input_.swap(output_);
}

void Calculator::CheckBrackets() {
  int bracket_count = 0;
  int function_count = 0;
  while (!input_.empty()) {
    if (input_.front().GetName() == "(") {
      ++bracket_count;
    } else if (input_.front().GetName() == ")") {
      --bracket_count;
      if (bracket_count < 0) {
        throw std::logic_error("open bracket missing");
      }
      if (output_.back().GetName() == "(") {
        throw std::logic_error("empty brackets");
      }
    } else if (input_.front().GetPrecedence() == Precedence::kFunction) {
      ++function_count;
      output_.push(input_.front());
      input_.pop();
      if (input_.front().GetName() == "(") {
        ++bracket_count;
        --function_count;
      } else {
        throw std::logic_error("missing function bracket");
      }
    } else if (input_.front().GetOperationType() == OperationType::kBinary) {
      if (!output_.empty() && output_.back().GetName() == "(") {
        throw std::logic_error("binary_operation_after_opening_bracket");
      }
    } else {
    }
    output_.push(input_.front());
    input_.pop();
  }
  if (bracket_count) {
    throw std::logic_error("close bracket missing");
  }
  if (function_count) {
    throw std::logic_error("function bracket missing");
  }
  input_.swap(output_);
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
        throw std::logic_error("open bracket missing");
      }
      if (!stack_.empty() &&
          stack_.top().GetPrecedence() == Precedence::kFunction) {
        FromStackToOutput();
      }
      input_.pop();
    } else {
      throw std::logic_error("incorrect token");
    }
  }
  while (!stack_.empty()) {
    if (stack_.top().GetName() == "(")
      throw std::logic_error("close bracket missing");

    FromStackToOutput();
  }
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
                             "missing number for function or unary operator");
                       }
                     },
                     [&](fp_2arg fn) {
                       if (result_.size() > 1) {
                         double rhs = FromResult();
                         double lhs = FromResult();
                         ToResult(fn(lhs, rhs));
                       } else {
                         throw std::logic_error(
                             "missing number for binary operator");
                       }
                     },
                     [&](auto fn) {
                       if (fn == nullptr) ToResult();
                     }},
          input_.front().GetFunction());
    }
  }
  if (result_.size() > 1) {
    throw std::logic_error("missing binary operator or function");
  }
  return FromResult();
}
