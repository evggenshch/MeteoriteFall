#ifndef ATM_LAYER_H
#define ATM_LAYER_H

class atm_layer {               // макромодель или микромодель?
public:
    double density;
    double height;
    double gamma; // соотношение теплоемкостей c_p/c_v
    atm_layer();
    atm_layer(double, double, double);
};

#endif // ATM_LAYER_H
