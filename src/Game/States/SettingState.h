#include "State.h"


class SettingState: public State {
    private:
    ofImage img1;

    public:
    SettingState();
    void tick();
	void render();
	void keyPressed(int key);
	void reset();
	void mousePressed(int x, int y, int button);
};