#include "point.h"
#include "math.h"

point::point()
{
}

point::point(double set_x, double set_y, double set_z) {
    x = set_x;
    y = set_y;
    z = set_z;
}

double point::module() {
    return sqrt(x * x + y * y + z * z);
}

const point point::operator- (const point & p2) const {
    return point(x - p2.x, y - p2.y, z - p2.z);
}

const point point::operator+ (const point & p2) const {
    return point(x + p2.x, y + p2.y, z + p2.z);
}
