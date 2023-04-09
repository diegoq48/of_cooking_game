#include "SettingState.h"
void SettingState::getSongs(){
    ofDirectory dir = ofDirectory("audioFiles"); 
    for (auto file : dir.getFiles()){
        std::string ext = file.getExtension();
        if (ext == "mp3" || ext == "wav" || ext == "ogg" || ext == "flac" ){
            songs.push_back(file);
        }
    }
    

}

SettingState::SettingState(Restaurant *res) {
    getSongs();
    this->restaurant = res;
    img1.load("images/setting.png");
    sound.setVolume(0.5);
    font.load("fonts/sans-serif.ttf", 24);
    sound.load(songs[activeSong]);
    sound.play();
    sound.setLoop(true);
    

}


void SettingState::tick() {
    ticks++;
    optionsResults[0] = "1 Customer every " + to_string(restaurant->getSpawnRate()/100) + " seconds";
    optionsResults[1] = to_string((int)(sound.getVolume()*100))+"%";
    optionsResults[2] = songs[activeSong].getFileName();
}

void SettingState::render() {
    img1.draw(0,0,ofGetWidth(),ofGetHeight());

    for (int i = 0; i < 3; i++){
        if (i == selectedSetting){
            ofSetColor(255, 165, 0);
        } else {
            ofSetColor(255);
        }
        font.drawString(options[i], 100, 100 + i * 100);
        font.drawString(optionsResults[i], 300, 100 + i * 100);
    }
    font.drawString("Press 'g' to go back to the game", 100, 500);
    font.drawString("Use the up and down arrow keys to select a setting", 100, 550);
    font.drawString("Use the left and right arrow keys to change the setting", 100, 600);
}

void SettingState::keyPressed(int key) {
    switch (key){
        case OF_KEY_UP:
            selectedSetting--;
            if (selectedSetting < 0){
                selectedSetting = 2;
            }
            break;
        case OF_KEY_DOWN:
            selectedSetting++;
            if (selectedSetting > 2){
                selectedSetting = 0;
            }
            break;
        case OF_KEY_LEFT:
            switch (selectedSetting){
                case 2:
                    if (activeSong == 0){
                        activeSong = songs.size() - 1;
                        playActiveSong();
                    } else {
                        activeSong--;
                        playActiveSong();
                    }
                    break;
                case 1:
                    if(0 < sound.getVolume()) sound.setVolume(sound.getVolume() - 0.1);
                    break;
                case 0:
                    if(restaurant->getSpawnRate() > 100) restaurant->setSpawnRate(restaurant->getSpawnRate() - 100);
                    break;
            }
            break;
        case OF_KEY_RIGHT:
            switch (selectedSetting){
                case 2:
                    if (activeSong == songs.size() - 1){
                        activeSong = 0;
                        playActiveSong();
                    } else {
                        activeSong++;
                        playActiveSong();
                    }
                    break;
                case 1:
                    if (sound.getVolume() < 1){
                        sound.setVolume(sound.getVolume() + 0.1);
        
                    }
                    break;
                case 0:
                    if(restaurant->getSpawnRate() < 1000) restaurant->setSpawnRate(restaurant->getSpawnRate() + 100);
                    break;
            }

            break;
        case 'g':
            setFinished(true);
            setNextState("Game");
            break;
    }
}

void SettingState::playActiveSong(){
    sound.stop();
    sound.load(songs[activeSong]);
    sound.play();
    sound.setLoop(true);
}

void SettingState::mousePressed(int x, int y, int button) {
}


void SettingState::reset() {
    setFinished(false);
    setNextState("");
}

