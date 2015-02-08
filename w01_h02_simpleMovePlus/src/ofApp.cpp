#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    myCircle.setup(ofVec2f(0,500), ofVec2f(ofGetWindowWidth(), 500));
    pct = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if (pct < 0.99){
        pct += 0.01;}
    
    myCircle.easeIn(pct);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    myCircle.draw();
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
