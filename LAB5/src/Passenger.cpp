#include "Passenger.h"

Passenger::Passenger()
{
    this->name = "EMPTY";
}


Passenger::Passenger(std::string name)
{
    this->name = name;
}

std::string Passenger::getName()
{
    return name;
}

void Passenger::setName(std::string name)
{
    this->name = name;
}