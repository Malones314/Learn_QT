#include "mywidget.h"
#include <QApplication>
#include <QPushButton>
#include <QFont>

MyWidget::MyWidget( QWidget* parent) : QWidget( parent) {   //定义了 MyWidget 类的构造函数，它是 QWidget 类的子类。
                                                            //构造函数接受一个 QWidget 指针作为参数，该指针是正在创建的 MyWidget 实例的父窗口部件。
                                                            //它使用 parent 参数初始化 QWidget 基类。
  //这两行将小部件的最小和最大尺寸设置为 200 x 120 像素。
  setMinimumSize( 200, 120);
  setMaximumSize( 200, 120);

  //创建了一个名为 'quit' 的新 QPushButton 对象，它是当前窗口部件 ('this') 的子部件。按钮上显示的文本为 "Quit"。
  QPushButton* quit = new QPushButton( "Quit", this);

  //将 'quit' 按钮的位置和大小设置为一个矩形，其 x=62，y=40，宽度=75，高度=30。这些坐标是相对于窗口部件的左上角。
  quit->setGeometry( 62, 40, 75, 30);
  //将 'quit' 按钮的字体设置为粗体，并使用大小为 18 的 "Times" 字体系列。
  quit->setFont( QFont("Times", 18, QFont::Bold) );

  //将 'quit' 按钮的 clicked() 信号连接到 qApp 对象的 quit() 槽，qApp 是应用程序实例。这意味着当单击 'quit' 按钮时，应用程序将退出。
  //SIGNAL() 和 SLOT() 宏用于指定要连接的信号和槽。
  connect( quit, SIGNAL( clicked()), qApp, SLOT(quit()) );
}
MyWidget::~MyWidget(){ }
