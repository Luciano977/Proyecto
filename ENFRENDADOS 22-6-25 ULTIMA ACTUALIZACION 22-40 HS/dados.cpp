#include <cstdlib>  /// para poder usar rand y generar numeros aleatorios
#include "dados.h"
#include "rlutil.h"
#include <iostream>
#include <algorithm> // para std::any_of
using namespace std;

///menu leer opcion

int leerOpcionMenu() {
    int opcion;

    while (true) {

        cout << "Ingrese una opcion (0 al 3): ";
        cin >> opcion;

        if (cin.fail()|| opcion<0 || opcion>3){
        cin.clear();    ///limpiamos el estado de error cin
        cin.ignore(1000, '\n');   ///descarta la entrada incorrecta
        cout <<"Entrada incorrecta. Por favor, ingrese un numero del 0 al 3."<<endl;
        } else {
        cin.ignore(1000, '\n'); ///descarta el sobrante del buffer ver?!
        return opcion;
        }
    }
}

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
    rlutil::cls();
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
    rlutil::anykey();
    rlutil::cls();

}

/// Suma todos los valores en el arreglo y devuelve el total

int calcularPuntos(int valores[], int cantidad) {
    int suma = 0;
    for (int i = 0; i < cantidad; i++) {
        suma += valores[i];
    }
    return suma;
}

       ///ronda de jugada

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
        cout << "[" << i + 1 << "] => " << vDados6Caras[i];
        cout << endl;

    ///elegir dados :D

       int sumaElegida = 0, suma = 0, pos;
int cantElegir = 0, puntosObtenidos = 0;
bool usados[11] = {};  // total de 11 dados en 0

do {
    cout << " Elige el dado: ";
    cin >> pos;

    /// Validamos la entrada
    while (cin.fail() || pos < 1 || pos > dadosJugador || usados[pos - 1]) {
        if (cin.fail()) {
            cin.clear();              /// Limpia el estado de error
            cin.ignore(1000, '\n');   /// Descarta caracteres incorrectoss
            cout << "Entrada inv lida. Ingres  solo n£meros enteros: ";
        } else if (pos < 1 || pos > dadosJugador) {
            cout << "Posici¢n incorrecta. Cont s con 1 a " << dadosJugador << " dados. Volv‚ a elegir: ";
        } else if (usados[pos - 1]) {
            cout << "Ese dado ya fue usado. Eleg¡ otro: ";
        }

        cin >> pos;
    }

    usados[pos - 1] = true;  /// Marca el dado como usado (importante)
    suma += vDados6Caras[pos - 1];
    cout << "La suma da " << suma << ", N£mero Objetivo: " << resultadoSuma12caras << endl;
    cantElegir++;

} while (suma < resultadoSuma12caras);

cout << "\nSuma elegida : " << suma << '\n';
cout << "N£mero objetivo: " << resultadoSuma12caras << '\n';


    ///puntuaciones (se a¤adio penalizacion)



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

void jugarPartida (string jugadorUno, string jugadorDos, int &maximoPuntaje, string &mejorJugador){
    int tiradaUno, tiradaDos, opcionTiradas;
    int cantidadDadosInicioP1 = 6;
    int cantidadDadosInicioP2 = 6;
    const int RONDAS = 3;
    int puntosP1 = 0, puntosP2 = 0;
    int jugadorQueEmpieza = 0;

            ///Pide el nombre al primer jugador
            jugadorUno = obtenerNombre();
            cout << endl;
            ///Pide el nombre al segundo jugador
            jugadorDos = obtenerNombre();
            cout <<endl;
            cout << "Arrojemos los dados para saber quien comienza el juego"<< endl;
            cout << "------------------------------------------------------"<< endl<< endl; ///Se arrojan los dados para saber quien comienza el juego

            do {
            tiradaUno = tirarDadosSeisCaras();///Arroja los dados el primero jugador
            cout <<"El jugador "<<jugadorUno<<" arrojo el: "<<tiradaUno<< endl;
            rlutil::anykey();
            cout << endl;

            tiradaDos = tirarDadosSeisCaras();///Arroja los dados el segundo jugador
            cout <<"El jugador "<<jugadorDos<<" arrojo el: "<<tiradaDos<< endl;
            rlutil::anykey();
            cout << endl;

            if (tiradaUno == tiradaDos){
                cout << "empate en la tirada inicial. Volvemos a tirar..."<<endl;
                rlutil::anykey();
            }
            ///ponemos un do while y a¤adimos el if dentro para la condicion de empate
            }while (tiradaUno==tiradaDos);

                if (tiradaUno > tiradaDos){
                opcionTiradas = 20;
            }
                else {
                    opcionTiradas = 30;
                }

            switch (opcionTiradas){
            case 10:
                cout <<"Ambos obtuvieron los mismos puntos, volvamos a tirar" << endl;
                break;

            case 20:{
            cout << "Comienza tirando el jugador " <<jugadorUno<< ". ­vamos a jugar!\n";
                jugadorQueEmpieza = 1;           ///siempre arranca jugador 1 si sale ganador
                int ronda = 1;

                while (ronda <= RONDAS && cantidadDadosInicioP1 > 0 && cantidadDadosInicioP2 > 0){
                    cout << "\n==========  RONDA " << ronda << " ==========\n";

                    /// Jugador 1
                    int puntosRondaP1 = jugarRonda(jugadorUno, cantidadDadosInicioP1, cantidadDadosInicioP2);
                        puntosP1 += puntosRondaP1;
                    cout << jugadorUno << " obtuvo " << puntosRondaP1 << " puntos en la ronda " << ronda << "\n";

                     /// Corte si alguien se queda sin dados
                    if (cantidadDadosInicioP1 == 0){
                            puntosP1 = 10000;
                            break;
                    }
                    /// Jugador 2 (si le quedan dados)
                    int puntosRondaP2 = 0;
                    if (cantidadDadosInicioP2 > 0) {
                    puntosRondaP2 = jugarRonda(jugadorDos, cantidadDadosInicioP2, cantidadDadosInicioP1);
                    puntosP2 += puntosRondaP2;
                    cout << jugadorDos << " obtuvo " << puntosRondaP2 << " puntos en la ronda " << ronda << "\n";
                    }

                     ///corte jugador 2 si se queda sin dados.
                    if (cantidadDadosInicioP2 == 0){
                        puntosP2 = 10000;
                            break;
                        }
                      ++ronda;
                    rlutil::anykey();
                  }

                    /* Resultadoss*/
                    cout << "\n========== RESULTADO FINAL ==========\n";
                    cout << jugadorUno << ": " << puntosP1 << " puntos (" << cantidadDadosInicioP1 << " dados)\n";
                    cout << jugadorDos << ": " << puntosP2 << " puntos (" << cantidadDadosInicioP2 << " dados)\n";

                    if (puntosP1 > puntosP2){
                            cout << "Ganador " << jugadorUno << "\n";
                            maximoPuntaje = puntosP1;
                            mejorJugador = jugadorUno;
                    }
                        else if (puntosP2 > puntosP1){
                            cout << "Ganador " << jugadorDos << "\n";
                            maximoPuntaje = puntosP2;
                            mejorJugador = jugadorDos;
                        }
                        else{
                            cout << "Empate\n";
                        }

                        rlutil::anykey();
                        break;
                }

            case 30:{
                cout << "Comienza tirando el jugador "<<jugadorDos<< ". ­vamos a jugar!"<<endl;

                jugadorQueEmpieza = 2;           // siempre arranca jugador 2 si gana la tirada
                int ronda = 1;

                while (ronda <= RONDAS && cantidadDadosInicioP1 > 0 && cantidadDadosInicioP2 > 0){
                    cout << "\n==========  RONDA " << ronda << " ==========\n";

                    /// Jugador 2
                    int puntosRondaP2 = jugarRonda(jugadorDos, cantidadDadosInicioP2, cantidadDadosInicioP1);
                    puntosP2 += puntosRondaP2;
                    cout << jugadorDos << " obtuvo " << puntosRondaP2 << " puntos en la ronda " << ronda <<endl;


                    // Corte si alguno se queda sin dados
                    if (cantidadDadosInicioP2 == 0){
                            puntosP2 = 10000;
                        break;
                    }

                    /// Jugador 1 (si le quedan dados)
                    int puntosRondaP1 = 0;
                    if (cantidadDadosInicioP1 > 0) {
                        puntosRondaP1 = jugarRonda(jugadorUno, cantidadDadosInicioP1, cantidadDadosInicioP2);
                        puntosP1 += puntosRondaP1;
                        cout << jugadorUno << " obtuvo " << puntosRondaP1 << " puntos en la ronda " << ronda << "\n";
                    }

                    if (cantidadDadosInicioP1 == 0){
                            puntosP1 = 10000;
                        break;
                    }

                        ++ronda;
                        rlutil::anykey();
                }

                    /* Resultadoss*/
                    cout << "\n========== RESULTADO FINAL ==========\n";
                    cout << jugadorUno << ": " << puntosP1 << " puntos (" << cantidadDadosInicioP1 << " dados)\n";
                    cout << jugadorDos << ": " << puntosP2 << " puntos (" << cantidadDadosInicioP2 << " dados)\n";

                    if (puntosP1 > puntosP2){
                            cout << "Ganador " << jugadorUno << "\n";
                            maximoPuntaje = puntosP1;
                            mejorJugador = jugadorUno;

                    }
                        else if (puntosP2 > puntosP1){
                            cout << "Ganador " << jugadorDos << "\n";
                            maximoPuntaje = puntosP2;
                            mejorJugador = jugadorDos;

                        }
                        else{
                            cout << "Empate\n";
                        }

                        rlutil::anykey();

            }
                 break;
            }

        }

