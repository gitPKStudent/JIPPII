#ifndef LAB6_TRIANGLE_H
#define LAB6_TRIANGLE_H
#include <iostream>
#include "Triangle.h"
#include "Node.h"

class Triangle
{
    private:
        std::string name;
        Node nodes[3];

    public:
        Triangle(Node a, Node b, Node c, std::string name);

        void display();
        double distance(int firstPointIndex, int secondPointIndex);

        friend std::ostream & operator<<(std::ostream & stream, const Triangle triangle);
};

 //void showTriangleData(Triangle triangle); nie moze istniec rownoczesnie z showTriangleData(Triangle & triangle)
 void showTriangleData(Triangle & triangle);
 void showTriangleData(Triangle *triangle);
#endif //LAB6_TRIANGLE_H
