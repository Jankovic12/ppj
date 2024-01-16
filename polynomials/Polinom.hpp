#ifndef POLINOM_H
#define POLINOM_H

#include <iostream>
#include <vector>
#include <cmath>


class Polinom{

private:
    std::vector<double> _coef;
    void Normalize();

public:
    //konstruktori
    Polinom();
    Polinom(int n);
    Polinom(Polinom* other);
    
    //ispis
    void show(std::ostream os)const;

    //binarni operatori koristimo pokazivace zbog lakseg koriscenja u parseru
    Polinom& operator =(const Polinom& other);
    Polinom* operator +(const Polinom& other) const;
    Polinom* operator -(const Polinom& other) const;
    Polinom* operator /(const Polinom& other) const;
    //unarni
    Polinom* operator -();

    //dodavanje koeficijenta na kraj i prikazivanje stepena
    void AddCoef(double v);
    int Degree() const;

    //funkcije izvoda i integrala
    Polinom* Derivative() const;
    Polinom* Integral(double c) const;

    //logicki operatori
    bool operator ==(const Polinom& other) const;
    bool operator != (const Polinom& other) const;

};

std::ostream& operator <<(std::ostream& os, const Polinom& p);


#endif