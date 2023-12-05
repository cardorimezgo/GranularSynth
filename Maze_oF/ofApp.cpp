    #include "ofApp.h"
    #include "ofGraphics.h"

    void ofApp::setup() {       
        ofBackground(0, 0, 0);

        currentState = WAITING_FOR_INPUT;
        Draw_Buffer.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    }

    void ofApp::update() {      

        static unsigned long lastUpdateTime = 0;
        unsigned long currentTime = ofGetElapsedTimeMillis();
        //static int currentIndex = 0;
        static int stepSize = 22; // Adjust this value for faster or slower rendering

        if (currentTime - lastUpdateTime > MILLISECS_PER_FRAME) {
            if (currentState == MAZE_GENERATION) {  //<- remove state machine
                Draw_Buffer.begin();

                if (clearBuffer) {
                    ofClear(0, 0, 0);
                    clearBuffer = false;
                }

                for (int i = 0; i < stepSize && currentIndex < sz.get_Total_Cells(); ++i) {
                    run.Render(currentIndex);
                    currentIndex++;
                }
                Draw_Buffer.end();

                if (currentIndex >= sz.get_Total_Cells()) {
                    currentState = MAZE_GENERATED;
                }
            }
            lastUpdateTime = currentTime;
        }
    }

    //-View-------------------------------------------------------------
    void ofApp::draw() {
        
        if (currentState == WAITING_FOR_INPUT){
            std::string m_size = "chose 1 through 4 for the size of the maze: ";
            std::string c_maze = "chose initial letter for maze algorithm: ";
            std::string g_maze = "press / when ready to generate";
            ofDrawBitmapString(m_size, 100, 100);
            ofDrawBitmapString(c_maze, 100,200);
            ofDrawBitmapString(g_maze, 100, 250);
        }

        else{
            ofSetColor(255, 255, 255);
            Draw_Buffer.draw(0, 0);
            
            //set_size = false;
            //set_maze = false;
        }
    }

    //--------------------------------------------------------------
    void ofApp::keyPressed(int key) {
        
        if (key >= '0' && key <= '4') {
            set_size = sz.set_Maze_Sz(key);
        }

        if(key>= 'a' && key<= 'z' || key>= 'A' && key<= 'Z') {
            set_maze = run.Select_Maze(key);
        }

        if(set_size && set_maze && key == '/'){ // (/)SLASH STANDS FOR GENERATE BUTTON
            currentIndex = 0;
            clearBuffer = true;
            run.Setup_Maze(maze_algo);
            currentState = MAZE_GENERATION;        
        }
        
    }

    //--------------------------------------------------------------
    void ofApp::keyReleased(int key) {

    }

    //--------------------------------------------------------------
    void ofApp::mouseMoved(int x, int y) {

    }

    //--------------------------------------------------------------
    void ofApp::mouseDragged(int x, int y, int button) {

    }

    //--------------------------------------------------------------
    void ofApp::mousePressed(int x, int y, int button) {

    }

    //--------------------------------------------------------------
    void ofApp::mouseReleased(int x, int y, int button) {

    }

    //--------------------------------------------------------------
    void ofApp::mouseEntered(int x, int y) {

    }

    //--------------------------------------------------------------
    void ofApp::mouseExited(int x, int y) {

    }

    //--------------------------------------------------------------
    void ofApp::windowResized(int w, int h) {

    }

    //--------------------------------------------------------------
    void ofApp::gotMessage(ofMessage msg) {

    }

    //--------------------------------------------------------------
    void ofApp::dragEvent(ofDragInfo dragInfo) {

    }
