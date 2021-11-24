#include "common.h"
#include "utils.h"
#include "calc.h"

int main(int argc, char * argv[])
{
    int i = 1;

    while(i < argc)
    {
        if(!isOperator(argv [i]))
        {
            //invalid input
            error();
        }
        else
        {
            //calculating specific function
            if(strcmp("add", argv[i]) == 0)
            {
                if( i + 2 >= argc)
                    error();
                if(!(isNumber(argv[i + 1]) && isNumber(argv[i + 2])) )
                    error();

                int a = atoi(argv[i + 1]);
                int b = atoi(argv[i + 2]);
                std::cout<<"add "<<add(a, b)<<"\n";
                i += 3;
            }
            else if(strcmp("subtract", argv[i]) == 0)
            {
                if( i + 2 >= argc)
                    error();
                if(!(isNumber(argv[i + 1]) && isNumber(argv[i + 2])) )
                    error();

                int a = atoi(argv[i + 1]);
                int b = atoi(argv[i + 2]);
                std::cout<<"subtract:  "<<subtract(a, b)<<"\n";
                i += 3;
            }
            else if(strcmp("volume", argv[i]) == 0)
            {

                if( i + 4 >= argc)
                    error();
                if(!(isNumber(argv[i + 1]) && isNumber(argv[i + 2])
                     && isNumber(argv[i + 3]) && isNumber(argv[i + 4]) ))
                    error();

                int a = atoi(argv[i + 1]);
                int b = atoi(argv[i + 2]);
                int hp = atoi(argv[i + 3]);
                int H = atoi(argv[i + 4]);
                std::cout<<"volume: "<< ((a + b) * hp * H) / 2<<"\n";
                i += 5;
            }
            else if(strcmp("help", argv[i]) == 0)
            {
                std::cout<<getDoc()<<std::endl;
                break;
            }
        }
    }

}

