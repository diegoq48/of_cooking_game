#include "MenuState.h"

// Menu constructor uses buttons OH the humanity 
MenuState::MenuState() {
	string text = "Start";
	font.load("sans-serif.ttf", 20);
	startButton = new Button(ofGetWidth()/2 - text.length()*8, ofGetHeight()/2 - text.length()*11, 64, 50, "Start");
	exitButton = new Button(ofGetWidth()/2 - text.length()*8, (ofGetHeight()/2) + 20 - text.length()*11, 64, 50, "Exit");
}
void MenuState::tick() {
	exitButton->tick();
	if (exitButton->wasPressed()) {
		std::cout << "Exit button pressed" << std::endl;
		ofExit();
	}
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);
	}
	

}
// Equivalent to the draw function in the  ofApp class
void MenuState::render() {
	ofSetBackgroundColor(230, 230, 250);
	startButton->render();
	exitButton->render();
	font.drawString("Instructions: ", ofGetWidth() / 2 -100, ofGetHeight() / 2  + 40);
	font.drawString("Use the arrow keys to move", ofGetWidth() / 2 -100, ofGetHeight() / 2 + 60);
	font.drawString("Press e to add ingredient to the burger", ofGetWidth() / 2 -100, ofGetHeight() / 2 + 80);
	font.drawString("Press 'p' to pause", ofGetWidth() / 2 -100, ofGetHeight() / 2 + 100);
	font.drawString("Press 'r' to restart restaurant", ofGetWidth() / 2 -100, ofGetHeight() / 2 + 120);
	font.drawString("Press 'q' to quit", ofGetWidth() / 2 -100, ofGetHeight() / 2 + 140);
	font.drawString("Press 's' to serve burger", ofGetWidth() / 2 -100, ofGetHeight() / 2 + 160);
	font.drawString("Press 'u' to undo", ofGetWidth() / 2 -100, ofGetHeight() / 2 + 180);
	font.drawString("Press '/' to go to settings", ofGetWidth() / 2 -100, ofGetHeight() / 2 + 200);
	font.drawString("Press s on this screen to start the game", ofGetWidth() / 2 -100, ofGetHeight() / 2 + 220);
}

// uses s to start the game and q to quit the game and '/' to go to the settings menu
void MenuState::keyPressed(int key){
	switch(key) { 
		case 's':
			setNextState("Game");
			setFinished(true);
			break;
		case '/':
			setNextState("Settings");
			setFinished(true);
			break;
		case 'q':
			ofExit();
			break;
		default:
			break;
	}

	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}