#ifndef MACHINE_H
#define MACHINE_H

#include <QObject>
#include <QMap>

struct Transition;

struct State {
    bool isAccepting;
    // transitions
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

public:
    Machine();


signals:



public slots:
    void compile(QString code);


};


#endif // MACHINE_H
