//
// Created by mik15 on 27.11.2021.
//

#ifndef LAB7_FIGURE_H
#define LAB7_FIGURE_H
#include <string>
class Figure
{
    private:
        std::string name;
        std::string color;
    public:
        Figure();
        Figure(std::string name, std::string color);
        void setName(std::string name);
        void setColor(std::string color);
        std::string getName();
        std::string getColor();

        virtual double getArea() = 0;
        virtual double getSideLen() = 0;
        virtual void print();

};
#endif //LAB7_FIGURE_H
