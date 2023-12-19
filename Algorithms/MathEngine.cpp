#include <iostream>
#include <vector>
#include <initializer_list>

class Vector 
{
public:
    Vector() {}
    Vector(std::initializer_list<double> values) : elements(values) {}

    Vector operator+(const Vector& other) const 
    {
        Vector result;
        for (size_t i = 0; i < elements.size(); i++) {
            result.elements.push_back(elements[i] + other.elements[i]);
        }
        return result;
    }

    Vector operator-(const Vector& other) const 
    {
        Vector result;
        for (size_t i = 0; i < elements.size(); i++) {
            result.elements.push_back(elements[i] - other.elements[i]);
        }
        return result;
    }

    double& operator[](size_t index) 
    {
        return elements[index];
    }

    const double& operator[](size_t index) const 
    {
        return elements[index];
    }

    size_t size() const 
    {
        return elements.size();
    }

private:
    std::vector<double> elements;
};

class Matrix 
{
public:
    Matrix() {}
    Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), elements(rows * cols) {}

    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);
        for (size_t i = 0; i < elements.size(); i++) {
            result.elements[i] = elements[i] + other.elements[i];
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix result(rows, cols);
        for (size_t i = 0; i < elements.size(); i++) {
            result.elements[i] = elements[i] - other.elements[i];
        }
        return result;
    }

    double& operator()(size_t row, size_t col) {
        return elements[row * cols + col];
    }

    const double& operator()(size_t row, size_t col) const {
        return elements[row * cols + col];
    }

    size_t numRows() const {
        return rows;
    }

    size_t numCols() const {
        return cols;
    }

private:
    size_t rows;
    size_t cols;
    std::vector<double> elements;
};

int main() {
    Vector v1 = {1.0, 2.0, 3.0};
    Vector v2 = {4.0, 5.0, 6.0};
    Vector v3 = v1 + v2;

    Matrix m1(2, 2);
    m1(0, 0) = 1.0;
    m1(0, 1) = 2.0;
    m1(1, 0) = 3.0;
    m1(1, 1) = 4.0;

    Matrix m2(2, 2);
    m2(0, 0) = 5.0;
    m2(0, 1) = 6.0;
    m2(1, 0) = 7.0;
    m2(1, 1) = 8.0;

    Matrix m3 = m1 + m2;

    std::cout << "v3 = ";
    for (size_t i = 0; i < v3.size(); i++)
    {
        std::cout << v3[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "m3 = " << std::endl;
    for (size_t i = 0; i < m3.numRows(); i++) 
    {
        for (size_t j = 0; j < m3.numCols(); j++) 
        {
            std::cout << m3(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
