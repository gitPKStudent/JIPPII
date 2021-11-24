//
// Created by filip on 07.11.2021.
//

#include <iostream>
#include "Vehicle.h"
#include "Vector.h"
#include "Complex.h"

using namespace std;

class TestClass {
public:
    const int t = 0;

public:
    TestClass(const int t) : t(t) {

    }
};

void task1_2();
void task2_3();
void task3();

int main()
{
    task1_2();
    task2_3();
    task3();

    return 0;
}

void task1_2()
{
    Vehicle tesla("KRK123456", "TESLA", "S", 4);

    Passenger p0("Elon");
    Passenger p1("Ada");
    Passenger p2("Adam");
    Passenger p3;
    p3.setName("Mikolaj");

    tesla.setPassenger(0, p0);
    tesla.setPassenger(1, p1);
    tesla.setPassenger(2, p2);
    tesla.setPassenger(3, p3);

    tesla.printData();

    Vehicle bmw = tesla;
    bmw.setName("BMW");
    bmw.setRegNum("BOBEK_K1");
    bmw.setPassenger(0, "Karl");
    bmw.setPassenger(1, "Franz");
    bmw.setPassenger(2, "Gustav");
    bmw.setPassenger(3, "Camillo");

    bmw.printData();
}

void task2_3()
{
    //2
    int a = 3;
    int b = -3;

    const int * ptr0 = &a;
    int * const ptr1 = &b;
    const int * const ptr2 = &a;

    ptr0 = &b;
    //*ptr0 = 10;

    //ptr1 = &a;
    *ptr1 = 10;

    //ptr2 = &b;
    //*ptr2 = 10;

    //3 - 7
    Vehicle maluch("KRK22303", "maluch", "PRL", 4);
    Vehicle syrenka("WZW22303", "syrenka", "PRL", 4);


    maluch.printSoftwareVersion();
    syrenka.printSoftwareVersion();

    maluch.updateSoftware();

    maluch.printSoftwareVersion();
    syrenka.printSoftwareVersion();

    Vehicle::softwareRelease(20.05);
    syrenka.updateSoftware();

    maluch.printSoftwareVersion();
    syrenka.printSoftwareVersion();
}

void task3()
{
    //VECTORS
    Vector vector0(3, 1.0, 2.0 ,3.0);
    Vector vector1(3, 3.0, 2.0 ,1.0);
    (vector0+vector1).print();

    Vector vector2(3, 4.0, 4.0, 4.0);
    (vector2 * (vector0 + vector1)).print();

    std::cout<< (vector0 == vector1) << std::endl;
    std::cout<< ((vector0 + vector1) == vector2) << std::endl;

    //COMPLEX NUMBERS
    C a(3,3);
    C b(-3, -3);
    C c(0, 0);
    C d(8, -7);

    (a + d).print();
    (a * b).print();
    (!a).print();
    std::cout<<((a + b) == c)<<std::endl;
}