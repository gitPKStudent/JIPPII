#include "utils.h"

bool isNumber(std::string arg)
{
    for(int i = 0; i < arg.length(); i++)
    {
        if(arg[i] == '-' && i != 0)
            return false;

        if (!((arg[i] >= '0' && arg[i] <= '9') || arg[i] == '.' || arg[i] == '-'))
            return false;
    }
    return true;
}

bool isChar(std::string arg)
{
    if(!isNumber(arg) && arg.length() == 1)
        return true;
    return false;
}

