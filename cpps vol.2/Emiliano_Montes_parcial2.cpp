#include <iostream> 
#include <stdio.h> 
#include <vector>
using namespace std;

class Figura {
public: 
    Figura();
    virtual double getArea() const = 0;
    virtual double getPerimetro() const = 0;
    virtual void Dibujar() const = 0;
    virtual double duplicarA() const = 0;
private: 
    double area;
    double perimetro;
};

class Rectangulo: public Figura {
public: 
    Rectangulo(double ancho, double altura);
    virtual double getArea() const override;
    virtual double getPerimetro() const override;
    virtual void Dibujar() const override;
    virtual double duplicarA() const override;
private: 
    double ancho;
    double altura;
};

class Cuadrado: public Figura {
public: 
    Cuadrado(double lado);
    virtual double getArea() const override;
    virtual double getPerimetro() const override;
    virtual void Dibujar() const override;
    virtual double duplicarA() const override;
private: 
    double lado;
    Rectangulo * rect;
};

class Circulo: public Figura {
public: 
    Circulo(double radio);
    virtual double getArea() const override;
    virtual double getPerimetro() const override;
    virtual void Dibujar() const override;
    virtual double duplicarA() const override;
private: 
    double radio;
};

Figura::Figura() {
    cout << "Se está creando la figura" << endl;
};

Rectangulo::Rectangulo(double ancho, double altura)
{
    cout << "Se está creando un rectangulo" << endl;
    this->ancho = ancho;
    this->altura = altura;
};

double Rectangulo::getArea()const {
    return ancho * altura;
};

double Rectangulo::duplicarA() const {
    return (ancho*altura)*2;
};

double Rectangulo::getPerimetro() const {
    return (2 * ancho) + (2 * altura);
};

void Rectangulo::Dibujar() const {
    cout << "Se dibujó el rectangulo de ancho: " << ancho << ", y de alto: " << altura << endl;
};

Cuadrado::Cuadrado(double lado) {
    cout <<  "Se está creando un cuadrado" << endl;
    this->lado = lado;
    this->rect = new Rectangulo(lado, lado);
};

double Cuadrado::getArea() const {
    return rect->getArea();
};

double Cuadrado::duplicarA()const {
    return (rect->getArea())*2;
};

double Cuadrado::getPerimetro() const {
    return rect->getPerimetro();
};

void Cuadrado::Dibujar() const {
    cout <<  "Se dibujo un cuadrado de lado:" << lado << endl;
};

Circulo::Circulo(double radio) {
    cout <<  "Se esta creando un circulo" << endl;
    this->radio = radio;
};

double Circulo::getArea() const {
    return 3.1416*(radio*radio);
};

double Circulo::duplicarA()const {
    return (3.1416*(radio*radio))*2;
};

double Circulo::getPerimetro() const {
    return 3.1416*(radio*2);
};

void Circulo::Dibujar() const {
    cout <<  "Se dibujo un circulo de radio:" << radio << endl;
};

vector<double> f1(vector<Figura>& v) {
    vector<double> areas;
    double area=0;
    for(auto i : v) {
        area=i.getArea();
        areas.push_back(area);
        
    };
    return areas;
}
    
double f2(vector<double>& v){
    double suma=0;
    for(auto i: v)
    {
        suma+=i;
    }
    return suma;
};

bool operator == (const Figura & f1, const Figura & f2) {
    if(f1.getArea() == f2.getArea()) 
        return true;
    else 
        return false;
};
        
int main() {

    vector<Figura> figuras;
    vector<double> areas;
    double suma;
    Circulo circulo1(5);
    Rectangulo rectangulo1(5,10);
    Cuadrado cuadrado1(5);
    bool comp = cuadrado1==rectangulo1;
    
    figuras.push_back(circulo1);
    figuras.push_back(rectangulo1);
    figuras.push_back(cuadrado1);
    cout << figuras.duplicarA() << endl;
    cout << comp << endl;;
    areas=f1(figuras);
    suma=f2(areas);
};