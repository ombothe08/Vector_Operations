#include "../headers/geomVector.h"
#include "../headers/point3D.h"
#include <cmath>
#include <iostream>

geomVector::geomVector(){}
geomVector::geomVector(point3D v1, point3D v2, point3D v3, point3D v4)
{
    mV1 = v1;
    mV2 = v2;
    mV3 = v3;
    mV4 = v4;
}

geomVector ::~geomVector()
{
}

void geomVector::sVectoV1(point3D v1)
{
    mV1 = v1;
}

void geomVector ::sVectoV2(point3D v2)
{
    mV2 = v2;
}
void geomVector ::sVectoV3(point3D v3)
{
    mV2 = v3;
}
void geomVector ::sVectoV4(point3D v4)
{
    mV2 = v4;
}

point3D geomVector::vector1()
{
    return mV1;
}
point3D geomVector ::vector2()
{
    return mV2;
}
point3D geomVector ::vector3()
{
    return mV2;
}
point3D geomVector ::vector4()
{
    return mV2;
}
void geomVector ::print(point3D a)
{
    std::cout << a.x() << " " << a.y() << " " << a.z();
}

void geomVector:: calculateVectorComponents(point3D v1, point3D v2, point3D v3, point3D v4)
{
     vec1X = v2.x() - v1.x();
     vec1Y = v2.y() - v1.y();
     vec1Z = v2.z() - v1.z();
     vec2X = v4.x() - v3.x();
     vec2Y = v4.y() - v3.y();
     vec2Z = v4.z() - v3.z();
}

double geomVector ::dotProduct(point3D v1, point3D v2, point3D v3, point3D v4)
{
    int result = 0;
     calculateVectorComponents(v1,v2,v3,v4);
    result = vec1X * vec2X + vec1Y * vec2Y + vec1Z * vec2Z;
    return result;
}

point3D geomVector::crossProduct(point3D v1, point3D v2, point3D v3, point3D v4)
{
    calculateVectorComponents(v1,v2,v3,v4);
    double result_x = vec1Y * vec2Z - vec1Z * vec2Y;
    double result_y = vec1Z * vec2X - vec1X * vec2Z;
    double result_z = vec1X * vec2Y - vec1Y * vec2X;
    return point3D(result_x, result_y, result_z);
}

point3D geomVector::vectorAddition(point3D v1, point3D v2, point3D v3, point3D v4)
{
    calculateVectorComponents(v1,v2,v3,v4);
    double x = vec1X + vec2X;
    double y = vec1Y + vec2Y;
    double z = vec1Z + vec2Z;
    return point3D(x, y, z);
}

double geomVector::vectorMagnitude(point3D v1, point3D v2)
{
    double magnitude = sqrt(pow(v2.x() - v1.x(), 2) + pow(v2.y() - v1.y(), 2) + pow(v2.z() - v1.z(), 2));
    return magnitude;
}

point3D geomVector::vectorNormalized(point3D v1, point3D v2)
{
    double x = v2.x() - v1.x();

    double y = v2.y() - v1.x();

    double z = v2.z() - v1.x();

    double magnitude = sqrt(x * x + y * y + z * z);

    double nX = x / magnitude;
    double nY = y / magnitude;
    double nZ = z / magnitude;

    return point3D(nX, nY, nZ);
}

bool geomVector::isEqual(point3D v1, point3D v2, point3D v3, point3D v4)
{
    calculateVectorComponents(v1,v2,v3,v4);
     if (vec1X == vec2X && vec1Y == vec2Y && vec1Z == vec2Z)
    {
        return true;
    }
    else
    {
        return false;
    }
  
}

point3D geomVector::addScalar(point3D v1, point3D v2, double scalar)
{
    double X = v2.x() - v1.x() + scalar;
    double Y = v2.y() - v1.y() + scalar;
    double Z = v2.z() - v1.z() + scalar;

    return point3D(X, Y, Z);
}

point3D geomVector::vectorScalarMultiplication(point3D v1, point3D v2, double scalar)
{
    double X = v2.x() - v1.x() * scalar;
    double Y = v2.y() - v1.y() * scalar;
    double Z = v2.z() - v1.z() * scalar;

    return point3D(X, Y, Z);
}

double geomVector::angleBetweenVectors(point3D v1, point3D v2, point3D v3, point3D v4)
{

    double dot = dotProduct(v1, v2, v3, v4);
    calculateVectorComponents(v1,v2,v3,v4);

    point3D nVec1(vec1X, vec1Y, vec1Z);
    point3D nVec2(vec2X, vec2Y, vec2Z);

    double magnitude = vectorMagnitude(nVec1, nVec2);

    return acos(dot / magnitude) * 180.0 / M_PI;
}

double geomVector::distanceBetweenVectors(point3D v1, point3D v2, point3D v3, point3D v4)
{
    calculateVectorComponents(v1,v2,v3,v4);
    double d1 = vec2X - vec1X;
    double d2 = vec2Y - vec1Y;
    double d3 = vec2Z - vec1Z;

    double formula = d1 * d1 + d2 * d2 + d3 * d3;

    double Distance = sqrt(formula);

    return Distance;
}

point3D geomVector ::subtractScalar(point3D v1, point3D v2, double scalar)
{
    double X = v2.x() - v1.x() - scalar;
    double Y = v2.y() - v1.y() - scalar;
    double Z = v2.z() - v1.z() - scalar;

    return point3D(X, Y, Z);
}

point3D geomVector::vectorScalarDivision(point3D v1, point3D v2, point3D v3, point3D v4, double scalar)
{
    double X = v2.x() - v1.x() / scalar;
    double Y = v2.y() - v1.y() / scalar;
    double Z = v2.z() - v1.z() / scalar;

    return point3D(X, Y, Z);
}

double geomVector ::angleBetweenPlaneandVector(plane normal, point3D v1, point3D v2)
{

    double dot = dotProduct(v1, v2, normal.gVector1(), normal.gVector2());

    double x1 = v2.x() - v1.x();
    double y1 = v2.y() - v1.y();
    double z1 = v2.z() - v1.z();

    point3D nVec1(x1, y1, z1);

    double x2 = normal.gVector2().x() - normal.gVector1().x();
    double y2 = normal.gVector2().y() - normal.gVector1().y();
    double z2 = normal.gVector2().z() - normal.gVector1().z();

    point3D nVec2(x2, y2, z2);

    double magnitude = vectorMagnitude(nVec1, nVec2);
    double angle = acos(dot / magnitude) * 180 / M_PI;
    return angle;
}

void geomVector ::directionCosines(point3D v1, point3D v2, point3D v3, point3D v4)
{
    double x1 = v2.x() - v1.x();
    double y1 = v2.y() - v1.y();
    double z1 = v2.z() - v1.z();

    double magnitude1 = vectorMagnitude(v1, v2);

    std ::cout << " Direction Cosine of X is " << x1 / magnitude1 << std ::endl;

    std ::cout << " Direction Cosine of Y is " << y1 / magnitude1 << std ::endl;

    std ::cout << " Direction Cosine of Z is " << z1 / magnitude1 << std ::endl;
}


double geomVector ::setLength(point3D v1, point3D v2, double length)
{

    point3D normal = vectorNormalized(v1, v2);

    double magnitude = sqrt(pow(normal.x(), 2) + pow(normal.y(), 2) + pow(normal.z(), 2));

    double newLength = magnitude * length;

    return newLength;
}

