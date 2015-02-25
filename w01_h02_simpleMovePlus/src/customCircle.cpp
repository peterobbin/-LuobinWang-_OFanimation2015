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
    ofSetColor(255*(1 -pct)); // alpha animation
    ofLine(currentPos,finalPos);
    ofDrawBitmapString("x"  + ofToString(finalPos.x) + ", " + "y" + ofToString(finalPos.y) + ", " + ofToString(pct*100) + "%", finalPos);
    
    ofNoFill();
    ofCircle(finalPos, 50 * pct*(2-pct));
    ofFill();
    
    
    
    ofSetColor(255, 255, 255);
    ofCircle(currentPos, rad);
    currentPos = initPos * (1 - pct) + finalPos * pct;
    
}



void customCircle::setNewPos(ofVec2f _newPos){
    
    initPos = currentPos;
    finalPos = _newPos;
    
    
}