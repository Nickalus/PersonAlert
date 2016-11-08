#include "MainWindow.hpp"

int main(int argc, char * argv[])
{
  QGuiApplication app(argc, argv);
  
  MainWindow * window = new MainWindow(app.primaryScreen());
  
  app.exec()
}
