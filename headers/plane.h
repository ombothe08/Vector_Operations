#include "point3D.h"
class plane 
{
    public:
    plane();
    ~plane();

    plane(point3D point , point3D v1 ,point3D v2);

    void sPoint(point3D mPoint);
    void sVector1(point3D v1);
    void sVectoV2(point3D v2);

    point3D gPoint();
    point3D gVector1();
    point3D gVector2();

    private:
    point3D mPoint;
    point3D mV1;
    point3D mV2;



    
};