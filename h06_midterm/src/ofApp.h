#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //--------audio part from 'Mastering openFrameworks"
    
    //Function for receiving audio
    void audioReceived( float *input, int bufferSize, int nChannels );
    
    //Function for generating audio
    void audioOut( float *output, int bufferSize, int nChannels );
    
    //Object for sound output and input setup
    ofSoundStream soundStream;
    
    //Constants
    const int sampleRate = 44100;           //Sample rate of sound
    const float duration = 0.25;            //Duration of the recorded sound in seconds
    const int N = duration * sampleRate;    //Size of the PCM buffer
    
    const float volume = 0.5;	//Output sound volume
    
    //Variables
    vector<float> buffer;		//PCM buffer of sound sample
    int recPos = 0;				//Current recording position in the buffer
    int playPos = 0;			//Current playing position in the buffer
    
    int recordingEnabled = 1;	//Is recording enabled
    int playingEnabled = 0;		//Is playing enabled
    
    
    
    
    
    ofMesh mesh;		//Mesh
    ofLight light;		//Light
    
    ofVec3f pos;
    ofVec2f p,p2,p3;
    ofColor c,pC;
    
    int W = 30;		//Grid size
    int H = 30;
    
    int ofGetSec(){
        time_t curr;
        tm  local;
        time(&curr);
        local =*(localtime(&curr));
        return local.tm_sec;
    }
    
    int ofGetMin(){
        time_t curr;
        tm  local;
        time(&curr);
        local =*(localtime(&curr));
        return local.tm_min;
    }
    
    int ofGetHour(){
        time_t curr;
        tm  local;
        time(&curr);
        local =*(localtime(&curr));
        return local.tm_hour;
    }
    
    float sec, min, hour;
    float cuSec;
    float ctime, lasTime;
    float bgColor;

};










//Universal function which sets normals  //mastering
//for the triangle mesh
void setNormals( ofMesh &mesh );

