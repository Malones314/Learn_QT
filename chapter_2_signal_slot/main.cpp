//实际就是观察者模式，当某个时间发生后，例如按钮检测到自己被点击后，会发出signal
//广播式发出，如果有对象对该信号感兴趣，会使用connect函数(成为slot)来处理这个信号，
//即：当signal发出后slot函数会自动被回调(当发生了感兴趣的事件，某一操作会被自动触发)

#include<QApplication>
#include<QPushButton>

int main( int argc, char* argv[]){
  QApplication app( argc, argv);

  QPushButton button( "Quit");  // 创建一个QPushButton对象,用于发出signal
  QObject::connect( &button, &QPushButton::clicked, &QApplication::quit);
    // 连接按钮的clicked信号和应用程序对象的quit槽函数
  //QObject::connect()有五个重载：
    //1. QMetaObject::Connection connect( const QObject*, const char*,
                    //const QObject*, const char*, Qt::ConnectionType);
    //2. QMetaObject::Connection connect(const QObject *, const QMetaMethod &,
                    //const QObject *, const QMetaMethod &, Qt::ConnectionType);
    //3. QMetaObject::Connection connect(const QObject *, const char *,
                    //const char *, Qt::ConnectionType) const;
    //4. QMetaObject::Connection connect(const QObject *, PointerToMemberFunction,
                    //const QObject *, PointerToMemberFunction, Qt::ConnectionType)
    //5. QMetaObject::Connection connect(const QObject *, PointerToMemberFunction,
                    //Functor);
    //最常用的connect形式：
      /// @param sender 发出信号的对象   const QObject*
      /// @param signal 发送对象发出的信号   const char*
      /// @param receiver 接收信号的对象    const QObject*
      /// @param slot 接受对象在接收到型号之后要调用的函数  const char*
      /// 函数将signal和slot当作字符串处理
      //connect(sender, signal, receiver, slot);

  button.show();  //显示按钮

  return app.exec();
}
