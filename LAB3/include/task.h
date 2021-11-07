//
// Created by mik15 on 05.11.2021.
//

#ifndef LAB3_TASK_H
#define LAB3_TASK_H
#include <string>
//I
struct Car
{
    std::string marka;
    std::string model;
    int prodYear;
    std::string color;
    double avgCustomerRate;
};

void task1_1();
void task1_2();
void task1_3();
void task1_4();

void printCar(Car& car);
int minProdYear(Car* cars, int n);
void countMark(Car* cars, int n);

//II
void task2_1();
void task2_2();
void task2_3();
void task2_4();

//III
void task3_1();
void task3_2();

//IV
void task4();

#endif //LAB3_TASK_H
