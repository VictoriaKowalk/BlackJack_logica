#include "Banca.h"
#include <string.h>
#include <stdio.h>
#include <cstring>
#include <SFML/Graphics.hpp>

Banca::Banca() {
    strcpy_s(_nombre, "La banca");
}

Banca::~Banca()
{
    //dtor
}

