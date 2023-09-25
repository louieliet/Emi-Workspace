#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Persona{
    int edad;
    string nombre;
};

class Usuario{
public:
    void mostarNombre();
private:
    string username;
    string nombrereal;
};


int foo(int a, int b);


