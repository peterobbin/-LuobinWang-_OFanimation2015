#include "ofApp.h"
using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    iSight.listDevices();
    iSight.setDeviceID(0);
    iSight.initGrabber(320 ,240);
    
    
    gui.setup();
    gui.add(notification.setup("instructions", ""));
    
    
    
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    float intensityThreshold = 180;
    
    int w = iSight.getWidth();
    int h = iSight.getHeight();
    
    
    
    for (int y = 0; y<h; y= y + 1) {
        for (int x = 0; x<w; x = x +
             1){
            
            
            ofVec3f pos(y*4,x*4,0);
            mesh.addVertex(pos);
            mesh.addColor(ofFloatColor(255,0,0));
            
            mesh.addIndex(x+y*w);
            //mesh.addIndex((x+1)+y*w);
            //mesh.addIndex(x+(y+1)*w);
            mesh.addIndex((x+1)+y*w);
            //mesh.addIndex((x+1)+(y+1)*w);
            //mesh.addIndex(x+(y+1)*w);
            
            offsets.push_back(ofVec3f(ofRandom(0,100000), ofRandom(0,100000), ofRandom(0,100000)));
            
        }
    }
    
    
    
    
    
    tracker.setup();
    tracker.setRescale(.5);
    
    
    
    
    
    cout << mesh.getNumVertices() <<endl;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    
    
    int numVerts = mesh.getNumVertices();
    
    ofVec2f noseBase = tracker.getImageFeature(ofxFaceTracker::NOSE_BASE).getCentroid2D();
    ofLog(OF_LOG_NOTICE) << "nosePosition " << noseBase.x;
    
    iSight.update();
    
    if (iSight.isFrameNew()){
        if(tracker.update(toCv(iSight))) {
            classifier.classify(tracker);
        }
      
    
    //diff calculate
        
        
        image.setFromPixels( iSight.getPixelsRef() );
        
        if ( grayImage.bAllocated ) {
            grayImagePrev = grayImage;
        }
        
        
        grayImage = image;	//Convert to grayscale image
        
        
        if ( grayImagePrev.bAllocated ) {
            
            diff.absDiff( grayImage, grayImagePrev );
            
            
            diffFloat = diff;
            diffFloat *= 5.0;
            
            //Update the accumulation buffer
            if ( !bufferFloat.bAllocated ) {
                
                bufferFloat = diffFloat;
            }
            else {
                //Slow damping the buffer to zero
                bufferFloat *= 0.85;
                //Add current difference image to the buffer
                bufferFloat += diffFloat;
            }
        }
        
        for (int i=0; i<numVerts ; i= i+1){
            
            
            ofFloatColor sampleColor(image.getPixels()[i*3]/255.f,				// r
                                     image.getPixels()[i*3+1]/255.f,			// g
                                     image.getPixels()[i*3+2]/255.f);			// b
            // mesh.setColor(i, sampleColor);
            
            
            
        }
        
        
        
        
        
    }
    
    
    
    
    
    
    
    if ( diffFloat.bAllocated ) {
        
        
        
        for (int i=0; i<numVerts; i++) {
            
            ofVec3f vert = mesh.getVertex(i);
            
            float time = ofGetElapsedTimef();
            float timeScale = 5;
            float displacementScale = 0.2;
            ofVec3f timeOffsets = offsets[i];
            float *pixels = bufferFloat.getPixelsAsFloats();
            float diffValue = ofMap(pixels[i], 0, 1, 0, 100);
            vert.x += (ofSignedNoise(time*timeScale+timeOffsets.x)) * displacementScale;
            vert.y += (ofSignedNoise(time*timeScale+timeOffsets.y)) * displacementScale;
            vert.z = (ofSignedNoise(time*timeScale+timeOffsets.z)) * displacementScale - diffValue;
            float destZ = vert.z;
            
            
            
            
            
            int w = grayImage.width;
            int h = grayImage.height;
            
            
            
            //float diffValue = ofMap(pixels[i], 0, 1, 0, 1);
            //        vert.z = vert.z + diffValue;
            //        float difZ = vert.z - destZ;
            
            
            mesh.setVertex(i, vert);
            
            
            ofFloatColor sampleColor(image.getPixels()[i*3]/255.f,				// r
                                     image.getPixels()[i*3+1]/255.f,			// g
                                     image.getPixels()[i*3+2]/255.f);			// b
            
           
            
            
            
            
            if (noseBase.x > 0) {
                
                
                faceShadow = true;
                
                
            }else if (noseBase.x == 0){
                faceShadow = false;
                
                test = 0;
            }
            
            
            
            
            
            if (faceShadow == true && test == 1) {
                if (diffValue<10) {
                    
                    mesh.setColor(i, sampleColor);
                }
                
               
            }
            
            
            
            
            
            
        
            
            
            
        }
        
        
        
    }
    
    if (noseBase.x>0) {
        notification = "press t";
    }else{notification = " ";}
    
     ofLog(OF_LOG_NOTICE, ofToString(test));
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
  
    
    ofColor centerColor = ofColor(85,78,68);
    ofColor edgeColor(0,0,0);
    
    ofBackgroundGradient(centerColor, edgeColor,OF_GRADIENT_CIRCULAR);
    ofBackground(0);
    
    easyCam.begin();
    ofPushMatrix();
    ofRotateY(180);
    ofRotateZ(-90);
    ofTranslate(-iSight.getWidth()*3/2, -iSight.getHeight()*2.7);
    mesh.draw();
    ofPopMatrix();
    easyCam.end();
    
    //image.draw(0, 0);
    
    
    
    gui.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 't'){
       test = 1 ; // do something
    } else {test = 0;}
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
