#include "student.h"
#include <QDebug>
#include <QString>
Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat(){
  qDebug() << "请老师吃饭";
}
void Student::treat(QString foodName){

  //把QString 转为char*
  //1.调用toUtf8 转为 QByteArray
  //2.调用data 转为 char*
  qDebug() << "请老师吃饭，老师要吃:" << foodName.toUtf8().data();
}
