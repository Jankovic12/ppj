#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <cmath>
#include <utility>


class Matrix{

private:
    std::vector<std::vector<double>> _data;

public:
    //constructors
    Matrix();
    Matrix(int rows, int cols, double v=0);
    Matrix(Matrix* other);

    //Matrix size and rows and column size
    int Rows() const;
    int Cols() const;
    std::pair<int, int> Size() const;


    //adding rows to matrix 
    void AddRow(std::vector<double>& row);

    void show(std::ostream& os) const;

    Matrix& operator =(Matrix& other) ;
    //arithmetic operators return pointers to new objects on heap for easier managment in parser
    Matrix* operator +(Matrix& other) const;
    //Matrix* operator +(double c) const;

    Matrix* operator -(Matrix& other) const;
    //Matrix* operator -(double c) const;


    Matrix* operator *(Matrix& other) const;
    //Matrix* operator *(double c) const;

    //custom multiplication for multiplying numbers that have same [i][j] coordinates
    Matrix* MultiplyByCoordinates(Matrix& other) const;

    //operator [] overload for accessing vector of matrix 
    //when we use m[i][j] first one is overloaded version, and other is regular vector operator []
    std::vector<double>& operator [](int i);
    const std::vector<double>& operator[](int i) const;

    Matrix* Transpose() const;

    Matrix* SubMatrix(std::pair<int, int>& rows, std::pair<int, int>& cols) const;

    //logic operators
    bool operator ==(Matrix& other) const;
    bool operator !=(Matrix& other) const;

};

std::ostream& operator <<(std::ostream& os, const Matrix& m);
std::ostream& operator <<(std::ostream& os, std::pair<int, int>& p);

//arithmetic operators for type `constant + Matrix` 
// Matrix* operator +(double c, Matrix& m);


#endif