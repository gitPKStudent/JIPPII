#include "ComVehicle.h"

ComVehicle::ComVehicle(unsigned short num, std::string start, std::string stop, std::string oper)
{
    this->number = num;
    this->startingStop = start;
    this->endingStop = stop;
    this->comOperator = oper;
}

ComVehicle::ComVehicle(std::string data)
{
    std::string chunk = data.substr(0, data.find(",",0));
    data.erase(0, data.find(",") + 1);
    number = std::stoi(chunk);

    chunk = data.substr(0, data.find(",",0));
    data.erase(0, data.find(",") + 1);
    startingStop = chunk;

    chunk = data.substr(0, data.find(",",0));
    data.erase(0, data.find(",") + 1);
    endingStop = chunk;

    chunk = data.substr(0, data.find(",",0));
    data.erase(0, data.find(",") + 1);
    comOperator = chunk;
}

void ComVehicle::writeToFile(std::ofstream& ostream)
{
    if(ostream.good())
        ostream<<number<<","<< startingStop<<","<<endingStop<<","<<comOperator<<"\n";
}

bool ComVehicle::isBus()
{
    if(number > 99)
        return true;
    return false;
}