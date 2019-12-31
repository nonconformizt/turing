#ifndef CONTROLSSECTION_H
#define CONTROLSSECTION_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include "buttonpanel.h"
#include "inputpanel.h"
#include "speedslider.h"


class ControlsSection : public QFrame
{
Q_OBJECT


private:
    QHBoxLayout * centralLayout;
    InputPanel * inputPanel;


public:
    ButtonPanel * buttonPanel;
    SpeedSlider * speedSlider;

    explicit ControlsSection(QWidget *parent = nullptr);
    QSize sizeHint() const override;


signals:
    void inputLoaded(QString inp);

public slots:
    void handleInput();

};



#endif // CONTROLSSECTION_H
