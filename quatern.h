#ifndef QUATERN_H
#define QUATERN_H
#include <ostream>
class quatern
{
private:

public:
    float R,i,j,k;
    quatern();
    quatern(float r, float I, float J, float K);
    quatern(float r, DDDPoint p);
    quatern(DDDPoint p);

    quatern inv();

    friend quatern operator*(quatern const &a, quatern const &b);
    friend std::ostream &operator<<(std::ostream &os, quatern const &p);
};
#endif