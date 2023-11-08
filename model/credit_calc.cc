#include "credit_calc.h"
namespace s21 {

using PaymentInfoVector = std::vector<Credit::PaymentInfo>;

PaymentInfoVector Credit::annuityPaymentSchedule(double amount, int months,
                                                 double annual_rate) {
  double r = annual_rate / 12 / 100;
  double monthlyPayment =
      amount * (r * std::pow(1 + r, months)) / (std::pow(1 + r, months) - 1);

  std::vector<s21::Credit::PaymentInfo> schedule;
  for (int i = 0; i < months; ++i) {
    s21::Credit::PaymentInfo info;
    info.interestPayment = amount * r;
    info.principalPayment = monthlyPayment - info.interestPayment;
    amount -= info.principalPayment;
    info.totalPayment = monthlyPayment;
    info.remainingDebt = amount;
    schedule.push_back(info);
  }

  return schedule;
}
PaymentInfoVector Credit::differentialPaymentSchedule(double amount, int months,
                                                      double annual_rate) {
  std::vector<s21::Credit::PaymentInfo> schedule;
  double monthly_principal = amount / months;
  double r = annual_rate / 12 / 100;
  for (int i = 0; i < months; i++) {
    s21::Credit::PaymentInfo info;
    info.interestPayment = (amount - i * monthly_principal) * r;
    info.principalPayment = monthly_principal;
    info.totalPayment = info.principalPayment + info.interestPayment;
    info.remainingDebt = amount - (i + 1) * monthly_principal;
    schedule.push_back(info);
  }

  return schedule;
}

}  // namespace s21
