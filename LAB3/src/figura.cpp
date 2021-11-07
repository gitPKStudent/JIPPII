#include <iostream>
#include "figura.h"

Figura::Figura(Point *points, int size)
{
    Figura::points = new Point[size];
    memcpy(Figura::points, points, sizeof(Point) * size);
    Figura::size = size;
}

Figura::~Figura()
{
    delete [] points;
}

int Figura::getSize()
{
    return size;
}

void Figura::printVert()
{
    std::cout<<"[ ";
    for(int i = 0; i < size; i++)
        std::cout<<points[i].toString()<<" ";
    std::cout<<"]"<<std::endl;
}