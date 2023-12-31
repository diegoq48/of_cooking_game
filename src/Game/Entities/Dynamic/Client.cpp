#include "Client.h"

//boilerplate code for the clients in the game
Client::Client(int x, int y, int width, int height, ofImage sprite, Burger* burger): Entity(x, y, width, height, sprite){
    this->burger = burger;
}
Client::~Client(){
    delete burger;
}
void Client::render(){
    burger->render();
    ofSetColor (255,patience/10 ,patience/10);
    sprite.draw(x, y, width, height);
    ofSetColor (255,255,255);
    if(nextClient != nullptr){
        nextClient->render();
    }
}

void Client::tick(){
    patience--;
    burger->setY(y);
    if(patience == 0){
        
        isLeaving = true;

    }
    if(nextClient != nullptr){
        nextClient->tick();
    }
}

int Client::serve(Burger* burger){
    if (burger->equals(this->burger)){
        isServed = true;
        return this->burger->getCost()*3;
    }
    if(nextClient == nullptr){
        return 0;
    }
    else{
        return nextClient->serve(burger);
    }
}



