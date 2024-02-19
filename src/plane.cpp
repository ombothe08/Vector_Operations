#include "../headers/plane.h"


plane ::plane()
{
    
}
plane ::plane(point3D point, point3D v1, point3D v2)
{
    this->mPoint = point;
    this->mV1 = v1;
    this->mV2 = v2;
}
plane :: ~plane()
{

}

void plane ::sPoint(point3D mPoint)
{
    this->mPoint = mPoint;
}
void plane:: sVector1(point3D v1)
{
    mV1 = v1;
}
void plane :: sVectoV2(point3D v2)
{
    mV2 = v2;
    
}

point3D plane :: gPoint()
{
    return mPoint;
}
point3D plane ::  gVector1()
{
    return mV1;

}
point3D plane :: gVector2(){
    return mV2;
}
