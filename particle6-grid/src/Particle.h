#pragma once
#include "ofMain.h"

class Particle {

public:
    Particle();
    void setup(ofVec2f position,ofVec2f velocity);
    void setup(float positionX, float positionY,float velocityX, float velocityY);
    void resetForce();
    void addForce(ofVec2f force);
    void addForce(float forceX, float forceY);
    void updateForce();
    void updatePos();
    void update();
    void bounceOffWalls();
    void draw();

    void addRepulsionForce(float x, float y, float radius, float scale);
    void addRepulsionForce(Particle &p, float radius, float scale);
    
    void updateDamp();
    void updateColor();
    void updateAge();
    void updateNoise();


    void addAttractionForce(float x, float y, float radius, float scale);
    void addAttractionForce(Particle &p, float radius, float scale);
    void addgravityforce();
    void offset();
    

    void addCounterClockwiseForce(Particle & p, float radius, float scale);
    

    ofVec2f position;
    
    ofVec2f originposition;


    ofVec2f velocity;

    ofVec2f force;
    
    ofVec2f noises;

    ofColor color;
    

    float friction;

    float radius;

    bool bFixed;
    
    float life;
    
    float age;
    
    float agePct;
    
    
    float wrapX;
    float wrapY;

};