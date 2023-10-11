#pragma once
#include <SFML/Graphics.hpp>
//#ifndef MENU_H
#define MENU_H
#include "Usuario.h"
#include "Banca.h"
/*
class Menu
{
public:
    Menu();
    virtual ~Menu();
    void MensajeBienvenida();
    void MensajeRepartida();
    int MensajeOpciones(int);
    void MensajeTurnoBanca();
    void MensajeResultados();
    void MensajeDarVueltaCartaBanca();
    void MensajeBancaPideCarta();
    int PedirUsuarios();
    void CrearUsuario(int);
    Usuario* getUsuarios();
    void determinarResultado(Banca, Usuario, int);
protected:
    Usuario usuarios[3];
    /// Esta cantidad de usuarios en el vector tiene que ser dinámica
};*/

//#endif /// MENU_H
class Menu
{
public:
    Menu();
    virtual ~Menu();
   // void MensajeBienvenida(sf::RenderWindow& window);
    void MensajeBienvenida();
    void MensajeRepartida();
    int MensajeOpciones(int);
    void MensajeTurnoBanca();
    void MensajeResultados();
    void MensajeDarVueltaCartaBanca();
    void MensajeBancaPideCarta();
    //int PedirUsuarios(sf::RenderWindow& window);
    int PedirUsuarios();
    void CrearUsuario(int);
    Usuario* getUsuarios();
    void determinarResultado(Banca, Usuario, int);
protected:
    sf::Font font;
    sf::Text text;
    Usuario usuarios[3];
};
