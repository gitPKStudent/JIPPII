#ifndef LAB7_CIRCLE_H
#define LAB7_CIRCLE_H

#include <iostream>
#include "Figure.h"

class Circle : public Figure
{
    private:
        double r;
    public:
        Circle(std::string name, std::string color, double r);
        Circle(double r);
        double getArea();
        double getSideLen();
        void print();
};

#endif //LAB7_CIRCLE_H
