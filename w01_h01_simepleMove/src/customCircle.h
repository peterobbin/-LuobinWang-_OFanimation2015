
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
    void update(float pct);
    void draw();
    void setNewPos(ofVec2f _newPos);
private:
    ofVec2f initPos, finalPos, currentPos;
    float pct;
    


};