#include <math.h>
#include "Circle.h"

Circle::Circle(std::string name, std::string color, double r) : Figure(name, color)
{
    this->r = r;
}

Circle::Circle(double r)
{
    this->r = r;
}

double Circle::getArea()
{
    return M_PI * r * r;
}

double Circle::getSideLen()
{
    return 2 * M_PI * r;
}

void Circle::print()
{
    Figure::print();
    std::cout<<"RADIUS: "<<r<<std::endl;
}