#include "MenuState.h"

MenuState::MenuState() {
	string text = "Start";
	font.load("sans-serif.ttf", 10);
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
void MenuState::render() {
	ofSetBackgroundColor(230, 230, 250);
	startButton->render();
	exitButton->render();
	font.drawString("Instructions: ", ofGetWidth() / 2, ofGetHeight() / 2 + 40);
	font.drawString("Use the arrow keys to move", ofGetWidth() / 2 - strlen("Use the arrow "), ofGetHeight() / 2 + 60);
	font.drawString("Press space to shoot", ofGetWidth() / 2, ofGetHeight() / 2 + 80);
	font.drawString("Press 'p' to pause", ofGetWidth() / 2, ofGetHeight() / 2 + 100);
	font.drawString("Press 'r' to restart", ofGetWidth() / 2, ofGetHeight() / 2 + 120);
	font.drawString("Press 'm' to return to this menu", ofGetWidth() / 2, ofGetHeight() / 2 + 140);
}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}