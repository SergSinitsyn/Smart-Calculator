#include <gtest/gtest.h>

#include "../model/model.h"

// TEST(logic_error, character_limit_exceeded) {
//   Model calc;
//   ASSERT_(calc.Calculate("1234567890+1234567890+1234567890+1234567890+"
//                          "1234567890+1234567890+"
//                          "1234567890+1234567890+1234567890+"
//                          "1234567890+1234567890+1234567890+1234567890+"
//                          "1234567890+1234567890+"
//                          "1234567890+1234567890+1234567890+"
//                          "1234567890+1234567890+1234567890+1234567890+"
//                          "1234567890+1234567890+"
//                          "1234567890+")
//               .second);
// }

// TEST(logic_error, empty_input) {
//   Model calc;
//   ASSERT_ANY_THROW(calc.Calculate(""));
// }

// TEST(logic_error, incorrect_symbol) {
//   Model calc;
//   ASSERT_ANY_THROW(calc.Calculate("2 + $"));
// }

// TEST(logic_error, incorrect_function_name) {
//   Model calc;
//   ASSERT_ANY_THROW(calc.Calculate("2+ sinus(5)"));
// }
// TEST(logic_error, fail_2) {
//   Model calc;
//   ASSERT_ANY_THROW(calc.Calculate("2.5.4 + 6"));
// }

// TEST(logic_error, fail_3) {
//   Model calc;
//   ASSERT_ANY_THROW(calc.Calculate(""));
// }

// TEST(logic_error, fail_4) {
//   Model calc;
//   ASSERT_ANY_THROW(calc.Calculate("cos()"));
// }

// TEST(logic_error, fail_5) {
//   Model calc;
//   ASSERT_ANY_THROW(calc.Calculate("2*1+5)"));
// }

// TEST(logic_error, fail_6) {
//   Model calc;
//   ASSERT_ANY_THROW(calc.Calculate("(2-6"));
// }

// TEST(logic_error, fail_7) {
//   Model calc;
//   ASSERT_ANY_THROW(calc.Calculate("sqrt2"));
// }

// TEST(logic_error, fail_8) {
//   Model calc;
//   ASSERT_ANY_THROW(calc.Calculate("22+7 5.4"));
// }

// TEST(logic_error, fail_9) {
//   Model calc;
//   ASSERT_ANY_THROW(calc.Calculate("100+2+"));
// }

// TEST(logic_error, fail_10) {
//   Model calc;
//   ASSERT_ANY_THROW(calc.Calculate("*"));
// }

// TEST(logic_error, fail_11) {
//   Model calc;
//   ASSERT_ANY_THROW(calc.Calculate("2(*2)"));
// }

// TEST(logic_error, fail_12) {
//   Model calc;
//   ASSERT_ANY_THROW(calc.Calculate("14sin"));
// }

// TEST(logic_error, fail_13) {
//   Model calc;
//   ASSERT_ANY_THROW(calc.Calculate("1+."));
// }

// TEST(logic_error, fail_14) {
//   Model calc;
//   ASSERT_ANY_THROW(calc.Calculate("2 2 *"));
// }

// TEST(logic_error, fail_15) {
//   Model calc;
//   ASSERT_ANY_THROW(calc.Calculate(" * * 2 2 *"));
// }

// TEST(logic_error, fail_16) {
//   Model calc;
//   ASSERT_ANY_THROW(calc.Calculate("-"));
// }

// TEST(logic_error, fail_17) {
//   Model calc;
//   ASSERT_ANY_THROW(calc.Calculate("+"));
// }
