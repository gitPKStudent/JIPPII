#include <cmath>
#include "sphere.h"

double Sphere::volume()
{
    return (4 * M_PI * r * r * r) / 3;
};

Sphere::Sphere(double r)
{
    Sphere::r = r;
}
