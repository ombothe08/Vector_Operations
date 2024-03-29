#pragma once

class Point3D
{
public:
    Point3D();
    Point3D(double x, double y, double z);
    ~Point3D()=default;

    double X() const;
    double Y() const;
    double Z() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    bool operator==(const Point3D &other) const;
    bool operator<(const Point3D &other) const;

protected:
    double mX;
    double mY;
    double mZ;
};
