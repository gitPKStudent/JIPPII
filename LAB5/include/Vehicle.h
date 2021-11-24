#ifndef LAB5_VEHICLE_H
#define LAB5_VEHICLE_H
#include "Passenger.h"
#include <string>
class Vehicle
{
    private:
        static double newestSoftwareVersion;
        double installedSoftwareVersion = 11.0;
        std::string regNum;
        std::string name;
        int seatNum;
        Passenger* passengerData;
        std::string type;

    public:
        Vehicle(std::string regNum, std::string name, std::string type, int seatNum);
        Vehicle(const Vehicle& vehicle);

        void printSoftwareVersion();
        void printData();
        void updateSoftware();
        void setPassenger(int seatNum, Passenger passenger);
        void setPassenger(int seatNum, std::string passengerName);

        void setRegNum(std::string regNum);
        void setName(std::string name);

        static void softwareRelease(double version);
        static double getNewestSoftwareVersion();

        std::string getRegNum();
        std::string getName();
        std::string getType();
        double getSoftwareVersion();

};


#endif //LAB5_VEHICLE_H
