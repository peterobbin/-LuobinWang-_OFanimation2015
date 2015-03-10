//
//  particleSystem.cpp
//  w05_02_particles
//
//  Created by peterobbin on 3/3/15.
//
//

#include "particleSystem.h"



//--------------------------------------------------------------
ParticleSystem::ParticleSystem(ofVec2f _pos){
    ofBackground(0);
    pos.set(_pos);
    
    for(int i = 0; i < 100; i++){
        customCircle myCircle;
        myCircle.setup(ofVec2f(ofGetWidth()/2, ofGetHeight()));
        circleList.push_back(myCircle);
        
    }
    
    
}

//--------------------------------------------------------------
void ParticleSystem::update(ofVec2f _force){
    
    
    for(int i = 0; i < 100; i++){
        circleList[i].update(ofVec2f(ofGetMouseX(), ofGetMouseY()), 0.01*i);
        
//        if(i == 99 && circleList.size() > 0){
//            
//            circleList.clear();
//        }
        
        if( circleList.size() < 99 && circleList.size()>0  ){
            
            circleList.erase(circleList.begin()-i);
        }
        
    }
    
    
    
    
    
    for (int i = 0; i < 10; i++) {
          Particle particle(pos);
            if (pushing == 1){
                particleList.push_back(particle);
            }
            
            if (pushing == 0){
                //particleList.erase(particleList.begin());
            }
        
        
    }
    
    
    
    for (int i = 0; i < 3; i++) {
        Particle particle(pos);
        if (pushing == 1){
            sparkList.push_back(particle);
        }
        
        if (pushing == 0){
            sparkList.clear();
        }
        
        
    }
    
    
    
   // ofLog(OF_LOG_NOTICE,ofToString(pushing));
    
    for (int i = 0; i < particleList.size(); i++) {
        
     ofVec2f diff = ofVec2f(abs(particleList[i].pos.x - pos.x),abs(particleList[i].pos.y - pos.y));
            particleList[i].resetForces();
            particleList[i].applyForce(_force);
            particleList[i].update(ofMap(diff.length(), 0, 200, 4, 1));
        
       
        
        
        
        
        if (diff.length() >= ofRandom(200, 400)) {
            pushing = 0;
            
            if (particleList.size() > 0) {
                particleList.erase(particleList.begin()+i);

            }
           
        }
        
        
        
        
        
        
        
        
       
        
        
    
//        while (particleList.size() > 500){
//            pushing = 0;
//            particleList.erase(particleList.begin()+particleList.size()-i);
//            
//        }
    
    }
//    
//    ofLog(OF_LOG_NOTICE, ofToString(particleList.size()));
//    if (particleList.size()> 10) {
//        pushing = 0;
//    }
    
   
    
    
    
    
    
    cout << ofGetFrameRate() << endl;
}

//--------------------------------------------------------------
void ParticleSystem::draw(){
    
    for(int i = 0; i < 100; i++){
        circleList[i].draw(255, 255, 255, pushing);
        
    }
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].draw();
    }
}

//--------------------------------------------------------------