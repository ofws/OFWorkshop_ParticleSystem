#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    pos.x=mouseX;
    pos.y=mouseY;
    
    greavityOn=true;
    bounceable=false;
    attractionOn=true;
    
    mass=50;
    
    radius=20;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    //update acc
    acceleration=netForce/mass;
    
    //update vel
    vel+=acceleration;

    //update position
    pos=pos+vel;
    
    //update attraction force
    if(attractionOn){
        mouseAttraction= ofVec2f((mouseX-pos.x),(mouseY-pos.y))/60;
    }
    else{
        mouseAttraction=ofVec2f(0,0);
    }
    
    //bounce when hit the border
    if(bounceable){
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
    
    //adding greavity
    if(greavityOn){
        netForce=(greavity+mouseAttraction);
    }
    else{
    //adding force
        netForce=mouseAttraction;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(30,30,30);
    ofSetColor(200, 200, 200);
    ofFill();
    ofCircle(pos.x, pos.y, radius);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}