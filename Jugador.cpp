#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Jugador.h"
#include "Usuario.h"

Jugador::Jugador() {
}

Jugador::~Jugador()
{
    //dtor
}

int Jugador::getCantCartas() {
    return cantCartas;
}

void Jugador::pedirCarta() {
    int indice;
    Carta nuevaCarta;
    indice = getCantCartas();
    _misCartas[indice] = nuevaCarta;
    cantCartas++;
}


void Jugador::mostrarMano() {
    int i;

    for (i = 0; i < getCantCartas(); i++) {
        _misCartas[i].mostrarCarta();
        /// El vector guarda objetos de tipo Carta
        /// Entonces mostrarCarta() está en Carta.cpp
    }
}


int Jugador::calcularMano(Carta* mano, bool dividio) {
    int total = 0, i, valorCarta;
    bool hayAs{};

    /// Por cada carta en la mano, suma su valor numérico al total.
    /// Si hay un As en la mano, lo contemplamos a futuro mediante la bandera hayAs.
    for (i = 0; i < getCantCartas(); i++) {
        valorCarta = mano[i].getValor();
        if (valorCarta == 1) {
            hayAs = true;
        }
        total += valorCarta;
    }

    /// Si el total excede 21, el jugador se pasó.
    if (total > 21) {
        setSePaso();
        std::cout << getNombre() << " se paso de 21 y perdio." << std::endl;
        std::cout << std::endl;
    }

    /// Si el total es menor o igual a once y tenemos un As, podemos usar su valor como 11.
    else if (total <= 11 && hayAs) {
        total += 10;
        /// Comparamos si el total es menor a 21.
        if (total < 21) {
            /// Si el usuario no dividió, le mostramos ambos valores posibles de su mano.
            if (dividio == false) {
                std::cout << "La mano es de " << total - 10 << " o de " << total << "." << std::endl;
            }
            /// Si el usuario sí dividió, sólo le mostramos el valor más alto.
            else {
                std::cout << "La mano es de " << total << "." << std::endl;
            }
        }
        /// Si no es menor a 21 y no se pasó de 21, entonces es igual a 21.
        else {
            /// Si es la primer mano (dos cartas), es Blackjack.
            if (getCantCartas() == 2) {
                std::cout << "BLACKJACK!" << std::endl;
            }
            /// De lo contrario, simplemente tiene 21.
            else {
                std::cout << "La mano es de 21." << std::endl;
            }
            setBlackjack(); /// Técnicamente un 21 no siempre es Blackjack, pero es más sencillo escribirlo así.
        }
    }
    /// De lo contrario, evaluamos las últimas dos posibilidades.
    else if (total == 21) {
        std::cout << "La mano es de 21." << std::endl;
        setBlackjack();
    }
    else {
        std::cout << "La mano es de " << total << "." << std::endl;
    }

    hayAs = false;
    return total;
}

Carta* Jugador::getMisCartas() {
    return _misCartas;
}

void Jugador::setMano(int mano) {
    _mano = mano;
}

void Jugador::setBlackjack() {
    blackjack = true;
}

void Jugador::setSePaso() {
    sePaso = true;
}

void Jugador::setPlanto() {
    planto = true;
}

char* Jugador::getNombre() {
    return _nombre;
}

int Jugador::getMano() {
    return _mano;
}

bool Jugador::getBlackjack() {
    return blackjack;
}

bool Jugador::getSePaso() {
    return sePaso;
}

bool Jugador::getPlanto() {
    return planto;
}
