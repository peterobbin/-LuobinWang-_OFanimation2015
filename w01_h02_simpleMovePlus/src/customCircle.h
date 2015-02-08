
//
//  customCircle.h
//  w01_h01_simepleMove
//
//  Created by peterobbin on 2/8/15.
//
//

#pragma once
#include "ofMain.h"

class customCircle {
public:
    void setup(ofVec2f _initPos, ofVec2f _finalPos);
    void update(float _pct);
    void draw(float _rad);
    void setNewPos(ofVec2f _newPos);
    void easeIn(float _pct);
    void radiusAlt(float _rad);
    void easeOut(float _pct);
    
    
private:
    ofVec2f initPos, finalPos, currentPos;
    float pct;
    float rad;
    
    
};