#include "string_validator.h"

bool s21::StringValidator::IsValid() const {
  bool is_valid = true;
  for (size_t pos = 0; pos < input_.length() && is_valid; ++pos) {
    char ch = input_[pos];
    // Проверка на число, десятичную точку или экспоненту
    if (std::isdigit(ch) || ch == '.' || ch == 'e' || ch == 'E') {
      if (!IsValidNumber(input_, pos)) {
        is_valid = false;
        break;
      }
    }
    // Проверка на наличие оператора
    else if (operators.find(ch) != std::string::npos) {
      if (!IsValidOperator(pos)) {
        is_valid = false;
      }
    }
    // Проверка на открывающую скобку
    else if (ch == '(') {
      is_valid = HandleOpeningParenthesis(pos);
    }
    // Проверка на закрывающую скобку
    else if (ch == ')') {
      is_valid = HandleClosingParenthesis(pos);
    }
    // Проверка на наличие функции
    else {
      if (!IsValidFunction(pos)) {
        is_valid = false;
        break;
      }
    }
  }
  // Проверка на корректность окончания строки и парность скобок
  if (operators.find(input_.back()) != std::string::npos ||
      open_parentheses != close_parentheses) {
    is_valid = false;
  }
  return is_valid;
}

bool s21::StringValidator::IsValidNumber(const std::string& str,
                                         size_t& pos) const {
  bool has_dot = false;  // Наличие точки в числе
  bool has_exp = false;  // Наличие экспоненциального символа ('e' или 'E')
  bool is_digit_before = false;  // Была ли цифра перед текущим символом
  for (; pos < str.length(); ++pos) {
    char ch = str[pos];
    if (std::isdigit(ch)) {
      is_digit_before = true;
    } else if (ch == '.') {
      if (has_dot || has_exp) {
        return false;  // Точка уже была или уже есть экспонента
      }
      has_dot = true;
    } else if ((ch == 'e' || ch == 'E')) {
      if (!is_digit_before || has_exp) {
        return false;
      }
      has_exp = true;
      is_digit_before = false;
      if (++pos < str.length()) {
        if (str[pos] == '+' || str[pos] == '-') {
          // Пропускаем знак, но убедимся, что после него идет цифра
          if (++pos < str.length() && std::isdigit(str[pos])) {
            is_digit_before = true;
          } else {
            // После 'e' или 'E' идет знак, но нет цифры
            return false;
          }
        } else if (!std::isdigit(str[pos])) {
          // Сразу после 'e' или 'E' нет ни знака, ни цифры
          return false;
        } else {
          // Сразу после 'e' или 'E' идет цифра
          is_digit_before = true;
        }
      } else {
        // Строка заканчивается на 'e' или 'E'
        return false;
      }
    } else {
      // Выходим из цикла, так как следующий символ не является частью числа
      pos--;
      break;
    }
  }
  // Проверяем, что после экспоненты есть число
  if (has_exp && !is_digit_before) {
    return false;
  }
  return true;  // Число валидно
}

bool s21::StringValidator::IsValidOperator(size_t pos) const {
  if (pos == 0 && input_[pos] != '-') return false;
  // Унарный минус может стоять в начале строки или после '(' или другого
  // оператора.
  if (input_[pos] == '-' &&
      (pos == 0 || input_[pos - 1] == '(' ||
       operators.find(input_[pos - 1]) != std::string::npos)) {
    return true;
  }
  // Проверка на два оператора подряд (кроме унарного минуса).
  if (pos > 0 && operators.find(input_[pos - 1]) != std::string::npos)
    return false;
  // Оператор не может идти сразу после открывающей скобки.
  if (pos > 0 && input_[pos - 1] == '(') return false;
  // Оператор не может предшествовать закрывающей скобке.
  if (pos < input_.length() - 1 && input_[pos + 1] == ')') return false;
  return true;
}

bool s21::StringValidator::IsValidFunction(size_t& pos) const {
  bool found_function = false;
  for (const std::string& func : functions) {
    if (input_.substr(pos, func.length()) == func) {
      found_function = true;
      // Пропуск названия функции
      pos += func.length() - 1;
      // Проверка на открывающую скобку после функции
      if (pos + 1 == input_.length() || input_[pos + 1] != '(') {
        return false;  // Отсутствие открывающей скобки после функции делает
                       // выражение невалидным
      }
      break;
    }
  }
  return found_function;  // Возвращает true, если найдена функция, иначе false
}

bool s21::StringValidator::HandleOpeningParenthesis(size_t pos) const {
  if (pos > 0 && (std::isdigit(input_[pos - 1]) || input_[pos - 1] == ')')) {
    return false;
  }
  if (pos + 1 < input_.length() && input_[pos + 1] == ')') {
    return false;
  }
  open_parentheses++;
  return true;
}

bool s21::StringValidator::HandleClosingParenthesis(size_t pos) const {
  if (pos + 1 < input_.length() && std::isdigit(input_[pos + 1])) {
    return false;
  }
  close_parentheses++;
  if (pos == 0 || operators.find(input_[pos - 1]) != std::string::npos) {
    return false;
  }
  return true;
}