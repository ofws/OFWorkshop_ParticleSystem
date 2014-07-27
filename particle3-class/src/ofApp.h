#pragma once

#include "ofMain.h"
#include "Particle.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofVec2f pos;
        ofVec2f vel;
        ofVec2f netForce;
        ofVec2f mouseAttraction;
        ofVec2f greavity=ofVec2f(0, 1);;
        ofVec2f acceleration;
    
        vector<Particle> particle;
    
    
    
    float w=ofGetWindowWidth();
    float h=ofGetWindowHeight();
    
    bool bounceable;
    bool greavityOn;
    bool attractionOn;
    bool fractionOn;
};
