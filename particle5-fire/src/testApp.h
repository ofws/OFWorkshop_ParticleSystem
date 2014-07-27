#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "ofAppGlutWindow.h"


class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void DrawParticle(float x, float y, float rad,float size,int r, int g, int b);
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    vector<Particle> particle;
   // ofImage particleImage;
    static const int NUM = 5;
    
    int max=500;
    
    
    
    ofPoint corners[4];
    int selectedCorner;
    
    
    ofTexture Sc1;
    ofTexture Sc2;
    ofTexture Sc3;
    ofTexture SSc4;
    
};
