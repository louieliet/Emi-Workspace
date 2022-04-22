#include <iostream>
#include <stdio.h>

using namespace std;


void incrementar(int& a)
{
    a+=1;
    //Utiliza el valor dentro de la dirección de memoria de la variable que le paso.
    //Esto es "Paso por referencia".
}

void incrementarp(int* a)
{
    *a+=1;
    //lo que quiero es el valor al que apunta a, es decir, el valor que contiene la dirección de memoria que le voy a meter como argumento a la función

}

void incrementarpb(int* a)
{
    *a+=1;

}

int main()
{

    int a=2;
    int* b=&a;

    cout<<"Valor de a: " << a <<endl;
    cout<<"Direccion de memoria de a: " << &a <<endl;
    cout<<"Valor de b: " << b <<endl;
    cout<<"Direccion de memoria de b: " << &b <<endl;
    cout<<"Valor al que apunta b: "<< *b <<endl;
    cout<<"--------------"<<endl;

    cout<<"Modificando b atraves de a: "<<endl;
    a=5;
    cout<<"a=5"<<endl;
    cout<<"Valor de a: " << a <<endl;
    cout<<"Valor al que apunta b: "<< *b <<endl;
    cout<<"--------------"<<endl;
    cout<<"Modificando a atraves de b: "<<endl;
    *b=7;
    cout<<"*b=7"<<endl;
    cout<<"Valor de a: " << a <<endl;
    cout<<"Valor al que apunta b: "<< *b <<endl;

    //El &b es similar pero diferente a la vez de int&

    incrementar(a);

    //Lo que estoy diciendo con int& es que utilice la misma dirección de memoria de la variable que le voy a pasar, en este caso, de a, por eso se le llama
    //paso por referencia.
    //cuando yo hago &a, estoy referenciando a la variable
    //cuando yo hago *b, estoy derreferenciando la variable

    cout<<a<<endl;
    cout<<*b<<endl;

    //Ahora, la función incrementar utiliza un puntero (int* a), por lo que le paso la dirección de memoria de a, para que utilice esa misma a y su valor

    incrementarp(&a);

    cout<<a<<endl;
    cout<<*b<<endl;

    //Utilizo una función diferente pero igual para que, através de una variable de tipo int*, modifique el valor. En vez de pasarle la dirección de memoria
    // de la variable que quiero, le paso el int* que ya contiene esa dirección de variable.

    incrementarpb(b);

    cout<<a<<endl;
    cout<<*b<<endl;
    
    return 0;
}      