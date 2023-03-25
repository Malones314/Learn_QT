#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>
#include <QString>
#include <QEvent>
MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
  //设置鼠标追踪
  this->setMouseTracking( true);
}
//QEvent类是Qt框架中的一个核心类，用于表示事件（Event）。事件是指系统或用户操作的信号，
//例如鼠标点击、键盘按下等等。

////鼠标进入
//void MyLabel::enterEvent(QEvent *){
//  qDebug() << "鼠标进入";
//}

////鼠标离开
//void MyLabel::leaveEvent(QEvent *){
//  qDebug() << "鼠标离开";
//}

//使用buttons代表使用联合按键，同时使用鼠标左键、右键、中键的组合


//鼠标按下
void MyLabel::mousePressEvent( QMouseEvent* ev){
  QString str = QString("鼠标按下的相对位置：x=%1 ，y=%2").arg(ev->x()).arg( ev->y());
  QString strr = QString("鼠标按下的绝对位置：x=%1 ，y=%2").arg( ev->globalX()).arg( ev->globalY());
  qDebug() << "鼠标按下" << str << strr;
}

//鼠标释放
void MyLabel::mouseReleaseEvent( QMouseEvent* ev){
  qDebug() << "鼠标释放";
}

//鼠标移动
void MyLabel::mouseMoveEvent( QMouseEvent* ev){
  qDebug() << "鼠标移动";
}

//事件分发器
bool MyLabel::event(QEvent *e){
  if( e->type() == QEvent::MouseButtonPress){
    QMouseEvent* ev = dynamic_cast<QMouseEvent*>(e);
    qDebug() << "在event中 鼠标按下了";
    return true;  //拦截事件，不向下分发事件
  }

  //其他事件交给父类处理
  return QLabel::event(e);

}
