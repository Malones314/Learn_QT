# Learn_QT
## 常见问题与思考

## 常见技巧
```
在styleSheet中设置border: 1 px solid red显示widget边框
```
```cpp
判断lineEdit中的text是否为空
QString text = ui->lineEdit->text();
if (text.isNull() || text.isEmpty()) {
    // 处理lineEdit为空的情况
} else {
    // 处理lineEdit不为空的情况
}
```
```cpp
emit用于发射信号
eg：
emit mySignal();
请注意，emit 关键字不是必须的。也可以使用 mySignal() 来发射信号，但在大多数情况下，建议使用 emit 关键字，以便更清晰地表达代码意图。
emit 关键字只能在类中使用，而不能在其他地方（例如在主函数中）使用。这是因为发射信号需要访问类的内部状态和成员函数。
```
```cpp
qstring转为unsigned char
QString str = "Hello, world!";
QByteArray byteArray = str.toUtf8();
const unsigned char* data = reinterpret_cast<const unsigned char*>(byteArray.data());
```
```cpp
reinterpret_cast:
reinterpret_cast 运算符执行底层类型的强制类型转换，它不进行运行时检查，也不考虑源类型和目标类型之间的继承关系。
因此，如果你需要将一个指针或引用转换为一个完全不同类型的指针或引用（如 unsigned char* 转换为 QString*），
并且你确定它们的内存布局是相同的，那么可以使用 reinterpret_cast。
```
```cpp
QByteArray:
QByteArray 是 Qt 框架中的一个类，用于处理字节数组，它提供了一些方便的函数，使得对字节数组的操作更加简单。

QByteArray 本质上是一个指向字节数组的指针，同时它也提供了一些函数，如 append()、prepend()、insert() 等，
用于向字节数组中添加数据。除此之外，QByteArray 还提供了一些函数用于查找、比较、删除和截取字节数组。
在 Qt 中，QByteArray 经常被用作在网络通信中传输数据，或在文件读写中读取或写入二进制数据。QByteArray 的数据
存储方式类似于 C++ 中的字符数组，但是 QByteArray 支持 Unicode 编码，并且可以与 QString 类型进行相互转换，
这使得处理中文等特殊字符更加方便。

使用 QByteArray 存储和读取二进制数据:
QByteArray byteArray;
byteArray.append(0x10);
byteArray.append(0x20);
byteArray.append(0x30);

// 从字节数组中读取数据
unsigned char* data = reinterpret_cast<unsigned char*>(byteArray.data());
for (int i = 0; i < byteArray.size(); i++) {
    printf("%02X ", data[i]);
}

```
在ui设计中把sizePolicy中的策略：
Ignore：指定的控件在布局中忽略它的大小。
Fixed：用于指定一个控件的大小应该是固定的，而不应该被布局系统改变。
Minimum：用于指定控件在布局中的最小大小，当控件的大小小于最小大小时，布局系统将自动扩展控件的大小，以确保其能够容纳其内容。
Maximum：用于指定控件在布局中的最大大小，当控件的大小大于最大大小时，布局系统将自动缩小控件的大小，以确保其不会占用过多的空间。
Preferred：指定控件的首选大小，即控件在布局中应该具有的大小。布局系统会尽可能满足控件的首选大小，并将其放置在布局中。
MinimumExpanding：用于指定控件在布局中是否应该按照最小大小进行扩展。它会尽可能地扩展到与布局中的其他控件相同的大小。然而，控件的大小不会超过最小大小。这个参数通常用于希望控件在布局中占据空间但不希望太大的情况。
Expanding：用于指定控件在布局中应该按照什么方式扩展。让控件在布局中自由扩展，直到填满布局中的所有空间。当布局的大小发生变化时，控件会自动调整大小以填充可用的空间。
