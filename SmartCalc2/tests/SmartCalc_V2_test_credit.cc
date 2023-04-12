#include <gtest/gtest.h>

#include "../model/credit.h"

#define kAcc 1e-12

TEST(credit, expression_1) {
  Credit calc;
  calc.CalculateCredit(0, 123456, 120, 4.56);
  ASSERT_NEAR(calc.GetTotalPayment(), 153966.00, kAcc);
  ASSERT_NEAR(calc.GetOverpaymentOnCredit(), 30510.00, kAcc);
  ASSERT_NEAR(calc.GetMonthlyPayment().front(), 1283.05, kAcc);
}