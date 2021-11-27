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

C C::operator-()
{
    return {-x, -y};
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

C operator*(double s, const C& rhs)
{
    return {s * rhs.x, s * rhs.y};
}

C operator*(const C& lhs, double s)
{
    return {s * lhs.x, s * lhs.y};
}

void C::print()
{
    std::cout<<"("<<x<<", "<<y<<")\n";
}

std::ostream & operator<<(std::ostream& stream, const C& rhs)
{
    stream<<"("<<rhs.x<<", "<<rhs.y<<")";
    return stream;
}