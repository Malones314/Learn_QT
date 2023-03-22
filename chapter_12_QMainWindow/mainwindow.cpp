#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

//可以有多个的部件，添加到窗口用add
//最多只能有一个的部件，添加到窗口用set

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  //设置固定尺寸
  setFixedSize(600, 400);

  //1 菜单栏 最多只能有一个菜单栏
  QMenuBar* bar = new QMenuBar(this);
  //1.1 将菜单栏设置到窗口中
  this->setMenuBar( bar);
  //1.2 添加菜单内容
  QMenu* start = bar->addMenu("开始");
  //1.3 添加菜单项
  QAction* shutdown = start->addAction("关机");
  QAction* restart = start->addAction("重启");
  //1.4 添加分割线
  start->addSeparator();
  //1.5 添加子菜单
  QMenu* testMenu = bar->addMenu("测试菜单");
  QMenu* subMenu = new QMenu;
  subMenu->setTitle("挂子菜单");
  subMenu->addAction("子菜单1");
  subMenu->addAction("子菜单2");
  testMenu->addMenu(subMenu);
  start->addMenu(testMenu);

  //2 工具栏 可以多个
  QToolBar* toolBar1 = new QToolBar(this);
  //2.1 将工具栏设置到窗口中
  addToolBar( Qt::LeftToolBarArea ,toolBar1); //设置到左边停靠
  //2.2 设置只允许左右停靠
  toolBar1->setAllowedAreas( Qt::LeftToolBarArea | Qt::RightToolBarArea);
  //2.3 关闭浮动
  toolBar1->setFloatable(false);
  //2.4 关闭移动拖拽
  //toolBar1->setMovable(false);
  //2.5 添加菜单项
  toolBar1->addAction(restart);
  toolBar1->addAction(shutdown);

  //3 状态栏 最多只能有一个
  QStatusBar* sBar = new QStatusBar;
  //添加到窗口中
  setStatusBar( sBar);
  QLabel* label1 = new QLabel("左侧状态信息", this);
  QLabel* label2 = new QLabel("右侧状态信息", this);
  QLabel* label11 = new QLabel("左侧状态信息2", this);
  //添加到左侧
  sBar->addWidget( label1);
  //添加到右侧
  sBar->addPermanentWidget( label2);
  //左侧指定位置插入
  sBar->insertWidget(0,label11);  //0为插入位置

  //4 铆接部件(浮动窗口) 围绕核心部件浮动
  QDockWidget* dock = new QDockWidget("浮动窗口", this);
  //设置位置
  addDockWidget( Qt::BottomDockWidgetArea, dock);
  //设置只允许上和下 停靠浮动
  dock->setAllowedAreas( Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

  //5 核心部件(中心部件) 最多只有一个
  QTextEdit* text = new QTextEdit;
  setCentralWidget( text);


}

MainWindow::~MainWindow()
{
  delete ui;
}

