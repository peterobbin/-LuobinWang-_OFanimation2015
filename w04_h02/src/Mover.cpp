//
//  Mover.cpp
//  w04_h02
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

void Mover::collide(){
    
    
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
    
    rad = 10*mass*(vel.length()/7);
    
}

void Mover::updateLine(ofVec2f _lineStart, ofVec2f _lineEnd){
    lineStart = _lineStart;
    lineEnd = _lineEnd;
}




void Mover::draw(){
    
    ofCircle(pos, rad);
}

void Mover::drawLine(){
    ofLine(lineStart, lineEnd);
}