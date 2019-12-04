#ifndef TAPE_H
#define TAPE_H

#include <QWidget>
#include <QApplication>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QResizeEvent>
#include <QPropertyAnimation>
#include <QDebug>
#include "cell.h"



class Tape : public QFrame
{
Q_OBJECT


private:
    const int CELLS_N = 100;
    int activeCell = CELLS_N / 2;
    QVector<Cell *> * cells;
    QWidget * tapeContainer;
    QHBoxLayout * tapeContainerLayout;

    QPropertyAnimation * animation;

    int getNewPosition(int cellIndex);
    void changePosition(int cellIndex, bool animation = true);
    void setCellValue(int cellIndex, int value);

    void setupTapeContainer();
    void setupAnimation();


public:
    explicit Tape(QWidget *parent = nullptr);
    QSize sizeHint() const override;
    void resizeEvent(QResizeEvent* event) override;



signals:


public slots:


};



#endif // TAPE_H