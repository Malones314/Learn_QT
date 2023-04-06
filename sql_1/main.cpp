#include "widget.h"

#include <QApplication>
#include <QCoreApplication>
#include <QTextCodec>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlRecord>
#include <QTime>
#include <QtDebug>


int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  QTextCodec::setCodecForLocale( QTextCodec::codecForLocale()); //设置中文显示
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setHostName("hosename");
  db.setDatabaseName("qtDB.db");
  db.setUserName("zrc");  //设置用户名
  db.setPassword("123456"); //设置密码
  if (db.open()) {    //要先打开连接数据库
      qDebug() << "Database opened";
  } else {
      qDebug() << "Database NOT opened";
  }
  //创建数据库
  QSqlQuery query;
  bool success = query.exec( //exec用于执行SQL语句并返回一个布尔值来表示执行是否成功。
                      "create table automobile "
                      "(id int primary key, type varchar, number int) ");
  if( success)
    qDebug() << QObject::tr( "数据库表创建成功");
  else
    qDebug() << QObject::tr("数据库表创建失败");

  //插入
  query.prepare("insert into automobile values(?,?,?)");
  //使用 ? 作为占位符，是为了在执行 SQL 语句之前预处理 SQL 语句，以避免 SQL 注入攻击。
    //等价于：
//    query.prepare("insert into automobile values( id, type, number)"
//                  "values(:id, :type, :number)");
  query.bindValue(0, 1);  //id设置为1
  query.bindValue(1,"A");
  query.bindValue(2, 213);
  query.exec();
  //查询
  query.exec("SELECT * FROM automobile WHERE id = 1");
  QSqlRecord rec = query.record();
    //创建了一个QSqlRecord对象rec，然后通过调用QSqlQuery::record()函数，将查询结果集中的元数据信息（例如列名、数据类型等）存储在QSqlRecord对象rec中。
  if( query.next()) //将指针移动到第一条符合的记录上
    qDebug() << query.value("type").toString();
  else
    qDebug() << "没有查询到结果";
  Widget w;
  w.show();
  return a.exec();
}
