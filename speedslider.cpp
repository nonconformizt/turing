#include "speedslider.h"



SpeedSlider::SpeedSlider(QWidget *parent) : QFrame(parent)
{
    slider = new QSlider(Qt::Horizontal, this);
    slider->setRange(1, 100);
    slider->setValue(10);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(handleSlider(int)));
}


void SpeedSlider::handleSlider(int value)
{
    emit speedChanged(value);
}


QSize SpeedSlider::sizeHint() const
{
    return QSize(200, 52);
}
