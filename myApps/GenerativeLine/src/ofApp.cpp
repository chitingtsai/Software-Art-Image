#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetFrameRate(7);
}

//--------------------------------------------------------------
void ofApp::update(){
    myLine.addVertex(ofRandom (ofGetWidth()), ofRandom(ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor DrawingColor;
    
    for (int i = 0; i < 255; i++){
        DrawingColor.setHsb(i, i/1.5, i/1.5, i/2);
        ofSetColor(DrawingColor);
        
        ofSetLineWidth(i/20);
        
        ofDrawLine(ofRandom(ofGetWidth()/2.5), ofRandom(ofGetHeight()), ofRandom(ofGetWidth()), ofRandom(ofGetHeight()/2.5));
    }
    
    for (int j = 0; j < 255; j++){
        DrawingColor.setHsb(j/1.5, j/1.5, j/1.1, j/1.3);
        ofSetColor(DrawingColor);
        
        ofSetLineWidth(j/30);
        
        ofDrawLine(ofRandom(ofGetWidth()/4), ofRandom(ofGetHeight()), ofRandom(ofGetWidth()), ofRandom(ofGetHeight()/4));
    }
    
    for (int k = 0; k < 255; k++){
        DrawingColor.setHsb(k, k, k, k);
        ofSetColor(DrawingColor);
        
        ofSetLineWidth(k/40);
        
        ofDrawLine(ofRandom(ofGetWidth()/5), ofRandom(ofGetHeight()), ofRandom(ofGetWidth()), ofRandom(ofGetHeight()/5));
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
