#include "tapesection.h"



TapeSection::TapeSection(QWidget *parent) : QWidget(parent)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    centralLayout = new QVBoxLayout(this);
    centralLayout->setMargin(0);
    centralLayout->setAlignment(Qt::AlignVCenter);

    stateIndicator = new QLabel("State: none", this);
    stateIndicator->setAlignment(Qt::AlignCenter);
    centralLayout->addWidget(stateIndicator);

    tape = new Tape(this);
    centralLayout->addWidget(tape);

    carriage = new QLabel(this);
    QPixmap pix(":/img/res/triangle.png");
    carriage->setPixmap(pix.scaled(32, 32, Qt::KeepAspectRatio));
    carriage->setAlignment(Qt::AlignCenter);
    centralLayout->addWidget(carriage);

    stepsIndicator = new QLabel("Steps: 0", this);
    stepsIndicator->setAlignment(Qt::AlignRight);
    centralLayout->addWidget(stepsIndicator);


}


QSize TapeSection::sizeHint() const
{
    return QSize(0, 0);
}

