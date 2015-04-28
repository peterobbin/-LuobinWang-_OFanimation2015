//
//  Particle.cpp
//  03_flowField
//
//  Created by Bernardo Santos Schorr on 3/31/15.
//
//

#include "Particle.h"

void Particle::setup() {
    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();
    pos.z = (ofRandomHeight()+ofRandomWidth())/2;
   // pos.z = 0;
}

void Particle::resetForces() {
    acc *= 0;
}

void Particle::applyForce(ofVec3f force) {
    acc += force;
    
    //ofLog(OF_LOG_NOTICE, ofToString(force));
}

void Particle::applyDampingForce(float damping) {
    acc -= vel.getNormalized() * damping;
}

void Particle::update() {
    vel += acc;
    pos += vel;
    
}

void Particle::draw(float _mouseX, float _mouseY) {
    float size = vel.length()*2;
    ofVec3f mousePos = ofVec3f(_mouseX, _mouseY, (_mouseX + _mouseY)/2);
    float diff = abs((pos - mousePos).length());
    if (diff < ofNoise(ofGetElapsedTimef()/10)*150) {
        //ofSetLineWidth(ofNoise(ofGetElapsedTimef())/10);
       // ofSetLineWidth(0.1);
        //glLineWidth(0.1);
        ofSetColor(255, 255, 255, diff/3);
        ofFill();
       // ofLine(pos, mousePos);
        
        
    }
    
    ofSetColor(255);
  
    ofCircle(pos, size);
}
