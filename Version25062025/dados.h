#ifndef DADOS_H
#define DADOS_H

#include <iostream>
#include <string>

using namespace std;
///muestra menu de opciones
void mostrarMenu();
///leer opcion menu para validacion de ingreso
int leerOpcionMenu();
/// Pide el nombre del jugador
string obtenerNombre();
/// Devuelve un numero aleatorio entre 1 y 6
int tirarDadosSeisCaras();
/// Devuelve un numero aleatorio entre 1 y 12
int tirarDadosDoceCaras();
/// Dibuja los cuadrados de los dados
void dibujarCuadrado(int posx, int posy);
/// Dibuja los dados con los puntos
void dibujarDado(int numero, int posx, int posy);
///Muestra los creditos
void mostrarCreditos();
///Jugar Ronda
int jugarRonda(string jugadorActivo, int &dadosJugador, int &dadosContrincante);
///Validacion
bool sePuedeSumarObjetivo(int dados[], int cantidad, int objetivo);
/// Esta funcion nos lleva al juego
void jugarPartida (string jugadorUno, string jugadorDos, int &maximoPuntaje, string &mejorJugador);
#endif
