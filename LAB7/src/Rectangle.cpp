#include "Rectangle.h"

Rectangle::Rectangle(std::string name, std::string color, double a, double b) : Figure(name, color)
{
    this->a = a;
    this->b = b;
}

Rectangle::Rectangle(double a, double b)
{
    this->a = a;
    this->b = b;
}

double Rectangle::getArea()
{
    return a * b;
}

double Rectangle::getSideLen()
{
    return 2 * a + 2 * b;
}

void Rectangle::print()
{
    Figure::print();
    std::cout<<"SIDES: "<<a<<" "<<b<<std::endl;
}