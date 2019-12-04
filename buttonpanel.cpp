#include "buttonpanel.h"




ButtonPanel::ButtonPanel(QWidget *parent) : QFrame(parent)
{
    layout = new QHBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->setAlignment(Qt::AlignCenter);

    play  = makeButton("play");
    pause = makeButton("pause");
    stop  = makeButton("stop");
    skip  = makeButton("skip");

    setLayout(layout);

}


QPushButton * ButtonPanel::makeButton(QString name)
{
    auto btn = new QPushButton(QIcon(":/img/res/" + name + ".png"), "", this);

    btn->setObjectName(name);
    btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btn->setIconSize(QSize(35, 35));
    layout->addWidget(btn);

    return btn;
}


QSize ButtonPanel::sizeHint() const
{
    return QSize(56 * 4, 56);
}


