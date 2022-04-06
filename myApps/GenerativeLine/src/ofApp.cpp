#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetFrameRate(6);
    
    gui.setup();
    gui.add(label.setup("label", "Headache, Use Sliders to Solve the Headache"));
    
    gui.add(vec2Slider.setup("size of headache", ofVec2f(ofGetWidth(), ofGetHeight()), ofVec2f(0,0), ofVec2f(ofGetWidth(), ofGetHeight()) ));
    gui.add(vec4Slider.setup("color of headache", ofVec4f(255,255,255,1.00), ofVec4f(0,0,0,0.00), ofVec4f(255,255,255,1.00)));
    gui.add(intSlider.setup("thickness of headache", 20, 1, 20));

    gui.add(toggle.setup("quiet headache", false));
    gui.add(button.setup("attention to yourself"));
    
    //    gui.add(vec3Slider.setup("vec3 slider", ofVec3f(100,150,90), ofVec3f(0,0,0), ofVec3f(255,255,255)));
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //Draw consecutive line
    myLine.addVertex(ofGetWidth() - ofRandom (vec2Slider->x), ofGetHeight() - ofRandom(vec2Slider->y));
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //Draw lines
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
    
    
    if(toggle == false){
        ofSetColor(ofRandom(vec4Slider->x), ofRandom(vec4Slider->y), ofRandom(vec4Slider->z, ofRandom(vec4Slider->w)));
    }
    
    if (button){
        ofSetColor(255,255,255,0.0);
    }
    
    ofSetLineWidth(intSlider);
    myLine.draw();
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
