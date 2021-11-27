#include <math.h>
#include <iostream>
#include "Node.h"

Node::Node()
{
    x = 0;
    y = 0;
}

Node::Node(double x, double y): x(x), y(y) {}

void Node::display()
{
    std::cout << "x: " << x << "\ty: " << y << std::endl;
}

void Node::updateValue(double x, double y)
{
    this->x = x;
    this->y = y;
}

double pointsDistance(Node a, Node b)
{
    return sqrt( pow(b.x -a.x, 2) + pow(b.y -a.y, 2) );
}