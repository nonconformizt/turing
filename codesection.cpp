#include "codesection.h"




CodeSection::CodeSection(QWidget *parent) : QFrame(parent)
{
    maximizedY = window()->height() - 550;
    minimizedY = window()->height() - 120;

    currentGeometry = QRect(
                    (window()->width() - 600) / 2, // x
                    minimizedY, // y
                    600, // width
                    600 - 50 // height
                );
    setGeometry(currentGeometry);


    // temp
    setStyleSheet("background-color: #000; border-top-left-radius: 10px; border-top-right-radius: 10px;");


}


void CodeSection::resize(QResizeEvent * ev)
{
    currentGeometry.setX((ev->size().width() - 600) / 2);
    currentGeometry.setWidth(600);
    minimizedY = ev->size().height() - 120;

    if (!isExpanded)
        currentGeometry.setY(minimizedY);

    setGeometry(currentGeometry);
}


void CodeSection::mousePressEvent(QMouseEvent *event)
{
    // start dragging
    movingOffset = event->y();
}


void CodeSection::mouseReleaseEvent(QMouseEvent *event)
{
    // mouse was not moved
    if (!wasMoved)
        toggle();

    wasMoved = false;

}


void CodeSection::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        wasMoved = true;
        this->move(mapToParent(QPoint(0, event->y() - movingOffset)));
    }
}


void CodeSection::toggle()
{
    //! TODO: animation

    isExpanded = !isExpanded;

    if (isExpanded)
        currentGeometry.setY(maximizedY);
    else
        currentGeometry.setY(minimizedY);

    setGeometry(currentGeometry);
}


QSize CodeSection::sizeHint() const
{
    return currentGeometry.size();
}


