#ifndef CELL_H
#define CELL_H

#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>
#include <QStyleOption>
#include <QPainter>


class Cell : public QFrame
{
Q_OBJECT

private:
    int index;
    int data;
    QVBoxLayout * layout;
    QLabel * label;

    void setupLayout();

public:
    explicit Cell(int index, QWidget *parent = nullptr);
    QSize sizeHint() const override;


signals:


public slots:


};

#endif // CELL_H
