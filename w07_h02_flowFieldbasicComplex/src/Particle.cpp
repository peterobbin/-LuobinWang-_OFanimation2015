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
}

void Particle::resetForces() {
    acc *= 0;
}

void Particle::applyForce(ofVec2f force) {
    acc += force;
}

void Particle::applyDampingForce(float damping) {
    acc -= vel.getNormalized() * damping;
}

void Particle::update() {
    vel += acc;
    pos += vel;
    
}

void Particle::draw(float _mouseX, float _mouseY, float _soundV) {
    float size = vel.length();
    ofVec2f mousePos = ofVec2f(_mouseX, _mouseY);
    float diff = abs((pos - mousePos).length());
    if (diff < ofNoise(ofGetElapsedTimef()/10)*150) {
        //ofSetLineWidth(ofNoise(ofGetElapsedTimef())/10);
       // ofSetLineWidth(0.1);
        //glLineWidth(0.1);
        ofSetColor(255, 255, 255, diff/3);
        ofFill();
        ofLine(pos, mousePos);
        ofSetColor(255);
    }
    
    
    ofCircle(pos, size*_soundV*100);
}
