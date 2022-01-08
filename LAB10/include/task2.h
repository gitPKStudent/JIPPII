#ifndef LAB10_TASK2_H
#define LAB10_TASK2_H

template <typename T, int SIZE>
class Array
{
    private:
        int size = SIZE;
        T array[SIZE];
    public:

        int getSize()
        {
            return size;
        }

        void put(T e, int index)
        {
            if(index < 0 || index >= SIZE)
                throw "Index out of bound !";
            else
                array[index] = e;
        }

        T get(int index)
        {
            if(index < 0 || index >= SIZE)
                throw "Index out of bound !";
            else
                return array[index];
        }

        void print()
        {
            for(T t : array)
                std::cout<<t<<" ";
            std::cout<<std::endl;
        }
};
#endif //LAB10_TASK2_H
