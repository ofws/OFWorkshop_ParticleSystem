//
//  File.cpp
//  emptyExample
//
//  Created by Hang Ye on 7/25/14.
//
//

#include "Particle.h"

Particle::Particle(){
    
   // dot.loadImage("images/dot.png");
    

}

void Particle::setUp(ofVec2f position,ofVec2f velocity){
    pos=position;
    vel=velocity;
    mass=50;
    radius=20;
    lifeSpan=0;
}


void Particle::updatePos(){
    
    //update acc
    acceleration=netForce/mass;
    
    //update vel
    vel+=acceleration;
    
    //update position
    pos=pos+vel;
    
    //set netforce to zero everyframe, prevent netforce from growing crazy.
    netForce=ofVec2f (0,0);

}



void Particle::draw(){
    ofSetColor(200, 200, 200,255*(lifeSpan/200));
    ofFill();
    radius=20*(1-lifeSpan/200);
    ofCircle(pos.x, pos.y, radius);
    
    //dot.draw(pos.x, pos.y, radius,radius);
    
}

void Particle::updateLifespan(){
    lifeSpan++;
}

void Particle::addForce(ofVec2f force){
    netForce+=force;
}

void Particle::updateFraction(){
    netForce -= vel*fraction;
}

void Particle::updateAttractionForce(float inputX,float inputY){
    mouseAttraction= ofVec2f((inputX-pos.x),(inputY-pos.y))/(60+ofRandom(50)-25) ;
}

void Particle::bounce(){
    if(pos.x-radius<0 ){
        pos.x=radius;
        vel.x=-vel.x;
    }
    else if(pos.x+radius>w){
        pos.x=w-radius;
        vel.x=-vel.x;
    }
    else if(pos.y-radius<0 ){
        pos.y=radius;
        vel.y=-vel.y;
    }
    else if(pos.y+radius>h){
        pos.y=h-radius;
        vel.y=-vel.y;
    }
}