#ifndef SMARTCALC_MODEL_MATH_TOKEN_H_
#define SMARTCALC_MODEL_MATH_TOKEN_H_

#include <functional>
#include <map>
#include <string>
#include <variant>

namespace MyNamespace {
/// @brief Макрос для определения основных арифметических функций с одним
/// аргументом
/// @details lamdas function with one argument
/// @param[in] SIGN operator простых унарных арифметических выражений
/// @return Возращает указатель на унарную функцию
#define lamdas_f1arg(SIGN) \
  [](double argument) -> double { return SIGN(argument); }

/// @brief Макрос для определения основных арифметических функций с двумя
/// аргументами
/// @details lamdas function with two arguments
/// @param[in] SIGN operator простых бинарных арифметических выражений
/// @return Возращает указатель на бинарную функцию
#define lamdas_f2arg(SIGN)                                    \
  [](double left_argument, double right_argument) -> double { \
    return left_argument SIGN right_argument;                 \
  }

/// @brief function cast on a function with one argument
using unary_func = double (*)(double);

/// @brief function cast on a function with two arguments
using binary_func = double (*)(double, double);

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

/// @brief function pointer on a function with one argument
using unary_function_pointer = std::function<double(double)>;

/// @brief function pointer on a function with two arguments
using binary_function_pointer = std::function<double(double, double)>;

/// @brief Safe union для указателей на функции с одним и двумя аргументами
/// function pointer variant
using function_pointer_variant =
    std::variant<unary_function_pointer, binary_function_pointer, nullptr_t>;

enum Precedence {
  kNumber,
  kLow,
  kMedium,
  kHigh,
  kUnaryOperator,
  kFunction,
  kOpenBracket,
  kCloseBracket,
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

};  // namespace MyNamespace

namespace MyNamespace {
class Token {
 public:
  Token() = default;
  Token(const std::string& name, Precedence precedence,
        Associativity associativity, OperationType operation_type, double value,
        function_pointer_variant function);
  ~Token() = default;

  std::string GetName() const;
  Precedence GetPrecedence() const;
  Associativity GetAssociativity() const;
  OperationType GetOperationType() const;
  double GetValue() const;
  function_pointer_variant GetFunction() const;

  void MakeNumber(std::string name, double value);
  void MakeUnaryNegation();

 private:
  std::string name_;
  Precedence precedence_;
  Associativity associativity_;
  OperationType operation_type_;
  double value_;
  function_pointer_variant function_;
};

void CreateTokenMap(std::map<std::string, MyNamespace::Token>& temp_map);

};  // namespace MyNamespace

#endif  // SMARTCALC_MODEL_MATH_TOKEN_H_
