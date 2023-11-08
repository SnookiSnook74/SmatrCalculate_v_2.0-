#include "depositview.h"

#include "ui_depositview.h"

DepositView::DepositView(QWidget *parent)
    : QWidget(parent), ui(new Ui::DepositView) {
  ui->setupUi(this);
  UiSetting();
}

DepositView::~DepositView() { delete ui; }

void DepositView::on_pushButton_toUp_clicked() {
  QString type = ui->comboBox->currentText();
  QDate date = ui->dateOfTopUp->date();
  QString sum = ui->sumUp->text();
  int newRow = ui->tableWidget_toUp->rowCount();
  ui->tableWidget_toUp->insertRow(newRow);
  ui->tableWidget_toUp->setItem(newRow, 0, new QTableWidgetItem(type));
  ui->tableWidget_toUp->setItem(
      newRow, 1, new QTableWidgetItem(date.toString("dd.MM.yyyy")));
  ui->tableWidget_toUp->setItem(newRow, 2, new QTableWidgetItem(sum));
}

void DepositView::on_pushButton_toUp_clean_clicked() {
  ui->tableWidget_toUp->setRowCount(0);
}

void DepositView::on_pushButton_toDown_clicked() {
  QString type = ui->comboBoxDown->currentText();
  QDate date = ui->dateOfTopDown->date();
  QString sum = ui->sumDown->text();
  int newRow = ui->tableWidget_toDown->rowCount();
  ui->tableWidget_toDown->insertRow(newRow);
  ui->tableWidget_toDown->setItem(newRow, 0, new QTableWidgetItem(type));
  ui->tableWidget_toDown->setItem(
      newRow, 1, new QTableWidgetItem(date.toString("dd.MM.yyyy")));
  ui->tableWidget_toDown->setItem(newRow, 2, new QTableWidgetItem(sum));
}

void DepositView::on_pushButton_toDown_clean_clicked() {
  ui->tableWidget_toDown->setRowCount(0);
}

void DepositView::on_pushButton_final_clicked() {
  s21::Deposit::InputData inputData;
  // std::vector<s21::Deposit::Operation> toUP;
  s21::Deposit::Result result;
  inputData.startSum = ui->depositSum->text().toStdString();
  inputData.duration = ui->depositDuration->text().toStdString();
  int startDay = ui->depositDate->date().day();
  int startMonth = ui->depositDate->date().month();
  int startYear = ui->depositDate->date().year();
  tm placementDate{0, 0, 0, startDay, startMonth, startYear, 0, 0, 0, 0, 0};
  inputData.placementDate = placementDate;
  inputData.interestRate = ui->depositRate->text().toStdString();
  inputData.taxRate = ui->depositTaxRate->text().toStdString();
  inputData.frequency = ui->frequency->currentText().toStdString();
  inputData.capitalization = ui->depositCapitalisation->isChecked();
  inputData.topUps = extractOperationsFromTable(ui->tableWidget_toUp);
  inputData.withdrawals = extractOperationsFromTable(ui->tableWidget_toDown);
  try {
    result = calculatorController.CalculateDeposit(inputData);
  } catch (...) {
    return;
  }

  ui->depositResultAccum->setText(QString::fromStdString(result.percentage));
  ui->depositResultTax->setText(QString::fromStdString(result.tax));
  ui->depositResultFinalSum->setText(
      QString::fromStdString(result.depositAmount));
}

std::vector<s21::Deposit::Operation> DepositView::extractOperationsFromTable(
    QTableWidget *table) const {
  std::vector<s21::Deposit::Operation> operations;
  for (int row = 0; row < table->rowCount(); ++row) {
    s21::Deposit::Operation operation;
    operation.type = table->item(row, 0)->text().toStdString();
    QDate date = QDate::fromString(table->item(row, 1)->text(), "dd.MM.yyyy");
    int day = date.day();
    int month = date.month();
    int year = date.year();
    tm OperationDate{0, 0, 0, day, month, year, 0, 0, 0, 0, 0};
    operation.date = OperationDate;
    operation.sum = table->item(row, 2)->text().toStdString();
    operations.push_back(operation);
  }

  return operations;
}

void DepositView::UiSetting() {
  this->setFixedSize(this->width(), this->height());
  ui->tableWidget_toUp->horizontalHeader()->setSectionResizeMode(
      0, QHeaderView::Stretch);
  ui->tableWidget_toUp->horizontalHeader()->setSectionResizeMode(
      1, QHeaderView::Fixed);
  ui->tableWidget_toUp->horizontalHeader()->setSectionResizeMode(
      2, QHeaderView::Stretch);
  ui->tableWidget_toDown->horizontalHeader()->setSectionResizeMode(
      0, QHeaderView::Stretch);
  ui->tableWidget_toDown->horizontalHeader()->setSectionResizeMode(
      1, QHeaderView::Fixed);
  ui->tableWidget_toDown->horizontalHeader()->setSectionResizeMode(
      2, QHeaderView::Stretch);
  ui->dateOfTopUp->setDisplayFormat("dd.MM.yyyy");
  ui->dateOfTopDown->setDisplayFormat("dd.MM.yyyy");
  ui->depositDate->setDisplayFormat("dd.MM.yyyy");
  QValidator *validator = new QDoubleValidator(0.01, 99999999999.99, 2, this);
  ui->sumUp->setValidator(validator);
  ui->sumDown->setValidator(validator);
  ui->depositDuration->setValidator(validator);
  ui->depositSum->setValidator(validator);
  ui->depositRate->setValidator(validator);
  ui->depositTaxRate->setValidator(validator);
}
