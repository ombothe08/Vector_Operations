#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    double rows;
    double cols;

public:
    // Constructor
    Matrix(double rows, double cols) : rows(rows), cols(cols) {
        // Initialize matrix with zeros
        data.resize(rows, std::vector<int>(cols, 0));
    }

    // Accessor for number of rows
    double numRows()  {
        return rows;
    }

    // Accessor for number of columns
    double numCols()  {
        return cols;
    }

    // Accessor to get element at specific row and column
    int getElement(double row, double col)  {
        return data[row][col];
    }

    // Modifier to set element at specific row and column
    void setElement(double row, double col, int value) {
        data[row][col] = value;
    }

    // Overload the multiplication operator for scalar multiplication
    Matrix operator*(int scalar) const {
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] * scalar;
            }
        }
        return result;
    }

    // Overload the addition operator for matrix addition
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrices must have the same dimensions for addition");
        }
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Overload the output stream operator for printing
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (size_t i = 0; i < matrix.rows; ++i) {
            for (size_t j = 0; j < matrix.cols; ++j) {
                os << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }
};


