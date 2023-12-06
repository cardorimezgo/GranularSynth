#pragma once

#include "ofMain.h"
#include "Maze_Algos.h"
#include "Maze_Run.h"
#include "Maze_Sz.h"        


// Delta time
const int FPS = 60;
const int MILLISECS_PER_FRAME = 1000 / FPS;

enum AppState {
	WAITING_FOR_INPUT,
	MAZE_GENERATION,
	MAZE_GENERATED,
	RENDERING_COMPLETE,
	GENERATE
};

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	///KEYBOARD INPUT
	bool set_size = false;
	bool set_maze = false;
	/////////////////////

	bool clearBuffer = false;
	int currentIndex = 0;

	ofFbo Draw_Buffer;
	
	Maze_Algos maze_algo;
	Maze_Sz sz;	
	Maze_Run run = Maze_Run(sz , maze_algo);

private:
	AppState currentState;
};