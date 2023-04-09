#include "GameState.h"

GameState::GameState(Restaurant *res) {
    this->restaurant = res;
}
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
void GameState::render() {
	restaurant->render();
}

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