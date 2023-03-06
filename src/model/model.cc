#include "model.h"

Calculator::Calculator(const std::string input_string) {
  input_expression_ = input_string;
};

double Calculator::CalculateValue(double x) {
  CheckVariable(x);
  ConvertToPostfixNotation();
  return PostfixNotationCalculation(x);
}

double Calculator::CalculateValue() {
  ConvertToPostfixNotation();
  return PostfixNotationCalculation(0);
}

XYGraph Calculator::CalculateGraph(int number_of_points, double x_start,
                                   double x_end) {
  CheckNumberOfPoints(number_of_points);
  CheckRange(x_start, x_end);
  ConvertToPostfixNotation();
  std::vector<double> x, y;
  for (int i = 0; i < number_of_points + 1.0; ++i) {
    x.push_back(x_start + (double)i * (x_end - x_start) / number_of_points);
    //    TODO check finite of y
    y.push_back(PostfixNotationCalculation(x.back()));
  }
  return make_pair(x, y);
}

void Calculator::ConvertToPostfixNotation() {
  CheckLength(input_expression_);
  ConvertToLowercase();
  token_map_ = CreateTokenMap();
  Parsing();
  UnarySigns();
  //   CheckBrackets();  // TODO
  ShuntingYardAlgorithm();
}

void Calculator::ConvertToLowercase() {
  std::string result;
  for (size_t i = 0; i < input_expression_.size(); ++i) {
    result.push_back(tolower(input_expression_[i]));
  }
  input_expression_ = result;
}

void Calculator::Parsing() {
  for (size_t i = 0; i < input_expression_.size();) {
    if (is_symbol(input_expression_[i])) {
      std::string temp;
      temp.push_back(input_expression_[i]);
      ++i;
      PushToken(temp);
    } else if (is_letter(input_expression_[i])) {
      std::string temp;
      while (is_letter(input_expression_[i]) && i < input_expression_.size()) {
        temp.push_back(input_expression_[i]);
        ++i;
      }
      PushToken(temp);
    } else if (isdigit(input_expression_[i])) {
      PushNumber(input_expression_, i);
    } else {
      throw std::logic_error("incorrect symbol");  // TODO print this symbol
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

void Calculator::PushNumber(std::string& str, size_t& start) {
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
  std::queue<Token> temp_input;
  temp_input.swap(input_);
  std::queue<Token> temp_output;
  while (!temp_input.empty()) {
    std::string input_type = temp_input.front().GetName();
    if (input_type == "+" || input_type == "-") {
      if (temp_output.empty() ||
          !(temp_output.back().GetPrecedence() ==
                Precedence::kNumber ||  //! operation type operand
            temp_output.back().GetName() == ")")) {
        if (input_type == "-") {
          Token temp;
          temp.MakeUnaryNegation();
          temp_output.push(temp);
        }
        temp_input.pop();
      }
    }
    temp_output.push(temp_input.front());
    temp_input.pop();
  }
  input_.swap(temp_output);
}

// void Calculator::CheckBrackets() {
//   std::queue temp_input(input);
//   std::queue<OldToken> temp_output;
//   int bracket_count = 0;
//   int function_count = 0;
//   while (!temp_input.empty()) {
//     if (temp_input.front().type == t_bra) {
//       ++bracket_count;
//     } else if (temp_input.front().type == t_ket) {
//       --bracket_count;
//       if (bracket_count < 0) {
//         error_code_ = open_bracket_missing;
//         return;
//       }
//       if (temp_output.back().type == t_bra) {
//         error_code_ = empty_brackets;
//         return;
//       }
//     } else if (temp_input.front().priority == kFunction) {
//       ++function_count;
//     }
//     if (!temp_output.empty()) {
//       if (temp_output.back().type == t_bra) {
//         if (temp_input.front().priority == p_add ||
//             temp_input.front().priority == p_mult ||
//             temp_input.front().priority == p_pow) {
//           error_code_ = binary_operation_after_opening_bracket;
//           return;
//         }
//       } else if (temp_output.back().priority == kFunction) {
//         if (temp_input.front().type != t_bra) {
//           error_code_ = functions_braket_missing;
//           return;
//         } else {
//           --function_count;
//         }
//       }
//     }
//     temp_output.push(temp_input.front());
//     temp_input.pop();
//   }
//   if (bracket_count) {
//     error_code_ = close_bracket_missing;
//     return;
//   }
//   if (function_count) {
//     error_code_ = functions_braket_missing;
//     return;
//   }
//   input.swap(temp_output);
// }

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

bool is_letter(char c) {
  return (c >= 'a' && c <= 'z');
}  // TODO add hight letters

bool is_symbol(char c) {
  return (c == ' ' || (c >= '(' && c <= '+') || c == '-' || c == '/' ||
          c == '^' || c == 'x');
}
