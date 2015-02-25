#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    myCircle.setup(ofVec2f(ofGetWidth()/2, ofGetHeight()/2));
    secondCircle.setup(ofVec2f(ofGetWidth()/2, ofGetHeight()/2));
    thirdCircle.setup(ofVec2f(ofGetWidth()/2, ofGetHeight()/2));
    fourthCircle.setup(ofVec2f(ofGetWidth()/2, ofGetHeight()/2));
    fifthCircle.setup(ofVec2f(ofGetWidth()/2, ofGetHeight()/2));
    pct = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    myCircle.update(ofVec2f(ofGetMouseX(), ofGetMouseY()), 0.1);
    secondCircle.update(ofVec2f(ofGetMouseX(), ofGetMouseY()), 0.2);
    thirdCircle.update(ofVec2f(ofGetMouseX(), ofGetMouseY()), 0.3);
    fourthCircle.update(ofVec2f(ofGetMouseX(), ofGetMouseY()), 0.4);
    fifthCircle.update(ofVec2f(ofGetMouseX(), ofGetMouseY()), 0.5);
}

//--------------------------------------------------------------
void ofApp::draw(){
    myCircle.draw(255,0,40);
    secondCircle.draw(80,130,99);
    thirdCircle.draw(25,222,55);
    fourthCircle.draw(0,32,0);
    fifthCircle.draw(255,255,0);
    
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
