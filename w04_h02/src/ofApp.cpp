#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    mover.setup(50, 500, 1.0);
    follower.setup(ofGetWidth()/2, ofGetHeight()/2, 1.0);
    gravity.set(0,0.5);
    spring = 0.05;
    
    
    for (int i = 0; i< 20; i++){
        
        Mover myFollowers;
        myFollowers.setup(ofGetWidth()/2 + ofRandom(-100,100), ofGetHeight()/2+ ofRandom(-100,100),1.0);
        followerList.push_back(myFollowers);
    
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    mover.resetForces();
    // windStrenth = ofMap(ofNoise(ofGetElapsedTimef()*0.1), 0, 1, -1, 1);
    //wind.set(windStrenth,0.4);
    // ofLog(OF_LOG_NOTICE, "wind force is " + ofToString(windStrenth));
    
    //  mover.applyForce(wind);
    
    
    for (int i = 0; i< 20; i++){
        
        
        for (int k = 0; k< 20; k++){
            ofVec2f dis = followerList[i].pos - followerList[k].pos;
            float minDis = followerList[i].rad*2;
            
            
            
            if (dis.length() < minDis) {
                
                float angle = atan2(dis.y, dis.x);
                ofVec2f targetDis = ofVec2f(dis.x+cos(angle)*minDis,dis.y+cos(angle)*minDis);
                
                
               
                
                
                
                followerList[i].pos = followerList[i].pos*0.9 + (targetDis+followerList[i].pos)*0.1;
            }
            
        }
        
        if(followerList[i].vel.x > 3){followerList[i].vel.x = 3;}
        if(followerList[i].vel.y > 3){followerList[i].vel.y = 3;}
        
        followerList[i].resetForces();
        mag.set(followerList[i].pos.x - ofGetMouseX(), followerList[i].pos.y - ofGetMouseY());
        mag.normalize();
        mag.scale(0.2);
        mag = -mag;
        //ofVec2f dis.set();
        
        followerList[i].collide();
        followerList[i].applyForce(mag);
        followerList[i].update();
        
    }

    
    
    
    
    
    
    
    
   /*
    if(follower.vel.x > 3){follower.vel.x = 3;}
    if(follower.vel.y > 3){follower.vel.y = 3;}
    
    
    
    follower.resetForces();
    mag.set(follower.pos.x - ofGetMouseX(), follower.pos.y - ofGetMouseY());
    mag.normalize();
    mag.scale(0.2);
    mag = -mag;
    follower.applyForce(mag);
    follower.update();
    
    */
    
    
    mover.applyForce(gravity*mover.mass);
    
    ofLog(OF_LOG_NOTICE, "wind force is " + ofToString(mag.x) + "  "+ ofToString(mag.y));
    mouseVel.set((ofGetMouseX()-ofGetPreviousMouseX())/5,(ofGetMouseY()-ofGetPreviousMouseY())/5);
    mover.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i< 20; i++){
        
        
        followerList[i].draw();
        
        
    }

    
    
    //mover.draw();
    //follower.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    
    mover.resetForces();
    mover.resetVel();
    mover.setup(ofGetMouseX(), ofGetMouseY(), 1.0);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    mover.setup(ofGetMouseX(), ofGetMouseY(), 1.0);
    //mover.resetForces();
    //mover.resetVel();
    
    
    mover.applyForce(mouseVel);
    
    
    
    mover.update();
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
