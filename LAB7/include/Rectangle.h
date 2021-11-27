//
// Created by mik15 on 27.11.2021.
//

#ifndef LAB7_RECTANGLE_H
#define LAB7_RECTANGLE_H

#include <iostream>
#include "Figure.h"

class Rectangle : public Figure
{
    private:
        double a;
        double b;
    public:
        Rectangle(std::string name, std::string color, double a, double b);
        Rectangle(double a, double b);
        double getArea();
        double getSideLen();
        void print();
};
#endif //LAB7_RECTANGLE_H
