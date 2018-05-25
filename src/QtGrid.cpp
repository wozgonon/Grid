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
     setFocusPolicy(Qt::ClickFocus);

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

Cell QtGrid::arrowKey(QKeyEvent * event) const
{
  const unsigned col = m_grid.m_currentCell.xx();
  const unsigned row = m_grid.m_currentCell.yy();
  const auto key = event->key();
  switch (key) {
  case Qt::Key_Up:    return Cell (col, row == 0 ? 0 : row - 1);
  case Qt::Key_Down:  return Cell (col, row + 1 >= m_grid.m_rows.size () ? row : row + 1);
  case Qt::Key_Left:  return Cell (col == 0 ? 0 : col - 1, row);
  case Qt::Key_Right: return Cell (col +1 >= m_grid.m_columns.size () ? col : col + 1, row);
  default: return m_grid.m_currentCell;
  }
}

void QtGrid::keyPressEvent(QKeyEvent * event)
{
  const auto key = event->key();
  std::cerr << "Key event: " << key << std::endl;
  if (key == Qt::Key_Up || key == Qt::Key_Down || key == Qt::Key_Left || key == Qt::Key_Right) {
    m_grid.m_currentCell = arrowKey (event);
    repaint ();
  }
}


void QtGrid::paintEvent(QPaintEvent *event)
{
  //
  //  TODO only draw the impacted part of the screen
  //
  QPainter painter(this);

  //
  // Draw the horizontal grid lines
  //
  const unsigned columns = m_grid.m_columns.size ();
  const unsigned rows    = m_grid.m_rows.size ();
  if (rows > 0) {
    const unsigned min_x = 0;
    const unsigned max_x = m_grid.m_columns.end (columns - 1); //painter.device()->width ();
    std::cerr << "max_x=" << max_x << " rows=" << rows << std::endl;
    for (int ii = 0; ii < rows; ++ ii) {
      const unsigned yy = m_grid.m_rows.end (ii);
      std::cerr << ii << " yy=" << yy << std::endl;
      painter.drawLine (min_x, yy, max_x, yy);
    }
  }
  //
  // Draw the vertical grid lines
  //
  if (columns > 0) {
    const unsigned min_y = 0;
    const unsigned max_y = m_grid.m_rows.end (rows - 1) ; //painter.device()->width ();
    std::cerr << "max_y=" << max_y << " columns=" << columns << std::endl;
    for (int ii = 0; ii < columns; ++ ii) {
      const unsigned xx = m_grid.m_columns.end (ii);
      std::cerr << ii << " " << xx << std::endl;
      painter.drawLine (xx, min_y, xx, max_y);
    }
  }
  //
  //  Draw the cell values
  //
  for (int ii = 0; ii < columns; ++ ii) {
    for (int jj = 0; jj < rows; ++ jj) {
      const std::string value = m_grid.m_model.getCellValue (Cell (ii, jj));
      const QString     qstr  = QString::fromStdString(value);
      const unsigned    xx    = m_grid.m_columns [ii];
      const unsigned    yy    = m_grid.m_rows [jj];
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
