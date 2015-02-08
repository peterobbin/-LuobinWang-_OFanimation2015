//
//  customCircle.cpp
//  w01_h01_simepleMove
//
//  Created by peterobbin on 2/8/15.
//
//

#include "customCircle.h"

void customCircle::setup(ofVec2f _initPos, ofVec2f _finalPos){
    initPos = _initPos;
    finalPos = _finalPos;
}

void customCircle::update(float _pct){
    pct = _pct;
    currentPos = initPos * (1 - pct) + finalPos * pct;
}

void customCircle::easeIn(float _pct){
    pct = powf(_pct, 2);
    currentPos = initPos * (1 - pct) + finalPos * pct;
}

void customCircle::easeOut(float _pct){
    pct = _pct * (2 - _pct);
    currentPos = initPos * (1 - pct) + finalPos * pct;
}




void customCircle::draw(float _rad){
    rad = _rad;
    ofSetColor(255*(1 -pct));
    ofLine(currentPos,finalPos);
    ofDrawBitmapString(ofToString(finalPos.x) + ", " + ofToString(finalPos.y), finalPos);
    ofSetColor(255, 255, 255);
    ofCircle(currentPos, rad);
    currentPos = initPos * (1 - pct) + finalPos * pct;
    
}



void customCircle::setNewPos(ofVec2f _newPos){
    
    initPos = currentPos;
    finalPos = _newPos;
    
    
}