#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <QtWidgets/QWidget>

class Window : public QWidget
{
  //    Q_OBJECT

public:
  Window();
  virtual ~Window();

  QSize minimumSizeHint() const override;
  QSize sizeHint() const override;

};

#endif
