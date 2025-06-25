#include <cstdlib>  /// para poder usar rand y generar numeros aleatorios
#include "dados.h"
#include "rlutil.h"
#include <iostream>
using namespace std;
//////////////////////////////////////////////
///mostrar menu
void mostrarMenu(){
    cout << endl<< endl;
    cout << "1 - JUGAR" << endl<< endl;
    cout << "2 - ESTADISTICAS " << endl<< endl;
    cout << "3 - CREDITOS" << endl<< endl;
    cout << "-----------------" << endl<< endl;
    cout << "0 - SALIDA"<< endl<< endl;
}
//////////////////////////////////////////////
/// validacion de la entrada de int opcion;
int leerOpcionMenu(){
    int opcion;

    while (true){
        cout << "Ingrese una opcion (0 al 3): ";
        cin >> opcion;

        if (cin.fail()|| opcion<0 || opcion>3){
        cin.clear();    ///limpiamos el estado de error cin
        cin.ignore(1000, '\n');   ///descarta la entrada incorrecta
        cout <<"Entrada incorrecta. Por favor, ingrese un numero del 0 al 3."<<endl;
        } else{
        cin.ignore(1000, '\n'); ///descarta el sobrante del buffer
        return opcion;
        }
    }
}
//////////////////////////////////////////////
/// Pide el nombre del jugador
string obtenerNombre(){
    string jugador;

    cout <<"Ingresa tu nombre : ";
    cin >> jugador;
    return jugador;
}
//////////////////////////////////////////////
/// Da un numero aleatorio entre 1 y 6
int tirarDadosSeisCaras() {
    return 1 + rand() % 6;
}
//////////////////////////////////////////////
///Da un numero aleatorio entre 1 y 12
int tirarDadosDoceCaras() {
   return 1 + rand() % 12;
}
//////////////////////////////////////////////
///Muestra los creditos
void mostrarCreditos(){
    cout<<" Este Juego fue desarrollado por los alumnos"<< endl;
    cout<<" de la UTN FACULTAD REGIONAL GENERAL PACHECO "<< endl;
    cout<<" -------------------------------------------"<< endl;
    cout<< "Facundo Sosa - Legajo Nro. 28812"<< endl;
    cout<< "Jorge Cristian Garay -  Legajo Nro."<< endl;
    cout<< "Luciano Damian Cejas - Legajo Nro.32457"<< endl;
    cout<< "Pablo Nicolas Bozicek - Legajo Nro."<< endl;
    cout<< endl;
    cout<<" -------------------------------------------"<< endl<< endl;
    cout<< "­Agradecemos tu colaboracion y por jugar!"<< endl<< endl;
    cout<< "  Equipo:  Cada vez C++ "<< endl;
    rlutil::anykey();
    rlutil::cls();
}
//////////////////////////////////////////////
///ronda de jugada
int jugarRonda(string jugadorActivo, int &dadosJugador, int &dadosContrincante){
    int vDados6Caras[11]{}; /// stock maximo de dados

    /* 1. Asigno valor de dados stock de 6 caras */
    for (int i = 0; i < dadosJugador; ++i)
        vDados6Caras[i] = tirarDadosSeisCaras();

    /* 2. Declaro dados objetivo alcanzables */
    int dado12Caras1, dado12Caras2, resultadoSuma12caras;
    int intentos = 0, maxIntentos = 100;

    do {
        ///Asigno valor de dados objetivos
        dado12Caras1 = tirarDadosDoceCaras();
        dado12Caras2 = tirarDadosDoceCaras();
        resultadoSuma12caras = dado12Caras1 + dado12Caras2;
        ++intentos;
    } while (!sePuedeSumarObjetivo(vDados6Caras, dadosJugador, resultadoSuma12caras) && intentos < maxIntentos);

    ///mostrar tirada de los dados objetivos
    cout << "----------------------------------------------\n";
    cout << "Jugando: " << jugadorActivo << '\n';
    cout << "Dados objetivo: " << dado12Caras1 <<" + "<< dado12Caras2 <<" || Numero objetivo : " << resultadoSuma12caras << '\n';
    cout << "----------------------------------------------\n";
    ///
    for (int i = 0; i < dadosJugador; ++i)
        cout << " [" << i + 1 << "]=>" << vDados6Caras[i];
    cout << endl;

    ///elegir dados
    int sumaElegida = 0, pos;
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
        sumaElegida += vDados6Caras[pos - 1];
        cout << "La suma da " << sumaElegida << ", N£mero Objetivo: " << resultadoSuma12caras << endl;
        cantElegir++;


        /// vemos si quedan dados sin usar comparando con la suma objetivo

        if (sumaElegida>=resultadoSuma12caras) {
        break;
        }

        bool quedanDados=false;
        int sumaMaximaPosible=sumaElegida;
        for (int i=0;i<dadosJugador;i++) {
            if (!usados[i]){
                quedanDados=true;
                sumaMaximaPosible+= vDados6Caras[i];
            }
        }
        ///finaliza el turno

      if (!quedanDados || sumaMaximaPosible < resultadoSuma12caras){

        cout << "no hay mas jugadas posibles, termina tu turno sin penalizar."<<endl;
        break;
        }
    }while (true);

    cout << "\nSuma elegida : " << sumaElegida << '\n';
    cout << "N£mero objetivo: " << resultadoSuma12caras << '\n';


    ///puntuaciones (se a¤adio penalizacion)
    if (sumaElegida == resultadoSuma12caras){
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
//////////////////////////////////////////////
///verifica si se pueden sumar los dados stock y llegar a el numero de dados objetivos
bool sePuedeSumarObjetivo(int dados[], int cantidad, int objetivo){
    int totalCombinaciones = 1 << cantidad; ///2 elevado a la cantidad (para generar conbinaciones posibles) :)

    for (int comb = 1; comb < totalCombinaciones; comb++){
        int suma = 0;
        for (int i = 0; i < cantidad; i++) {
            /// Si en la combinacion (comb) el dado i esta seleccionado lo suma.

            if ((comb / (1 << i)) % 2 == 1) {
                suma += dados[i];
            }
        }
        if (suma == objetivo){///verifica si se puede sumar los dados lanzados para que el total sea igual al num objetivo
            return true;
        }
    }
    return false;
}
///////////////////////////////////
///Inicio del juego
void jugarPartida (string jugadorUno, string jugadorDos, int &maximoPuntaje, string &mejorJugador){
    int tiradaUno, tiradaDos, opcionTiradas;
    int cantidadDadosInicioP1 = 6;
    int cantidadDadosInicioP2 = 6;
    const int RONDAS = 3;
    int puntosP1 = 0, puntosP2 = 0;

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
    ///Defino quien comienza..
    if (tiradaUno > tiradaDos){
        opcionTiradas = 1;
    }else {
        opcionTiradas = 2;
    }

    switch (opcionTiradas){
    case 1:{
        cout << "Comienza tirando el jugador " <<jugadorUno<< ". ­vamos a jugar!\n";

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
    case 2:{
        cout << "Comienza tirando el jugador "<<jugadorDos<< ". ­vamos a jugar!"<<endl;

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
            if (cantidadDadosInicioP1 > 0){
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
/// esta funcion dibuja el cuadrado
void dibujarCuadrado(int posx, int posy){
    rlutil:: setColor(rlutil::WHITE);
    for (int x=posx; x<= posx + 6; x++){
        for (int y=posy; y<=posy + 2; y++){
            rlutil::locate(x,y);
            cout << (char) 219;
        }

    }
}
/// esta funcion dibuja los puntos
void dibujarDado(int numero, int posx, int posy){
    dibujarCuadrado(posx,posy);

    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::WHITE);

    switch(numero){
    case 1:
       rlutil::locate(posx+3,posy+1);
        cout << (char)254;///(char) 254 punto medio
        break;
    case 2:
       rlutil::locate(posx+1,posy);
       cout << (char)220;///(char) 220 punto superior
       rlutil::locate(posx+5,posy+2);
       cout << (char)223;///(char) 223 punto inferior
        break;
    case 3:

       rlutil::locate(posx+1,posy);
       cout << (char)220;
       rlutil::locate(posx+5,posy+2);
       cout << (char)223;
       rlutil::locate(posx+3,posy+1);
        cout << (char)254;
        break;
    case 4:
        rlutil::locate(posx+1,posy);
       cout << (char)220;
        rlutil::locate(posx+5,posy);
       cout << (char)220;
       rlutil::locate(posx+5,posy+2);
       cout << (char)223;
       rlutil::locate(posx+1,posy+2);
       cout << (char)223;
        break;
    case 5:
        rlutil::locate(posx+1,posy);
       cout << (char)220;
        rlutil::locate(posx+5,posy);
       cout << (char)220;
       rlutil::locate(posx+5,posy+2);
       cout << (char)223;
       rlutil::locate(posx+1,posy+2);
       cout << (char)223;
       rlutil::locate(posx+3,posy+1);
        cout << (char)254;
        break;
    case 6:
       rlutil::locate(posx+1,posy);
       cout << (char)220;
       rlutil::locate(posx+3,posy);
       cout << (char)220;
        rlutil::locate(posx+5,posy);
       cout << (char)220;
       rlutil::locate(posx+5,posy+2);
       cout << (char)223;
       rlutil::locate(posx+1,posy+2);
       cout << (char)223;
       rlutil::locate(posx+3,posy+2);
        cout << (char)223;
        break;
    }

}
