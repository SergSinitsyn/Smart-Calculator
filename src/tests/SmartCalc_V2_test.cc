#include <gtest/gtest.h>

#include "../model/model.h"

#define kAcc 1e-6

TEST(calculation, add) {
  Calculator calc;
  calc.LoadExpression("5.53234+1032.42342");
  ASSERT_NEAR(calc.CalculateValue(), 1037.95576, kAcc);
}

TEST(calculation, sum) {
  Calculator calc;
  calc.LoadExpression("1037.95576-234.234");
  ASSERT_NEAR(calc.CalculateValue(), 803.72176, kAcc);
}

TEST(calculation, mul) {
  Calculator calc;
  calc.LoadExpression("803.72176*423.234");
  ASSERT_NEAR(calc.CalculateValue(), 340162.375372, kAcc);
}

TEST(calculation, div) {
  Calculator calc;
  calc.LoadExpression("340162.375372/342.32");
  ASSERT_NEAR(calc.CalculateValue(), 993.697053552, kAcc);
}

TEST(calculation, mod) {
  Calculator calc;
  calc.LoadExpression("993.697053552mod423.234");
  ASSERT_NEAR(calc.CalculateValue(), 147.229053552, kAcc);
}

TEST(calculation, parenthesis) {
  Calculator calc;
  calc.LoadExpression("423.23*(23-4.3)");
  ASSERT_NEAR(calc.CalculateValue(), 7914.401, kAcc);
}

TEST(calculation, sin) {
  Calculator calc;
  calc.LoadExpression("sin(54.5)");
  ASSERT_NEAR(calc.CalculateValue(), -0.88797583833, kAcc);
}

TEST(calculation, cos) {
  Calculator calc;
  calc.LoadExpression("cos(32.32)");
  ASSERT_NEAR(calc.CalculateValue(), 0.61841396583, kAcc);
}

TEST(calculation, tan) {
  Calculator calc;
  calc.LoadExpression("tan(34.23)");
  ASSERT_NEAR(calc.CalculateValue(), -0.33975534786, kAcc);
}

TEST(calculation, log) {
  Calculator calc;
  calc.LoadExpression("log(23.23)");
  ASSERT_NEAR(calc.CalculateValue(), 1.3660492098, kAcc);
}

TEST(calculation, ln) {
  Calculator calc;
  calc.LoadExpression("ln(48.234)");
  ASSERT_NEAR(calc.CalculateValue(), 3.87606416657, kAcc);
}

TEST(calculation, sqrt) {
  Calculator calc;
  calc.LoadExpression("sqrt(423)");
  ASSERT_NEAR(calc.CalculateValue(), 20.5669638012, kAcc);
}

TEST(calculation, cbrt) {
  Calculator calc;
  calc.LoadExpression("cbrt(x)");
  ASSERT_NEAR(calc.CalculateValue(27), 3, kAcc);
}

TEST(calculation, asin) {
  Calculator calc;
  calc.LoadExpression("asin(0.324)");
  ASSERT_NEAR(calc.CalculateValue(), 0.329954518, kAcc);
}

TEST(calculation, acos) {
  Calculator calc;
  calc.LoadExpression("acos(0.324)");
  ASSERT_NEAR(calc.CalculateValue(), 1.24084181, kAcc);
}

TEST(calculation, atan) {
  Calculator calc;
  calc.LoadExpression("atan(-0.324)");
  ASSERT_NEAR(calc.CalculateValue(), -0.313327168, kAcc);
}

TEST(calculation, pow) {
  Calculator calc;
  calc.LoadExpression("423.32^(2.432^(1/5))");
  ASSERT_NEAR(calc.CalculateValue(), 1372.787322, kAcc);
}

TEST(calculation, pi) {
  Calculator calc;
  calc.LoadExpression("pi");
  ASSERT_NEAR(calc.CalculateValue(), 3.1415926, kAcc);
}

TEST(calculation, e) {
  Calculator calc;
  calc.LoadExpression("e");
  ASSERT_NEAR(calc.CalculateValue(), 2.718281, kAcc);
}

TEST(calculation, exp) {
  Calculator calc;
  calc.LoadExpression("exp(5)");
  ASSERT_NEAR(calc.CalculateValue(), 148.413159103, kAcc);
}

TEST(calculation, fabs) {
  Calculator calc;
  calc.LoadExpression("fabs(-1324.234)");
  ASSERT_NEAR(calc.CalculateValue(), 1324.234, kAcc);
}

TEST(calculation, expression_1) {
  Calculator calc;
  calc.LoadExpression("COS(sin(3.14))");
  ASSERT_NEAR(calc.CalculateValue(), 0.999998, kAcc);
}

TEST(calculation, expression_2) {
  Calculator calc;
  calc.LoadExpression("(cos(sin(3.14))+3.12)^-5.14E-3");
  ASSERT_NEAR(calc.CalculateValue(), 0.9927489, kAcc);
}

TEST(calculation, expression_3) {
  Calculator calc;
  calc.LoadExpression("sqrt(cos(sin(3.14))+3.12)^-5.14E-3");
  ASSERT_NEAR(calc.CalculateValue(), 0.9963678, kAcc);
}

TEST(calculation, expression_4) {
  Calculator calc;
  calc.LoadExpression("sqrt(cos(sin(3.14))+3.12)^-5.14E-3");
  ASSERT_NEAR(calc.CalculateValue(), 0.9963678, kAcc);
}

TEST(calculation, expression_5) {
  Calculator calc;
  calc.LoadExpression("(-(-(+(+5))))");
  ASSERT_NEAR(calc.CalculateValue(), 5, kAcc);
}

TEST(calculation, expression_6) {
  Calculator calc;
  calc.LoadExpression("0^(-1)");
  ASSERT_DOUBLE_EQ(calc.CalculateValue(), INFINITY);
}

TEST(calculation, expression_7) {
  Calculator calc;
  calc.LoadExpression("2^(3+4*5)*(2*2)+2+6/3");
  ASSERT_NEAR(calc.CalculateValue(), 33554436, kAcc);
}

TEST(calculation, expression_8) {
  Calculator calc;
  calc.LoadExpression("sin(2-1)*2^2+6^2*2");
  ASSERT_NEAR(calc.CalculateValue(), 75.365883939231579, kAcc);
}

TEST(calculation, expression_9) {
  Calculator calc;
  calc.LoadExpression("(-(-(-5)))*(-(-5))");
  ASSERT_NEAR(calc.CalculateValue(), -25, kAcc);
}

TEST(calculation, expression_10) {
  Calculator calc;
  calc.LoadExpression("-2^(3+4*5)*(2*2)+2+6/3");
  ASSERT_NEAR(calc.CalculateValue(), -33554428, kAcc);
}

TEST(calculation, expression_11) {
  Calculator calc;
  calc.LoadExpression("56+21-376+(56-22)-(13+10)+(11+(7-(3+2)))");
  ASSERT_NEAR(calc.CalculateValue(), -275, kAcc);
}

TEST(calculation, expression_12) {
  Calculator calc;
  calc.LoadExpression("tan(10)*((5-3)*ln(4)-log(8))*2+7");
  ASSERT_NEAR(calc.CalculateValue(), 9.4242194938376841, kAcc);
}

TEST(calculation, expression_13) {
  Calculator calc;
  calc.LoadExpression(
      "((-(-356.081*4598.63)*803.928*(70.592*(-0.1569))*(-36.1566)))");
  ASSERT_NEAR(calc.CalculateValue(), 527181836601.876000, 1);
}

TEST(calculation, expression_14) {
  Calculator calc;
  calc.LoadExpression("x+9+2-3*4/5mod6^7");
  ASSERT_NEAR(calc.CalculateValue(), 8.6, kAcc);
}

TEST(calculation, expression_15) {
  Calculator calc;
  calc.LoadExpression("2^3^4");
  ASSERT_NEAR(calc.CalculateValue(), 2417851639229258349412352.0, kAcc);
}

TEST(calculation, expression_16) {
  Calculator calc;
  calc.LoadExpression("sin(x+cos(x^x))*tan(x)");
  ASSERT_NEAR(calc.CalculateValue(1), 1.5566836754802069187064716, kAcc);
}

TEST(calculation, expression_17) {
  Calculator calc;
  calc.LoadExpression("asin(x+1)+acos(x)-atan(2)");
  ASSERT_NEAR(calc.CalculateValue(-0.60), 1.518665563861578471360758, kAcc);
}

TEST(calculation, expression_18) {
  Calculator calc;
  calc.LoadExpression("sqrt(8965)+ln(56253)-log(965)");
  ASSERT_NEAR(calc.CalculateValue(), 102.636771255135727187735, kAcc);
}

TEST(calculation, expression_19) {
  Calculator calc;
  calc.LoadExpression("5.3+8.6-sin(x*1.6-5)/0.5");
  ASSERT_NEAR(calc.CalculateValue(-0.60), 13.26482286785592989986, kAcc);
}

TEST(calculation, expression_20) {
  Calculator calc;
  calc.LoadExpression("+5*-x");
  ASSERT_NEAR(calc.CalculateValue(-20), 100, kAcc);
  ASSERT_NEAR(calc.CalculateValue(-10), 50, kAcc);
  ASSERT_NEAR(calc.CalculateValue(0), 0, kAcc);
  ASSERT_NEAR(calc.CalculateValue(-5), 25, kAcc);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}