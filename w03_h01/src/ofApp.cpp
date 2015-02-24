#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    // pos = ofVec2f(300, 300);
    rad = 2;
    
    
    for(float i = 0; i<17; i++){
        customCircle myCircle;
        customCircle myCircle2;
        
        
        myCircle.setup();
        myCircle2.setup();
        circleList.push_back(myCircle);
        circle2List.push_back(myCircle2);
        // circle2List.push_back(myCircle);
        
        
        
    }


}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (float i = 1; i < 17; i++) {
        
        float sinOfTime = sin(ofGetElapsedTimef()*i/10);
        float nextSinOfTime = sin(ofGetElapsedTimef()*(i+1)/10);
        float cosOfTime = cos(ofGetElapsedTimef()*i/10);
        float nextCosOfTime = cos(ofGetElapsedTimef()*(i+1)/10);
        
        
        
       
        float offset = sinOfTime * 100;
        
        
        float offset2 = cosOfTime * 100;
        float nextOffset = nextSinOfTime * 100;
        float nextOffset2 = nextCosOfTime * 100;
        float x = i*60;
        float a = x;
        float nextX = (i+1)*60;
        float nextA = nextX;
        float y = ofGetHeight()/2 + offset;
        float b = ofGetHeight()/2 + offset2;
        float nextY = ofGetHeight()/2 + nextOffset;
        float nextB = ofGetHeight()/2 + nextOffset2;
        
        
        
        ofVec2f nextPos = ofVec2f(nextX, nextY);
        ofVec2f pos = ofVec2f(x, y);
        ofVec2f nextPos2 = ofVec2f(nextA, nextB);
        ofVec2f pos2 = ofVec2f(a, b);
        
      
        
        circleList[i].update(pos, nextPos, pos2, nextPos2, rad);
       // circle2List[i].update(pos2, nextPos2, rad);
        
        
        
    }


}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (float i = 1; i < 17; i++) {
        circleList[i].draw();
       // circle2List[i].draw();
       
        
    }
    
    for (float i = 1; i < 17; i++) {
        
        
        
        circleList[i].drawLine(1);
      //  circle2List[i].drawLine();
        
        
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
