#include "widget.h"
#include "ui_widget.h"
#include <QAxObject>  //要加上QT+= axcontainer
#include <QDebug>
Widget::Widget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::Widget)
{
  ui->setupUi(this);
  QAxObject* excel = new QAxObject;         //该类允许QT应用与OLE对象交互
                                            //如Microsoft Office文档、Adobe PDF文档、Windows Media Player等。
  excel->setControl( "Excel.Application");  //控制器类型设置为Excel.Application，
                                            //Excel.Application表示启动Microsoft Excel应用,将其嵌入到QT中
  excel->setProperty("Visible", true);      // 设置Excel应用程序的可见性为true
  QAxObject* workbooks = excel->querySubObject("Workbooks");  // 从Excel对象中获取Workbooks对象
  workbooks->dynamicCall("Add");          // 在Excel中添加一个新的工作簿
  QAxObject* workbook = excel->querySubObject("ActiveWorkbook");  // 获取当前活动的工作簿
  QAxObject* worksheets = workbook->querySubObject("Worksheets"); // 获取当前工作簿的工作表集合
  QAxObject* worksheet = worksheets->querySubObject("Item(int)", 1);  // 获取第一个工作表

  QAxObject* range = worksheet->querySubObject("Range(const QString&)", "A1");  // 获取A1单元格
  range->setProperty("Value", "Hello, World!");     // 将"Hello, World!"写入A1单元格

  workbook->dynamicCall("SaveAs(const QString&)", "C:\\Users\\Malones\\Desktop\\example.xlsx"); // 保存工作簿
  workbook->dynamicCall("Close()"); // 关闭工作簿
  excel->dynamicCall("Quit()"); // 退出Excel应用程序

  delete range;
  delete worksheet;
  delete worksheets;
  delete workbook;
  delete workbooks;
  delete excel;
}

Widget::~Widget()
{
  delete ui;
}

