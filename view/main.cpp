#include <QApplication>
#include <QFont>
#include <QFontDatabase>
#include <QLocale>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  QLocale::setDefault(QLocale::c());
  QFontDatabase::addApplicationFont(":/front/fronts/Quicksand-Bold.ttf");
  QFontDatabase::addApplicationFont(":/front/fronts/Quicksand-Medium.ttf");
  QFontDatabase::addApplicationFont(":/front/fronts/Quicksand-Regular.ttf");
  MainWindow w;
  w.show();
  return a.exec();
}
