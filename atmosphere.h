#ifndef ATMOSPHERE_H
#define ATMOSPHERE_H
#include <vector>
#include "atm_layer.h"

using namespace std;

class atmosphere
{
public:
    /*atmosphere(arguments);
    ~ atmosphere(); */
    vector <atm_layer> layers;
    atmosphere();
    void add_atm_layer(atm_layer);
};

#endif // ATMOSPHERE_H
