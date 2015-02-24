//
//  customCircle.h
//  w03_h01
//
//  Created by peterobbin on 2/23/15.
//
//

#pragma once
#include "ofMain.h"

class customCircle{
public:
    void setup();
    void update(ofVec2f _pos, ofVec2f _nextPos, ofVec2f _pos2, ofVec2f _nextPos2, float _rad);
    void draw();
    void drawLine(float _thick);
   
   
    
private:
    ofVec2f pos, nextPos, pos2, nextPos2, offset, offset2;
    float rad, thick;
    
};
