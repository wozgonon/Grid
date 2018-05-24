
#include <iostream>
#include "QtGrid.hpp"
#include "Window.hpp"

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QScrollArea>


//
//  A simple model for demonstration that just provides a multiplication table.
//

class TsvModel : public Model {
  std::vector<std::vector<std::string> >  m_rows;
  unsigned m_width;
public:
  TsvModel ();
  virtual unsigned    rows         () { return m_rows.size (); }
  virtual unsigned    columns      () { return m_width; }
  virtual std::string getCellValue (const Cell& cell) {
    const unsigned xx = cell.xx ();
    const unsigned yy = cell.yy ();
    const std::vector<std::string> cols = m_rows [yy];
    return xx < cols.size () ? cols [xx] : "";
  }
  void add (const std::string& line) {
    const unsigned len = line.size ();
    if (len == 0) {
      return;
    }
    std::vector<std::string>   cols;
    unsigned pp = 0;
    for (unsigned xx = 0; xx < len; ++ xx) {
      const char ch = line [xx];
      if (ch == '\t') {
	const std::string token = line.substr (pp, xx-pp);
	cols.push_back (token);
	++ xx;
	pp = xx;
	std::cerr << "Token: " << token << std::endl;
      }
    }
    const std::string token = line.substr (pp, len-pp);
    cols.push_back (token);
    std::cerr << "Token: " << token << std::endl;
    m_width = m_width < cols.size () ? cols.size () : m_width;
    m_rows.push_back (cols);
  }
};

TsvModel::TsvModel () : m_width (0)
{
}


extern int main (int argc, char**argv)
{
  std::cerr << "Running: " << argv[0] << std::endl;

  TsvModel model;
  std::string                line;

  std::cerr << "Reading TSV from stdin " << std::endl;
  while(!std::cin.eof()) {
    std::getline(std::cin, line);
    model.add (line);
  }

  std::cerr << "Finished reading TSV from stdin " << std::endl;

  QApplication app(argc, argv);

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
