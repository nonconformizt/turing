#ifndef CONTROLSSECTION_H
#define CONTROLSSECTION_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include "buttonpanel.h"
#include "inputpanel.h"


class ControlsSection : public QFrame
{
Q_OBJECT


private:
    QHBoxLayout * centralLayout;
    ButtonPanel * buttonPanel;
    InputPanel * inputPanel;


public:
    explicit ControlsSection(QWidget *parent = nullptr);
    QSize sizeHint() const override;


signals:


public slots:


};



#endif // CONTROLSSECTION_H
