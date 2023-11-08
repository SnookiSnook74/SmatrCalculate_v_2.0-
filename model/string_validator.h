#ifndef CPP3_SMARTCALC_V2_SRC_MODEL_STRING_VALIDATOR_H_
#define CPP3_SMARTCALC_V2_SRC_MODEL_STRING_VALIDATOR_H_

#include <cctype>
#include <set>
#include <string>

namespace s21 {

class StringValidator {
 public:
  explicit StringValidator(const std::string& input) : input_(input) {}
  /**
   * @brief Проверяет, валидна ли вся входная строка.
   *
   * @return true Если строка валидна.
   * @return false Если строка невалидна.
   */
  bool IsValid() const;

 private:
  const std::string operators = "+-*/^%";
  const std::set<std::string> functions = {
      "cos", "sin", "tan", "acos", "asin", "atan", "sqrt", "ln", "log"};
  mutable int open_parentheses = 0;
  mutable int close_parentheses = 0;
  /**
   * @brief Проверяет, является ли подстрока числом в правильном формате.
   *
   * Этот метод проверяет, правильно ли сформирована числовая
   * последовательность, включая десятичные точки и экспоненциальную нотацию.
   *
   * @param str Строка для проверки.
   * @param pos Позиция начала числовой последовательности в строке.
   * @return true Если подстрока является числом в правильном формате.
   * @return false Если подстрока не является числом в правильном формате.
   */
  bool IsValidNumber(const std::string& str, size_t& pos) const;
  /**
   * @brief Проверяет, является ли символ в позиции pos валидным оператором.
   *
   * Учитывает контекст символа (например, унарный минус).
   *
   * @param pos Позиция символа для проверки.
   * @return true Если символ является валидным оператором.
   * @return false Если символ не является валидным оператором.
   */
  bool IsValidOperator(size_t pos) const;
  /**
   * @brief Проверяет, начинается ли с позиции pos валидное название функции.
   *
   * Функция должна быть за followed by an opening parenthesis '('.
   *
   * @param pos Позиция начала функции в строке и обновляется
   *            для указания на следующую позицию после функции.
   * @return true Если с данной позиции начинается функция.
   * @return false Если функция не найдена или формат неверен.
   */
  bool IsValidFunction(size_t& pos) const;
  /**
   * @brief Обрабатывает открывающую скобку, увеличивая счётчик скобок.
   *
   * Проверяет корректность расположения открывающей скобки в выражении.
   *
   * @param pos Позиция открывающей скобки в выражении.
   * @return true Если скобка находится в допустимом контексте.
   * @return false Если скобка расположена некорректно.
   */
  bool HandleOpeningParenthesis(size_t pos) const;
  /**
   * @brief Обрабатывает закрывающую скобку, увеличивая счётчик скобок.
   *
   * Проверяет корректность расположения закрывающей скобки в выражении.
   *
   * @param pos Позиция закрывающей скобки в выражении.
   * @return true Если скобка находится в допустимом контексте.
   * @return false Если скобка расположена некорректно.
   */
  bool HandleClosingParenthesis(size_t pos) const;
  std::string input_;
};

}  // namespace s21
#endif  // CPP3_SMARTCALC_V2_SRC_MODEL_STRING_VALIDATOR_H_