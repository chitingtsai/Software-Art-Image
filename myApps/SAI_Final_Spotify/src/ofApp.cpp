#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    //    ofSetBackgroundAuto(false);
    sound.load("BornThisWay.wav");
    ring.load("ringtone.wav");
    
    home.load("/Users/chi-tingtsai/Downloads/of_v0.11.2_osx_release 2/apps/myApps/SAI_Final_Spotify/bin/data/home-icon-black-22.jpg");
    search.load("/Users/chi-tingtsai/Downloads/of_v0.11.2_osx_release 2/apps/myApps/SAI_Final_Spotify/bin/data/search-icon-jpg-14.jpeg");
    shelf.load("/Users/chi-tingtsai/Downloads/of_v0.11.2_osx_release 2/apps/myApps/SAI_Final_Spotify/bin/data/book-icon-black-background-flat-style-vector-illustration-168420237.jpeg");
    play.load("/Users/chi-tingtsai/Downloads/of_v0.11.2_osx_release 2/apps/myApps/SAI_Final_Spotify/bin/data/a54f63994e1b39bd0d6feeae27d64adb.jpg");
    pause.load("/Users/chi-tingtsai/Downloads/of_v0.11.2_osx_release 2/apps/myApps/SAI_Final_Spotify/bin/data/800px_COLOURBOX26341460.jpeg");
    
    play_transparency = 255;
    call_transparency = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    audio_position = sound.getPosition();
    ring_position = ring.getPosition();
    ofSoundUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //pulsing circle
    ofColor drawColor;
    int length = 700;
    int barWidth = 20;
    float bandsToGet = 512;
    float width = (float)(5*128) / bandsToGet;
    float * val = ofSoundGetSpectrum(bandsToGet);
    for (int i = 0; i < bandsToGet; i++){
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofRotateDeg(360.0 / bandsToGet * i );
        
        drawColor.setHsb(255/bandsToGet * i, 255, 255, 100);
        ofSetColor(drawColor);
        ofDrawRectangle(100, barWidth/2, val[i] * length, barWidth/2);
        ofPopMatrix();
        
        //audio progress
        ofSetColor(255);
        for (int j = 0; j < 3; j++){
            ofDrawRectangle((j * 20) + 300, ofGetHeight()- 110, ofMap(audio_position, 0, 1, 20, ofGetWidth()/4 - 50), 5);
        }
        
        //Spotify text
        ofSetColor(255);
        ofDrawBitmapString("For You Playlist", 300, 170);
        0
        //Spotify background
        ofSetColor(255, 255, 255, 180);
        home.draw(ofGetWidth()/2 - 205, ofGetHeight()-70, 70, 70);
        search.draw(ofGetWidth()/2 - 40, ofGetHeight()-65, 60, 60);
        shelf.draw(ofGetWidth()/2 + 100, ofGetHeight()-95, 120, 120);
        pause.draw(ofGetWidth()/2 - 215, ofGetHeight()-225, 100, 100);
        
        ofSetColor(0, 0, 0, call_transparency);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        
        ofSetColor(255, 255, 255, play_transparency);
        play.draw(ofGetWidth()/2 - 205, ofGetHeight()-215, 75, 75);
        
        //ringtone & end of pride music
        if (audio_position > 0.99){
            play_transparency = 255;
            ring.play();
            call_transparency = 255;
        }
        ofSetColor(170, 1, 20, call_transparency);
        ofDrawRectangle(ofGetWidth()/2 - 200, ofGetHeight()/2 - 50, 400, 100);
        ofSetColor(255, 255, 255, call_transparency);
        ofDrawBitmapString("Call from: DAD (p.s. don't pick up)", ofGetWidth()/2 - 150, ofGetHeight()/2);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == ' '){
        sound.play();
        play_transparency = 0;
    }
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
