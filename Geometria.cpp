#include <iostream>
#include <ostream>

using namespace std;

using uint = unsigned int;

// Ejercicio 1

class Rectangulo {
    public:
        Rectangulo(uint alto, uint ancho);
        uint alto();
        uint ancho();
        float area();
        //int operator*(Rectangulo mult); PREGUNTAR SI HACE FALTA

    private:
        int alto_;
        int ancho_;

};

Rectangulo::Rectangulo(uint alto, uint ancho) :
    alto_(alto), ancho_(ancho){}

uint Rectangulo::alto() {
    return alto_;
}

uint Rectangulo::ancho() {
    return ancho_;
}
float Rectangulo::area() {
    return alto_ * ancho_;
}
/*int Rectangulo::operator*(Rectangulo mult) {
    return alto_ * ancho_ == mult.alto_ * ancho_;
} PREGUNTAR SI HAY QUE AGREGAR EL MULTIPLICAR*/

// Ejercicio 2

class Elipse{
public:
    Elipse(uint a, uint b);
    uint a();
    uint b();
    float area();

private:
    uint r_a;
    uint r_b;
    float PI = 3.14;
};

Elipse::Elipse (uint a, uint b):
    r_a(a), r_b(b), PI(){}

uint Elipse::a(){
    return r_a;
}

uint Elipse::b(){
    return r_b;
}

float Elipse::area(){
    return r_a * r_b * PI;
}


// Ejercicio 3

class Cuadrado {
    public:
        Cuadrado(uint lado);
        uint lado();
        float area();

    private:
        Rectangulo r_;
        uint lado_;
};

Cuadrado::Cuadrado(uint lado): r_(lado, lado) {}

uint Cuadrado::lado() {
    return lado_;
}

float Cuadrado::area() {
    return lado_ * lado_;
}

// Ejercicio 4

class Circulo{
public:
    Circulo(float radio);
    float radio();
    float p();
    float area();

private:
    float radio_;
    float PI = 3.14;
};

Circulo::Circulo(float radio):
    radio_(radio), PI()
{}

float Circulo::radio(){
    return radio_;
}

float Circulo::p(){
    return PI * 2 * radio_;
}

float Circulo::area(){
    return  radio_ * radio_ * PI;
}



// Ejercicio 5

ostream& operator<<(ostream& os, Elipse e) {
    os << "Elipse(" << e.a() << ", " << e.b() << ")";
    return os;
}

// Ejercicio 6


ostream& operator<<(ostream& os, Cuadrado q) {
    os << "Cuadrado(" << q.lado() << ")";
    return os;
}//Agrega el cout al cuadrado

ostream& operator<<(ostream& os, Circulo c) {
    os << "Circulo(" << c.radio() << ")";
    return os;
}//Agrega el cout al círculo