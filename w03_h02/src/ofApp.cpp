#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    
    for(int i = 0; i<10; i++){
        Cross myCross;
        myCross.setup();
        crossList.push_back(myCross);
        
    }
    
    npos.set(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    
    ofVec2f newPos;
    newPos.set(ofGetMouseX(), ofGetMouseY());
    npos = npos * 0.97 + newPos * 0.03;
    
    
    diff = newPos - npos;
    rot = atan2(diff.y, diff.x);
    rot = ofRadToDeg(rot);
    
   
    
    
    
    
    
    
    
    for(int i=0; i<10; i ++ ){
        
        float rad = 100;
        float shapeRad = 10;
        ofVec2f pos, innerPos;
        
        
        float angle = PI*2/10*i;
        pos.x =   cos(angle)* rad;
        pos.y =   sin(angle)* rad;
        
        
        
        innerPos.x =  cos(angle)* rad/2;
        innerPos.y =  sin(angle)* rad/2;
       // innerPos = innerPos * 0.97 + npos * 0.03;
        
        ofVec2f center = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
        
        
        crossList[i].update(ofGetMouseX(),ofGetMouseY(), pos, innerPos, diff, shapeRad);
        
    }

    
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(npos);
    ofRotate(rot);
    
    for(int i=0; i<10; i ++ ){
        
    crossList[i].draw();
        
    }
    ofPopMatrix();
    
    
   
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
