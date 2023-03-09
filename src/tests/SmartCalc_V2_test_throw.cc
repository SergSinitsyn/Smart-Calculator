#include <gtest/gtest.h>

#include "../model/calculator.h"

TEST(logic_error, character_limit_exceeded) {
  Calculator calc;
  ASSERT_ANY_THROW(calc.LoadExpression(
      "1234567890+1234567890+1234567890+1234567890+1234567890+1234567890+"
      "1234567890+1234567890+1234567890+"
      "1234567890+1234567890+1234567890+1234567890+1234567890+1234567890+"
      "1234567890+1234567890+1234567890+"
      "1234567890+1234567890+1234567890+1234567890+1234567890+1234567890+"
      "1234567890+");
                   calc.CalculateValue());
}

TEST(logic_error, empty_input) {
  Calculator calc;
  ASSERT_ANY_THROW(calc.LoadExpression(""); calc.CalculateValue());
}

TEST(logic_error, incorrect_symbol) {
  Calculator calc;
  ASSERT_ANY_THROW(calc.LoadExpression("2 + $"); calc.CalculateValue());
}

TEST(logic_error, incorrect_function_name) {
  Calculator calc;
  ASSERT_ANY_THROW(calc.LoadExpression("2+ sinus(5)"); calc.CalculateValue());
}
TEST(logic_error, fail_2) {
  Calculator calc;
  ASSERT_ANY_THROW(calc.LoadExpression("2.5.4 + 6"); calc.CalculateValue());
}

TEST(logic_error, fail_3) {
  Calculator calc;
  ASSERT_ANY_THROW(calc.LoadExpression(""); calc.CalculateValue());
}

TEST(logic_error, fail_4) {
  Calculator calc;
  ASSERT_ANY_THROW(calc.LoadExpression("cos()"); calc.CalculateValue());
}

TEST(logic_error, fail_5) {
  Calculator calc;
  ASSERT_ANY_THROW(calc.LoadExpression("2*1+5)"); calc.CalculateValue());
}

TEST(logic_error, fail_6) {
  Calculator calc;
  ASSERT_ANY_THROW(calc.LoadExpression("(2-6"); calc.CalculateValue());
}

TEST(logic_error, fail_7) {
  Calculator calc;
  ASSERT_ANY_THROW(calc.LoadExpression("sqrt2"); calc.CalculateValue());
}

TEST(logic_error, fail_8) {
  Calculator calc;
  ASSERT_ANY_THROW(calc.LoadExpression("22+7 5.4"); calc.CalculateValue());
}

TEST(logic_error, fail_9) {
  Calculator calc;
  ASSERT_ANY_THROW(calc.LoadExpression("100+2+"); calc.CalculateValue());
}

TEST(logic_error, fail_10) {
  Calculator calc;
  ASSERT_ANY_THROW(calc.LoadExpression("*"); calc.CalculateValue());
}

TEST(logic_error, fail_11) {
  Calculator calc;
  ASSERT_ANY_THROW(calc.LoadExpression("2(*2)"); calc.CalculateValue());
}

TEST(logic_error, fail_12) {
  Calculator calc;
  ASSERT_ANY_THROW(calc.LoadExpression("14sin"); calc.CalculateValue());
}

TEST(logic_error, fail_13) {
  Calculator calc;
  ASSERT_ANY_THROW(calc.LoadExpression("1+."); calc.CalculateValue());
}

TEST(logic_error, fail_14) {
  Calculator calc;
  ASSERT_ANY_THROW(calc.LoadExpression("2 2 *"); calc.CalculateValue());
}

TEST(logic_error, fail_15) {
  Calculator calc;
  ASSERT_ANY_THROW(calc.LoadExpression(" * * 2 2 *"); calc.CalculateValue());
}

TEST(logic_error, fail_16) {
  Calculator calc;
  ASSERT_ANY_THROW(calc.LoadExpression("-"); calc.CalculateValue());
}

TEST(logic_error, fail_17) {
  Calculator calc;
  ASSERT_ANY_THROW(calc.LoadExpression("+"); calc.CalculateValue());
}
