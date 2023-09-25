#include <iostream>
using namespace std;

void incremento(int numero);

int main(){

    int a = 3;

    /*
    int* apuntador_a_a = &a;

    
    cout << "El valor de a es: " << a << endl;
    cout << "Dónde está ubicado: " << &a << endl;
    cout << "Y nuevamente el valor de a: " << *(&a) << endl;
    */

   incremento(a);

   cout << a;

}

void incremento(int numero){
    numero++;
}