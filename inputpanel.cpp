#include "inputpanel.h"


InputPanel::InputPanel(QWidget *parent) : QFrame(parent)
{
    layout = new QHBoxLayout(this);
    layout->setSpacing(0);
    layout->setMargin(0);

    input = new QLineEdit(this);
    layout->addWidget(input);

    loadBtn = new QPushButton("Load", this);
    loadBtn->setCursor(Qt::CursorShape::PointingHandCursor);
    layout->addWidget(loadBtn);

    setLayout(layout);

    setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
}


QSize InputPanel::sizeHint() const
{
    return QSize(200, 52);
}

