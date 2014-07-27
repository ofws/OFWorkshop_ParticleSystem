#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    greavityOn=true;
    bounceable=true;
    attractionOn=true;
    fractionOn=false;
    

    
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
        if(fractionOn){
            particle[i].updateFraction();
        }
        particle[i].updateLifespan();
        particle[i].updatePos();
        
        if(particle[i].lifeSpan>200){
            particle.erase(particle.begin()+i);
        }
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
    for (int i=0;i<2;i++){
        Particle P;
        P.setUp( ofVec2f(x, y) ,ofVec2f(ofRandom(2)-1,ofRandom(2)-1));
        particle.push_back(P);
    }
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