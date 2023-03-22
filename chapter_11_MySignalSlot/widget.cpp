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
  //connect( this->te, &Teacher::hungry, this->st, &Student::treat);

  //连接有参数的信号槽
  //connect( this->te, &Teacher::hungry, this->st, &Student::treat);  //error，发生了重载不知道调用哪一个
  //connect(this->te, SIGNAL(hungry(QString)), this->st, SLOT(treat(QString)));

//  void (Teacher:: * teacherSingal)(QString) = &Teacher::hungry;
//  void (Student:: * studentSlot)(QString) = &Student::treat;
//  connect( this->te, teacherSingal, this->st, studentSlot);


  void (Teacher:: * teacherSingal2)() = &Teacher::hungry;
  void (Student:: * studentSlot2)() = &Student::treat;
  connect( this->te, teacherSingal2, this->st, studentSlot2);


  QPushButton* button = new QPushButton;
  button->setParent( this);
  button->setText("下课");

  //QPushButton的clicked信号不带参数，与teacherSingal信号不匹配，必须用不带参数的teacherSingal2
  connect( button, &QPushButton::clicked, this->te, teacherSingal2);
  //可以通过使用lambda表达式写槽函数
  //connect( button, &QPushButton::clicked, this->te,[=](){
  //    this->st->treat("西红柿炒蛋");
  //  });
  
  //信号和槽的拓展
  //1.信号连接信号
  //2.一个信号可以连接多个槽函数
  //3.多个信号可以绑定同一个槽函数
  //4.信号和槽的参数类型要一一对应
  //5.信号的参数个数可以多余槽参数，反之不行，类型相同的参数个数也要一一对应
  //6.可以使用 disconnect 断开信号槽的连接
    //怎么连接的就要怎么断开

  //Qt4版本的信号和槽的写法
  //连接有参数的信号和槽
  //优点：参数直观，写法简单
  //缺点：编译器不检测参数是否符合，只会在运行后提示错误(最致命的缺点)
  //connect(this->te, SIGNAL(hungry(QString)), this->st, SLOT(treat(QString)) );

  //下课函数调用
  //classOver();
}

Widget::~Widget()
{
  delete ui;
}

void Widget::classOver(){

  //触发自定义信号
  emit this->te->hungry();

  emit this->te->hungry("西红柿炒蛋");
}
