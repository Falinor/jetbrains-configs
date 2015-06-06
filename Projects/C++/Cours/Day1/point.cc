#include <iostream>

#include "point.hh"

Point::Point()
  : x_(0)
  , y_(0)
{}

void Point::move(int x, int y)
{
  x_ = x;
  y_ = y;
}

void Point::display() const
{
  std::cout << "x: " << x_ << std::endl;
  std::cout << "y: " << y_ << std::endl;
}

int main()
{
  Point a;
  const Point b;
  a.display();
  b.display();
  b.move(1, 1);
}
