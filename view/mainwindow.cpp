#include "mainwindow.h"

#include "./ui_mainwindow.h"
#include "qcustomplot.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), isXPressed(false) {
  ui->setupUi(this);
  this->setFixedSize(this->width(), this->height());
  qc_setup();
  setFocusPolicy(Qt::StrongFocus);
  connect_main();
}

MainWindow::~MainWindow() { delete ui; }

// Этот метод вызывается, когда одна из цифровых кнопок (0-9) нажата.
void MainWindow::digit_pressed() {
  QPushButton *button = (QPushButton *)sender();
  QString currentText = ui->result->text();

  // Проверка, если последний символ в currentText это 'x' и нажата цифровая
  // кнопка
  if (!currentText.isEmpty() &&
      currentText.at(currentText.length() - 1) == 'x') {
    currentText.append('*');
  }
  if (currentText == "0" && !button->text().startsWith('.')) {
    currentText.clear();
  }
  currentText.append(button->text());
  ui->result->setText(currentText);
}

void MainWindow::operation_pressed() {
  QPushButton *button = (QPushButton *)sender();
  QString currentText = ui->result->text();
  QChar lastChar = currentText.isEmpty()
                       ? QChar()
                       : currentText.at(currentText.length() - 1);

  if (currentText.isEmpty() ||
      (!lastChar.isDigit() && lastChar != ')' && lastChar != 'x')) {
    if (button->text() == "^" || button->text() == "%" ||
        button->text() == "*" || button->text() == "/")
      return;
    else if ((button->text() == "-" || button->text() == "+") &&
             lastChar == button->text())
      return;
  }
  currentText.append(button->text());
  ui->result->setText(currentText);
}

void MainWindow::on_pushButton_AC_clicked() {
  ui->result->setText("0");
  ui->graph->clearPlottables();
  ui->graph->replot();
  ui->lineEdit_x->clear();
  isXPressed = false;
  ui->Xmax->setText("10");
  ui->Xmin->setText("-10");
  ui->Ymax->setText("10");
  ui->Ymin->setText("-10");
}

void MainWindow::on_pushButton_point_clicked() {
  QString currentText = ui->result->text();
  // Проверка, является ли последний символ цифрой
  if (currentText.isEmpty() || !currentText.back().isDigit()) {
    return;  // Выход из функции, если условие не выполнено
  }
  // Находит индекс последнего оператора
  int indexOfLastOperator =
      std::max({currentText.lastIndexOf('+'), currentText.lastIndexOf('-'),
                currentText.lastIndexOf('*'), currentText.lastIndexOf('/'),
                currentText.lastIndexOf('%')});

  // Извлекаем подстроку
  QString lastNumber = currentText.mid(indexOfLastOperator + 1);
  // Проверка, содержит ли последнее число точку
  if (lastNumber.contains('.')) {
    return;  // Выход из функции, если условие не выполнено
  }
  // Если все проверки пройдены успешно, добавляем точку
  ui->result->setText(currentText + '.');
}

void MainWindow::bracket_pressed() {
  QPushButton *button = (QPushButton *)sender();
  QString currentText = ui->result->text();
  if (currentText == "0") {
    currentText.clear();
  }
  currentText.append(button->text());
  ui->result->setText(currentText);
}

// Меняет знак последнего числа в тексте.
void MainWindow::on_pushButton_plus_minus_clicked() {
  QString currentText = ui->result->text();
  int indexOfLastOperator =
      std::max({currentText.lastIndexOf('+'), currentText.lastIndexOf('*'),
                currentText.lastIndexOf('/'), currentText.lastIndexOf('%'),
                currentText.lastIndexOf('^'), currentText.lastIndexOf('('),
                currentText.lastIndexOf(')')});
  QString lastNumber = currentText.mid(indexOfLastOperator + 1);
  if (!lastNumber.isEmpty()) {
    double number = lastNumber.toDouble();
    number *= -1;
    currentText = currentText.left(indexOfLastOperator + 1) +
                  QString::number(number, 'g', 15);
    ui->result->setText(currentText);
  }
}

void MainWindow::trigonometry() {
  QPushButton *button = (QPushButton *)sender();
  QString currentText = ui->result->text();
  if (currentText == "0") {
    currentText.clear();
  }
  // Проверяем, является ли последний символ цифрой или закрывающей скобкой
  QChar lastChar = currentText.isEmpty()
                       ? QChar()
                       : currentText.at(currentText.length() - 1);

  // Проверка, если последний символ в currentText это 'x' и нажата цифровая
  // кнопка
  if (!currentText.isEmpty() &&
      currentText.at(currentText.length() - 1) == 'x') {
    currentText.append('*');
  }
  if (lastChar.isDigit() || lastChar == ')') {
    // Если последний символ - цифра или закрывающая скобка, добавляем знак
    // умножения
    currentText.append("*");
  }

  currentText.append(button->text() + "(");
  ui->result->setText(currentText);
}

void MainWindow::on_pushButton_x_clicked() {
  isXPressed = true;
  QString currentText = ui->result->text();
  QPushButton *button = (QPushButton *)sender();
  QChar lastChar = currentText.isEmpty()
                       ? QChar()
                       : currentText.at(currentText.length() - 1);
  if (lastChar == 'x') {
    return;
  }
  if (lastChar.isDigit() || lastChar == ')') {
    // Если последний символ - цифра или закрывающая скобка, добавляем знак
    // умножения, если текущий текст не равен "0"
    if (currentText != "0") {
      currentText.append("*");
    }
  }
  if (currentText == "0") {
    currentText =
        button->text();  // Если текущий текст равен "0", заменяем его на "x"
  } else {
    currentText.append(button->text());
  }
  ui->result->setText(currentText);
}

void MainWindow::graph_draw(const QString &func) {
  // Получаем границы по осям x и y из пользовательского интерфейса
  double xMax = ui->Xmax->text().toDouble();
  double xMin = ui->Xmin->text().toDouble();
  double yMax = ui->Ymax->text().toDouble();
  double yMin = ui->Ymin->text().toDouble();
  if ((xMax > 1000000) || (xMin < -1000000) || (yMax > 1000000) ||
      (yMin < -1000000)) {
    ui->result->setText("Error");
    return;
  }
  const int numPoints =
      801;  // Количество точек, которые будут отрисованы на графике
  // Инициализируем векторы для хранения значений по осям x и y
  QVector<double> x(numPoints), y(numPoints);
  // Вычисляем шаг для оси x
  double step = (xMax - xMin) / numPoints;
  // Вычисляются значения для каждой точки на графике
  for (int i = 0; i < numPoints; ++i) {
    double xValue = xMin + i * step;  // Вычисляем значение x
    x[i] = xValue;
    QString expr = func;
    // Заменяем "x" в нашем выражении на текущее значение xValue
    expr.replace("x", QString::number(xValue, 'g', 7));
    QByteArray ba = expr.toLatin1();
    char *line = ba.data();
    // Вычисляем значение y для каждого x с помощью нашей функции
    try {
      double yValue = calculatorController.CalculateExpression(line);
      // Устанавливаем порог, чтобы скрыть асимптоты
      if (yValue > 10 || yValue < -10) {
        yValue = qQNaN();  // Ставим значение "не число", чтобы оно не
                           // отображалось на графике
      }
      y[i] = yValue;
    } catch (const std::invalid_argument &e) {
      ui->result->setText("Error");
      return;
    } catch (const std::runtime_error &e) {
      y[i] = qQNaN();
    }
  }
  // Создаем график и присваиваем ему данные:
  ui->graph->addGraph();
  QPen linePen(Qt::yellow);
  linePen.setWidth(2);
  ui->graph->graph(0)->setPen(linePen);
  ui->graph->graph(0)->setData(x, y);
  // Устанавливаем диапазоны для осей, чтобы отобразить все данные:
  ui->graph->xAxis->setRange(xMin, xMax);
  ui->graph->yAxis->setRange(yMin, yMax);
  // Перерисовываем график
  ui->graph->replot();
}

void MainWindow::on_pushButton_equal_clicked() {
  QString currentText = ui->result->text();
  currentText.replace("x", ui->lineEdit_x->text());
  if (isXPressed && ui->lineEdit_x->text().isEmpty()) {
    QString func = ui->result->text();
    graph_draw((func));
    return;
  }
  try {
    double res =
        calculatorController.CalculateExpression(currentText.toStdString());
    QString resultString;
    if (res == static_cast<int>(res)) {
      resultString = QString::number(static_cast<int>(res));
    } else {
      resultString = QString::number(res, 'g', 10);
    }
    ui->result->setText(resultString);
  } catch (const std::invalid_argument &e) {
    ui->result->setText("Incorrect");
  } catch (const std::runtime_error &e) {
    ui->result->setText("Incorrect");
  }
}

void MainWindow::connect_main() {
  connect(ui->pushButton_0, &QPushButton::clicked, this,
          &MainWindow::digit_pressed);
  connect(ui->pushButton_1, &QPushButton::clicked, this,
          &MainWindow::digit_pressed);
  connect(ui->pushButton_2, &QPushButton::clicked, this,
          &MainWindow::digit_pressed);
  connect(ui->pushButton_3, &QPushButton::clicked, this,
          &MainWindow::digit_pressed);
  connect(ui->pushButton_4, &QPushButton::clicked, this,
          &MainWindow::digit_pressed);
  connect(ui->pushButton_5, &QPushButton::clicked, this,
          &MainWindow::digit_pressed);
  connect(ui->pushButton_6, &QPushButton::clicked, this,
          &MainWindow::digit_pressed);
  connect(ui->pushButton_7, &QPushButton::clicked, this,
          &MainWindow::digit_pressed);
  connect(ui->pushButton_8, &QPushButton::clicked, this,
          &MainWindow::digit_pressed);
  connect(ui->pushButton_9, &QPushButton::clicked, this,
          &MainWindow::digit_pressed);
  connect(ui->pushButton_plus, &QPushButton::clicked, this,
          &MainWindow::operation_pressed);
  connect(ui->pushButton_minus, &QPushButton::clicked, this,
          &MainWindow::operation_pressed);
  connect(ui->pushButton_multy, &QPushButton::clicked, this,
          &MainWindow::operation_pressed);
  connect(ui->pushButton_div, &QPushButton::clicked, this,
          &MainWindow::operation_pressed);
  connect(ui->pushButton_pow, &QPushButton::clicked, this,
          &MainWindow::operation_pressed);
  connect(ui->pushButton_mod, &QPushButton::clicked, this,
          &MainWindow::operation_pressed);
  connect(ui->pushButton_left_bracket, &QPushButton::clicked, this,
          &MainWindow::bracket_pressed);
  connect(ui->pushButton_right_bracket, &QPushButton::clicked, this,
          &MainWindow::bracket_pressed);
  connect(ui->pushButton_sin, &QPushButton::clicked, this,
          &MainWindow::trigonometry);
  connect(ui->pushButton_cos, &QPushButton::clicked, this,
          &MainWindow::trigonometry);
  connect(ui->pushButton_tan, &QPushButton::clicked, this,
          &MainWindow::trigonometry);
  connect(ui->pushButton_asin, &QPushButton::clicked, this,
          &MainWindow::trigonometry);
  connect(ui->pushButton_acos, &QPushButton::clicked, this,
          &MainWindow::trigonometry);
  connect(ui->pushButton_atan, &QPushButton::clicked, this,
          &MainWindow::trigonometry);
  connect(ui->pushButton_ln, &QPushButton::clicked, this,
          &MainWindow::trigonometry);
  connect(ui->pushButton_sqrt, &QPushButton::clicked, this,
          &MainWindow::trigonometry);
  connect(ui->pushButton_log, &QPushButton::clicked, this,
          &MainWindow::trigonometry);
}

void MainWindow::qc_setup() {
  ui->graph->setBackground(QBrush(Qt::black));
  // Основные оси
  ui->graph->xAxis->setBasePen(QPen(Qt::white));
  ui->graph->yAxis->setBasePen(QPen(Qt::white));
  // Деления
  ui->graph->xAxis->setTickPen(QPen(Qt::white));
  ui->graph->yAxis->setTickPen(QPen(Qt::white));
  // Под-деления
  ui->graph->xAxis->setSubTickPen(QPen(Qt::white));
  ui->graph->yAxis->setSubTickPen(QPen(Qt::white));
  // Метки делений
  ui->graph->xAxis->setTickLabelColor(Qt::white);
  ui->graph->yAxis->setTickLabelColor(Qt::white);
  // Подписи к осям
  ui->graph->xAxis->setLabelColor(Qt::white);
  ui->graph->yAxis->setLabelColor(Qt::white);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_E && event->modifiers() == Qt::NoModifier) {
    QString currentText = ui->result->text();
    currentText.append("e");
    ui->result->setText(currentText);

  } else {
    // Для всех остальных клавиш вызываем родительский метод
    QMainWindow::keyPressEvent(event);
  }
}

void MainWindow::on_pushButton_credit_clicked() { credit.show(); }
void MainWindow::on_pushButton_deposit_clicked() { deposit.show(); }
