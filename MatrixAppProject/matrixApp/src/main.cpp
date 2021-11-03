#include <iostream>
#include "AppInterface.h"
#include "ArgumentParser.h"
#include "matrixLib.h"
#include "utils.h"

void error();
char getNextChar(ArgumentParser* parser);
double getNextNumber(ArgumentParser* parser);

int main(int argc, char* argv[])
{
    AppInterface appInterface = AppInterface();
    ArgumentParser parser = ArgumentParser(argc, argv);
    //skip program name
    parser.nextString();
    while (parser.hasNext())
    {
        //get function name
        std::string funName;
        funName = parser.nextString();

        if (funName == "addMatrix")
        {
            if (parser.isNumberNext())
            {
                int row = getNextNumber(&parser);
                int col = getNextNumber(&parser);
                if (!appInterface.addMatrixInterf(row, col))
                    error();
            } else
            {
                char flag0 = getNextChar(&parser);
                char flag1 = getNextChar(&parser);
                //check if input is correct
                if (!appInterface.addMatrixInterf(0, 0, flag0, flag1))
                    error();
            }
        } //if(funName == "addMatrix")
        else if (funName == "subtractMatrix")
        {
            if (parser.isNumberNext())
            {
                int row = getNextNumber(&parser);
                int col = getNextNumber(&parser);
                if (!appInterface.subtractMatrixInterf(row, col))
                    error();
            } else
            {
                char flag0 = getNextChar(&parser);
                char flag1 = getNextChar(&parser);
                //check if input is correct
                if (!appInterface.subtractMatrixInterf(0, 0, flag0, flag1))
                    error();
            }
        }//else if(funName == "subtractMatrix")
        else if (funName == "multiplyMatrix")
        {
            if (parser.isNumberNext())
            {
                int rowA = getNextNumber(&parser);
                int colA = getNextNumber(&parser);
                int colB = getNextNumber(&parser);
                if (!appInterface.multiplyMatrixInterf(rowA, colA, colA, colB))
                    error();
            } else
            {
                char flag0 = getNextChar(&parser);
                char flag1 = getNextChar(&parser);
                //check if input is correct
                if (!appInterface.multiplyMatrixInterf(0, 0, 0, 0, flag0, flag1))
                    error();
            }
        }//    else if(funName == "multiplyMatrix")
        else if (funName == "multiplyByScalar")
        {
            if (parser.isNumberNext())
            {
                int row = getNextNumber(&parser);
                int col = getNextNumber(&parser);
                double scalar = getNextNumber(&parser);
                if (!appInterface.multiplyByScalarInterf(row, col, scalar))
                    error();
            } else
            {
                char flag0 = getNextChar(&parser);
                int scalar = getNextNumber(&parser);
                //check if input is correct
                if (!appInterface.multiplyByScalarInterf(0, 0, scalar, flag0))
                    error();
            }
        }//else if(funName == "multiplyByScalar")
        else if (funName == "transpozeMatrix")
        {
            if (parser.isNumberNext())
            {
                int row = getNextNumber(&parser);
                int col = getNextNumber(&parser);
                if (!appInterface.transpozeMatrixInterf(row, col))
                    error();
            } else
            {
                char flag0 = getNextChar(&parser);
                //check if input is correct
                if (!appInterface.transpozeMatrixInterf(0, 0, flag0))
                    error();
            }
        }//else if(funName == "transpozeMatrix")
        else if (funName == "powerMatrix")
        {
            if (parser.isNumberNext())
            {
                int row = getNextNumber(&parser);
                int col = getNextNumber(&parser);
                int power = getNextNumber(&parser);
                if (!appInterface.powerMatrixInterf(row, col, power))
                    error();
            } else
            {
                char flag0 = getNextChar(&parser);
                int power = getNextNumber(&parser);
                //check if input is correct
                if (!appInterface.powerMatrixInterf(0, 0, power, flag0))
                    error();
            }
        }//else if(funName == "powerMatrix")
        else if (funName == "matrixIsDiagonal")
        {
            if (parser.isNumberNext())
            {
                int row = getNextNumber(&parser);
                int col = getNextNumber(&parser);
                if (!appInterface.matrixIsDiagonalInterf(row, col))
                    error();
            } else
            {
                char flag0 = getNextChar(&parser);
                //check if input is correct
                if (!appInterface.matrixIsDiagonalInterf(0, 0, flag0))
                    error();
            }
        }//else if(funName == "matrixIsDiagonal")
        else if (funName == "sortRow")
        {
            if (parser.isNumberNext())
            {
                int row = getNextNumber(&parser);
                int col = getNextNumber(&parser);
                int rowToSort = getNextNumber(&parser);
                if (!appInterface.sortRowInterf(row, col, rowToSort))
                   error();
            } else
            {
                char flag0 = getNextChar(&parser);
                int rowToSort = getNextNumber(&parser);
                //check if input is correct
                if (!appInterface.sortRowInterf(0, 0, rowToSort, flag0))
                    error();
            }
        }//else if(funName == "sortRow")
        else if (funName == "sortRowsInMatrix")
        {
            if (parser.isNumberNext())
            {
                int row = getNextNumber(&parser);
                int col = getNextNumber(&parser);
                if (!appInterface.sortRowsInMatrixInterf(row, col))
                  error();
            } else
            {
                char flag0 = getNextChar(&parser);
                //check if input is correct
                if (!appInterface.sortRowsInMatrixInterf(0, 0, flag0))
                    error();
            }
        }//else if(funName == "sortRowsInMatrix")
        else if (funName == "determinantMatrix")
        {
            if (parser.isNumberNext())
            {
                int row = getNextNumber(&parser);
                int col = getNextNumber(&parser);
                if (!appInterface.determinantMatrixInterf(row, col))
                    error();
            } else
            {
                char flag0 = getNextChar(&parser);
                //check if input is correct
                if (!appInterface.determinantMatrixInterf(0, 0, flag0))
                    error();
            }
        }//else if(funName == "determinantMatrix")
        else if (funName == "fill")
        {
            if (parser.isNumberNext())
            {
                int row = getNextNumber(&parser);
                int col = getNextNumber(&parser);
                char flag = getNextChar(&parser);
                if (!appInterface.fill(row, col, flag))
                    error();
            } else
                error();
        }//else if(funName == "fill")
        else
        {
            appInterface.help();
            break;
        }
    }// while (parser.hasNext())
}

void error()
{
    AppInterface::help();
    exit(0);
}

double getNextNumber(ArgumentParser* parser)
{
    double num;
    if(parser->isNumberNext())
        num = parser->nextValue();
    else
        error();
    return num;
}

char getNextChar(ArgumentParser* parser)
{
    std::string str;
    if(parser->isCharacterNext())
        str = parser->nextString();
    else
        error();
    return str[0];
}