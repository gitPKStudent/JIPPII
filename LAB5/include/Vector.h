#ifndef LAB5_VECTOR_H
#define LAB5_VECTOR_H
class Vector
{
    private:
        const int len;
        double* data;

    public:
        Vector(int length, ...);
        Vector(int length, double* array);
        ~Vector();
        void print();

        Vector operator+(const Vector& rhs);
        Vector operator-(const Vector& rhs);
        bool operator==(const Vector& rhs);
        Vector operator*(const Vector& rhs);
        void operator=(const Vector& rhs);
};
#endif //LAB5_VECTOR_H
