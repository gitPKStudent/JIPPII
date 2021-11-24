#include "student.h"

Student::Student(std::string name, std::string surname, double cor, double incor)
{
    setInfo(name, surname, cor, incor);
}

void Student::setName(std::string name)
{
    Student::name = name;
}

void Student::setSurname(std::string surname)
{
    Student::surname = surname;
}

void Student::setCorrectAns(double correctAns)
{
    Student::correctAns = correctAns;
}

void Student::setIncorrectAns(double incorrectAns)
{
    Student::incorrectAns = incorrectAns;
}

void Student::setInfo(std::string name, std::string surname, double correct, double incorrect)
{
    setName(name);
    setSurname(surname);
    setCorrectAns(correct);
    setIncorrectAns(incorrect);
}

double Student::calcPercent()
{
    return ( correctAns / (correctAns + incorrectAns) ) * 100;
}