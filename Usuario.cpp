#include "Usuario.h"
#include <cstring>
#include <SFML/Graphics.hpp>
Usuario::Usuario(char* nombre)
{
    strcpy_s(_nombre, nombre);
}

Usuario::Usuario() {
}

Usuario::~Usuario() {
    //dtor
}

void Usuario::Dividir() {
    int mano1, mano2;
    setDividio(); /// Acá ya seteamos que el jugador efectivamente dividió su mano.
    mazo1[0] = _misCartas[0];
    mazo2[0] = _misCartas[1];
    pedirCartasDividir();
    mostrarManoDividir();
    mano1 = calcularMano(mazo1, getDividio()); /// Calculamos la primer mano, contemplando que fue una división.
    mostrarManoDividir2();
    mano2 = calcularMano(mazo2, getDividio()); /// Calculamos la segunda mano, contemplando que fue una división.
    setMano1Dividir(mano1);
    setMano2Dividir(mano2);
    setPlanto(); /// Y acá seteamos que el jugador se plantó y ya no puede pedir más cartas.
}

void Usuario::pedirCartasDividir() {
    Carta nuevaCarta;
    mazo1[1] = nuevaCarta;
    Carta nuevaCarta2;
    mazo2[1] = nuevaCarta2;
}

void Usuario::mostrarManoDividir() {
    int i;
    for (i = 0; i < 2; i++) {
        mazo1[i].mostrarCarta();
    }
}

void Usuario::mostrarManoDividir2() {
    int i;
    for (i = 0; i < 2; i++) {
        mazo2[i].mostrarCarta();
    }
}

void Usuario::setPuedeDividir(bool puedeDividir) {
    _puedeDividir = puedeDividir;
}

bool Usuario::puedeDividir() {
    return _puedeDividir;
}

void Usuario::setMano1Dividir(int mano) {
    _mano1 = mano;
}

void Usuario::setMano2Dividir(int mano) {
    _mano2 = mano;
}

int Usuario::getMano1() {
    return _mano1;
}

int Usuario::getMano2() {
    return _mano2;
}

bool Usuario::getDividio() {
    return dividio;
}

void Usuario::setDividio() {
    dividio = true;
}
