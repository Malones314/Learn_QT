#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QString>
#include <QTimerEvent>
#include <QTimer>

Widget::Widget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::Widget)
{
  ui->setupUi(this);

  //启动定时器
  timeId1 = startTimer(1000); //每隔一秒启动一次
  timeId2 = startTimer(2000);

  //定时器类   常用这种方式而非定时器事件
  QTimer* timer = new QTimer(this);
  timer->start(500);
  //监听定时器对象的信号
  connect( timer, &QTimer::timeout, [=](){
    static int number3 = 0;
    ui->label_3->setText( QString::number(number3++));
  });
}

Widget::~Widget()
{
  delete ui;
}


//定时器的实现
void Widget::timerEvent( QTimerEvent* e){
  if( e->timerId() == timeId1 ){
    static int number = 0;
    ui->label->setText(QString::number( number++));
  }
  if( e->timerId() == timeId2 ){
    static int number2 = 0;
    ui->label_2->setText(QString::number( number2++));
  }
}
