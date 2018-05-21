#ifndef __QT_GRID_HPP__
#define __QT_GRID_HPP__

#include "Grid.hpp"
#include <QtWidgets/QWidget>


class QtGrid : public QWidget {
  Grid& m_grid;
public:

  QtGrid (Grid& grid, QWidget* parent = 0);
  virtual ~QtGrid ();
  
  QSize minimumSizeHint() const override;
  QSize sizeHint() const override;

public:
//     void setShape(Shape shape);
//     void setPen(const QPen &pen);
//     void setBrush(const QBrush &brush);
//     void setAntialiased(bool antialiased);
//     void setTransformed(bool transformed);

protected:
  void paintEvent(QPaintEvent *event) override;
  void mousePressEvent(QMouseEvent * event) override;

// private:
//     QPen pen;
//     QBrush brush;
//     bool antialiased;
//     bool transformed;
//     QPixmap pixmap;
// };

};




#endif
  
