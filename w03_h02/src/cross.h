
//
//  Cross.h
//  w03_h02
//
//  Created by peterobbin on 2/24/15.
//
//

#pragma once
#include "ofMain.h"

class Cross{
public:
    
    void setup();
    void update(float _x, float _y, ofVec2f _pos, ofVec2f _innerPos, ofVec2f _diff, float rad);
    void draw();
    void drawLine();
    
private:
    ofVec2f pos, npos,innerPos,diff;
    float rad, x,y,rot;


};