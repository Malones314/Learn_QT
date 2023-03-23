#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::Widget)
{
  ui->setupUi(this);

  //tableWidget的使用

  //1 设置列数
  ui->tableWidget->setColumnCount(3);

  //2 设置水平表头标签
  ui->tableWidget->setHorizontalHeaderLabels(
        QStringList() << "姓名" << "性别" << "年龄" );
  //3 设置行数
  ui->tableWidget->setRowCount(2);

  //设置行列中的Item
  ui->tableWidget->setItem( 0, 0, new QTableWidgetItem("zrc"));
  ui->tableWidget->setItem( 0, 1, new QTableWidgetItem("男"));
  ui->tableWidget->setItem( 0, 2, new QTableWidgetItem("22"));

  ui->tableWidget->setItem( 1, 0, new QTableWidgetItem("zrc"));
  ui->tableWidget->setItem( 1, 1, new QTableWidgetItem("男"));
  ui->tableWidget->setItem( 1, 2, new QTableWidgetItem("22"));

}

Widget::~Widget()
{
  delete ui;
}

