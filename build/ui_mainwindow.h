/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *Calc;
    QPushButton *pushButton_9;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_0;
    QPushButton *pushButton_point;
    QPushButton *pushButton_equal;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_multy;
    QPushButton *pushButton_div;
    QPushButton *pushButton_plus_minus;
    QPushButton *pushButton_AC;
    QPushButton *pushButton_mod;
    QLabel *result;
    QPushButton *pushButton_right_bracket;
    QPushButton *pushButton_left_bracket;
    QPushButton *pushButton_pow;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_log;
    QPushButton *pushButton_x;
    QLabel *xxx;
    QLineEdit *lineEdit_x;
    QFrame *frame_2;
    QCustomPlot *graph;
    QLineEdit *Xmax;
    QLineEdit *Xmin;
    QLineEdit *Ymax;
    QLineEdit *Ymin;
    QPushButton *pushButton_credit;
    QPushButton *pushButton_deposit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(983, 450);
        QFont font;
        font.setFamilies({QString::fromUtf8("Quicksand")});
        font.setPointSize(15);
        font.setBold(false);
        font.setItalic(false);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../Icon/calc.icns"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("font: 15pt \"Quicksand\";"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setFont(font);
        Calc = new QFrame(centralwidget);
        Calc->setObjectName("Calc");
        Calc->setGeometry(QRect(0, 0, 511, 451));
        Calc->setFont(font);
        Calc->setStyleSheet(QString::fromUtf8(" background-color: rgb(0, 0, 0);"));
        Calc->setFrameShape(QFrame::StyledPanel);
        Calc->setFrameShadow(QFrame::Raised);
        pushButton_9 = new QPushButton(Calc);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(370, 160, 61, 61));
        pushButton_9->setFont(font);
        pushButton_9->setMouseTracking(false);
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   \n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: rgb(66, 66, 66)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_8 = new QPushButton(Calc);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(300, 160, 61, 61));
        pushButton_8->setFont(font);
        pushButton_8->setMouseTracking(false);
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   \n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: rgb(66, 66, 66)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_7 = new QPushButton(Calc);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(230, 160, 61, 61));
        pushButton_7->setFont(font);
        pushButton_7->setMouseTracking(false);
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   \n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: rgb(66, 66, 66)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_6 = new QPushButton(Calc);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(370, 230, 61, 61));
        pushButton_6->setFont(font);
        pushButton_6->setMouseTracking(false);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   \n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: rgb(66, 66, 66)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_4 = new QPushButton(Calc);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(230, 230, 61, 61));
        pushButton_4->setFont(font);
        pushButton_4->setMouseTracking(false);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   \n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: rgb(66, 66, 66)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_5 = new QPushButton(Calc);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(300, 230, 61, 61));
        pushButton_5->setFont(font);
        pushButton_5->setMouseTracking(false);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   \n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: rgb(66, 66, 66)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_3 = new QPushButton(Calc);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(370, 300, 61, 61));
        pushButton_3->setMouseTracking(false);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   \n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: rgb(66, 66, 66)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_1 = new QPushButton(Calc);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setGeometry(QRect(230, 300, 61, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Quicksand")});
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setKerning(true);
        pushButton_1->setFont(font1);
        pushButton_1->setMouseTracking(false);
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   \n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: rgb(66, 66, 66)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_2 = new QPushButton(Calc);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(300, 300, 61, 61));
        pushButton_2->setFont(font);
        pushButton_2->setMouseTracking(false);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   \n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: rgb(66, 66, 66)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_0 = new QPushButton(Calc);
        pushButton_0->setObjectName("pushButton_0");
        pushButton_0->setGeometry(QRect(230, 370, 131, 61));
        pushButton_0->setFont(font);
        pushButton_0->setMouseTracking(false);
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   \n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: rgb(66, 66, 66)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_point = new QPushButton(Calc);
        pushButton_point->setObjectName("pushButton_point");
        pushButton_point->setGeometry(QRect(370, 370, 61, 61));
        pushButton_point->setFont(font);
        pushButton_point->setMouseTracking(false);
        pushButton_point->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   \n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: rgb(66, 66, 66)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_equal = new QPushButton(Calc);
        pushButton_equal->setObjectName("pushButton_equal");
        pushButton_equal->setGeometry(QRect(440, 370, 61, 61));
        pushButton_equal->setFont(font1);
        pushButton_equal->setMouseTracking(false);
        pushButton_equal->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"\n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_plus = new QPushButton(Calc);
        pushButton_plus->setObjectName("pushButton_plus");
        pushButton_plus->setGeometry(QRect(440, 300, 61, 61));
        pushButton_plus->setFont(font);
        pushButton_plus->setMouseTracking(false);
        pushButton_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"\n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_minus = new QPushButton(Calc);
        pushButton_minus->setObjectName("pushButton_minus");
        pushButton_minus->setGeometry(QRect(440, 230, 61, 61));
        pushButton_minus->setFont(font);
        pushButton_minus->setMouseTracking(false);
        pushButton_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"\n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_multy = new QPushButton(Calc);
        pushButton_multy->setObjectName("pushButton_multy");
        pushButton_multy->setGeometry(QRect(440, 160, 61, 61));
        pushButton_multy->setFont(font1);
        pushButton_multy->setMouseTracking(false);
        pushButton_multy->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"\n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_div = new QPushButton(Calc);
        pushButton_div->setObjectName("pushButton_div");
        pushButton_div->setGeometry(QRect(440, 90, 61, 61));
        pushButton_div->setFont(font);
        pushButton_div->setMouseTracking(false);
        pushButton_div->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"\n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_plus_minus = new QPushButton(Calc);
        pushButton_plus_minus->setObjectName("pushButton_plus_minus");
        pushButton_plus_minus->setGeometry(QRect(300, 90, 61, 61));
        pushButton_plus_minus->setFont(font1);
        pushButton_plus_minus->setMouseTracking(false);
        pushButton_plus_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   \n"
"   color: black;\n"
"   border-radius: 30px;\n"
"   background-color: rgb(214, 214, 214)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_AC = new QPushButton(Calc);
        pushButton_AC->setObjectName("pushButton_AC");
        pushButton_AC->setGeometry(QRect(230, 90, 61, 61));
        pushButton_AC->setFont(font1);
        pushButton_AC->setMouseTracking(false);
        pushButton_AC->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   \n"
"   color: black;\n"
"   border-radius: 30px;\n"
"   background-color: rgb(214, 214, 214)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_mod = new QPushButton(Calc);
        pushButton_mod->setObjectName("pushButton_mod");
        pushButton_mod->setGeometry(QRect(370, 90, 61, 61));
        pushButton_mod->setFont(font1);
        pushButton_mod->setMouseTracking(false);
        pushButton_mod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   \n"
"   color: black;\n"
"   border-radius: 30px;\n"
"   background-color: rgb(214, 214, 214)\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        result = new QLabel(Calc);
        result->setObjectName("result");
        result->setGeometry(QRect(40, 20, 441, 61));
        result->setFont(font);
        result->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"color: white;\n"
"}\n"
"\n"
""));
        pushButton_right_bracket = new QPushButton(Calc);
        pushButton_right_bracket->setObjectName("pushButton_right_bracket");
        pushButton_right_bracket->setGeometry(QRect(160, 90, 61, 61));
        pushButton_right_bracket->setFont(font1);
        pushButton_right_bracket->setMouseTracking(false);
        pushButton_right_bracket->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_left_bracket = new QPushButton(Calc);
        pushButton_left_bracket->setObjectName("pushButton_left_bracket");
        pushButton_left_bracket->setGeometry(QRect(90, 90, 61, 61));
        pushButton_left_bracket->setFont(font1);
        pushButton_left_bracket->setMouseTracking(false);
        pushButton_left_bracket->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_pow = new QPushButton(Calc);
        pushButton_pow->setObjectName("pushButton_pow");
        pushButton_pow->setGeometry(QRect(20, 90, 61, 61));
        pushButton_pow->setFont(font1);
        pushButton_pow->setMouseTracking(false);
        pushButton_pow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_sin = new QPushButton(Calc);
        pushButton_sin->setObjectName("pushButton_sin");
        pushButton_sin->setGeometry(QRect(20, 160, 61, 61));
        pushButton_sin->setFont(font1);
        pushButton_sin->setMouseTracking(false);
        pushButton_sin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_cos = new QPushButton(Calc);
        pushButton_cos->setObjectName("pushButton_cos");
        pushButton_cos->setGeometry(QRect(90, 160, 61, 61));
        pushButton_cos->setFont(font1);
        pushButton_cos->setMouseTracking(false);
        pushButton_cos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_tan = new QPushButton(Calc);
        pushButton_tan->setObjectName("pushButton_tan");
        pushButton_tan->setGeometry(QRect(160, 160, 61, 61));
        pushButton_tan->setFont(font1);
        pushButton_tan->setMouseTracking(false);
        pushButton_tan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_acos = new QPushButton(Calc);
        pushButton_acos->setObjectName("pushButton_acos");
        pushButton_acos->setGeometry(QRect(90, 230, 61, 61));
        pushButton_acos->setFont(font1);
        pushButton_acos->setMouseTracking(false);
        pushButton_acos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_asin = new QPushButton(Calc);
        pushButton_asin->setObjectName("pushButton_asin");
        pushButton_asin->setGeometry(QRect(20, 230, 61, 61));
        pushButton_asin->setFont(font1);
        pushButton_asin->setMouseTracking(false);
        pushButton_asin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_atan = new QPushButton(Calc);
        pushButton_atan->setObjectName("pushButton_atan");
        pushButton_atan->setGeometry(QRect(160, 230, 61, 61));
        pushButton_atan->setFont(font1);
        pushButton_atan->setMouseTracking(false);
        pushButton_atan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_sqrt = new QPushButton(Calc);
        pushButton_sqrt->setObjectName("pushButton_sqrt");
        pushButton_sqrt->setGeometry(QRect(20, 300, 61, 61));
        pushButton_sqrt->setFont(font1);
        pushButton_sqrt->setMouseTracking(false);
        pushButton_sqrt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_ln = new QPushButton(Calc);
        pushButton_ln->setObjectName("pushButton_ln");
        pushButton_ln->setGeometry(QRect(90, 300, 61, 61));
        pushButton_ln->setFont(font1);
        pushButton_ln->setMouseTracking(false);
        pushButton_ln->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_log = new QPushButton(Calc);
        pushButton_log->setObjectName("pushButton_log");
        pushButton_log->setGeometry(QRect(160, 300, 61, 61));
        pushButton_log->setFont(font1);
        pushButton_log->setMouseTracking(false);
        pushButton_log->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_x = new QPushButton(Calc);
        pushButton_x->setObjectName("pushButton_x");
        pushButton_x->setGeometry(QRect(20, 370, 61, 61));
        pushButton_x->setFont(font);
        pushButton_x->setMouseTracking(false);
        pushButton_x->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        xxx = new QLabel(Calc);
        xxx->setObjectName("xxx");
        xxx->setGeometry(QRect(90, 380, 41, 41));
        xxx->setFont(font);
        xxx->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"color: white;\n"
"}\n"
"\n"
""));
        lineEdit_x = new QLineEdit(Calc);
        lineEdit_x->setObjectName("lineEdit_x");
        lineEdit_x->setGeometry(QRect(130, 380, 91, 41));
        lineEdit_x->setFont(font);
        lineEdit_x->setStyleSheet(QString::fromUtf8("   color: white;"));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(510, 0, 481, 451));
        frame_2->setFont(font);
        frame_2->setStyleSheet(QString::fromUtf8(" background-color: rgb(0, 0, 0);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        graph = new QCustomPlot(frame_2);
        graph->setObjectName("graph");
        graph->setGeometry(QRect(0, 0, 481, 361));
        graph->setFont(font);
        Xmax = new QLineEdit(frame_2);
        Xmax->setObjectName("Xmax");
        Xmax->setGeometry(QRect(10, 370, 61, 31));
        Xmax->setFont(font);
        Xmax->setStyleSheet(QString::fromUtf8("   color: white;"));
        Xmin = new QLineEdit(frame_2);
        Xmin->setObjectName("Xmin");
        Xmin->setGeometry(QRect(10, 410, 61, 31));
        Xmin->setFont(font);
        Xmin->setStyleSheet(QString::fromUtf8("   color: white;"));
        Ymax = new QLineEdit(frame_2);
        Ymax->setObjectName("Ymax");
        Ymax->setGeometry(QRect(80, 370, 61, 31));
        Ymax->setFont(font);
        Ymax->setStyleSheet(QString::fromUtf8("   color: white;"));
        Ymin = new QLineEdit(frame_2);
        Ymin->setObjectName("Ymin");
        Ymin->setGeometry(QRect(80, 410, 61, 31));
        Ymin->setFont(font);
        Ymin->setStyleSheet(QString::fromUtf8("   color: white;"));
        pushButton_credit = new QPushButton(frame_2);
        pushButton_credit->setObjectName("pushButton_credit");
        pushButton_credit->setGeometry(QRect(170, 380, 131, 61));
        pushButton_credit->setFont(font);
        pushButton_credit->setMouseTracking(false);
        pushButton_credit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_deposit = new QPushButton(frame_2);
        pushButton_deposit->setObjectName("pushButton_deposit");
        pushButton_deposit->setGeometry(QRect(320, 380, 131, 61));
        pushButton_deposit->setFont(font);
        pushButton_deposit->setMouseTracking(false);
        pushButton_deposit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   color: white;\n"
"   border-radius: 30px;\n"
"   background-color: #F79E02\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SmartCalc_v2.0", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_point->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_equal->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_multy->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_plus_minus->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        pushButton_AC->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        result->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_right_bracket->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_left_bracket->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_pow->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        pushButton_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        pushButton_x->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        xxx->setText(QCoreApplication::translate("MainWindow", "X = ", nullptr));
        Xmax->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        Xmax->setPlaceholderText(QCoreApplication::translate("MainWindow", " X Max", nullptr));
        Xmin->setText(QCoreApplication::translate("MainWindow", "-10", nullptr));
        Xmin->setPlaceholderText(QCoreApplication::translate("MainWindow", " X Min", nullptr));
        Ymax->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        Ymax->setPlaceholderText(QCoreApplication::translate("MainWindow", " Y Max", nullptr));
        Ymin->setText(QCoreApplication::translate("MainWindow", "-10", nullptr));
        Ymin->setPlaceholderText(QCoreApplication::translate("MainWindow", " Y Min", nullptr));
        pushButton_credit->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\320\265\320\264\320\270\321\202", nullptr));
        pushButton_deposit->setText(QCoreApplication::translate("MainWindow", "\320\224\320\265\320\277\320\276\320\267\320\270\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
