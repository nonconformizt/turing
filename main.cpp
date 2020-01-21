#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setFont(QFont ("Lato", 11, QFont::Normal));

    QFile Style(":/style/style.qss");
    Style.open(QFile::ReadOnly);
    QString stylesheet = QLatin1String(Style.readAll());
    a.setStyleSheet(stylesheet);

    MainWindow w;
    w.show();

    return a.exec();
}
