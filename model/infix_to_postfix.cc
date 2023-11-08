#include "infix_to_postfix.h"

#include "string_validator.h"

const std::map<std::string, char> s21::InfixToPostfix::functions = {
    {"sin", 's'},  {"cos", 'c'},  {"tan", 't'}, {"asin", 'i'}, {"acos", 'o'},
    {"atan", 'n'}, {"sqrt", 'q'}, {"ln", 'l'},  {"log", 'g'}};

std::string s21::InfixToPostfix::Convert(const std::string &infix) {
  // Результирующее выражение в постфиксной записи.
  std::string postfix = "";
  // Стек для хранения операторов и скобок в процессе конвертации.
  std::stack<char> s;
  // Проверка корректности данного инфиксного выражения.
  s21::StringValidator validator(infix);
  if (!validator.IsValid()) {
    throw std::invalid_argument("Некорректное выражение");
  }
  // Итерация по каждому символу в инфиксном выражении.
  for (size_t i = 0; i < infix.size(); i++) {
    char c = infix[i];
    if (std::isdigit(c) || c == '.') {
      HandleNumeric(infix, i, postfix);
    }
    // Если текущий символ — это открывающая скобка.
    else if (c == '(') {
      s.push(c);
    }
    // Если текущий символ — это закрывающая скобка.
    else if (c == ')') {
      // Убрать все операторы из стека до открывающей скобки.
      while (!s.empty() && s.top() != '(') {
        postfix += s.top();
        postfix += ' ';
        s.pop();
      }
      // Убрать открывающую скобку.
      if (!s.empty()) s.pop();
    }
    // Если текущий символ — это унарный минус.
    else if (c == '-') {
      // Проверка на унарный минус
      if (i == 0 || infix[i - 1] == '(' || IsOperator(infix[i - 1])) {
        s.push('u');
      } else {
        // Если это не унарный минус, обрабатываем как обычный бинарный оператор
        while (!s.empty() && s.top() != '(' &&
               Precedence(s.top()) >= Precedence(c)) {
          postfix += s.top();
          postfix += ' ';
          s.pop();
        }
        s.push(c);
      }
    }
    // Если текущий символ — это другой оператор.
    else if (IsOperator(c)) {
      // Для оператора ^ используем строгое сравнение '>',
      // чтобы обеспечить правильную ассоциативность (правоассоциативность).
      while (!s.empty() && s.top() != '(' &&
             (c != '^' ? Precedence(s.top()) >= Precedence(c)
                       : Precedence(s.top()) > Precedence(c))) {
        postfix += s.top();
        postfix += ' ';
        s.pop();
      }
      // Положить текущий оператор в стек.
      s.push(c);
    }
    // Если текущий символ начинает имя функции.
    else {
      std::string func = "";
      // Извлечь имя функции.
      while (i < infix.size() && std::isalpha(infix[i])) {
        func += infix[i++];
      }
      --i;  // Корректировка счетчика после извлечения имени функции.
      // Если функция распознана, добавить соответствующий ей символ в стек.
      if (functions.find(func) != functions.end()) {
        s.push(functions.at(func));
      }
    }
  }
  // Убрать оставшиеся операторы или функции из стека.
  while (!s.empty()) {
    postfix += s.top();
    postfix += ' ';
    s.pop();
  }
  return postfix;
}

bool s21::InfixToPostfix::IsOperator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%' ||
         c == 'u';
}

int s21::InfixToPostfix::Precedence(char c) {
  switch (c) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
    case '%':
      return 2;
    case 'u':
      return 4;
    case '^':
      return 5;
    default:
      return 6;
  }
}

void s21::InfixToPostfix::HandleNumeric(const std::string &infix, size_t &index,
                                        std::string &postfix) {
  while (index < infix.size() &&
         (std::isdigit(infix[index]) || infix[index] == '.' ||
          infix[index] == 'e' || infix[index] == 'E')) {
    postfix += infix[index];
    if ((infix[index] == 'e' || infix[index] == 'E') &&
        index + 1 < infix.size() &&
        (infix[index + 1] == '+' || infix[index + 1] == '-')) {
      postfix += infix[++index];  // Добавляем '+' или '-'
      // Удостоверимся, что за '+' или '-' следует число
      if (index + 1 < infix.size() && std::isdigit(infix[index + 1])) {
        postfix += infix[++index];
      } else {
        // Если за '+' или '-' не следует число, то выбрасываем исключение
        throw std::invalid_argument("Некорректная научная нотация числа");
      }
    }
    index++;
  }
  postfix += ' ';
  index--;  // Компенсируем инкремент index на последнем шаге цикла while
}

bool s21::InfixToPostfix::isNumericChar(char c, const std::string &infix,
                                        size_t index) {
  // Возвращает true, если символ является цифрой
  if (std::isdigit(c)) return true;
  // Возвращает true, если символ является точкой и следующий за ним символ
  // является цифрой
  if (c == '.' && index + 1 < infix.size() && std::isdigit(infix[index + 1]))
    return true;
  // Обработка научной нотации
  if ((c == 'e' || c == 'E') && index + 1 < infix.size()) {
    char next = infix[index + 1];  // Получение следующего символа
    if (std::isdigit(next) ||
        ((next == '+' || next == '-') && index + 2 < infix.size() &&
         std::isdigit(infix[index + 2]))) {
      // Если следующий символ является цифрой или '+'/'-' с последующей цифрой
      return true;
    }
  }
  // Возвращает false, если символ не является частью числового значения
  return false;
}
