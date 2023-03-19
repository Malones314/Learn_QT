#include "mainwindow.h"

#include <QApplication>

#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QMainWindow>
#include <QStatusBar>

//input widgets 包含如下组件
#include <QComboBox>      //QComboBox：组合框
#include <QFontComboBox>  //QFontComboBox：字体组合框
#include <QLineEdit>      //QLineEdit：行编辑框
#include <QTextEdit>      //QTextEdit：文本编辑框
#include <QPlainTextEdit> //QPlainTextEdit：纯文本编辑框
#include <QSpinBox>       //QSpinBox：数字显示框(自旋盒)
#include <QDoubleSpinBox> //QDoubleSpinBox：浮点数数字显示框(双自旋盒)
#include <QTime>          //QTime：时间编辑
#include <QDate>          //QDate：日期编辑
#include <QDateTime>      //QDateTime：时间日期编辑

////QComboBox实例：
//class MyWindow:public QMainWindow{
//public:
//  MyWindow(){
//    QComboBox* combo_box = new QComboBox();//创建可以下拉的组合框
//    combo_box->addItem("item1");  //在组合框中添加Item1
//    combo_box->addItem("item2");//在组合框中添加Item2
//    combo_box->addItem("item3"); //在组合框中添加Item3
//    setCentralWidget( combo_box); //将QComboBox实例设置为主窗口的中央部件


//    QLabel* label = new QLabel( combo_box->currentText(), this); //创建一个QLabel实例，将其文本设置为QComboBox当前选中的文本
//    //setStatusBar(label); error:cannot initialize a parameter of type 'QStatusBar *' with an lvalue of type
//    //解决办法：
//    QStatusBar* statusBarPtr = statusBar();
//    statusBarPtr->addWidget( label);  //将label设置为主窗口的状态栏
//    connect( combo_box, QOverload<const QString&>::of( &QComboBox::currentTextChanged),
//                        //QOverload是一个模板类，用于解决C++中的函数重载（overload）问题。QOverload<>::of函数模板可以用于指定函数重载的具体函数。
//                        //可以用于绑定信号和槽函数。其模板参数为函数指针类型，表示将要绑定的槽函数。
//                        //QOverload的返回值是一个函数指针，指向与给定函数指针类型匹配的函数。Qt5中，由于Qt信号和槽机制的改进，
//                        //需要使用QOverload类来重载信号槽函数。
//                          //QOverload<const QString&>::of( &QComboBox::currentTextChanged)
//                          //表示获取QComboBox的currentTextChanged信号的重载版本，该信号的参数为一个const QString&类型的引用。
//    [=]( const QString& text){
//      label->setText( text);     //QLabel::setText()函数是一个用于设置QLabel对象文本内容的函数。
//                                 //它的作用是将指定的文本设置为QLabel对象的文本，并在标签上显示该文本。
//    } );     // 将QComboBox的currentTextChanged信号连接到一个lambda槽中，该槽将更新标签的文本以显示当前选择的选项的名称

//  }
//};
//int main( int argc, char* argv[]){
//  QApplication app( argc, argv);
//  MyWindow w;
//  w.show();

//  return app.exec();
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////QFontComboBox实例：
//int main(int argc, char *argv[]) {
//    QApplication app(argc, argv);

//    QWidget *window = new QWidget;
//    window->setWindowTitle("QFontComboBox Example");  //设置窗口标题

//    QFontComboBox *fontCombo = new QFontComboBox(window); //构造QFontComboBox对象，为window的子对象
//                         //QFontComboBox(QWidget *parent = nullptr);为函数声明，
//                         //如果指定了parent参数，那么QFontComboBox控件将成为parent对象的子控件，从而继承了parent对象的属性和行为，
//                         //并且可以响应parent对象的信号和槽函数，以及处理parent对象的鼠标、键盘等事件。
//                         //如果未指定parent参数，那么QFontComboBox控件将是一个独立的窗口，不会与任何其他控件相关联。
//    QVBoxLayout *layout = new QVBoxLayout(window);  //创建一个垂直布局管理器，为window的子对象
//    layout->addWidget(fontCombo);

//    window->show();

//    return app.exec();
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////QSpinBox实例：
//int main(int argc, char *argv[]) {
//    QApplication app(argc, argv);
//    QWidget w;    // 创建一个QWidget窗口对象
//    QHBoxLayout h_layout;  // 创建一个水平布局管理器
//    QSpinBox s; // 创建一个QSpinBox自旋框控件

//    // 设置自旋框范围和步进值
//    s.setRange( 0, 100);
//    s.setSingleStep(1);

//    h_layout.addWidget( &s); // 把自旋框控件添加到水平布局管理器中
//    w.setLayout( &h_layout);  // 把水平布局管理器设置为QWidget窗口对象的布局管理器
//    w.show(); // 显示QWidget窗口对象

//    return app.exec();
//}

//int main(int argc, char *argv[]) {
//}
