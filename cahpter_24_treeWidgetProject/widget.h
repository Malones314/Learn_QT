#ifndef WIDGET_H
#define WIDGET_H
#include <QTreeWidgetItem>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
  Q_OBJECT

public:
  Widget(QWidget *parent = nullptr);
  ~Widget();
  void init();
  void updateParentItem( QTreeWidgetItem* item);

public slots: //声明可以被用来声明公共的槽函数
  void treeItemChanged( QTreeWidgetItem* item, int column);

private:
  Ui::Widget *ui;
};
#endif // WIDGET_H
