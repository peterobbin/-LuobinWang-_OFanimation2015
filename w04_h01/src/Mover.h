//
//  Mover.h
//  w04_h01
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
    void resetVel();
    
    ofVec2f pos, vel, acc;
    float mass;

};

