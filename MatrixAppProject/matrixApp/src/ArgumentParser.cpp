#include "ArgumentParser.h"
#include "utils.h"

ArgumentParser::ArgumentParser(int argc, char* argv[])
{
    input = "";
    position = - 1;
    isNextNum = false;
    isNextChar = false;
    argsNum = argc;
    this->argv = argv;
}

bool ArgumentParser::hasNext()
{
    return position + 1 < argsNum;
}

double ArgumentParser::nextValue()
{
    if(hasNext() && isNextNum)
    {
        position++;
        if(hasNext())
        {
            std::string nextArg = argv[position + 1];
            isNextNum = isNumber(nextArg);
            isNextChar = isChar(nextArg);
        }
        std::string arg = std::string(argv[position]);
        return std::stod(arg);
    }
    else
        return 0;
}

std::string ArgumentParser::nextString()
{
    if(hasNext() && !isNextNum)
    {
        position++;
        if(hasNext())
        {
            std::string nextArg = argv[position + 1];
            isNextNum = isNumber(nextArg);
            isNextChar = isChar(nextArg);
        }

        std::string arg = std::string(argv[position]);
        return arg;
    }
}

bool ArgumentParser::isNumberNext()
{
    return hasNext() && isNextNum;
}

bool ArgumentParser::isCharacterNext()
{
    return hasNext() && isNextChar;
}

