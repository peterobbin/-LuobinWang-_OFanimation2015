//
//  customCircle.cpp
//  w03_h01
//
//  Created by peterobbin on 2/23/15.
//
//

#include "customCircle.h"


void customCircle::setup(){
    
    
    
}

void customCircle::update(ofVec2f _pos, ofVec2f _nextPos, ofVec2f _pos2, ofVec2f _nextPos2, float _rad){
    pos = _pos;
    nextPos = _nextPos;
    pos2 = _pos2;
    nextPos2 = _nextPos2;
    
    rad = _rad;
    
    
    float sinOfTime = sin(ofGetElapsedTimef()*1);
    float cosOfTime = cos(ofGetElapsedTimef()*1);
    float mul = ofMap(sinOfTime, -1, 1, -20, 10);
    float mul2 = ofMap(cosOfTime, -1, 1, -20, 10);
    
    offset = ofVec2f(mul, mul);
    offset2 = ofVec2f(mul2, mul2);
    
}


void customCircle::draw(){
    
    
    ofCircle(pos, rad);
    ofCircle(pos2, rad);
    //ofLine(pos,nextPos);
}

void customCircle::drawLine(float _thick){
thick = _thick;
    
    //ofLog(OF_LOG_NOTICE, "the number is " + ofToString(mul));
   // ofSetLineWidth(thick);
    
    
   
    ofLine(pos+offset, pos2+offset2);


}