#pragma once

#include "ofMain.h"
#include "customCircle.h"


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
    
    
   
    
    
#define NUM_CIRCLES 20
    customCircle myCircle[NUM_CIRCLES];
    float pct[NUM_CIRCLES];
    float scatterX[NUM_CIRCLES], scatterY[NUM_CIRCLES];
    float rad[NUM_CIRCLES];
    
};
