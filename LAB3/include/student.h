#ifndef LAB3_STUDENT_H
#define LAB3_STUDENT_H
#include <string>
class Student
{
private:
    std::string name;
    std::string surname;
    double correctAns;
    double incorrectAns;
public:
    Student(std::string, std::string, double, double);
    void setName(std::string);
    void setSurname(std::string);
    void setCorrectAns(double);
    void setIncorrectAns(double);
    void setInfo(std::string, std::string, double, double);
    double calcPercent();
};
#endif //LAB3_STUDENT_H
