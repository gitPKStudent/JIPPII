#include <iostream>
#include <stdarg.h>
#include <memory.h>
#include "Vector.h"

Vector::Vector(int length, ...) : len(length)
{
    data = new double [length];

    va_list list;
    va_start(list, length);
    for(int i = 0; i < length; i++)
        data[i] = va_arg(list, double);
    va_end(list);
}

Vector::Vector(int length, double *array) : len(length)
{
    data = new double [length];
    for(int i = 0; i < length; i++)
        data[i] = array[i];
}

Vector::~Vector()
{
    delete [] data;
}

void Vector::print()
{
    std::cout<<"[ ";
    for(int i = 0; i < len; i++)
        std::cout<<data[i]<<" ";
    std::cout<<"]\n";
}

Vector Vector::operator+(const Vector& rhs)
{
    if(len != rhs.len)
        throw "Illegal operation!";

    double tmp [len];
    for(int i = 0; i < len; i++)
        tmp[i] = rhs.data[i] + data[i];

    return Vector(len, tmp);
}

Vector Vector::operator-(const Vector& rhs)
{
    if(len != rhs.len)
        throw "Illegal operation!";

    double tmp [len];
    for(int i = 0; i < len; i++)
        tmp[i] = rhs.data[i] - data[i];

    return Vector(len, tmp);
}

Vector Vector::operator*(const Vector& rhs)
{
    if(len != rhs.len)
        throw "Illegal operation!";

    double tmp [len];
    for(int i = 0; i < len; i++)
        tmp[i] = rhs.data[i] * data[i];

    return Vector(len, tmp);
}

bool Vector::operator==(const Vector& rhs)
{
    if(len != rhs.len)
        return false;
    double tmp [len];
    for(int i = 0; i < len; i++)
        if(data[i] != rhs.data[i])
             return false;
    return true;
}

void Vector::operator=(const Vector& rhs)
{
    if(this != &rhs)
    {
        if (len != rhs.len)
            throw "Illegal operation!";

        for (int i = 0; i < len; i++)
            data[i] = rhs.data[i];
    }
}
