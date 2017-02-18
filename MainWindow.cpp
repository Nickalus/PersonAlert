#include "MainWindow.hpp"

MainWindow::MainWindow(QScreen * screen) :mPipeline(new Pipeline)
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

  mButton = new QPushButton("&Download", this);
  mPipeline->CreatePipeline();
}

void MainWindow::ConnectSignals()
{
  connect(mButton, &QPushButton::released, mPipeline, &Pipeline::Start);
}
