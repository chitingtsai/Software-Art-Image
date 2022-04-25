#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofColor backgroundColor;
    backgroundColor.setHsb(0,0,0);
    ofBackground(backgroundColor);
    ofSetFrameRate(5);
    
    gui.setup();
    gui.add(label.setup("label", "ON THE ROAD"));
    gui.add(toggle.setup("fast & slow", true));

}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //Draw lines
    ofColor DrawingColor;
    
    
    for (int i = 0; i < 255; i++){
        DrawingColor.setHsb(0, 0, 50, 50);
        ofSetColor(DrawingColor);

        ofSetLineWidth(i/40);

        ofDrawLine(ofGetWidth()/2, ofGetHeight()/4*3 + ofNoise(-50, 50), ofRandom(ofGetWidth()), ofGetHeight());
    }

    for (int k = 0; k < 255; k++){
        DrawingColor.setHsb(240, 60, 150, 25);
        ofSetColor(DrawingColor);

        ofSetLineWidth(k/40);

        ofDrawLine(ofGetWidth()/2 , ofGetHeight()/4*3 + ofNoise(-50, 50), 0, ofRandom(ofGetHeight()/4*3, ofGetHeight()) + ofNoise(-50, 50));
        ofDrawLine(ofGetWidth()/2 , ofGetHeight()/4*3 + ofNoise(-50, 50), ofGetWidth(), ofRandom(ofGetHeight()/4*3, ofGetHeight()) + ofNoise(-50, 50));
    }

    for (int j = 0; j < 255; j++){
        DrawingColor.setHsb(180 + ofNoise(30), 0, 255, 20);
        if(toggle == true){
            DrawingColor.setHsb(0, 0, 0, 50);
        }
        ofSetColor(DrawingColor);

        ofSetLineWidth(j/40);

        ofDrawLine(ofGetWidth()/2 , ofGetHeight()/4*3 + ofNoise(-50, 50), 0, ofRandom(ofGetHeight()/4*3) + ofNoise(-50, 50));
        
        ofDrawLine(ofGetWidth()/2 , ofGetHeight()/4*3 + ofNoise(-50, 50) , ofGetWidth(), ofRandom(ofGetHeight()/4*3 + ofNoise(-50, 50)));
    }
    
    DrawingColor.setHsb(0,0,0);
    ofSetColor(DrawingColor);
    ofDrawCircle(ofGetWidth()/2 , ofGetHeight()/4*3,5);
    
    gui.draw();
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
