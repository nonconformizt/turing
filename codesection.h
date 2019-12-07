#ifndef CODESECTION_H
#define CODESECTION_H

#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QResizeEvent>
#include <QPropertyAnimation>
#include <QDebug>


class CodeSection : public QFrame
{
Q_OBJECT

const int fullHeight = 550;
const int visibleHeight = 120;
const int width = 600;

//QRect currentGeometry;
QPoint coords;
QSize size;

int maximizedY;
int minimizedY;

int movingOffset;
bool wasMoved = false;

bool isExpanded = false;

QPropertyAnimation * animation;

void mousePressEvent(QMouseEvent * event) override;
void mouseReleaseEvent(QMouseEvent * event) override;
void mouseMoveEvent(QMouseEvent * event) override;

void toggle();
void animateTo(int y);
void minimize();
void maximize();

public:
    explicit CodeSection(QWidget *parent = nullptr);
    QSize sizeHint() const override;


signals:


public slots:
    void resize (QResizeEvent * ev);


};

#endif // CODESECTION_H
