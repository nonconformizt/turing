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
    void speedChanged(int value);

public slots:
    void handleSlider(int value);

};


#endif // SPEEDSLIDER_H
