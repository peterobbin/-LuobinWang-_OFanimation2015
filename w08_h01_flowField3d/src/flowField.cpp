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

void flowField::setup(float w, float h, float z, float res) {
    
    screenWidth = w;
    screenHeight = h;
    resolution = res;
    
    //because 1024/20 == 51.2. But we want 52 flows, so we force it to the ceiling of this integer.
    fieldWidth = ceil (screenWidth /resolution);
    fieldHeight = ceil (screenHeight /resolution);
    fieldZ = ceil(((screenHeight+screenHeight)/2)/resolution);
    
    
    totalFlows = fieldWidth * fieldHeight * fieldZ;
    
    //putting all the flows into the same vector
    for (int i = 0; i < totalFlows; i++) {
        ofVec3f flow;
        flow.set(0.0, 0.0, 0.0);
        field.push_back(flow);
    }
    
    for (int i = 0; i < totalFlows; i++) {
        ofVec3f mouseForce;
        mouseForce.set(0.0, 0.0, 0.0);
        mouseF.push_back(mouseForce);
    }

}

void flowField::setRandom(float scale) {
    
    for (int i = 0; i < totalFlows; i++) {
        float x = ofRandom(-1, 1) * scale;
        float y = ofRandom(-1, 1) * scale;
        float z = ofRandom(-1, 1) * scale;

        field[i].set(x, y, z);
       
    }
    
}

void flowField::setNoise(float _passTime) {
    for (int z = 0; z< fieldZ; z++){
        for (int y = 0; y < fieldHeight; y++) {
            for (int x = 0; x < fieldWidth; x++) {
                //finding the position of the flow in the vector container
                int index = (z*fieldWidth*fieldHeight) + (y * fieldWidth) + x;
            
                //setting a perlin noise value according to position in 2d space
                float noise = ofNoise((x + z)*0.1+_passTime, (y + z) *0.1+_passTime);
            
                //mapping the noise value to a rotation in radians
                noise = ofMap(noise, 0, 1, 0, TWO_PI);
            
            
                //setting the flow x and y to be the sin and cos of that angle times 2.0
              
                field[index].set(ofVec3f(cos(noise) * 2.0, sin(noise) * 2.0, cos(noise) * 2.0));
            }
        }
    }
}

void flowField::setMouse(float _mouseX, float _mouseY) {
    for (int z = 0; z < fieldHeight; z++){
    for (int y = 0; y < fieldHeight; y++) {
        for (int x = 0; x < fieldWidth; x++) {
            //finding the position of the flow in the vector container
            int index = z* fieldHeight*fieldWidth + (y * fieldWidth) + x;
            
            //setting a perlin noise value according to position in 2d space
            float noise = ofNoise(_mouseX*0.1, _mouseY*0.1);
            
            //mapping the noise value to a rotation in radians
            noise = ofMap(noise, 0, 1, 0, TWO_PI);
            
            
            float x0 = x * resolution;
            float y0 = y * resolution;
            float z0 = z * resolution;
            
            dissMouse = ofVec3f(_mouseX - x0, _mouseY - y0, (_mouseX+_mouseY)/2 - z0);
            
            
            
            //setting the flow x and y to be the sin and cos of that angle times 2.0
//            mouseF[index].set(ofVec2f(cos(noise) * 2.0, sin(noise) * 2.0));
            if (dissMouse.length() < 100) {
                mouseF[index].set(ofVec3f((_mouseX - x0)*0.004, (_mouseY - y0)*0.004, ((_mouseX+_mouseY)/2 - z0) * 0.004));
                                  
                                   
                                   
            }else {mouseF[index].set(0,0,0);}
            
        }
        }
    }
}

void flowField::draw() {
    for (int z = 0; z < fieldHeight; z++) {
     
    for (int y = 0; y < fieldHeight; y++) {
        for (int x = 0; x < fieldWidth; x++) {
            
            //finding the position of the flow in the vector container
            int index = z*fieldHeight*fieldWidth + (y * fieldWidth) + x;
            
            //converting X and Y to position in pixels. This will be where the flow will start drawing.
            float x0 = x * resolution;
            float y0 = y * resolution;
            float z0 = z * resolution;
            
            //converting the flow X and Y values to position in pixels. This is the tip of the line.
            float x1 = x0 + (field[index].x * 5) + (mouseF[index].x * 50);
            float y1 = y0 + (field[index].y * 5) + (mouseF[index].y * 50);
            float z1 = z0 + (field[index].z * 5) + (mouseF[index].z * 50);
            
            
        
            //draw a line
            ofLine (x0, y0, z0, x1, y1, z1);
            
            //draw a circle to know where the flow starts
            ofCircle(x0, y0, z0, 2);
            
            }
        }
    }
}

ofVec3f flowField::getForceAt(float x, float y, float z) {
    
    //create a vector force to apply to the particle and set it to zero.
    ofVec3f frc;
    frc.set(0, 0, 0);
    
    //make sure the particle is within the flow. If not, just return force as zero. When you return from a function, nothing else after the return line is executed.
    if (x < 0 || x > screenWidth || y < 0 || y > screenHeight || z < 0 || z > (screenHeight +screenWidth)/2) {
        return frc;
    }
    
    //convert the X and Y position from pixels to the size in number of flows.
    float xIndex = ceil (ofMap (x, 0, ofGetWidth(), 0, fieldWidth));
    float yIndex = ceil (ofMap (y, 0, ofGetHeight(), 0, fieldHeight));
    float zIndex = ceil (ofMap (z, 0, (ofGetHeight()+ofGetWidth())/2, 0, fieldZ));
    
    //finding the position of the flow in the vector container
    int index = zIndex*fieldHeight*fieldWidth + (yIndex * fieldWidth) + xIndex;
   // ofLog(OF_LOG_NOTICE, ofToString(index));
    
    //set the force from the flow. Scale it down otherwise it will be too strong.
 
            
    
    
                
    
     //frc.set(field[index].x * 0.01 , field[index].y * 0.01 , field[index].z * 0.01 );
    frc.set(field[index].x * 0.01 + mouseF[index].x * 0.1, field[index].y * 0.01 + mouseF[index].y * 0.1, field[index].z * 0.01 + mouseF[index].z * 0.1);

    
                
    
                
    
                
    

    
    
    
    
    
    return frc;
    
}














