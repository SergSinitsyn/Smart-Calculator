#include "model.h"

Calculator::Calculator(const std::string input_string)
    : error_code_(0), input_expression_(input_string){};

Calculator::~Calculator(){};

Token::Token(){};
Token::Token(std::string type, int precedence, double value, int associativity,
             int operation_type, function_variant function)
    : type_(type),
      precedence_(precedence),
      value_(value),
      associativity_(associativity),
      operation_type_(operation_type),
      function_(function){};

Token::Token(const Token& other)
    : type_(other.type_),
      precedence_(other.precedence_),
      value_(other.value_),
      associativity_(other.associativity_),
      operation_type_(other.operation_type_),
      function_(other.function_){};

Token::~Token(){};

std::string Token::GetType() { return type_; }
int Token::GetPrecedence() { return precedence_; }
double Token::GetValue() { return value_; }
int Token::GetAssociativity() { return associativity_; }
int Token::GetOperationType() { return operation_type_; }
function_variant Token::GetFunction() { return function_; }
void Token::SetValue(double value) { value_ = value; }

void Calculator::CreateTokenMap() {
  using namespace std;
  initializer_list<pair<const string, Token>> list = {
      make_pair("x", Token("x", p_number, 0, a_none, ot_none, nullptr)),
      make_pair("+", Token("+", p_bin_low, 0, a_left, ot_binary, Addition)),
      make_pair("-", Token("-", p_bin_low, 0, a_left, ot_binary, Subtraction)),
      make_pair("*",
                Token("*", p_bin_med, 0, a_left, ot_binary, Multiplication)),
      make_pair("/", Token("/", p_bin_med, 0, a_left, ot_binary, Division)),
      make_pair("^", Token("^", p_bin_hig, 0, a_right, ot_binary, powl)),
      make_pair("mod", Token("mod", p_bin_med, 0, a_left, ot_binary, fmodl)),
      make_pair("cos", Token("cos", p_function, 0, a_right, ot_unary, cosl)),
      make_pair("sin", Token("sin", p_function, 0, a_right, ot_unary, sinl)),
      make_pair("tan", Token("tan", p_function, 0, a_right, ot_unary, tanl)),
      make_pair("acos", Token("acos", p_function, 0, a_right, ot_unary, acosl)),
      make_pair("asin", Token("asin", p_function, 0, a_right, ot_unary, asinl)),
      make_pair("atan", Token("atan", p_function, 0, a_right, ot_unary, atanl)),
      make_pair("sqrt", Token("sqrt", p_function, 0, a_right, ot_unary, sqrtl)),
      make_pair("ln", Token("ln", p_function, 0, a_right, ot_unary, logl)),
      make_pair("log", Token("log", p_function, 0, a_right, ot_unary, log10l)),
      make_pair("(", Token("(", p_bracket, 0, a_none, ot_none, nullptr)),
      make_pair(")", Token(")", p_bracket, 0, a_none, ot_none, nullptr)),
      make_pair("exp", Token("exp", p_function, 0, a_right, ot_unary, expl)),
      make_pair("e", Token("e", p_number, M_E, a_none, ot_none, nullptr)),
      make_pair("pi", Token("pi", p_number, M_PI, a_none, ot_none, nullptr)),
      make_pair("inf",
                Token("inf", p_number, INFINITY, a_none, ot_none, nullptr)),

  };
  token_map_.insert(list);
};

Token Number_("", p_number, 0, a_none, ot_none, nullptr);
Token UnaryPlus_("+", p_unary, 0, a_left, ot_unary, UnaryPlus);
Token UnaryNegation_("-", p_unary, 0, a_left, ot_unary, UnaryNegation);

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
  CreateTokenMap();
  Parsing();
  UnarySigns();
  //   CheckBrackets();
  ShuntingYardAlgorithm();
}

void Calculator::CheckLength() {
  if (input_expression_.size() > MAX) {
    error_code_ = character_limit_exceeded;
    return;
  }
  if (input_expression_.size() == 0) {
    error_code_ = empty_input_string;
    return;
  }
}
void Calculator::CheckVariable(double x) {
  if (x != x) {
    error_code_ = x_is_nan;
    return;
  }
}

bool is_letter(char c) { return (c >= 'a' && c <= 'z'); }
bool is_E(char c) { return (c == 'E' || c == 'e'); }
bool is_pm(char c) { return (c == '+' || c == '-'); }
bool is_number(char c) { return (c == '.' || (c >= '0' && c <= '9')); }
bool is_symbol(char c) {
  return (c == ' ' || (c >= '(' && c <= '+') || c == '-' || c == '/' ||
          c == '^' || c == 'x');
}

double Addition(double a, double b) { return a + b; }
double Subtraction(double a, double b) { return a - b; }
double Multiplication(double a, double b) { return a * b; }
double Division(double a, double b) { return a / b; }
double UnaryPlus(double a) { return a; }
double UnaryNegation(double a) { return -a; }

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
    error_code_ = incorrect_symbol;  // print this symbol
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
    if (input_.front().GetPrecedence() == p_number) {
      FromInputToOutput();
    } else if (input_.front().GetOperationType() == ot_unary) {
      FromInputToStack();
    } else if (input_.front().GetOperationType() == ot_binary) {
      while (!stack_.empty() &&
             (stack_.top().GetOperationType() == ot_binary) &&
             (stack_.top().GetPrecedence() > input_.front().GetPrecedence() ||
              (stack_.top().GetPrecedence() == input_.front().GetPrecedence() &&
               input_.front().GetAssociativity() == a_left))) {
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
      if (!stack_.empty() && stack_.top().GetPrecedence() == p_function) {
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
//     } else if (temp_input.front().priority == p_function) {
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
//       } else if (temp_output.back().priority == p_function) {
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
          !(temp_output.back().GetPrecedence() == p_number ||
            temp_output.back().GetType() == ")")) {
        if (input_type == "-") {
          temp_output.push(UnaryNegation_);
        } else {
          temp_output.push(UnaryPlus_);
        }
        temp_input.pop();
      }
    }
    temp_output.push(temp_input.front());
    temp_input.pop();
  }
  input_.swap(temp_output);
}

double Calculator::PostfixNotationCalculation(double x) {
  input_ = output_;
  while (!input_.empty()) {
    if (input_.front().GetPrecedence() == p_number) {
      if (input_.front().GetType() == "x") {
        ToResult(x);
      } else {
        ToResult();
      }
    } else if (input_.front().GetOperationType() == ot_binary) {
      if (result_.size() >= 2) {
        double value2 = FromResult();
        double value1 = FromResult();
        // std::visit function = input_.front().GetFunction();
        // ToResult(function(value1, value2));
      } else {
        error_code_ = missing_value_for_binary_operator;
        return 0;
      }
    } else if (input_.front().GetOperationType() == ot_unary) {
      if (result_.size() >= 1) {
        // std::visit function = input_.front().GetFunction();
        // ToResult(function(FromResult()));
      } else {
        error_code_ = missing_value_for_unary_operator;
        return 0;
      }
    }
  }
  if (result_.size() > 1) {
    error_code_ = missing_binary_operator;
    return 0;
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

void Calculator::CheckNumberOfPoints(int number_of_points) {
  if (number_of_points < 1) {
    error_code_ = not_a_plot;
    return;
  }
  std::vector<double> x;
  if (number_of_points > x.max_size() / 2.) {  //! ? ?
    error_code_ = exceeded_max_size_of_vector;
    return;
  }
}

void Calculator::CheckRange(double x_start, double x_end) {
  if (x_start == x_end) {
    error_code_ = x_start_equals_x_end;
    return;
  }
}
