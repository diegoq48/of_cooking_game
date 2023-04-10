#include "looseState.h"

// constructor
looseState::looseState(Restaurant *res) {
	font.load("sans-serif.ttf", 10);
    restaraunt = res;
    ofSetColor(0);
}

void looseState::tick() {
}

// Equivalent to the draw function in the  ofApp class
void looseState::render() {
	ofSetBackgroundColor(230, 230, 250);
    ofSetColor(0,0,0);
	font.drawString("You lost 10 costumers left the restaraunt" , ofGetWidth() / 2, ofGetHeight() / 2 + 40);
    font.drawString("Press 'r' to restart", ofGetWidth() / 2, ofGetHeight() / 2 + 140);
    font.drawString("You served: " + ofToString(10) + "costumers", ofGetWidth() / 2, ofGetHeight() / 2 + 160);
    font.drawString("Press q to quit", ofGetWidth() / 2, ofGetHeight() / 2 + 180);
}

// uses r to restart the and q to quit the game
void looseState::keyPressed(int key){
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

void looseState::reset(){
	setFinished(false);
	setNextState("");
}

void looseState::mousePressed(int x, int y, int button){
}