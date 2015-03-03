//
//  Mover.cpp
//  w04_h01
//
//  Created by peterobbin on 3/2/15.
//
//

#include "Mover.h"

void Mover::setup(float x, float y, float _mass){
    pos.set(x,y);
    mass = _mass;
}

void Mover::resetForces(){
    acc = acc*0;
}

void Mover::resetVel(){
    vel = vel*0;
}


void Mover::applyForce(ofVec2f force){
    acc = acc + force/mass;
}



void Mover::update(){
    vel = vel + acc;
    pos = pos + vel;
    
    if (pos.x<0) {
        pos.x=0;
        vel.x*=-1;
        
    }
    
    if (pos.x>ofGetWidth()) {
        pos.x=ofGetWidth();
        vel.x*=-1;
        
        
    }
    
    if (pos.y<0) {
        pos.y=0;
        vel.y*=-1;
        
    }
    
    if (pos.y>ofGetHeight()) {
        pos.y=ofGetHeight();
        vel.y*=-1;
        
        
    }

}



void Mover::draw(){
    ofCircle(pos, 10*mass);
}