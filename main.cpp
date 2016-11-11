#include "MainWindow.hpp"
#include <QApplication>

int main(int argc, char * argv[])
{
  QApplication app(argc, argv);
  
  MainWindow * window = new MainWindow(app.primaryScreen());

  window->show();
  
  app.exec();
}
