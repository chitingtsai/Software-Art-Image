#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
      midi.listInPorts();
      midi.openPort("Arturia KeyLab Essential 49 MIDI In");
      midi.addListener(this);
}

//--------------------------------------------------------------
void ofApp::update(){

    starttime = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //displaying MIDI messages
    for(int i = 0; i < messages.size(); i++) {
        ofxMidiMessage &message = messages[i];
        
        
        //reading the messages
        ofSetColor(255);
        ofDrawBitmapString("Velocity", ofGetWidth() - 75, 205);     //0 - 127 -> size
        ofDrawBitmapString(ofToString(message.velocity), ofGetWidth() - 50, 240 + i * 16);
        ofDrawBitmapString("Pitch", ofGetWidth() - 125, 205);   //36 - 84 -> color
        ofDrawBitmapString(ofToString(message.pitch), ofGetWidth() - 100, 240 + i * 16);
//        ofDrawBitmapString("Value", ofGetWidth() - 175, 205);   //0 - 127 ->
//        ofDrawBitmapString(ofToString(message.value), ofGetWidth() - 150, 240 + i * 16);
        
    
        //mapping values
        mappedVelocity = ofMap(message.velocity, 0, 127, 20, 250);
        mappedPitch = ofMap(message.pitch, 36, 84, 0, ofGetWidth());
//        mappedValue = ofMap(message.value, 0, 127, 0, 255);
        
        
        //drawing circles based on the MIDI messages
        ofSetColor(mappedVelocity, mappedVelocity/2, mappedVelocity/1.5, 100-i*5);
        ofDrawCircle( mappedPitch, ofGetHeight()/2, size = mappedVelocity * (i * 1.1));
        
    }
    
}

//--------------------------------------------------------------
void ofApp::exit(){
  midi.closePort();
  midi.removeListener(this);
}

//--------------------------------------------------------------
void ofApp::newMidiMessage(ofxMidiMessage &message){
  messages.push_back(message);
  
  if(messages.size() > 32) {
    messages.erase(messages.begin());
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