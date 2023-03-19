#include <gtest/gtest.h>

#include "../model/model.h"

#define kAcc 1e-6

TEST(calculation, kek_add) {
  MathCalculator calc;
  calc.CalculateAnswer("8+3");
  ASSERT_NEAR(calc.GetAnswer(), 11, kAcc);
}

TEST(calculation, add) {
  MathCalculator calc;
  calc.CalculateAnswer("5.53234+1032.42342");
  ASSERT_NEAR(calc.GetAnswer(), 1037.95576, kAcc);
}

TEST(calculation, sum) {
  MathCalculator calc;
  calc.CalculateAnswer("1037.95576-234.234");
  ASSERT_NEAR(calc.GetAnswer(), 803.72176, kAcc);
}

TEST(calculation, mul) {
  MathCalculator calc;
  calc.CalculateAnswer("803.72176*423.234");
  ASSERT_NEAR(calc.GetAnswer(), 340162.375372, kAcc);
}

TEST(calculation, div) {
  MathCalculator calc;
  calc.CalculateAnswer("340162.375372/342.32");
  ASSERT_NEAR(calc.GetAnswer(), 993.697053552, kAcc);
}

TEST(calculation, mod) {
  MathCalculator calc;
  calc.CalculateAnswer("993.697053552mod423.234");
  ASSERT_NEAR(calc.GetAnswer(), 147.229053552, kAcc);
}

TEST(calculation, parenthesis) {
  MathCalculator calc;
  calc.CalculateAnswer("423.23*(23-4.3)");
  ASSERT_NEAR(calc.GetAnswer(), 7914.401, kAcc);
}

TEST(calculation, sin) {
  MathCalculator calc;
  calc.CalculateAnswer("sin(54.5)");
  ASSERT_NEAR(calc.GetAnswer(), -0.88797583833, kAcc);
}

TEST(calculation, cos) {
  MathCalculator calc;
  calc.CalculateAnswer("cos(32.32)");
  ASSERT_NEAR(calc.GetAnswer(), 0.61841396583, kAcc);
}

TEST(calculation, tan) {
  MathCalculator calc;
  calc.CalculateAnswer("tan(34.23)");
  ASSERT_NEAR(calc.GetAnswer(), -0.33975534786, kAcc);
}

TEST(calculation, log) {
  MathCalculator calc;
  calc.CalculateAnswer("log(23.23)");
  ASSERT_NEAR(calc.GetAnswer(), 1.3660492098, kAcc);
}

TEST(calculation, ln) {
  MathCalculator calc;
  calc.CalculateAnswer("ln(48.234)");
  ASSERT_NEAR(calc.GetAnswer(), 3.87606416657, kAcc);
}

TEST(calculation, sqrt) {
  MathCalculator calc;
  calc.CalculateAnswer("sqrt(423)");
  ASSERT_NEAR(calc.GetAnswer(), 20.5669638012, kAcc);
}

TEST(calculation, cbrt) {
  MathCalculator calc;
  calc.CalculateAnswer("cbrt(x)", "27");
  ASSERT_NEAR(calc.GetAnswer(), 3, kAcc);
}

TEST(calculation, asin) {
  MathCalculator calc;
  calc.CalculateAnswer("asin(0.324)");
  ASSERT_NEAR(calc.GetAnswer(), 0.329954518, kAcc);
}

TEST(calculation, acos) {
  MathCalculator calc;
  calc.CalculateAnswer("acos(0.324)");
  ASSERT_NEAR(calc.GetAnswer(), 1.24084181, kAcc);
}

TEST(calculation, atan) {
  MathCalculator calc;
  calc.CalculateAnswer("atan(-0.324)");
  ASSERT_NEAR(calc.GetAnswer(), -0.313327168, kAcc);
}

TEST(calculation, pow) {
  MathCalculator calc;
  calc.CalculateAnswer("423.32^(2.432^(1/5))");
  ASSERT_NEAR(calc.GetAnswer(), 1372.787322, kAcc);
}

TEST(calculation, pi) {
  MathCalculator calc;
  calc.CalculateAnswer("pi");
  ASSERT_NEAR(calc.GetAnswer(), 3.1415926, kAcc);
}

TEST(calculation, e) {
  MathCalculator calc;
  calc.CalculateAnswer("e");
  ASSERT_NEAR(calc.GetAnswer(), 2.718281, kAcc);
}

TEST(calculation, exp) {
  MathCalculator calc;
  calc.CalculateAnswer("exp(5)");
  ASSERT_NEAR(calc.GetAnswer(), 148.413159103, kAcc);
}

TEST(calculation, abs) {
  MathCalculator calc;
  calc.CalculateAnswer("abs(-1324.234)");
  ASSERT_NEAR(calc.GetAnswer(), 1324.234, kAcc);
}

TEST(calculation, expression_1) {
  MathCalculator calc;
  calc.CalculateAnswer("COS(Sin(3.14))");
  ASSERT_NEAR(calc.GetAnswer(), 0.999998, kAcc);
}

TEST(calculation, expression_2) {
  MathCalculator calc;
  calc.CalculateAnswer("(cos(sin(3.14))+3.12)^-5.14E-3");
  ASSERT_NEAR(calc.GetAnswer(), 0.9927489, kAcc);
}

TEST(calculation, expression_3) {
  MathCalculator calc;
  calc.CalculateAnswer("sqrt(cos(sin(3.14))+3.12)^-5.14E-3");
  ASSERT_NEAR(calc.GetAnswer(), 0.9963678, kAcc);
}

TEST(calculation, expression_5) {
  MathCalculator calc;
  calc.CalculateAnswer("(-(-(+(+5))))");
  ASSERT_NEAR(calc.GetAnswer(), 5, kAcc);
}

TEST(calculation, expression_6) {
  MathCalculator calc;
  calc.CalculateAnswer("0^(-1)");
  ASSERT_DOUBLE_EQ(calc.GetAnswer(), INFINITY);
}

TEST(calculation, expression_7) {
  MathCalculator calc;
  calc.CalculateAnswer("2^(3+4*5)*(2*2)+2+6/3");
  ASSERT_NEAR(calc.GetAnswer(), 33554436, kAcc);
}

TEST(calculation, expression_8) {
  MathCalculator calc;
  calc.CalculateAnswer("sin(2-1)*2^2+6^2*2");
  ASSERT_NEAR(calc.GetAnswer(), 75.365883939231579, kAcc);
}

TEST(calculation, expression_9) {
  MathCalculator calc;
  calc.CalculateAnswer("(-(-(-5)))*(-(-5))");
  ASSERT_NEAR(calc.GetAnswer(), -25, kAcc);
}

TEST(calculation, expression_10) {
  MathCalculator calc;
  calc.CalculateAnswer("-2^(3+4*5)*(2*2)+2+6/3");
  ASSERT_NEAR(calc.GetAnswer(), -33554428, kAcc);
}

TEST(calculation, expression_11) {
  MathCalculator calc;
  calc.CalculateAnswer("56+21-376+(56-22)-(13+10)+(11+(7-(3+2)))");
  ASSERT_NEAR(calc.GetAnswer(), -275, kAcc);
}

TEST(calculation, expression_12) {
  MathCalculator calc;
  calc.CalculateAnswer("tan(10)*((5-3)*ln(4)-log(8))*2+7");
  ASSERT_NEAR(calc.GetAnswer(), 9.4242194938376841, kAcc);
}

TEST(calculation, expression_13) {
  MathCalculator calc;
  calc.CalculateAnswer(
      "((-(-356.081*4598.63)*803.928*(70.592*(-0.1569))*(-36.1566)))");
  ASSERT_NEAR(calc.GetAnswer(), 527181836601.876000, 1);
}

TEST(calculation, expression_14) {
  MathCalculator calc;
  calc.CalculateAnswer("1+9+2-3*4/5mod6^7");
  ASSERT_NEAR(calc.GetAnswer(), 9.6, kAcc);
}

TEST(calculation, expression_15) {
  MathCalculator calc;
  calc.CalculateAnswer("2^3^4");
  ASSERT_NEAR(calc.GetAnswer(), 2417851639229258349412352.0, kAcc);
}

TEST(calculation, expression_16) {
  MathCalculator calc;
  calc.CalculateAnswer("sin(x+cos(x^x))*tan(x)", "1");
  ASSERT_NEAR(calc.GetAnswer(), 1.5566836754802069187064716, kAcc);
}

TEST(calculation, expression_17) {
  MathCalculator calc;
  calc.CalculateAnswer("asin(x+1)+acos(x)-atan(2)", "-0.60");
  ASSERT_NEAR(calc.GetAnswer(), 1.518665563861578471360758, kAcc);
}

TEST(calculation, expression_18) {
  MathCalculator calc;
  calc.CalculateAnswer("sqrt(8965)+ln(56253)-log(965)");
  ASSERT_NEAR(calc.GetAnswer(), 102.636771255135727187735, kAcc);
}

TEST(calculation, expression_19) {
  MathCalculator calc;
  calc.CalculateAnswer("5.3+8.6-sin(x*1.6-5)/0.5", "-0.60");
  ASSERT_NEAR(calc.GetAnswer(), 13.26482286785592989986, kAcc);
}

TEST(calculation, expression_20) {
  MathCalculator calc;
  calc.CalculateAnswer("x", "-0.60");
  ASSERT_NEAR(calc.GetAnswer(), -0.60, kAcc);
}

TEST(calculation, expression_21) {
  MathCalculator calc;
  calc.CalculateAnswer("x", "-pi");
  ASSERT_NEAR(calc.GetAnswer(), -1 * M_PI, kAcc);
}

TEST(calculation, expression_22) {
  MathCalculator calc;
  calc.CalculateAnswer("x", "-e");
  ASSERT_NEAR(calc.GetAnswer(), -1 * M_E, kAcc);
}

TEST(calculation, expression_23) {
  MathCalculator calc;
  calc.CalculateAnswer("x", "-1");
  ASSERT_NEAR(calc.GetAnswer(), -1, kAcc);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}