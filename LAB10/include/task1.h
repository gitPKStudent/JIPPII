#ifndef LAB10_TASK1_H
#define LAB10_TASK1_H
#include <iostream>

template<typename T>
T minF(T a, T b)
{
    static_assert(!std::is_same<decltype(a), unsigned  int>::value, "forbidden type");
    return a < b ? a : b;
}

template<typename T>
T maxF(T a, T b)
{
    return a > b ? a : b;
}

template<typename T>
void printArray(T* array, int size)
{
    for (int i = 0; i < size; ++i)
        std::cout<<array[i]<<" ";
    std::cout<<std::endl;
}

template<typename T>
void printMatrix(T* matrix, int row, int col)
{
    for (int i = 0; i < col; ++i)
        printArray<T>((matrix + i * row), row);

}

#endif //LAB10_TASK1_H
