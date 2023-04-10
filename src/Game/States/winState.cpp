#include "winState.h"
//Called when the user wins the game in other words when the player has over 100 units of money
winState::winState(Restaurant *res) {
	font.load("sans-serif.ttf", 10);
    restaraunt = res;
    ofSetColor(0);
}
void winState::tick() {
}
// Equivalent to the render function in the  ofApp class 
void winState::render() {
	ofSetBackgroundColor(230, 230, 250);
    ofSetColor(0,0,0);
	font.drawString("You won capitalism you earned over 100$" , ofGetWidth() / 2, ofGetHeight() / 2 + 40);
    font.drawString("Press 'r' to restart", ofGetWidth() / 2, ofGetHeight() / 2 + 140);
    font.drawString("You served: " + ofToString(10) + "costumers", ofGetWidth() / 2, ofGetHeight() / 2 + 160);
    font.drawString("Press q to quit", ofGetWidth() / 2, ofGetHeight() / 2 + 180);
}

// uses r to restart the and q to quit the game and '/' to go to the settings menu
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
        case '/':
            setFinished(true);
            setNextState("Settings");
            break;
        default:
            break;
    }
}

void winState::reset(){
	setFinished(false);
}

void winState::mousePressed(int x, int y, int button){
}