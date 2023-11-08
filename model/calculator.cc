#include "calculator.h"

double s21::Calculator::Evaluate(const std::string &infix) {
  std::string postfix = InfixToPostfix::Convert(infix);
  result_ = EvaluatePostfix(postfix);
  return EvaluatePostfix(postfix);
}

double s21::Calculator::EvaluatePostfix(const std::string &postfix) {
  setlocale(LC_NUMERIC, "C");
  std::stack<double> s;
  std::istringstream iss(postfix);
  std::string token;
  while (iss >> token) {
    if (std::isalpha(token[0])) {
      if (s.empty()) {
        throw std::runtime_error("Ожидался аргумент для унарной функции");
      }
      double a = s.top();
      s.pop();
      s.push(ApplyUnaryFunction(token[0], a));
    } else if (InfixToPostfix::IsOperator(token[0])) {
      if (s.size() < 2) {
        throw std::runtime_error("Недостаточно операндов для операции");
      }
      double b = s.top();
      s.pop();
      double a = s.top();
      s.pop();
      s.push(ApplyBinaryOperation(token[0], a, b));
    } else {
      s.push(std::stod(token));
    }
  }
  if (s.size() != 1) {
    throw std::runtime_error("Ошибка в выражении");
  }
  return s.top();
}

double s21::Calculator::ApplyUnaryFunction(char function, double value) {
  switch (function) {
    case 's':
      return sin(value);
    case 'c':
      return cos(value);
    case 't':
      return tan(value);
    case 'i':
      return asin(value);
    case 'o':
      return acos(value);
    case 'n':
      return atan(value);
    case 'q':
      if (value < 0.0) {
        throw std::runtime_error("Отрицательное значение под корнем");
      }
      return sqrt(value);
    case 'l':
      if (value <= 0.0) {
        throw std::runtime_error("ln от неположительного числа");
      }
      return log(value);
    case 'g':
      if (value <= 0.0) {
        throw std::runtime_error("log от неположительного числа");
      }
      return log10(value);
    case 'u':
      return -value;
    default:
      throw std::runtime_error("Неизвестная унарная функция");
  }
}

double s21::Calculator::ApplyBinaryOperation(char operation, double a,
                                             double b) {
  switch (operation) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      if (b == 0.0) {
        throw std::runtime_error("Деление на ноль");
      }
      return a / b;
    case '%':
      return fmod(a, b);
    case '^':
      return pow(a, b);
    default:
      throw std::runtime_error("Неизвестная бинарная операция");
  }
}