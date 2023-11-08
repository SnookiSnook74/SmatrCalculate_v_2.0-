#include "deposit_calc.h"

namespace s21 {
Deposit::Result Deposit::CalculateResult(Deposit::InputData InputData) {
  // Продолжительность вклада
  double duration = std::stod(InputData.duration);
  // Начальная сумма вклада
  double depositSum = std::stod(InputData.startSum);
  // Процентная ставка
  double interestRate = std::stod(InputData.interestRate);
  // Для хранения прибыли.
  double profit = 0;
  // Для прибыли, которая будет накапливаться.
  double profitBuffer = 0;
  // Конвертируем налоговую ставку из строки в число.
  double taxProcent = std::stod(InputData.taxRate);
  // Переменная для годовой прибыли.
  double yearlyProfit = 0;
  // Переменная для общей суммы налогов.
  double totalTax = 0;
  // Задаем текущую дату равной дате размещения вклада.
  tm current = InputData.placementDate;
  // Вычисляем дату окончания вклада, добавив к дате размещения
  // продолжительность вклада.
  tm endOfDepositDate = AddMonths(InputData.placementDate, duration);
  // Если дата окончания вклада - 29 февраля, меняем на 28 февраля.
  if (endOfDepositDate.tm_mon == 2 && endOfDepositDate.tm_mday == 29) {
    endOfDepositDate.tm_mday = 28;
  }
  // Вычисляем следующий день выплаты процентов в соответствии с частотой
  // выплат.
  tm nextPayoutDay = GetNextPayoutDay(current, InputData.frequency);
  // Цикл продолжается до тех пор, пока текущая дата не достигнет даты окончания
  // вклада.
  while (IsBefore(current, endOfDepositDate)) {
    // Увеличиваем сумму вклада на сумму пополнений.
    depositSum += GetToUpsAndWithdrowals(current, InputData.topUps);
    // Уменьшаем сумму вклада на сумму снятий.
    depositSum -= GetToUpsAndWithdrowals(current, InputData.withdrawals);
    // Переходим к следующему дню.
    current = AddDays(current, 1);
    // Вычисляем дневную долю процентной ставки.
    double dayShare = interestRate / GetDaysInYear(current);
    // Добавляем к прибыли дневную прибыль от вклада.
    profit += depositSum * dayShare / 100;
    // Проверяем, является ли текущая дата днем выплаты процентов.
    if (IsToday(current, nextPayoutDay)) {
      // Увеличиваем годовую прибыль на накопленную прибыль.
      yearlyProfit += profit;
      // Вычисляем следующий день выплаты процентов.
      nextPayoutDay = GetNextPayoutDay(nextPayoutDay, InputData.frequency);
      // Округляем прибыль до двух знаков после запятой.
      profit = std::round(profit * 100) / 100;
      // Если используется капитализация, добавляем прибыль к сумме вклада.
      if (InputData.capitalization == true) {
        depositSum += profit;
      }
      // Добавляем прибыль в буфер прибыли.
      profitBuffer += profit;
      // Обнуляем прибыль для следующего периода расчета.
      profit = 0;
    }
    // Если текущий день - последний день года или дата окончания вклада.
    if ((current.tm_mday == 31 && current.tm_mon == 12) ||
        IsToday(current, endOfDepositDate)) {
      // Если это дата окончания вклада, добавляем к годовой прибыли оставшуюся
      // прибыль.
      if (IsToday(current, endOfDepositDate)) yearlyProfit += profit;
      // Вычисляем налогооблагаемую часть годовой прибыли, вычитая необлагаемый
      // минимум.
      double yearlyTaxableIncome = yearlyProfit - BASIC_UNTAXED_INCOME;
      // Если есть налогооблагаемая прибыль, начисляем налог.
      if (yearlyTaxableIncome > 0)
        totalTax += yearlyTaxableIncome * taxProcent / 100.0;
      // Сбрасываем годовую прибыль, так как год завершился.
      yearlyProfit = 0;
    }
  }
  // Проверяем пополнения и снятия даже на последний день вклада.
  depositSum += GetToUpsAndWithdrowals(current, InputData.topUps);
  depositSum -= GetToUpsAndWithdrowals(current, InputData.withdrawals);
  // Если используется капитализация, округляем и добавляем последнюю прибыль к
  // сумме вклада.
  if (InputData.capitalization == true) {
    profit = std::round(profit * 100) / 100;
    depositSum += profit;
  }
  // Округляем общую сумму налогов.
  totalTax = std::round(totalTax * 100) / 100;
  // Добавляем последнюю прибыль в буфер прибыли.
  profitBuffer += profit;
  // Вычисляем конечную сумму вклада в зависимости от капитализации.
  depositSum =
      InputData.capitalization ? depositSum : depositSum + profitBuffer;
  // Возвращаем структуру Result с результатами расчета вклада.
  return {std::to_string(profitBuffer), std::to_string(totalTax),
          std::to_string(depositSum)};
}

double Deposit::GetToUpsAndWithdrowals(
    tm currentDate, std::vector<Deposit::Operation> eventList) {
  double result = 0;
  for (auto& item : eventList) {
    tm date = currentDate;
    if (IsAfter(date, item.date) || IsToday(item.date, date)) {
      if (item.type == "Разовое") {
        if (IsToday(item.date, date)) {
          result += std::stod(item.sum);
        }
      } else if (item.type == "Раз в месяц") {
        while (IsAfter(date, item.date)) {
          item.date = AddMonths(item.date, 1);
        }
        if (IsToday(item.date, date)) {
          result += std::stod(item.sum);
        }
      } else if (item.type == "Раз в 2 месяца") {
        while (IsAfter(date, item.date)) {
          item.date = AddMonths(item.date, 2);
        }
        if (IsToday(item.date, date)) {
          result += std::stod(item.sum);
        }
      } else if (item.type == "Раз в квартал") {
        while (IsAfter(date, item.date)) {
          item.date = AddMonths(item.date, 3);
        }
        if (IsToday(item.date, date)) {
          result += std::stod(item.sum);
        }
      } else if (item.type == "Раз в полгода") {
        while (IsAfter(date, item.date)) {
          item.date = AddMonths(item.date, 6);
        }
        if (IsToday(item.date, date)) {
          result += std::stod(item.sum);
        }
      } else if (item.type == "Раз в год") {
        while (IsAfter(date, item.date)) {
          item.date = AddYears(item.date, 1);
        }
        if (IsToday(item.date, date)) {
          result += std::stod(item.sum);
        }
      }
    }
  }
  return result;
}

bool Deposit::IsBefore(tm date1, tm date2) {
  bool result = false;
  int arr[3];
  arr[0] = date1.tm_year - date2.tm_year;
  arr[1] = date1.tm_mon - date2.tm_mon;
  arr[2] = date1.tm_mday - date2.tm_mday;
  for (int i = 0, exit = false; i < 3 && exit == false; ++i) {
    if (arr[i] < 0)
      result = true;
    else if (arr[i] > 0)
      exit = true;
  }
  return result;
}
bool Deposit::IsAfter(tm date1, tm date2) {
  bool result = false;
  int arr[3];
  arr[0] = date1.tm_year - date2.tm_year;
  arr[1] = date1.tm_mon - date2.tm_mon;
  arr[2] = date1.tm_mday - date2.tm_mday;
  for (int i = 0, exit = false; i < 3 && exit == false; ++i) {
    if (arr[i] > 0)
      result = true;
    else if (arr[i] < 0)
      exit = true;
  }
  return result;
}

bool Deposit::IsToday(tm date1, tm date2) {
  return date1.tm_year == date2.tm_year && date1.tm_mon == date2.tm_mon &&
         date1.tm_mday == date2.tm_mday;
}
tm Deposit::AddDays(tm date, int days) {
  date.tm_mday += days;
  while (date.tm_mday > GetDaysInMonth(date)) {
    date.tm_mday -= GetDaysInMonth(date);
    date = AddMonths(date, 1);
  }
  return date;
}
tm Deposit::AddMonths(tm date, int months) {
  date.tm_mon += months;
  while (date.tm_mon > 12) {
    date.tm_mon -= 12;
    date.tm_year += 1;
  }
  return date;
}

tm Deposit::AddYears(tm date, int year) {
  if (date.tm_mon == 2 && date.tm_mday == 29 && year != 0) {
    date.tm_mday = 1;
    date.tm_mon = 3;
  }
  date.tm_year += year;
  return date;
}

int Deposit::GetDaysInMonth(tm date) {
  int result = 0;
  switch (date.tm_mon) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      result = 31;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      result = 30;
      break;
    case 2:
      result = IsLeapYear(date) ? 29 : 28;
      break;
  }
  return result;
}
int Deposit::GetDaysInYear(tm date) { return IsLeapYear(date) ? 366 : 365; }

bool Deposit::IsLeapYear(tm date) {
  bool result = false;
  if (date.tm_year % 4 == 0) {
    if (date.tm_year % 100 == 0) {
      if (date.tm_year % 400 == 0) {
        result = true;
      }
    } else {
      result = true;
    }
  }
  return result;
}
tm Deposit::GetNextPayoutDay(tm current, const std::string& frequency) {
  if (frequency == "Каждый день") {
    current = AddDays(current, 1);
  } else if (frequency == "Каждую неделю") {
    current = AddDays(current, 7);
  } else if (frequency == "Раз в месяц") {
    current = AddMonths(current, 1);
  } else if (frequency == "Раз в квартал") {
    current = AddMonths(current, 3);
  } else if (frequency == "Раз в полгода") {
    current = AddMonths(current, 6);
  } else if (frequency == "Раз в год") {
    current = AddYears(current, 1);
  }
  return current;
}

}  // namespace s21