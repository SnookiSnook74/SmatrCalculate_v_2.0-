#ifndef CPP3_SMARTCALC_V2_SRC_MODEL_CREDIT_CALC_H_
#define CPP3_SMARTCALC_V2_SRC_MODEL_CREDIT_CALC_H_

#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

namespace s21 {

class Credit {
 public:
  struct PaymentInfo {
    double totalPayment;
    double principalPayment;
    double interestPayment;
    double remainingDebt;
  };

  Credit() {}

  /**
   * @brief Рассчитывает график аннуитетных платежей.
   *
   * Метод рассчитывает график платежей для кредита на основе аннуитетных
   * платежей.
   *
   * @param[in] amount Общая сумма кредита.
   * @param[in] months Срок кредита в месяцах.
   * @param[in] annual_rate Годовая процентная ставка (в процентах).
   * @return Вектор с информацией о платежах по месяцам.
   */
  std::vector<PaymentInfo> annuityPaymentSchedule(double amount, int months,
                                                  double annual_rate);
  /**
   * @brief Рассчитывает график дифференцированных платежей.
   *
   * Метод рассчитывает график платежей для кредита на основе дифференцированных
   * платежей.
   *
   * @param[in] amount Общая сумма кредита.
   * @param[in] months Срок кредита в месяцах.
   * @param[in] annual_rate Годовая процентная ставка (в процентах).
   * @return Вектор с информацией о платежах по месяцам.
   */
  std::vector<PaymentInfo> differentialPaymentSchedule(double amount,
                                                       int months,
                                                       double annual_rate);
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_SRC_MODEL_CREDIT_CALC_H_
