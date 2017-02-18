#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QScreen>
#include <QPushButton>

#include "Pipeline.hpp"

class MainWindow : public QMainWindow
{
  Q_OBJECT
  
  public:
    MainWindow(QScreen *);
    ~MainWindow();
    
  private:
    void CreateGUI(QScreen *);
    void ConnectSignals();
    
  private:
    Pipeline * mPipeline;
    QPushButton * mButton;
};

#endif
