#include "../headers/Plane.h"
#include "../headers/GeomVector.h"

Plane::Plane() : mNormal(GeomVector(0, 0, 0)), mPointOnPlane(Point3D(0, 0, 0)) {}
Plane::Plane(GeomVector &normal, Point3D &pointOnPlane) : mNormal(normal), mPointOnPlane(pointOnPlane) {}
Plane::~Plane() {}

GeomVector Plane::getNormal() const
{
    return this->mNormal;
}
 
Point3D Plane::getPointOnPlane() const
{
    return this->mPointOnPlane;
}
 
