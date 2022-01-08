#ifndef LAB10_COMVEHICLE_H
#define LAB10_COMVEHICLE_H
#include <string>
#include <fstream>

class ComVehicle
{
private:
    unsigned short number;
    std::string startingStop;
    std::string endingStop;
    std::string comOperator;
public:
    ComVehicle(unsigned short num, std::string, std::string, std::string);
    ComVehicle(std::string);
    void writeToFile(std::ofstream& ostream);
    bool isBus();
};


#endif //LAB10_COMVEHICLE_H
