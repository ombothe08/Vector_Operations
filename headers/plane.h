#pragma once
#include "GeomVector.h"

class Plane
{
public:
    Plane();
    Plane(GeomVector&, Point3D &);
    ~Plane();

    GeomVector getNormal() const;
    Point3D getPointOnPlane() const;


private:
    GeomVector mNormal;
    Point3D mPointOnPlane;
};