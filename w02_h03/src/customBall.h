//
//  customBall.h
//  w02_h03
//
//  Created by peterobbin on 2/17/15.
//
//

#pragma once

#include "ofMain.h"



class customBall{
public:
    
    void setup();
    void update();
    void draw(float _x);
    
    ofVec2f pos;
    float yOffset;
    
};
