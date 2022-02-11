#include "quatern.h"
#include "DDDPoints.h"
#include <iostream>
#include <ostream>
#include <string>
using namespace std;

quatern::quatern() { R = i = j = k = 0; }

quatern::quatern(float r, float I, float J, float K) { R=r; i=I; j=J; k=K;}

quatern::quatern(float r, DDDPoint p) {R=r; i=p.x; j=p.y; k=p.z;}
quatern::quatern(DDDPoint p){R=0; i=p.x; j=p.y; k=p.z;}

/* A few notes on Quaternion math
    i*i == j*j == k*k == ijk == -1
    ij == k
    ik == -j
    ji == -k
    jk == i
    ki == j
    kj == -i
*/

quatern quatern::inv()
{
    return quatern(this->R, -this->i, -this->j, -this->k);
}

quatern operator*(quatern const &a, quatern const &b)
{
    quatern product;

    //just going to calc the hamiltonian product
    product.R = (a.R*b.R)-(a.i*b.i)-(a.j*b.j)-(a.k*b.k);
    product.i = (a.R*b.i)+(a.i*b.R)+(a.j*b.k)-(a.k*b.j);
    product.j = (a.R*b.j)-(a.i*b.k)+(a.j*b.R)+(a.k*b.i);
    product.k = (a.R*b.k)+(a.i*b.j)-(a.j*b.i)+(a.k*b.R);

    return product;
}

std::ostream &operator<<(std::ostream &os, quatern const &p)
{
    return os << "R:" + std::to_string(p.R) + " i:" + std::to_string(p.i) + " j:" + std::to_string(p.j) + " k:" + std::to_string(p.k);
}