#pragma once
//#ifndef JUGADOR_H
#define JUGADOR_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Carta.h"
///El jugador con todos los metodos que pueden hacer tanto el Usuario como la banca

class Jugador
{
public:
    Jugador();
    virtual ~Jugador();
    void pedirCarta();
    void mostrarMano();
    int calcularMano(Carta*, bool dividio = false);
    int getCantCartas();
    Carta* getMisCartas();
    void setMano(int);
    void setBlackjack();
    void setSePaso();
    void setPlanto();
    int getMano();
    char* getNombre();
    bool getBlackjack();
    bool getSePaso();
    bool getPlanto();
    char _nombre[50]; /// Esto tendría que ir en private/protected
protected:
    //int id;
    int cantCartas = 0;
    Carta miCarta; /// ¿Qué es esto?
    Carta _misCartas[20]; /// Tiene que ser dinámico el tamaño
    /// Almacena objetos de tipo Carta, representa
    /// las cartas que tiene el jugador.
    int _mano;
    bool sePaso = false;
    bool planto = false;
    bool blackjack = false;
    bool cartasIguales = false;
};

//#endif  JUGADOR_H