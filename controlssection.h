#ifndef CONTROLSSECTION_H
#define CONTROLSSECTION_H

#include <QWidget>
#include <QHBoxLayout>


class ControlsSection : public QWidget
{
Q_OBJECT


private:
    QHBoxLayout * centralLayout;



public:
    explicit ControlsSection(QWidget *parent = nullptr);
    QSize sizeHint() const override;


signals:


public slots:


};



#endif // CONTROLSSECTION_H
