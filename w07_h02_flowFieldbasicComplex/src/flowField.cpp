//
//  flowField.cpp
//  03_flowField
//
//  Created by Bernardo Santos Schorr on 3/31/15.
//
//

#include "flowField.h"

flowField::flowField() {
    
}

void flowField::setup(float w, float h, float res) {
    
    screenWidth = w;
    screenHeight = h;
    resolution = res;
    
    //because 1024/20 == 51.2. But we want 52 flows, so we force it to the ceiling of this integer.
    fieldWidth = ceil (screenWidth /resolution);
    fieldHeight = ceil (screenHeight /resolution);
    
    totalFlows = fieldWidth * fieldHeight;
    
    //putting all the flows into the same vector
    for (int i = 0; i < totalFlows; i++) {
        ofVec2f flow;
        flow.set(0.0, 0.0);
        field.push_back(flow);
    }
    
    for (int i = 0; i < totalFlows; i++) {
        ofVec2f mouseForce;
        mouseForce.set(0.0, 0.0);
        mouseF.push_back(mouseForce);
    }

}

void flowField::setRandom(float scale) {
    
    for (int i = 0; i < totalFlows; i++) {
        float x = ofRandom(-1, 1) * scale;
        float y = ofRandom(-1, 1) * scale;
        field[i].set(x, y);
    }
    
}

void flowField::setNoise(float _passTime) {
    for (int y = 0; y < fieldHeight; y++) {
        for (int x = 0; x < fieldWidth; x++) {
            //finding the position of the flow in the vector container
            int index = (y * fieldWidth) + x;
            
            //setting a perlin noise value according to position in 2d space
            float noise = ofNoise(x*0.1+_passTime, y *0.1+_passTime);
            
            //mapping the noise value to a rotation in radians
            noise = ofMap(noise, 0, 1, 0, TWO_PI);
            
            
            //setting the flow x and y to be the sin and cos of that angle times 2.0
            field[index].set(ofVec2f(cos(noise) * 2.0, sin(noise) * 2.0));
            
        }
    }
}

void flowField::setMouse(float _mouseX, float _mouseY) {
    for (int y = 0; y < fieldHeight; y++) {
        for (int x = 0; x < fieldWidth; x++) {
            //finding the position of the flow in the vector container
            int index = (y * fieldWidth) + x;
            
            //setting a perlin noise value according to position in 2d space
            float noise = ofNoise(_mouseX*0.1, _mouseY*0.1);
            
            //mapping the noise value to a rotation in radians
            noise = ofMap(noise, 0, 1, 0, TWO_PI);
            
            
            float x0 = x * resolution;
            float y0 = y * resolution;
            
            dissMouse = ofVec2f(_mouseX - x0, _mouseY - y0);
            
            
            
            //setting the flow x and y to be the sin and cos of that angle times 2.0
//            mouseF[index].set(ofVec2f(cos(noise) * 2.0, sin(noise) * 2.0));
            if (dissMouse.length() < 100) {
                 mouseF[index].set(ofVec2f((_mouseX - x0)*0.004, (_mouseY - y0)*0.004));
            }else {mouseF[index].set(0,0);}
            
            
        }
    }
}

void flowField::draw() {
    for (int y = 0; y < fieldHeight; y++) {
        for (int x = 0; x < fieldWidth; x++) {
            
            //finding the position of the flow in the vector container
            int index = (y * fieldWidth) + x;
            
            //converting X and Y to position in pixels. This will be where the flow will start drawing.
            float x0 = x * resolution;
            float y0 = y * resolution;
            
            //converting the flow X and Y values to position in pixels. This is the tip of the line.
            float x1 = x0 + (field[index].x * 5) + (mouseF[index].x * 50);
            float y1 = y0 + (field[index].y * 5) + (mouseF[index].y * 50);
            
            
        
            //draw a line
            ofLine (x0, y0, x1, y1);
            
            //draw a circle to know where the flow starts
            ofCircle(x0, y0, 2);
            
        }
    }
}

ofVec2f flowField::getForceAt(float x, float y) {
    
    //create a vector force to apply to the particle and set it to zero.
    ofVec2f frc;
    frc.set(0, 0);
    
    //make sure the particle is within the flow. If not, just return force as zero. When you return from a function, nothing else after the return line is executed.
    if (x < 0 || x > screenWidth || y < 0 || y > screenHeight) {
        return frc;
    }
    
    //convert the X and Y position from pixels to the size in number of flows.
    int xIndex = ceil (ofMap (x, 0, ofGetWidth(), 0, fieldWidth));
    float yIndex = ceil (ofMap (y, 0, ofGetHeight(), 0, fieldHeight));
    
    //finding the position of the flow in the vector container
    int index = (yIndex * fieldWidth) + xIndex;
    
    //set the force from the flow. Scale it down otherwise it will be too strong.
 
            
    
    
                
                
                
              
                
                
    frc.set(field[index].x * 0.01 + mouseF[index].x * 0.1, field[index].y * 0.01 + mouseF[index].y * 0.1);
                
    
                
    

    
    
    
    
    
    return frc;
    
}














