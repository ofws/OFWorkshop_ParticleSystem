//
//  File.h
//  emptyExample
//
//  Created by Hang Ye on 7/25/14.
//
//

#ifndef particle_h
#define particle_h

#include "ofMain.h"

class Particle{
    
public:
    Particle();
    
    void updatePos();
    void updateAttractionForce(float inputX,float inputY);
    void addForce();
    void setUp(ofVec2f position,ofVec2f velocity);
    void draw();
    void addForce(ofVec2f force);
    void bounce();
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f netForce;
    ofVec2f mouseAttraction;
    ofVec2f greavity=ofVec2f(0, 1);
    ofVec2f acceleration;
    
    
    float fraction;
    float mass;
    

    
    float w=ofGetWindowWidth();
    float h=ofGetWindowHeight();
    
    
    float lifeSpan;
    float radius;
    
    ofColor color;
    
    
    
};

#endif
