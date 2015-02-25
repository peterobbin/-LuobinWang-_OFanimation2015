//
//  customCircle.h
//  01_simpleClass
//
//  Created by Bernardo Santos Schorr on 1/31/15.
//
//

#pragma once
#include "ofMain.h"

class customCircle {
public:
    customCircle();
    void setup(ofVec2f _initPos);
    void update(ofVec2f _mouse, float _pct);
    void draw(float _r, float _g, float _b, float _rad, float _num);
    ofVec2f pace;
    
private:
    ofVec2f currentPos;
    float num;
    float pct;
    float r,g,b;
    float rad;
    
};
