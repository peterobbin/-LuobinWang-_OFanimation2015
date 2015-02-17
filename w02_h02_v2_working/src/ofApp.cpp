#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    mesh.setMode(OF_PRIMITIVE_POINTS);
    testMesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    //ofSetBackgroundAuto(false);
    
//    ofVec3f top(100.0, 50.0, 0.0);
//    ofVec3f left(50.0, 150.0, 0.0);
//    ofVec3f right(150.0, 150.0, 0.0);
//    
//    mesh.addVertex(top);
//    mesh.addVertex(left);
//    mesh.addVertex(right);
    
    for(int i = 0; i < NUM_STARS; i++){
        // newMesh[i].setMode(OF_PRIMITIVE_POINTS);
        stars[i] = ofVec3f(ofRandom(ofGetWidth()),ofRandom(ofGetHeight(),0));
        //scatter[i] = ofVec3f(ofRandom(-5,5),ofRandom(-5,5));
        
        // testMesh.addVertex(stars[i]+scatter[i]);
         //testMesh.addIndex(i);
        //testMesh.addIndex(i+1);
        //testMesh.addIndex(i+2);
         testMesh.addVertex(stars[i]);
        
    }
    
    
    
    
    
    
    
    

    
    
}

//--------------------------------------------------------------
void ofApp::update(){
 
    
    lastime = xtime;
    xtime = xtime + 0.0001;
 
    int skip = 100;
    for(int y = 0; y < ofGetHeight(); y += skip) {
        for(int x = 0; x < ofGetWidth(); x += skip) {
            ofColor cur = (ofMap(ofNoise(lastime), 0, 1, -50, 50),50);
            if(cur.a > 0) {
               
               // float z = ofMap(cur.a, 0, 255, -300, 300);
               // cur.a = 255;
               // mesh.addcolor
                mesh.addColor(ofMap(ofNoise(lastime), 0, 1, 0, 255));
                ofVec3f clearpos(x+ ofRandom(50), y + ofRandom(50) , ofMap(ofNoise(lastime), 0, 1, -200, 200));
              //  mesh.addColor(100);
                
                
                
                
              //  ofVec3f pos(x+ofMap(ofNoise(xtime), 0, 1, 50, 50), y , ofMap(ofNoise(xtime), 0, 1, -200, 200));
                
                
                
                
                mesh.addVertex(clearpos);
                
            }
        }
    }
    
    
    for(int y = 0; y < ofGetHeight(); y += skip) {
        for(int x = 0; x < ofGetWidth(); x += skip) {
            ofColor cur = (50,50);
            if(cur.a > 0) {
                // the alpha value encodes depth, let's remap it to a good depth range
                // float z = ofMap(cur.a, 0, 255, -300, 300);
                // cur.a = 255;
              //  mesh.addColor(0);
              //  ofVec3f clearpos(x+ofMap(ofNoise(lastime), 0, 1, -50, 50), y , ofMap(ofNoise(lastime), 0, 1, -200, 200));
                mesh.addColor(00);
                
                
                
                
                ofVec3f pos(x+ofMap(ofNoise(xtime), 0, 1, 50, 50), y , ofMap(ofNoise(xtime), 0, 1, -200, 200));
                
                
                
                
                mesh.addVertex(pos);
                
            }
        }
    }

    
    
    
    
    
    
    
   
    for(int i = 0; i < NUM_STARS; i++){
        stars[i] = stars[i] + ofVec3f(1,1,0);
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
   // ofSetColor(255);
   // ofSetColor(100);
   // testMesh.draw();
   // mesh.draw();
    
   cam.begin();
    
   // ofRect(0, 0, 500, 500);
    ofBackground(0);
    ofScale(2, -2, 2);
    ofRotateY(45);
    ofTranslate(-ofGetWidth() / 2, -ofGetHeight() / 2);
    mesh.draw();
    cam.end();
    
   // ofRect(0, 0, 0, 500, 500);
    
    
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
