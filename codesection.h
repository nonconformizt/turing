#ifndef CODESECTION_H
#define CODESECTION_H

#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QResizeEvent>
#include <QDebug>


class CodeSection : public QFrame
{
Q_OBJECT


QRect currentGeometry;
int maximizedY;
int minimizedY;

int movingOffset;
bool wasMoved = false;

bool isExpanded = false;


void mousePressEvent(QMouseEvent * event) override;
void mouseReleaseEvent(QMouseEvent * event) override;
void mouseMoveEvent(QMouseEvent * event) override;

void toggle();

public:
    explicit CodeSection(QWidget *parent = nullptr);
    QSize sizeHint() const override;


signals:


public slots:

    void resize (QResizeEvent * ev);


};

#endif // CODESECTION_H
