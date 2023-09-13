#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    ofSetupOpenGL(800, 480, OF_WINDOW);			// <-------- setup the GL context
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}


//TODO:
// Introduce randomness into Prims and Kruskals algos. 
//	-Leave option for adjusting weights in graphs depending... 
//    on audio frequency analysis for example
// implement Dijkstra algo
// implement Kruskal algo
// implement Prime's algo
// Generate switch function for maze algos.
// Reset Grid values when generating new mazes
// find out how to integrate color gradient add-on
// implementation of ofxColorMap to differentiate distances between cells
// Implement Dither algorithm to maze 
// Implement communication bia OSC with supercollider
// Integrate touch interface RBPi
