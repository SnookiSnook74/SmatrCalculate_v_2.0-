/********************************************************************************
** Form generated from reading UI file 'creditview.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDITVIEW_H
#define UI_CREDITVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreditView
{
public:
    QTableWidget *tableWidget;
    QGroupBox *groupBox_2;
    QPushButton *pushButton;
    QLabel *label_4;
    QLineEdit *percent_credit;
    QComboBox *year_and_month;
    QLabel *label_6;
    QGroupBox *groupBox;
    QRadioButton *radioButton_aut;
    QRadioButton *radioButton_dif;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *sum_credit;
    QLineEdit *time_credit;
    QLabel *label_3;
    QLabel *label_5;
    QFrame *line;

    void setupUi(QWidget *CreditView)
    {
        if (CreditView->objectName().isEmpty())
            CreditView->setObjectName("CreditView");
        CreditView->resize(983, 450);
        QFont font;
        font.setFamilies({QString::fromUtf8("Quicksand")});
        CreditView->setFont(font);
        CreditView->setStyleSheet(QString::fromUtf8(" background-color: rgb(255, 255, 255)"));
        tableWidget = new QTableWidget(CreditView);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(440, 0, 541, 451));
        tableWidget->setFont(font);
        tableWidget->setStyleSheet(QString::fromUtf8("QHeaderView::section {\n"
"    background-color: rgb(255, 156, 58);\n"
"    color: white;\n"
"}\n"
"QTableWidget {\n"
"    background-color: rgb(0, 0, 0);\n"
"color: white;\n"
"}\n"
""));
        groupBox_2 = new QGroupBox(CreditView);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(0, 0, 441, 451));
        QFont font1;
        font1.setFamilies({QString::fromUtf8(".AppleSystemUIFont")});
        groupBox_2->setFont(font1);
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(66, 66, 66)"));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(100, 350, 221, 61));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Quicksand")});
        font2.setPointSize(16);
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   border: 0px solid gray rgb(255, 209, 0);\n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: rgb(255, 150, 17);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(120, 20, 198, 20));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Quicksand")});
        font3.setPointSize(17);
        font3.setBold(false);
        font3.setItalic(false);
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("\n"
"   color: white;\n"
""));
        percent_credit = new QLineEdit(groupBox_2);
        percent_credit->setObjectName("percent_credit");
        percent_credit->setGeometry(QRect(150, 160, 171, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8(".AppleSystemUIFont")});
        font4.setPointSize(13);
        percent_credit->setFont(font4);
        percent_credit->setStyleSheet(QString::fromUtf8("\n"
"   color: white;\n"
""));
        year_and_month = new QComboBox(groupBox_2);
        year_and_month->addItem(QString());
        year_and_month->addItem(QString());
        year_and_month->setObjectName("year_and_month");
        year_and_month->setGeometry(QRect(320, 120, 101, 31));
        year_and_month->setFont(font4);
        year_and_month->setStyleSheet(QString::fromUtf8("\n"
"   color: white;\n"
""));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(330, 160, 16, 31));
        label_6->setFont(font4);
        label_6->setStyleSheet(QString::fromUtf8("\n"
"   color: white;\n"
""));
        groupBox = new QGroupBox(groupBox_2);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 230, 291, 101));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Quicksand")});
        font5.setPointSize(15);
        font5.setBold(false);
        font5.setItalic(false);
        groupBox->setFont(font5);
        groupBox->setStyleSheet(QString::fromUtf8("\n"
"   color: white;\n"
""));
        radioButton_aut = new QRadioButton(groupBox);
        radioButton_aut->setObjectName("radioButton_aut");
        radioButton_aut->setGeometry(QRect(10, 30, 121, 21));
        radioButton_aut->setStyleSheet(QString::fromUtf8("\n"
"   color: white;\n"
""));
        radioButton_dif = new QRadioButton(groupBox);
        radioButton_dif->setObjectName("radioButton_dif");
        radioButton_dif->setGeometry(QRect(10, 60, 181, 20));
        radioButton_dif->setStyleSheet(QString::fromUtf8("\n"
"   color: white;\n"
""));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(330, 70, 16, 31));
        label_2->setFont(font4);
        label_2->setStyleSheet(QString::fromUtf8("\n"
"   color: white;\n"
""));
        label = new QLabel(groupBox_2);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 70, 131, 51));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("\n"
"   color: white;\n"
""));
        sum_credit = new QLineEdit(groupBox_2);
        sum_credit->setObjectName("sum_credit");
        sum_credit->setGeometry(QRect(150, 80, 171, 31));
        sum_credit->setFont(font4);
        sum_credit->setStyleSheet(QString::fromUtf8("\n"
"   color: white;\n"
""));
        sum_credit->setInputMethodHints(Qt::ImhNone);
        time_credit = new QLineEdit(groupBox_2);
        time_credit->setObjectName("time_credit");
        time_credit->setGeometry(QRect(150, 120, 171, 31));
        time_credit->setFont(font4);
        time_credit->setStyleSheet(QString::fromUtf8("\n"
"   color: white;\n"
""));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 120, 121, 31));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("\n"
"   color: white;\n"
""));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 150, 121, 51));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("\n"
"   color: white;\n"
""));
        line = new QFrame(groupBox_2);
        line->setObjectName("line");
        line->setGeometry(QRect(421, 0, 31, 451));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        retranslateUi(CreditView);

        QMetaObject::connectSlotsByName(CreditView);
    } // setupUi

    void retranslateUi(QWidget *CreditView)
    {
        CreditView->setWindowTitle(QCoreApplication::translate("CreditView", "Credit", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("CreditView", "\320\234\320\265\321\201\321\217\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("CreditView", "\320\241\321\203\320\274\320\274\320\260 \320\277\320\273\320\260\321\202\320\265\320\266\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("CreditView", "\320\237\320\273\320\260\321\202\320\265\320\266 \320\277\320\276 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\260\320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("CreditView", "\320\237\320\276 \320\276\321\201\320\275\320\276\320\262\320\275\320\276\320\274\321\203 \320\264\320\276\320\273\320\263\321\203", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("CreditView", "\320\236\321\201\321\202\320\260\321\202\320\276\320\272 \320\264\320\276\320\273\320\263\320\260", nullptr));
        groupBox_2->setTitle(QString());
        pushButton->setText(QCoreApplication::translate("CreditView", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("CreditView", "\320\232\321\200\320\265\320\264\320\270\321\202\320\275\321\213\320\271 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        percent_credit->setInputMask(QString());
        year_and_month->setItemText(0, QCoreApplication::translate("CreditView", "\320\234\320\265\321\201\321\217\321\206\320\265\320\262", nullptr));
        year_and_month->setItemText(1, QCoreApplication::translate("CreditView", "\320\233\320\265\321\202", nullptr));

        label_6->setText(QCoreApplication::translate("CreditView", "%", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CreditView", "\320\242\320\270\320\277 \320\265\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\321\205 \320\277\320\273\320\260\321\202\320\265\320\266\320\265\320\271", nullptr));
        radioButton_aut->setText(QCoreApplication::translate("CreditView", "\320\220\320\275\320\275\321\203\320\270\321\202\320\265\321\202\320\275\321\213\320\265", nullptr));
        radioButton_dif->setText(QCoreApplication::translate("CreditView", "\320\224\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\265", nullptr));
        label_2->setText(QCoreApplication::translate("CreditView", "\321\200", nullptr));
        label->setText(QCoreApplication::translate("CreditView", "\320\241\321\203\320\274\320\274\320\260 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        sum_credit->setInputMask(QString());
        time_credit->setInputMask(QString());
        label_3->setText(QCoreApplication::translate("CreditView", "\320\241\321\200\320\276\320\272 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("CreditView", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreditView: public Ui_CreditView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDITVIEW_H
