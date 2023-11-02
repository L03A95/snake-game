#include <iostream>
#include "rlutil.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int randomNum (int direction) {
    srand(time(NULL));
    int result = 0;

    if(direction == 0) {
        result = 1 + (rand() % 39);
    }
    else if (direction == 1) {
        result =  1 + (rand() % 69);
    }
    return result;
}

int main () {
    int posY = 20, posX = 35, direction = 0, puntaje = 0, appleY = 0, appleX = 0;

    while (true) {

        if(posY == appleY && posX == appleX) {
            appleY = 0;
            appleX = 0;
            puntaje += 1;
        }

        if (appleY == 0 || appleX == 0) {
            appleY = randomNum(0);
            appleX = randomNum(1);
        }


        int key = rlutil::nb_getch();
        key == 0 ? direction = direction : direction = key;
        switch (direction)
        {
        case 119:
            posY -= 1;
            break;
        case 100:
            posX += 1;
            break;
        case 115:
            posY += 1;
            break;
        case 97:
            posX -= 1;
            break;
        
        default:
            break;
        }
        rlutil::cls();

        for (int y = 0; y < 40; y++) {
            for (int x = 0; x < 70; x++) {

                if(y == 0 || y == 39 || x == 0 || x == 69) { //GENERAR EL MAPA
                    rlutil::setColor(rlutil::RED);
                    cout<<"X";
                } 
                else {
                    if(posY == y && posX == x) { // GENERAR LA SERPIENTE
                        rlutil::setColor(rlutil::GREEN);
                        cout<<(char)237;
                    }
                    else if (appleY == y && appleX == x) {
                        rlutil::setColor(rlutil::YELLOW);
                        cout<<(char)149;
                    }
                    else {
                        cout<<(" ");
                    }
                }
            }
        cout<<endl;
        }
    

    rlutil::msleep(200);
    }

    return 0;
}