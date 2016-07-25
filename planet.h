#ifndef PLANET_H
#define PLANET_H

#include "point.h"

class planet
{
public:
    double grav;
    double mass;
    double radius;
    point center;  // все координаты по дефолту равны 0
    double v_omega;
    planet();
};

#endif // PLANET_H
