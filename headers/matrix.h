#pragma once
class Matrix
{
public:
    Matrix();
    Matrix(double a, double b, double c, double d, double e, double f, double g, double h, double i);
    ~Matrix()=default;

    double Elements(int row, int col) const;

private:
    double matrix[3][3];
};
