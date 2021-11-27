#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Quadrat.h"

void task_1();
void task_2();

int main()
{
    task_1();
    task_2();
    return 0;
}

void task_1()
{
    std::cout<<"-----TASK 1-----\n";

    Quadrat q0("Adam", "WHITE", 3);
    Circle c0("Ada", "BLACK", 5.5);

    q0.print();
    c0.print();

    std::cout<<q0.getArea()<<std::endl;
    std::cout<<c0.getArea()<<std::endl;

    std::cout<<q0.getSideLen()<<std::endl;
    std::cout<<c0.getSideLen()<<std::endl;
}

void task_2()
{
    std::cout<<"-----TASK 2-----\n";

    Figure *circle = new Circle(5);
    Figure *rectangle = new Rectangle(5, 18);

    std::cout << "Circle area: " << circle->getArea() << std::endl;
    std::cout << "Rectangle area: " << rectangle->getArea() << std::endl;

    delete circle;
    delete rectangle;
}
