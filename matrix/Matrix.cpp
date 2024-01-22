#include "Matrix.hpp"
#include <utility>


Matrix::Matrix() :  _data() {}
Matrix::Matrix(int rows, int cols, double val): _data(rows, std::vector<double>(cols, val)) {}
Matrix::Matrix(Matrix* other){

    _data.resize(other->Rows());
    for(int i = 0; i < this->Rows(); i++){
        _data[i].resize(other->Cols());
    }

    for (int i = 0; i < this->Rows(); i++){
        for (int j = 0; j < this->Cols(); j++){
            _data[i][j] = (*other)[i][j];
        }
    }

     
}

//size of matrix
int Matrix::Rows() const{
    return _data.size();
}

int Matrix::Cols() const{
    if(_data.size() == 0){
        return 0;
    }
    return _data[0].size();
}

std::pair<int, int> Matrix::Size()const {
    std::pair<int, int> p;
    p.first = this->Rows();
    p.second = this->Cols();

    return p;
}

//Adding a row to a matrix
void Matrix::AddRow(std::vector<double>& row){
    if(int(row.size()) == this->Cols()){
        _data.push_back(row);
    }
    else{
        throw "Cant add row, not the same size with matrix rows";
    }
}

//print out content of matrix
void Matrix::show(std::ostream& os) const{
    
    for(int i = 0; i < this->Rows(); i++){
        for(int j = 0; j < this->Cols(); j++){
            os << std::setw(6) << (*this)[i][j] << " ";
        }
        os << std::endl;
    }
}

//assignment operator not needed but im writting it for practice
Matrix& Matrix::operator = (Matrix& other){
    
    if(this == &other){
        return *this;
    }

    _data = other._data;

    return *this;
}

//arithmetic operators written in pair 

// M + M
//return value is pointer to new object on heap for easier manipulation later in parser)
/*This implementation will be used because in parser grammar
    expression nonterminal will be type Matrix*, and regular numbers will be
    portrayed as 1x1 Matrix
*/
Matrix* Matrix::operator +(Matrix& other) const{

    Matrix* result = nullptr;
    
    if(this->Rows() == 1 && this->Cols() == 1){
        
        result = new Matrix(other.Rows(), other.Cols());

        for( int i = 0; i < other.Rows(); i++){
           for(int j = 0; j < other.Cols(); j++){
                (*result)[i][j] = other[i][j] + _data[0][0];
            }
        }
    }
    else if(other.Rows() == 1 && other.Cols() == 1){

        result = new Matrix(this->Rows(), this->Cols());

        for( int i = 0; i < this->Rows(); i++){
           for(int j = 0; j < this->Cols(); j++){
                (*result)[i][j] = _data[i][j] + other[0][0];
            }
        }
    }
    else{

        if(this->Rows() != other.Rows() || this->Cols() != other.Cols()){
            return nullptr;
        }

        result = new Matrix(this->Rows(), this->Cols());

        for(int i = 0; i < this->Rows(); i++){
            for(int j = 0; j < this->Cols(); j++){
                result->_data[i][j] = this->_data[i][j] + other._data[i][j];
            }
        }
    }

    return result;
}

Matrix* Matrix::operator -(Matrix& other) const{

    Matrix* result = nullptr;
    
    if(this->Rows() == 1 && this->Cols() == 1){
        
        result = new Matrix(other.Rows(), other.Cols());

        for( int i = 0; i < other.Rows(); i++){
           for(int j = 0; j < other.Cols(); j++){
                (*result)[i][j] = _data[0][0] - other[i][j];
            }
        }
    }
    else if(other.Rows() == 1 && other.Cols() == 1){

        result = new Matrix(this->Rows(), this->Cols());

        for( int i = 0; i < this->Rows(); i++){
           for(int j = 0; j < this->Cols(); j++){
                (*result)[i][j] = _data[i][j] - other[0][0];
            }
        }
    }
    else{

        if(this->Rows() != other.Rows() || this->Cols() != other.Cols()){
            return nullptr;
        }

        result = new Matrix(this->Rows(), this->Cols());

        for(int i = 0; i < this->Rows(); i++){
            for(int j = 0; j < this->Cols(); j++){
                result->_data[i][j] = this->_data[i][j] - other[i][j];
            }
        }
    }

    return result;
}

Matrix* Matrix::operator *(Matrix& other) const{

    Matrix* result = nullptr;

    if(this->Rows() == 1 && this->Cols() == 1){
        
        result = new Matrix(other.Rows(), other.Cols());
        
        for(int i = 0; i < other.Rows(); i++){
            for(int j = 0; j < other.Cols(); j++){
                (*result)[i][j] = (*this)[0][0] * other[i][j];
            }
        }
    }
    else if(other.Rows() == 1 && other.Cols() == 1){

        result = new Matrix(this->Rows(), this->Cols());

        for(int i = 0; i < this->Rows(); i++){
            for(int j = 0; j < this->Cols(); j++){
                (*result)[i][j] = (*this)[i][j] * other[0][0];
            }
        }

    }
    else{

        if(this->Cols() != other.Rows()){
            return nullptr;
        }

        result = new Matrix(this->Rows(), other.Cols());

        for(int i = 0; i < result->Rows(); i++){
            for(int j = 0; j < result->Cols(); j++){

                double r = 0;
                for(int k = 0; k < this->Cols(); k++){
                    r += (*this)[i][k] * other[k][j];
                }
                (*result)[i][j] = r;
            }
        }
    }

    return result;
}

Matrix* Matrix::MultiplyByCoordinates(Matrix& other) const{

    if(this->Rows() != other.Rows() || this->Cols() != other.Cols()){
        return nullptr;
    }
    Matrix* result = new Matrix(this->Rows(), this->Cols());

    for(int i = 0; i < this->Rows(); i++){
        for (int j = 0; j < this->Cols(); j++){

            (*result)[i][j] = (*this)[i][j] * other[i][j];
        }
    }

    return result;
}

//unar - operator
Matrix* Matrix::operator -() const{

    Matrix* result = new Matrix(this->Rows(), this->Cols());
    for(int i = 0; i < this->Rows(); i++){
        for(int j = 0; j < this->Cols(); j++){
            (*result)[i][j] = -(*this)[i][j];
        }
    }

    return result;
}

//arithmetics over
//------------------------------------------------

//operators for accesing data in matrix
std::vector<double>& Matrix::operator [](int i){
    if(i < 0 || i >= this->Rows()){
        throw "Index out of bounds";
    }
    return _data[i];
}

const std::vector<double>& Matrix::operator [](int i) const{
    if(i < 0 || i >= this->Rows()){
        throw "Index out of bounds";
    }
    return _data[i];
}

Matrix* Matrix::Transpose() const {

    Matrix* result = new Matrix(this->Cols(), this->Rows());

    for(int i = 0; i < result->Rows(); i++){
        for(int j = 0; j < result->Cols(); j++){
            (*result)[i][j] = (*this)[j][i];
        }
    }

    return result;
}

Matrix* Matrix::SubMatrix(std::pair<int, int>& rows, std::pair<int, int>& cols) const{

    int rowFrom = rows.first;
    int rowTo = rows.second;
    int colFrom = cols.first;
    int colTo = cols.second;

    if(rowFrom < 0 || rowFrom >= this->Rows() || rowTo < 0 || rowTo >= this->Rows()
        || colFrom < 0 || colFrom >= this->Cols() ||  colTo < 0 || colTo >= this->Cols()
        || rowTo < rowFrom || colTo < colFrom)
        {
            return nullptr;
        }

//  n and m are dimensions of result Matrix
    int n = rowTo - rowFrom + 1;
    int m = colTo - colFrom + 1;

    Matrix* result = new Matrix(n, m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            (*result)[i][j] = (*this)[i + rowFrom][j + colFrom];
        }
    }

    return result;
}


//logic operators
bool Matrix::operator ==(Matrix& other) const{
    if(this->Rows() != other.Rows() || this->Cols() != other.Cols()){
        return false;
    }

    for(int i = 0; i < this->Rows(); i++){
        for(int j = 0; j < this->Cols(); j++){
            if((*this)[i][j] != other[i][j]){
                return false;
            }
        }
    }

    return true;
}

bool Matrix::operator !=(Matrix& other) const{
    if((*this) == other){
        return false;
    }
    return true;
}

std::ostream& operator <<(std::ostream& os, const Matrix& m){
    m.show(os);
    return os;
}
std::ostream& operator <<(std::ostream& os, std::pair<int, int> p){
    os << p.first << " x " << p.second;
    return os;
}

int main(){

    Matrix a = Matrix(3, 4, 4);
    std::cout << *(-a) << std::endl;

    return 0;
}