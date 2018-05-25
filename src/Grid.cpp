#include "Grid.hpp"
#include <iostream>

const unsigned default_column_width = 100;
const unsigned default_row_height = 50;

Grid::Grid (Model& model) : m_model (model), m_columns (model.columns (), default_column_width), m_rows (model.rows (), default_row_height)
{
}

Axis::Axis (unsigned count, unsigned width_in_pixels) : m_default_width_in_pixels (width_in_pixels)
{
  for (int ii = 0; ii < count; ++ ii) {
    const unsigned pixels = (ii+1) * width_in_pixels;
    this->m_position.push_back (pixels);
    const unsigned xx = m_position [ii];
    std::cerr << "Axis: " << ii << " " << xx << std::endl;

  }
}

unsigned Axis::findPosition (unsigned pixel)
{
  unsigned total_pixels = 0;
  const unsigned len = m_position.size ();
  if (len == 0) {
    return 0;
  }
  for (int ii = 0; ii < len; ++ ii) {
    total_pixels = m_position [ii];
    if (pixel < total_pixels) {
      return ii;
    }
  }
  return len - 1;  // Out of bound
}

unsigned Axis::total_pixels () const {
  const unsigned size = m_position.size ();
  if (size == 0) {
    return 0;
  }
  return m_position [size - 1];
}


unsigned Axis::span (unsigned position) const
{
  const unsigned start = (*this) [position];
  const unsigned end   = m_position [position];

  std::cerr << "span: " << position << " size=" << m_position.size () << " start=" << start << " end=" << end << std::endl;
  return end - start;
}
