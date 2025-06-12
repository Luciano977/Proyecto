#include <iostream>
#include <ctime>
#include "dados.h"
#include "rlutil.h"

using namespace std;

int main(){
     /// se debe ejecutar una sola vez por programa

    srand (time(nullptr));
    int jugador1, jugador2;
    int tiradaSeis[6];
    int tiradaDoce[2];
    int sumaSeis=0, sumaDoce=0, opcion;

    cout << "Arrojemos los dados para saber quien comienza el juego"<< endl;
    cout << "------------------------------------------------------"<< endl<< endl; ///Se arrojan los dados para saber quien comienza el juego
    jugador1 = tirarDadosSeisCaras();
    cout << "El jugador 1 tiro: "<<jugador1<< endl;
    rlutil::anykey();
    jugador2 = tirarDadosSeisCaras();
    cout << "El jugador 2 tiro: "<<jugador2<< endl;
    rlutil::anykey();
    cout << endl;
    if (jugador1 == jugador2){
        opcion = 0;
    }
        else if (jugador1 > jugador2){
            opcion = 1;
        }
            else {
                opcion = 2;
            }
    switch (opcion){
            case 0:
                cout <<"Ambos obtuvieron los mismos puntos, volvamos a tirar" << endl;
                break;
            case 1:
                cout <<"Comienza tirando el jugador 1, vamos a jugar!!!"<< endl;
                break;
            case 2:
                cout <<"Comienza tirando el jugador 2, vamos a jugar!!!"<< endl;
                break;
    }


    tiradaDados12(tiradaDoce, 2);

    int puntosObtenidosDoce = calcularPuntos(tiradaDoce, 2);


    for(int i=0; i<2 ; i++){
        cout << endl;
        cout << "El "<<i+1<<" dado arrojo el numero: "<<tiradaDoce[i]<< endl;
        sumaDoce+= tiradaDoce[i];
    }
    cout <<" Los puntos obtenidos son: "<< sumaDoce<< endl; ///puntosObtenidosDoce
    cout <<" ----------------------------"<< endl;

    tiradaDados6(tiradaSeis, 6);

    int puntosObtenidosSeis = calcularPuntos(tiradaSeis, 6);


    for (int i=0; i<6; i++){
        cout << endl;
        cout <<"El "<<i+1<<" dado arrojo el numero: "<< tiradaSeis[i]<< endl;
        sumaSeis+= tiradaSeis[i];

    }
    cout <<" Los puntos obtenidos son: "<< sumaSeis<< endl;; ///puntosObtenidosSeis
    cout <<" ----------------------------"<< endl;



    return 0;
}
