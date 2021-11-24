#ifndef LAB3_FIGURA_H
#define LAB3_FIGURA_H
#include "point.h"
#include <memory.h>
class Figura
{
private:
    int size;
    Point* points;
public:
    Figura(Point* points, int size);
    ~Figura();
    int getSize();
    void printVert();
};
#endif //LAB3_FIGURA_H
