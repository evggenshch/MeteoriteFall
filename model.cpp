#include "model.h"
#include "math.h"

point x_direction = point(1, 0, 0);
point y_direction = point(0, 1, 0);
point z_direction = point(0, 0, 1);

double count_distance(point & p1, point & p2) { // подсчет расстояния
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z));
}

double count_sqr_distance(point & p1, point & p2) { // подсчет квадрата расстояния
    return ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z));
}

double dot_production(point & p1, point & p2) { // скалярное произведение
    return (p1.x * p2.x + p1.y * p2.y + p1.z * p2.z);
}

double count_projection(point & v1, point & v2) { // проекция вектора v1 на направление v2
    return (dot_production(v1, v2) / v2.module());
}

double to_pow(double num, double pow) {
    double res = 1;
    for(long i = 0; i < pow; i++) {
        res *= num;
    }
    return res;
}

point count_norm(point p1) { // подсчет нормы вектораb
    double mod = p1.module();
    return point (p1.x / mod, p1.y / mod, p1.z / mod);
}

bool check_collision (meteorite & met, planet & pl) {  // да/нет - есть столкновение/нет столкновения
  return ((count_distance(met.center, pl.center) - met.radius - pl.radius) < accuracy);
}

void count_step (meteorite & met, planet & pl) { // пересчет координат метеорита/спускаемого аппарата для одного шага модели
    double g_module = G * pl.mass / count_sqr_distance(met.center, pl.center) * step * to_pow(10, 7);
    point norm = count_norm(pl.center - met.center);
    met.center.x += met.v.x * step;
    met.center.y += met.v.y * step;
    met.center.z += met.v.z * step;
//    met.v.x += g_module * count_projection(norm, x_direction);
//    met.v.y += g_module * count_projection(norm, y_direction);
//    met.v.z += g_module * count_projection(norm, z_direction);
}
