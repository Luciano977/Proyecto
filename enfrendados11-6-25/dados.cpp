#include <cstdlib>  // para poder usar rand y generar numeros aleatorios
#include "dados.h"
#include <iostream>
using namespace std;

/// Pide el nombre del jugador
string obtenerNombre(){
    string jugador;

    cout <<"Ingresa tu nombre : ";
    cin >> jugador;
    return jugador;

}

/// Da un numero aleatorio entre 1 y 6
int tirarDadosSeisCaras() {
    return 1 + rand() % 6;

}

///Da un numero aleatorio entre 1 y 12

int tirarDadosDoceCaras() {
   return 1 + rand() % 12;
}

/// Rellena el arreglo 'tiradaDoce' con 'cantidad' tiradas de dados de 12 caras
void tiradaDados12(int tiradaDoce[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        tiradaDoce[i] = tirarDadosDoceCaras();
    }
}

/// Rellena el arreglo 'tiradaSeis' con 'cantidad' tiradas de dados de 6 caras
void tiradaDados6(int tiradaSeis[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        tiradaSeis[i] = tirarDadosSeisCaras();
    }
}

/// Suma todos los valores en el arreglo y devuelve el total
int calcularPuntos(int valores[], int cantidad) {
    int suma = 0;
    for (int i = 0; i < cantidad; i++) {
        suma += valores[i];
    }
    return suma;
}
