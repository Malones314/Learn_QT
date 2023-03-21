#include "widget.h"
#include "ui_widget.h"
#include "student.h"
#include "teacher.h"
#include <QPushButton>
// Teacher 老师类 Student 学生类
// 下课后老师发出饿的信号，学生响应，请老师吃饭

Widget::Widget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::Widget)
{
  ui->setupUi(this);
  st = new Student(this);
  te = new Teacher(this);

  //连接信号槽
  //connect( this->te, &Teacher::hungury, this->st, &Student::treat);

  //连接有参数的信号槽
  //connect( this->te, &Teacher::hungry, this->st, &Student::treat);  //error，发生了重载不知道调用哪一个
  //connect(this->tr, SIGNAL(hungry(QString)), this->st, SLOT(treat(QString)));

  void (Teacher:: * teacherSingalNoStr)() = &Teacher::hungury;
  void (Student:: * studentSlotNoStr)() = &Student::treat;
  connect(this->te,teacherSingalNoStr,this->st,studentSlotNoStr);


  void (Teacher:: * teacherSingal)(QString) = &Teacher::hungury;
  void (Student:: * studentSlot)(QString) = &Student::treat;
  connect(this->te,teacherSingal,this->st,studentSlot);

  QPushButton* button = new QPushButton;
  button->setParent(this);
  button->setText("下课");

  //信号和槽的拓展
  //1.信号连接信号
  connect( button, &QPushButton::clicked, this->st, studentSlotNoStr);
  //2.一个信号可以连接多个槽函数
  //3.多个信号可以绑定同一个槽函数

  //下课函数调用
//  classOver();
}

Widget::~Widget()
{
  delete ui;
}

void Widget::classOver(){

  //触发自定义信号
  emit this->te->hungury();

  emit this->te->hungury("西红柿炒蛋");
}
