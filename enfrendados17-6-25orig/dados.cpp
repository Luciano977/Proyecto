#include <cstdlib>  /// para poder usar rand y generar numeros aleatorios
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

/// Rellena el arreglo tiradaDoce con cantidad tiradas de dados de 12 caras
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

///Muestra los creditos
void mostrarCreditos(){
    system("cls");
    cout<< endl;
    cout<<" Este Juego fue desarrollado por los alumnos"<< endl;
    cout<<" de la UTN FACULTAD REGIONAL GENERAL PACHECO "<< endl;
    cout<<" -------------------------------------------"<< endl;
    cout<< "Facundo Sosa - Legajo Nro."<< endl;
    cout<< "Jorge -  Legajo Nro."<< endl;
    cout<< "Luciano Cejas - Legajo Nro."<< endl;
    cout<< "Nicolas - Legajo Nro."<< endl;
    cout<< endl;
    cout<< "Agradecemos tu colaboracion"<< endl<< endl;
    system("pause");

}

/// Suma todos los valores en el arreglo y devuelve el total

int calcularPuntos(int valores[], int cantidad) {
    int suma = 0;
    for (int i = 0; i < cantidad; i++) {
        suma += valores[i];
    }
    return suma;
}
#include <algorithm> // para std::any_of

int jugarRonda(string jugadorActivo, int &dadosJugador, int &dadosContrincante) {
    int vDados6Caras[11]{};          /// stock maximo de dados

    /* 1. Tirar dados de 6 caras */
    for (int i = 0; i < dadosJugador; ++i)
        vDados6Caras[i] = rand() % 6 + 1;

    /* 2. Generar dados objetivo alcanzables */
    int dado12Caras1, dado12Caras2, resultadoSuma12caras;
    int intentos = 0, maxIntentos = 100;

    do {
        dado12Caras1 = rand() % 12 + 1;
        dado12Caras2 = rand() % 12 + 1;
        resultadoSuma12caras = dado12Caras1 + dado12Caras2;
        ++intentos;

    } while (!sePuedeSumarObjetivo(vDados6Caras, dadosJugador, resultadoSuma12caras) &&
             intentos < maxIntentos);

    ///mostrar las tiradas

    cout << "------------------------------------------\n";
    cout << "Jugando: " << jugadorActivo << '\n';
    cout << "Dado objetivo 1: " << dado12Caras1 << '\n';
    cout << "Dado objetivo 2: " << dado12Caras2 << '\n';
    cout << "Numero objetivo : " << resultadoSuma12caras << '\n';
    cout << "------------------------------------------\n";

    for (int i = 0; i < dadosJugador; ++i)
        cout << "[" << i + 1 << "] => " << vDados6Caras[i] << '\n';

    ///  Elegir dados

    int cantElegir = 0;
    cout << "¨Cuantos dados deseas elegir? ";
    cin  >> cantElegir;
    while (cantElegir < 1 || cantElegir > dadosJugador) {
        cout << "Cantidad incorrecta." << dadosJugador << ": ";
        cin  >> cantElegir;
    }

    int sumaElegida = 0, pos;
    cout << "Elige las posiciones de esos " << cantElegir << " dados:\n";
    for (int k = 0; k < cantElegir; ++k) {
        cin >> pos;
        while (pos < 1 || pos > dadosJugador) {
            cout << "Posicion incorrecta." << dadosJugador << ": ";
            cin >> pos;
        }
        sumaElegida += vDados6Caras[pos - 1];
    }

    cout << "\nSuma elegida : " << sumaElegida << '\n';
    cout << "Numero objetivo: " << resultadoSuma12caras << '\n';


    ///puntuaciones (se a¤adio penalizacion)


    int puntosObtenidos = 0;


    if (sumaElegida == resultadoSuma12caras) {
    cout << "­Buen juego!";
    cout << "Se te restan " << cantElegir << " dados y se le suman al rival."<<endl;
    dadosJugador -= cantElegir;
    dadosContrincante += cantElegir;
    puntosObtenidos = sumaElegida * cantElegir;

   }else {
    cout << "La suma no coincide."<<endl;

    if (sePuedeSumarObjetivo(vDados6Caras, dadosJugador, resultadoSuma12caras)) {
        if (dadosContrincante > 1) {
            cout << jugadorActivo << " fallo y habia una suma posible. Recibes 1 dado del rival."<<endl;
            dadosJugador++;
            dadosContrincante--;
        } else {
            cout << jugadorActivo << " fallo, pero el rival no tiene dados suficientes para penalizar."<<endl;
        }
    } else {
        cout << "No habia forma posible de hacer la suma. No hay penalizacion."<<endl;
    }
}


        cout << "Dados Stock de " << jugadorActivo << ": " << dadosJugador << " dados."<<endl;
        cout << "Dados Stock rival: " << dadosContrincante << " dados."<<endl;

        return puntosObtenidos;   ///  puntos que sumara el jugador en main
    }

    bool sePuedeSumarObjetivo(int dados[], int cantidad, int objetivo) {
    int totalCombinaciones = 1 << cantidad; ///2 elevado a la cantidad (para generar conbinaciones posibles) :)

    for (int comb = 1; comb < totalCombinaciones; comb++) {
        int suma = 0;
        for (int i = 0; i < cantidad; i++) {
            /// Si en la combinacion (comb) el dado i esta seleccionado lo suma.

            if ((comb / (1 << i)) % 2 == 1) {
                suma += dados[i];
            }
        }
        if (suma == objetivo) {   ///verifica si se puede sumar los dados lanzados para que el total sea igual al num objetivo
            return true;
        }
    }
    return false;
}

