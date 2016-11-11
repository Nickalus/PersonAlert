#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QScreen>

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
};

#endif
