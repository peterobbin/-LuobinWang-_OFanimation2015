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
    
    pct = _pct;
    currentPos = currentPos * (1 - pct) + _mouse * pct;
    
}

void customCircle::draw(float _r, float _g, float _b) {
    r = _r;
    g = _g;
    b = _b;
    ofSetColor(r,g,b);
    ofCircle(currentPos, 50);
    }
