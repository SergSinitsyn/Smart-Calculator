#include "model.h"

Calculator::Calculator(const std::string input_string)
    : error_code_(0), input_expression_(input_string){};

Calculator::~Calculator(){};

double Calculator::CalculateValue(double x) {
  CheckVariable(x);
  ConvertToPostfixNotation();  //! converte before x
  return PostfixNotationCalculation(x);
}

std::pair<std::vector<double>, std::vector<double>> Calculator::CalculateGraph(
    int number_of_points, double x_start, double x_end) {
  CheckNumberOfPoints(number_of_points);
  CheckRange(x_start, x_end);
  ConvertToPostfixNotation();  //! converte before x
  std::vector<double> x, y;
  for (int i = 0; i < number_of_points + 1.0; ++i) {
    x.push_back(x_start + (double)i * (x_end - x_start) / number_of_points);
    y.push_back(PostfixNotationCalculation(x.back()));
  }
  return make_pair(x, y);
}

void Calculator::ConvertToPostfixNotation() {
  CheckLength();
  token_map_ = CreateTokenMap();
  Parsing();
  UnarySigns();
  //   CheckBrackets();  // TODO
  ShuntingYardAlgorithm();
}

void Calculator::Parsing() {
  auto it = input_expression_.begin();
  auto end = input_expression_.end();
  while (it != end) {
    if (is_symbol(*it)) {
      std::string temp;
      temp.push_back(*it++);
      PushToken(temp);
    } else if (is_letter(*it)) {
      std::string temp;
      while (is_letter(*it) && (it != end)) {
        temp.push_back(*it++);
      }
      PushToken(temp);
    } else if (is_number(*it)) {
      std::string temp;
      while (is_number(*it) && (it != end)) {
        temp.push_back(*it++);
        if (is_E(*it)) {
          temp.push_back(*it++);
          if (is_pm(*it)) {
            temp.push_back(*it++);
          }
        }
      }
      PushNumber(temp);
    } else {
      error_code_ = incorrect_symbol;
      return;
    }
  }
}

void Calculator::PushToken(std::string temp) {
  if (auto it = token_map_.find(temp); it != token_map_.end()) {
    // std::cout << "Found " << it->first << '\n'; //! delete
    if (it->second.GetType() != " ") input_.push(it->second);  //! check
  } else {
    error_code_ = incorrect_symbol;  // TODO print this symbol
    return;
  }
}

void Calculator::PushNumber(std::string temp) {
  std::stringstream ss(temp);
  double d = 0;
  ss >> d;
  //   std::cout << "Found " << d << '\n';  //! delete
  Token value(Number_);
  value.SetValue(d);
  input_.push(value);
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
      while (
          !stack_.empty() &&
          ((stack_.top().GetOperationType() == OperationType::kBinary) &&
           (stack_.top().GetPrecedence() > input_.front().GetPrecedence() ||
            (stack_.top().GetPrecedence() == input_.front().GetPrecedence() &&
             input_.front().GetAssociativity() == Associativity::kLeft)))) {
        FromStackToOutput();
      }
      FromInputToStack();
    } else if (input_.front().GetType() == "(") {
      FromInputToStack();
    } else if (input_.front().GetType() == ")") {
      while (!stack_.empty() && stack_.top().GetType() != "(") {
        FromStackToOutput();
      }
      if (!stack_.empty() && stack_.top().GetType() == "(") {
        stack_.pop();
      } else {
        error_code_ = open_bracket_missing;
        return;
      }
      if (!stack_.empty() &&
          stack_.top().GetPrecedence() == Precedence::kFunction) {
        FromStackToOutput();
      }
      input_.pop();
    } else {
      error_code_ = incrorrect_lexem;
      return;
    }
  }
  while (!stack_.empty()) {
    if (stack_.top().GetType() == "(") {
      error_code_ = close_bracket_missing;
      return;
    }
    FromStackToOutput();
  }
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

void Calculator::UnarySigns() {
  std::queue temp_input(input_);
  std::queue<Token> temp_output;
  while (!temp_input.empty()) {
    std::string input_type = temp_input.front().GetType();
    if (input_type == "+" || input_type == "-") {
      if (temp_output.empty() ||
          !(temp_output.back().GetPrecedence() ==
                Precedence::kNumber ||  //! operation type operand
            temp_output.back().GetType() == ")")) {
        if (input_type == "-") {
          temp_output.push(UnaryNegation_);
        }
        temp_input.pop();
      }
    }
    temp_output.push(temp_input.front());
    temp_input.pop();
  }
  input_.swap(temp_output);
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
    if (input_.front().GetType() == "x") {
      ToResult(x);
    } else {
      std::visit(overloaded{[&](fp_1arg fn) { ToResult(fn(FromResult())); },
                            [&](fp_2arg fn) {
                              double rhs = FromResult();
                              double lhs = FromResult();
                              ToResult(fn(lhs, rhs));
                            },
                            [&](auto fn) { ToResult(); }},
                 input_.front().GetFunction());
    }
  }
  if (result_.size() > 1) {
    error_code_ = missing_binary_operator;
    return 0;
  }
  return FromResult();
}

bool is_letter(char c) { return (c >= 'a' && c <= 'z'); }
bool is_E(char c) { return (c == 'E' || c == 'e'); }
bool is_pm(char c) { return (c == '+' || c == '-'); }
bool is_number(char c) { return (c == '.' || (c >= '0' && c <= '9')); }
bool is_symbol(char c) {
  return (c == ' ' || (c >= '(' && c <= '+') || c == '-' || c == '/' ||
          c == '^' || c == 'x');
}
