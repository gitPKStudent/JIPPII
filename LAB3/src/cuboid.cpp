#include "cuboid.h"

double Cuboid::area()
{
    return 2 * w_x * w_y + 4 * w_x * w_z;
}

Cuboid::Cuboid(double wx, double wy, double wz)
{
    w_x = wx;
    w_y = wy;
    w_z = wz;
}

