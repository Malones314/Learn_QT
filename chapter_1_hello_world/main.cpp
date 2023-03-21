#include<QApplication>
#include<QLabel>
int main( int argc, char* argv[]){
  //GUI程序创建QApplication对象实例
  //对于非GUI程序是创建QCoreApplication对象实例
  QApplication app( argc, argv);  //用于管理QT程序的生命周期，开启事件循环

  //QLabel是一个非常有用的Qt窗口部件，可以用于在GUI应用程序中显示各种静态或动态文本和图像，并与其他窗口部件进行交互。

  //QLabel常用于显示文本或图像。它通常用于在GUI应用程序中显示静态文本，例如标签或标题。
  //它还可以用于显示动态文本，例如进度条或计数器的值，或用于显示图像或图标。

  //QLabel可以包含各种文本格式和属性，例如字体、颜色、对齐方式、换行和文本格式（例如HTML或富文本格式）等。
  //它还可以通过设置QPixmap、QImage或QIcon等图像属性来显示图像。

  //QLabel还可以通过单击、双击、鼠标移动等事件来触发特定的操作或与其他窗口部件进行交互。它还支持拖放操作，
  //可以将文本或图像从QLabel拖动到其他应用程序中。

  QLabel* label = new QLabel(" Hello world"); //创建Qlabel对象实例,赋值Hello world
                                //在label上显示文本
    //不用写delete，qt在一定程度上简化了内存回收
    //如果制定了父窗口为QObject或者QObject派生来的类，则对象会被放到对象树中，
    //由程序自动管理内存释放
    //当程序结束时，先从顶往下，顶部的元素先调用析构函数，但是不释放对象，看是否有儿子（如果有儿子，先释放
    //儿子），然后再释放自己
  label->show(); //显示label内容
  
  return app.exec();  //开启事件循环
}
