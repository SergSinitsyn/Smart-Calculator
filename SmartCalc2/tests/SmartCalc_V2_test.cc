#include <gtest/gtest.h>

#include "../model/model.h"

#define kAcc 1e-6

TEST(calculation, kek_add) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("8").first, 8, kAcc);
}

TEST(calculation, add) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("5.53234+1032.42342").first, 1037.95576, kAcc);
}

TEST(calculation, sum) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("1037.95576-234.234").first, 803.72176, kAcc);
}

TEST(calculation, mul) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("803.72176*423.234").first, 340162.375372, kAcc);
}

TEST(calculation, div) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("340162.375372/342.32").first, 993.697053552,
              kAcc);
}

TEST(calculation, mod) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("993.697053552mod423.234").first, 147.229053552,
              kAcc);
}

TEST(calculation, parenthesis) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("423.23*(23-4.3)").first, 7914.401, kAcc);
}

TEST(calculation, sin) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("sin(54.5)").first, -0.88797583833, kAcc);
}

TEST(calculation, cos) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("cos(32.32)").first, 0.61841396583, kAcc);
}

TEST(calculation, tan) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("tan(34.23)").first, -0.33975534786, kAcc);
}

TEST(calculation, log) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("log(23.23)").first, 1.3660492098, kAcc);
}

TEST(calculation, ln) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("ln(48.234)").first, 3.87606416657, kAcc);
}

TEST(calculation, sqrt) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("sqrt(423)").first, 20.5669638012, kAcc);
}

TEST(calculation, cbrt) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("cbrt(x)", 27).first, 3, kAcc);
}

TEST(calculation, asin) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("asin(0.324)").first, 0.329954518, kAcc);
}

TEST(calculation, acos) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("acos(0.324)").first, 1.24084181, kAcc);
}

TEST(calculation, atan) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("atan(-0.324)").first, -0.313327168, kAcc);
}

TEST(calculation, pow) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("423.32^(2.432^(1/5))").first, 1372.787322, kAcc);
}

TEST(calculation, pi) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("pi").first, 3.1415926, kAcc);
}

TEST(calculation, e) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("e").first, 2.718281, kAcc);
}

TEST(calculation, exp) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("exp(5)").first, 148.413159103, kAcc);
}

TEST(calculation, fabs) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("fabs(-1324.234)").first, 1324.234, kAcc);
}

TEST(calculation, expression_1) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("COS(Sin(3.14))").first, 0.999998, kAcc);
}

TEST(calculation, expression_2) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("(cos(sin(3.14))+3.12)^-5.14E-3").first, 0.9927489,
              kAcc);
}

TEST(calculation, expression_3) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("sqrt(cos(sin(3.14))+3.12)^-5.14E-3").first,
              0.9963678, kAcc);
}

TEST(calculation, expression_5) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("(-(-(+(+5))))").first, 5, kAcc);
}

TEST(calculation, expression_6) {
  Model calc;
  ASSERT_DOUBLE_EQ(calc.Calculate("0^(-1)").first, INFINITY);
}

TEST(calculation, expression_7) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("2^(3+4*5)*(2*2)+2+6/3").first, 33554436, kAcc);
}

TEST(calculation, expression_8) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("sin(2-1)*2^2+6^2*2").first, 75.365883939231579,
              kAcc);
}

TEST(calculation, expression_9) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("(-(-(-5)))*(-(-5))").first, -25, kAcc);
}

TEST(calculation, expression_10) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("-2^(3+4*5)*(2*2)+2+6/3").first, -33554428, kAcc);
}

TEST(calculation, expression_11) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("56+21-376+(56-22)-(13+10)+(11+(7-(3+2)))").first,
              -275, kAcc);
}

TEST(calculation, expression_12) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("tan(10)*((5-3)*ln(4)-log(8))*2+7").first,
              9.4242194938376841, kAcc);
}

TEST(calculation, expression_13) {
  Model calc;
  ASSERT_NEAR(
      calc.Calculate(
              "((-(-356.081*4598.63)*803.928*(70.592*(-0.1569))*(-36.1566)))")
          .first,
      527181836601.876000, 1);
}

TEST(calculation, expression_14) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("x+9+2-3*4/5mod6^7").first, 8.6, kAcc);
}

TEST(calculation, expression_15) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("2^3^4").first, 2417851639229258349412352.0, kAcc);
}

TEST(calculation, expression_16) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("sin(x+cos(x^x))*tan(x)", 1).first,
              1.5566836754802069187064716, kAcc);
}

TEST(calculation, expression_17) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("asin(x+1)+acos(x)-atan(2)", -0.60).first,
              1.518665563861578471360758, kAcc);
}

TEST(calculation, expression_18) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("sqrt(8965)+ln(56253)-log(965)").first,
              102.636771255135727187735, kAcc);
}

TEST(calculation, expression_19) {
  Model calc;
  ASSERT_NEAR(calc.Calculate("5.3+8.6-sin(x*1.6-5)/0.5", -0.60).first,
              13.26482286785592989986, kAcc);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}