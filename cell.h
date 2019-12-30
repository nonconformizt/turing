#ifndef CELL_H
#define CELL_H

#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>



class Cell : public QFrame
{
Q_OBJECT

private:
    int index;
    QChar data;
    QVBoxLayout * layout;
    QLabel * label;

    void setupLayout();

public:
    explicit Cell(int index, QWidget *parent = nullptr);
    QSize sizeHint() const override;

    void set(QChar val) { label->setText(val); }
    QChar get() { return (data == ' ') ? '_' : data; }


signals:


public slots:


};

#endif // CELL_H
