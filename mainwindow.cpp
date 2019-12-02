#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupLayout();

    controlsSection = new ControlsSection(centralWidget);
    globalLayout->addWidget(controlsSection);

    tapeSection = new TapeSection(centralWidget);
    globalLayout->addWidget(tapeSection);

}


MainWindow::~MainWindow()
{
}


void MainWindow::setupLayout()
{
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    centralWidget->showFullScreen();

    globalLayout = new QVBoxLayout(centralWidget);
    globalLayout->setMargin(0);
    globalLayout->setSpacing(0);
    centralWidget->setLayout(globalLayout);

    resize(800, 400);
}

