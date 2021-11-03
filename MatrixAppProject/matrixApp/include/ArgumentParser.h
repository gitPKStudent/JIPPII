#ifndef MATRIXAPP_ARGUMENTPARSER_H
#define MATRIXAPP_ARGUMENTPARSER_H
#include "common.h"

class ArgumentParser
{
    private:
        char** argv;
        int argsNum;
        int position;
        bool isNextNum;
        bool isNextChar;
        std::string input;
    public:
        ArgumentParser(int argc, char* argv[]);
        ArgumentParser(std::string input);
        bool hasNext();
        bool isNumberNext();
        bool isCharacterNext();
        std::string nextString();
        double nextValue();
};


#endif //MATRIXAPP_ARGUMENTPARSER_H
