#pragma once
class point3D
{
public:
    point3D();

    point3D(double x, double y, double z);

    ~point3D();

    void sX(double x);
    void sY(double Y);
    void sZ(double z);

    void print(point3D a);


    double x();

    double y();
    double z();

private:
    double mX;
    double mY;
    double mZ;
};