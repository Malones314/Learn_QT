#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);  //必须放在最上面,所有控件都要在ui中找
  //ui->actionopen->setIcon(QIcon("C:\\Users\\Malones\\Pictures\\Camera Roll\\p1.jpg"));//或者把路径中的//改成'\ '
  //导入资源
  //1. 将资源放入项目下
  //2. 添加资源文件
  //2.1 右键项目->添加新文件->Qt->Qt Resource file->给资源文件起名 eg:photo 生产photo.qrc文件
  //3 编辑资源文件
  //3.1 添加前缀
  //3.2 添加文件
  //4 使用资源
  //4.1 语法： “ : + 前缀名 + 文件名 ”

  ui->actionopen->setIcon(QIcon(":/witcher3.png"));

}

MainWindow::~MainWindow()
{
  delete ui;
}

