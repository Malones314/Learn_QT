#include "mainwindow.h"

#include <QApplication>

#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QMainWindow>
#include <QStatusBar>
#include <QDebug>

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

////QLineEdit实例：

//int main(int argc, char *argv[]){
//    QApplication app(argc, argv);

//    QWidget window;

//    QVBoxLayout *layout = new QVBoxLayout(&window); // 创建布局管理器对象，为window的子对象
          //确定子控件的位置：使用QVBoxLayout可以很方便地确定子控件的位置和大小，以便在窗口中正确地布局子控件。
          //动态调整布局：当添加、删除或者调整子控件的大小时，QVBoxLayout会自动调整窗口中子控件的位置，以保持窗口布局的整洁。
          //支持嵌套布局：QVBoxLayout可以与其他布局管理器结合使用，实现复杂的窗口布局，从而实现灵活的窗口设计。
          //自动调整大小：当子控件大小发生变化时，QVBoxLayout会自动调整窗口大小，以保持窗口布局的整洁。

//    QLineEdit *lineEdit = new QLineEdit(&window); // 创建单行文本框对象，为window的子对象

//    layout->addWidget(lineEdit);  // 将单行文本框对象添加到布局管理器中

//    window.setLayout(layout); // 设置窗口对象的布局管理器为上面创建的布局管理器

//    window.setWindowTitle("QLineEdit Example"); // 设置窗口标题
//    window.show();

//    return app.exec();
//}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////QPlainTextEdit实例：

//int main( int argc, char* argv[]){
//  QApplication app( argc, argv);

//  QPlainTextEdit textEdit;
//  textEdit.setPlainText("This is a sample text.\nhello\nhello");  // 设置文本内容

//  textEdit.show();

//  return app.exec();
//}

////QPlainTextEdit和QLineEdit的区别

//1. 输入内容的类型不同： QLineEdit 只能输入单行文本，而 QPlainTextEdit 可以输入多行文本。
//2. 大小和外观不同： QLineEdit 通常比 QPlainTextEdit 更小，只能显示一行文本，
//   而 QPlainTextEdit 更大，可以显示多行文本。此外，它们的外观也不同：QLineEdit 通常只有一条线作为边框，而 QPlainTextEdit 通常具有多行边框和滚动条。
//3. 支持的操作不同： QLineEdit 支持一些基本操作，如剪切、复制、粘贴等，而 QPlainTextEdit 支持更多的操作，如查找、替换、插入图片等。
//4. 性能不同： 由于 QPlainTextEdit 可以显示大量的文本，因此在处理大量文本时，QPlainTextEdit 的性能可能会比 QLineEdit 更好。
//如果需要输入单行文本，可以使用 QLineEdit，如果需要输入多行文本，可以使用 QPlainTextEdit


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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
