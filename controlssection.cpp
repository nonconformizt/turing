#include "controlssection.h"


ControlsSection::ControlsSection(QWidget *parent) : QWidget(parent)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    centralLayout = new QHBoxLayout(this);
    centralLayout->setAlignment(Qt::AlignCenter);
    centralLayout->setSpacing(100);
    centralLayout->setContentsMargins(50, 0, 50, 0);


    QLabel * tmp1 = new QLabel("<INPUT>", this);
    centralLayout->addWidget(tmp1);

//    QLabel * tmp2 = new QLabel("<CONTROLS>", this);
//    centralLayout->addWidget(tmp2);

    buttonPanel = new ButtonPanel(this);
    centralLayout->addWidget(buttonPanel);

    QLabel * tmp3 = new QLabel("<SPEED>", this);
    centralLayout->addWidget(tmp3);


}


QSize ControlsSection::sizeHint() const
{
    return QSize(0, 50);
}

