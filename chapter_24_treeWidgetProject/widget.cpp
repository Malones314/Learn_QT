#include "widget.h"
#include "ui_widget.h"
#include <QTreeWidgetItem>
#include <QTreeWidget>

Widget::Widget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::Widget)
{
  ui->setupUi(this);
  init();
  connect( ui->treeWidget, SIGNAL( itemChanged( QTreeWidgetItem* , int)),   //表示树形控件中某个 QTreeWidgetItem 的状态发生了变化。
                                    //当用户更改了一个树形控件项的任何属性时（例如，选中状态、文本、图标等等），该信号将被发出。
                                    //void itemChanged(QTreeWidgetItem *item, int column);
                                    //item 表示发生更改的 QTreeWidgetItem，column 表示发生更改的列号。
           this,
           SLOT( treeItemChanged( QTreeWidgetItem*, int)));
}

void Widget::init(){
  ui->treeWidget->clear();

  //分组1
  QTreeWidgetItem* group1 = new QTreeWidgetItem( ui->treeWidget);
  group1->setText(0, "group1");
  group1->setFlags( Qt::ItemIsUserCheckable   //一个枚举值，用于指示列表或树形视图中的项是否可以被用户勾选。
                            //Qt::ItemIsUserCheckable：表示项可以被用户勾选或取消勾选。
                            //Qt::ItemIsTristate：表示项可以有三种状态：选中、未选中和半选中。
                            //Qt::ItemIsAutoTristate：表示项可以有三种状态，但是在状态改变时，框架会自动判断项的状态。
                    | Qt::ItemIsEnabled       //表示该元素是否可以被用户操作
                    | Qt::ItemIsSelectable);  //表示该元素是否可以被选择
  group1->setCheckState( 0, Qt::Unchecked); //第0个子控件的选中状态为未选中状态。
  QTreeWidgetItem* subItem11 = new QTreeWidgetItem( group1);
  subItem11->setText(0, "subItem11");
  subItem11->setFlags( Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
  subItem11->setCheckState( 0, Qt::Unchecked);
  QTreeWidgetItem* subItem12 = new QTreeWidgetItem(group1);
  subItem12->setText(0, "subItem12");
  subItem12->setFlags( Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
  subItem12->setCheckState( 0, Qt::Unchecked);
  QTreeWidgetItem* subItem13 = new QTreeWidgetItem( group1);
  subItem13->setText(0, "subItem13");
  subItem13->setFlags( Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
  subItem13->setCheckState( 0, Qt::Unchecked);
  QTreeWidgetItem* subItem14 = new QTreeWidgetItem( group1);
  subItem14->setText(0, "subItem14");
  subItem14->setFlags( Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
  subItem14->setCheckState( 0, Qt::Unchecked);


  //分组2
  QTreeWidgetItem* group2 = new QTreeWidgetItem( ui->treeWidget);
  group2->setText(0, "group2");
  group2->setFlags( Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
  group2->setCheckState( 0, Qt::Unchecked);
  QTreeWidgetItem* subItem21 = new QTreeWidgetItem( group2);
  subItem21->setText(0, "subItem21");
  subItem21->setFlags( Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
  subItem21->setCheckState( 0, Qt::Unchecked);
  QTreeWidgetItem* subItem22 = new QTreeWidgetItem(group2);
  subItem22->setText(0, "subItem22");
  subItem22->setFlags( Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
  subItem22->setCheckState( 0, Qt::Unchecked);
  QTreeWidgetItem* subItem23 = new QTreeWidgetItem( group2);
  subItem23->setText(0, "subItem23");
  subItem23->setFlags( Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
  subItem23->setCheckState( 0, Qt::Unchecked);
  QTreeWidgetItem* subItem24 = new QTreeWidgetItem( group2);
  subItem24->setText(0, "subItem24");
  subItem24->setFlags( Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
  subItem24->setCheckState( 0, Qt::Unchecked);
}

void Widget::treeItemChanged( QTreeWidgetItem* item, int column){
  QString itemText = item->text(0);

  //选中时
  if( Qt::Checked == item->checkState(0)){
    QTreeWidgetItem* parent = item->parent();
    int count = item->childCount();
    if( count > 0){
      for( int i = 0; i < count; i++){
        //选中子节点
        item->child(i)->setCheckState( 0, Qt::Checked);
      }
    }else{  //子节点
      updateParentItem( item);
    }
  }else if( Qt::Unchecked == item->checkState(0)){
    int count = item->childCount();
    if( count > 0){
      for( int i = 0; i < count; i++){
        item->child(i)->setCheckState(0, Qt::Unchecked);
      }
    }else{
      updateParentItem( item);
    }
  }
}

void Widget::updateParentItem( QTreeWidgetItem* item){
  QTreeWidgetItem* parent = item->parent();
  if( parent == nullptr){
    return ;
  }

  //选中的子节点个数
  int selectCount = 0;
  int childCount = parent->childCount();
  for( int i = 0; i < childCount; i++){
    QTreeWidgetItem* childItem = parent->child(i);
    if( childItem->checkState(0) == Qt::Checked)
        selectCount++;
  }
  if( selectCount <= 0){
    //未选中
    parent->setCheckState( 0, Qt::Unchecked);
  }else if( selectCount > 0 && selectCount < childCount){
    //部分选中
    parent->setCheckState( 0, Qt::PartiallyChecked);
  }else if( selectCount == childCount){
    //选中
    parent->setCheckState( 0, Qt::Checked);
  }
}

Widget::~Widget()
{
  delete ui;
}

