#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
#include "Employee.cpp"
#include "SalariedEmployee.cpp"
#include "CommissionEmployee.cpp"
#include "BasePlusCommissionEmployee.cpp"
using namespace std;

class Base {
    public: Base() {
        cout << "Constructor de la clase base sin argumentos" << endl;
    }
    Base(int arg) {
        this -> arg = arg;
    }

    virtual string fVirtualPura() {
        return "Ya no es pura";
    }
    virtual string fVirtual() {
        return "fVirtual de la clase base";
    }

    string ffinalBase() {
        return "ffinalBase";
    }

    private: int arg = 0;

};

class Derivada1 : public Base
{

};

class Derivada11 : public Derivada1{
    public:
    virtual string fVirtual(){
        return "fVirtual de la lcase Derviada11";
    }
};

class Presidente {

public: 
    static Presidente* creaPresidente() {
        return &Presidente();
    }

private: 
    string nombre = "Jhon Doe";
};

int main(){

    Presidente* p1 = Presidente::creaPresidente();
    Presidente* p2 = Presidente::creaPresidente();

}

