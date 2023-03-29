#include "StoveCounter.h"


void StoveCounter::tick(){
    if (isCooking){
        std::cout <<" is Cooking" << std::endl;
        startCooking();
    }
}

void StoveCounter::setIsCooking(bool sett) {
        this->isCooking = sett;
    }
bool StoveCounter::getIsCooking() {
        return isCooking;
    }
bool StoveCounter::getisCooked() {
        return isCooked;
    }
void StoveCounter::setisCooked(bool sett) {
        this->isCooked = sett;
    }


void StoveCounter::showItem(){
    // Draw the item grayed out if it is not cooked
    if (!canGrab){
        ofSetColor(100, 100, 100);
        item->sprite.draw(x+width/2 -25, y-30, 50, 30);
        ofSetColor(255, 255, 255);
    }
    else{
        ofSetColor(255, 255, 255);
        item->sprite.draw(x+width/2 -25, y-30, 50, 30);
    }
}

void StoveCounter::startCooking(){
    //Start the cooling
    if(cookTime < cookTimeMax){
        cookTime++;
        std::cout << "Cooking== " <<cookTime << std::endl;
    }
    else{
        isCooked = true;
    }
    // When the cooking is done set isCooking to false
    if(isCooked){
    isCooking = false;
    cookTime = 0;
    isCooked = false;
    canGrab = true;
    std::cout << "Cooking Done: " << canGrab<< std::endl;
    }


}