#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofBackground(63);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    

    
    
    
    
    for(int i = 0; i < 19; i++){
        
        for (int m=0; m<19; m++) {
            
            
            ofVec2f pos = ofVec2f((ofGetWidth()/20)*(i+1), (ofGetHeight()/20)*(m+1));
            float length = ofRandom(0.2);
            float angle = ofRandom(PI * 2);
            ofVec2f vel = ofVec2f(cos(angle) * length, sin(angle) * length);
            
            //ofVec2f vel=ofVec2f(0,0);
            
            Particle p;
            p.setup(pos,vel);
            p.offset();
            p.radius = 2;
            p.friction = 0.02;
            p.life=800;
            particle.push_back(p);
            
            
            
            
            
        }
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    for (int i = 0; i < particle.size(); i++){
		particle[i].resetForce();
	}
    
    for (int i = 0; i < particle.size(); i++){
		
        
		particle[i].addRepulsionForce(mouseX, mouseY, 1000, 0.07f);
    }
    
    for(int i = 0; i < particle.size(); i++){
       particle[i].update();
        
        
    }
    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    

    

    
    
    
    
    for(int i = 0; i < particle.size(); i++){
        particle[i].draw();
        
        
        
        
        
        
        ofPoint pos = ofPoint(particle[i].position.x, particle[i].position.y);
        if(i<particle.size()-1 ){
        ofPoint pos2= ofPoint(particle[i+1].position.x, particle[i+1].position.y);
            if((pos2-pos).length()<200){
        ofLine(pos.x, pos.y, pos2.x, pos2.y);
            }
        }
        
        
        if(i<particle.size()-19 ){

        ofPoint pos3=ofPoint(particle[i+19].position.x, particle[i+19].position.y);
            if((pos3-pos).length()<200){
                ofLine(pos.x, pos.y, pos3.x, pos3.y);
            }

        }
    }
    
        
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
