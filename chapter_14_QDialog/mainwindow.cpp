#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  //点击新建，弹出对话框
  connect( ui->actionnew, &QAction::triggered,[=](){  //triggered:类似于clicked
    //对话框的种类
    //模块化对话框    弹出后不可以对别的窗口操作
    //非模块化对话框  弹出后可以操作别的窗口

    //创建模态对话框
    //      QDialog* dia = new QDialog(this);
    //      dia->setWindowTitle("对话框");
    //      dia->resize( 220,100);
    //      dia->exec();

    //创建非模态对话框
    //      QDialog* dia = new QDialog(this);
    //      dia->setWindowTitle("对话框");
    //      dia->resize( 220,100);
    //      dia->show();
    //      dia->setAttribute(Qt::WA_DeleteOnClose);  //关闭窗口时释放资源，防止堆区溢出

    //QMessageBox 消息对话框
    //错误提示
    //QMessageBox::critical(this, "title错误", "错误！"); //参数：父类，标题，中间文本

    //信息提示
    //QMessageBox::information(this, "title信息", "信息提示");

    //询问提示
    //QMessageBox::question(QWidget *parent, const QString &title, const QString &text,   //父类、标题、中间文本
    //QMessageBox::StandardButtons buttons = StandardButtons(Yes | No), //按钮
    //QMessageBox::StandardButton defaultButton = NoButton)   //默认关联回车的按钮
    //返回值为StandardButtons，可以使用if来写条件判断逻辑
    //      QMessageBox::StandardButtons button = QMessageBox::question( this, "title询问", "询问提示",
    //                                                                   QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel);
    //      if( button == QMessageBox::Cancel){
    //          qDebug() << "选择的是取消";
    //      } else {
    //          qDebug() << "选择的是保存";
    //      }

    //警告提示
    //    QMessageBox::warning( this, "title警告", "警告");

    //颜色对话框
//    QColor color = QColorDialog::getColor( QColor(0,0,255));
//    qDebug() << color.red() << color.green() << color.blue();

    //字体对话框
//    bool ok;
//    QFont font = QFontDialog::getFont( &ok, QFont("宋体", 36));
//    qDebug() << "字体：" << font.family() << "字号：" << font.pointSize()
//             << "加粗：" << font.bold() << "倾斜：" << font.italic();

    //文件对话框
    QString str = QFileDialog::getOpenFileName(
          this,   //父窗口
          "打开文件",   //标题
          "E:/MyCandCPPSpace/QtCode/charpter_14/charpter_14_QDialog", //默认路径
          "*.cpp *.h" //文件类型 过滤条件
          );
    qDebug() << str;

    }); //end of connect
}

MainWindow::~MainWindow()
{
  delete ui;
}

