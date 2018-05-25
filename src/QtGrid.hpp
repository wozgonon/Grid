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

protected:

  void paintEvent(QPaintEvent *event) override;
  void mousePressEvent(QMouseEvent * event) override;
  void keyPressEvent(QKeyEvent * event ) override;

private:
  Cell arrowKey(QKeyEvent *event) const;
};




#endif
  
