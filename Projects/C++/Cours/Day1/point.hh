#ifndef POINT_HH_
# define POINT_HH_

class Point
{
public:
  Point();
  Point(int x, int y);
  void display() const;
  void move(int x, int y);

private:
  int x_;
  int y_;
};

#endif /* !POINT_HH_ */
