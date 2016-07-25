#include "atmosphere.h"

atmosphere::atmosphere()
{
}

void atmosphere::add_atm_layer(atm_layer new_atm_layer) {
    layers.push_back(new_atm_layer);
}
