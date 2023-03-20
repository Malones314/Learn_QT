#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets>

#include <QLabel>
#include <QTextBrowser>
#include <QGraphicsView>
#include <QCalendarWidget>
#include <QLCDNumber>
#include <QProgressBar>
#include <QFrame>
#include <QOpenGLWidget>
//QLabel:标签
//QTextBrowser：文本浏览器，支持超链接和图像
//QGraphicsView提供图形视图框架，后面讲解
//QCalendarWidget：日历
//QFrame：创建一个具有框架的窗口小部件，用于为其他小部件提供框架或背景，并且可以设置不同的框架样式和边框样式。

////QTextBrowser
//int main(int argc, char *argv[]) {
//    QApplication app(argc, argv);

//    QTextBrowser textBrowser;
//    textBrowser.setPlainText("This is some sample text.");

//    textBrowser.show();

//    return app.exec();
//}

////////////////////////////////////////////////////////////////////////////////////////////////

////日历
//int main(int argc, char *argv[]) {
//    QApplication app(argc, argv);

//    QCalendarWidget *calendar = new QCalendarWidget();
//    calendar->setGridVisible(true);

//    calendar->show();

//    return app.exec();
//}

////////////////////////////////////////////////////////////////////////////////////////////////

////LCD Number

//int main(int argc, char *argv[]) {
//    QApplication app(argc, argv);

//    QLCDNumber *lcd = new QLCDNumber();
//    lcd->setDigitCount(10); //设置显示的数字数量
//    lcd->display(12345);  //设置显示的数字为 12345

//    lcd->show();

//    return app.exec();
//}

////QProgressBar
//int main( int argc, char *argv[]) {
//  QApplication app( argc, argv);

//  QWidget window;

//  QProgressBar* progress_bar = new QProgressBar;
//  progress_bar->setRange( 0, 100);  // 设置进度条范围，最小值0，最大值100

//  QPushButton button("start");  // 创建按钮对象，文本为“start”

//   // 连接按钮的clicked信号与lambda表达式
//  QObject::connect( &button, &QPushButton::clicked, [&](){
//      // 每隔100毫秒增加进度条的值
//      for (int i = 0; i <= 100; ++i) {
//          progress_bar->setValue(i);  // 设置进度条的值
//          QCoreApplication::processEvents();  // 处理Qt事件队列,让程序
//                      //处理那些还没有处理的事件，然后再把使用权返回给调用者
//          QThread::msleep(100); // 线程休眠100毫秒
//      }
//    });

//  QVBoxLayout layout( &window); // 创建垂直布局对象
//  layout.addWidget( &button); // 将按钮添加到垂直布局中
//  layout.addWidget( progress_bar);  // 将进度条添加到垂直布局中
//  window.show();

//  return app.exec();
//}

////////////////////////////////////////////////////////////////////////////////////////////////

///QFrame

//setFrameStyle()用于设置框架的样式，setLineWidth()用于设置边框的宽度，setMidLineWidth()用于
//设置中线的宽度等等。此外，QFrame还提供了一些方便的函数，例如setStyleSheet()用于设置QSS样式表，
//setAutoFillBackground()用于设置是否自动填充背景颜色等。

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // 创建一个窗口
    QWidget window;
    window.setWindowTitle("QFrame Example");

    // 创建一个QFrame，并设置边框样式和背景颜色
    QFrame frame(&window);
    frame.setFrameStyle(QFrame::Box | QFrame::Raised);  //用于设置框架的样式
      //QFrame::Box表示要显示一个带边框的方框，即显示一个完整的边框。
      //QFrame::Raised表示将框架边框凸起以突出框架的外观。
      //通过将这两个常量用按位或（|）运算符组合在一起，可以将它们的值合并到一个整数中，用于设置QFrame的边框样式。
    frame.setStyleSheet("background-color: yellow;");
    frame.setGeometry(50, 50, 200, 100);  //设置frame位置

    // 将QFrame添加到窗口中并显示
    window.show();
    return app.exec();
}
