#include "mainwindow.h"
#include <QDebug>
#include <QVariant>
#include <QColor>
#include <QApplication>
#include <QMetaType>

//类似于Cpp的联合(union)数据类型，能存放Qt类型值：Qcolor、QFont等，也能存放Qt的容器类型的值的一个类
//为开发者提供了一种方便的方式来储存和处理各种类型的数据

int main(int argc, char *argv[]){
  QVariant vi( 100);  //声明一个QVariant变量，初始化为一个整数
  qDebug()<<vi.toInt(); //将QVariant变量转化为整数并输出
  QVariant vs( "how are you");
  qDebug() << vs.toString();
  QMap<QString, QVariant> map;  //声明
  map["int"] = 100;
  map["double"] = 21.5;
  qDebug()<<map["int"].toInt();

  //QVariant::type() 得到QVariant的type
  qDebug()<<vs.type();  //QVariant::QString

  ///////////////////////////////////////////////////////////////////////////////////////////
  //QVariant::Type type = vs.type();
  //map[type] = 12; error,如果要实现这个功能要使用QMetaType
    //该函数可以用于调试、序列化、反序列化等场景中，帮助您了解对象的类型信息。
    //需要注意的是，该函数只能返回已注册的类型名称。因此，如果您使用了自定义类型，您需要确保在使用该类型之前先使用 Q_DECLARE_METATYPE() 宏进行注册。
    /**
     * struct MyClass{
     * //.....
     * };
     * Q_DECLARE_METATYPE(MyClass)
     **/
  const char* typeName = QMetaType::typeName( vs.type());   //得到
  qDebug()<< typeName;
  map[typeName] = 10;
  ///////////////////////////////////////////////////////////////////////////////////////////

  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
