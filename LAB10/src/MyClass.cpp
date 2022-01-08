#include "MyCllass.h"

MyClass::MyClass(double x)
{
    this->x = x;
}

bool MyClass::operator<(const MyClass& a) const
{
    return x < a.x;
}

bool MyClass::operator>(const MyClass& a) const
{
    return x > a.x;
}

