#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QWidget>

class MyWidget : public QWidget {
  Q_OBJECT  //宏定义，用于在Qt中声明一个类，使其能够支持Qt的信号与槽（Signals and Slots）机制。
            //使用Q_OBJECT宏定义可以让一个类支持信号与槽机制，同时也可以使这个类支持其他Qt特性
            //Q_OBJECT宏定义会在类声明的私有部分中自动添加一些额外的代码，这些代码包括信号和槽的声明、元对象信息的注册等等。
            //如果一个类中使用了Q_OBJECT宏定义，那么这个类需要在使用Qt的moc编译器进行编译之后才能正常使用，因为moc编译器会
            //根据Q_OBJECT宏定义生成一些额外的代码。

public:
  MyWidget( QWidget* parent = 0 );
  ~MyWidget();
};

#endif // MYWIDGET_H
