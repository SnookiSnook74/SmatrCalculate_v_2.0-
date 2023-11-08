#ifndef CPP3_SMARTCALC_V2_SRC_MODEL_DEPOSIT_CALC_H_
#define CPP3_SMARTCALC_V2_SRC_MODEL_DEPOSIT_CALC_H_

#include <ctime>
#include <string>
#include <vector>

/**
 * @class Deposit
 * @brief Класс для расчета доходности по вкладам.
 *
 * Класс Deposit предоставляет функциональность для расчета итоговой суммы
 * вклада, учитывая различные параметры, такие как процентная ставка, регулярные
 * пополнения и снятия, налоги и частоту капитализации. Расчеты основаны на
 * входных данных, предоставленных в структуре InputData.
 *
 * @author Emerosro
 */
namespace s21 {

class Deposit {
 public:
  const double BASIC_UNTAXED_INCOME = 150000;
  Deposit() {}
  typedef struct Operation {
    std::string type;
    tm date;
    std::string sum;
  } Operation;

  typedef struct InputData {
    std::string startSum;
    std::string duration;
    tm placementDate;
    std::string interestRate;
    std::string taxRate;
    std::string frequency;
    bool capitalization;
    std::vector<Operation> topUps;
    std::vector<Operation> withdrawals;
  } InputData;

  typedef struct Result {
    std::string percentage;
    std::string tax;
    std::string depositAmount;
  } Result;

  /**
   * @brief Вычисляет итоговый результат по вкладу.
   *
   * @param InputData Структура с входными данными для расчета.
   * @return Deposit::Result Структура с результатами расчета вклада.
   */
  Result CalculateResult(InputData InputData);

 private:
  /**
   * @brief Получает суммы пополнений и снятий на определенную дату.
   *
   * @param currentDate Текущая дата для проверки операций.
   * @param eventList Список операций пополнений и снятий.
   * @return double Сумма пополнений и снятий на текущую дату.
   */
  double GetToUpsAndWithdrowals(tm currentDate,
                                std::vector<Operation> eventList);
  /**
   * @brief Проверяет, является ли одна дата предшествующей другой.
   *
   * @param date1 Первая дата для сравнения.
   * @param date2 Вторая дата для сравнения.
   * @return bool Возвращает true, если первая дата предшествует второй.
   */
  bool IsBefore(tm date1, tm date2);
  /**
   * @brief Проверяет, следует ли одна дата за другой.
   *
   * @param date1 Первая дата для сравнения.
   * @param date2 Вторая дата для сравнения.
   * @return bool Возвращает true, если первая дата следует за второй.
   */
  bool IsAfter(tm date1, tm date2);
  /**
   * @brief Проверяет, являются ли две даты одинаковыми.
   *
   * @param date1 Первая дата для сравнения.
   * @param date2 Вторая дата для сравнения.
   * @return bool Возвращает true, если даты идентичны.
   */
  bool IsToday(tm date1, tm date2);
  /**
   * @brief Добавляет дни к дате.
   *
   * @param date Дата для увеличения.
   * @param days Количество дней для добавления.
   * @return tm Обновленная дата.
   */
  tm AddDays(tm date, int days);
  /**
   * @brief Добавляет месяцы к дате.
   *
   * @param date Дата для увеличения.
   * @param months Количество месяцев для добавления.
   * @return tm Обновленная дата.
   */
  tm AddMonths(tm date, int months);
  /**
   * @brief Добавляет годы к дате.
   *
   * @param date Дата для увеличения.
   * @param year Количество лет для добавления.
   * @return tm Обновленная дата.
   */
  tm AddYears(tm date, int year);
  /**
   * @brief Получает количество дней в месяце.
   *
   * @param date Дата, месяц которой нужно проверить.
   * @return int Количество дней в месяце.
   */
  int GetDaysInMonth(tm date);
  /**
   * @brief Получает количество дней в году.
   *
   * @param date Дата, год которой нужно проверить.
   * @return int Количество дней в году.
   */
  int GetDaysInYear(tm date);
  /**
   * @brief Проверяет, является ли год високосным.
   *
   * @param date Дата, год которой нужно проверить.
   * @return bool Возвращает true, если год високосный.
   */
  bool IsLeapYear(tm date);
  /**
   * @brief Получает следующий день выплаты по вкладу.
   *
   * @param current Текущая дата.
   * @param frequency Частота выплат.
   * @return tm Дата следующей выплаты.
   */
  tm GetNextPayoutDay(tm current, const std::string& frequency);
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_SRC_MODEL_DEPOSIT_CALC_H_
