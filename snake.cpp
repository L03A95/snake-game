#include <iostream>
#include "rlutil.h"

using namespace std;

int main () {
    for (int y = 0; y < 40; y++) {
        for (int x = 0; x < 70; x++)
        {
            if(y == 0 || y == 39 || x == 0 || x == 69) {
                cout<<"X";
            } else {
                cout<<" ";
            }
        }
        cout<<endl;
    }
    
    rlutil::getkey(KEY_UP);

    return 0;
}