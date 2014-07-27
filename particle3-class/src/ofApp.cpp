#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    greavityOn=true;
    bounceable=false;
    attractionOn=true;
    
    for (int i=0;i<22;i++){
        Particle P;
        P.setUp(ofVec2f(mouseX+ofRandom(10)-5,mouseY+ofRandom(10)-5),ofVec2f(0,0));
        particle.push_back(P);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    for(int i=0;i<particle.size();i++){
        if(attractionOn){
            particle[i].updateAttractionForce(mouseX, mouseY);
            particle[i].addForce(particle[i].mouseAttraction);
        }
        if(greavityOn){
            particle[i].addForce(particle[i].greavity);
        }
        if(bounceable){
            particle[i].bounce();
        }
        particle[i].updatePos();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(20, 20, 20);
    for(int i=0;i<particle.size();i++){
        particle[i].draw();
    }
    
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