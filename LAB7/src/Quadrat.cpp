#include "Quadrat.h"

Quadrat::Quadrat(std::string name, std::string color, double a) : Figure(name, color)
{
    this->a = a;
}

Quadrat::Quadrat(double a)
{
    this->a = a;
}

void Quadrat::print()
{
    Figure::print();
    std::cout<<"SIDE: "<<a<<" "<<std::endl;
}

double Quadrat::getArea()
{
    return a * a;
}

double Quadrat::getSideLen()
{
    return 4 * a;
}