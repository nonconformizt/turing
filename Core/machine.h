#ifndef MACHINE_H
#define MACHINE_H

#include <QObject>
#include <QMap>
#include <QDebug>
#include <QTimer>
#include <QMessageBox>
#include <QPushButton>
#include "tape.h"
#include "controlssection.h"
struct State;



struct Transition
{
    State * next;
    QChar symbol;
    short shift; // -1, 0 or 1

    Transition(State * next, QChar symbol, char shift)
    {
        this->next = next;
        this->symbol = symbol;
        if (shift == '<')
            this->shift = -1;
        else if (shift == '>')
            this->shift = +1;
        else this->shift = 0;
    }

    Transition() {}
};


struct State
{
    QString name;
    bool isAccepting = false;
    QMap<QChar, Transition> rules;


    State(QString name)
    {
        this->name = name;
    }

    void print() const
    {
        qInfo() << "> State " << name;

        if (isAccepting)
            qInfo() << "=Accepting=";

        qInfo() << "Rules: ";
        for (auto const & rule : rules.toStdMap())
        {
            qInfo() << "Char: " << rule.first <<
                       " Goto: " << rule.second.next->name << ", " <<
                       rule.second.symbol << ", " << rule.second.shift;
        }
    }

    Transition * findTransition(QChar val)
    {
        if (rules.contains(val))
            return &rules[val];
        else
            return nullptr;
    }
};



class Machine : public QObject
{
Q_OBJECT

private:
    bool compiled = false;
    QVector<State *> states;
    State * initial;
    State * current;
    int stepsCount = 0;

    Tape * tape;
    ControlsSection * controls;

    double speed = 10;
    const double maxStepDuration = 5000;
    double stepDuration = maxStepDuration / speed;

    void clear();
    State * findOrCreateState(QString name);
    State * findState(QString name);
    void setAccepting(QStringList names);
    void setInitial(QString name);


public:
    Machine(Tape * tape, ControlsSection * controls);


public slots:
    void compile(QString code);
    void run();
    void step();
    void pause();
    void stop();
    void input(QString inp);
    void changeSpeed(int value);

};


#endif // MACHINE_H


