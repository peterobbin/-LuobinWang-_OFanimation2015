#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(false);
    
    flowField.setup(ofGetWidth(), ofGetHeight(), 20.0);
    //flowField.setRandom(2.0);
    
    
    for (int i = 0; i < 5000; i++) {
        Particle myParticle;
        myParticle.setup();
        particles.push_back(myParticle);
    }
    
    bDrawField = false;
    bDrawBackground = true;

    
    
    
    ofSetVerticalSync(true);
    ofSetCircleResolution(80);
    
    // 0 output channels,
    // 2 input channels
    // 44100 samples per second
    // 256 samples per buffer
    // 4 num buffers (latency)
    
    soundStream.listDevices();
    
    //if you want to set a different device id
    //soundStream.setDeviceID(0); //bear in mind the device id corresponds to all audio devices, including  input-only and output-only devices.
    
    int bufferSize = 256;
    
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    
    bufferCounter	= 0;
    drawCounter		= 0;
    smoothedVol     = 0.0;
    scaledVol		= 0.0;
    
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    passTime = ofGetElapsedTimef();
    flowField.setNoise(passTime);
    flowField.setMouse(ofGetMouseX(), ofGetMouseY());
    mouseX = ofGetMouseX();
    mouseY = ofGetMouseY();
    
    for (int i = 0; i < particles.size(); i++){
        
        particles[i].resetForces();
        
        //get the force of the flowfield at the particle position
        ofVec2f frc = flowField.getForceAt(particles[i].pos.x, particles[i].pos.y);
        
        //apply force to the particle
        particles[i].applyForce(frc);
        particles[i].applyDampingForce(0.01);
        particles[i].update();
        
    }
    
    
    //lets scale the vol up to a 0-1 range
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    
    //lets record the volume into an array
    volHistory.push_back( scaledVol );
    
    //if we are bigger the the size we want to record - lets drop the oldest value
    if( volHistory.size() >= 400 ){
        volHistory.erase(volHistory.begin(), volHistory.begin()+1);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255, 0, 0);
    
    if(bDrawBackground) ofBackground(0);
    if (bDrawField) flowField.draw();
    
//    for (unsigned int i = 0; i < left.size(); i++){
//        left[i]
//    
//    
//    }
    
    ofLog(OF_LOG_NOTICE, ofToString(left.size()) );
    ofLog(OF_LOG_NOTICE, ofToString(particles.size()) );
    
    ofSetColor(255);
    for (int i = 0; i < particles.size(); i++){
         ofFill();
        int indexV = ceil(i/20);
        float soundV = left[indexV];
        particles[i].draw(mouseX, mouseY, soundV);
    }
    
 
    
    
    
    stringstream buf;
    
    buf << "Press 'f' to toggle flowfield draw" << endl <<
    "Press 'b' to toggle background draw" << endl;
    
    ofDrawBitmapString(buf.str(), 20, 20);

    
    
    
    ofNoFill();
    
    // draw the left channel:
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(32, 170, 0);
    
    ofSetColor(225);
    ofDrawBitmapString("Channel Wave", 4, 18);
    
    ofSetLineWidth(1);
    //ofRect(0, 0, 512, 200);
    
    ofSetColor(245, 58, 135);
    ofSetLineWidth(1);
    
    ofBeginShape();
    for (unsigned int i = 0; i < left.size(); i++){
        ofVertex(i*2, 100 -left[i]*180.0f);
    }
    ofEndShape(false);
    
    ofPopMatrix();
    ofPopStyle();

}
//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    
    // samples are "interleaved"
    int numCounted = 0;
    
    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (int i = 0; i < bufferSize; i++){
        left[i]		= input[i*2]*0.5;
        right[i]	= input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    
    //this is how we get the mean of rms :)
    curVol /= (float)numCounted;
    
    // this is how we get the root of rms :)
    curVol = sqrt( curVol );
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    
    bufferCounter++;
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key) {
        case 'f' | 'F':
            bDrawField = !bDrawField;
            break;
        case 'b' | 'B' :
            bDrawBackground = !bDrawBackground;
            break;
            
        default:
            break;
    }

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
