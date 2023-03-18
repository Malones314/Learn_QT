#include "mainwindow.h"

#include <QApplication>
#include <QCoreApplication>

int main(int argc, char *argv[]) {

  //常用算法和Cpp差不多
  //qAbs
  //qMax
  //qRound(b);  返回与一个浮点数最接近的整数值，四舍五入返回一个整数
  //qSwap
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
