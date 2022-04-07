#include "Figuras.h"
using namespace std;

Figura::Figura() {
    cout << "Se esta creando la figura" << endl;
};

Rectangulo::Rectangulo(double ancho, double altura)
{
    cout << "Se esta creando un rectangulo" << endl;
    this->ancho = ancho;
    this->altura = altura;
};

double Rectangulo::getArea()const {
    return ancho * altura;
};

double Rectangulo::getPerimetro() const
{
    return (2 * ancho) + (2 * altura);
};

void Rectangulo::Dibujar() const {
    cout << "Se dibujo el rectangulo de ancho: " << ancho << ", y de alto: " << altura << endl;
};

Cuadrado::Cuadrado(double lado)
{
    cout << "Se esta creando un cuadrado" << endl;
    this->lado = lado;
    this->rect = new Rectangulo(lado, lado);
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
    cout << "Se dibujo un cuadrado de lado:" << lado << endl;
};