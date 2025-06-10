#include <iostream>

#include "rlutil.h"
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
    int opcion, opcionTiradas;
    string jugadorUno, jugadorDos;
    int tiradaUno =0, tiradaDos =0;
    string nombre;
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::WHITE);

    do{

        system ("cls"); ///limpia la pantalla para la nueva opcion
        rlutil::locate(5,5);
        cout << "BIENVENIDOS AL JUEGO ENFRENTADOS"<< endl;
        cout << "--------------------------------"<< endl;
        cout << endl<< endl;
        cout << "1 - JUGAR" << endl<< endl;
        cout << "2 - ESTADISTICAS " << endl<< endl;
        cout << "3 - CREDITOS" << endl<< endl;
        cout << "-----------------" << endl<< endl;
        cout << "0 - SALIDA"<< endl<< endl;
        cout <<" Elija una opcion: ";
        cin >> opcion;

        switch (opcion){
        case 1:
            cout <<"VAMOS A JUGAR" << endl;
            system ("cls");
            ///Pido el nombre al primer jugador
            jugadorUno = obtenerNombre();
            cout << endl;
            ///Pido el nombre al segundo jugador
            jugadorDos = obtenerNombre();
            cout <<endl;
            cout << "Arrojemos los dados para saber quien comienza el juego"<< endl;
            cout << "------------------------------------------------------"<< endl<< endl; ///Se arrojan los dados para saber quien comienza el juego

            tiradaUno = tirarDadosSeisCaras();///Arroja los dados el primero jugador
            cout <<"El jugador "<<jugadorUno<<" arrojo el: "<<tiradaUno<< endl;
            system ("pause");
            tiradaDos = tirarDadosSeisCaras();///Arroja los dados el segundo jugador
            cout <<"El jugador "<<jugadorDos<<" arrojo el: "<<tiradaDos<< endl;

            break;


        case 2:
            cout <<"ESTADISTICAS" << endl;
            break;
        case 3:
            cout <<"CREDITOS" << endl;
            mostrarCreditos();
            break;
        case 0:
            cout <<"Gracias por utilizar mi aplicacion :)"<< endl;
            break;

        default:
            cout <<endl<<"Opcion no valida .... :("<< endl;
            rlutil::anykey();


            }
        ///system ("pause"); /// hace una pausa antes de borrar

    }while (opcion !=0);




    return 0;

}
string obtenerNombre(){
    string jugador;

    cout <<"Ingresa tu nombre : ";
    cin >> jugador;
    return jugador;

}
/*
if (tiradaUno == tiradaDos){
                opcionTiradas = 10;
            }
            else if (tiradaUno > tiradaDos){
                opcionTiradas = 20;
            }
                else {
                    opcionTiradas = 30;
                }
            switch (opcionTiradas){
            case 10:
                cout <<"Ambos obtuvieron los mismos puntos, volvamos a tirar" << endl;
                break;
            case 20:
                cout <<"Comienza tirando el jugador 1, vamos a jugar!!!"<< endl;
                break;
            case 30:
                cout <<"Comienza tirando el jugador 2, vamos a jugar!!!"<< endl;
                break;
            }

/*
void tiradaDados12(tiradaDoce, 2){

    int puntosObtenidosDoce = calcularPuntos(tiradaDoce, 2);

    for(int i=0; i<2 ; i++){
        cout << endl;
        cout << "El "<<i+1<<" dado arrojo el numero: "<<tiradaDoce[i]<< endl;
        sumaDoce+= tiradaDoce[i];
    }
    cout <<" Los puntos obtenidos son: "<< sumaDoce<< endl; ///puntosObtenidosDoce
    cout <<" ----------------------------"<< endl;
}

void tiradaDados6(tiradaSeis, 6){

    int puntosObtenidosSeis = calcularPuntos(tiradaSeis, 6);


    for (int i=0; i<6; i++){
        cout << endl;
        cout <<"El "<<i+1<<" dado arrojo el numero: "<< tiradaSeis[i]<< endl;
        sumaSeis+= tiradaSeis[i];

    }
    cout <<" Los puntos obtenidos son: "<< sumaSeis<< endl;; ///puntosObtenidosSeis
    cout <<" ----------------------------"<< endl;
}
*/
int tirarDadosSeisCaras(){
    return rand() %6 + 1;

}
int tirarDadosDoceCaras(){
    return rand() % 12 + 1;
}

void tiradaDados12 (int vecDoce[], int cant){
    for(int i=0; i<cant; i++){
        vecDoce[i]=tirarDadosDoceCaras();
    }
}
void tiradaDados6 (int vecSeis[], int cant){
    for(int i=0; i<cant; i++){
        vecSeis[i]=tirarDadosSeisCaras();
    }
}

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

}
