#include "mainwindow.h"

#include <QApplication>
#include <QCoreApplication>
#include <QLabel>
#include <QLineEdit>

#include <QSpacerItem>
#include <QLayout>
#include <QtContainerFwd>
#include <QPushButton>

//QSpacerItem: 允许您在布局管理器中添加一个空间（spacer），它可以自动调整其大小以填充布局中的可用空间。
  //水平（horizontal）spacer和垂直（vertical）spacer
//QLayout 布局管理系统
  //Vertical Layout、Horizontal Layout、 Grid Layout(网格布局)、Form Layout(表单布局)
//QtContainerFwd：容器组
  //Group Box：组框
  //Scroll Area：滚动区域
  //Tool Box：工具箱
  //Tab Widget：标签部件
  //Stacked Widget：堆叠部件
  //Frame：帧
  //Widget：小部件
  //MDI Area：MDI区域
  //Dock Widget：停靠窗体部件
  //QAxWidget：封装Flash的ActiveX控件
//Widget是所有Qt GUI界面类的基类，能接受鼠标、键盘及其他窗口时间，并在显示器上绘制自己
//对于传入QWidget构造函数的参数（或者嗲用QWidget::setWindowFlags()和QWidget::setParent()
//函数）可以指定一个窗口部件的窗口标识（window flags）和父窗口
//窗口部件的窗口标识定义了窗口部件的窗口类型和窗口提示（hint）
//窗口类型制定了窗口部件的窗口系统属性，一个窗口部件只有一个窗口类型
//窗口提示定义了顶层的窗口外观，一个窗口可以有多个提示（提示可以进行按位或操作）

//int main( int argc, char* argv[]){
//  QApplication app(argc, argv);
//  QWidget window;
//  window.resize( 320, 240);
//  window.show();
//  QPushButton* button = new QPushButton( QObject::tr("press this"), &window);
//    // 创建一个QPushButton对象，文本为"press this"，并将其附加到QWidget窗口
//  button->move( 200, 100);   // 设置QPushButton按钮的位置为(200, 100)像素
//  button->show();

//  return app.exec();
//}

int main( int argc, char* argv[]){
  QApplication app( argc, argv);
  QWidget window;
  QLabel *label = new QLabel( QObject::tr("Name:"));
  QLineEdit* lineEdit = new QLineEdit();
  QHBoxLayout* layout = new QHBoxLayout();
  layout->addWidget( label);
  layout->addWidget(lineEdit);
  window.setLayout( layout);
  window.show();

  return app.exec();
}
