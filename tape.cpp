#include "tape.h"



Tape::Tape(QWidget * parent) : QFrame(parent)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    setupTapeContainer();
    setupAnimation();

    carriage = new QLabel("hello", this);
    QPicture pic;
    pic.load(":/img/res/triangle.png");
    carriage->setPicture(pic);
    carriage->setGeometry(0, 0, 100, 100);
    carriage->show();

    cells = new QVector<Cell *>(CELLS_N);
    for (int i = 0; i < cells->size(); i++)
    {
        (*cells)[i] = new Cell(i, tapeContainer);
        tapeContainerLayout->addWidget(cells->at(i));
    }

    changePosition(CELLS_N / 2, false);

}


int Tape::getNewPosition(int cellIndex)
{
    int tapeBeforeCellLen = cellIndex * (70 + 10); // 70 is a width of cell, 10 is spacing
                                                   //! TODO: macroconstants
    int winWidth = this->window()->size().width();
    int pos = -tapeBeforeCellLen - 70/2 + winWidth/2;

    return pos;
}


void Tape::changePosition(int cellIndex, bool isAnimated)
{
    activeCell = cellIndex;

    QRect geometry = tapeContainer->geometry();
    geometry.setX(getNewPosition(cellIndex));

    if (isAnimated) {
        animation->setStartValue(tapeContainer->geometry());
        animation->setEndValue(geometry);
        animation->start();
    } else {
        tapeContainer->setGeometry(geometry);
    }

}


void Tape::setCellValue(int cellIndex, QChar value)
{
    ((*cells)[cellIndex])->set(value);
}


QChar Tape::getCellValue(int cellIndex)
{
    return ((*cells)[cellIndex])->get();
}


void Tape::setupTapeContainer()
{
    tapeContainer = new QWidget(this);
    tapeContainerLayout = new QHBoxLayout(this);
    tapeContainerLayout->setSpacing(10);
    tapeContainerLayout->setMargin(0);
    tapeContainerLayout->setAlignment(Qt::AlignLeft);

    tapeContainer->resize(CELLS_N * 90, 70);
    tapeContainer->setLayout(tapeContainerLayout);
}


void Tape::setupAnimation()
{
    animation = new QPropertyAnimation(tapeContainer, "geometry");
    animation->setEasingCurve(QEasingCurve::InCurve);
}


QSize Tape::sizeHint() const
{
    return QSize(0, 70);
}


void Tape::resizeEvent(QResizeEvent* event)
{
    // adjust size
    changePosition(activeCell, false);
    QFrame::resizeEvent(event);
}


void Tape::clear()
{
    for (int i = 0; i < CELLS_N; i++)
        setCellValue(i, '_');

    changePosition(CELLS_N / 2, false);
}


void Tape::load(QString inp)
{
    clear();
    for (int i = 0, len = inp.length(); i < len && (activeCell+i < CELLS_N); i++)
        ((*cells)[activeCell + i])->set(inp[i]);
    wasLoaded = true;
}

