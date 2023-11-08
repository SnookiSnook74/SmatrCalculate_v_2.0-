#ifndef CPP3_SMARTCALC_V2_SRC_VIEW_CREDITVIEW_H
#define CPP3_SMARTCALC_V2_SRC_VIEW_CREDITVIEW_H

#include <QWidget>

#include "../controller/calculator_controller.h"

namespace Ui {
class CreditView;
}

class CreditView : public QWidget {
  Q_OBJECT

 public:
  explicit CreditView(QWidget *parent = nullptr);
  ~CreditView();

 private slots:
  void on_pushButton_clicked();

 private:
  Ui::CreditView *ui;
  s21::CalculatorController calculatorController;
};

#endif  // CPP3_SMARTCALC_V2_SRC_VIEW_CREDITVIEW_H
