#include "widget.h"
#include "ui_widget.h"
#include <QTreeWidget>
#include <QTreeWidgetItem>
Widget::Widget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::Widget)
{
  ui->setupUi(this);
  //QTreeWidget 树控件
  //1. 设置头标签
  ui->treeWidget->setHeaderLabels(QStringList() << "学科" << "分数" );
  //2. Item创建
  QTreeWidgetItem* sciences = new QTreeWidgetItem( QStringList() << "理科" );
  //2.1 添加顶层级别的Item
  ui->treeWidget->addTopLevelItem( sciences);

  QTreeWidgetItem* liberalArts = new QTreeWidgetItem( QStringList() << "文科" );
  ui->treeWidget->addTopLevelItem( liberalArts);

  QTreeWidgetItem* physics = new QTreeWidgetItem( QStringList() << "物理" << "110");
  QTreeWidgetItem* chemistry = new QTreeWidgetItem( QStringList() << "化学" << "100");
  QTreeWidgetItem* biology = new QTreeWidgetItem( QStringList() << "生物" << "90");
  QTreeWidgetItem* politics = new QTreeWidgetItem( QStringList() << "政治" << "100");
  QTreeWidgetItem* history = new QTreeWidgetItem( QStringList() << "历史" << "100");
  QTreeWidgetItem* geography = new QTreeWidgetItem( QStringList() << "地理" << "100");

  //2.1 挂到顶层的Item中
  sciences->addChild(physics);
  sciences->addChild(chemistry);
  sciences->addChild(biology);
  liberalArts->addChild(politics);
  liberalArts->addChild(history);
  liberalArts->addChild(geography);

}

Widget::~Widget()
{
  delete ui;
}

