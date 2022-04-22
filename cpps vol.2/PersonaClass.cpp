#include <iostream>
#include <stdio.h> 
#include <string>
using namespace std;

class Persona {
    private: string nombre;
    int telefono;
    public: void getPersona(string n, int t) {
        this -> nombre = n;
        this -> telefono = t;
    }

    string setPersona() {
        return "Nombre " + this -> nombre + to_string(this -> telefono);
    }
};

int main() {
    Persona personas[2];
    int contador = 0;
    do {
        system("cls");
        string n;
        int t;
        cout << "nombre: ";
        cin >> n;
        cout << "telefono: ";
        cin >> t;
        personas[contador].getPersona(n, t);
        contador++;
    } while (contador < 2);

    for (int i = 0; i < 2; i++) {
        cout << personas[i].setPersona() << endl;
    }
}