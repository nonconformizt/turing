#ifndef INPUTPANEL_H
#define INPUTPANEL_H

#include <QFrame>
#include <QValidator>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>


class InputPanel : public QFrame
{
Q_OBJECT

private:
    QHBoxLayout * layout;
    QLineEdit * input;
    QPushButton * loadBtn;



public:
    explicit InputPanel(QWidget *parent = nullptr);
    QSize sizeHint() const override;

signals:

public slots:


};


#endif // INPUTPANEL_H
