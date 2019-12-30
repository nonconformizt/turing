#include "machine.h"



Machine::Machine(Tape * tape, ControlsSection * controls)
{
    this->tape = tape;
    this->controls = controls;

    tape->clear();
}


void Machine::compile(QString code)
{
    try {
        clear();

        QStringList lines = code.split('\n', QString::SkipEmptyParts);

        QString initialName;
        if (lines[0].indexOf("init: ") == 0)
            initialName = lines[0].mid(6, lines[0].length());
        else
            throw "No initial state provided.";

        qInfo() << "Init: " << initialName;


        QStringList acceptNames;
        if (lines[1].indexOf("accept: ") == 0)
        {
            QString tmp = lines[1].mid(8, lines[1].length());
            acceptNames = tmp.split(',', QString::SkipEmptyParts);
            for (auto & acname : acceptNames)
                acname = acname.trimmed();
            if (acceptNames.size() == 0)
                throw "No accept states provided.";
        }
        else
            throw "No accept states provided.";

        qInfo() << "Accept: " << acceptNames.join(',');

        for (int i = 2, len = lines.length(); i < len; i+=2)
        {
            if (i + 1 == len)
                throw "Syntax error in line " + QString::number(i+1) + ": no transition described.";

            QStringList condition = lines[i].split(',');
            if (condition.size() != 2)
                throw "Syntax error in line " + QString::number(i+1) + ": incorrect condition.";

            QString currStateName = condition[0];

            // get condition character
            if (condition[1].length() != 1)
                throw "Syntax error in line " + QString::number(i+1) + ": invalid condition character.";

            char conditionChar = condition[1].at(0).toLatin1();


            State * currState = findOrCreateState(currStateName);

            QStringList transition = lines[i+1].split(',');
            if (transition.size() != 3)
                throw "Syntax error in line " + QString::number(i+2) + ": incorrect transition.";

            if (transition[1].length() != 1 || (transition[2] != "<" && transition[2] != "-" && transition[2] != ">"))
                throw "Syntax error in line " + QString::number(i+2) + ": incorrect transition.";

            Transition currTransition(
                        findOrCreateState(transition[0]),
                        transition[1][0].toLatin1(),
                        transition[2][0].toLatin1()
                    );

            currState->rules.insert(conditionChar, currTransition);
        }

        setAccepting(acceptNames);
        setInitial(initialName);

        for (const auto & state: states)
            state->print();

        compiled = true;

        QMessageBox msgBox;
        msgBox.setText("Compiled!");
        msgBox.setInformativeText("Program compiled successfully!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();

    } catch (QString e) {

        compiled = false;
        clear();

        QMessageBox errBox;
        errBox.setText("Complation error!");
        errBox.setInformativeText(e);
        errBox.setStandardButtons(QMessageBox::Ok);
        errBox.exec();
    }

    run();
}


void Machine::run()
{
    current = initial;
    step();
}


void Machine::pause()
{

}


void Machine::stop()
{

}


void Machine::step()
{
    qInfo("Step!");

    if (current->isAccepting) {
        qInfo() << "Accepted!";
        stop();
        return;
    }

    // check rules for curr state

    QChar currVal = tape->read();

    Transition *tr = current->findTransition(currVal);

    if (tr == nullptr) { // not found
        qInfo() << "Rejected!";
        stop();
        return;
    }

    tape->write(tr->symbol);
    tape->shift(tr->shift);

    current = tr->next;

    stepsCount++;

    step();
}


void Machine::clear()
{
    // delete all states
    while(!states.empty())
    {
        State * tmp = states.first();
        states.removeFirst();
        delete tmp;
    }

    initial = nullptr;
    current = nullptr;
    compiled = false;

    stepsCount = 0;
}


State * Machine::findOrCreateState(QString name)
{
    for (State * state: states)
        if (state->name == name)
            return state;

    auto state = new State(name);
    states.append(state);
    return state;
}


State * Machine::findState(QString name)
{
    for (State * state: states)
        if (state->name == name)
            return state;

    return nullptr;
}


void Machine::setAccepting(QStringList names)
{
    State * tmp;
    for (const auto & name : names)
    {
        tmp = findState(name);
        if (tmp == nullptr)
            throw "Syntax error: incorrect accepting states!";
        tmp->isAccepting = true;
    }
}


void Machine::setInitial(QString name)
{
    initial = findState(name);
    if (initial == nullptr)
        throw "Syntax error: incorrect initial state!";
}




