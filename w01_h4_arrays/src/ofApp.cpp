#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
   
    ofSetFrameRate(60);
    
    for(int i = 0; i < NUM_CIRCLES; i++){
        pct[i] = (i + 0.01)*0.01;
        myCircle[i].setup(ofVec2f(ofGetWidth()/2, ofGetHeight()/2));
        scatterX[i] = ofRandom(-500,500);
        scatterY[i] = ofRandom(-500,500);
        rad[i] = i/2;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    //ofNoFill();
    for (int i = 0; i<NUM_CIRCLES; i++){
    myCircle[i].update(ofVec2f(ofGetMouseX()+scatterX[i], ofGetMouseY()+scatterY[i]), pct[i]);
        
        scatterX[i] = scatterX[i] + ofRandom(-1,1);
        scatterY[i] = scatterY[i] + ofRandom(-1,1);
    }
    
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i< NUM_CIRCLES ; i++){
    myCircle[i].draw(255,255,255,rad[i], i);
    
    }
  
    
    
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
