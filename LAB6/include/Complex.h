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
        C operator-();
        C operator*(const C& rhs);
        bool operator ==(const C& rhs);
        C operator!();
        friend C operator*(double s, const C& rhs);
        friend C operator*(const C& lhs, double s);
        friend std::ostream& operator<<(std::ostream& stream, const C& rhs);

};

#endif //LAB5_COMPLEX_H
