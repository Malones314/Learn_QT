#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QtDebug>

Widget::Widget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::Widget)
{
  ui->setupUi(this);

  //监听 用户选中的是女
  connect( ui->rButton_woman, &QRadioButton::clicked, [&](){
    sex = woman;
  });
  connect( ui->rButton_man, &QRadioButton::clicked,[&](){
    sex = man;
  });
  connect( ui->rButton_adult,&QRadioButton::clicked,[&](){
    age = adult;
  });
  connect( ui->rButton_underage,&QRadioButton::clicked,[&](){
    age = underage;
  });
  connect( ui->sex_pushButton, &QPushButton::clicked, [=](){
    if( sex == woman)
      qDebug() << "选择女人";
    else
      qDebug() << "选择男人";
  });
  connect( ui->age_pushButton, &QPushButton::clicked, [=](){
    if( age == adult)
      qDebug() << "选择成年";
    else
      qDebug() << "选择未成年";
  });

  //复选按钮
  //监听 选项是否被选中
  //ui->checkBox_1->setTristate( true); //半选中状态
    //可能的使用场景：几个复选按钮都选中时总的按钮为全选中，当有一个或以上的复选按钮没选中时总的为半选中
  connect( ui->checkBox_1, &QCheckBox::stateChanged, [=]( int state){
    //QCheckBox::stateChanged返回一个整数，0代表未选择 1代表半选中 2代表全选中

    if( state == 2){
      qDebug() << "选中1" ;
    }
  });
  connect( ui->checkBox_2, &QCheckBox::stateChanged, [=]( int state){
    if( state == 2){
      qDebug() << "选中2" ;
    }
  });
  connect( ui->checkBox_3, &QCheckBox::stateChanged, [=]( int state){
    if( state == 2){
      qDebug() << "选中3" ;
    }
  });
  connect( ui->checkBox_4, &QCheckBox::stateChanged, [=]( int state){
    if( state == 2){
      qDebug() << "选中4" ;
    }
  });

}

Widget::~Widget()
{
  delete ui;
}

