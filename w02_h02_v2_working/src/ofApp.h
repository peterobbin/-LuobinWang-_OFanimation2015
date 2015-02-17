#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofEasyCam cam;
    ofMesh mesh;
    ofMesh testMesh;
    float xtime = 0;
    float lastime;
    
    
    #define NUM_STARS 20
    ofMesh newMesh[NUM_STARS];
    ofVec3f stars[NUM_STARS];
    ofVec3f scatter[NUM_STARS];
		
};
