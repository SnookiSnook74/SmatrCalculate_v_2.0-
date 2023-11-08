#ifndef CPP3_SMARTCALC_V2_SRC_VIEW_MAINWINDOW_H
#define CPP3_SMARTCALC_V2_SRC_VIEW_MAINWINDOW_H

#include <QMainWindow>

#include "../controller/calculator_controller.h"
#include "creditview.h"
#include "depositview.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  s21::CalculatorController calculatorController;
  Ui::MainWindow *ui;
  bool isXPressed;
  CreditView credit;
  DepositView deposit;

 private slots:
  void on_pushButton_AC_clicked();
  void on_pushButton_point_clicked();
  void on_pushButton_plus_minus_clicked();
  void on_pushButton_equal_clicked();
  void on_pushButton_x_clicked();
  void operation_pressed();
  void bracket_pressed();
  void digit_pressed();
  void trigonometry();
  void graph_draw(const QString &func);
  void qc_setup();
  void connect_main();
  void keyPressEvent(QKeyEvent *event);

  void on_pushButton_credit_clicked();
  void on_pushButton_deposit_clicked();
};
#endif  // CPP3_SMARTCALC_V2_SRC_VIEW_MAINWINDOW_H
