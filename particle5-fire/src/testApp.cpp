#include "testApp.h"
#include "ofAppGlutWindow.h"


//--------------------------------------------------------------
void testApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(63);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    // パーティクル画像読込み
    //particleImage.loadImage("particle32.png");
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i = 0; i < particle.size(); i++){
       particle[i].resetForce();

        //particle[i].updateForce();   this is useless after resetforce()
        
        
        
        particle[i].updateColor();
        particle[i].updatePos();
        particle[i].updateDamp();
        particle[i].updateAge();
       // particle[i].updateNoise();

    }
    
    

    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    // 設定した場所に円を描く
   // ofSetHexColor(0xffffff);
    for(int i = 0; i < particle.size(); i++){
        particle[i].draw();
        
        ofPoint pos = ofPoint(particle[i].position.x, particle[i].position.y);
        //ofDrawBitmapString("particle num = " + ofToString(particle[i].noises), pos.x, pos.y);

        //particleImage.draw(pos.x-16, pos.y-16, 32, 32);
        //DrawParticle(pos.x, pos.y, 2, 12, 80, 20, 10);
    }
    
    ofSetColor(255, 255,255);
    ofDrawBitmapString("particle num = " + ofToString(particle.size()), 10, 15);
   // ofDrawBitmapString("force " + ofToString(bFixed), 10, 30);
    
    


    
//    Sc1.setTextureWrap(GL_REPEAT,GL_REPEAT);
//    Sc1.setTextureMinMagFilter(GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
//
//    glBegin(GL_QUADS);
//    glTexCoord2d(0,0); ;glVertex3f(-400, 250, 20);
//    glTexCoord2d(400,0); ;glVertex3f(-400, 250, -20);
//    glTexCoord2d(400,400); ;glVertex3f(-400, -250, -20);
//    glTexCoord2d(0,400); ;glVertex3f(-400, -250, 20);
//
//    
//    
//    glEnd();
    
    
   //Sc1.draw(0,0,500,500);

    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == 'f') {
        ofToggleFullscreen();
    }
    if (key == 'c') {
        particle.clear();
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    for(int i = 0; i < NUM; i++){
        ofVec2f pos = ofVec2f(x, y);
        float length = ofRandom(1);
        float angle = ofRandom(PI * 2);
        ofVec2f vel = ofVec2f(cos(angle) * length, sin(angle) * length);
        Particle p;
        p.setup(pos, vel);
        p.radius = 22;
        p.friction = 0.002;
        p.color=ofColor(80,20,10);
        p.life=800;
        particle.push_back(p);

        
    }
    
    if(particle.size()>max){
        for(int i = 0; i < NUM; i++){
            particle.erase(particle.begin());
         
        }
        
    }
    
    
    
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

