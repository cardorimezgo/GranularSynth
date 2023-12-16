#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main() {
	ofSetupOpenGL(800, 480, OF_WINDOW);			// <-------- setup the GL context
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}


//TODO:
// (7)Refine interface design
// (6)Option for adjusting maze's grid size(granular)
// (2)Calculate longest path in maze (use DFS for all algos weighted and unweighted mazes) 
//	-Leave option for adjusting weights in graphs depending... 
//    on audio frequency analysis for example
// (1)implement DFS maze algos.
// (3)find out how to integrate color gradient add-on
// (4)implementation of ofxColorMap to differentiate distances between cells
// (5)Implement Dither algorithm to maze 
// (8)Implement communication via OSC with supercollider
// (9)Integrate touch interface RBPi (reading USB port to download audio sample)


///ISSUES : 
//			-DYNAMIC RENDERING OF THE MAZE,  AVOID REFRESHING THE WHOLE TEXTURE AND UPDATE ONLY THE ESSENTIALS
//			-ENCODING AND DECODING OF 2D VECTOR OF CELLS TO A 1D VECTOR WHERE THE INDEX SETS THE ORDER OF THE PATH