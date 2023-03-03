#ifndef _MODEL_TOKEN_H_
#define _MODEL_TOKEN_H_

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

// /**
//  * @brief Alias для типов данных в таблице приоритетов и указателей на
//  функции
//  * @details function prioritet and pointer type
//  */
// using fun_ptr_t = const QMap<QChar, QPair<QString, QPair<f_prt_t,
// fp_variant>>>;

//   /**
//    * @brief Таблиц приоритетов и указателей на функции
//    * @details table function prioritet and pointer type
//    */
//   static fun_ptr_t m_fun_ptr;

// /**
//  * @brief Таблиц приоритетов и указателей на функции
//  * @details table function prioritet and pointer type
//  */
// static fun_ptr_t m_fun_ptr;

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
  Token(std::string type, Precedence precedence, Associativity associativity,
        OperationType operation_type, double value, fp_variant function);
  Token(const Token& other);

  //! rule of 5
  ~Token();

  std::string GetType();
  int GetPrecedence();
  double GetValue();
  int GetAssociativity();
  int GetOperationType();
  fp_variant GetFunction();
  void SetValue(double value);

 private:
  std::string type_;
  Precedence precedence_;
  Associativity associativity_;
  OperationType operation_type_;
  double value_;
  fp_variant function_;
};

#endif  // _MODEL_TOKEN_H_