//
// Created by mikolaj on 1/8/22.
//

#ifndef LAB10_MYCLLASS_H
#define LAB10_MYCLLASS_H
class MyClass
{
    private:
        double x;
    public:
        MyClass(double x);
        bool operator<(const MyClass& a) const;
        bool operator>(const MyClass& b) const;
};
#endif //LAB10_MYCLLASS_H
