#include "ofApp.h"




//--------------------------------------------------------------
void ofApp::setup(){
    testMesh.setMode(OF_PRIMITIVE_POINTS);
   // ofBackground(0);
    
    ofVec3f top(100.0, 50.0, 0.0);
    ofVec3f left(50.0, 150.0, 0.0);
    ofVec3f right(150.0, 150.0, 0.0);
//    
//    for (int i = 0; i < NUM_CIRCLES; i++){
//        
//        stars[i] = ofVec3f(ofVec3f(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()),0));
//        mesh[i].addVertex(stars[i]);
//        
//    //dmyStar[i].setup(ofVec3f(100,100,0));
// 
//    }
    
    
    testMesh.addVertex(top);
    testMesh.addVertex(left);
    testMesh.addVertex(right);
    
   // myStar.setup(ofVec3f(50,50,0));
    
   
}

//--------------------------------------------------------------
void ofApp::update(){
    
//    for (int i = 0; i < NUM_CIRCLES; i++){
//        //stars[i]=ofVec3f(ofRandom(0,ofGetWidth()), ofRandom(0, ofGetHeight()), 0.0);
//        myStar[i].setup(30,30,30);
//        hori[i]=0;
//        vert[i]=0;
//        
//        
//    }
    
    
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
//    myStar.draw();
//    for (int i = 0; i < NUM_CIRCLES; i++){
//        mesh[i].draw();
//        
//    }
    testMesh.draw();
    
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
