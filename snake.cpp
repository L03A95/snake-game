#include <iostream>
#include "rlutil.h"

using namespace std;

int main () {
    int posY = 20, posX = 35;
    int direction = 0;

    while (true) {

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
                if(y == 0 || y == 39 || x == 0 || x == 69) {
                    rlutil::setColor(rlutil::RED);
                    cout<<"X";
                } else {
                    if(posY == y && posX == x) {
                        rlutil::setColor(rlutil::GREEN);
                        cout<<"S";
                    }
                    else {
                        cout<<" ";
                    }
                }
            }
        cout<<endl;
        }
    

    rlutil::msleep(200);
    }

    return 0;
}