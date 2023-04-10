#pragma once

/* This file is the base class called state which dictates what the program should be doing */

#include "ofMain.h"
#include "Restaurant.h"


// large chuncks of the code are just rehashes of the ofBaseApp functions
// if finished is true, the state will be changed to the next state
class State {
	public:
		State() {}
		virtual void reset() = 0;
		virtual void tick() = 0;
		virtual void render() = 0;
		virtual void keyPressed(int key) = 0;
		virtual void mousePressed(int x, int y, int button) = 0;

		virtual void keyReleased(int key){}
		void mouseMoved(int x, int y){}
		void mouseDragged(int x, int y, int button){}
		void mouseReleased(int x, int y, int button){}
		void mouseEntered(int x, int y){}
		void mouseExited(int x, int y){}
		void windowResized(int w, int h){}
		void gotMessage(ofMessage msg){}
		void dragEvent(ofDragInfo dragInfo){}
		bool hasFinished(){
			return finished;
		}
		string getNextState(){
			return nextState;
		}
		void setFinished(bool finished){
			this->finished = finished;
		}

		void setNextState(string nextState){
			this->nextState = nextState;
		}

	private:
		string nextState;
		bool finished = false;

};