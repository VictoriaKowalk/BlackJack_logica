#include <string>
#include <cstring>
#ifndef CARTA_H
#define CARTA_H

/// ver de hacer una matriz para hacer el random con 4 mazos

class Carta {
public:
    Carta();
    virtual ~Carta();
    int getValor();
    int getTipo();
    void mostrarCarta();
    //string Carta::toString() ;

private:
    int _valor;
    int _palo;
    std::string palos[4] = { "♠", "♥","♣","♦" };
    std::string valores[13] = { "As","Dos","Tres","Cuatro", "Cinco", "Seis",
    "Siete", "Ocho", "Nueve", "Diez", "Jota", "Reina", "Rey" };
};

#endif // CARTA_H
