#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QDebug>
#include <QPushButton>
#include "controlssection.h"
#include "tapesection.h"
#include "codesection.h"

class MainWindow : public QMainWindow
{
Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void resizeEvent(QResizeEvent * event) override;


private:
    QWidget * centralWidget;
    QVBoxLayout * globalLayout;

    ControlsSection * controlsSection;
    TapeSection * tapeSection;
    CodeSection * codeSection;


    void setupLayout();


signals:
    void windowResized(QResizeEvent * event);



};


#endif // MAINWINDOW_H
