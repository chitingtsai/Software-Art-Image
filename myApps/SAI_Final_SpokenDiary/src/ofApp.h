#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofSoundPlayer sound;
    
    float *fft;
    float *soundSpectrum;
    int bands;
    
    float intensity;
    float line_width;
    float line_number;
    
    float audio_position;
    float line_progress;
    float opacity_progress;
    
    ofImage notes;
    int note_transparency;
    float time; 
};
