#include "tape.h"




Tape::Tape(QWidget * parent) : QFrame(parent)
{

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    setupTapeContainer();

    cells = new QVector<Cell *>(CELLS_N);
    for (int i = 0; i < cells->size(); i++)
    {
        (*cells)[i] = new Cell(i, tapeContainer);
        tapeContainerLayout->addWidget(cells->at(i));
    }

}


int Tape::getNewTapePosition(int cellIndex)
{
    int tapeBeforeCellLen = cellIndex * 70;
    int winWidth = this->window()->size().width();
    int pos = tapeBeforeCellLen - 70/2 + winWidth/2;

    return pos;
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


QSize Tape::sizeHint() const
{
    return QSize(0, 70);
}


void Tape::resizeEvent(QResizeEvent* event)
{
    qInfo() << "Window size: " << event->size().width() << "x" << event->size().height();

    QFrame::resizeEvent(event);
}




