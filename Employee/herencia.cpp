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

int main() {
    // set floating-point formatting
    cout << fixed << setprecision(2);

    Employee* obj= new SalariedEmployee("John", "Smith", "111-11-1111", 800);
    //SalariedEmployee* obj= new SalariedEmployee("John", "Smith", "111-11-1111", 800);
    cout<<obj->toString();
    CommissionEmployee* bar = (CommissionEmployee*)obj;
    bar->toString();//conversión de otra manera
    //cout<<(dynamic_cast<SalariedEmployee*>(obj))->foo();//Conversión a algo más específico
    //obj = new CommissionEmployee("Sue", "Jones", "333-33-3333", 10000, .06);
    //cout<<obj->toString();
    //cout<<obj->foo();
    return 0;


    // ya dale clases de programación a este brother (:

    // create and initialize vector of three base-class pointers
    vector < Employee *> employees {
        new SalariedEmployee("John", "Smith", "111-11-1111", 800),
        new CommissionEmployee("Sue", "Jones", "333-33-3333", 10000, .06),
        new BasePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", 5000, .04, 300)
    };

//sites.google.com/up.edu.mx/poo/mis-clases/tema_4

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
    }
}

/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/