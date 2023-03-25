#ifndef SMALLWIDGET_H
#define SMALLWIDGET_H

#include <QWidget>

namespace Ui {
  class smallWidget;
}

class smallWidget : public QWidget
{
  Q_OBJECT

public:
  explicit smallWidget(QWidget *parent = nullptr);
  ~smallWidget();

  //设置数据
  void setData( int value);

  //得到数据
  const int getData();

private:
  Ui::smallWidget *ui;
};

#endif // SMALLWIDGET_H
