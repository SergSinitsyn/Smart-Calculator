#include <gtest/gtest.h>

#include <cmath>

#include "../model/bank/creditcalculator.h"
#include "../model/bank/depositcalculator.h"
#include "../model/math/math_calculator.h"

#define kAcc 1e-6

TEST(calculation, number) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("1.2e3");
  ASSERT_NEAR(calc.GetAnswer(), 1200, kAcc);
  calc.CalculateAnswer("1.2e+3");
  ASSERT_NEAR(calc.GetAnswer(), 1200, kAcc);
  calc.CalculateAnswer("1.2e-3");
  ASSERT_NEAR(calc.GetAnswer(), 0.0012, kAcc);
  calc.CalculateAnswer("1.2e3+x", "-1.2e3");
  ASSERT_NEAR(calc.GetAnswer(), 0, kAcc);
}

TEST(calculation, add) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("5.53234 + 1032.42342");
  ASSERT_NEAR(calc.GetAnswer(), 1037.95576, kAcc);
}

TEST(calculation, sum) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("1037.95576-234.234");
  ASSERT_NEAR(calc.GetAnswer(), 803.72176, kAcc);
}

TEST(calculation, mul) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("803.72176*423.234");
  ASSERT_NEAR(calc.GetAnswer(), 340162.375372, kAcc);
}

TEST(calculation, div) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("340162.375372/342.32");
  ASSERT_NEAR(calc.GetAnswer(), 993.697053552, kAcc);
}

TEST(calculation, mod) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("993.697053552mod423.234");
  ASSERT_NEAR(calc.GetAnswer(), 147.229053552, kAcc);
}

TEST(calculation, parenthesis) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("423.23*(23-4.3)");
  ASSERT_NEAR(calc.GetAnswer(), 7914.401, kAcc);
}

TEST(calculation, sin) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("sin(54.5)");
  ASSERT_NEAR(calc.GetAnswer(), -0.88797583833, kAcc);
}

TEST(calculation, cos) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("cos(32.32)");
  ASSERT_NEAR(calc.GetAnswer(), 0.61841396583, kAcc);
}

TEST(calculation, tan) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("tan(34.23)");
  ASSERT_NEAR(calc.GetAnswer(), -0.33975534786, kAcc);
}

TEST(calculation, log) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("log(23.23)");
  ASSERT_NEAR(calc.GetAnswer(), 1.3660492098, kAcc);
}

TEST(calculation, ln) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("ln(48.234)");
  ASSERT_NEAR(calc.GetAnswer(), 3.87606416657, kAcc);
}

TEST(calculation, sqrt) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("sqrt(423)");
  ASSERT_NEAR(calc.GetAnswer(), 20.5669638012, kAcc);
}

TEST(calculation, cbrt) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("cbrt(x)", "27");
  ASSERT_NEAR(calc.GetAnswer(), 3, kAcc);
}

TEST(calculation, asin) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("asin(0.324)");
  ASSERT_NEAR(calc.GetAnswer(), 0.329954518, kAcc);
}

TEST(calculation, acos) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("acos(0.324)");
  ASSERT_NEAR(calc.GetAnswer(), 1.24084181, kAcc);
}

TEST(calculation, atan) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("atan(-0.324)");
  ASSERT_NEAR(calc.GetAnswer(), -0.313327168, kAcc);
}

TEST(calculation, pow) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("423.32^(2.432^(1/5))");
  ASSERT_NEAR(calc.GetAnswer(), 1372.787322, kAcc);
}

TEST(calculation, pi) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("pi");
  ASSERT_NEAR(calc.GetAnswer(), 3.1415926, kAcc);
}

TEST(calculation, e) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("e");
  ASSERT_NEAR(calc.GetAnswer(), 2.718281, kAcc);
}

TEST(calculation, exp) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("exp(5)");
  ASSERT_NEAR(calc.GetAnswer(), 148.413159103, kAcc);
}

TEST(calculation, abs) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("abs(-1324.234)");
  ASSERT_NEAR(calc.GetAnswer(), 1324.234, kAcc);
}

TEST(calculation, expression_1) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("COS(Sin(3.14))");
  ASSERT_NEAR(calc.GetAnswer(), 0.999998, kAcc);
}

TEST(calculation, expression_2) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("(cos(sin(3.14))+3.12)^-5.14E-3");
  ASSERT_NEAR(calc.GetAnswer(), 0.9927489, kAcc);
}

TEST(calculation, expression_3) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("sqrt(cos(sin(3.14))+3.12)^-5.14E-3");
  ASSERT_NEAR(calc.GetAnswer(), 0.9963678, kAcc);
}

TEST(calculation, expression_5) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("(-(-(+(+5))))");
  ASSERT_NEAR(calc.GetAnswer(), 5, kAcc);
}

TEST(calculation, expression_6) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("0^(-1)");
  ASSERT_DOUBLE_EQ(calc.GetAnswer(), INFINITY);
}

TEST(calculation, expression_7) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("2^(3+4*5)*(2*2)+2+6/3");
  ASSERT_NEAR(calc.GetAnswer(), 33554436, kAcc);
}

TEST(calculation, expression_8) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("sin(2-1)*2^2+6^2*2");
  ASSERT_NEAR(calc.GetAnswer(), 75.365883939231579, kAcc);
}

TEST(calculation, expression_9) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("(-(-(-5)))*(-(-5))");
  ASSERT_NEAR(calc.GetAnswer(), -25, kAcc);
}

TEST(calculation, expression_10) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("-2^(3+4*5)*(2*2)+2+6/3");
  ASSERT_NEAR(calc.GetAnswer(), -33554428, kAcc);
}

TEST(calculation, expression_11) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("56+21-376+(56-22)-(13+10)+(11+(7-(3+2)))");
  ASSERT_NEAR(calc.GetAnswer(), -275, kAcc);
}

TEST(calculation, expression_12) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("tan(10)*((5-3)*ln(4)-log(8))*2+7");
  ASSERT_NEAR(calc.GetAnswer(), 9.4242194938376841, kAcc);
}

TEST(calculation, expression_13) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer(
      "((-(-356.081*4598.63)*803.928*(70.592*(-0.1569))*(-36.1566)))");
  ASSERT_NEAR(calc.GetAnswer(), 527181836601.876000, 1);
}

TEST(calculation, expression_14) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("1+9+2-3*4/5mod6^7");
  ASSERT_NEAR(calc.GetAnswer(), 9.6, kAcc);
}

TEST(calculation, expression_15) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("2^3^4");
  ASSERT_NEAR(calc.GetAnswer(), 2417851639229258349412352.0, kAcc);
}

TEST(calculation, expression_16) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("sin(x+cos(x^x))*tan(x)", "1");
  ASSERT_NEAR(calc.GetAnswer(), 1.5566836754802069187064716, kAcc);
}

TEST(calculation, expression_17) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("asin(x+1)+acos(x)-atan(2)", "-0.60");
  ASSERT_NEAR(calc.GetAnswer(), 1.518665563861578471360758, kAcc);
}

TEST(calculation, expression_18) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("sqrt(8965)+ln(56253)-log(965)");
  ASSERT_NEAR(calc.GetAnswer(), 102.636771255135727187735, kAcc);
}

TEST(calculation, expression_19) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("5.3+8.6-sin(x*1.6-5)/0.5", "-0.60");
  ASSERT_NEAR(calc.GetAnswer(), 13.26482286785592989986, kAcc);
}

TEST(calculation, expression_20) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("x", "-0.60");
  ASSERT_NEAR(calc.GetAnswer(), -0.60, kAcc);
}

TEST(calculation, expression_21) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("x", "-pi");
  ASSERT_NEAR(calc.GetAnswer(), -1 * M_PI, kAcc);
}

TEST(calculation, expression_22) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("x", "-e");
  ASSERT_NEAR(calc.GetAnswer(), -1 * M_E, kAcc);
}

TEST(calculation, expression_23) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("x", "-1");
  ASSERT_NEAR(calc.GetAnswer(), -1, kAcc);
}

TEST(calculation, expression_24) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("sin(x)", "inf");
  ASSERT_TRUE(std::isnan(calc.GetAnswer()));
}

TEST(calculation, expression_25) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("1/0");
  ASSERT_TRUE(std::isinf(calc.GetAnswer()));
}

TEST(calculation, expression_26) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("-1/0");
  ASSERT_TRUE(std::isinf(calc.GetAnswer()));
}

TEST(calculation, expression_27) {
  MyNamespace::MathCalculator calc;
  calc.CalculateAnswer("x", "-e");
  ASSERT_NEAR(calc.GetAnswer(), -2.718281828459, kAcc);
}

TEST(calculation_graph, expression) {
  using namespace MyNamespace;
  MathCalculator calc;
  calc.CalculateGraph("x*x", 11, 0, 10, -10, 100);
  MathCalculator::XYGraph result = calc.GetGraph();
  std::vector<double> expected_x = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<double> expected_y = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
  ASSERT_TRUE((result.first == expected_x) && (result.second == expected_y));
}

TEST(credit, ann) {
  MyNamespace::CreditCalculator calc;
  calc.CalculateCredit(0, 123456, 120, 4.56);
  ASSERT_NEAR(calc.GetTotalPayment(), 153966.00, kAcc);
  ASSERT_NEAR(calc.GetOverpaymentOnCredit(), 30510.00, kAcc);
  ASSERT_NEAR(calc.GetMonthlyPayment().at(0), 1283.05, kAcc);
}

TEST(credit, diff) {
  MyNamespace::CreditCalculator calc;
  calc.CalculateCredit(1, 100000, 6, 12.5);
  ASSERT_NEAR(calc.GetTotalPayment(), 103645.83, kAcc);
  ASSERT_NEAR(calc.GetOverpaymentOnCredit(), 3645.83, kAcc);
  std::vector<double> expected_mp = {17708.33, 17534.72, 17361.11,
                                     17187.50, 17013.89, 16840.28};
  for (int i = 0; i < 6; ++i) {
    ASSERT_NEAR(calc.GetMonthlyPayment().at(i), expected_mp.at(i), kAcc);
  }
}

TEST(deposit, test1) {
  using namespace MyNamespace;
  DepositCalculator calc;
  DepositCalculator::MultiMapDate ReplenishmentsList;
  ReplenishmentsList.insert(
      std::make_pair(Date(30, 03, 2023), std::make_pair(2, 20000.00)));
  ReplenishmentsList.insert(
      std::make_pair(Date(04, 05, 2023), std::make_pair(3, 60000.00)));
  DepositCalculator::MultiMapDate PartialWithdrawalsList;
  PartialWithdrawalsList.insert(
      std::make_pair(Date(29, 10, 2025), std::make_pair(0, 300000.00)));
  PartialWithdrawalsList.insert(
      std::make_pair(Date(30, 03, 2028), std::make_pair(2, 30000.00)));
  DepositCalculator::DepositInputData InputData{1000000,
                                                Date(13, 3, 2023),
                                                100,
                                                1,
                                                7.3,
                                                0.0,
                                                2,
                                                1,
                                                ReplenishmentsList,
                                                PartialWithdrawalsList,
                                                0};
  calc.CalculateDeposit(InputData);
  ASSERT_NEAR(calc.GetDepositAmountByTheEndOfTheTerm(), 3516943.69, kAcc);
  ASSERT_NEAR(calc.GetAccruedInterest(), 1476943.69, kAcc);
  ASSERT_NEAR(calc.GetTaxAmount(), 0.0, kAcc);
}

TEST(deposit, test2) {
  using namespace MyNamespace;
  DepositCalculator calc;
  DepositCalculator::MultiMapDate ReplenishmentsList;
  ReplenishmentsList.insert(
      std::make_pair(Date(28, 01, 2024), std::make_pair(2, 7777.77)));
  DepositCalculator::MultiMapDate PartialWithdrawalsList;
  DepositCalculator::DepositInputData InputData{1000000,
                                                Date(13, 3, 2023),
                                                20,
                                                2,
                                                8.13,
                                                0.0,
                                                1,
                                                0,
                                                ReplenishmentsList,
                                                PartialWithdrawalsList,
                                                0};
  calc.CalculateDeposit(InputData);
  ASSERT_NEAR(calc.GetDepositAmountByTheEndOfTheTerm(), 2788887.10, kAcc);
  ASSERT_NEAR(calc.GetAccruedInterest(), 3019635.29, kAcc);
  ASSERT_NEAR(calc.GetTaxAmount(), 0.0, kAcc);
}

TEST(deposit, test3) {
  using namespace MyNamespace;
  DepositCalculator calc;
  DepositCalculator::MultiMapDate ReplenishmentsList;
  ReplenishmentsList.insert(
      std::make_pair(Date(28, 01, 2024), std::make_pair(1, 7777.77)));
  DepositCalculator::MultiMapDate PartialWithdrawalsList;
  DepositCalculator::DepositInputData InputData{1000000,
                                                Date(13, 3, 2023),
                                                2000,
                                                0,
                                                8.13,
                                                0.0,
                                                0,
                                                0,
                                                ReplenishmentsList,
                                                PartialWithdrawalsList,
                                                0};
  calc.CalculateDeposit(InputData);
  ASSERT_NEAR(calc.GetDepositAmountByTheEndOfTheTerm(), 2866664.80, kAcc);
  ASSERT_NEAR(calc.GetAccruedInterest(), 795061.21, kAcc);
  ASSERT_NEAR(calc.GetTaxAmount(), 0.0, kAcc);
}

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
  ASSERT_ANY_THROW(calc.CalculateAnswer("()"));
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
  DepositCalculator calc;
  DepositCalculator::MultiMapDate ReplenishmentsList;
  DepositCalculator::MultiMapDate PartialWithdrawalsList;
  PartialWithdrawalsList.insert(
      std::make_pair(Date(28, 01, 2024), std::make_pair(1, 100000000)));
  DepositCalculator::DepositInputData InputData{1000000,
                                                Date(13, 3, 2023),
                                                2000,
                                                0,
                                                8.13,
                                                0.0,
                                                4,
                                                0,
                                                ReplenishmentsList,
                                                PartialWithdrawalsList,
                                                0};
  ASSERT_ANY_THROW(calc.CalculateDeposit(InputData));
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}