//
//  customBall.cpp
//  w02_h03
//
//  Created by peterobbin on 2/17/15.
//
//

#include "customBall.h"


void customBall::setup(){
    ofBackground(0);
    yOffset = 10000.0;
}

void customBall::update(){
    
    float noiseX = ofNoise(ofGetElapsedTimef());
    float noiseY = ofNoise(ofGetElapsedTimef()+yOffset);
    
    pos.x = ofMap(noiseX, 0, 1, 0, ofGetWidth());
    pos.y = ofMap(noiseY, 0, 1, 0, ofGetHeight());
}

void customBall::draw(float _x){
    ofCircle(pos.x + _x, pos.y, 10);
    
}