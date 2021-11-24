#include "Vehicle.h"
#include <iostream>

double Vehicle::newestSoftwareVersion = 17.01;

Vehicle::Vehicle(std::string regNum, std::string name, std::string type, int seatNum)
{
    this->regNum = regNum;
    this->name = name;
    this->type = type;
    this->seatNum = seatNum;

    passengerData = new Passenger [seatNum];
}

Vehicle::Vehicle(const Vehicle& vehicle)
{
    regNum = vehicle.regNum;
    type = vehicle.type;
    name = vehicle.name;
    seatNum = vehicle.seatNum;

    passengerData = new Passenger[seatNum];
    for(int i = 0; i < seatNum; i++)
        passengerData[i] = vehicle.passengerData[i];
}

void Vehicle::printData()
{
    std::cout<<"-----------------\n";
    std::cout<<regNum<<" "<<name<<" "<<type<<std::endl;
    std::cout<<"SEATS: "<<seatNum<<std::endl;

    std::cout<<"PASSENGER'S:\n";
    for(int i = 0; i < seatNum; i++)
        std::cout<<passengerData[i].getName()<<std::endl;

    std::cout<<"-----------------\n";
}

void Vehicle::setPassenger(int seatNum, Passenger passenger)
{
    if(seatNum < this->seatNum)
        passengerData[seatNum] = passenger;
}

void Vehicle::setPassenger(int seatNum, std::string passengerName)
{
    if(seatNum < this->seatNum)
        passengerData[seatNum].setName(passengerName);
}

void Vehicle::setName(std::string name)
{
    this->name = name;
}

void Vehicle::setRegNum(std::string regNum)
{
    this->regNum = regNum;
}

std::string Vehicle::getName()
{
    return name;
}

std::string Vehicle::getRegNum()
{
    return regNum;
}

std::string Vehicle::getType()
{
    return type;
}

double Vehicle::getSoftwareVersion()
{
    return installedSoftwareVersion;
}

double Vehicle::getNewestSoftwareVersion()
{
    return Vehicle::newestSoftwareVersion;
}

void Vehicle::printSoftwareVersion()
{
    std::cout<<"-----------------\n";
    std::cout<<name<<std::endl;
    std::cout<<"INSTALLED: "<<installedSoftwareVersion<<std::endl;
    std::cout<<"NEWEST: "<<newestSoftwareVersion<<std::endl;
    std::cout<<"-----------------\n";
}

void Vehicle::updateSoftware()
{
    installedSoftwareVersion = newestSoftwareVersion;
}

void Vehicle::softwareRelease(double version)
{
    newestSoftwareVersion = version;
}