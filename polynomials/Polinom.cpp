#include "Polinom.hpp"
#include <algorithm>

void Polinom::Normalize(){

    while(_coef.size() > 0 && _coef[_coef.size() - 1] == 0){
        _coef.pop_back();
    }
}

Polinom::Polinom() : _coef() {}

Polinom::Polinom(int n) : _coef(n+1, 0){
    _coef[_coef.size() - 1] = 1;
}

Polinom::Polinom(Polinom* p){

    int n = p->_coef.size()

    for(int i = 0; i < n; i++){
        _coef.push_back(p->_coef[i]);
    }
}

void Polinom::AddCoef(double v){
    _coef.push_back(v);
}

void Polinom::show(std::ostream& os){

    bool prvi = true;
    for(int i = 0; i < _coef.size(); i++){
        if(_coef[i] == 0)
            continue;

        if(prvi){
            if(_coef[i] > 0){
                os << _coef[i];
                prvi = false;
            }
            else{
                os << "-" << _coef[i];
                prvi = false;
            }
        }
        else {
            if(_coef[i] > 0){
                os << " + " << fabs(_coef[i]);
            }
            else{
                os << " - " << fabs(_coef[i]);
            }
        }
        if(i > 0){
            os << "x^" << i;
        }
    }
    if(_coef.size() == 0){
        os << "0";
    }
}


Polinom& Polinom::operator = (const Polinom& other){
    
    if(this == &other){
        return *this;
    }

    _coef = other._coef;

    return *this;
}

Polinom* Polinom::operator +(const Polinom& other) const{

    int n = std::min(_coef.size(), other._coef.size());

    Polinom* result = new Polinom();

    int i = 0;
    for(i = 0; i < n; i++){
        result->AddCoef(_coef[i] + other._coef[i]);
    }

    while(i < _coef.size()){
        result->AddCoef(_coef[i]);
        i++;
    }
    while(i < other._coef.size()){
        result->AddCoef(other._coef[i]);
        i++;
    }

    result->Normalize();

    return result;
}
Polinom* Polinom::operator -(const Polinom& other) const{

    Polinom result = new Polinom();

    int n = std::min(_coef.size(), other._coef.size());

    int i = 0;
    for(i = 0; i < n; i++){
        result->AddCoef(_coef[i] - other._coef[i]);
    }

    while(i < _coef.size()){
        result->AddCoef(_coef[i]);
        i++;
    }
    while(i < other._coef.size()){
        result->AddCoef(-other._coef[i]);
        i++;
    }

    result->Normalize();

    return result;
}

Polinom* Polinom::operator *(const Polinom& other) const{

    Polinom* result = Polinom(this->Degree() + other.Degree() + 1);
    result->_coef[result->_coef.size() - 1] = 0;

    for(int i = 0; i <_coef.size(); i++){
        for(int j = 0; j < other._coef.size(); j++){

            result->_coef[i+j] += _coef[i] * other._coef[j];
        }
    } 

    return result;
}