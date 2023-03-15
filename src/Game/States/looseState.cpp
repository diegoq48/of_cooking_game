#include "MenuState.h"

MenuState::MenuState() {
	font.load("sans-serif.ttf", 10);
}
void MenuState::tick() {
}
void MenuState::render() {
	ofSetBackgroundColor(230, 230, 250);
	font.drawString("You lost 10 costumers left the restaraunt" , ofGetWidth() / 2, ofGetHeight() / 2 + 40);
    font.drawString("Press 'r' to restart", ofGetWidth() / 2, ofGetHeight() / 2 + 140);
    font.drawString("You served: " + ofToString(10) + "costumers", ofGetWidth() / 2, ofGetHeight() / 2 + 160);
}

void MenuState::keyPressed(int key){
	switch(key){
        case 'r':
            setNextState("Game");
            setFinished(true);
            break;
        case 'q':
            ofExit();
            break;
    }
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
}