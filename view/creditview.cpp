#include "creditview.h"

#include "ui_creditview.h"

CreditView::CreditView(QWidget* parent)
    : QWidget(parent), ui(new Ui::CreditView) {
  ui->setupUi(this);
  this->setFixedSize(this->width(), this->height());
  ui->tableWidget->setColumnWidth(0, 70);
  ui->tableWidget->setColumnWidth(2, 160);
  ui->tableWidget->setColumnWidth(3, 160);
  ui->radioButton_aut->click();
  QIntValidator* intValidator = new QIntValidator(this);
  ui->sum_credit->setValidator(intValidator);
  ui->time_credit->setValidator(intValidator);
  QDoubleValidator* doubleValidator =
      new QDoubleValidator(0.00, 100.00, 2, this);
  doubleValidator->setNotation(QDoubleValidator::StandardNotation);
  ui->percent_credit->setValidator(doubleValidator);
}

CreditView::~CreditView() { delete ui; }

void CreditView::on_pushButton_clicked() {
  double totalPaymentsSum = 0.0;
  double totalInterestPaymentsSum = 0.0;
  double totalPrincipalPaymentsSum = 0.0;
  ui->tableWidget->clearContents();
  ui->tableWidget->setRowCount(0);
  double amount = ui->sum_credit->text().toDouble();
  int months = ui->time_credit->text().toInt();
  double rate = ui->percent_credit->text().toDouble();
  if (ui->year_and_month->currentIndex() == 1) {
    months *= 12;
  }
  std::vector<s21::Credit::PaymentInfo> payments;
  if (ui->radioButton_aut->isChecked()) {
    payments =
        calculatorController.CalculatePaymentSchedule(amount, months, rate);
  } else if (ui->radioButton_dif->isChecked()) {
    payments =
        calculatorController.CalculatePaymentDiffSchedule(amount, months, rate);
  }

  for (size_t i = 0; i < payments.size(); i++) {
    ui->tableWidget->insertRow(i);
    ui->tableWidget->setItem(i, 0,
                             new QTableWidgetItem(QString::number(i + 1)));
    ui->tableWidget->setItem(i, 1,
                             new QTableWidgetItem(QString::number(
                                 payments[i].totalPayment, 'f', 2)));
    ui->tableWidget->setItem(i, 2,
                             new QTableWidgetItem(QString::number(
                                 payments[i].interestPayment, 'f', 2)));
    ui->tableWidget->setItem(i, 3,
                             new QTableWidgetItem(QString::number(
                                 payments[i].principalPayment, 'f', 2)));
    ui->tableWidget->setItem(i, 4,
                             new QTableWidgetItem(QString::number(
                                 payments[i].remainingDebt, 'f', 2)));
    totalPaymentsSum += payments[i].totalPayment;
    totalInterestPaymentsSum += payments[i].interestPayment;
    totalPrincipalPaymentsSum += payments[i].principalPayment;
  }
  int lastRowIndex = payments.size();
  ui->tableWidget->insertRow(lastRowIndex);
  ui->tableWidget->setItem(lastRowIndex, 0, new QTableWidgetItem("Итого"));
  ui->tableWidget->setItem(
      lastRowIndex, 1,
      new QTableWidgetItem(QString::number(totalPaymentsSum, 'f', 2)));
  ui->tableWidget->setItem(
      lastRowIndex, 2,
      new QTableWidgetItem(QString::number(totalInterestPaymentsSum, 'f', 2)));
  ui->tableWidget->setItem(
      lastRowIndex, 3,
      new QTableWidgetItem(QString::number(totalPrincipalPaymentsSum, 'f', 2)));
  QBrush brush(QColor(255, 150, 17));
  for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
    QTableWidgetItem* item = ui->tableWidget->item(lastRowIndex, col);
    if (item) {
      item->setBackground(brush);
    }
  }
}
