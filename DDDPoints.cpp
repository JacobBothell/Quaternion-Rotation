#include "DDDPoints.h"
#include "quatern.h"
#include <iostream>
#include <ostream>
#include <string>
#include <cmath>
using namespace std;

DDDPoint::DDDPoint()
{
    x=y=z=0;
}

DDDPoint::DDDPoint(float X, float Y, float Z)
{
    x = X;
    y = Y;
    z = Z;
}

DDDPoint DDDPoint::rotate(DDDPoint &a1, DDDPoint &a2, float &angle)
{
    //move everything to the origin and determine axis points
    DDDPoint origin(0,0,0);
    DDDPoint vectorEnd, point;
    bool reOrigined = false;

    if(a1==origin)
    {
        vectorEnd=a2;
        point = *(this);
    }
    else if (a2==origin)
    {
        vectorEnd=a1;    
        point = *(this);
    }
    else
    {
        //force a1 to be origin
        vectorEnd = a2-a1;
        point = *(this)-a1;
        reOrigined = true;
    }

    if(reOrigined)
        cout << "Origin Moved \n";

    cout << "Rotation Points\n\t" << "Point\n\t" << point << "\n\tOrigin\n\t" << origin << "\n\tVectorEnd\n\t" << vectorEnd << "\n";

    //make axis a rotatable quaternion
    //normalize axis
    float axisMag = sqrt((pow(vectorEnd.x,2)+pow(vectorEnd.y,2)+pow(vectorEnd.z,2)));
    cout << "Axis Magnitude: " << axisMag << "\n";
    vectorEnd = vectorEnd/axisMag;
    cout << "Normalized Vector: " << vectorEnd << "\n";

    //create angle/2 quaternion for rotation
    float sinAngle = sin(angle/2);
    quatern rotQuat(cos(angle/2), sinAngle*vectorEnd.x, sinAngle*vectorEnd.y, sinAngle*vectorEnd.z);

    cout << "Rotation Quaternion: " << rotQuat << "\n";

    //make p a quaternion
    quatern rotPoint(point);
    cout << "Point turned into Quaternion: " << rotPoint << "\n";

    //do rotation
    rotPoint = rotQuat * rotPoint;
    rotPoint = rotPoint  * rotQuat.inv();

    cout << "Rotated Quaternion: " << rotPoint << "\n";

    //return point
    //translate back to dddpoint
    point = DDDPoint(rotPoint.i,rotPoint.j,rotPoint.k);
    //move back if translated
    if(reOrigined)
        return  point+a1;
    else
        return point;
}

DDDPoint operator+(const DDDPoint& a, const DDDPoint& b)
{
    return DDDPoint((a.x+b.x), (a.y+b.y), (a.z+b.z));
}

DDDPoint operator-(const DDDPoint& a, const DDDPoint& b)
{
    return DDDPoint((a.x-b.x), (a.y-b.y), (a.z-b.z));
}

DDDPoint operator/(const DDDPoint& a, const float& b)
{
    return DDDPoint((a.x/b), (a.y/b), (a.z/b));
}

bool operator==(const DDDPoint& a, const DDDPoint& b)
{
    if( (a.x==b.x) && (a.y==b.y) && (a.z==b.z))
        return true;
    
    return false;
}

bool operator!=(const DDDPoint& a, const DDDPoint& b)
{
    return !(a==b);
}

std::ostream &operator<<(std::ostream &os, DDDPoint const &p)
{
    return os << "X:" + std::to_string(p.x) + " Y:" + std::to_string(p.y) + " Z:" + std::to_string(p.z) + "\n";
}