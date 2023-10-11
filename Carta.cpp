#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Carta.h"




Carta::Carta()  ///constructor
{
    _valor = rand() % 13 + 1; /// Elige un valor entre 1 y 13 (para la carta)
    _palo = rand() % 4 + 1; /// Elige un valor entre 1 y 4 (para el palo)
}

Carta::~Carta()
{
    /// destructor. ******No sé si lo necesitamos******
}

int Carta::getTipo() {
    return _valor;
}

int Carta::getValor() {
    if (_valor > 10) { /// del 1 hasta el 10, la carta tiene su mismo valor. Las figuras valen 10.
        return 10;
    }
    else {
        return _valor;
    }
}

void Carta::mostrarCarta() {
    std::cout << valores[_valor - 1] << " de " << palos[_palo - 1] << std::endl;
}