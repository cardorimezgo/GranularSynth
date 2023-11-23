    #include "ofApp.h"
    #include "ofGraphics.h"

    void ofApp::setup() {       
        ofBackground(0, 0, 0);
    
        currentState = WAITING_FOR_INPUT;
        Draw_Buffer.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    }

    void ofApp::update() {

        if (currentState == MAZE_GENERATION) {
            static unsigned long lastUpdateTime = 0;
            unsigned long currentTime = ofGetElapsedTimeMillis();
            static int stepSize = 22; // Control speed: higher value for faster rendering

            if (currentTime - lastUpdateTime > MILLISECS_PER_FRAME) {
                static int currentIndex = 0;

                for (int i = 0; i < stepSize; ++i) {
                    if (currentIndex < sz.get_Total_Cells()) {
                        Draw_Buffer.begin();
                        run.Render(currentIndex);
                        Draw_Buffer.end();
                        currentIndex++;
                    }
                }
                lastUpdateTime = currentTime;
            }
        }
    }

    //-View-------------------------------------------------------------
    void ofApp::draw() {
        ofClear(0, 0, 0);

        if (currentState == WAITING_FOR_INPUT){
            std::string m_size = "chose 1 through 4 for the size of the maze: ";
            std::string c_maze = "chose initial letter for maze algorithm: ";
            ofDrawBitmapString(m_size, 100, 100);
            ofDrawBitmapString(c_maze, 100,200);
        }

        else if (currentState == MAZE_GENERATED) {
            Draw_Buffer.draw(0, 0);
            currentState = WAITING_FOR_INPUT;
            set_size = false;
            set_maze = false;
        }
    }

    //--------------------------------------------------------------
    void ofApp::keyPressed(int key) {

        if (key>= '0' && key<= '4'){
            set_size = sz.set_Maze_Sz(key);
        }

        if(key>= 'a' && key<= 'z' || key>= 'A' && key<= 'Z') {
            set_maze = run.Select_Maze(key);        
        }

        if(set_size && set_maze){
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
