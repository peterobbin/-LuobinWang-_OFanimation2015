//
//  Particle.h
//  03_flowField
//
//  Created by Bernardo Santos Schorr on 3/31/15.
//
//

#pragma once
#include "ofMain.h"

class Particle {
public:
    
    void setup();
    
    void resetForces();
    void applyForce(ofVec3f force);
    void applyDampingForce(float damping);
    
    void update();
    void draw(float _mouseX, float _mouseY);
    
    ofVec3f pos, vel, acc;
    
    
    
};
