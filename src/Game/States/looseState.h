#pragma once

#include "State.h"

class looseState : public State {
private:
	Restaurant *restaraunt;
	ofTrueTypeFont font;

public:
	looseState(Restaurant *res);
	void tick();
	void render();
	void keyPressed(int key);
	void reset();
	void mousePressed(int x, int y, int button);
};
