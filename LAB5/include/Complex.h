#ifndef LAB5_COMPLEX_H
#define LAB5_COMPLEX_H
class C
{
    private:
        double x;
        double y;

    public:
        C();
        C(double x, double y);
        void print();
        C operator+(const C& rhs);
        C operator-(const C& rhs);
        C operator*(const C& rhs);
        bool operator ==(const C& rhs);
        C operator!();
};

#endif //LAB5_COMPLEX_H
