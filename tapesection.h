#ifndef TAPESECTION_H
#define TAPESECTION_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "tape.h"


class TapeSection : public QWidget
{
Q_OBJECT


private:
    QVBoxLayout * centralLayout;
    QLabel * carriage;
    QLabel * stepsIndicator;
    QLabel * stateIndicator;

public:
    Tape *tape;

    explicit TapeSection(QWidget *parent = nullptr);
    QSize sizeHint() const override;

    void setSteps(int steps) { stepsIndicator->setText("Steps" + QString::number(steps)); }
    void setState(QString name) { stateIndicator->setText("State: " + name); }

};



#endif // TAPESECTION_H
