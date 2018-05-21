
#include <iostream>
#include "QtGrid.hpp"
#include "Window.hpp"

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QScrollArea>



extern int main (int argc, char**argv)
{
  std::cerr << "Running: " << argv[0] << std::endl;

  //Q_INIT_RESOURCE(basicdrawing);
  
  QApplication app(argc, argv);

  SimpleModel model (10);
  Grid grid (model);

  Window window;
  QScrollArea scrollArea (&window);
  scrollArea.setHorizontalScrollBarPolicy (Qt::ScrollBarAlwaysOn);
  scrollArea.setVerticalScrollBarPolicy (Qt::ScrollBarAlwaysOn);
  scrollArea.setWidgetResizable (true);
  scrollArea.setGeometry( 10, 10, 400, 400 );
  //
  QtGrid qtGrid (grid, &scrollArea);
  scrollArea.setWidget (&qtGrid);
  scrollArea.show ();
  window.show ();
  
  return app.exec();
  return 0;
}
