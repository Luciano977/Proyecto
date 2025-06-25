#include <iostream>
#include "dados.h"
#include "rlutil.h"
#include <ctime>

using namespace std;

int main(){
    srand(time(0));
    int opcion, opcionTiradas;
    int maximoPuntaje=0;
    string mejorJugador;
    string jugadorUno, jugadorDos;
    string nombre;
    rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
    rlutil::setColor(rlutil::BLACK);

    do{
        rlutil::cls(); ///limpia la pantalla para la nueva opcion
        rlutil::locate(5,5);
        ///https://www.patorjk.com/software/taag/#p=display&h=2&v=2&f=Big&t=ENFRENDADOS (por si lo quieren ver)
        cout <<"-------------------------------------------------------------------------------------\n";
        cout <<"       |  ____| \\ | |  ____|  __ \\|  ____| \\ | |  __ \\   /\\   |  __ \\ / __ \\ / ____|\n";
        cout <<"       | |__  |  \\| | |__  | |__) | |__  |  \\| | |  | | /  \\  | |  | | |  | | (___  \n";
        cout <<"       |  __| | . ` |  __| |  _  /|  __| | . ` | |  | |/ /\\ \\ | |  | | |  | |\\___ \\ \n";
        cout <<"       | |____| |\\  | |    | | \\ \\| |____| |\\  | |__| / /__\\ \\| |__| | |__| |____) |\n";
        cout <<"       |______|_| \\_|_|    |_|  \\_\\______|_| \\_|_____/_/    \\_\\_____/ \\____/|_____/\n";
        cout <<"    -------------------------------------------------------------------------------------\n";

        /// Muestra menu
        mostrarMenu();
        ///llamamos a validacion de ingreso
        opcion=leerOpcionMenu();

        switch (opcion){
        case 1:
            cout <<"VAMOS A JUGAR" << endl;
            rlutil::cls();
            ///Esta funcion realiza el juego, y nos trae el maximo puntaje y el mejor jugador para la estadistica.
            jugarPartida (jugadorUno, jugadorDos, maximoPuntaje, mejorJugador);
            break;
        case 2:
            rlutil::cls();
            rlutil::hidecursor();
            rlutil::saveDefaultColor();
            for (int i=1; i <=6; i++){
                dibujarDado(i,i*10,rand()%10+1);
            }
            rlutil::resetColor();
            rlutil::locate(8,15);
            cout <<"ESTADISTICAS" << endl;
            if(maximoPuntaje==0){
                cout<<"Todavia no existe un maximo puntaje."<<endl;
            }else{
                cout <<" Mejor puntaje: "<< maximoPuntaje<< " del jugador "<< mejorJugador;
            }
            rlutil::anykey();
            break;
        case 3:
            rlutil::cls();
            rlutil::hidecursor();
            rlutil::saveDefaultColor();
            for (int i=1; i <=6; i++){
                dibujarDado(i,i*10,rand()%10+1);
            }
            ///rlutil::anykey();
            rlutil::resetColor();
            rlutil::locate(8,15);
            cout <<"CREDITOS" << endl;
            mostrarCreditos();
            break;
        case 0:
            cout <<"Gracias por utilizar nuestra aplicacion :)"<< endl;
            break;
        default:
            cout <<endl<<"Opcion no valida .... :( "<< endl;
            rlutil::anykey();
        }
    }while (opcion !=0);
    return 0;
}



