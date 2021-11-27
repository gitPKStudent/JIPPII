#include "Vector.h"
#include <math.h>
#include <ostream>

Vector::Vector(): x(0), y(0) {}

Vector::Vector(double x, double y) : x(x), y(y) {}

double Vector::length()
{
    return sqrt(x * x + y * y);
}

Vector Vector::operator+(const Vector& rhs)
{
    return {x + rhs.x, y + rhs.y};
}

Vector Vector::operator-(const Vector& rhs)
{
    return {x - rhs.x, y - rhs.y};
}

Vector Vector::operator-()
{
    return {-x, -y};
}

double Vector::operator*(const Vector &rhs)
{
    return x * rhs.x + y * rhs.y;
}

Vector operator*(const Vector& lhs, double s)
{
    return {s * lhs.x, s * lhs.y};
}

Vector operator*(  double s, const Vector& rhs)
{
    return {s * rhs.x, s * rhs.y};
}

bool Vector::operator==(const Vector &rhs)
{
    return x == rhs.x && y == rhs.y;
}

std::ostream & operator<<(std::ostream& stream, const Vector& rhs)
{
    stream<<"["<<rhs.x<<", "<<rhs.y<<"]";
    return stream;
}

void Vector::print()
{
    std::cout<<"["<<x<<", "<<y<<"]\n";
}

