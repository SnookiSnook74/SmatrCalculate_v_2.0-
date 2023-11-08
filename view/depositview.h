#ifndef CPP3_SMARTCALC_V2_SRC_VIEW_DEPOSITVIEW_H
#define CPP3_SMARTCALC_V2_SRC_VIEW_DEPOSITVIEW_H

#include <QTableWidget>
#include <QWidget>
#include <cmath>

#include "../controller/calculator_controller.h"

namespace Ui {
class DepositView;
}

class DepositView : public QWidget {
  Q_OBJECT

 public:
  explicit DepositView(QWidget *parent = nullptr);
  ~DepositView();
  std::vector<s21::Deposit::Operation> extractOperationsFromTable(
      QTableWidget *table) const;
  void UiSetting();

 private slots:

  void on_pushButton_toUp_clicked();
  void on_pushButton_toUp_clean_clicked();
  void on_pushButton_toDown_clicked();
  void on_pushButton_toDown_clean_clicked();
  void on_pushButton_final_clicked();

 private:
  Ui::DepositView *ui;
  s21::CalculatorController calculatorController;
};

#endif  // CPP3_SMARTCALC_V2_SRC_VIEW_DEPOSITVIEW_H
