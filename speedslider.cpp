#include "speedslider.h"



SpeedSlider::SpeedSlider(QWidget *parent) : QFrame(parent)
{
    slider = new QSlider(Qt::Horizontal, this);
    slider->setRange(0, 100);
    slider->setValue(50);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);


}


QSize SpeedSlider::sizeHint() const
{
    return QSize(200, 52);
}

