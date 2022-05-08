#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    sound.load("BornThisWay.wav");
    sound.play();
    
    intensity = 250.0;
    line_width = 512;
    line_number = 8;
    
    
    fft = new float[512];
    for (int i = 0; i < 512; i++){
        fft[i] = 0;
    }
    bands = line_width;

}
//--------------------------------------------------------------
void ofApp::update(){
    audio_position = sound.getPosition()*100;
    ofSoundUpdate();
    
    soundSpectrum = ofSoundGetSpectrum(bands);
    for (int i = 0; i < bands; i++){
        fft[i] *= 0.9;
        if (fft[i] < soundSpectrum[i]){
            fft[i] = soundSpectrum[i];
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //say diary playing 
    
    line_progress = ofMap(audio_position, 0, 100, 0, 512);
    opacity_progress = ofMap(audio_position, 0, 100, 0, 255);
    
    
    ofTranslate(256, 192);
    for (int i = 0; i < line_progress
         ; i+=(line_width/line_number)){
        
        ofPolyline polyline;
        
        for (int j = 0; j < line_progress; j++){
            polyline.addVertex(j, i - fft[j] * intensity);
            
        }
        ofSetColor(255, 255, 255, opacity_progress);
        polyline.draw();
    }
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
