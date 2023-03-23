#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::Widget)
{
  ui->setupUi(this);

  //ListWidget使用
  //一行行添加文本并单独设置文本属性
//  QListWidgetItem * item = new QListWidgetItem("hello");
//  ui->listWidget->addItem( item);
//  //设置文本对齐方式
//  item->setTextAlignment( Qt::AlignHCenter | Qt::AlignVCenter); //水平居中和垂直居中
  //设置多行文本
  //不能设置对齐方式，只能左对齐
  QStringList qsList;
  qsList << "hello1" << "hello2" << "hello3";
  ui->listWidget->addItems( qsList);

}

Widget::~Widget()
{
  delete ui;
}

