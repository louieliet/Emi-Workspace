#include <iostream>
using namespace std;

class Personaje {
    public: Personaje(int a, int d) {
        ataque = a;
        defensa = d;
    }

    void print() {
        cout << "Ataque = " << ataque << endl; //¿Cómo es que las funciones de una clase saben que, por ejemplo "int ataque", pertenece al objeto?
        // al usar el apuntador this, le permite acceder a su propia dirección de
        // memoria, a su propia ubicación, al estar en su propia ubicación, ya sabe qué
        // variables son propias del objeto, en esta función se ocupa de manera
        // implícita
        cout << "this->Ataque = " << this ->ataque << endl; //Imprime de manera explícita el this
        cout << "(*this).Ataque = " << ( * this).ataque << endl; //Derreferenciar el this
        //Los tres me dan en pantalla lo mismo

    }

    void printboth() {
        cout << "Ataque= " << ataque << endl;
        cout << "Defensa= " << defensa << endl;

    }

    Personaje & setDefensa(int d) {
        defensa = d;
        return * this;
    }

    Personaje & setAtaque(int a) {
        ataque = a;
        return * this;
    }

    private: int ataque,
    defensa;

};

int main() {

    Personaje Alucard(100, 90);
    Alucard.print();
    Alucard
        .setAtaque(50)
        .setDefensa(40);

    Alucard.printboth();

    return 0;
}

//En conclusión, los this-> nos sirven para poder asignar variables que sean el tipo clase que nosotros creamos sin necesidad de tener un constructor, es decir, mediante un
//constructor predeterminado o inexistente como en el ejemplo, utilizamos el this para poder inicializar variables del tipo clase sin necesidad de un constructor que lo haga