#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofBackground(0);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    myCircle.setup(ofVec2f(ofGetWindowWidth()/2,ofGetWindowHeight()/2), ofVec2f(ofGetWindowWidth()/2,ofGetWindowHeight()/2));
    pct = 0;
    rad = 0;
    maxRad = 10;
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if (pct < 0.99){
        pct += 0.01;
    }
    
    rad = maxRad * (1 - pct);
    
    myCircle.easeOut(pct);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(0,0,0,99);
    ofRect(0,0,ofGetWidth(),ofGetHeight());//motion blur
    myCircle.draw(rad);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    pct = 0.0;
    myCircle.setNewPos(ofVec2f(x, y));
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
