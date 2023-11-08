#include <gtest/gtest.h>

#include "calculator.h"
#include "credit_calc.h"
#include "deposit_calc.h"
#include "infix_to_postfix.h"
#include "string_validator.h"

TEST(StringValidatorTest, ValidString1) {
  s21::StringValidator validator("1+2*3-sin(90)/tan(45+2*3)");
  ASSERT_TRUE(validator.IsValid());
}

TEST(StringValidatorTest, ValidString2) {
  s21::StringValidator validator("ln(2+2)*log(10)");
  ASSERT_TRUE(validator.IsValid());
}

TEST(StringValidatorTest, ValidString3) {
  s21::StringValidator validator("sqrt(16*16+9*9)");
  ASSERT_TRUE(validator.IsValid());
}

TEST(StringValidatorTest, ValidString4) {
  s21::StringValidator validator("1+(2*(3+4)-5)/6");
  ASSERT_TRUE(validator.IsValid());
}

TEST(StringValidatorTest, ValidString5) {
  s21::StringValidator validator("asin(0.5)^2");
  ASSERT_TRUE(validator.IsValid());
}

TEST(StringValidatorTest, ValidString6) {
  s21::StringValidator validator("cos(90)*tan(45)");
  ASSERT_TRUE(validator.IsValid());
}

TEST(StringValidatorTest, ValidString7) {
  s21::StringValidator validator("ln(2.71)");
  ASSERT_TRUE(validator.IsValid());
}

TEST(StringValidatorTest, ValidString8) {
  s21::StringValidator validator("sqrt(2+2*2)");
  ASSERT_TRUE(validator.IsValid());
}

TEST(StringValidatorTest, ValidString9) {
  s21::StringValidator validator("(2+2)*(3+3)/(4+4)");
  ASSERT_TRUE(validator.IsValid());
}

TEST(StringValidatorTest, ValidString10) {
  s21::StringValidator validator("acos(0.5)*atan(1)");
  ASSERT_TRUE(validator.IsValid());
}

TEST(StringValidatorTest, ValidString11) {
  s21::StringValidator validator("2^3^2");
  ASSERT_TRUE(validator.IsValid());
}

TEST(StringValidatorTest, ValidString12) {
  s21::StringValidator validator("log(100/10)*ln(7+7)");
  ASSERT_TRUE(validator.IsValid());
}

TEST(StringValidatorTest, ValidString13) {
  s21::StringValidator validator("1/(1+1)");
  ASSERT_TRUE(validator.IsValid());
}

TEST(StringValidatorTest, ValidString14) {
  s21::StringValidator validator("sin(30+30)+cos(60)");
  ASSERT_TRUE(validator.IsValid());
}

TEST(StringValidatorTest, ValidString15) {
  s21::StringValidator validator("sqrt(2)*sqrt(2)");
  ASSERT_TRUE(validator.IsValid());
}

TEST(StringValidatorTest, ValidString16) {
  s21::StringValidator validator("acos(0.5)^atan(1)");
  ASSERT_TRUE(validator.IsValid());
}

TEST(StringValidatorTest, ValidString17) {
  s21::StringValidator validator("-5+5*(-6)");
  ASSERT_TRUE(validator.IsValid());
}

TEST(StringValidatorTest, InvalidString1) {
  s21::StringValidator validator("1+2++3");
  ASSERT_FALSE(validator.IsValid());
}

TEST(StringValidatorTest, InvalidString2) {
  s21::StringValidator validator("sin(90(90))");
  ASSERT_FALSE(validator.IsValid());
}

TEST(StringValidatorTest, InvalidString3) {
  s21::StringValidator validator("1()2");
  ASSERT_FALSE(validator.IsValid());
}

TEST(StringValidatorTest, InvalidString4) {
  s21::StringValidator validator("(1+2");
  ASSERT_FALSE(validator.IsValid());
}

TEST(StringValidatorTest, InvalidString5) {
  s21::StringValidator validator("tan(45)+");
  ASSERT_FALSE(validator.IsValid());
}

TEST(StringValidatorTest, InvalidString6) {
  s21::StringValidator validator("cos90)*tan(45)");
  ASSERT_FALSE(validator.IsValid());
}

TEST(StringValidatorTest, InvalidString7) {
  s21::StringValidator validator("ln(2.71");
  ASSERT_FALSE(validator.IsValid());
}

TEST(StringValidatorTest, InvalidString8) {
  s21::StringValidator validator("sqrt+2+2*2)");
  ASSERT_FALSE(validator.IsValid());
}

TEST(StringValidatorTest, InvalidString9) {
  s21::StringValidator validator("(2+2(3+3)/(4+4)");
  ASSERT_FALSE(validator.IsValid());
}

TEST(StringValidatorTest, InvalidString10) {
  s21::StringValidator validator("2^3^");
  ASSERT_FALSE(validator.IsValid());
}

TEST(StringValidatorTest, InvalidString11) {
  s21::StringValidator validator("log(100/10)*ln(7+7+)");
  ASSERT_FALSE(validator.IsValid());
}

TEST(StringValidatorTest, InvalidString12) {
  s21::StringValidator validator("sin30+30)+cos(60)");
  ASSERT_FALSE(validator.IsValid());
}

TEST(StringValidatorTest, InvalidString13) {
  s21::StringValidator validator("sqrt(2*sqrt(2)");
  ASSERT_FALSE(validator.IsValid());
}

TEST(StringValidatorTest, InvalidString14) {
  s21::StringValidator validator("1..2+2");
  ASSERT_FALSE(validator.IsValid());
}

TEST(StringValidatorTest, InvalidString15) {
  s21::StringValidator validator("()");
  ASSERT_FALSE(validator.IsValid());
}

TEST(StringValidatorTest, InvalidString16) {
  s21::StringValidator validator("sin5");
  ASSERT_FALSE(validator.IsValid());
}

TEST(StringValidatorTest, UnknownFunction) {
  s21::StringValidator validator("blah(30)");
  ASSERT_FALSE(validator.IsValid());
}

TEST(StringValidatorTest, ClosingParenthesisBeforeNumber) {
  s21::StringValidator validator("1+2)3");
  ASSERT_FALSE(validator.IsValid());
}

TEST(StringValidatorTest, ClosingParenthesisAfterOperator) {
  s21::StringValidator validator("1+*2)");
  ASSERT_FALSE(validator.IsValid());
}

TEST(StringValidatorTest, ValidString18) {
  s21::StringValidator validator("1.340781e+154");
  ASSERT_TRUE(validator.IsValid());
}

TEST(InfixToPostfixTest, BasicConversion) {
  EXPECT_EQ(s21::InfixToPostfix::Convert("1+2"), "1 2 + ");
  EXPECT_EQ(s21::InfixToPostfix::Convert("3*4-5"), "3 4 * 5 - ");
  EXPECT_EQ(s21::InfixToPostfix::Convert("6/(7+8)"), "6 7 8 + / ");
}

TEST(InfixToPostfixTest, MultipleOperators) {
  EXPECT_EQ(s21::InfixToPostfix::Convert("3+5*2-8/4"), "3 5 2 * + 8 4 / - ");
}

TEST(InfixToPostfixTest, WithFunctions) {
  EXPECT_EQ(s21::InfixToPostfix::Convert("sin(90)+cos(0)"), "90 s 0 c + ");
}

TEST(InfixToPostfixTest, MultipleFunctionsAndPriorities) {
  EXPECT_EQ(s21::InfixToPostfix::Convert("tan(45)+sin(30)*cos(60)-sqrt(9)/3"),
            "45 t 30 s 60 c * + 9 q 3 / - ");
}

TEST(InfixToPostfixTest, NestedFunctions) {
  EXPECT_EQ(s21::InfixToPostfix::Convert("sin(cos(45)+tan(30))"),
            "45 c 30 t + s ");
}

TEST(InfixToPostfixTest, LongExpression) {
  EXPECT_EQ(s21::InfixToPostfix::Convert(
                "2+3*4-5^6/tan(30)+7*8/9-10+asin(1)-acos(0)+atan(1)"),
            "2 3 4 * + 5 6 ^ 30 t / - 7 8 * 9 / + 10 - 1 i + 0 o - 1 n + ");
}

TEST(InfixToPostfixTest, SequenceOfOperatorsAndFunctions) {
  EXPECT_EQ(s21::InfixToPostfix::Convert("2*3+4/5-6^7%8"),
            "2 3 * 4 5 / + 6 7 ^ 8 % - ");
}

TEST(InfixToPostfixTest, InvalidExpressionThrowsException) {
  EXPECT_THROW(s21::InfixToPostfix::Convert("2+*3"), std::invalid_argument);
}

TEST(InfixToPostfixTest, SequenceWithFloatingPointNumbers) {
  EXPECT_EQ(s21::InfixToPostfix::Convert("2.5*3.1+4.6/5.7-6.8^7.9%8.2"),
            "2.5 3.1 * 4.6 5.7 / + 6.8 7.9 ^ 8.2 % - ");
}

TEST(StringValidatorTest, ValidString33) {
  s21::StringValidator validator("1.1.1+3");
  ASSERT_FALSE(validator.IsValid());
}

TEST(CalcTest, Test1) {
  s21::Calculator test("2+5*3");
  EXPECT_NEAR(test.GetResult(), 17, 1e-6);
}

TEST(CalcTest, Test2) {
  s21::Calculator test("(3^2+4^2)^0.5");
  EXPECT_NEAR(test.GetResult(), 5, 1e-6);
}

TEST(CalcTest, Test3) {
  s21::Calculator test("2+3*4-5^6/tan(30)+7*8/9-10+asin(1)-acos(0)+atan(1)");
  EXPECT_NEAR(test.GetResult(), 2450.38, 1e-2);
}

TEST(InfixToPostfixTest, SimpleExponentialNumber) {
  EXPECT_EQ(s21::InfixToPostfix::Convert("1.340781e+154+10*2"),
            "1.340781e+154 10 2 * + ");
}

TEST(CalcTest, Test4) {
  s21::Calculator test("sqrt(4)+log(5)");
  EXPECT_NEAR(test.GetResult(), 2.698970, 1e-6);
}

TEST(CalcTest, Test5) {
  s21::Calculator test;
  EXPECT_THROW(test.Evaluate("5/0"), std::runtime_error);
}

TEST(CalculatorTest, UnaryMinusComplexTest) {
  s21::Calculator calc("-4+(-4)*(-2)-sin(-30)");
  EXPECT_NEAR(calc.GetResult(), 3.01197, 1e-5);
}

TEST(CalculatorTest, CosFunction) {
  s21::Calculator calc("cos(90)");
  EXPECT_NEAR(calc.GetResult(), -0.44807, 1e-5);
}

TEST(CalcTest, Test6) {
  s21::Calculator test;
  EXPECT_THROW(test.Evaluate("log(-5)"), std::runtime_error);
}

TEST(CalcTest, Test7) {
  s21::Calculator test;
  EXPECT_THROW(test.Evaluate("ln(-5)"), std::runtime_error);
}

TEST(CalcTest, Test8) {
  s21::Calculator test;
  EXPECT_THROW(test.Evaluate("sqrt(-5)"), std::runtime_error);
}

TEST(CalculatorTest, Test9) {
  s21::Calculator calc("10%3");
  EXPECT_NEAR(calc.GetResult(), 1, 1e-5);
}

TEST(CalcTest, Test10) {
  s21::Calculator test("ln(10)+log(5)");
  EXPECT_NEAR(test.GetResult(), 3.001555, 1e-6);
}

TEST(CalcTest, Test11) {
  s21::Calculator test("-3^4");
  EXPECT_NEAR(test.GetResult(), -81, 1e-6);
}

TEST(CreditTest, DifferentialPaymentScheduleLastDebt) {
  s21::Credit credit;
  double amount = 100000;
  int months = 12;
  double annual_rate = 10;

  auto schedule =
      credit.differentialPaymentSchedule(amount, months, annual_rate);

  ASSERT_NEAR(schedule.back().remainingDebt, 0, 1e-10);
}

TEST(CreditTest, AnnuityPaymentScheduleLastDebt) {
  s21::Credit credit;
  double amount = 100000;
  int months = 12;
  double annual_rate = 10;

  auto schedule = credit.annuityPaymentSchedule(amount, months, annual_rate);

  ASSERT_NEAR(schedule.back().remainingDebt, 0, 1e-9);
}

TEST(CreditTest, DifferentialPaymentScheduleSixthMonthTotal) {
  s21::Credit credit;
  double amount = 100000;
  int months = 12;
  double annual_rate = 10;

  auto schedule =
      credit.differentialPaymentSchedule(amount, months, annual_rate);

  double expectedTotalPayment = 8819.4444444444453;
  ASSERT_NEAR(schedule[5].totalPayment, expectedTotalPayment, 1e-6);
}

TEST(DepositTest, TestWithoutOperations) {
  s21::Deposit deposit;

  tm timeInfo;
  timeInfo.tm_mday = 22;
  timeInfo.tm_mon = 9;
  timeInfo.tm_year = 2023;

  s21::Deposit::Result result = deposit.CalculateResult(
      {"10000000", "360", timeInfo, "11", "13", "Раз в месяц", true, {}, {}});
  EXPECT_EQ(result.percentage, "257078165.250000");
  EXPECT_EQ(result.tax, "32815661.480000");
  EXPECT_EQ(result.depositAmount, "267078165.250000");
}

TEST(DepositTest, TestWithoutOperations2) {
  s21::Deposit deposit;

  tm timeInfo;
  timeInfo.tm_mday = 22;
  timeInfo.tm_mon = 9;
  timeInfo.tm_year = 2023;

  s21::Deposit::Result result = deposit.CalculateResult(
      {"100000", "12", timeInfo, "11", "13", "Раз в месяц", true, {}, {}});
  EXPECT_EQ(result.percentage, "11580.970000");
  EXPECT_EQ(result.tax, "0.000000");
  EXPECT_EQ(result.depositAmount, "111580.970000");
}

TEST(DepositTest, TestWithoutOperations3) {
  s21::Deposit deposit;

  tm timeInfo;
  timeInfo.tm_mday = 22;
  timeInfo.tm_mon = 9;
  timeInfo.tm_year = 2023;

  tm topUpDate;
  topUpDate.tm_mday = 22;
  topUpDate.tm_mon = 11;
  topUpDate.tm_year = 2023;

  s21::Deposit::Operation topUp_1{"Раз в месяц", topUpDate, "1000"};
  s21::Deposit::Operation topUp_2{"Разовое", topUpDate, "1000"};
  s21::Deposit::Operation topUp_3{"Раз в 2 месяца", topUpDate, "1000"};

  std::vector<s21::Deposit::Operation> topUps;

  topUps.push_back(topUp_1);
  topUps.push_back(topUp_2);
  topUps.push_back(topUp_3);
  s21::Deposit::Result result = deposit.CalculateResult(
      {"100000", "12", timeInfo, "11", "13", "Раз в месяц", true, topUps, {}});

  EXPECT_EQ(result.percentage, "12480.330000");
  EXPECT_EQ(result.tax, "0.000000");
  EXPECT_EQ(result.depositAmount, "130480.330000");
}

TEST(DepositTest, TestWithoutOperations4) {
  s21::Deposit deposit;

  tm timeInfo;
  timeInfo.tm_mday = 22;
  timeInfo.tm_mon = 9;
  timeInfo.tm_year = 2023;

  tm topUpDate;
  topUpDate.tm_mday = 22;
  topUpDate.tm_mon = 11;
  topUpDate.tm_year = 2023;

  s21::Deposit::Operation topUp_1{"Раз в квартал", topUpDate, "10000"};
  s21::Deposit::Operation topUp_2{"Раз в полгода", topUpDate, "1000"};
  s21::Deposit::Operation topUp_3{"Раз в год", topUpDate, "1000"};

  std::vector<s21::Deposit::Operation> topUps;

  topUps.push_back(topUp_1);
  topUps.push_back(topUp_2);
  topUps.push_back(topUp_3);
  s21::Deposit::Result result = deposit.CalculateResult(
      {"100000", "12", timeInfo, "11", "13", "Раз в месяц", true, topUps, {}});

  EXPECT_EQ(result.percentage, "13891.360000");
  EXPECT_EQ(result.tax, "0.000000");
  EXPECT_EQ(result.depositAmount, "156891.360000");
}
