#include "Window.hpp"

Window::Window ()
{
  setWindowTitle("Basic Drawing");
}

Window::~Window()
{
}

QSize Window::sizeHint() const
{
    return QSize(600, 600);
}

QSize Window::minimumSizeHint() const
{
    return QSize(400, 400);
}


