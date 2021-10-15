#include "common.h"

/*
   returns sum of two Integer numbers
*/
int add(int a , int b)
{
    return a + b;
}

/*
   returns diffrence between two Integer numbers
*/
int subtract(int a, int b)
{
    return a - b;
}

/*
    returns volume of straight prism
 */
double volume(int a, int b, int h, int H)
{
    return (((a + b)* h) / 2) * H;
}

/*
    returns string object that includes context of documentation.
 */
std::string getDoc()
{
    return "Simple calculatur\n"
           "simpleCalc add\n"
           "\n"
           "Działania:\n"
           "add [a] [b]\n"
           "    Dodawanie dwóch liczb ([a] i [b]) całkowitych.\n"

           "simpleCalc subtract\n"
           "\n"
           "Działania:\n"
           "subtract [a] [b]\n"
           "    Odejmowanie dwóch liczb ([a] i [b]) całkowitych.\n"

           "simpleCalc volume\n"
           "\n"
           "Działania:\n"
           "volume [a] [b] [h] [H]\n"
           "    Zwraca objetosc granistosluba prostego o podstawie ([a] [b] [h]) trapezu"
           " i wysokosci [H].";
}