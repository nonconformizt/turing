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

public:
    QHBoxLayout * layout;
    QLineEdit * input;
    QPushButton * loadBtn;

    explicit InputPanel(QWidget *parent = nullptr);
    QSize sizeHint() const override;

};


#endif // INPUTPANEL_H
