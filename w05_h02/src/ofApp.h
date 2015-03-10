#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxFaceTracker.h"
#include "ofxGui.h"

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
    
    
    
    ofVideoGrabber iSight;
    vector<ofVec3f> offsets;
    bool faceShadow;
    int test;
    
    
    ofMesh mesh;
    ofEasyCam easyCam;
    //ofImage image;
    
    ofxFaceTracker tracker;
    ExpressionClassifier classifier;
    ofVec2f noseBase;
    
    ofxCvColorImage image;
    ofxCvGrayscaleImage grayImage, grayImagePrev;
    ofxCvGrayscaleImage diff;
    ofxCvFloatImage diffFloat;
    ofxCvFloatImage bufferFloat;
    
    
    
    ofxLabel notification;
    
    ofxPanel gui;
    
    
};
