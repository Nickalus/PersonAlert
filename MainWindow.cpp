#include "MainWindow.hpp"

MainWindow::MainWindow(QScreen * screen) 
{
  CreateGUI(screen);
  ConnectSignals();
}

MainWindow::~MainWindow()
{

}

void MainWindow::CreateGUI(QScreen * screen)
{
  //Create the GUI based off screen size
    this->resize(screen->availableSize());
}

void MainWindow::ConnectSignals()
{
}
