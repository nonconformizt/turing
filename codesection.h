#ifndef CODESECTION_H
#define CODESECTION_H

#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>
#include <QResizeEvent>
#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>
#include <QDebug>
#include <QPushButton>
#include "CodeEditor/codeeditor.h"


class CodeSection : public QFrame
{
Q_OBJECT

private:
    const int fullHeight = 550;
    const int visibleHeight = 120;
    const int fullWidth = 600;

    QPoint coords;
    QSize size;

    int maximizedY;
    int minimizedY;

    int movingOffset;
    bool wasMoved = false;

    bool isExpanded = false;

    QPropertyAnimation * animation;
    QGraphicsDropShadowEffect * dropShadow;

    QVBoxLayout * layout;
    QPushButton * handle;
    QPushButton * compileBtn;
    CodeEditor * editor;

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
    void compileRequested(QString text);


public slots:
    void resize (QResizeEvent * ev);
    void compileBtnPressed();


};

#endif // CODESECTION_H
