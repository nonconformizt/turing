#ifndef MACHINE_H
#define MACHINE_H

#include <QObject>
#include <QMap>
#include <QDebug>
#include <QException>


struct State;

struct Transition
{
    State * next;
    char symbol;
    short shift; // -1, 0 or 1

    Transition(State * next, char symbol, char shift)
    {
        this->next = next;
        this->symbol = symbol;
        if (shift == '<')
            this->shift = -1;
        else if (shift == '>')
            this->shift = +1;
        else this->shift = 0;
    }
};


struct State
{
    QString name;
    bool isAccepting = false;
    QMap<char, Transition> rules;


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
};



class Machine : public QObject
{
Q_OBJECT

private:
    QVector<State *> states;
    State * initial;

    void clear();
    State * findOrCreateState(QString name);


public:
    Machine();


signals:


public slots:
    void compile(QString code);


};


#endif // MACHINE_H


