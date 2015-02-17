#pragma once

#include "ofMain.h"
#include "customStars.h"

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
		
    
    
  
    
    
    
    customStars myStar;
    ofMesh testMesh;
    
    
    #define NUM_CIRCLES 20
    
    customStars dmyStar[NUM_CIRCLES];
    
    ofMesh mesh[NUM_CIRCLES];
    ofVec3f stars[NUM_CIRCLES];
    float hori[NUM_CIRCLES];
    float vert[NUM_CIRCLES];
    
    
};
