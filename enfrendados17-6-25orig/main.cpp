#include <iostream>
#include "dados.h"
#include "rlutil.h"
#include <ctime>
using namespace std;

///Declaracion de funciones

string obtenerNombre();
int tirarDadosSeisCaras();
int tirarDadosDoceCaras();
void tiradaDados12 (int vec[], int cant);
void tiradaDados6 (int vec[], int cant);
void mostrarCreditos();


int main()
{
    srand(time(0));
    int opcion, opcionTiradas;
    string jugadorUno, jugadorDos;
    string nombre;
    rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
    rlutil::setColor(rlutil::BLACK);


    do{

        system ("cls"); ///limpia la pantalla para la nueva opcion
        rlutil::locate(5,5);

    cout << " ______ _   _ ______ _____  ______ _   _ _____          _____   ____   _____" <<endl;
    cout << "|  ____| \ | |  ____|  __ \|  ____| \ | |  __ \   /\   |  __ \ / __ \ / ____|"<<endl;
    cout << "| |__  |  \| | |__  | |__) | |__  |  \| | |  | | /  \  | |  | | |  | | (___  "<<endl;
    cout << "|  __| | . ` |  __| |  _  /|  __| | . ` | |  | |/ /\ \ | |  | | |  | |\___ \ "<<endl;
    cout << "| |____| |\  | |    | | \ \| |____| |\  | |__| / ____ \| |__| | |__| |____) |"<<endl;
    cout << "|______|_| \_|_|    |_|  \_\______|_| \_|_____/_/    \_\_____/ \____/|_____/ "<<endl;

              ///en titulo no me lee los guiones bajo todo seguido a mi en mi consola, quizas a ustedes si. Esto lo saque de
              ///https://www.patorjk.com/software/taag/#p=display&h=2&v=2&f=Big&t=ENFRENDADOS (por si lo quieren ver) .




        cout << "-----------------------------------------------------------------------------------------------"<< endl;
        cout << endl<< endl;
        cout << "1 - JUGAR" << endl<< endl;                        ///Menu del juego
        cout << "2 - ESTADISTICAS " << endl<< endl;
        cout << "3 - CREDITOS" << endl<< endl;
        cout << "-----------------" << endl<< endl;
        cout << "0 - SALIDA"<< endl<< endl;
        cout <<" Elija una opcion: ";
        cin >> opcion;

        switch (opcion){
        case 1:{
             int tiradaUno =0, tiradaDos =0;  /*declaramos dentro del case 1 ya que sino al no cerrar el programanos da errores de jugabilidad*/
             int cantidadDadosInicioP1 = 6;
             int cantidadDadosInicioP2 = 6;
             const int RONDAS = 3;
             int puntosP1 = 0, puntosP2 = 0;
             int jugadorQueEmpieza = 0;

            cout <<"VAMOS A JUGAR" << endl;
            system ("cls");
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
            system ("pause");
            cout << endl;

            tiradaDos = tirarDadosSeisCaras();///Arroja los dados el segundo jugador
            cout <<"El jugador "<<jugadorDos<<" arrojo el: "<<tiradaDos<< endl;
            system ("pause");
            cout << endl;

            if (tiradaUno == tiradaDos){
                cout << "empate en la tirada inicial. Volvemos a tirar..."<<endl;
                system ("pause") ;
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
                    system("pause");
                  }

                    /* Resultadoss*/
                    cout << "\n========== RESULTADO FINAL ==========\n";
                    cout << jugadorUno << ": " << puntosP1 << " puntos (" << cantidadDadosInicioP1 << " dados)\n";
                    cout << jugadorDos << ": " << puntosP2 << " puntos (" << cantidadDadosInicioP2 << " dados)\n";

                    if (puntosP1 > puntosP2){
                            cout << "Ganador " << jugadorUno << "\n";
                    }
                        else if (puntosP2 > puntosP1){
                            cout << "Ganador " << jugadorDos << "\n";
                        }
                        else{
                            cout << "Empate\n";
                        }

                        system("pause");
                        break;
                }

            case 30:{
                cout << "Comienza tirando el jugador "<<jugadorDos<< ". ­vamos a jugar!"<<endl;

                jugadorQueEmpieza = 2;           // siempre arranca jugador 2 si gana tirada
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
                        system("pause");
                }

                    /* Resultadoss*/
                    cout << "\n========== RESULTADO FINAL ==========\n";
                    cout << jugadorUno << ": " << puntosP1 << " puntos (" << cantidadDadosInicioP1 << " dados)\n";
                    cout << jugadorDos << ": " << puntosP2 << " puntos (" << cantidadDadosInicioP2 << " dados)\n";

                    if (puntosP1 > puntosP2){
                            cout << "Ganador " << jugadorUno << "\n";
                    }
                        else if (puntosP2 > puntosP1){
                            cout << "Ganador " << jugadorDos << "\n";
                        }
                        else{
                            cout << "Empate\n";
                        }

                        system("pause");

            }
                 break;
            }
        }
        case 2:
            cout <<"ESTADISTICAS" << endl;
            break;
        case 3:
            cout <<"CREDITOS" << endl;
            mostrarCreditos();
            break;
        case 0:
            cout <<"Gracias por utilizar nuestra aplicacion :)"<< endl;
            break;

        default:
            cout <<endl<<"Opcion no valida .... :("<< endl;
            rlutil::anykey();



        ///system ("pause"); /// hace una pausa antes de borrar
        }


    }while (opcion !=0);

    return 0;

}



