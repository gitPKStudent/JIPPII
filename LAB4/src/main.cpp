#include <iostream>
#include "task.h"
#include "poly2.h"
#include "sphere.h"
#include "cuboid.h"
#include "student.h"
#include "point.h"
#include "figura.h"
#include "MyClass.h"

int main()
{
    std::cout<<"---------------1_1---------------"<<std::endl;
    task1_1();
    std::cout<<"---------------1_2---------------"<<std::endl;
    task1_2();
    std::cout<<"---------------1_3---------------"<<std::endl;
    task1_3();
    std::cout<<"---------------1_4---------------"<<std::endl;
    task1_4();

    std::cout<<"---------------2_1---------------"<<std::endl;
    task2_1();
    std::cout<<"---------------2_2---------------"<<std::endl;
    task2_2();
    std::cout<<"---------------2_3---------------"<<std::endl;
    task2_3();
    std::cout<<"---------------2_4---------------"<<std::endl;
    task2_4();

    std::cout<<"---------------3_1---------------"<<std::endl;
    task3_1();
    std::cout<<"---------------3_2---------------"<<std::endl;
    task3_2();

    std::cout<<"----------------4----------------"<<std::endl;
    task4();

    return 0;
}
 void printCar(Car& car)
{
    std::cout<<car.marka<<" "<<car.model<<" "<<car.prodYear<<" "<<car.color<<" "<<car.avgCustomerRate<<std::endl;
}

void task1_1()
{
    Car cars [4] = {{"BMW", "M3", 2010, "BLACK"},
                    {"HONDA", "CIVIC", 2005, "BLUE"},
                    {"BMW", "X3", 2014, "WHITE"},
                    {"AMZ-Kutno", "Syrenka", 2016, "RED"}};
    printCar(cars[0]);
    printCar(cars[1]);
    printCar(cars[2]);
    printCar(cars[3]);
}

void task1_2()
{
    Car cars [4] = {{"BMW", "M3", 2010, "BLACK", 4.2},
                    {"HONDA", "CIVIC", 2005, "BLUE", 4.6},
                    {"BMW", "X3", 2014, "WHITE", 3.7},
                    {"AMZ-Kutno", "Syrenka", 2016, "RED", 5}};
    printCar(cars[0]);
    printCar(cars[1]);
    printCar(cars[2]);
    printCar(cars[3]);
}

void task1_3()
{
    Car cars [4] = {{"BMW", "M3", 2010, "BLACK", 4.2},
                    {"HONDA", "CIVIC", 2005, "BLUE", 4.6},
                    {"BMW", "X3", 2014, "WHITE", 3.7},
                    {"AMZ-Kutno", "Syrenka", 2016, "RED", 5}};
    countMark(cars, 4);

}
void countMark(Car* cars, int n)
{
    bool* counted = new bool [n];
    for(int i = 0; i < n; i++)
        counted[i] = false;

    int counter;

    for(int i = 0; i < n; i++)
    {
        counter = 0;
        if(!counted[i])
        {
            for(int k = i; k < n; k++)
                if(cars[i].marka == cars[k].marka)
                {
                    counter++;
                    counted[k] = true;
                }
            std::cout<<cars[i].marka<<" - "<<counter<<std::endl;
        }
    }

    delete [] counted;
}

void task1_4()
{
    Car cars [4] = {{"BMW", "M3", 2010, "BLACK", 4.2},
                    {"HONDA", "CIVIC", 2005, "BLUE", 4.6},
                    {"BMW", "X3", 2014, "WHITE", 3.7},
                    {"AMZ-Kutno", "Syrenka", 2016, "RED", 5}};
    printCar(cars[minProdYear(cars, 4)]);
}

int minProdYear(Car* cars, int n)
{
    int index = 0;
    for(int i = 1; i < n; i++)
    {
        if(cars[index].prodYear > cars[i].prodYear)
            index = i;
    }
    return index;
}

//II
void task2_1()
{
    Cuboid cuboid = {1, 1, 1};
    std::cout<<cuboid.area()<<std::endl;
}

void task2_2()
{
    Sphere sphere = Sphere(3);
    std::cout<<sphere.volume()<<std::endl;
}

void task2_3()
{
    Poly2 poly = {3, 2, 1};
    poly.print();
}

void task2_4()
{
    Student student = {"Alojzy", "Apollo", 3, 7};
    std::cout<<student.calcPercent()<<"%"<<std::endl;
};

void task3_1()
{
    Point point(2,4);
    Point point2(2,6);
    std::cout<<point.toString()<<" "<<point2.toString()<<" "<<point.distance(&point2)<<std::endl;
}

void task3_2()
{
    Point points [3] = { {1, 1}, {1, 2}, {3,3} };
    Figura triangle(points, 3);
    triangle.printVert();
}

void task4()
{
     MyClass myClass;
}

