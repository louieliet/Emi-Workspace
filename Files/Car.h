#pragma once
#include <string>

using namespace std;
class Car
{
public:
    int id;
    string brand;
    int year;
    float cost;
    double price;
    bool enabled;
    Car(int& x, string& y, int& z, float& a, double& b, bool& c);
    ~Car();

private:

};

Car::Car(int& x, string& y, int& z, float& a, double& b, bool& c)
{
    id = x;
    brand = y;
    year = z;
    cost = a;
    price = b;
    enabled = c;
}

Car::~Car()
{
}