#include <iostream>
#include <cmath>
#include "..\headers\GeomVector.h"
#include "..\headers\Plane.h"

GeomVector::GeomVector() : Point3D(){};
GeomVector::GeomVector(double x, double y, double z) : Point3D(x, y, z) {}

bool GeomVector ::operator==(const GeomVector &other) const
{
    if (other.X() == X() && other.Y() == Y() && other.Z() == Z())
    {
        return true;
    }
    else
    {
        return false;
    }
}

double GeomVector::getDotProduct(const GeomVector &other) const
{
    double dotProduct = 0.0;
    dotProduct += X() * other.X();
    dotProduct += Y() * other.Y();
    dotProduct += Z() * other.Z();
    return dotProduct;
}

GeomVector GeomVector::getCrossProduct(const GeomVector &other) const
{
    double newX = (this->Y() * other.Z()) - (this->Z() * other.Y());
    double newY = (this->Z() * other.X()) - (this->X() * other.Z());
    double newZ = (this->X() * other.Y()) - (this->Y() * other.X());
    return GeomVector(newX, newY, newZ);
}

double GeomVector::getMagnitude() const
{
    double x = this->X();
    double y = this->Y();
    double z = this->Z();

    double sum = x * x + y * y + z * z;
    double magnitude = sqrt(sum);
    return magnitude;
}

GeomVector GeomVector::getNormalized() const
{
    double _magnitude = getMagnitude();
    return GeomVector(this->X() / _magnitude, this->Y() / _magnitude, this->Z() / _magnitude);
}

GeomVector GeomVector::operator+(const GeomVector &other) const
{
    double newX = this->X() + other.X();
    double newY = this->Y() + other.Y();
    double newZ = this->Z() + other.Z();
    return GeomVector(newX, newY, newZ);
}

GeomVector GeomVector::operator-(const GeomVector &other) const
{
    double newX = this->X() - other.X();
    double newY = this->Y() - other.Y();
    double newZ = this->Z() - other.Z();
    return GeomVector(newX, newY, newZ);
}

GeomVector GeomVector::operator*(const GeomVector &other) const
{
    double newX = this->X() * other.X();
    double newY = this->Y() * other.Y();
    double newZ = this->Z() * other.Z();
    return GeomVector(newX, newY, newZ);
}
GeomVector GeomVector::operator/(const GeomVector &other) const
{
    double newX = this->X() / other.X();
    double newY = this->Y() / other.Y();
    double newZ = this->Z() / other.Z();
    return GeomVector(newX, newY, newZ);
}
GeomVector GeomVector::setVectorLength(double newLength) const
{
    return this->getNormalized().multiplyScalar(newLength);
}

GeomVector GeomVector::addScalar(double scalar) const
{
    double newX = this->X() + scalar;
    double newY = this->Y() + scalar;
    double newZ = this->Z() + scalar;
    return GeomVector(newX, newY, newZ);
}
GeomVector GeomVector::subtractScalar(double scalar) const
{
    double newX = this->X() - scalar;
    double newY = this->Y() - scalar;
    double newZ = this->Z() - scalar;
    return GeomVector(newX, newY, newZ);
}

GeomVector GeomVector::multiplyScalar(double scalar) const
{
    double newX = this->X() * scalar;
    double newY = this->Y() * scalar;
    double newZ = this->Z() * scalar;
    return GeomVector(newX, newY, newZ);
}

GeomVector GeomVector::divideScalar(double scalar) const
{
    double newX = this->X() / scalar;
    double newY = this->Y() / scalar;
    double newZ = this->Z() / scalar;
    return GeomVector(newX, newY, newZ);
}

double GeomVector::getDistanceBetweenVectors(const GeomVector &other) const
{
    double dx = this->X() - other.X();
    double dy = this->Y() - other.Y();
    double dz = this->Z() - other.Z();

    double distance = sqrt(dx * dx + dy * dy + dz * dz);
    return distance;
}

double GeomVector::getDistanceBetweenVectorAndPlane(const Plane &plane) const
{
    double dX = X() - plane.getPointOnPlane().X();
    double dY = Y() - plane.getPointOnPlane().Y();
    double dZ = Z() - plane.getPointOnPlane().Z();

    double dotProduct = dX * plane.getNormal().X() + dY * plane.getNormal().Y() + dZ * plane.getNormal().Z();
    double distance = std::abs(dotProduct) / plane.getNormal().getMagnitude();

    return distance;
}

double GeomVector::getAngleBetweenVectors(const GeomVector &other) const
{
    double dotProductResult = this->getDotProduct(other);
    double magnitudeResult = getMagnitude() * other.getMagnitude();

    double angleRadians = acos(dotProductResult / magnitudeResult);
    double angleDegrees = angleRadians * (180.0 / M_PI);

    return angleDegrees;
}

double GeomVector::getAngleBetweenVectorAndPlane(const Plane &plane) const
{
    // Calculate the dot product of the vector and the plane's normal
    double dotProductResult = getDotProduct(plane.getNormal());

    // Calculate the magnitudes of the vector and the plane's normal
    double vectorMagnitude = getMagnitude();
    double normalMagnitude = plane.getNormal().getMagnitude();

    // Calculate the angle in radians using the arccosine function
    double angleRadians = std::acos(dotProductResult / (vectorMagnitude * normalMagnitude));

    return angleRadians * (180.0 / M_PI);
}

void GeomVector::directionCosines() const
{
    double _magnitude = getMagnitude();
    double alpha, beta, gamma;

    if (_magnitude != 0.0)
    {
        alpha = std::acos(this->X() / _magnitude) * (180.0 / M_PI);
        beta = std::acos(this->Y() / _magnitude) * (180.0 / M_PI);
        gamma = std::acos(this->Z() / _magnitude) * (180.0 / M_PI);
    }
    else
    { //  case if  the magnitude is zero
        alpha = beta = gamma = 0.0;
    }
}

GeomVector GeomVector::multiplyMatrix(const Matrix &matrix) const
{
    // Extract elements of the matrix for clarity
    double m00 = matrix.Elements(0, 0);
    double m01 = matrix.Elements(0, 1);
    double m02 = matrix.Elements(0, 2);
    double m10 = matrix.Elements(1, 0);
    double m11 = matrix.Elements(1, 1);
    double m12 = matrix.Elements(1, 2);
    double m20 = matrix.Elements(2, 0);
    double m21 = matrix.Elements(2, 1);
    double m22 = matrix.Elements(2, 2);

    // Calculate the new vector components
    double resultX = X() * m00 + Y() * m10 + Z() * m20;
    double resultY = X() * m01 + Y() * m11 + Z() * m21;
    double resultZ = X() * m02 + Y() * m12 + Z() * m22;

    return GeomVector(resultX, resultY, resultZ);
}

GeomVector GeomVector::projectionOnVector(const GeomVector &otherVector) const
{
    double dotProduct = getDotProduct(otherVector);
    double otherDotProduct = otherVector.getDotProduct(otherVector);
    // Check if the denominator is close to zero to avoid division by zero
    if (std::abs(otherDotProduct) < std::numeric_limits<double>::epsilon())
    {
        // Return a zero vector if the denominator is close to zero
        return GeomVector();
    }
    double scalar = dotProduct / otherDotProduct;
    return otherVector.multiplyScalar(scalar);
}

GeomVector GeomVector::projectVectorOnPlane(const GeomVector &vector, const GeomVector &planeNormal) const
{
    GeomVector projection = vector.projectionOnVector(planeNormal);
    GeomVector answer = vector - projection;
    return answer;
}