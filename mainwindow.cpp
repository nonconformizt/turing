#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupLayout();

    controlsSection = new ControlsSection(centralWidget);
    globalLayout->addWidget(controlsSection);

    tapeSection = new TapeSection(centralWidget);
    globalLayout->addWidget(tapeSection);

    codeSection = new CodeSection(centralWidget);
    // no layout

    connect(this, &MainWindow::windowResized, this->codeSection, &CodeSection::resize);

    machine = new Machine(tapeSection->tape, tapeSection, controlsSection);
    connect(codeSection, &CodeSection::compileRequested, machine, &Machine::compile);
}



MainWindow::~MainWindow()
{
}


void MainWindow::resizeEvent(QResizeEvent * event)
{
    emit windowResized(event);
    QMainWindow::resizeEvent(event);
}


void MainWindow::setupLayout()
{
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    centralWidget->showFullScreen();

    globalLayout = new QVBoxLayout(centralWidget);
    globalLayout->setMargin(0);
    globalLayout->setSpacing(0);
    globalLayout->setContentsMargins(0, 0, 0, 80);
    centralWidget->setLayout(globalLayout);

    resize(900, 600);
}


