#include "mainwindow.h"

#include <QApplication>
#include <QList>
#include <QVector>
#include <iostream>
#include <QDebug>
#include <QCoreApplication>
using namespace std;

//存储在Qt容器中的数据必须是可赋值的数据类型，必须提供一个默认无参的ctor
//一个复制构造函数、一个赋值操作运算符
//可容纳一般数据类型以及Qt的一些数据类型，不过，QObject及其子类都无法存储
//如：QWidget、Qdialog、QToolBar、QThread、QTimer、QCoreApplication
//QFile、QTcpSocket、QProcess、QIODevice、QObjectCleanupHandler等，
//可以考虑使用指针存储这些无法直接存储的类

//Qt容器可以嵌套
//eg:
  // QHash< QString, QList<double> >

int main(int argc, char *argv[]){

  QApplication a(argc, argv);

  //QList Qt 5.15版本及之前的实现 是通过动态数组，而 Qt 6之后的版本是通过
  //链表实现，但是接口和方法都没有改变，对于开发者来说变化是透明的
  //在尾部插入元素（append）：O(1)。由于QList是基于链表实现的，因此在尾部插入元素只需要将新元素插入到链表的尾部即可。
  //在头部插入元素（prepend）：O(1)。由于QList是基于链表实现的，因此在头部插入元素只需要将新元素插入到链表的头部即可。
  //在任意位置插入元素（insert）：O(n)。由于QList是基于链表实现的，因此在任意位置插入元素需要遍历链表，找到对应的位置并插入新元素。
  //删除元素（remove）：O(n)。由于QList是基于链表实现的，因此删除元素需要遍历链表，找到要删除的元素并将其从链表中删除。
  //访问元素（at）：O(n)。由于QList是基于链表实现的，因此访问元素需要遍历链表，找到对应的位置并返回相应的元素。
  //排序（sort）：O(nlog(n))。QList使用快速排序算法进行排序，因此排序的时间复杂度为O(nlog(n))。

  //虽然在Qt 6中，QList的内部实现已经从基于动态数组改为基于链表，但是与QLinkedList相比，QList仍然有一些区别。

  //插入和删除操作的效率：QList在插入和删除元素时比QLinkedList效率更高。这是因为QList使用了空间预分配和缓存技术，可以在内部数组中存储
  //多个节点，而不需要为每个节点单独分配内存。这种技术可以减少内存分配的次数，提高插入和删除操作的效率。

  //访问操作的效率：在访问元素时，QLinkedList比QList更高效，因为QLinkedList的元素存储在连续的内存块中，可以利用CPU缓存的特性，提高访
  //问元素的效率。

  //内存占用：QList比QLinkedList使用更少的内存，因为QList在存储元素时，只需要存储指向前一个和后一个元素的指针，而QLinkedList还需要为
  //每个节点分配额外的内存来存储指向前一个和后一个元素的指针。

  //排序操作的效率：由于QLinkedList中的节点不是连续存储的，所以在排序操作时，需要将节点复制到数组中进行排序，然后再将排序后的元素复制回
  //链表中。而QList由于内部使用了数组来存储元素，可以直接使用STL提供的排序算法。

  //两者都是双向链表，但都不是循环链表

  QList<QString> list_string;
  QString str("this is a test");
  list_string << str;  //把str输入到list中
  list_string.append(str); //把str添加到list最后
  list_string.insert( list_string.size(), str); //把str插入到list最后
  list_string.insert( 0, str); //插入到链表头中

  QList<int> list_int;

  for( auto k : list_string)
    qDebug() << k << endl;

  //有Cpp风格迭代器
    //QList<T>::iterator,QList<T>::const_iterator

  //QVector是一个动态数组，可以自动扩展大小，用于存储同类型的元素。QVector提供了方便的数组访问和修改方法，以及支持STL容器算法的接口。
  //QVector在需要频繁进行元素插入或删除操作时，性能可能不如QList，因为QVector需要重新分配内存，而QList只需要更新指针。
  //QVector的默认构造函数创建一个空的向量，大小为0，如果需要在创建时指定向量大小，可以使用构造函数QVector(int size)。
  //在使用QVector时，如果需要获取向量的元素个数，应该使用size()方法，而不是count()方法，因为size()方法的时间复杂度是O(1)，
    //而count()方法的时间复杂度是O(n)。
  //在使用QVector的迭代器时，应该使用const_iterator来保证迭代器只读访问，以避免意外的修改。
  //当QVector存储的元素是自定义的对象时，需要重载对象的拷贝构造函数和析构函数，以确保对象在插入和删除时被正确地构造和销毁。

  return a.exec();

}
