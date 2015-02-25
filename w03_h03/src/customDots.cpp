//
//  customDots.cpp
//  w03_h03
//
//  Created by peterobbin on 2/24/15.
//
//

#include "customDots.h"

void customDots::setup(){


}

void customDots::update(ofVec2f _pos, float _rad){
    pos = _pos;
    rad = _rad;

}


void customDots::draw(){
    
    

    ofCircle(pos, rad);


}