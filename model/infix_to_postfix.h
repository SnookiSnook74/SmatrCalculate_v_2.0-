#ifndef CPP3_SMARTCALC_V2_SRC_MODEL_INFIX_TO_POSTFIX_H_
#define CPP3_SMARTCALC_V2_SRC_MODEL_INFIX_TO_POSTFIX_H_

#include <map>
#include <stack>
#include <stdexcept>
#include <string>

namespace s21 {

class InfixToPostfix {
 public:
  /**
   * Конвертирует математическое выражение из инфиксной записи в постфиксную.
   *
   * @param infix Входное выражение в инфиксной записи.
   * @return Выражение в постфиксной записи.
   * @throws std::invalid_argument если входное выражение некорректно.
   */
  static std::string Convert(const std::string &infix);
  /**
   * @brief Проверяет, является ли символ оператором.
   *
   * @param c Символ для проверки.
   * @return true Если символ является оператором.
   * @return false Если символ не является оператором.
   */
  static bool IsOperator(char c);
  /**
   * @brief Возвращает приоритет оператора для использования в алгоритме
   * преобразования.
   *
   * @param c Оператор, для которого нужно определить приоритет.
   * @return int Числовое значение приоритета оператора.
   */
  static int Precedence(char c);

 private:
  static const std::map<std::string, char> functions;
  /**
   * @brief Обрабатывает числовые значения, включая десятичные и научную
   * нотацию, добавляя их в постфиксную строку.
   *
   * @param infix Инфиксное выражение для обработки.
   * @param index Индекс текущего символа в инфиксном выражении.
   * @param postfix Строка, в которую добавляется постфиксное выражение.
   */
  static void HandleNumeric(const std::string &infix, size_t &index,
                            std::string &postfix);
  /**
   * @brief Проверяет, может ли символ быть частью числового значения.
   *
   * @param c Символ для проверки.
   * @param infix Инфиксное выражение, содержащее символ.
   * @param index Индекс символа в инфиксном выражении.
   * @return true Если символ может быть частью числового значения.
   * @return false Если символ не может быть частью числового значения.
   */
  static bool isNumericChar(char c, const std::string &infix, size_t index);
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_SRC_MODEL_INFIX_TO_POSTFIX_H_
