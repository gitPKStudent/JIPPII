#include <iostream>
#include "Complex.h"

C::C()
{
    x = 0;
    y = 0;
}

C::C(double x, double y) : x(x), y(y)
{

}

C C::operator+(const C& rhs)
{
    return {x + rhs.x, y + rhs.y};
}

C C::operator-(const C& rhs)
{
    return {x - rhs.x, y - rhs.y};
}

C C::operator*(const C& rhs)
{
    return {x * rhs.x - y * rhs.y, x * rhs.y + y * rhs.x};
}

bool C::operator==(const C& rhs)
{
    return  x == rhs.x && y == rhs.y;
}

C C::operator!()
{
    return {x, -y};
}

void C::print()
{
    std::cout<<"("<<x<<", "<<y<<")\n";
}