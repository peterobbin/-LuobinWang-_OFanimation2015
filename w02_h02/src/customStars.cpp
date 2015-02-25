//
//  customStars.cpp
//  w02_h02
//
//  Created by peterobbin on 2/17/15.
//
//

#include "customStars.h"



void customStars::setup(ofVec3f _vertex){
    mesh.setMode(OF_PRIMITIVE_POINTS);
    vertex = _vertex;
    
    
    
    mesh.addVertex(_vertex);
    //mesh.addVertex(ofVec3f(30,40,0));
    
    
    
   
    
}




void customStars::update(){
    
    
    
}


void customStars::draw(){
    mesh.draw();

}