#include "dealer.h"

void Dealer::setPlayerSet(vector<Player*> &playerSet){
    this->playerSet = playerSet;
}

vector<Player*> Dealer :: getPlayerSet(){
    return this->playerSet;
}

void Dealer::Hit(){
    this->hand.push_back(getCard());
}

void Dealer::Distribute(){
    this->Hit();
    this->Hit();

    for(auto p : this->playerSet){
        p->Hit();
        p->Hit();
    }
}

int Dealer::CheckHand(){
    int sum = 0;
    cout<<"Dealer Hand: "<<endl;
    for(auto i : this->hand){
        if(i == 1 and sum + 11 <= 21)i = 11;
        cout<<"Card: "<<i<<endl;
        sum += i;
    }
    return sum;
}