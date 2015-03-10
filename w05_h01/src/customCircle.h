
//
//  customCircle.h
//  w05_h01
//
//  Created by peterobbin on 3/10/15.
//
//

#pragma once
#include "ofMain.h"

class customCircle {
public:
    customCircle();
    void setup(ofVec2f _initPos);
    void update(ofVec2f _mouse, float _pct);
    void draw(float _r, float _g, float _b, float _t);
    float pct;
     ofVec2f currentPos;
private:
   
    
    float r,g,b;
};
