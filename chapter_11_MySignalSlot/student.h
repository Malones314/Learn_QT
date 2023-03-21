#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
  Q_OBJECT
public:
  explicit Student(QObject *parent = nullptr);

  //槽函数写在public slot下 或 public下 或 全局函数 或 lambda
  //返回值void
  //需要声明 需要实现
  //可以有参数 可以重载
signals:

public slots:
  void treat();
  void treat( QString foodName);
};

#endif // STUDENT_H
