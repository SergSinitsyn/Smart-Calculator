#ifndef _MODEL_TOKEN_H_
#define _MODEL_TOKEN_H_

#include <cmath>
#include <functional>
#include <map>
#include <string>
#include <variant>

/**
 * @brief Макрос для определения основных арифметических функций с одним
 * аргументом
 * @details lamdas function with one argument
 * @param[in] SIGN operator простых унарных арифметических выражений
 * @return Возращает указатель на унарную функцию
 */
#define lamdas_f1arg(SIGN) [](double src) -> double { return SIGN(src); }

/**
 * @brief Макрос для определения основных арифметических функций с двумя
 * аргументами
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

/// @brief function pointer on a function with one argument
using fp_1arg = std::function<double(double)>;

/// @brief function pointer on a function with two arguments
using fp_2arg = std::function<double(double, double)>;

/// @brief Safe union для указателей на функции с одним и двумя аргументами
/// function pointer variant
using fp_variant = std::variant<fp_1arg, fp_2arg, nullptr_t>;

/// @brief precendence of operation
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

/// @brief operation type
enum OperationType {
  kOperand,
  kUnary,
  kBinary,
};

/// @brief associativity of operation
enum Associativity {
  kNone,
  kLeft,
  kRight,
};

class Token {
 public:
  Token() = default;
  Token(const std::string& name, Precedence precedence,
        Associativity associativity, OperationType operation_type, double value,
        fp_variant function);
  ~Token() = default;

  std::string GetName() const;
  Precedence GetPrecedence() const;
  Associativity GetAssociativity() const;
  OperationType GetOperationType() const;
  double GetValue() const;
  fp_variant GetFunction() const;

  void MakeNumber(std::string name, double value);
  void MakeUnaryNegation();

 private:
  std::string name_;
  Precedence precedence_;
  Associativity associativity_;
  OperationType operation_type_;
  double value_;
  fp_variant function_;
};

void CreateTokenMap(std::map<std::string, Token>& temp_map);

#endif  // _MODEL_TOKEN_H_
