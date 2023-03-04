#ifndef _MODEL_TOKEN_H_
#define _MODEL_TOKEN_H_

#include <cmath>
// #include <exception>
#include <functional>
#include <string>
#include <variant>

/**
 * @brief Макрос для определения основных арифметических функций с одним
 * аргументом в таблице fun_ptr_t
 * @details lamdas function with one argument
 * @param[in] SIGN operator простых унарных арифметических выражений
 * @return Возращает указатель на унарную функцию
 */
#define lamdas_f1arg(SIGN) [](double src) -> double { return SIGN(src); }

/**
 * @brief Макрос для определения основных арифметических функций с двумя
 * аргументами в таблице fun_ptr_t
 * @details lamdas function with two arguments
 * @param[in] SIGN operator простых бинарных арифметических выражений
 * @return Возращает указатель на бинарную функцию
 */
#define lamdas_f2arg(SIGN) \
  [](double lhs, double rhs) -> double { return lhs SIGN rhs; }

/// @brief Шаблонный класс для переопределения лямда-выражений в std::visit
/// @tparam ...Ts - принемаемый тип лямда-выражения
template <class... Ts>
struct overloaded : Ts... {
  using Ts::operator()...;
};

/// @brief Метод переопределения списка агрументов метода overloaded в классы
/// @tparam ...Ts - принемаемый тип лямда-выражения
template <class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;

/// @brief function cast on a function with one argument
using fcast_1arg = double (*)(double);

/// @brief function cast on a function with two arguments
using fcast_2arg = double (*)(double, double);

/// @brief function points on a function with one argument
using fp_1arg = std::function<double(double)>;

/// @brief function pointer on a function with two arguments
using fp_2arg = std::function<double(double, double)>;

/// @brief Safe union для указателей на функции с одним и двумя аргументами
/// function pointer variant
using fp_variant = std::variant<fp_1arg, fp_2arg, nullptr_t>;

enum Precedence {
  kNumber,
  kLow,
  kMedium,
  kHigh,
  kUnaryOperator,
  kFunction,
  kBracket,
};

enum OperationType {
  kOperand,
  kUnary,
  kBinary,
};

enum Associativity {
  kNone,
  kLeft,
  kRight,
};

class Token {
 public:
  Token();
  Token(std::string name, Precedence precedence, Associativity associativity,
        OperationType operation_type, double value, fp_variant function);
  Token(const Token& other);

  //! rule of 5
  ~Token();

  std::string GetName();
  int GetPrecedence();
  double GetValue();
  int GetAssociativity();
  int GetOperationType();
  fp_variant GetFunction();
  void SetValue(double value);

 private:
  std::string name_;
  Precedence precedence_;
  Associativity associativity_;
  OperationType operation_type_;
  double value_;
  fp_variant function_;
};

Token Number_("", kNumber, kNone, kOperand, 0, nullptr);
Token UnaryNegation_("-", kUnaryOperator, kLeft, kUnary, 0, lamdas_f1arg(-));

std::map<std::string, Token> CreateTokenMap();

#endif  // _MODEL_TOKEN_H_