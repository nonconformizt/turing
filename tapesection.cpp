#include "tapesection.h"
#include <QLabel>
#include <QPushButton>



TapeSection::TapeSection(QWidget *parent) : QWidget(parent)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    centralLayout = new QVBoxLayout(this);
    centralLayout->setMargin(0);
    centralLayout->setAlignment(Qt::AlignVCenter);

    QLabel * stateIndicator = new QLabel("State: something", this);
    stateIndicator->setAlignment(Qt::AlignCenter);
    centralLayout->addWidget(stateIndicator);

    tape = new Tape(this);
    centralLayout->addWidget(tape);

    QLabel * stepsIndicator = new QLabel("Steps: 1488", this);
    stepsIndicator->setAlignment(Qt::AlignRight);
    centralLayout->addWidget(stepsIndicator);

}


QSize TapeSection::sizeHint() const
{
    return QSize(0, 0);
}

