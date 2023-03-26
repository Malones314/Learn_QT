#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPixmap>

Widget::Widget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::Widget)
{
  ui->setupUi(this);
  posX = 0;
  posY = 0;
}

Widget::~Widget()
{
  delete ui;
}
//重写绘画事件
void Widget::paintEvent(QPaintEvent *event){
  QPainter* painter = new QPainter(this);

  /*基本绘图*/
  ///////////////////////////////////////////////////////////////////////////////////////////////////////
//  //画笔
//  QPen pen( QColor( 255, 0, 0));
//  //设置画笔宽度
//  pen.setWidth(5);
//  //设置画笔风格
//  pen.setStyle(Qt::DashLine);
//  //画家使用创建的画笔
//  painter->setPen(pen);

//  //画刷
//  QBrush brush( Qt::yellow);  //填充封闭图案
//  //设置画刷风格
//  brush.setStyle(Qt::CrossPattern);
//  //画家使用画刷
//  painter->setBrush(brush);

//  //画线
//  //painter->drawLine( 0, 0, 100, 100); //param: x1, y1, x2, y2
//  painter->drawLine( QPoint( 0,0), QPoint(100, 100));

//  //画圆
//  painter->drawEllipse( QPoint(100, 100), 100, 100);

//  //画矩形
//  painter->drawRect( QRect( QPoint(0,0), QPoint( 100, 100))); //QRect为矩形区域

//  //写字
//  painter->setFont(QFont("宋体", 18));
//  painter->drawText( QRect( QPoint(100, 100), QPoint( 200, 200)), "键盘敲烂");

  /*高级绘图*/
  ///////////////////////////////////////////////////////////////////////////////////////////////////////
  QPen pen;
  painter->setPen(pen);

  painter->save();  //保存画家的状态和位置

  painter->drawEllipse( QPoint( posX,posY), 100, 100);
  painter->setRenderHint( QPainter::Antialiasing);  //设置抗锯齿效果

  painter->translate(100, 0); //移动画家位置

  painter->drawEllipse( QPoint( posX,posY), 100, 100);

  painter->restore(); //恢复画家的状态和位置

  QPixmap photo;
  photo.load("://photos//witcher3.png");
  photo = photo.scaled(400, 400); //按比例缩放图片大小
  painter->drawPixmap(QPoint(200,200), photo);

  posX += 1;
  posY += 1;
  update();   //重新调用绘图事件paintEvent

}

