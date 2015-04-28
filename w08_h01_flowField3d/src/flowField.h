//
//  flowField.h
//  03_flowField
//
//  Created by Bernardo Santos Schorr on 3/31/15.
//
//

#pragma once

#include "ofMain.h"

class flowField {
public:
    
    flowField();
    
    void setup(float w, float h, float z, float res);
    
    //functions to set patterns on the flow field
    void setRandom(float scale);
    void setNoise(float _passTime);
     void setMouse(float _mouseX, float _mouseY);
    
    //to be called from the particle, so it knows the force of the flow where it stands on
    ofVec3f getForceAt(float x, float y, float z);
    
    //drawing the field
    void draw();
    
    //container for all the flows
    vector<ofVec3f> field;
    vector<ofVec3f> mouseF;
    
    //The size of the field in pixels, e.g. 1024x768
    int screenWidth;
    int screenHeight;
    int screenZ;
    
    //The size of the field in number of flows, e.g. 52 x 40
    int fieldWidth;
    int fieldHeight;
    int fieldZ;
    
    //What is the area covered by each flow, e.g. 20x20 pixels
    float resolution;
    
    //Total number of flows in a field
    int totalFlows;
    
    ofVec3f dissMouse;
    
};
