

//
//  particleSystem.h
//  w05_02_particles
//
//  Created by peterobbin on 3/3/15.
//
//

#pragma once
#include "ofMain.h"
#include "Particle.h"
#include "customCircle.h"

class ParticleSystem{
public:
    ParticleSystem(ofVec2f _pos);
    void update(ofVec2f _force);
    void draw();
    
    
    vector<Particle> particleList;
    vector<Particle> sparkList;
    vector<customCircle> circleList;
    ofVec2f pos;
    
    int pushing = 1;
};