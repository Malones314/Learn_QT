#include "mainwindow.h"
#include "mywidget.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MyWidget w;
  //setGeometry() 函数是 QWidget 类的成员函数，用于设置窗口部件的位置和大小。
  //它的参数是四个整数值，依次表示 x 坐标、y 坐标、宽度和高度。这些参数是相对于父窗口部件的坐标。
  //使用 setGeometry() 函数可以在创建窗口部件之后更改其位置和大小，或者在创建窗口部件时立即设置其位置和大小。
  //如果使用布局管理器来管理窗口部件的位置和大小，则通常不需要手动调用 setGeometry() 函数。布局管理器会自动根
  // 据其规则和父窗口部件的大小和位置来设置子部件的大小和位置。
  w.setGeometry( 100, 100, 200, 120);
      //左上角为(0,0)点，从左往右为x轴增大方向，从上往下为y轴增大方向
  w.show();
  return a.exec();
}
