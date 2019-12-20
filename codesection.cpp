#include "codesection.h"




CodeSection::CodeSection(QWidget *parent) : QFrame(parent)
{
    maximizedY = window()->height() - fullHeight;
    minimizedY = window()->height() - visibleHeight;

    coords = QPoint((window()->width() - width) / 2, minimizedY);
    size = QSize(width, fullHeight);

    setGeometry(QRect(coords, size));

    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(350);
    animation->setEasingCurve(QEasingCurve::InQuad);



    layout = new QVBoxLayout(this);
    //layout->setMargin(0);
    layout->setSpacing(0);
    layout->setAlignment(Qt::AlignCenter);

    editor = new CodeEditor(this);
    layout->addWidget(editor);


}


void CodeSection::resize(QResizeEvent * ev)
{
    coords.setX((ev->size().width() - width) / 2);

    minimizedY = ev->size().height() - visibleHeight;
    maximizedY = ev->size().height() - fullHeight;

    coords.setY((isExpanded) ? maximizedY : minimizedY);

    setGeometry(QRect(coords, size));
}


void CodeSection::mousePressEvent(QMouseEvent *event)
{
    // start dragging
    if(event->buttons() & Qt::LeftButton)
        movingOffset = event->y();
}


void CodeSection::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        wasMoved = true;
        QPoint nextPos = mapToParent(QPoint(0, event->y() - movingOffset));

        if (nextPos.y() <= minimizedY && nextPos.y() >= maximizedY)
        {
            coords = nextPos;
            setGeometry(QRect(coords, size));
        }
    }
}


void CodeSection::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() & Qt::LeftButton)
    {
        // end dragging
        if (!wasMoved)
            toggle();
        else if (coords.y() < (minimizedY + maximizedY) / 2)
            maximize();
        else
            minimize();

        wasMoved = false;
    }
}


void CodeSection::toggle()
{
    if (isExpanded)
        minimize();
    else
        maximize();
}


void CodeSection::minimize()
{
    isExpanded = false;
    animateTo(minimizedY);
}


void CodeSection::maximize()
{
    isExpanded = true;
    animateTo(maximizedY);
}


void CodeSection::animateTo(int y)
{
    coords.setY(y);
    animation->setStartValue(geometry());
    animation->setEndValue(QRect(coords, size));
    animation->start();
}


QSize CodeSection::sizeHint() const
{
    return size;
}


