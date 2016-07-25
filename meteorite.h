#ifndef METEORITE_H
#define METEORITE_H
#include "point.h"

class meteorite
{
public:
 /*   meteorite(arguments);
    ~ meteorite(); */
    double mass;  // масса
    double radius; // заменить
    point center;
    point v;
    double v_mass;
};

#endif // METEORITE_H
