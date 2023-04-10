#include "StoveCounter.h"


void StoveCounter::tick(){
    if (isCooking){
        std::cout <<" is Cooking" << std::endl;
        startCooking();
        showItem();
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
        // create me a variable that get the percentage 
        // of the cookTime and cookTimeMax
        float cooktimeRatio = static_cast<float>(cookTime) / static_cast<float>(cookTimeMax);

        // Interpolate color based on cooktime ratio
        int r = static_cast<int>(100 + (255 - 100) * cooktimeRatio);
        int g = static_cast<int>(100 + (255 - 100) * cooktimeRatio);
        int b = static_cast<int>(100 + (255 - 100) * cooktimeRatio);

        ofSetColor(r, g, b);
        item->sprite.draw(x+width/2 -25, y-30, 50, 30);
        ofSetColor(255, 255, 255);
    }
    else{
        ofSetColor(255, 255, 255);
        item->sprite.draw(x+width/2 -25, y-30, 50, 30);
    }
}

void StoveCounter::drawProgressBar(){
    // draw 10 pixels  more in the y axis a progress bar
    // ofSetColor(255, 255, 255);
    // ofDrawRectangle(x, y+height, width, 10);
    ofSetColor(255, 0, 0);
    ofDrawRectangle(x, y+20, 10000, 10);
    ofSetColor(255, 255, 255);
}

void StoveCounter::startCooking(){
    //Start the cooling
    if(cookTime < cookTimeMax){
        cookTime++;
        std::cout << "Cooking== " <<cookTime << std::endl;
        drawProgressBar();
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
    playCookedSound();
    }
}

void StoveCounter::playCookedSound(){
    // Play the cooked sound effect
    cookedSound.play();
}
