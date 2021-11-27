#include "Triangle.h"

Triangle::Triangle(Node a, Node b, Node c, std::string name)
{
    nodes[0] = a;
    nodes[1] = b;
    nodes[2] = c;
    this->name = name;
}

void Triangle::display()
{
    std::cout<<name<<":\n";
    nodes[0].display();
    nodes[1].display();
    nodes[2].display();
}

double Triangle::distance(int firstPointIndex, int secondPointIndex)
{
    if(firstPointIndex < 0 || firstPointIndex > 2
            || secondPointIndex < 0 || secondPointIndex > 2)
        return -1;

    return pointsDistance(nodes[firstPointIndex], nodes[secondPointIndex]);
}

std::ostream & operator<<(std::ostream & stream,  Triangle triangle)
{
    stream<<triangle.name<<":\n";
    triangle.nodes[0].display();
    triangle.nodes[1].display();
    triangle.nodes[2].display();
}

void showTriangleData(Triangle triangle)
{
    triangle.display();
}

void showTriangleData(Triangle &triangle)
{
    triangle.display();
}

void showTriangleData(Triangle *triangle)
{
    triangle->display();
}