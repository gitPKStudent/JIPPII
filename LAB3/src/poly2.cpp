#include <iostream>
#include "poly2.h"

void Poly2::print()
{
    std::cout<<"f ( x ) = "<<a<<" * x^2 + " <<b<<" * x + "<<c<<std::endl;
}

Poly2::Poly2(double a, double b, double c)
{
    Poly2::a = a;
    Poly2::b = b;
    Poly2::c = c;
}