#pragma once
#ifndef BANCA_H
#define BANCA_H
#include "Jugador.h"
///La banca hereda de jugador

class Banca :public Jugador {
public:
    Banca();
    virtual ~Banca();
};

#endif // BANCA_H
