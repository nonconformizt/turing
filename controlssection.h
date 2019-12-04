#ifndef CONTROLSSECTION_H
#define CONTROLSSECTION_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include "buttonpanel.h"


class ControlsSection : public QWidget
{
Q_OBJECT


private:
    QHBoxLayout * centralLayout;
    ButtonPanel * buttonPanel;


public:
    explicit ControlsSection(QWidget *parent = nullptr);
    QSize sizeHint() const override;


signals:


public slots:


};



#endif // CONTROLSSECTION_H
