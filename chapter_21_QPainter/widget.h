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

  //重写绘画事件
  void paintEvent(QPaintEvent *event);
private:
  Ui::Widget *ui;
  int posX;
  int posY;
};
#endif // WIDGET_H
