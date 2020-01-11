#include "machine.h"



Machine::Machine(Tape * tape, TapeSection * tapeSection, ControlsSection * controls)
{
    this->tape = tape;
    this->tapeSection = tapeSection;
    this->controls = controls;

    connect(this->controls->buttonPanel->play, SIGNAL(released()), this, SLOT(run()));
    connect(this->controls->buttonPanel->pause, SIGNAL(released()), this, SLOT(pause()));
    connect(this->controls->buttonPanel->stop, SIGNAL(released()), this, SLOT(stop()));
    connect(this->controls->speedSlider, SIGNAL(speedChanged(int)), this, SLOT(changeSpeed(int)));
    connect(this->controls, SIGNAL(inputLoaded(QString)), this, SLOT(input(QString)));

    changeSpeed(speed);

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

    } catch (QString e) {

        compiled = false;
        clear();
        QMessageBox::critical(nullptr, "Complation error!", e);
    }
}


void Machine::run()
{
    if (paused)
    {
        // resume

        paused = false;
        step();
    }
    else
    {
        if (! compiled)
            QMessageBox::warning(nullptr, "No program!", "You have not comiled any program or the program was not correct.");
        else if (! tape->wasLoaded)
            QMessageBox::warning(nullptr, "No initilal data!", "No data was loaded to the tape. Load some data first.");
        else {
            current = initial;
            stepsCount = 0;
            step();
        }
    }
}


void Machine::pause()
{
    paused = true;
}


void Machine::stop()
{
    tape->wasLoaded = false;
}


void Machine::step()
{
    if (paused)
        return;

    if (current->isAccepting) {
        QMessageBox::information(nullptr, "Accepted!", "Accepted!");
        stop();
        return;
    }

    // check rules for curr state
    QChar currVal = tape->read();

    Transition *tr = current->findTransition(currVal);

    if (tr == nullptr) { // not found
        QMessageBox::information(nullptr, "Rejected!", "Rejected!");
        stop();
        return;
    }

    tape->write(tr->symbol);
    tape->shift(tr->shift);

    current = tr->next;
    tapeSection->setState(current->name);

    stepsCount++;
    tapeSection->setSteps(stepsCount);

    QTimer::singleShot(int(stepDuration * 2), this, SLOT(step()));
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
    tapeSection->setSteps(stepsCount);
}


void Machine::input(QString inp)
{
    tape->load(inp);
}


void Machine::changeSpeed(int value)
{
    speed = value;
    stepDuration = maxStepDuration / speed;
    tape->setAnimationDuration((int) stepDuration);
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




