#include "GameState.h"
// constructor
GameState::GameState(Restaurant *res) {
    this->restaurant = res;
}

// checks if the player has lost or won and if so changes the state to the win or loose state
void GameState::tick() {
	restaurant->tick();
	if(restaurant->lost){
		setNextState("Loose");
		setFinished(true);
	}
	if(restaurant->won){
		setNextState("Win");
		setFinished(true);
	}
	
}
// calls the render function in the restaurant ptr 
void GameState::render() {
	restaurant->render();
}

// uses p to go to the menu, r to restart the game and '/' to go to the settings menu otherwise it calls the keyPressed function in the restaurant ptr
void GameState::keyPressed(int key){
	switch (key) {
		case 'p':
			setNextState("Menu");
			setFinished(true);
			break;
		case 'r':
			restaurant->reset();
			break;
		case '/':
            setFinished(true);
            setNextState("Settings");
            break;
	}
	restaurant->keyPressed(key);
}

void GameState::mousePressed(int x, int y, int button){
}

void GameState::keyReleased(int key){
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
}