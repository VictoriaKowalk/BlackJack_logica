#pragma once

#ifndef USUARIO_H
#define USUARIO_H
#include "Jugador.h"
///El usuario es humano y hereda de Jugador los atributos

class Usuario :public Jugador
{
public:
    Usuario();
    Usuario(char*);
    virtual ~Usuario();
    void Dividir();
    void pedirCartasDividir();
    void mostrarManoDividir();
    void mostrarManoDividir2(); /// Esto lo agregue para poder mostrar los mazos por separado
    void setMano1Dividir(int);
    void setMano2Dividir(int);
    void setPuedeDividir(bool); /// Nueva funcion en V8
    bool puedeDividir(); /// Nueva funcion en V8
    int getMano1();
    int getMano2();
    void setDividio();
    bool getDividio();
protected:
    Carta mazo1[2];
    Carta mazo2[2];
    int _mano1;
    int _mano2;
    bool _puedeDividir = false; /// Nueva propiedad en V8
    bool dividio = false;
};

#endif // USUARIO_H
