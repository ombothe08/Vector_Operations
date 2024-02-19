#include <iostream>
#include <vector>
#include <string>
#include "./headers/GeomVector.h"
#include "./headers/Writer.h"
#include "./headers/Matrix.h"
#include "./headers/Plane.h"
#include 
int main()
{
    int choice;
    double x, x1;
    double y, y1;
    double z, z1;
    
    while (1)
    {
        std::cout << "1. Check if two vectors are equal" << std::endl
                  << "2. Find magnitude of vector" << std::endl
                  << "3. Find normalized vector" << std::endl
                  << "4. Set new Vector-Length" << std::endl
                  << "5. Add Scalar Value to Vector" << std::endl
                  << "6. Subtract scalar value from vector" << std::endl
                  << "7. Multiply Vector by Scalar Value" << std::endl
                  << "8. Divide Vector by a Scalar Value" << std::endl
                  << "9. Add two Vectors" << std::endl
                  << "10. Dot-Product of two Vectors" << std::endl
                  << "11. Cross-Product of two Vectors" << std::endl
                  << "12. Find Direction Cosines of a Vector" << std::endl
                  << "13. Multiply Vector with Matrix" << std::endl
                  << "14. Find Distance between two Vectors" << std::endl
                  << "15. Find Distance between Vector and Plane" << std::endl
                  << "16. Find Angle between two Vectors" << std::endl
                  << "17. Find Angle between Vector and Plane" << std::endl
                  << "18. Find Projection on Vector" << std::endl
                  << "19. Find Projection on Plane " << std::endl
                  << "20. Angle between Vector and Axis" << std::endl
                  << "21. Exit" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::cout << "Enter value for x, y and z" << std::endl;
            std::cin >> x >> y >> z;
            std::cout << "Enter value for x, y and z" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            GeomVector a(x, y, z);
            GeomVector b(x1, y1, z1);
            if (a == b)
            {
                std::cout << "Two vectors are equal." << std::endl;
            }
            else
            {
                std::cout << "Two vectors are not equal." << std::endl;
            }
        }
        break;

        case 2:
        {
            std::cout << "Enter value for x, y and z" << std::endl;
            std::cin >> x >> y >> z;
            GeomVector a(x, y, z);
            std::cout << "Magnitude of two vector is " << a.getMagnitude() << std::endl;
        }
        break;

        case 3:
        {
            std::cout << "Enter value for x, y and z" << std::endl;
            std::cin >> x >> y >> z;
            GeomVector a(x, y, z);
            std::vector<GeomVector> vectors;
            vectors.push_back(a);
            
            GeomVector result = a.getNormalized();
            vectors.push_back(result);
            Writer writer;
            std::string filepath = "resources/output.txt";
            writer.write(filepath, vectors);
        }
        break;

        case 4:
        {
            int newLength;
            std::cout << "Enter value for x, y and z" << std::endl;
            std::cin >> x >> y >> z;
            GeomVector a(x, y, z);
            std::vector<GeomVector> vectors;
            vectors.push_back(a);

            std::cout << "Enter new length " << std::endl;
            std::cin >> newLength;
            GeomVector result = a.setVectorLength(newLength);

            vectors.push_back(result);
            Writer writer;
            std::string filepath = "resources/output.txt";
            writer.write(filepath, vectors);
        }

        case 5:
        {
            int scalarValue;
            std::cout << "Enter x, y and z value for vector1" << std::endl;
            std::cin >> x >> y >> z;
            GeomVector a(x, y, z);

            std::cout << "Enter integer value" << std::endl;
            std::cin >> scalarValue;

            GeomVector result = a.addScalar(scalarValue);
            std::vector<GeomVector> vectors;
            vectors.push_back(result);
            Writer writer;
            std::string filepath = "resources/output.txt";
            writer.write(filepath, vectors);
        }
        break;

        case 6:
        {
            int scalarValue;
            std::cout << "Enter x, y and z value for vector1" << std::endl;
            std::cin >> x >> y >> z;
            GeomVector a(x, y, z);

            std::cout << "Enter integer value" << std::endl;
            std::cin >> scalarValue;

            GeomVector result = a.subtractScalar(scalarValue);
            std::vector<GeomVector> vectors;
            vectors.push_back(a);
            vectors.push_back(result);
            Writer writer;
            std::string filepath = "resources/output.txt";
            writer.write(filepath, vectors);
        }
        break;
        case 7:
        {
            int scalarValue;
            std::cout << "Enter x, y and z value for vector1" << std::endl;
            std::cin >> x >> y >> z;
            GeomVector a(x, y, z);

            std::cout << "Enter integer value" << std::endl;
            std::cin >> scalarValue;

            GeomVector result = a.multiplyScalar(scalarValue);
            std::vector<GeomVector> vectors;
            vectors.push_back(a);
            vectors.push_back(result);
            Writer writer;
            std::string filepath = "resources/output.txt";
            writer.write(filepath, vectors);
        }
        break;

        case 8:
        {
            int scalarValue;
            std::cout << "Enter x, y and z value for vector1" << std::endl;
            std::cin >> x >> y >> z;
            GeomVector a(x, y, z);

            std::cout << "Enter integer value" << std::endl;
            std::cin >> scalarValue;

            GeomVector result = a.divideScalar(scalarValue);
            std::vector<GeomVector> vectors;
            vectors.push_back(a);
            vectors.push_back(result);
            Writer writer;
            std::string filepath = "resources/output.txt";
            writer.write(filepath, vectors);
        }
        break;

        case 9:
        {
            std::cout << "Enter x, y and z value for vector1" << std::endl;
            std::cin >> x >> y >> z;
            GeomVector a(x, y, z);

            std::cout << "Enter x, y and z value for vector1" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            GeomVector b(x1, y1, z1);

            GeomVector result = a + b;
            std::vector<GeomVector> vectors;
            vectors.push_back(a);
            vectors.push_back(b);
            vectors.push_back(result);
            Writer writer;
            std::string filepath = "resources/output.txt";
            writer.write(filepath, vectors);
        }
        break;

        case 10:
        {
            std::cout << "Enter x, y and z value for vector1" << std::endl;
            std::cin >> x >> y >> z;
            GeomVector a(x, y, z);

            std::cout << "Enter x, y and z value for vector1" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            GeomVector b(x1, y1, z1);

            double result = a.getDotProduct(b);
            std::vector<GeomVector> vectors;
            vectors.push_back(a);
            vectors.push_back(b);
            std::cout << "dot product is " << result << std::endl;
            Writer writer;
            std::string filepath = "resources/output.txt";
            writer.write(filepath, vectors);
        }
        break;

        case 11:
        {
            std::cout << "Enter x, y and z value for vector1" << std::endl;
            std::cin >> x >> y >> z;
            GeomVector a(x, y, z);

            std::cout << "Enter x, y and z value for vector1" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            GeomVector b(x1, y1, z1);

            GeomVector result = a.getCrossProduct(b);
            std::vector<GeomVector> vectors;
            vectors.push_back(a);
            vectors.push_back(b);
            vectors.push_back(result);
            Writer writer;
            std::string filepath = "resources/output.txt";
            writer.write(filepath, vectors);
        }
        break;

        case 12:
        {
            std::cout << "Enter x, y and z value for vector1" << std::endl;
            std::cin >> x >> y >> z;
            GeomVector a(x, y, z);
            a.directionCosines();
            std::vector<GeomVector> vectors;
            vectors.push_back(a);
        }
        break;

        case 13:
        {
            std::cout << "Enter x, y and z value for vector1" << std::endl;
            std::cin >> x >> y >> z;
            GeomVector a(x, y, z);

            double s, b, c, d, e, f, g, h, i;
            std::cout << "Enter the elements of the 3 x 3 matrix: ";
            std::cin >> s >> b >> c >> d >> e >> f >> g >> h >> i;
            Matrix matrix(s, b, c, d, e, f, g, h, i);

            GeomVector result = a.multiplyMatrix(matrix);
            std::vector<GeomVector> vectors;
            vectors.push_back(a);
            vectors.push_back(result);
            Writer writer;
            std::string filepath = "resources/output.txt";
            writer.write(filepath, vectors);
        }
        break;

        case 14:
        {
            std::cout << "Enter x, y and z value for vector1" << std::endl;
            std::cin >> x >> y >> z;
            GeomVector a(x, y, z);

            std::cout << "Enter x,y and z value for vector2" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            GeomVector b(x1, y1, z1);

            double result = a.getDistanceBetweenVectors(b);
            std::cout << "Distance between two vectors is " << result << std::endl;
        }
        break;

        case 15:
        {
            double x2;
            double y2;
            double z2;
            std::cout << "Enter x, y and z value for vector1" << std::endl;
            std::cin >> x >> y >> z;
            GeomVector a(x, y, z);

            std::cout << "Enter x,y and z value for normal" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            GeomVector normal(x1, y1, z1);

            std::cout << "Enter 3 coordinates for point" << std::endl;
            std::cin >> x2 >> y2 >> z2;
            Point3D point(x2, y2, z2);

            Plane plane(normal, point);
            double result = a.getDistanceBetweenVectorAndPlane(plane);
            std::cout << "Distance between vector and plane is " << result << std::endl;
        }
        break;

        case 16:
        {

            std::cout << "Enter x, y and z value for vector1" << std::endl;
            std::cin >> x >> y >> z;
            GeomVector a(x, y, z);

            std::cout << "Enter x,y and z value for normal" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            GeomVector b(x1, y1, z1);

            double result = a.getAngleBetweenVectors(b);
            std::cout << "Angle between two vectors is " << result << std::endl;
        }
        break;

        case 17:
        {
            double x2;
            double y2;
            double z2;
            std::cout << "Enter x, y and z value for vector1" << std::endl;
            std::cin >> x >> y >> z;
            GeomVector a(x, y, z);

            std::cout << "Enter x,y and z value for normal" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            GeomVector normal(x1, y1, z1);

            std::cout << "Enter 3 coordinates for point" << std::endl;
            std::cin >> x2 >> y2 >> z2;
            Point3D point(x2, y2, z2);

            Plane plane(normal, point);
            double result = a.getAngleBetweenVectorAndPlane(plane);
            std::cout << "angle between vector and plane is " << result << std::endl;
        }
        break;

        case 18:
        {
            std::cout << "Enter x, y and z value for vector1" << std::endl;
            std::cin >> x >> y >> z;
            GeomVector a(x, y, z);

            std::cout << "Enter x,y and z value for normal" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            GeomVector b(x1, y1, z1);

            GeomVector result = a.projectionOnVector(b);
            std::vector<GeomVector> vectors;
            vectors.push_back(a);
            vectors.push_back(b);
            vectors.push_back(result);
            Writer writer;
            std::string filepath = "resources/output.txt";
            writer.write(filepath, vectors);
        }
        break;

        case 19:
        {
            double x2;
            double y2;
            double z2;
            std::cout << "Enter x, y and z value for vector1" << std::endl;
            std::cin >> x >> y >> z;
            GeomVector a(x, y, z);

            std::cout << "Enter x,y and z value for normal" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            GeomVector normal(x1, y1, z1);

            GeomVector result = a.projectVectorOnPlane(a, normal);
            std::vector<GeomVector> vectors;
            vectors.push_back(a);
            vectors.push_back(normal);
            vectors.push_back(result);
            Writer writer;
            std::string filepath = "resources/output.txt";
            writer.write(filepath, vectors);
        }

        case 21: // Exit case
            break;

        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }

    return 0;
}
