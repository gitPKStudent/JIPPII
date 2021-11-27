#ifndef LAB6_NODE_H
#define LAB6_NODE_H
class Node
{
    private:
        double x, y;
        friend double pointsDistance(Node a, Node b);

    public:
        Node();
        Node(double x, double y);

        void display();
        void updateValue(double x, double y);
};
#endif //LAB6_NODE_H
