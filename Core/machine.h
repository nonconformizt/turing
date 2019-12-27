#ifndef MACHINE_H
#define MACHINE_H

#include <QObject>
#include <QMap>
#include <QDebug>

struct Transition;

struct State {
    bool isAccepting;
    QMap<char, Transition> rules;
};

struct Transition {
    State * next;
    char symbol;
    short shift; // -1, 0 or 1
};



class Machine : public QObject
{
Q_OBJECT

private:
    QVector<State *> states;
    State * initial;

    void clear();


public:
    Machine();


signals:


public slots:
    void compile(QString code);


};


#endif // MACHINE_H


