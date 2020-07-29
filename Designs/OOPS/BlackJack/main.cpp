#include<iostream>
#include "game.h"

int main(){

    addDealer();

    addPlayer();
    addPlayer();
    addPlayer();
    addPlayer();
    
    start();
    turn();
    checkWin();

    system("pause");
}
