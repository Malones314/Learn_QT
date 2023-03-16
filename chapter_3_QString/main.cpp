#include "mainwindow.h"

#include <QApplication>
#include <QString>
#include <QLabel>
#include <cstdio>
int main(int argc, char *argv[]){

  QString ss = "hello";
  ss += "world";
  ss.append("hello"); //和+=同样的功能
  ss.sprintf("%s", "hello");  //ss = "hello"
  //相比于sprintf，arg()函数更加方便与安全
  ss = QString( "%1 was born in %2.").arg("Z").arg(2001);
  //ss = "Z was born in 2001"

  //QString::trimmed()用于移除字符串两端的空白字符
  //QString::simplified()移除字符串两端的空白字符，使用单个字符替换字符串出现的空白字符

  ss = "    a\t\t\tb\t  \tc";
  ss = ss.simplified(); //ss = "a b c"

  //QString::startsWith( QString s) 判断this是否以s开头
  //QString::endsWith( QString s) 判断this是否以s结尾
  //QString::contains( QString s) 判断s是否出现过

  // toInt(), toDouble(), toFloat(), toLong(), toLongLong()等转换函数
  //有两个参数，一个是bool类型的指针，用于返回转换状态，
  //第二个是转换的基数:
    //0: 用C语言的转换方式：字符串0x开头时基数为16，字符串0开头基数为8
    //别的数为设置的基数

  //toAscii()返回一个ASCII编码的8位字符串
  //toLatin1()返回一个Latin-1编码的8位字符串
  //toUtf8()返回一个UTF-8编码的8位字符串
  //tolocal8Bit()返回一个系统本地编码的8位字符串

  QApplication app( argc, argv);
  QLabel label( ss);
  label.show();

  return app.exec();
}
