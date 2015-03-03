#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    mover.setup(50, 500, 1.0);
    
    gravity.set(0,0.5);
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    mover.resetForces();
   // windStrenth = ofMap(ofNoise(ofGetElapsedTimef()*0.1), 0, 1, -1, 1);
    //wind.set(windStrenth,0.4);
   // ofLog(OF_LOG_NOTICE, "wind force is " + ofToString(windStrenth));
   
  //  mover.applyForce(wind);
    
    
     mover.applyForce(gravity*mover.mass);
   
    //ofLog(OF_LOG_NOTICE, "wind force is " + ofToString(mouseVel.x) + "  "+ ofToString(mouseVel.y));
     mouseVel.set((ofGetMouseX()-ofGetPreviousMouseX())/5,(ofGetMouseY()-ofGetPreviousMouseY())/5);
     mover.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    mover.draw();
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
    
   
    mover.resetForces();
    mover.resetVel();
    mover.setup(ofGetMouseX(), ofGetMouseY(), 1.0);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    mover.setup(ofGetMouseX(), ofGetMouseY(), 1.0);
    //mover.resetForces();
    //mover.resetVel();
    
    
    mover.applyForce(mouseVel);
    
   

   mover.update();
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
