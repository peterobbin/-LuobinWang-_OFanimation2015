//
//  cross.cpp
//  w03_h02
//
//  Created by peterobbin on 2/24/15.
//
//

#include "Cross.h"

void Cross::setup(){
    
    
}

void Cross::update(float _x, float _y, ofVec2f _pos, ofVec2f _innerPos, ofVec2f _diff, float _rad){
    
        
    ofVec2f newPos;
    newPos.set(_x, _y);
    pos = _pos;
    innerPos = _innerPos;
    
   // innerPos = innerPos * 0.98 + newPos*0.02;
    
    diff.set(abs(_diff.x), abs(_diff.y));
    ofLog(OF_LOG_NOTICE, "degree is" + ofToString(diff.x));

    rad = _rad * _diff.x * _diff.y/ 100000;
    
    
}

void Cross::draw(){
    

    
   
    
    
    ofCircle(pos, rad);
     ofLine(pos,innerPos+diff/10);
       

    
    

}

void Cross::drawLine(){
   

}