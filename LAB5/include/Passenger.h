#ifndef LAB5_PASSENGER_H
#define LAB5_PASSENGER_H
#include <string>

class Passenger
{
    private:
        std::string name;

    public:
        Passenger(std::string name);
        Passenger();
        std::string getName();
        void setName(std::string name);
};
#endif //LAB5_PASSENGER_H
