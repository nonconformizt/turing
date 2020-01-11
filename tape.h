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
#include <QPicture>
#include "cell.h"



class Tape : public QFrame
{
Q_OBJECT


private:
    const int CELLS_N = 100;
    int activeCell = CELLS_N / 2;
    QVector<Cell *> * cells;
    QLabel * carriage;
    QWidget * tapeContainer;
    QHBoxLayout * tapeContainerLayout;

    QPropertyAnimation * animation;

    int getNewPosition(int cellIndex);
    void changePosition(int cellIndex, bool animation = true);
    void setCellValue(int cellIndex, QChar value);
    QChar getCellValue(int cellIndex);

    void setupTapeContainer();
    void setupAnimation();


public:
    explicit Tape(QWidget *parent = nullptr);
    QSize sizeHint() const override;
    void resizeEvent(QResizeEvent* event) override;

    void clear();
    void forward() { changePosition(activeCell + 1); }
    void back() { changePosition(activeCell - 1); }
    void shift(short shift) { changePosition(activeCell + shift); }
    void write(QChar val) { setCellValue(activeCell, val); }
    QChar read() { return getCellValue(activeCell); }
    void setAnimationDuration(int ms) { animation->setDuration(ms); }
    void load(QString inp);
    bool wasLoaded = false;

};



#endif // TAPE_H
