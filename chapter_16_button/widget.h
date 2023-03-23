#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
const int woman = false;
const int man = true;
const int adult = true;
const int underage = false;
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
  Q_OBJECT

public:
  Widget(QWidget *parent = nullptr);
  ~Widget();

  bool sex; //设置性别 男为true 女为false
  bool age; //设置是否成年 成年为true 未成年为false

private:
  Ui::Widget *ui;
};
#endif // WIDGET_H
