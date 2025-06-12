#include <iostream>
#include "rlutil.h"
using namespace std;
/***
Como hacer un menu
*/

void mostrarCreditos();
int main(){
    int opcion;
     rlutil::setBackgroundColor(rlutil::BLUE);
     rlutil::setColor(rlutil::WHITE);
    do{
        system ("cls"); ///limpia la pantalla para la nueva opcion
        rlutil::locate(5, 5);
        cout << "BIENVENIDO AL JUEGO ENFRENDADOS" << endl;
        rlutil::locate(5, 6);
        cout << "-------------------------------" << endl;
        cout << endl<< endl;
        cout << "1- JUGAR" << endl;
        cout << endl;
        cout << "2- ESTADISTICAS" << endl;
        cout << endl;
        cout << "3- CREDITOS" << endl;
        cout << endl;
        cout << "-----------------" << endl;
        cout << endl;
        cout << "0 - SALIR" << endl;
        cout << "Elige una opcion : " ;
        cin >> opcion;

        switch (opcion){
            case 1:
                cout <<"VAMOS A JUGAR" << endl;
                break;
            case 2:
                cout <<"ESTADISTICAS: "<< endl;
                break;
            case 3:

                cout <<"CREDITOS: "<< endl;
                mostrarCreditos();
                break;
            case 0:
                cout <<"Gracias por utilizar mi aplicacion :) "<< endl;
                break;
        default:
            cout <<endl <<"Opcion no valida... :(" << endl;
            rlutil::anykey();
        }
        system ("pause");///hace una pausa antes de borrar

    }while (opcion !=0);


    return 0;
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
