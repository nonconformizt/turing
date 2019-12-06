#ifndef SPEEDSLIDER_H
#define SPEEDSLIDER_H

#include <QFrame>
#include <QSlider>

class SpeedSlider : public QFrame
{
Q_OBJECT

private:
    QSlider * slider;


public:
    explicit SpeedSlider(QWidget *parent = nullptr);
    QSize sizeHint() const override;


signals:


public slots:


};


#endif // SPEEDSLIDER_H
