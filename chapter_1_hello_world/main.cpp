#include<QApplication>
#include<QLabel>
int main( int argc, char* argv[]){
  //GUI程序创建QApplication对象实例
  //对于非GUI程序是创建QCoreApplication对象实例
  QApplication app( argc, argv);  //用于管理QT程序的生命周期，开启事件循环

  QLabel label(" Hello world"); //创建Qlabel对象实例,赋值Hello world
                                //在label上显示文本
  label.show(); //显示label内容

  return app.exec();  //开启事件循环
}
