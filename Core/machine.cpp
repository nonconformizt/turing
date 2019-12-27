#include "machine.h"



Machine::Machine()
{
    // initialize States??
}


void Machine::compile(QString code)
{
    clear();

    QStringList lines = code.split('\n', QString::SkipEmptyParts);

    QString initialName;
    if (lines[0].indexOf("init: ") == 0)
        initialName = lines[0].mid(6, lines[0].length());
    else
        throw "No initial state provided";

    qInfo() << "Init: " << initialName;


    QStringList acceptNames;
    if (lines[1].indexOf("accept: ") == 0)
    {
        QString tmp = lines[1].mid(8, lines[1].length());
        acceptNames = tmp.split(',', QString::SkipEmptyParts);
        for (auto & acname : acceptNames)
            acname = acname.trimmed();
        if (acceptNames.size() == 0)
            throw "No accept states provided!";
    }
    else
        throw "No accept states provided!";

    qInfo() << "Accept: " << acceptNames.join(',');

    for (int i = 2, len = lines.length(); i < len; i++)
    {
        //
    }

}


void Machine::clear()
{
    while(!states.empty())
    {
        State * tmp = states.first();
        states.removeFirst();
        delete tmp;
    }
}
