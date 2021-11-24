#include "point.h"
 Point::Point()
{
    setX(0);
    setY(0);
}

Point::Point(double x, double y)
{
    setX(x);
    setY(y);
}

void Point::setX(double x)
{
    Point::x = x;
}
void Point::setY(double y)
{
    Point::y = y;
}
double  Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}
double Point::distance(Point* p)
{
    double x2 = p->getX();
    double y2 = p->getY();
    return sqrt((x - x2)*(x - x2) + (y - y2) * (y - y2));
}

std::string Point::toString()
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}
