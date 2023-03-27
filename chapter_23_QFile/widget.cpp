#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QString>
#include <QtDebug>
#include <QMessageBox>
#include <QFile>
#include <QTextCodec>
#include <QFileInfo>
#include <QDateTime>
Widget::Widget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::Widget)
{
  ui->setupUi(this);

  //点击选择文件，弹出文件对话框，读取设置的路径下的文件，文件路径放入lineEdit中，内容放到textEdit中
  connect( ui->pushButton, &QPushButton::clicked, [=](){
    QString path = QFileDialog::getOpenFileName( this, "打开文件", "E:\\MyCandCPPSpace\\QtCode\\chapter_23\\chapter_23_QFile", "*.txt");
    if( !path.isEmpty()){
      ui->lineEdit->setText(path);

      //读取文件信息
      QFile file(path);
      //设置打开方式
      file.open( QIODevice::ReadOnly);

//      //读取全部内容
//      QByteArray arr = file.readAll();

//      ui->textEdit->setText(arr);
//      //默认接受的格式为utf-8
//      //QTextCodec* codec = QTextCodec::codecForName("utf-8");  //显示设置文本格式

//      //转换文本格式
//      //ui->textEdit->setText( codec->toUnicode(arr));

      //文件信息
      QFileInfo info( path);
      qDebug() << "后缀名: " << info.suffix().toUtf8().data() << "大小: " << info.size() //大小为字节大小
             << "文件名: " << info.fileName() << "文件路径: " << info.filePath();
      qDebug() << "创建日期: " << info.created().toString("yyyy-MM-dd hh:mm:ss");
    } else {
      QMessageBox::warning( this, "警告", "路径不能为空");
    }

  });



}

Widget::~Widget()
{
  delete ui;
}

