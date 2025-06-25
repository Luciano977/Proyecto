#include <iostream>
#include <ctime>
#include "rlutil.h"
using namespace std;


void dibujarCuadrado(int posx, int posy);
void dibujarDado(int numero, int posx, int posy);


int main() {
    srand(time(0));
    rlutil::hidecursor();
    rlutil::saveDefaultColor();

    for (int i=1; i <=6; i++){
        dibujarDado(i,i*10,rand()%10+1);
    }


    ///rlutil::anykey();
    rlutil::resetColor();



    return 0;
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

