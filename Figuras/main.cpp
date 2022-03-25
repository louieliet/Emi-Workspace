#include "Figuras.h"
#include "Figura.cpp"
#include <vector>
using namespace std;

int main() {

    vector<Figura*> figuras={
        new Rectangulo(3,5),
        new Cuadrado(5)
    };

    for(Figura* elemento:figuras)
    {
        cout<<elemento->getArea()<<endl;
        cout<<elemento->getPerimetro()<<endl;
        elemento->Dibujar();

    }
    
    /*Figura* r1= new Rectangulo(3,5);
    cout<<r1->getArea()<<endl;
    cout<<r1->getPerimetro()<<endl;
    r1->Dibujar();*/
};