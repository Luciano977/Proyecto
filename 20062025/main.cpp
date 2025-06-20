#include <iostream>
#include "dados.h"
#include "rlutil.h"
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    int opcion, opcionTiradas;
    int maximoPuntaje;
    string mejorJugador;
    string jugadorUno, jugadorDos;
    string nombre;
    rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
    rlutil::setColor(rlutil::BLACK);


    do{

        rlutil::cls(); ///limpia la pantalla para la nueva opcion
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
        case 1:
            cout <<"VAMOS A JUGAR" << endl;
            rlutil::cls();
            ///Esta funcion realiza el juego, y nos trae el maximo puntaje y el mejor jugador para la estadistica.
            jugarPartida (jugadorUno, jugadorDos, maximoPuntaje, mejorJugador);

        case 2:
            cout <<"ESTADISTICAS" << endl;
            cout <<" Mejor puntaje: "<< maximoPuntaje<< " del jugador "<< mejorJugador;
            rlutil::anykey();
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

        }


    }while (opcion !=0);

    return 0;

}



