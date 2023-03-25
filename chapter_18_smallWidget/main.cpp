#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  //自定义控件的封装
  //在主widget中添加widget，选中widget使用右键，提升为，
  //提升的类名称填smallwidget

  QApplication a(argc, argv);
  Widget w;
  w.show();
  return a.exec();
}
