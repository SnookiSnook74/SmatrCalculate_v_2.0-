#include "calculator_controller.h"

namespace s21 {
using PaymentInfoVector = std::vector<Credit::PaymentInfo>;

double CalculatorController::CalculateExpression(
    const std::string& expression) {
  try {
    calculator_.Evaluate(expression);
    return calculator_.GetResult();
  } catch (const std::invalid_argument& error) {
    printf("ERROR");
    throw;
  }
}

PaymentInfoVector CalculatorController::CalculatePaymentSchedule(
    double amount, int months, double annual_rate) {
  return credit_.annuityPaymentSchedule(amount, months, annual_rate);
}
PaymentInfoVector CalculatorController::CalculatePaymentDiffSchedule(
    double amount, int months, double annual_rate) {
  return credit_.differentialPaymentSchedule(amount, months, annual_rate);
}
Deposit::Result CalculatorController::CalculateDeposit(
    Deposit::InputData inputData) {
  return deposit_.CalculateResult(inputData);
}

}  // namespace s21
