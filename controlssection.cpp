#include "controlssection.h"


ControlsSection::ControlsSection(QWidget *parent) : QFrame(parent)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    centralLayout = new QHBoxLayout(this);
    centralLayout->setAlignment(Qt::AlignCenter);
    centralLayout->setSpacing(25);
    centralLayout->setContentsMargins(0, 0, 0, 0);


    inputPanel = new InputPanel(this);
    centralLayout->addWidget(inputPanel);

    buttonPanel = new ButtonPanel(this);
    centralLayout->addWidget(buttonPanel);

    QLabel * tmp3 = new QLabel("<SPEED>", this);
    centralLayout->addWidget(tmp3);


}


QSize ControlsSection::sizeHint() const
{
    return QSize(0, 52);
}

