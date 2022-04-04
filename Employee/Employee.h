#pragma once

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string> 

class Employee {
public:
    Employee(const std::string&, const std::string&, const std::string&);
    virtual ~Employee() = default; // Destructor virtual

    void setFirstName(const std::string&); 
    std::string getFirstName() const; 

    void setLastName(const std::string&);
    std::string getLastName() const; 

    void setSocialSecurityNumber(const std::string&); 
    std::string getSocialSecurityNumber() const;

    // Funci�n virtual. La clase Employee es abstacta
    virtual double earnings() const = 0; // pure virtual
    //Funci�n virtual: puede anularse en clases derivadas
    virtual std::string toString() const; // virtual 
  
          
private:
    std::string firstName;
    std::string lastName;
    std::string socialSecurityNumber;
};

#endif // EMPLOYEE_H

