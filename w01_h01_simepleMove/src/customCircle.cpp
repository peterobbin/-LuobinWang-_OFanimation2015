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

void customCircle::draw(){
    ofCircle(currentPos, 10);
    
}

void customCircle::setNewPos(ofVec2f _newPos){

    initPos = currentPos;
    finalPos = _newPos;
    

}