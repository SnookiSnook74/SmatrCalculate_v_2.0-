#ifndef CPP3_SMARTCALC_V2_SRC_CONTROLLER_CALCULATOR_CONTROLLER_H_
#define CPP3_SMARTCALC_V2_SRC_CONTROLLER_CALCULATOR_CONTROLLER_H_

#include "../model/calculator.h"
#include "../model/credit_calc.h"
#include "../model/deposit_calc.h"

namespace s21 {

class CalculatorController {
 public:
  using PaymentInfoVector = std::vector<Credit::PaymentInfo>;
  CalculatorController() : calculator_(), credit_(), deposit_() {}
  // Методы калькулятора
  double CalculateExpression(const std::string& expression);
  // Методы кредитного калькулятора
  PaymentInfoVector CalculatePaymentSchedule(double amount, int months,
                                             double annual_rate);
  PaymentInfoVector CalculatePaymentDiffSchedule(double amount, int months,
                                                 double annual_rate);
  Deposit::Result CalculateDeposit(Deposit::InputData inputData);

 private:
  Calculator calculator_;
  Credit credit_;
  Deposit deposit_;
};

}  // namespace s21
#endif  // CPP3_SMARTCALC_V2_SRC_CONTROLLER_CALCULATOR_CONTROLLER_H_
