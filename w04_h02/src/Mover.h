//
//  Mover.h
//  w04_h02
//
//  Created by peterobbin on 3/2/15.
//
//

#pragma once
#include "ofMain.h"

class Mover{
public:
    void setup(float x, float y, float _mass);
    void update();
    void resetForces();
    void applyForce(ofVec2f force);
    void draw();
    void collide();
    void resetVel();
    void drawLine();
    void updateLine(ofVec2f _lineStart, ofVec2f _lineEnd);
    
    ofVec2f pos, vel, acc, lineStart, lineEnd;
    
    float mass,rad;
    
};

