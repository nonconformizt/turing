#ifndef BUTTONPANEL_H
#define BUTTONPANEL_H


#include <QFrame>
#include <QHBoxLayout>
#include <QPushButton>
#include <QStyleOption>
#include <QPainter>




class ButtonPanel : public QFrame
{
Q_OBJECT

private:
    QHBoxLayout * layout;

    QPushButton * makeButton(QString name);


public:
    QPushButton * play, * pause, * stop, * skip;

    explicit ButtonPanel(QWidget *parent = nullptr);
    QSize sizeHint() const override;


signals:


public slots:

};

#endif // BUTTONPANEL_H
