/********************************************************************************
** Form generated from reading UI file 'depositview.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSITVIEW_H
#define UI_DEPOSITVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DepositView
{
public:
    QGroupBox *groupBoxUp;
    QPushButton *pushButton_toUp;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QDateEdit *dateOfTopUp;
    QLineEdit *sumUp;
    QTableWidget *tableWidget_toUp;
    QPushButton *pushButton_toUp_clean;
    QGroupBox *groupBoxDown;
    QPushButton *pushButton_toDown;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBoxDown;
    QDateEdit *dateOfTopDown;
    QLineEdit *sumDown;
    QTableWidget *tableWidget_toDown;
    QPushButton *pushButton_toDown_clean;
    QGroupBox *groupBox;
    QDateEdit *depositDate;
    QLabel *label_25;
    QLineEdit *depositTaxRate;
    QLabel *label_27;
    QLineEdit *depositRate;
    QLineEdit *depositSum;
    QComboBox *frequency;
    QCheckBox *depositCapitalisation;
    QLineEdit *depositDuration;
    QLabel *label_29;
    QLabel *label_33;
    QLabel *label_32;
    QLabel *label_24;
    QLabel *label_26;
    QLabel *label_28;
    QLabel *label_31;
    QLabel *label_30;
    QPushButton *pushButton_final;
    QGroupBox *groupBox_2;
    QLabel *label_36;
    QLabel *label_38;
    QLabel *depositResultAccum;
    QLabel *label_34;
    QLabel *depositResultFinalSum;
    QLabel *label_40;
    QLabel *label_42;
    QLabel *label_41;
    QLabel *depositResultTax;

    void setupUi(QWidget *DepositView)
    {
        if (DepositView->objectName().isEmpty())
            DepositView->setObjectName("DepositView");
        DepositView->resize(983, 450);
        DepositView->setStyleSheet(QString::fromUtf8("background-color: rgb(66, 66, 66)"));
        groupBoxUp = new QGroupBox(DepositView);
        groupBoxUp->setObjectName("groupBoxUp");
        groupBoxUp->setGeometry(QRect(500, 10, 461, 211));
        QFont font;
        font.setFamilies({QString::fromUtf8("Quicksand")});
        groupBoxUp->setFont(font);
        pushButton_toUp = new QPushButton(groupBoxUp);
        pushButton_toUp->setObjectName("pushButton_toUp");
        pushButton_toUp->setGeometry(QRect(10, 180, 221, 31));
        pushButton_toUp->setFont(font);
        pushButton_toUp->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   color: white;\n"
"   border-radius: 10px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        horizontalLayoutWidget = new QWidget(groupBoxUp);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 150, 451, 32));
        horizontalLayoutWidget->setFont(font);
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(horizontalLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setFont(font);
        comboBox->setStyleSheet(QString::fromUtf8("/* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\270 \321\202\320\265\320\272\321\201\321\202\320\260 \320\276\321\201\320\275\320\276\320\262\320\275\320\276\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"QComboBox {\n"
"    background-color: #FFFFFF; \n"
"    color: black; \n"
"}\n"
"\n"
"/* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\270 \321\202\320\265\320\272\321\201\321\202\320\260 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #808080;\n"
"    color: black;\n"
"}\n"
"\n"
"/* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\270 \321\202\320\265\320\272\321\201\321\202\320\260 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260 \321\201\320\277\320\270\321\201\320\272\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320"
                        "\265\320\275\320\270\320\270 */\n"
"QComboBox QAbstractItemView::item:hover {\n"
"    background-color: #A0A0A0;\n"
"    color: black;\n"
"}\n"
"\n"
"/* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\270 \321\202\320\265\320\272\321\201\321\202\320\260 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\263\320\276 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"QComboBox::item:selected {\n"
"    background-color: #707070;\n"
"    color: black;\n"
"}\n"
""));

        horizontalLayout->addWidget(comboBox);

        dateOfTopUp = new QDateEdit(horizontalLayoutWidget);
        dateOfTopUp->setObjectName("dateOfTopUp");
        dateOfTopUp->setFont(font);
        dateOfTopUp->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"background-color: white;\n"
"color: black;\n"
"}"));
        dateOfTopUp->setAlignment(Qt::AlignCenter);
        dateOfTopUp->setDateTime(QDateTime(QDate(2023, 12, 31), QTime(17, 0, 0)));

        horizontalLayout->addWidget(dateOfTopUp);

        sumUp = new QLineEdit(horizontalLayoutWidget);
        sumUp->setObjectName("sumUp");
        sumUp->setFont(font);
        sumUp->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"background-color: white;\n"
"color: black;\n"
"}"));
        sumUp->setMaxLength(32761);
        sumUp->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(sumUp);

        tableWidget_toUp = new QTableWidget(groupBoxUp);
        if (tableWidget_toUp->columnCount() < 3)
            tableWidget_toUp->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_toUp->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_toUp->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_toUp->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget_toUp->setObjectName("tableWidget_toUp");
        tableWidget_toUp->setGeometry(QRect(0, 10, 461, 131));
        tableWidget_toUp->setFont(font);
        tableWidget_toUp->setStyleSheet(QString::fromUtf8("QHeaderView::section {\n"
"    background-color: rgb(255, 156, 58);\n"
"    color: white;\n"
"}\n"
"QTableWidget {\n"
"    background-color: rgb(0, 0, 0);\n"
"color: white;\n"
"}"));
        pushButton_toUp_clean = new QPushButton(groupBoxUp);
        pushButton_toUp_clean->setObjectName("pushButton_toUp_clean");
        pushButton_toUp_clean->setGeometry(QRect(240, 180, 211, 32));
        pushButton_toUp_clean->setFont(font);
        pushButton_toUp_clean->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   color: white;\n"
"   border-radius: 10px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        horizontalLayoutWidget->raise();
        tableWidget_toUp->raise();
        pushButton_toUp->raise();
        pushButton_toUp_clean->raise();
        groupBoxDown = new QGroupBox(DepositView);
        groupBoxDown->setObjectName("groupBoxDown");
        groupBoxDown->setGeometry(QRect(500, 230, 471, 211));
        groupBoxDown->setFont(font);
        pushButton_toDown = new QPushButton(groupBoxDown);
        pushButton_toDown->setObjectName("pushButton_toDown");
        pushButton_toDown->setGeometry(QRect(10, 180, 221, 32));
        pushButton_toDown->setFont(font);
        pushButton_toDown->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   color: white;\n"
"   border-radius: 10px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        horizontalLayoutWidget_3 = new QWidget(groupBoxDown);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(0, 150, 451, 32));
        horizontalLayoutWidget_3->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        comboBoxDown = new QComboBox(horizontalLayoutWidget_3);
        comboBoxDown->addItem(QString());
        comboBoxDown->addItem(QString());
        comboBoxDown->addItem(QString());
        comboBoxDown->addItem(QString());
        comboBoxDown->addItem(QString());
        comboBoxDown->addItem(QString());
        comboBoxDown->setObjectName("comboBoxDown");
        comboBoxDown->setFont(font);
        comboBoxDown->setStyleSheet(QString::fromUtf8("/* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\270 \321\202\320\265\320\272\321\201\321\202\320\260 \320\276\321\201\320\275\320\276\320\262\320\275\320\276\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"QComboBox {\n"
"    background-color: #FFFFFF; \n"
"    color: black; \n"
"}\n"
"\n"
"/* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\270 \321\202\320\265\320\272\321\201\321\202\320\260 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #808080;\n"
"    color: black;\n"
"}\n"
"\n"
"/* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\270 \321\202\320\265\320\272\321\201\321\202\320\260 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260 \321\201\320\277\320\270\321\201\320\272\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320"
                        "\265\320\275\320\270\320\270 */\n"
"QComboBox QAbstractItemView::item:hover {\n"
"    background-color: #A0A0A0;\n"
"    color: black;\n"
"}\n"
"\n"
"/* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\270 \321\202\320\265\320\272\321\201\321\202\320\260 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\263\320\276 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"QComboBox::item:selected {\n"
"    background-color: #707070;\n"
"    color: black;\n"
"}"));

        horizontalLayout_3->addWidget(comboBoxDown);

        dateOfTopDown = new QDateEdit(horizontalLayoutWidget_3);
        dateOfTopDown->setObjectName("dateOfTopDown");
        dateOfTopDown->setFont(font);
        dateOfTopDown->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"background-color: white;\n"
"color: black;\n"
"}"));
        dateOfTopDown->setAlignment(Qt::AlignCenter);
        dateOfTopDown->setDateTime(QDateTime(QDate(2023, 12, 31), QTime(12, 0, 0)));

        horizontalLayout_3->addWidget(dateOfTopDown);

        sumDown = new QLineEdit(horizontalLayoutWidget_3);
        sumDown->setObjectName("sumDown");
        sumDown->setFont(font);
        sumDown->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"background-color: white;\n"
"color: black;\n"
"}"));
        sumDown->setMaxLength(32761);
        sumDown->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(sumDown);

        tableWidget_toDown = new QTableWidget(groupBoxDown);
        if (tableWidget_toDown->columnCount() < 3)
            tableWidget_toDown->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_toDown->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_toDown->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_toDown->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        tableWidget_toDown->setObjectName("tableWidget_toDown");
        tableWidget_toDown->setGeometry(QRect(0, 10, 461, 131));
        tableWidget_toDown->setFont(font);
        tableWidget_toDown->setStyleSheet(QString::fromUtf8("QHeaderView::section {\n"
"    background-color: rgb(255, 156, 58);\n"
"    color: white;\n"
"}\n"
"QTableWidget {\n"
"    background-color: rgb(0, 0, 0);\n"
"color: white;\n"
"}"));
        pushButton_toDown_clean = new QPushButton(groupBoxDown);
        pushButton_toDown_clean->setObjectName("pushButton_toDown_clean");
        pushButton_toDown_clean->setGeometry(QRect(240, 180, 211, 32));
        pushButton_toDown_clean->setFont(font);
        pushButton_toDown_clean->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   color: white;\n"
"   border-radius: 10px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        horizontalLayoutWidget_3->raise();
        tableWidget_toDown->raise();
        pushButton_toDown->raise();
        pushButton_toDown_clean->raise();
        groupBox = new QGroupBox(DepositView);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 20, 491, 261));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(66, 66, 66)"));
        depositDate = new QDateEdit(groupBox);
        depositDate->setObjectName("depositDate");
        depositDate->setGeometry(QRect(180, 70, 231, 25));
        depositDate->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"background-color: white;\n"
"color: black;\n"
"}"));
        depositDate->setDateTime(QDateTime(QDate(2023, 12, 31), QTime(14, 0, 0)));
        depositDate->setCalendarPopup(true);
        label_25 = new QLabel(groupBox);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(420, 100, 81, 17));
        label_25->setFont(font);
        label_25->setStyleSheet(QString::fromUtf8("color:white;"));
        depositTaxRate = new QLineEdit(groupBox);
        depositTaxRate->setObjectName("depositTaxRate");
        depositTaxRate->setGeometry(QRect(180, 130, 231, 25));
        depositTaxRate->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"background-color: white;\n"
"color: black;\n"
"}"));
        depositTaxRate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_27 = new QLabel(groupBox);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(10, 100, 141, 20));
        label_27->setFont(font);
        label_27->setStyleSheet(QString::fromUtf8("color:white;"));
        depositRate = new QLineEdit(groupBox);
        depositRate->setObjectName("depositRate");
        depositRate->setGeometry(QRect(180, 100, 231, 25));
        depositRate->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"background-color: white;\n"
"color: black;\n"
"}"));
        depositRate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        depositSum = new QLineEdit(groupBox);
        depositSum->setObjectName("depositSum");
        depositSum->setGeometry(QRect(180, 10, 231, 25));
        depositSum->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"background-color: white;\n"
"color: black;\n"
"}"));
        depositSum->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        frequency = new QComboBox(groupBox);
        frequency->addItem(QString());
        frequency->addItem(QString());
        frequency->addItem(QString());
        frequency->addItem(QString());
        frequency->addItem(QString());
        frequency->addItem(QString());
        frequency->addItem(QString());
        frequency->setObjectName("frequency");
        frequency->setGeometry(QRect(180, 160, 231, 25));
        frequency->setStyleSheet(QString::fromUtf8("/* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\270 \321\202\320\265\320\272\321\201\321\202\320\260 \320\276\321\201\320\275\320\276\320\262\320\275\320\276\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"QComboBox {\n"
"    background-color: #FFFFFF; \n"
"    color: black; \n"
"}\n"
"\n"
"/* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\270 \321\202\320\265\320\272\321\201\321\202\320\260 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #808080;\n"
"    color: black;\n"
"}\n"
"\n"
"/* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\270 \321\202\320\265\320\272\321\201\321\202\320\260 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260 \321\201\320\277\320\270\321\201\320\272\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320"
                        "\265\320\275\320\270\320\270 */\n"
"QComboBox QAbstractItemView::item:hover {\n"
"    background-color: #A0A0A0;\n"
"    color: black;\n"
"}\n"
"\n"
"/* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\270 \321\202\320\265\320\272\321\201\321\202\320\260 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\263\320\276 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"QComboBox::item:selected {\n"
"    background-color: #707070;\n"
"    color: black;\n"
"}\n"
""));
        depositCapitalisation = new QCheckBox(groupBox);
        depositCapitalisation->setObjectName("depositCapitalisation");
        depositCapitalisation->setGeometry(QRect(180, 190, 231, 23));
        depositCapitalisation->setFont(font);
        depositCapitalisation->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"color: white;\n"
"}"));
        depositDuration = new QLineEdit(groupBox);
        depositDuration->setObjectName("depositDuration");
        depositDuration->setGeometry(QRect(180, 40, 231, 25));
        depositDuration->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"background-color: white;\n"
"color: black;\n"
"}"));
        depositDuration->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_29 = new QLabel(groupBox);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(10, 40, 151, 20));
        label_29->setFont(font);
        label_29->setStyleSheet(QString::fromUtf8("color:white;"));
        label_33 = new QLabel(groupBox);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(10, 70, 161, 20));
        label_33->setFont(font);
        label_33->setStyleSheet(QString::fromUtf8("color:white;"));
        label_32 = new QLabel(groupBox);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(10, 160, 171, 20));
        label_32->setFont(font);
        label_32->setStyleSheet(QString::fromUtf8("color:white;"));
        label_24 = new QLabel(groupBox);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(420, 40, 67, 17));
        label_24->setFont(font);
        label_24->setStyleSheet(QString::fromUtf8("color:white;"));
        label_26 = new QLabel(groupBox);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(10, 10, 161, 20));
        label_26->setFont(font);
        label_26->setStyleSheet(QString::fromUtf8("color:white;"));
        label_28 = new QLabel(groupBox);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(420, 10, 67, 17));
        label_28->setFont(font);
        label_28->setStyleSheet(QString::fromUtf8("color:white;"));
        label_31 = new QLabel(groupBox);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(420, 130, 81, 17));
        label_31->setFont(font);
        label_31->setStyleSheet(QString::fromUtf8("color:white;"));
        label_30 = new QLabel(groupBox);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(10, 130, 151, 20));
        label_30->setFont(font);
        label_30->setStyleSheet(QString::fromUtf8("color:white;"));
        pushButton_final = new QPushButton(groupBox);
        pushButton_final->setObjectName("pushButton_final");
        pushButton_final->setGeometry(QRect(180, 220, 231, 31));
        pushButton_final->setFont(font);
        pushButton_final->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   color: white;\n"
"   border-radius: 10px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        groupBox_2 = new QGroupBox(DepositView);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(0, 300, 491, 121));
        label_36 = new QLabel(groupBox_2);
        label_36->setObjectName("label_36");
        label_36->setEnabled(false);
        label_36->setGeometry(QRect(420, 70, 67, 17));
        label_36->setStyleSheet(QString::fromUtf8("color: white;"));
        label_38 = new QLabel(groupBox_2);
        label_38->setObjectName("label_38");
        label_38->setEnabled(false);
        label_38->setGeometry(QRect(10, 70, 211, 20));
        label_38->setStyleSheet(QString::fromUtf8("color: white;"));
        depositResultAccum = new QLabel(groupBox_2);
        depositResultAccum->setObjectName("depositResultAccum");
        depositResultAccum->setEnabled(false);
        depositResultAccum->setGeometry(QRect(180, 10, 231, 25));
        depositResultAccum->setStyleSheet(QString::fromUtf8("QLabel {\n"
"background-color: white;\n"
"color: black;\n"
"}\n"
"\n"
"QLabel:disabled{\n"
"	border: 1px solid grey;\n"
"}"));
        depositResultAccum->setTextInteractionFlags(Qt::NoTextInteraction);
        label_34 = new QLabel(groupBox_2);
        label_34->setObjectName("label_34");
        label_34->setEnabled(false);
        label_34->setGeometry(QRect(420, 40, 67, 17));
        label_34->setStyleSheet(QString::fromUtf8("color: white;"));
        depositResultFinalSum = new QLabel(groupBox_2);
        depositResultFinalSum->setObjectName("depositResultFinalSum");
        depositResultFinalSum->setEnabled(false);
        depositResultFinalSum->setGeometry(QRect(180, 70, 231, 25));
        depositResultFinalSum->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: white;\n"
"color: black;\n"
"}\n"
"QLabel:disabled{\n"
"	border: 1px solid grey;\n"
"}"));
        depositResultFinalSum->setTextInteractionFlags(Qt::NoTextInteraction);
        label_40 = new QLabel(groupBox_2);
        label_40->setObjectName("label_40");
        label_40->setEnabled(false);
        label_40->setGeometry(QRect(420, 10, 67, 17));
        label_40->setStyleSheet(QString::fromUtf8("color: white;"));
        label_42 = new QLabel(groupBox_2);
        label_42->setObjectName("label_42");
        label_42->setEnabled(false);
        label_42->setGeometry(QRect(10, 40, 151, 20));
        label_42->setStyleSheet(QString::fromUtf8("color: white;"));
        label_41 = new QLabel(groupBox_2);
        label_41->setObjectName("label_41");
        label_41->setEnabled(false);
        label_41->setGeometry(QRect(10, 10, 161, 20));
        label_41->setStyleSheet(QString::fromUtf8("color: white;"));
        depositResultTax = new QLabel(groupBox_2);
        depositResultTax->setObjectName("depositResultTax");
        depositResultTax->setEnabled(false);
        depositResultTax->setGeometry(QRect(180, 40, 231, 25));
        depositResultTax->setStyleSheet(QString::fromUtf8("QLabel {\n"
"background-color: white;\n"
"color: black;\n"
"}\n"
"\n"
"QLabel:disabled{\n"
"	border: 1px solid grey;\n"
"}"));
        depositResultTax->setTextInteractionFlags(Qt::NoTextInteraction);

        retranslateUi(DepositView);

        QMetaObject::connectSlotsByName(DepositView);
    } // setupUi

    void retranslateUi(QWidget *DepositView)
    {
        DepositView->setWindowTitle(QCoreApplication::translate("DepositView", "Deposit", nullptr));
        groupBoxUp->setTitle(QString());
        pushButton_toUp->setText(QCoreApplication::translate("DepositView", "\320\237\320\276\320\277\320\276\320\273\320\275\320\270\321\202\321\214", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("DepositView", "\320\240\320\260\320\267\320\276\320\262\320\276\320\265", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("DepositView", "\320\240\320\260\320\267 \320\262 \320\274\320\265\321\201\321\217\321\206", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("DepositView", "\320\240\320\260\320\267 \320\262 2 \320\274\320\265\321\201\321\217\321\206\320\260", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("DepositView", "\320\240\320\260\320\267 \320\262 \320\272\320\262\320\260\321\200\321\202\320\260\320\273", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("DepositView", "\320\240\320\260\320\267 \320\262 \320\277\320\276\320\273\320\263\320\276\320\264\320\260", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("DepositView", "\320\240\320\260\320\267 \320\262 \320\263\320\276\320\264", nullptr));

        sumUp->setPlaceholderText(QCoreApplication::translate("DepositView", "\320\241\321\203\320\274\320\274\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_toUp->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DepositView", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260 \320\277\320\276\320\277\320\276\320\273\320\265\320\275\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_toUp->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DepositView", "\320\224\320\260\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_toUp->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DepositView", "\320\241\321\203\320\274\320\274\320\260", nullptr));
        pushButton_toUp_clean->setText(QCoreApplication::translate("DepositView", "\320\236\321\202\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        groupBoxDown->setTitle(QString());
        pushButton_toDown->setText(QCoreApplication::translate("DepositView", "\320\241\320\275\321\217\321\202\321\214", nullptr));
        comboBoxDown->setItemText(0, QCoreApplication::translate("DepositView", "\320\240\320\260\320\267\320\276\320\262\320\276\320\265", nullptr));
        comboBoxDown->setItemText(1, QCoreApplication::translate("DepositView", "\320\240\320\260\320\267 \320\262 \320\274\320\265\321\201\321\217\321\206", nullptr));
        comboBoxDown->setItemText(2, QCoreApplication::translate("DepositView", "\320\240\320\260\320\267 \320\262 2 \320\274\320\265\321\201\321\217\321\206\320\260", nullptr));
        comboBoxDown->setItemText(3, QCoreApplication::translate("DepositView", "\320\240\320\260\320\267 \320\262 \320\272\320\262\320\260\321\200\321\202\320\260\320\273", nullptr));
        comboBoxDown->setItemText(4, QCoreApplication::translate("DepositView", "\320\240\320\260\320\267 \320\262 \320\277\320\276\320\273\320\263\320\276\320\264\320\260", nullptr));
        comboBoxDown->setItemText(5, QCoreApplication::translate("DepositView", "\320\240\320\260\320\267 \320\262 \320\263\320\276\320\264", nullptr));

        sumDown->setPlaceholderText(QCoreApplication::translate("DepositView", "\320\241\321\203\320\274\320\274\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_toDown->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DepositView", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260 \321\201\320\275\321\217\321\202\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_toDown->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DepositView", "\320\224\320\260\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_toDown->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("DepositView", "\320\241\321\203\320\274\320\274\320\260", nullptr));
        pushButton_toDown_clean->setText(QCoreApplication::translate("DepositView", "\320\236\321\202\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        groupBox->setTitle(QString());
        label_25->setText(QCoreApplication::translate("DepositView", "% \320\263\320\276\320\264\320\276\320\262\321\213\321\205", nullptr));
        label_27->setText(QCoreApplication::translate("DepositView", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        depositRate->setPlaceholderText(QString());
        depositSum->setText(QString());
        depositSum->setPlaceholderText(QString());
        frequency->setItemText(0, QCoreApplication::translate("DepositView", "\320\232\320\260\320\266\320\264\321\213\320\271 \320\264\320\265\320\275\321\214", nullptr));
        frequency->setItemText(1, QCoreApplication::translate("DepositView", "\320\232\320\260\320\266\320\264\321\203\321\216 \320\275\320\265\320\264\320\265\320\273\321\216", nullptr));
        frequency->setItemText(2, QCoreApplication::translate("DepositView", "\320\240\320\260\320\267 \320\262 \320\274\320\265\321\201\321\217\321\206", nullptr));
        frequency->setItemText(3, QCoreApplication::translate("DepositView", "\320\240\320\260\320\267 \320\262 \320\272\320\262\320\260\321\200\321\202\320\260\320\273", nullptr));
        frequency->setItemText(4, QCoreApplication::translate("DepositView", "\320\240\320\260\320\267 \320\262 \320\277\320\276\320\273\320\263\320\276\320\264\320\260", nullptr));
        frequency->setItemText(5, QCoreApplication::translate("DepositView", "\320\240\320\260\320\267 \320\262 \320\263\320\276\320\264", nullptr));
        frequency->setItemText(6, QCoreApplication::translate("DepositView", "\320\222 \320\272\320\276\320\275\321\206\320\265 \321\201\321\200\320\276\320\272\320\260", nullptr));

        depositCapitalisation->setText(QCoreApplication::translate("DepositView", "\320\232\320\260\320\277\320\270\321\202\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\276\320\262", nullptr));
        depositDuration->setPlaceholderText(QString());
        label_29->setText(QCoreApplication::translate("DepositView", "\320\241\321\200\320\276\320\272 \321\200\320\260\320\267\320\274\320\265\321\211\320\265\320\275\320\270\321\217", nullptr));
        label_33->setText(QCoreApplication::translate("DepositView", "\320\224\320\260\321\202\320\260 \320\275\320\260\321\207\320\260\320\273\320\260 \321\200\320\260\320\267\320\274\320\265\321\211\320\265\320\275\320\270\321\217", nullptr));
        label_32->setText(QCoreApplication::translate("DepositView", "\320\237\320\265\321\200\320\270\320\276\320\264\320\270\321\207\320\275\320\276\321\201\321\202\321\214 \320\262\321\213\320\277\320\273\320\260\321\202", nullptr));
        label_24->setText(QCoreApplication::translate("DepositView", "\320\274\320\265\321\201\321\217\321\206\320\265\320\262", nullptr));
        label_26->setText(QCoreApplication::translate("DepositView", "\320\241\321\203\320\274\320\274\320\260 \320\262\320\272\320\273\320\260\320\264\320\260", nullptr));
        label_28->setText(QCoreApplication::translate("DepositView", "\321\200\321\203\320\261.", nullptr));
        label_31->setText(QCoreApplication::translate("DepositView", "%", nullptr));
        label_30->setText(QCoreApplication::translate("DepositView", "\320\235\320\260\320\273\320\276\320\263\320\276\320\262\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        pushButton_final->setText(QCoreApplication::translate("DepositView", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        groupBox_2->setTitle(QString());
        label_36->setText(QCoreApplication::translate("DepositView", "\321\200\321\203\320\261.", nullptr));
        label_38->setText(QCoreApplication::translate("DepositView", "\320\241\321\203\320\274\320\274\320\260 \320\272 \320\272\320\276\320\275\321\206\321\203 \321\201\321\200\320\276\320\272\320\260", nullptr));
        depositResultAccum->setText(QString());
        label_34->setText(QCoreApplication::translate("DepositView", "\321\200\321\203\320\261.", nullptr));
        depositResultFinalSum->setText(QString());
        label_40->setText(QCoreApplication::translate("DepositView", "\321\200\321\203\320\261.", nullptr));
        label_42->setText(QCoreApplication::translate("DepositView", "\320\241\321\203\320\274\320\274\320\260 \320\275\320\260\320\273\320\276\320\263\320\260", nullptr));
        label_41->setText(QCoreApplication::translate("DepositView", "\320\235\320\260\321\207\320\270\321\201\320\273\320\265\320\275\320\275\321\213\320\265 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\321\213", nullptr));
        depositResultTax->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DepositView: public Ui_DepositView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSITVIEW_H
