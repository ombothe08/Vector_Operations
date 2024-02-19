#include <iostream>
#include <fstream>
#include "headers/point3D.h"
#include "headers/geomVector.h"
using namespace std;

point3D inputPoint(const string &prompt)
{
    double x, y, z;
    cout << prompt << endl;
    cout << "Enter x coordinate: ";
    cin >> x;
    cout << "Enter y coordinate: ";
    cin >> y;
    cout << "Enter z coordinate: ";
    cin >> z;
    return point3D(x, y, z);
}

int main()
{
    geomVector vectorCalculator; // Create an instance of geomVector

    int choice;
    cout << "Enter your choice:" << endl;
    cout << "1. Dot Product" << endl;
    cout << "2. Cross Product" << endl;
    cout << "3. Vector Magnitude" << endl;
    cout << "4. Vector Normalized" << endl;
    cout << "5. Is Equal" << endl;
    cout << "6. Add Scalar" << endl;
    cout << "7. Vector Scalar Multiplication" << endl;
    cout << "8. Angle Between Vectors" << endl;
    cout << "9. Distance Between Vectors" << endl;
    cout << "10. Subtract Scalar" << endl;
    cout << "11. Vector Scalar Division" << endl;
    cout << "12. Angle Between Plane and Vector" << endl;
    cout << "13. Direction Cosines" << endl;

    cin >> choice;

    point3D v1, v2, v3, v4;

    ofstream first("vector1.txt");

    ofstream second("vector2.txt");

    ofstream out("output.txt");

    // Take input for the vector points
    //cout << "Enter coordinates for vector 1:" << endl;

    switch (choice)
    {
    case 1:
    {
        cout << "Enter coordinates for vector 1:" << endl;
        v1 = inputPoint("Vector 1");
        cout << "Enter coordinates for vector 2:" << endl;
        v2 = inputPoint("Vector 2");
        cout << "Enter coordinates for vector 3:" << endl;
        v3 = inputPoint("Vector 3");
        cout << "Enter coordinates for vector 4:" << endl;
        v4 = inputPoint("Vector 4");

        cout << "Dot Product: " << vectorCalculator.dotProduct(v1, v2, v3, v4) << endl;
        break;
    }

    case 2:
    {
        cout << "Enter coordinates for vector 1:" << endl;
        v1 = inputPoint("Vector 1");
        cout << "Enter coordinates for vector 2:" << endl;
        v2 = inputPoint("Vector 2");
        first << v1.x() << " " << v1.y() << " " << v1.z() << " " << v2.x() << " " << v2.y() << " " << v2.z() << " " << endl;
        cout << "Enter coordinates for vector 3:" << endl;
        v3 = inputPoint("Vector 3");
        cout << "Enter coordinates for vector 4:" << endl;
        v4 = inputPoint("Vector 4");
        second << v3.x() << " " << v3.y() << " " << v3.z() << " " << v4.x() << " " << v4.y() << " " << v4.z() << " " << endl;
        point3D ans = vectorCalculator.crossProduct(v1, v2, v3, v4);
        out << ans.x() << " " << ans.y() << " " << ans.z() << " " << 0 << " " << 0 << " " << 0 << " " << endl;
        break;
    }

    case 3:
    {
        cout << "Enter coordinates for vector 1:" << endl;
        v1 = inputPoint("Vector 1");
        cout << "Enter coordinates for vector 2:" << endl;
        v2 = inputPoint("Vector 2");
        first << v1.x() << " " << v1.y() << " " << v1.z() << " " << v2.x() << " " << v2.y() << " " << v2.z() << " " << endl;
        cout << "Vector Magnitude: " << vectorCalculator.vectorMagnitude(v1, v2) << endl;
        break;
    }

    case 4:
    {
        cout << "Enter coordinates for vector 1:" << endl;
        v1 = inputPoint("Vector 1");
        cout << "Enter coordinates for vector 2:" << endl;
        v2 = inputPoint("Vector 2");
        first << v1.x() << " " << v1.y() << " " << v1.z() << " " << v2.x() << " " << v2.y() << " " << v2.z() << " " << endl;
        point3D ans = vectorCalculator.vectorNormalized(v1, v2);
      out << ans.x() << " " << ans.y() << " " << ans.z() << " " << 0 << " " << 0 << " " << 0 << " " << endl;
        break;
    }

    case 5:
    {
        cout << "Enter coordinates for vector 1:" << endl;
        v1 = inputPoint("Vector 1");
        cout << "Enter coordinates for vector 2:" << endl;
        v2 = inputPoint("Vector 2");
        first << v1.x() << " " << v1.y() << " " << v1.z() << " " << v2.x() << " " << v2.y() << " " << v2.z() << " " << endl;
        cout << "Enter coordinates for vector 3:" << endl;
        v3 = inputPoint("Vector 3");
        cout << "Enter coordinates for vector 4:" << endl;
        v4 = inputPoint("Vector 4");
        second << v3.x() << " " << v3.y() << " " << v3.z() << " " << v4.x() << " " << v4.y() << " " << v4.z() << " " << endl;
        cout << "Is Equal: " << (vectorCalculator.isEqual(v1, v2, v3, v4) ? "true" : "false") << endl;
        break;
    }

    case 6:
    {
        cout << "Enter coordinates for vector 1:" << endl;
        v1 = inputPoint("Vector 1");
        cout << "Enter coordinates for vector 2:" << endl;
        v2 = inputPoint("Vector 2");
        first << v1.x() << " " << v1.y() << " " << v1.z() << " " << v2.x() << " " << v2.y() << " " << v2.z() << " " << endl;
        point3D ans = vectorCalculator.addScalar(v1, v2, 5);
       out << ans.x() << " " << ans.y() << " " << ans.z() << " " << 0 << " " << 0 << " " << 0 << " " << endl;// Change 5 to the desired scalar value
        break;
    }

    case 7:
    {
        cout << "Enter coordinates for vector 1:" << endl;
        v1 = inputPoint("Vector 1");
        cout << "Enter coordinates for vector 2:" << endl;
        v2 = inputPoint("Vector 2");
        first << v1.x() << " " << v1.y() << " " << v1.z() << " " << v2.x() << " " << v2.y() << " " << v2.z() << " " << endl;
        point3D ans = vectorCalculator.vectorScalarMultiplication(v1, v2, 5);
        out << ans.x() << " " << ans.y() << " " << ans.z() << " " << 0 << " " << 0 << " " << 0 << " " << endl; // Change 5 to the desired scalar value
        break;
    }
    case 8:
    {
        cout << "Angle Between Vectors: " << vectorCalculator.angleBetweenVectors(v1, v2, v3, v4) << endl;
        break;
    }

    case 9:
    {
        cout << "Distance Between Vectors: " << vectorCalculator.distanceBetweenVectors(v1, v2, v3, v4) << endl;
        break;
    }

    case 10:
    {
        v1 = inputPoint("Vector 1");

        cout << "Enter coordinates for vector 2:" << endl;
        v2 = inputPoint("Vector 2");
        first << v1.x() << " " << v1.y() << " " << v1.z() << " " << v2.x() << " " << v2.y() << " " << v2.z() << " " << endl;
        point3D ans = vectorCalculator.subtractScalar(v1, v2, 5);
        out << ans.x() << " " << ans.y() << " " << ans.z() << " " << 0 << " " << 0 << " " << 0 << " " << endl;// Change 5 to the desired scalar value
        break;
    }

    case 11:
    {
         v1 = inputPoint("Vector 1");

        cout << "Enter coordinates for vector 2:" << endl;
        v2 = inputPoint("Vector 2");
        first << v1.x() << " " << v1.y() << " " << v1.z() << " " << v2.x() << " " << v2.y() << " " << v2.z() << " " << endl;
        cout << "Enter coordinates for vector 3:" << endl;
        v3 = inputPoint("Vector 3");

        cout << "Enter coordinates for vector 4:" << endl;
        v4 = inputPoint("Vector 4");
        second << v3.x() << " " << v3.y() << " " << v3.z() << " " << v4.x() << " " << v4.y() << " " << v4.z() << " " << endl;
        point3D ans = vectorCalculator.vectorScalarDivision(v1, v2, v3, v4, 5);
       out << ans.x() << " " << ans.y() << " " << ans.z() << " " << 0 << " " << 0 << " " << 0 << " " << endl;// Change 5 to the desired scalar value
        break;
    }

    case 12:
    {
        cout << "Angle Between Plane and Vector: " << vectorCalculator.angleBetweenPlaneandVector(plane(), v1, v2) << endl;
        break;
    }

    case 13:
    {
        vectorCalculator.directionCosines(v1, v2, v3, v4);
        break;
    }

    default:
        cout << "Invalid choice" << endl;
    }

    return 0;
}

