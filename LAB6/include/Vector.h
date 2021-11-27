//
// Created by mik15 on 26.11.2021.
//

#ifndef LAB6_VECTOR_H
#define LAB6_VECTOR_H
#include <iostream>
class Vector
{
    private:
        double x, y;

    public:
        Vector();
        Vector(double x, double y);
        double length();
        void print();

        Vector operator+(const Vector& rhs);
        Vector operator-(const Vector& rhs);
        Vector operator-();
        double operator* (const Vector& rhs);
        bool operator==(const Vector& rhs);
        friend Vector operator*(const Vector& lhs, double s);
        friend Vector operator*(double s, const Vector& lhs);
        friend std::ostream& operator<<(std::ostream& stream, const Vector& rhs);
};
#endif //LAB6_VECTOR_H
