#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    pos.set(ofGetWidth()/2,ofGetHeight()/2);
    
    for(int i = 0; i < 11; i++){
        
        for(int k = 0; k < 11; k++){
        customDots myDots;
        myDots.setup();
        dotsList.push_back(myDots);
        }
    
    }
    
//    for(int i = 0; i < N; i++){
//        for(int k = 0; k < M; k++){
//            pos.set(i*50, k*50);
//            myDots[i][k].update(pos,10);
//        }
//    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < 10; i++){
        for(int k = 0; k < 10; k++){
            pos.set(i*90 + 90, k*90 + 90);
            
            
            float sinOfTime = sin(ofGetElapsedTimef()*(k+i));
            float offset = ofNoise(ofGetElapsedTimeMillis()*10);
            float offsetval = ofMap(offset, 0, 1, 0, 10);
            float mul = ofMap(sinOfTime, -1, 1, 0.1,1 );
        
            dotsList[i*10 + k].update(pos,10 * mul);
            
            
            }
        }
    
    
//    for(int i = 0; i < N; i++){
//        for(int k = 0; k < M; k++){
//            pos.set(i*50, k*50);
//        myDots[i][k].update(pos,10);
//        }
//    }
//    
    
  }

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i < 10; i++){
        for(int k = 0; k < 10; k++){
        dotsList[i*10 + k].draw();
        }
        
    }
    
    
    
    
//    for(int i = 0; i < N; i++){
//        for(int k = 0; k < N; k++){
//            pos.set(i*50, k*50);
//            myDots[i][k].draw();
//        }
//    }
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
