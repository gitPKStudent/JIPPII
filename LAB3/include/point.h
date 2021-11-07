#include <cmath>
#include <string>
#ifndef LAB3_POINT_H
#define LAB3_POINT_H
class Point
{
private:
    double x;
    double y;
public:
    Point();
    Point(double x, double y);
    void setX(double x);
    void setY(double y);
    double getX();
    double getY();
    double distance(Point* p);
    std::string toString();
};
#endif //LAB3_POINT_H
