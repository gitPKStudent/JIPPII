#include <iostream>
#include "csvfile.h"

int main()
{
    CSVFile file("file.csv");

    while(file.hasNextElement())
    {
        std::cout<<file.readNextElement();
        if(file.getCol() == file.getColNum())
            std::cout<<std::endl;
        else
            std::cout<<" | ";
    }
    return 0;
}
