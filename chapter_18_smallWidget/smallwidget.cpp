#include "smallwidget.h"
#include "ui_smallwidget.h"

smallWidget::smallWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::smallWidget)
{
  ui->setupUi(this);

  void( QSpinBox::* signal)(int) = &QSpinBox::valueChanged;
  connect( ui->spinBox, signal, ui->horizontalSlider, &QSlider::setValue);
  connect( ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);

}
void smallWidget::setData(int value){
  ui->horizontalSlider->setValue( value);
}
const int smallWidget::getData(){
  return ui->horizontalSlider->value();
}
smallWidget::~smallWidget()
{
  delete ui;
}
