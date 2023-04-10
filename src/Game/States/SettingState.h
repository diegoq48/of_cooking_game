#include "State.h"
#include "ofMain.h"

class SettingState: public State {
    private:
    ofSoundPlayer sound; 
    ofImage img1;
    ofTrueTypeFont font;
    std::string options[3] = {"Spawn Rate" , "Volume", "Music Track"};
    std::string optionsResults[3];
    int ticks = 0;
    int selectedSetting = 0; 
    vector<ofFile> songs;
    void getSongs();
    int activeSong = 0;
    Restaurant *restaurant;



    public:
    void playActiveSong();
    SettingState(Restaurant *res);
    void tick();
	void render();
	void keyPressed(int key);
	void reset();
	void mousePressed(int x, int y, int button);
};