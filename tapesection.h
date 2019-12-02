#ifndef TAPESECTION_H
#define TAPESECTION_H

#include <QWidget>
#include <QVBoxLayout>
#include "tape.h"


class TapeSection : public QWidget
{
Q_OBJECT


private:
    QVBoxLayout * centralLayout;
    Tape *tape;


public:
    explicit TapeSection(QWidget *parent = nullptr);
    QSize sizeHint() const override;


signals:


public slots:



};



#endif // TAPESECTION_H
