#include <QApplication>

#include "MainWindow.hpp"

int main(int argc, char * argv[])
{
  QApplication app(argc, argv);
  gst_init(NULL, NULL);
  
  MainWindow * window = new MainWindow(app.primaryScreen());

  window->show();
  
  app.exec();
}
