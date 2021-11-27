#include "Figure.h"
#include <iostream>

Figure::Figure()
{

}

Figure::Figure(std::string name, std::string color)
{
    this->name = name;
    this->color = color;
}

void Figure::setName(std::string name)
{
    this->name = name;
}

void Figure::setColor(std::string color)
{
    this->color = color;
}

std::string Figure::getName()
{
    return name;
}

std::string Figure::getColor()
{
    return color;
}

void Figure::print()
{
    std::cout<<"NAME: "<<name<<std::endl<<"COLOR: "<<color<<std::endl;
}
