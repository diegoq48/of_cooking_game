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

void StoveCounter::drawCookingBar(){
    ofSetColor(0, 0, 0);
    ofDrawRectangle(x, y, width, height);
    ofSetColor(255, 25, 255);
    ofDrawRectangle(x, y + 100, width * (cookTime / cookTimeMax), height);
}

void StoveCounter::startCooking(){
    //Start the cooling
    if(cookTime < cookTimeMax){
        cookTime++;
        std::cout << "Cooking== " <<cookTime << std::endl;
        drawCookingBar();
    }
    else{
        isCooked = true;
    }
    // When the cooking is done set isCooking to false
    if(isCooked){
    isCooking = false;
    cookTime = 0;
    canGrab = true;
    std::cout << "Cooking Done: " << canGrab<< std::endl;
    
    isCooked = false;
    }


}