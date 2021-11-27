#ifndef LAB7_QUADRAT_H
#define LAB7_QUADRAT_H

#include <iostream>
#include "Figure.h"

class Quadrat : public Figure
{
private:
    double a;
public:
    Quadrat( std::string name, std::string color, double a);
    Quadrat(double a);
    double getArea();
    double getSideLen();
    void print();
};
#endif //LAB7_QUADRAT_H
