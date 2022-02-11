#ifndef DDDPOINT_H
#define DDDPOINT_H
#include <ostream>
class DDDPoint
{
private:

public:
    float x,y,z;

    DDDPoint();
    DDDPoint(float X, float Y, float Z);

    DDDPoint rotate(DDDPoint &a1, DDDPoint &a2, float &angle);

    friend DDDPoint operator+(const DDDPoint& a, const DDDPoint& b);
    friend DDDPoint operator-(const DDDPoint& a, const DDDPoint& b);
    friend DDDPoint operator/(const DDDPoint& a, const float& b);
    friend bool operator==(const DDDPoint& a, const DDDPoint& b);
    friend bool operator!=(const DDDPoint& a, const DDDPoint& b);
    friend std::ostream &operator<<(std::ostream &os, DDDPoint const &p);
};
#endif