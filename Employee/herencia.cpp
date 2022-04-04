// Demonstrating downcasting and runtime type information.
// NOTE: You may need to enable RTTI on your compiler before you can compile
// this application.
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

int main1() {
    // set floating-point formatting
    cout << fixed << setprecision(2);

    CommissionEmployee comissionEmployee{"Sue","Jones","222-22-2222",1000,0.6};
    CommissionEmployee* c1= new CommissionEmployee("Bob","Lewis","333-33-3333",5000,0.4);
    BasePlusCommissionEmployee basepluscomissionemployee{"Bob","Lewis","333-33-3333",5000,0.4,300};
    CommissionEmployee* comissionEmployeePtr{&comissionEmployee};
    
    
    double baseSalary= ((BasePlusCommissionEmployee*)comissionEmployeePtr)->getBaseSalary();
    ((BasePlusCommissionEmployee*)comissionEmployeePtr)->setBaseSalary(500);

  
   



    return 0;



    cout<<"Calling toString() with a Base-Class pointer to\n ";
    cout<<comissionEmployeePtr->toString();


    CommissionEmployee* commissionEmployeePtr=&basepluscomissionemployee;
    cout<<"calling to string with base-class pointer to";
    cout<<commissionEmployeePtr->toString();

    cout << "Display Base-Class and Derived-Class objects:\n";
    cout<<comissionEmployee.toString();
    cout<<"\n\n";
    cout<<basepluscomissionemployee.toString();

    //Assinging the adress of a base-class object to a derived-class pointer, results error
    //ComissionEmployee comissionEpmployeee{"sue","Jones","222-222",100,0.6}
    //BasePlussCommissionEmployee* basePlusCommissionEmployeePtr{&commissionEmployeee}

    //Las diapositivas 

    //DOWNCASTING
    
    /*Employee* obj= new SalariedEmployee("John", "Smith", "111-11-1111", 800);
    //SalariedEmployee* obj= new SalariedEmployee("John", "Smith", "111-11-1111", 800);
    cout<<obj->toString();
    CommissionEmployee* bar = (CommissionEmployee*)obj;
    bar->toString();//conversión de otra manera
    //cout<<(dynamic_cast<SalariedEmployee*>(obj))->foo();//Conversión a algo más específico
    //obj = new CommissionEmployee("Sue", "Jones", "333-33-3333", 10000, .06);
    //cout<<obj->toString();
    //cout<<obj->foo();
    return 0;


    

    // create and initialize vector of three base-class pointers
    vector < Employee *> employees {
        new SalariedEmployee("John", "Smith", "111-11-1111", 800),
        new CommissionEmployee("Sue", "Jones", "333-33-3333", 10000, .06),
        new BasePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", 5000, .04, 300)
    };



    // polymorphically process each element in vector employees
    for (Employee * employeePtr : employees) {
        cout << employeePtr -> toString() << endl; // output employee

        // attempt to downcast pointer, de ahora en adelante te voy a tratar como
        //base plus commission employee
        BasePlusCommissionEmployee * derivedPtr = dynamic_cast < BasePlusCommissionEmployee *> (
            employeePtr
        );

        // determine whether element points to a BasePlusCommissionEmployee
        if (derivedPtr != nullptr) { // true for "is a" relationship
            double oldBaseSalary = derivedPtr -> getBaseSalary();
            cout << "old base salary: $" << oldBaseSalary << endl;
            derivedPtr -> setBaseSalary(1.10 * oldBaseSalary);
            cout << "new base salary with 10% increase is: $" << derivedPtr -> getBaseSalary() << endl;
        }

        cout << "earned $" << employeePtr -> earnings() << "\n\n";
    }

    // release objects pointed to by vector’s elements
    for (const Employee * employeePtr : employees) {
        // output class name
        cout << "deleting object of " << typeid( * employeePtr).name() << endl;

        delete employeePtr;
    }*/
}

