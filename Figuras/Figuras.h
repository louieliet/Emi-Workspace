#include <iostream> 
#include <stdio.h> 
using namespace std;

class Figura {
    public: 
    Figura();
    virtual double getArea() const = 0;
    virtual double getPerimetro() const = 0;
    virtual void Dibujar() const = 0;

    private: 
    double area;
    double perimetro;
};

class Rectangulo:public Figura
{
    public:
    Rectangulo(double ancho, double altura);
    virtual double getArea() const override;
    virtual double getPerimetro() const override;
    virtual void Dibujar() const override;

    private:
    double ancho;
    double altura;   
};

class Cuadrado: public Figura {
    public: Cuadrado(double lado);
    virtual double getArea()
    const override;
    virtual double getPerimetro()
    const override;
    virtual void Dibujar()
    const override;

    private:
    double lado;
    Rectangulo* rect;

};