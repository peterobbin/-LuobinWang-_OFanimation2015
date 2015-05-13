#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    ofBackground(0);
    music.loadSound("wantyougone.mp3");
    mesh.setMode(OF_PRIMITIVE_POINTS);
    width =50;
    height = 50;
    res = 10;
    
    img.loadImage("gis.jpg");
    
    bUsePanCam = false;
    
    for(int y = -height/2; y<height/2;y++){
        for(int x = -width/2; x < width/2; x++){
            mesh.addVertex(ofPoint(x*res, y*res, 0));
            
            
            
        
        }
    }
    
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            mesh.addTexCoord(ofVec2f(x, height - y)*res);
        }
    }
    
    
    for (int y = 0; y < height - 1; y++) {
        for (int x = 0; x < width - 1  ; x++){
            mesh.addIndex(x + y*width);   //0
            mesh.addIndex((x+1) + y*width);    //1
            mesh.addIndex(x + (y+1)*width);      //50
            
            mesh.addIndex((x+1)+ y*width);        //1
            mesh.addIndex((x+1) + (y+1)*width);        //51
            mesh.addIndex(x + (y+1)*width);      //50`
        }
    }
    
    // we will bounce a circle using these variables:
    px = 300;
    py = 300;
    vx = 0;
    vy = 0;
    
    // the fft needs to be smoothed out, so we create an array of floats
    // for that purpose:
    fftSmoothed = new float[8192];
    for (int i = 0; i < 8192; i++){
        fftSmoothed[i] = 0;
    }
    
    nBandsToGet = 4000;
    music.play();
    
    //panCam.setPosition(500, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSoundUpdate();
    
    
    
    
    float * val = ofSoundGetSpectrum(nBandsToGet);		// request 128 values for fft
    for (int i = 0;i < nBandsToGet; i++){
        
        // let the smoothed calue sink to zero:
        fftSmoothed[i] *= 0.96f;
        
        // take the max, either the smoothed or the incoming:
        if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
        
        // mesh.setVertex(i, ofVec3f())
        
    }
    

    float time = ofGetElapsedTimef() * 5;
    
    for(int y = 0; y < height; y ++){
        for (int x = 0; x < width; x++) {
            int index = (y * width) + x;
            ofVec3f pos = mesh.getVertex(index);
            pos.z = ofNoise((x+time)*0.05, (y+time)*0.05) * 75.0;
           // cout <<index <<endl;
            int shiftindex = ofMap(index, 0, 3000, 0, 128);
            //cout << shiftindex << endl;
            
           // mesh.setVertex(index, pos );
           
        }
    }
    
    
    //pancam
    
    float radius = 300.0;
    ofVec3f center = ofVec3f(0,0,0);
    float x = cos(ofGetElapsedTimef()*0.5)*radius;
    float y = sin(ofGetElapsedTimef()*0.5)*radius;
    
    
    panCam.setPosition(x, y, 200);
    
    panCam.lookAt(center, ofVec3f(0,0,1));
    
   
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    
    
    //img.draw(0, 0);
    
    
    if(bUsePanCam == true){
        panCam.begin();
    }else{
        easyCam.begin();
    }

//    easyCam.draw();
//    panCam.draw();
    //img.bind();
//    mesh.drawWireframe();
    mesh.draw();
   // img.unbind();
    
    if(bUsePanCam == true){
        panCam.end();
    }else{
        easyCam.end();
    }
    
    
    
    float width = (float)(5*128) / nBandsToGet;
    
    
    for (int i = 0;i < nBandsToGet; i++){
        // (we use negative height here, because we want to flip them
        // because the top corner is 0,0)
       
        ofVec3f meshPos = mesh.getVertex(i);
       // cout<< fftSmoothed[i]*200<<endl;
        meshPos.z = fftSmoothed[i]*200;
        
        mesh.setVertex(i, meshPos);
        
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    bUsePanCam = !bUsePanCam;
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
