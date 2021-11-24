#include "common.h"
/*
    return true if char is a digit or '.'
*/
bool isDigitOrDot(char c)
{
    return  c == '.' || ( (int) c >= (int)'0' && (int) c <= (int) '9' );
}

/*
    return true if char is a number
*/
bool isNumber(char* str)
{
    int len = _msize(str) / sizeof(char) - 1;
    for(int i = 0; i < len; i++)
        if(!isDigitOrDot(str[i]))
            return false;
    return true;
}

/*
    return true if string is a operator
*/
bool isOperator(char * str)
{
    return strcmp("volume", str) == 0 ||
    strcmp("add", str) == 0 ||
    strcmp("help", str) == 0 ||
    strcmp("subtract", str) == 0;
}
/*
    prints eerror message to the screen, kills program
 */
void error()
{
    std::cout<<"Invalid input. ERROR !";
    exit(0);
}