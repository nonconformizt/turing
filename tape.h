#ifndef TAPE_H
#define TAPE_H

#include <QWidget>
#include <QApplication>
#include <QLineEdit>
#include <QFrame>
#include <QLabel>
#include <QHBoxLayout>
#include <QKeyEvent>
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

    int getNewTapePosition(int cellIndex);

    void setupTapeContainer();


public:
    explicit Tape(QWidget *parent = nullptr);
    QSize sizeHint() const override;
    void resizeEvent(QResizeEvent* event) override;



signals:


public slots:


};



#endif // TAPE_H
