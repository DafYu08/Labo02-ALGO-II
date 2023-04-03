#include <iostream>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

using Mes = int;
using Dia = int;

class Fecha{
public:
    Fecha(int mes, int dia);
    int mes();
    int dia();
    void incrementar_dia();
    #if EJ >= 9 // Para ejercicio 9
        bool operator==(Fecha o);
    #endif
private:
    int mes_;
    int dia_;
};


Fecha::Fecha(int mes, int dia): mes_(mes), dia_(dia){};

int Fecha::mes(){
    return mes_;
}

int Fecha::dia(){
    return dia_;
}
#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia() and
                    this ->mes() == o.mes();
    return igual_dia;
}
#endif

ostream& operator<<(ostream& os, Fecha f) {
    os << f.dia() << "/"<< f.mes();
    return os;
}
void Fecha::incrementar_dia(){
    if(dias_en_mes(mes_) == dia_){
        dia_ = 1;
        mes_++;
    } else{
        dia_++;
    }
};

class Horario{
    public:
    Horario(uint hora, uint min);
    uint hora();
    uint min();
    bool operator<(Horario h);
    private:
    uint hora_;
    uint min_;
};

Horario::Horario(uint hora, uint min): hora_(hora), min_(min){}

uint Horario::hora(){
    return hora_;
}
uint Horario::min(){
    return min_;
}
/*
bool Horario::operator==(Horario h) {
    bool igual_hora = this->hora() == h.hora() and
                     this ->min() == h.min();
    return igual_hora;
}
*/
ostream& operator<<(ostream& os, Horario h) {
    os << h.hora() << ":"<< h.min();
    return os;}

bool Horario::operator<(Horario h) {
    bool res = true;
        if(h.hora() < hora()){
            res = false;
        } else if (hora() == h.hora()){
            if(h.min() < min()){
                res = false;
            }
        }

    return res;
}

// Ejercicio 13

// Clase Recordatorio


// Ejercicio 14

// Clase Agenda

