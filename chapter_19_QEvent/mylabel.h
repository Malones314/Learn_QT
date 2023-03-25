#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
  Q_OBJECT
public:
  explicit MyLabel(QWidget *parent = nullptr);

//  //鼠标进入
//  void enterEvent( QEvent*);

//  //鼠标离开
//  void leaveEvent( QEvent*);

  //鼠标按下
  void mousePressEvent( QMouseEvent* ev);

  //鼠标释放
  void mouseReleaseEvent( QMouseEvent* ev);

  //鼠标移动
  void mouseMoveEvent( QMouseEvent* ev) ;

  //事件分发器

  //event 事件分发器，用于分发事件，也可以做拦截，返回值bool，如果返回的是true，
  //代表拦截处理，不再向下分发
  bool event(QEvent *e);

  //事件过滤器
  //让事件分发器也收不到事件信息
  //1. 给控件安装过滤器
  //2. 重写过滤事件
  //bool eventFilter(两个参数)


signals:

};

#endif // MYLABEL_H
