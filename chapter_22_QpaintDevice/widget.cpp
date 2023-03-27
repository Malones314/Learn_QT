#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QImage>
#include <QPicture>


Widget::Widget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::Widget)
{
  ui->setupUi(this);

  //QPixmap做绘图设备  对不同平台做了优化
//  QPixmap pix( 300, 300); //创建画纸
//  pix.fill(Qt::white);  //填充背景颜色
//  QPainter painter( &pix);
//  painter.setRenderHint(painter.Antialiasing);  //设置抗锯齿
//  painter.setPen( QPen(Qt::green));
//  painter.drawEllipse( QPoint(100,100), 80, 80);
//  pix.save("E:\\MyCandCPPSpace\\QtCode\\chapter_22\\chapter_22_QpaintDevice\\pix.png");

  //QImage做绘图设备   对像素级别的访问做了优化(可以显示修改图片像素点)
//  QImage img( 300, 300, QImage::Format_RGB32);
//  img.fill(Qt::white);  //填充背景颜色
//  QPainter painter( &img);
//  painter.setRenderHint(painter.Antialiasing);  //设置抗锯齿
//  painter.setPen( QPen(Qt::red));
//  painter.drawEllipse( QPoint(100,100), 80, 80);
//  img.save("E:\\MyCandCPPSpace\\QtCode\\chapter_22\\chapter_22_QpaintDevice\\img.png");

  //QPicture做绘图设备   记录和重现画家的绘图指令
  QPicture pic;
  QPainter painter( this);
//  painter.begin( &pic);

//  painter.setPen( QPen(Qt::red));
//  painter.drawEllipse( QPoint( 150, 150), 100, 100);

//  painter.end();
//  pic.save("E:\\MyCandCPPSpace\\QtCode\\chapter_22\\chapter_22_QpaintDevice\\pic.pic"); //后缀名可以自己定义

}
void Widget::paintEvent(QPaintEvent *event){
  //重现绘图指令
  QPicture pic;
  QPainter painter( this);
  pic.load("E:\\MyCandCPPSpace\\QtCode\\chapter_22\\chapter_22_QpaintDevice\\pic.pic");
  painter.drawPicture( 0, 0, pic);
}
Widget::~Widget()
{
  delete ui;
}

