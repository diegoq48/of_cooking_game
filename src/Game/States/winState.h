#pragma once

#include "State.h"

class winState : public State {
private:
	Restaurant *restaraunt;
	ofTrueTypeFont font;

public:
	winState(Restaurant *res);
	void tick();
	void render();
	void keyPressed(int key);
	void reset();
	void mousePressed(int x, int y, int button);
};
