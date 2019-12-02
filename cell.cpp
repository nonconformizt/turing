#include "cell.h"



Cell::Cell(int index, QWidget *parent) : QFrame(parent)
{
    this->index = index;
    setupLayout();

    label = new QLabel(QString::number(index));
    layout->addWidget(label);
}


void Cell::setupLayout()
{
    layout = new QVBoxLayout(this);
    layout->setMargin(0);
    layout->setAlignment(Qt::AlignCenter);
    this->setLayout(layout);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}


QSize Cell::sizeHint() const
{
    return QSize(70, 70);
}
