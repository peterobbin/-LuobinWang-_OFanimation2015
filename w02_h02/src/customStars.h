//
//  customStars.h
//  w02_h02
//
//  Created by peterobbin on 2/17/15.
//
//

#pragma once
#include "ofMain.h"

class customStars {
public:
    void setup(ofVec3f _vertex);
    void update();
    void draw();
    
  //  ofVec3f pos;
    
private:
    ofMesh mesh;
    ofVec3f vertex;
    
    

};