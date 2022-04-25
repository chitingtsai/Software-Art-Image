#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
      midi.listInPorts();
      midi.openPort("Arturia KeyLab Essential 49 MIDI In");
      midi.addListener(this);
}

//--------------------------------------------------------------
void ofApp::update(){

    time = ofGetElapsedTimef();
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
        
    
        //mapping values
        mappedVelocity = ofMap(message.velocity, 0, 127, 20, 70);
        mappedPitch = ofMap(message.pitch, 36, 84, 0, ofGetWidth());
        mappedColor = ofMap(message.pitch, 36, 84, 0, 255);
        
        
        //drawing circles based on the MIDI messages
        ofSetColor(mappedColor/2.5, mappedColor/1.5, mappedColor, 255* sin(i * 0.05 + time));
        ofDrawCircle(mappedPitch, ofGetWidth()-mappedPitch, mappedVelocity);
        
        ofSetColor(mappedColor/2, mappedColor/1.5, mappedColor, 30* sin(i * 0.05 + time));
        ofDrawCircle(mappedPitch - 150, ofGetWidth()- mappedPitch - 250, mappedVelocity*1.5);
        
        ofSetColor(mappedColor/3, mappedColor/1.5, mappedColor, 25* sin(i * 0.05 + time));
        ofDrawCircle(mappedPitch + 200 , ofGetWidth()- mappedPitch + 250, mappedVelocity*1.8);
        
        ofSetColor(mappedColor/3, mappedColor/1.5, mappedColor, 5* sin(i * 0.05 + time));
        ofDrawCircle(mappedPitch - 150 , ofGetWidth()- mappedPitch - 250, mappedVelocity*3);
        
        ofSetColor(mappedColor/3, mappedColor/1.5, mappedColor, 10* sin(i * 0.05 + time));
        ofDrawCircle(mappedPitch + 200 , ofGetWidth()- mappedPitch + 250, mappedVelocity*4.5);
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
