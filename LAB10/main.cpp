#include <iostream>
#include <fstream>
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "forwardDec.h"
#include "MyCllass.h"
#include "ComVehicle.h"

using namespace std;

int main()
{
    //1
    cout<<"1:"<<std::endl;
    cout<<minF<int>(-1001,-1002)<<endl;
    //minF<unsigned int>(1,2);
    int array[5] = {1,2,3,4,5};
    int matrx[2][2] = {{1,2},{3,4}};
    printArray<int>(array, 5);
    printMatrix<int>(reinterpret_cast<int *>(matrx), 2, 2);
    //2
    cout<<"2:"<<std::endl;
    Array<int, 3> array0;
    array0.put(5, 0);
    array0.put(10, 1);
    array0.put(15, 2);
    array0.print();
    cout<<array0.get(1)<<endl;
    //3
    cout<<"3:"<<std::endl;
    Vector<int> vector(3);
    vector.addLast(0);
    vector.addLast(1);
    vector.addLast(2);
    vector.addLast(3);
    vector.addLast(4);
    vector.print();
    vector.deleteLast();
    vector.deleteLast();
    vector.print();
    //4
    ofstream output("data.csv", ios::out);

    ComVehicle vehicle []  ={
            {50, "Brzezinska", "Wojarowicza", "PKS"},
            {40, "Olszecka", "Marka", "PKS"},
            {505, "Mazurka", "Andrzeja", "PKS"},
            {32, "Jaruszewicza", "Chojnackiego", "ZTP"},
            {501, "Bora Komorowskiego", "Wojarowicza", "ZTP"}
    };

    for(int i = 0; i < 5; i++)
        vehicle[i].writeToFile(output);
    //save changes to a file and close stream
    output.close();

    ifstream input("data.csv");
    ofstream tramsOut("tram.csv");
    ofstream busOut("bus.csv");

    if(input.good() && tramsOut.good() && busOut.good());
    else
        cout<<"error\n";
    while (!input.eof())
    {
        std::string line;
        getline(input, line);
        if(line == "")
            break;

        ComVehicle vehicle0(line);
        if(vehicle0.isBus())
            vehicle0.writeToFile(busOut);
        else
            vehicle0.writeToFile(tramsOut);
    }

    tramsOut.close();
    busOut.close();
    input.close();
}
