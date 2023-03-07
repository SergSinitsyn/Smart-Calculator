#include <gtest/gtest.h>

#include "../model/model.h"

#define kAcc 1e-6

TEST(logic_error, character_limit_exceeded) {
  Calculator calc(
      "1234567890+1234567890+1234567890+1234567890+1234567890+1234567890+"
      "1234567890+1234567890+1234567890+"
      "1234567890+1234567890+1234567890+1234567890+1234567890+1234567890+"
      "1234567890+1234567890+1234567890+"
      "1234567890+1234567890+1234567890+1234567890+1234567890+1234567890+"
      "1234567890+");
  ASSERT_ANY_THROW(calc.CalculateValue());
}

TEST(logic_error, empty_input) {
  Calculator calc("");
  ASSERT_ANY_THROW(calc.CalculateValue());
}

TEST(logic_error, incorrect_symbol) {
  Calculator calc("2 + $");
  ASSERT_ANY_THROW(calc.CalculateValue());
}

TEST(logic_error, incorrect_function_name) {
  Calculator calc("2+ sinus(5)");
  ASSERT_ANY_THROW(calc.CalculateValue());
}
TEST(logic_error, fail_2) {
  Calculator calc("2.5.4 + 6");
  ASSERT_ANY_THROW(calc.CalculateValue());
}

TEST(logic_error, fail_3) {
  Calculator calc("");
  ASSERT_ANY_THROW(calc.CalculateValue());
}

TEST(logic_error, fail_4) {
  Calculator calc("cos()");
  ASSERT_ANY_THROW(calc.CalculateValue());
}

TEST(logic_error, fail_5) {
  Calculator calc("2*1+5)");
  ASSERT_ANY_THROW(calc.CalculateValue());
}

TEST(logic_error, fail_6) {
  Calculator calc("(2-6");
  ASSERT_ANY_THROW(calc.CalculateValue());
}

// TEST(logic_error, fail_7) {
//   Calculator calc("sqrt2");
//   ASSERT_ANY_THROW(calc.CalculateValue());
// }

TEST(logic_error, fail_8) {
  Calculator calc("22+7 5.4");
  ASSERT_ANY_THROW(calc.CalculateValue());
}

TEST(logic_error, fail_9) {
  Calculator calc("100+2+");
  ASSERT_ANY_THROW(calc.CalculateValue());
}

// TEST(logic_error, fail_10) {
//   Calculator calc("-");
//   ASSERT_ANY_THROW(calc.CalculateValue());
// }

TEST(logic_error, fail_11) {
  Calculator calc("2(*2)");
  ASSERT_ANY_THROW(calc.CalculateValue());
}

TEST(logic_error, fail_12) {
  Calculator calc("14sin");
  ASSERT_ANY_THROW(calc.CalculateValue());
}

TEST(logic_error, fail_13) {
  Calculator calc("1+.");
  ASSERT_ANY_THROW(calc.CalculateValue());
}

TEST(logic_error, fail_14) {
  Calculator calc("2 2 *");
  ASSERT_ANY_THROW(calc.CalculateValue());
}