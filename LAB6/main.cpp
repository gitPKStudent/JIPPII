#include <iostream>

#include "Node.h"
#include "Complex.h"
#include "Vector.h"
#include "Triangle.h"

void task_1();
void task_2();
void task_3();

int main()
{
    task_1();
    task_2();
    task_3();

    return 0;
}

void task_1()
{
    std::cout<<"--------------TASK 1--------------\n";
    Node node0(2,2);
    Node node1(4,4);
    std::cout<<pointsDistance(node0, node1)<<std::endl;
}

void task_2()
{
    std::cout<<"--------------TASK 2--------------\n";
    Vector v0(2,4);
    Vector v1(3,8);
    std::cout << (v0 + v1) << std::endl;
    std::cout << (v0 - v1) << std::endl;
    std::cout << (v0 * v1) << std::endl;
    std::cout << (v0 * 2) << std::endl;
    std::cout << (2 * v0) << std::endl;
    std::cout << (-v0) << std::endl;

    C c0(2, 4);
    C c1(1, 3);
    std::cout<< (c0 + c1) << std::endl;
    std::cout<< -(c0 + c1) << std::endl;
    std::cout<< (c0 * c1) << std::endl;
}

void task_3()
{
    std::cout<<"--------------TASK 3--------------\n";
    Node a, b(5,8), c(1, 16);
    Triangle triangle(a, b, c, "First Triangle");

    triangle.display();
    std::cout << triangle << std::endl;
    std::cout << "Distance between first and second point is " << triangle.distance(0,1) << std::endl;

    Triangle myTriangle(a, b, c, "MT");
    showTriangleData(myTriangle); //odwolanie do funkcji tworzacej kopie lub referencje
    showTriangleData(&myTriangle); //odwolanie do funkcji majacej wskaznik jako argument
}