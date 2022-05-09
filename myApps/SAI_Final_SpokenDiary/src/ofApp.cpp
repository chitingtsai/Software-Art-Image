#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(231, 207, 138);
    sound.load("SAI_joined recording.mp3");
    sound.play();
    notes.load("/Users/chi-tingtsai/Downloads/of_v0.11.2_osx_release 2/apps/myApps/SAI_Final_SpokenDiary/bin/data/Note 8 May 2022 (2).jpg");
    
    intensity = 250.0;
    line_width = 512;
    line_number = 8;
    note_transparency = 0;
    
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
    
    ofPushMatrix();
    ofTranslate(192, 200);
    for (int i = 0; i < line_progress; i+=(line_width/line_number)){
        
        ofPolyline polyline;
        
        for (int j = 0; j < line_progress; j++){
            polyline.addVertex(j, i - fft[j] * intensity);
            
        }
        ofSetColor(0, 0, 0, opacity_progress);
        polyline.draw();
    }
    ofPopMatrix();
    
    if (audio_position > 0 & audio_position < 99){
        note_transparency = opacity_progress/3*2;
    }
    else if (audio_position > 99){
        note_transparency == 255;
    }
    ofSetColor(255, 255, 255, note_transparency);
    notes.draw(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' '){
        ofSetColor(0);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
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
