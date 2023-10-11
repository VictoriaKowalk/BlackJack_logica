#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include "Menu.h"
#include "Banca.h"
#include "Carta.h"
#include "Jugador.h"
#include <cstdio>
#include <Windows.h>

/// INCLUI LAS LIBRERIAS CSTDIO Y WINDOWS Y UN SETCONSEL DE LA LINEA 16 PARA QUE ME PERMITA
///IMPRIMIR POR PANTALLA LAS FORMAS DE LOS PALOS.
/// LA FUNCION DOBLAR LA CAMBIE POR DIVIDIR y la termine. Ahora divide en 2 mazos,MUESTRA LOS MAZOS
///Y CALCULA. ME FALTA SABER SI LAS 2 CARTAS SON IGUALES LINEA 72



using namespace std;

int main()
{

    SetConsoleOutputCP(CP_UTF8);


    std::srand(std::time(0));
    Menu menu;
    int cant_jugadores, i, j, mano;
    menu.MensajeBienvenida();
    cant_jugadores = menu.PedirUsuarios();
    menu.CrearUsuario(cant_jugadores);
    Banca banca;

    /// PRINCIPIO DEL JUEGO

    menu.MensajeRepartida();
    ///menu.RepartirManoInicial();

    for (i = 0; i < 2; i++) {
        /// Se reparten dos cartas por jugador y banca al principio del juego
        for (int j = 0; j < cant_jugadores; j++) {
            menu.getUsuarios()[j].pedirCarta();
            /// De mi clase Menu, desde mi clase Usuario, llamá a repartirCartas
            cout << "La mano de " << menu.getUsuarios()[j]._nombre << " es: " << endl;
            menu.getUsuarios()[j].mostrarMano();
            mano = menu.getUsuarios()[j].calcularMano(menu.getUsuarios()[j].getMisCartas());
            menu.getUsuarios()[j].setMano(mano);
            cout << endl;
        }

        banca.pedirCarta();
        if (i == 0) {
            cout << "La mano de la banca es: " << endl;
            banca.mostrarMano();
            mano = banca.calcularMano(banca.getMisCartas());
            banca.setMano(mano);
            cout << endl;
        }
        else {
            cout << "Se repartio una carta a la banca y queda oculta." << endl;
            cout << endl;
        }
    }

    /// FIN PRINCIPIO DEL JUEGO

    for (int j = 0; j < cant_jugadores; j++) {
        int opcion = 0;

        while (menu.getUsuarios()[j].getBlackjack() != true &&
            menu.getUsuarios()[j].getSePaso() != true &&
            menu.getUsuarios()[j].getPlanto() != true) {
            cout << "~ Turno del jugador " << menu.getUsuarios()[j]._nombre << " ~ " << endl;
            menu.getUsuarios()[j].calcularMano(menu.getUsuarios()[j].getMisCartas());
            ///ACA QUIERO PREGUNTAR SI LAS 2 CARTAS DE ESE JUGADOR SON IGUALES, PORQUE SI SON IGUALES
            ///LE MUESTRO LA OPCION DIVIDIR. SINO NO
            opcion = menu.MensajeOpciones(j);
            switch (opcion) {
            case 1:
                menu.getUsuarios()[j].pedirCarta();
                menu.getUsuarios()[j].mostrarMano();
                mano = menu.getUsuarios()[j].calcularMano(menu.getUsuarios()[j].getMisCartas());
                menu.getUsuarios()[j].setMano(mano);
                cout << endl;
                break;
            case 2:
                menu.getUsuarios()[j].setPlanto();
                break;
            case 3:
                if (menu.getUsuarios()[j].puedeDividir() && menu.getUsuarios()[j].getDividio() == false) {
                    menu.getUsuarios()[j].Dividir(); /// PENDIENTE Solo se puede hacer en la primer mano
                    /// V9 Calculamos las dos manos resultantes
                }
                else {
                    cout << "Elija una opcion valida.";
                    cout << endl;
                }
                break;
            default:
                cout << "Elija una opcion valida.";
                cout << endl;
            }
        }
    }

    /// LE TOCA A LA BANCA

    menu.MensajeTurnoBanca();
    ///Vicky--> Agregue un mensaje
    banca.mostrarMano();
    menu.MensajeDarVueltaCartaBanca();
    mano = banca.calcularMano(banca.getMisCartas());
    banca.setMano(mano);
    std::cout << endl;
    while (banca.getMano() < 17) {
        banca.pedirCarta();
        ///Vicky--> Agregue un mensaje para cuando la banca saca carta
        menu.MensajeBancaPideCarta();
        banca.mostrarMano();
        mano = banca.calcularMano(banca.getMisCartas());
        banca.setMano(mano);
    }
    ;

    /// FIN DEL JUEGO

    menu.MensajeResultados();

    for (int j = 0; j < cant_jugadores; j++) {
        if (menu.getUsuarios()[j].getDividio()) {
            menu.determinarResultado(banca, menu.getUsuarios()[j], menu.getUsuarios()[j].getMano1());
            menu.determinarResultado(banca, menu.getUsuarios()[j], menu.getUsuarios()[j].getMano2());
        }
        else {
            menu.determinarResultado(banca, menu.getUsuarios()[j], menu.getUsuarios()[j].getMano());
        }
    }
    system("pause");
    return 0;
}



/*
sf::RenderWindow window(sf::VideoMode(800, 600), "Blackjack");
while (window.isOpen())
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    window.clear();
    menu.MensajeBienvenida(window); // Llama a la función MensajeBienvenida
    window.display();

}


while (window.isOpen())
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    window.clear();
    while (window.isOpen())
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    window.clear();
    int numUsuarios = menu.PedirUsuarios(window); // Llama a la función PedirUsuarios
    window.display();

    if (numUsuarios > 0) // Si se seleccionó un número de usuarios, sal del bucle
        break;
}



}*/