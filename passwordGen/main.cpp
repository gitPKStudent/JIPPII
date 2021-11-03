#include <iostream>
#include <math.h>
#include <string>
#include <time.h>

bool isValid(char c)
{
    int iVal = (int) c;
    if(iVal  <= 32 || c == '\'' || c == '\"' || c =='/' || c == ','  || c == '.' || c == '\\' || c =='`' )
        return false;
    return true;
}

int main()
{
    srand(time(nullptr));
    std::string psw = "";
    char c;
    for(int i = 0 ;i < 10; i++)
    {
        c = (char) (33 + (int) (rand() * 128 / RAND_MAX));;
        while(!isValid(c))
            c = (char) (33 + (int) (rand() * 128 / RAND_MAX));;
        psw += c;
    }
    std::cout<<psw;
    return 0;
}
