#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QDebug>
#include <QPushButton>
#include "controlssection.h"
#include "tapesection.h"

class MainWindow : public QMainWindow
{
Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    QWidget * centralWidget;
    QVBoxLayout * globalLayout;

    ControlsSection * controlsSection;
    TapeSection * tapeSection;


    void setupLayout();


};


#endif // MAINWINDOW_H
