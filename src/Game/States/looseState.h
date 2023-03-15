#pragma once

#include "State.h"

class MenuState : public State {
private:
	ofTrueTypeFont font;

public:
	MenuState();
	void render();
	void keyPressed(int key);
	void reset();
};
