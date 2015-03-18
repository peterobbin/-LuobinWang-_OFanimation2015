#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    
    //Set buffer size and fill it by zeros
    buffer.resize( N, 0.0 );
    
    //Start the sound output in stereo (2 channels)
    //and sound input in mono (1 channel)
    soundStream.setup( this, 2, 1, sampleRate, 256, 4 );
    

    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);
 
    for (int y=0; y<H; y++) {
        for (int x=0; x<W; x++) {
            pos = ofVec3f((x - W/2) * 200, (y - H/2) * 200, 0 );
            mesh.addVertex(pos);
            mesh.addColor(ofFloatColor( 0, 0, 0 ) );
            
            
            
        }
    }
    
    lasTime = 0;
    cuSec = ofGetSec();
    pC.set(0);
    c.set(0);
    p.set(ofGetWidth()/2, ofGetHeight()/2);
     bgColor = 0;
    
    
    for (int y=0; y<H-1; y++) {
        for (int x=0; x<W-1; x++) {
    
            
            
      
            
            mesh.addIndex(x+y*W);
            mesh.addIndex((x+1)+y*W);
            mesh.addIndex(x+(y+1)*W);
    
            mesh.addIndex((x+1)+y*W);
            mesh.addIndex((x+1)+(y+1)*W);
            mesh.addIndex(x+(y+1)*W);
    
     }
    }
    
    //Set up triangles' indices
//    for (int y=0; y<H-1; y++) {
//        for (int x=0; x<W-1; x++) {
//            int i1 = x + W * y;
//            int i2 = x+1 + W * y;
//            int i3 = x + W * (y+1);
//            int i4 = x+1 + W * (y+1);
//            mesh.addTriangle( i1, i2, i3 );
//            mesh.addTriangle( i2, i4, i3 );
//        }
//    }
    //setNormals( mesh );		//Set normals
    light.enable();			//Enable lighting
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
     ctime = ofGetElapsedTimef();	//Get time
      float diff = lasTime - ctime;
    lasTime = ctime;
    
    
    
    sec = ofGetSec();
    min = ofGetMin();
    hour = ofGetHour();
    ofColor cDiff = c - pC;
    
    if (sec != cuSec) {
        c.set(ofNoise(ctime/10+99999)*255,ofNoise(ctime/10+293)*255,ofNoise(ctime/10-19248)*255);
        pC = c;
    }
    
    
    
    if (abs(sec- cuSec)>0.1&&abs(sec- cuSec)<1.2) {
        cuSec = cuSec +0.1;
        pC = pC*0.95 + cDiff*0.05;
        
        
    }else if(abs(sec- cuSec)<0.1){
        cuSec = sec;
        
    }else if(abs(sec-cuSec)>2){
        cuSec = sec;
       
    }
    
//    if (  sec == 0 ) {
//        cuSec = sec;
//    }
//    
    
    
//    if (0<ofGetMouseX()<ofGetWidth() || 0<ofGetMouseY()<ofGetHeight()) {
    
    
        ofVec2f followPoint = ofVec2f(ofGetMouseX(), ofGetMouseY());
    
        if(ofGetMouseX()>ofGetWidth() || ofGetMouseX() < 0 ||ofGetMouseY() < 0 || ofGetMouseY() >ofGetHeight()){
        
        followPoint.set(ofGetWidth()/2,ofGetHeight()/2);
        }
    
        ofVec2f pDiff = ofVec2f(followPoint.x-p.x,followPoint.y-p.y);
        ofVec2f p2Diff = ofVec2f(followPoint.x-p2.x,followPoint.y-p2.y);
        ofVec2f p3Diff = ofVec2f(followPoint.x-p3.x,followPoint.y-p3.y);
        
        p = p * 0.95 + (p+pDiff*2)*0.05;
        p2 = p2 * 0.94 + (p2+p2Diff*4)*0.06;
        p3 = p3 * 0.93 + (p3+p3Diff*8)*0.07;
    
    
  
    
    
   
    
    if ( hour < 18 || hour >7 ) {
        if (bgColor < 255) {
            bgColor++;
        }
    }
    if ( hour < 7 || hour >18 ) {
        if (bgColor > 0) {
            bgColor--;
        }
    }
    
  //  ofLog(OF_LOG_NOTICE, "bgcolor" + ofToString(buffer[500]));
    
    
    
    
    
    //ofLog(OF_LOG_NOTICE, "time sec" + ofToString(sec));
    
   // cuSec = cuSec*0.95 + (sec - cuSec)*0.05;
    ofLog(OF_LOG_NOTICE, "diff" + ofToString(abs(sec- cuSec)));
    
    

  
    
    //Change vertices
    for (int y=0; y<H; y++) {
        for (int x=0; x<W; x++) {
            
            
            int k = float(x) * N / W;   //Convert x to buffer's position
            ofLine( x, 100, x, 100 - buffer[k] * 100 );
            
            int i = x + W * y;			//Vertex index
            ofPoint p = mesh.getVertex( i );
            
            //Get Perlin noise value
            float value = ofNoise( x * 0.4, y * 0.4, ctime/5);
            
            
            
            
            float compareV =100 - buffer[k] * 100;
            if (compareV > 102) {
                p.z = p.z - 0.001;
            }
            
            if (compareV < 99) {
                p.z = p.z + 0.001;
            }
            
            p.z = value * 300 -(100 - buffer[k] * 100 ) + 100;
            //ofLog(OF_LOG_NOTICE, ofToString(100-buffer[1]*100));
           
            mesh.setVertex( i, p );
            
            //Change color of vertex
            float reverseValue = ofMap(value, 0, 1, 1, 0);
            mesh.setColor( i, ofColor( value*255, (reverseValue*100+50)*compareV/100, (reverseValue*200+55)/(compareV/100) ) );
        }
    }
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    ofEnableDepthTest();
    
   
    
    
    
    ofBackground(bgColor);
    
    ofPushMatrix();
    
       ofTranslate( ofGetWidth()/2, ofGetHeight(), 0 );
    
   
    float time = ofGetElapsedTimef();
    float angle = time * 20;
      ofRotate( 70, 1, 0, 0 );
  
 
    mesh.draw();
    
    ofPopMatrix();
    
    
    
    
    
    ofPath curve;
    
    curve.arc(        p, 300, 300, cuSec*6+10-90, cuSec*6-90 );
    curve.arcNegative(p, 250, 250, cuSec*6-90, cuSec*6+10-90);
    curve.close();
    curve.setArcResolution(60);
    
    curve.setFillColor(c);
    curve.setFilled(true);
    curve.draw();
    
    ofPath curve2;
        curve2.arc(        p2, 200, 200, min*6+10-90, min*6-90 );
    curve2.arcNegative(p2, 180, 180, min*6-90, min*6+10-90);
    curve2.close();
    curve2.setArcResolution(60);
    ofColor c2(255, 255,255);
    curve2.setFillColor(c2);
    curve2.setFilled(true);
    curve2.draw();
    
    
    ofPath curve3;
       curve3.arc(        p3, 150, 150, hour*30+10-90, hour*30-90 );
    curve3.arcNegative(p3, 140, 140, hour*30-90, hour*30+10-90);
    curve3.close();
    curve3.setArcResolution(60);
    ofColor c3(0, 255,255);
    curve3.setFillColor(c3);
    curve3.setFilled(true);
    curve3.draw();
    
    
    int w = 1024;	//Width of the sound visualization picture
    
  

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

//--------------------------------------------------------------
//Universal function which sets normals for the triangle mesh//mastering oF
void setNormals( ofMesh &mesh ){
    
    //The number of the vertices
    int nV = mesh.getNumVertices();
    
    //The number of the triangles
    int nT = mesh.getNumIndices() / 3;
    
    vector<ofPoint> norm( nV ); //Array for the normals
    
    //Scan all the triangles. For each triangle add its
    //normal to norm's vectors of triangle's vertices
    for (int t=0; t<nT; t++) {
        
        //Get indices of the triangle t
        int i1 = mesh.getIndex( 3 * t );
        int i2 = mesh.getIndex( 3 * t + 1 );
        int i3 = mesh.getIndex( 3 * t + 2 );
        
        //Get vertices of the triangle
        const ofPoint &v1 = mesh.getVertex( i1 );
        const ofPoint &v2 = mesh.getVertex( i2 );
        const ofPoint &v3 = mesh.getVertex( i3 );
        
        //Compute the triangle's normal
        ofPoint dir = ( (v2 - v1).crossed( v3 - v1 ) ).normalized();
        
        //Accumulate it to norm array for i1, i2, i3
        norm[ i1 ] += dir;
        norm[ i2 ] += dir;
        norm[ i3 ] += dir;
    }
    
    //Normalize the normal's length
    for (int i=0; i<nV; i++) {
        norm[i].normalize();
    }
    
    //Set the normals to mesh
    mesh.clearNormals();
    mesh.addNormals( norm );
}

//--------------------------------------------------------------
//--------------------------------------------------------------
//Audio input
void ofApp::audioReceived(
                          float *input, int bufferSize, int nChannels )
{
    //If recording is enabled by the user,
    //then store received data
    if ( recordingEnabled ) {
        for (int i=0; i<bufferSize; i++) {
            buffer[ recPos ] = input[i];
            recPos++;
            //When the end of buffer is reached, recPos sets
            //to 0, so we record sound in a loop
            recPos %= N;
        }
    }
}

//--------------------------------------------------------------
//Audio output
void ofApp::audioOut(
                     float *output, int bufferSize, int nChannels)
{
    //If playing is enabled by the user, then do output sound
    if ( playingEnabled ) {
        for (int i=0; i<bufferSize; i++) {
            output[ 2*i ] = output[ 2*i+1 ]
            = buffer[ playPos ] * volume;
            playPos++;
            //When the end of buffer is reached, playPos sets
            //to 0, so we hear looped sound
            playPos %= N;
        }
    }
}


