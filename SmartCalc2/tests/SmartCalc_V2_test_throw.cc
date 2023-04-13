#include <gtest/gtest.h>

#include "../model/deposit.h"
#include "../model/mathcalculator.h"

TEST(logic_error, character_limit_exceeded) {
  MyNamespace::MathCalculator calc;
  ASSERT_ANY_THROW(
      calc.CalculateAnswer("1234567890+1234567890+1234567890+1234567890+"
                           "1234567890+1234567890+"
                           "1234567890+1234567890+1234567890+"
                           "1234567890+1234567890+1234567890+1234567890+"
                           "1234567890+1234567890+"
                           "1234567890+1234567890+1234567890+"
                           "1234567890+1234567890+1234567890+1234567890+"
                           "1234567890+1234567890+"
                           "1234567890+"));
}

TEST(logic_error, empty_input) {
  MyNamespace::MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer(""));
}

TEST(logic_error, incorrect_symbol) {
  MyNamespace::MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("2 + $"));
}

TEST(logic_error, incorrect_function_name) {
  MyNamespace::MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("2+ sinus(5)"));
}
TEST(logic_error, fail_2) {
  MyNamespace::MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("2.5.4 + 6"));
}

TEST(logic_error, fail_3) {
  MyNamespace::MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer(""));
}

TEST(logic_error, fail_4) {
  MyNamespace::MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("cos()"));
}

TEST(logic_error, fail_5) {
  MyNamespace::MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("2*1+5)"));
}

TEST(logic_error, fail_6) {
  MyNamespace::MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("(2-6"));
}

TEST(logic_error, fail_7) {
  MyNamespace::MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("sqrt2"));
}

TEST(logic_error, fail_8) {
  MyNamespace::MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("22+7 5.4"));
}

TEST(logic_error, fail_9) {
  MyNamespace::MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("100+2+"));
}

TEST(logic_error, fail_10) {
  MyNamespace::MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("*"));
}

TEST(logic_error, fail_11) {
  MyNamespace::MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("2(*2)"));
}

TEST(logic_error, fail_12) {
  MyNamespace::MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("14sin"));
}

TEST(logic_error, fail_13) {
  MyNamespace::MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("1+."));
}

TEST(logic_error, fail_14) {
  MyNamespace::MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("2 2 *"));
}

TEST(logic_error, fail_15) {
  MyNamespace::MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer(" * * 2 2 *"));
}

TEST(logic_error, fail_16) {
  MyNamespace::MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("-"));
}

TEST(logic_error, fail_17) {
  MyNamespace::MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("+"));
}

TEST(logic_error, fail_18) {
  MyNamespace::MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("2+x", "re"));
}

TEST(logic_error, fail_19) {
  MyNamespace::MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("2+x", "1.3.4"));
}

TEST(logic_error, fail_20) {
  MyNamespace::MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("2+x", "$"));
}

TEST(logic_error, fail_21) {
  using namespace MyNamespace;
  MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateGraph("x*x", 1, 0, 10, -10, 100));
  ASSERT_ANY_THROW(calc.CalculateGraph("x*x", 5, 0, 0, -10, 100));
  ASSERT_ANY_THROW(calc.CalculateGraph("x*x", 5, NAN, 0, -10, 100));
}

TEST(logic_error, deposit_fail) {
  using namespace MyNamespace;
  Deposit calc;
  Deposit::MultiMapDate ReplenishmentsList;
  Deposit::MultiMapDate PartialWithdrawalsList;
  PartialWithdrawalsList.insert(
      std::make_pair(Date(28, 01, 2024), std::make_pair(1, 100000000)));
  ASSERT_ANY_THROW(calc.CalculateDeposit(1000000, Date(13, 3, 2023), 2000, 0,
                                         8.13, 0.0, 4, 0, ReplenishmentsList,
                                         PartialWithdrawalsList, 0));
}
