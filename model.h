#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "math.h"
#include "aerodynamics.h"
#include "theormech.h"
#include "meteorite.h"
#include "point.h"
#include "planet.h"

/*

Библиотека model.h предоставляет инструментарий для обсчета математической модели падения метеорита.

*/

const double G = 6.6738480; // гравитационная постоянная
const double step = 0.2; // шаг модуляции в секундах
const double accuracy = 0.00000001; // точность сравнения



double count_distance(point &, point &);
double count_sqr_distance(point &, point &);
double dot_production(point &, point &);
double count_projection(point &, point &);
double to_pow(double, double);
point count_norm(point);
bool check_collision(meteorite &, planet &);
void count_step (meteorite &, planet &);

//planet earth;

#endif // MODEL_H
