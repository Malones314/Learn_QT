#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QDebug>
Widget::Widget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::Widget)
{
  ui->setupUi(this);
  //利用事件过滤器，拦截label的鼠标按下事件
  //1 先给控件安装过滤器
  ui->label->installEventFilter( this);
  //2. 重写过滤器事件
}

//过滤器事件
//@param obj 判断控件
//@param e 判断事件
bool Widget::eventFilter(QObject * obj, QEvent * e){
  if( obj == ui->label){
    if( e->type() == QEvent::MouseButtonPress){
      QMouseEvent* ev = dynamic_cast<QMouseEvent*>(e);
      QString s = QString("在鼠标过滤器中 鼠标按下了 x=%1 y=%2").arg(ev->x()).arg(ev->y());
      qDebug() << s;
      return true;
    }
  }
  //其他事件交给父类处理
  return QWidget::eventFilter( obj, e);
}


Widget::~Widget()
{
  delete ui;
}

