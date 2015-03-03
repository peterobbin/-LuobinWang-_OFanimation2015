//
//  customCircle.cpp
//  01_simpleClass
//
//  Created by Bernardo Santos Schorr on 1/31/15.
//
//

#include "customCircle.h"

customCircle::customCircle() {
    
}

void customCircle::setup(ofVec2f _initPos) {
    currentPos = _initPos;
}

void customCircle::update(ofVec2f _mouse, float _pct) {
    
    pace = (_mouse - currentPos)*0.05;
    pct = _pct;
    currentPos = currentPos * (1 - pct) + _mouse * pct;
    
}

void customCircle::draw(float _r, float _g, float _b, float _rad, float _num) {
    r = _r;
    g = _g;
    b = _b;
    rad = _rad * pace.x ;
    num = _num;
    ofSetColor(r,g,b);
    ofSetColor(30);
    ofDrawBitmapString(ofToString(_num), currentPos);
    ofSetColor(255);
    ofCircle(currentPos, rad);
    

    
    

}
