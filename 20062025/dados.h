#ifndef DADOS_H
#define DADOS_H

#include <iostream>
#include <string>

using namespace std;

/// Pide el nombre del jugador
string obtenerNombre();

/// Devuelve un numero aleatorio entre 1 y 6
int tirarDadosSeisCaras();

int tirarDadosDoceCaras();

/// Rellena el arreglo 'tiradaDoce' con 'cantidad' tiradas de dados de 12 caras
void tiradaDados12(int tiradaDoce[], int cantidad);

/// Rellena el arreglo 'tiradaSeis' con 'cantidad' tiradas de dados de 6 caras
void tiradaDados6(int tiradaSeis[], int cantidad);

/// Devuelve la suma de los valores almacenados en un arreglo de tama¤o 'cantidad'
int calcularPuntos(int valores[], int cantidad);

///Muestra los creditos
void mostrarCreditos();

int jugarRonda(string jugadorActivo, int &dadosJugador, int &dadosContrincante);

bool sePuedeSumarObjetivo(int dados[], int cantidad, int objetivo);
/// Esta funcion nos lleva al juego
void jugarPartida (string jugadorUno, string jugadorDos, int &maximoPuntaje, string &mejorJugador);
#endif
