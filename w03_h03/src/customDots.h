//
//  customDots.h
//  w03_h03
//
//  Created by peterobbin on 2/24/15.
//
//

#pragma once
#include "ofMain.h"

class customDots{
public:
    void setup();
    void update(ofVec2f _pos, float _rad);
    void draw();
    
private:
    ofVec2f pos;
    float rad;

    
    
};