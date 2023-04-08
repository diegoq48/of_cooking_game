#include "ofApp.h"

SettingState::SettingState() {
    img1.load("images/setting.png");
}


void SettingState::tick() {
}

void SettingState::render() {
    img1.draw(0,0);
}

void SettingState::keyPressed(int key) {
}


void SettingState::mousePressed(int x, int y, int button) {
}


void SettingState::reset() {
    setFinished(false);
    setNextState("");
}

