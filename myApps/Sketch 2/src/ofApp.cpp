#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    ofSetCircleResolution(100);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float time = ofGetElapsedTimef();
    
    for (int y = 1; y < 20; y++){
    for (int i=0; i < 900; i+=5){
        
        ofSetColor(215 + 30 * sin (i * 0.01 + time),
                   230+ 15 * sin (i * 0.012 + time),
                   240 + 10 * sin (i * 0.011 + time));
        ofDrawCircle(i, ofGetHeight()/4+ 50 * y + 75 * sin(i * 0.01 + time + y)- 25, 30 + 50 * sin(i * 0.005 + time + y));
        
        ofSetColor(30 + 30 * sin (i * 0.01 + time),
                   90 + 10 * sin (i * 0.012 + time),
                   140 + 10 * sin (i * 0.011 + time));
        ofDrawCircle(60 + i, 50 * y + ofGetHeight()/4 + 75 * sin(i * 0.01 + time + y), 30 + 50 * sin(i * 0.005 + time + y));
        
    }
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
