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
// (10)Refine interface design
// (10)Option for adjusting maze's grid size
// (4)Calculate longest path in maze (use DFS for all algos weighted and unweighted mazes)
// (5)Integrate Prims and Kruskals algos into Maze_Generator. 
//	-Leave option for adjusting weights in graphs depending... 
//    on audio frequency analysis for example
// (1)implement Dijkstra algo (Done) TODO: --- checking for linked neighbors / send finalized to Cell renderer /
//		 setting weight to same value / set option to adjust weight values
// (2)implement Kruskal algo
// (3)implement Prime's algo
// (4)implement DFS maze algos.
// (7)Generate switch function for maze algos.
// (6)Reset Grid values when generating new mazes
// (8)find out how to integrate color gradient add-on
// (9)implementation of ofxColorMap to differentiate distances between cells
// (10)Implement Dither algorithm to maze 
// (11)Implement communication bia OSC with supercollider
// (12)Integrate touch interface RBPi (reading USB port to download audio sample)


///ISSUES : -PRINTING TWO TIMES FLOOD_FILL WHEN QUITING THE PROGRAM
//			-NOT GETTING TOTAL NUMBER OF  CELLS IN FLOOD_FILL
//			-WHEN FLOOD FILL HAS LESS THAN TOTAL NUMBER OF CELLS, THE ORDERED LIST WILL ADD NEGATIVE NUMBERS PER EACH CELL MISSING			
//			-CHECK MEMORY MANAGEMENT, VIRTUAL DESTRUCTORS NEED TO BE IMPLEMENTED?, CELLS USE NEW FOR THEIR CREATION