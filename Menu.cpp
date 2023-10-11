#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include "Menu.h"
#include "Usuario.h"

using namespace sf;


Menu::Menu()
{
    ///ctor
}

Menu::~Menu()
{
    ///dtor
}

void Menu::MensajeBienvenida() /// Agregue las reglas
{
    std::cout << "===========================================================================" << std::endl;
    std::cout << "=                                                                         =" << std::endl;
    std::cout << "=                      ♥ ♦ ♣ ♠ ~BLACKJACK~ ♥ ♦ ♣ ♠                        =" << std::endl;
    std::cout << "=                                                                         =" << std::endl;
    std::cout << "===========================================================================" << std::endl;
    std::cout << "===========================================================================" << std::endl;
    std::cout << "=                                                                         =" << std::endl;
    std::cout << "=   ~La Banca Pide Con 16 y en 17 Se Planta~                              =" << std::endl;
    std::cout << "=   ~Al Doblar o Dividir Se Repartira Una Carta~                          =" << std::endl;
    std::cout << "=   ~BlackJack paga 3 a 2~                                                =" << std::endl;
    std::cout << "=                                                                         =" << std::endl;
    std::cout << "===========================================================================" << std::endl;

}

void Menu::MensajeRepartida() {
    std::cout << "=================================================" << std::endl;
    std::cout << "=           Se reparten las cartas...           =" << std::endl;
    std::cout << "=================================================" << std::endl;
}

int Menu::MensajeOpciones(int indice) {
    int opcion;
    std::cout << "=================================================" << std::endl;
    std::cout << "= Seleccione la opcion deseada para el jugador: =" << std::endl;
    std::cout << "= OPCION 1: Pedir otra carta                    =" << std::endl;
    std::cout << "= OPCION 2: Plantarse                           =" << std::endl;
    if (usuarios[indice].getMisCartas()[0].getTipo() == usuarios[indice].getMisCartas()[1].getTipo() && usuarios[indice].getCantCartas() == 2) {
        usuarios[indice].setPuedeDividir(true);
        std::cout << "= OPCION 3: Dividir                             =" << std::endl;
    }
    std::cout << "=================================================" << std::endl;
    std::cin >> opcion;
    return opcion;
}

void Menu::MensajeTurnoBanca() {
    std::cout << "=================================================" << std::endl;
    std::cout << "=             Turno de la banca...               =" << std::endl;
    std::cout << "=================================================" << std::endl;
}

void Menu::MensajeResultados() {
    std::cout << "=================================================" << std::endl;
    std::cout << "=            RESULTADOS DEL JUEGO               =" << std::endl;
    std::cout << "=================================================" << std::endl;
}

int Menu::PedirUsuarios() ///Numero de jugadores. Maximo 3.
{
    int cant_usuarios = 0;
    while (cant_usuarios < 1 || cant_usuarios > 3)
    {
        std::cout << "¿Cuantos jugadores quieren ingresar a la sala? ";
        std::cin >> cant_usuarios;
        std::cout << std::endl;

        if (cant_usuarios > 3)
        {
            std::cout << "¡Maximo 3 jugadores!" << std::endl;
        }
        else if (cant_usuarios < 1)
        {
            std::cout << "Elige entre 1, 2 o 3 jugadores." << std::endl;
        }
    }
    return cant_usuarios;
}

Usuario* Menu::getUsuarios() {
    return usuarios;
}

void Menu::CrearUsuario(int cant_usuarios) {
    char nombre[50];

    for (int i = 0; i < cant_usuarios; i++) {
        std::cout << "Nombre de Usuario " << i + 1 << ": ";
        std::cin >> nombre;
        Usuario usuario(nombre);
        usuarios[i] = usuario;
    }
    system("cls");
}

void Menu::MensajeDarVueltaCartaBanca() {
    std::cout << "~ Se descubrio la segunda carta de la banca ~" << std::endl;
}

void Menu::MensajeBancaPideCarta() {
    std::cout << "La banca saca otra carta." << std::endl;
}

void Menu::determinarResultado(Banca banca, Usuario usuario, int mano) {
    if (banca.getSePaso() == false && usuario.getSePaso() == true) {
        std::cout << "El jugador " << usuario.getNombre() << " se paso y perdio el juego." << std::endl;
    }
    else if (banca.getSePaso() == true && usuario.getSePaso() == false) {
        std::cout << "El jugador " << usuario.getNombre() << " le gano a la banca." << std::endl;
    }
    else if (banca.getSePaso() == true && usuario.getSePaso() == true) {
        std::cout << "La banca y el jugador " << usuario.getNombre() << " perdieron." << std::endl;
    }
    else {
        if (banca.getMano() > mano) {
            std::cout << "La banca con un total de " << banca.getMano() << " le gano al jugador " << usuario.getNombre() << " con un total de " << mano << std::endl;
        }
        else if (banca.getMano() == mano) {
            std::cout << "La banca con un total de " << banca.getMano() << " y el jugador " << usuario.getNombre() << " con un total de " << mano << " empataron." << std::endl;
        }
        else {
            std::cout << "El jugador " << usuario.getNombre() << " con un total de " << mano << " le gano a la banca con un total de " << banca.getMano() << std::endl;
        }
    }
}


/*

Menu::Menu()
{// EN EL CONSTRUCTOR LE INDICO LA FUENTE, EL TAMANIO Y EL COLOR A USAR
    if (!font.loadFromFile("./fuentes/Casino.ttf"))
    {
        std::cout << "No se pudo cargar la fuente" << std::endl;
    }
    text.setFont(font);
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
}

Menu::~Menu()
{
}

void Menu::MensajeBienvenida(sf::RenderWindow& window)
{
    //SETEO LO QUE VOY A ESCRIBIR
    text.setString("Bienvenido al juego de Blackjack!");
    //SETEO LA POSICION
    text.setPosition(sf::Vector2f(window.getSize().x * 0.1, window.getSize().y * 0.1));
    window.draw(text);
}


int Menu::PedirUsuarios(sf::RenderWindow& window)
{
    sf::Text option1("1 jugador", font);
    sf::Text option2("2 jugadores", font);
    sf::Text option3("3 jugadores", font);

    option1.setPosition(100, 100);
    option2.setPosition(100, 200);
    option3.setPosition(100, 300);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (option1.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return 1;
                else if (option2.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return 2;
                else if (option3.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return 3;
            }
        }

        window.clear();
        window.draw(option1);
        window.draw(option2);
        window.draw(option3);
        window.display();
    }

    return 0; // Retorna 0 si 
}

void Menu::MensajeRepartida(sf::RenderWindow& window)
{
    text.setString("Se reparten las cartas...");
    text.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
    window.draw(text);
}

int Menu::MensajeOpciones(sf::RenderWindow& window, int indice)
{
    sf::Text option1("Pedir otra carta", font);
    sf::Text option2("Plantarse", font);
    sf::Text option3("Dividir", font);

    option1.setPosition(100, 100);
    option2.setPosition(100, 200);
    option3.setPosition(100, 300);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (option1.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return 1;
                else if (option2.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return 2;
                else if (option3.getGlobalBounds().contains(mousePos.x, mousePos.y) && usuarios[indice].getPuedeDividir())
                    return 3;
            }
        }

        window.clear();
        window.draw(option1);
        window.draw(option2);
        if (usuarios[indice].getPuedeDividir())
            window.draw(option3);
        window.display();
    }

    return 0; // Retorna 0 si la ventana se cierra antes de seleccionar una opción
}
*/