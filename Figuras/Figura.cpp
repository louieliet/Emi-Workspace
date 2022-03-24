#include "Figuras.h"
using namespace std;

Figura::Figura() {
    cout <<  "Se está creando la figura" << endl;
};

Rectangulo::Rectangulo(double ancho, double altura)
{
    cout<<"Se está creando un rectangulo"<<endl;
    this->ancho=ancho;
    this->altura=altura;
};

double Rectangulo::getArea()const{
    return ancho*altura;
};

double Rectangulo::getPerimetro() const
{
    return (2*ancho)+(2*altura);
};

void Rectangulo::Dibujar() const {
    cout<< "Se dibujó el rectangulo de ancho: "<<ancho<<", y de alto: "<<altura<<endl;
};

Cuadrado::Cuadrado(double lado)
{
    cout<<"Se está creando un cuadrado"<<endl;
    this->lado=lado;
    this->rect=new Rectangulo(lado,lado);
};

double Cuadrado::getArea() const
{
    return rect->getArea();
};

double Cuadrado::getPerimetro() const
{
    return rect->getPerimetro();
};

void Cuadrado::Dibujar() const
{
    cout<<"Se dibujó un cuadrado de lado:"<<lado<<endl;
};