
#include "../headers/point3D.h"
#include <iostream>

using namespace std;
point3D :: point3D ()
{
    
}
point3D ::point3D(double x, double y, double z)
{
    mX = x;
    mY = y;
    mZ = z;
}

point3D ::~point3D()
{
}

void point3D::sX(double x)
{
    mX = x;
}
void point3D::sY(double y)
{
    mY = y;
}
void point3D ::sZ(double z)
{
    mZ = z;
}

double point3D :: x()
{
    return mX;
}
double point3D :: y()
{
    return mY;
}
double point3D :: z()
{
    return mZ;
}
