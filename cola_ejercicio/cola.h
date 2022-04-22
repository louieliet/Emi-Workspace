#pragma once
#include <iostream>
#include <vector>

using namespace std;
//Tipo de dato para representar una pila

typedef int entero;

class cola {
public:
    cola(int);
    cola(const cola&);   //Sobrecarga de constructores
    ~cola();
    //Métodos de un objeto pila
    int tamano();
    void put(string);
    string get();
    string peek();
    int isempty();
    int capacidad();
    void print_cola();
    void clean_cola();
    int cambio(int index, string nuevo);
    void colado(string nuevo);
    //sobrecarga de algunos operadores
    void operator+=(int);
    //Atributos privados
private:
    string* espacio;//El nombre de un arreglo siempre es un apuntador al primer espacio de un arreglo
    int size;
    int top;
    int capacity;
    friend ostream& operator<<(ostream& os, const cola& st);
};

//Una excepcion habla de lo que sale mal en un codigo. Todas las excepciones que uno puede crear heredan de 
//la clase base excepcion que ofrece el lenguaje. En c++ es la clase excepction.
//Al crear una excepcion decimos que se hace cuando surge dicha excepcion.
struct FullQueue : public exception {
    const char* what() const throw () {
        return "Ya se repartieron todos los turnos";
    }
};
struct EmptyQueue : public exception {
    const char* what() const throw () {
        return "No hay nadie en la fila";
    }
};


#pragma once
