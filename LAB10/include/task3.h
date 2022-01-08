//
// Created by mikolaj on 1/8/22.
//

#ifndef LAB10_TASK3_H
#define LAB10_TASK3_H
#include <iostream>

template<typename T>
class Vector
{
    private:
        int SIZE = 5;
        int noe = 0;
        T *array;
    public:
        Vector()
        {
            array = new T[SIZE];
        }

        Vector(int size)
        {
            SIZE = size;
            array = new T [SIZE];
        }
        ~Vector() {delete [] array;}

        void addLast(T e)
        {
            if (noe >= SIZE)
            {
                T *tmp = new T[2 * SIZE];
                for (int i = 0; i < noe; i++)
                    tmp[i] = array[i];
                tmp[noe++] = e;
                delete[] array;
                array = tmp;
            } else
                array[noe++] = e;
        }

        void deleteLast()
        {
            if(noe == 0)
                throw "Index out of bound";
            else
                noe--;
        }

        T* getPointer()
        {
            return array;
        }

        void print()
        {
            for (int i = 0; i < noe; ++i)
                std::cout<<array[i]<<" ";
            std::cout<<std::endl;
        }

};
#endif //LAB10_TASK3_H
