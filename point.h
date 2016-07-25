#ifndef POINT_H
#define POINT_H

class point {
public:
    double x;
    double y;
    double z;
    point();
    point(double set_x, double set_y, double set_z);
    double module();
    const point operator-(const point & p2) const;
    const point operator+(const point & p2) const;
};

#endif // POINT_H
