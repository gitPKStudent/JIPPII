#include "MyClass.h"
#include <iostream>

MyClass::MyClass()
{
    ptr = new int[1024];
    std::cout<<"Wywolano konstruktor"<<std::endl;
    system("pause");
}

MyClass::~MyClass()
{
    delete [] ptr;
    std::cout<<"Wyczyszczono pamiec."<<std::endl;
}