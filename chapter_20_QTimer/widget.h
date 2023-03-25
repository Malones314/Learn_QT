#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
  Q_OBJECT

public:
  Widget(QWidget *parent = nullptr);
  ~Widget();

  //定时器的实现
  void timerEvent( QTimerEvent*);

private:
  Ui::Widget *ui;

  //第一个定时器的id
  int timeId1;
  //第二个定时器的id
  int timeId2;

};
#endif // WIDGET_H
