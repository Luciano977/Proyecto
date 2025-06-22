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
         cout <<"-------------------------------------------------------------------------------------\n";
        cout <<"       |  ____| \\ | |  ____|  __ \\|  ____| \\ | |  __ \\   /\\   |  __ \\ / __ \\ / ____|\n";
        cout <<"       | |__  |  \\| | |__  | |__) | |__  |  \\| | |  | | /  \\  | |  | | |  | | (___  \n";
        cout <<"       |  __| | . ` |  __| |  _  /|  __| | . ` | |  | |/ /\\ \\ | |  | | |  | |\\___ \\ \n";
        cout <<"       | |____| |\\  | |    | | \\ \\| |____| |\\  | |__| / /__\\ \\| |__| | |__| |____) |\n";
        cout <<"       |______|_| \\_|_|    |_|  \\_\\______|_| \\_|_____/_/    \\_\\_____/ \\____/|_____/\n";
        cout <<"    -------------------------------------------------------------------------------------\n";

        ///https://www.patorjk.com/software/taag/#p=display&h=2&v=2&f=Big&t=ENFRENDADOS (por si lo quieren ver)

        cout << endl<< endl;
        cout << "1 - JUGAR" << endl<< endl;
        cout << "2 - ESTADISTICAS " << endl<< endl;
        cout << "3 - CREDITOS" << endl<< endl;             ///Menu del juego
        cout << "-----------------" << endl<< endl;
        cout << "0 - SALIDA"<< endl<< endl;

        cout << " Elija una opcion: ";

         while (true) {
          cin >> opcion;

         if (cin.fail() || opcion < 0 || opcion > 3) {
          cin.clear(); /// limpia los errores
          cin.ignore(1000, '\n'); /// descarta lo que haya quedado en buffer
          cout << " Entrada invalida. Por favor, ingrese un n£mero entre 0 y 3: ";
           } else {
          cin.ignore(1000, '\n'); /// limpia cualquier
        break;
    }
}

         switch (opcion){
        case 1:
            cout <<"VAMOS A JUGAR" << endl;
            rlutil::cls();
            ///Esta funcion realiza el juego, y nos trae el maximo puntaje y el mejor jugador para la estadistica.
            jugarPartida (jugadorUno, jugadorDos, maximoPuntaje, mejorJugador);
            break;
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



