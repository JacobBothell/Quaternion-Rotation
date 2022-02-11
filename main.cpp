#include "DDDPoints.cpp"
#include "quatern.cpp"
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

int main()
{

    DDDPoint p1(1,1,1);
    DDDPoint p2(2,3,4);
    DDDPoint p3;

    p3=p1+p2;

    p1 = DDDPoint(1,0,0);
    p2 = DDDPoint(1,1,0);
    float angle = M_PI;
    
    DDDPoint p4;
    p4 = p3.rotate(p1, p2, angle);

    std:cout << p4;

}