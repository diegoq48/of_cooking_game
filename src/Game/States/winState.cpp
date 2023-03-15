#include "winState.h"

winState::winState() {
	font.load("sans-serif.ttf", 10);
    restaraunt = new Restaurant();
    ofSetColor(0);
}
void winState::tick() {
}
void winState::render() {
	ofSetBackgroundColor(230, 230, 250);
    ofSetColor(0,0,0);
	font.drawString("You won 10 costumers were served at the restaraunt" , ofGetWidth() / 2, ofGetHeight() / 2 + 40);
    font.drawString("Press 'r' to restart", ofGetWidth() / 2, ofGetHeight() / 2 + 140);
    font.drawString("You served: " + ofToString(10) + "costumers", ofGetWidth() / 2, ofGetHeight() / 2 + 160);
    font.drawString("Press q to quit", ofGetWidth() / 2, ofGetHeight() / 2 + 180);
}


void winState::keyPressed(int key){
	switch(key){
        case 'r':
            restaraunt->reset();
            setNextState("Game");
            setFinished(true);
            break;
        case 'q':
            ofExit();
            break;
    }
}

void winState::reset(){
	setFinished(false);
	setNextState("");
}

void winState::mousePressed(int x, int y, int button){
}