#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    pos.x=ofGetWindowWidth()/2;
    pos.y=ofGetWindowHeight()/2;
    vel= ofVec2f(ofRandom(20)-10,ofRandom(20)-10);
    radius=20;
}

//--------------------------------------------------------------
void ofApp::update(){
    pos=pos+vel;
    
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