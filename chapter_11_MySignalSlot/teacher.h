#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
  Q_OBJECT
public:
  explicit Teacher(QObject *parent = nullptr);

  // 自定义信号 写道signal下
  // 1.返回值为void
  // 2.只需要声明，不需要实现
  // 3.可以有参数，可以发生重载
signals:
  void hungury();
  void hungury( QString foodName);
};

#endif // TEACHER_H
