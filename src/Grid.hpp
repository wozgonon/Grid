#ifndef __GRID_HPP__
#define __GRID_HPP__

#include <vector>
#include <string>
#include <string>

class Cell {
  unsigned m_xx;
  unsigned m_yy;
public:
  Cell (unsigned xx, unsigned yy) : m_xx(xx), m_yy(yy) {}
  Cell () : Cell (0, 0) {}

  unsigned xx () const { return m_xx; }
  unsigned yy () const { return m_yy; }
 
};

class Model {
public:
  virtual unsigned    rows         () = 0;
  virtual unsigned    columns      () = 0;
  virtual std::string getCellValue (const Cell& cell) = 0;
};

class Axis {
  std::vector<unsigned> m_position;
  const unsigned m_default_width_in_pixels;
public:

  unsigned size () { return m_position.size (); }
  unsigned total_pixels () const;
  unsigned operator [] (unsigned ii) const {
    return m_position [ii];
  }
  unsigned span (unsigned position) const;
  
  Axis (unsigned size, unsigned pixels);

  unsigned findPosition (unsigned pixel);
};

class Grid {
public:
  Model& m_model;
  Axis   m_columns;
  Axis   m_rows;
  Cell   m_currentCell;
  
  Grid (Model& model);
};


#endif
  
