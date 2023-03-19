#include <gtest/gtest.h>

#include "../model/model.h"

TEST(logic_error, character_limit_exceeded) {
  MathCalculator calc;
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
  MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer(""));
}

TEST(logic_error, incorrect_symbol) {
  MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("2 + $"));
}

TEST(logic_error, incorrect_function_name) {
  MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("2+ sinus(5)"));
}
TEST(logic_error, fail_2) {
  MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("2.5.4 + 6"));
}

TEST(logic_error, fail_3) {
  MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer(""));
}

TEST(logic_error, fail_4) {
  MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("cos()"));
}

TEST(logic_error, fail_5) {
  MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("2*1+5)"));
}

TEST(logic_error, fail_6) {
  MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("(2-6"));
}

TEST(logic_error, fail_7) {
  MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("sqrt2"));
}

TEST(logic_error, fail_8) {
  MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("22+7 5.4"));
}

TEST(logic_error, fail_9) {
  MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("100+2+"));
}

TEST(logic_error, fail_10) {
  MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("*"));
}

TEST(logic_error, fail_11) {
  MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("2(*2)"));
}

TEST(logic_error, fail_12) {
  MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("14sin"));
}

TEST(logic_error, fail_13) {
  MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("1+."));
}

TEST(logic_error, fail_14) {
  MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("2 2 *"));
}

TEST(logic_error, fail_15) {
  MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer(" * * 2 2 *"));
}

TEST(logic_error, fail_16) {
  MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("-"));
}

TEST(logic_error, fail_17) {
  MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("+"));
}

TEST(logic_error, fail_18) {
  MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("2+x", "re"));
}

TEST(logic_error, fail_19) {
  MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("2+x", "1.3.4"));
}

TEST(logic_error, fail_20) {
  MathCalculator calc;
  ASSERT_ANY_THROW(calc.CalculateAnswer("2+x", "$"));
}
