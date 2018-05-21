#include "QtGrid.hpp"
#include <QtGui/QPainter>
#include <QtGui/QMouseEvent>
#include <iostream>
#include <string>

QtGrid::QtGrid (Grid& grid, QWidget * parent) : m_grid (grid), QWidget(parent)
{
  //     antialiased = false;
//     transformed = false;
//     pixmap.load(":/images/qt-logo.png");

     setBackgroundRole(QPalette::Base);
     setAutoFillBackground(true);

}

QtGrid::~QtGrid ()
{
}


QSize QtGrid::sizeHint() const
{
  return QSize(m_grid.m_columns.total_pixels (), m_grid.m_rows.total_pixels ());
}

QSize QtGrid::minimumSizeHint() const
{
    return QSize(m_grid.m_columns.total_pixels (), m_grid.m_rows.total_pixels ());
}

void QtGrid::mousePressEvent(QMouseEvent * event)
{
  const float xx = event->x();
  const float yy = event->y();
  const unsigned col = m_grid.m_columns.findPosition (xx);
  const unsigned row = m_grid.m_rows.findPosition (yy);

  const Cell cell { col, row };
  m_grid.m_currentCell = cell;
  std::cerr << "Click: " << col << "," << row << " = " << m_grid.m_model.getCellValue (cell) << std::endl;

  //
  // TODO only repaint the last cell selected and the new one.
  //
  repaint ();
  
}

void QtGrid::paintEvent(QPaintEvent *event)
{
  //
  //  TODO only draw the impacted part of the screen
  //
  QPainter painter(this);

  //
  // Draw the vertical grid lines
  //
  const unsigned min_y = 0;
  const unsigned max_y = painter.device()->height ();
  std::cerr << "max_y=" << max_y << " m_grid.m_rows.size=" << m_grid.m_rows.size () << std::endl;
  for (int ii = 0; ii < m_grid.m_rows.size (); ++ ii) {
    const unsigned xx = m_grid.m_columns [ii];
    //std::cerr << ii << " " << xx << std::endl;
    painter.drawLine (xx, min_y, xx, max_y);
  }
  //
  // Draw the horizontal grid lines
  //
  const unsigned min_x = 0;
  const unsigned max_x = painter.device()->width ();
  std::cerr << "max_x=" << max_x << " m_grid.m_columns.size=" << m_grid.m_columns.size () << std::endl;
  for (int ii = 0; ii < m_grid.m_columns.size (); ++ ii) {
    const unsigned yy = m_grid.m_rows [ii];
    //std::cerr << ii << " yy=" << yy << std::endl;
    painter.drawLine (min_x, yy, max_x, yy);
  }

  //
  //  Draw the cell values
  //
  for (int ii = 0; ii < m_grid.m_columns.size (); ++ ii) {
    for (int jj = 0; jj < m_grid.m_rows.size (); ++ jj) {
      const std::string value = m_grid.m_model.getCellValue (Cell (ii, jj));
      const QString qstr = QString::fromStdString(value);
      const unsigned xx = m_grid.m_columns [ii];
      const unsigned yy = m_grid.m_rows [jj];
      painter.drawText (xx, yy + 50, qstr);
    }
  }

  //
  //  Draw the current selected cell
  //
  const unsigned col = m_grid.m_currentCell.xx ();
  const unsigned row = m_grid.m_currentCell.yy ();

  painter.drawRoundedRect (m_grid.m_columns [col] + 2,
			   m_grid.m_rows [row] + 2,
			   m_grid.m_columns.span (col) - 4,
			   m_grid.m_rows.span (row) - 4,
			   5, 5);
}
