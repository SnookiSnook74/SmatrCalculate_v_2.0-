#ifndef CPP3_SMARTCALC_V2_SRC_MODEL_CALCULATOR_H_
#define CPP3_SMARTCALC_V2_SRC_MODEL_CALCULATOR_H_

#include <cmath>
#include <sstream>
#include <stack>
#include <stdexcept>

#include "infix_to_postfix.h"

/**
 * @class s21::Calculator
 * @brief Класс для вычисления математических выражений.
 *
 * Этот класс предоставляет методы для преобразования и вычисления
 * математических выражений, представленных в инфиксной и постфиксной нотации.
 *
 * @author Emerosro
 */

namespace s21 {

class Calculator {
 public:
  Calculator() : result_(0) {}
  /**
   * @brief Конструктор с вычислением выражения.
   *
   * Принимает строковое выражение и инициализирует калькулятор,
   * вычисляя данное выражение.
   *
   * @param[in] express Строковое математическое выражение для вычисления.
   */
  Calculator(const std::string &express) : result_(Evaluate(express)) {}
  double GetResult() const { return result_; }
  /**
   * @brief Вычисляет предоставленное инфиксное математическое выражение.
   *
   * Эта функция сначала преобразует инфиксное выражение в постфиксную нотацию с
   * помощью метода InfixToPostfix::Convert(). Затем она вычисляет получившееся
   * постфиксное выражение.
   *
   * @param[in] infix Строка инфиксного выражения.
   * @return Результат вычисления инфиксного выражения.
   */
  double Evaluate(const std::string &infix);

 private:
  double result_;
  /**
   * @brief Вычисляет постфиксное математическое выражение.
   *
   * Эта функция вычисляет постфиксное выражение, итерируясь по его токенам
   * и выполняя соответствующие вычисления.
   *
   * @param[in] postfix Строка постфиксного выражения.
   * @return Результат вычисления постфиксного выражения.
   * @throws std::runtime_error При проблемах при вычислении выражения.
   */
  double EvaluatePostfix(const std::string &postfix);
  /**
   * @brief Применяет унарную функцию к заданному значению.
   *
   * Эта функция принимает символ, представляющий унарную математическую
   * функцию, и применяет его к предоставленному значению.
   *
   * @param[in] function Символ, представляющий унарную функцию.
   * @param[in] value Значение, к которому следует применить унарную функцию.
   * @return Результат после применения унарной функции.
   * @throws std::runtime_error При встрече неизвестной функции или
   * проблемах при вычислении функции.
   */
  double ApplyUnaryFunction(char function, double value);
  /**
   * @brief Применяет бинарную операцию к двум значениям.
   *
   * Эта функция принимает символ, представляющий бинарную операцию,
   * и применяет его к предоставленным значениям a и b.
   *
   * @param[in] operation Символ, представляющий бинарную операцию.
   * @param[in] a Первый операнд.
   * @param[in] b Второй операнд.
   * @return Результат после применения бинарной операции.
   * @throws std::runtime_error При встрече неизвестной операции или
   * проблемах при вычислении операции.
   */
  double ApplyBinaryOperation(char operation, double a, double b);
};
}  // namespace s21
#endif  // CPP3_SMARTCALC_V2_SRC_MODEL_CALCULATOR_H_
