#include "Particle.h"

Particle::Particle(){
    friction = 0.01;
    bFixed = false;

}

void Particle::setup(ofVec2f _position, ofVec2f _velocity){
    // 位置を設定
    position = _position;
    // 初期速度を設定
    velocity = _velocity;
    
    originposition=position;

}
void Particle::setup(float positionX, float positionY,float velocityX,float velocityY){
    // 位置を設定
    position = ofVec2f(positionX, positionY);
    // 初期速度を設定
    velocity = ofVec2f(velocityX, velocityY);
    
    originposition=position;
    
}

// 力をリセット
void Particle::resetForce(){
    force= ofVec2f(0, 0);
}


// 力を加える

void Particle::addForce(float forceX, float forceY){
    force += ofVec2f(forceX, forceY);
}



void Particle::updateDamp(){
   radius=radius*(1-agePct);
}

void Particle::updateColor(){
    color.r-=0.1;
    color.g-=0.2;
    color.b-=0.1;
}

void Particle::updateAge(){
    if(age<life){
        age++;
    }
    agePct=age/life;
}


// 摩擦力の更新
void Particle::updateForce(){
    force -= velocity * friction;

}

void Particle::updateNoise(){
    //noises.x=sin(ofNoise(position.x,0))*agePct*100;
    //noises.y=cos(ofNoise(position.y,0))*agePct*100;
    //noises.x=sin(ofNoise(0,ofGetElapsedTimeMillis()));
    //noises.y=cos(ofNoise(0,ofGetElapsedTimeMillis()));
    
    
}

// 位置の更新
void Particle::updatePos(){


    if (!bFixed) {
        velocity += force;
        position += velocity;
        position += noises;
        
    }
    
    
    
    
    
}

// 力の更新と座標の更新をupdateとしてまとめる
void Particle::update(){
    //updateNoise();
    
    addgravityforce();
    updateForce();
    updatePos();
}



// 描画
void Particle::draw(){
  
//    for(int i=0;i<(radius-2);i++){
//        ofSetColor(color,(255/(radius-2))*i);
//        ofCircle(position, radius-i);
//    }
    
    ofCircle(position, radius);
    ofSetColor(255, 255, 255);
}

// 反発する力

void Particle::offset(){
    position=originposition+ofVec2f(ofRandom(-1,1), ofRandom(-1, 1));
    
}

void Particle:: addgravityforce(){
    force+=(originposition-position)/ ofRandom(200,500);
    
}



void Particle::addRepulsionForce(float x, float y, float radius, float scale){
    
	// ----------- (1) make a vector of where this position is:
	
	ofVec2f posOfForce;
	posOfForce.set(x,y);
	
	// ----------- (2) calculate the difference & length
	
	ofVec2f diff	= position - posOfForce;
	float length	= diff.length();
	
	// ----------- (3) check close enough
	
	bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
	
	// ----------- (4) if so, update force
    
	if (bAmCloseEnough == true){
		float pct = 1 - (length / radius);  // stronger on the inside
        diff.normalize();
		force.x = force.x + diff.x * scale * pct;
        force.y = force.y + diff.y * scale * pct;
    }
}

//------------------------------------------------------------
void Particle::addAttractionForce(float x, float y, float radius, float scale){
    
	// ----------- (1) make a vector of where this position is:
	
	ofVec2f posOfForce;
	posOfForce.set(x,y);
	
	// ----------- (2) calculate the difference & length
	
	ofVec2f diff	= position - posOfForce;
	float length	= diff.length();
	
	// ----------- (3) check close enough
	
	bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
	
	// ----------- (4) if so, update force
    
	if (bAmCloseEnough == true){
		float pct = 1 - (length / radius);  // stronger on the inside
		diff.normalize();
		force.x = force.x - diff.x * scale * pct;
        force.y = force.y - diff.y * scale * pct;
    }
}


void Particle::addRepulsionForce(Particle &p, float radius, float scale){
	ofVec2f posOfForce;
	posOfForce.set(p.position.x,p.position.y);
	ofVec2f diff	= position - posOfForce;
	float length	= diff.length();
	bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
	if (bAmCloseEnough == true){
		float pct = 1 - (length / radius);
		diff.normalize();
		force.x = force.x + diff.x * scale * pct;
        force.y = force.y + diff.y * scale * pct;
		p.force.x = p.force.x - diff.x * scale * pct;
        p.force.y = p.force.y - diff.y * scale * pct;
    }
}

// 引き付けあう力


void Particle::addAttractionForce(Particle &p, float radius, float scale){
	ofVec2f posOfForce;
	posOfForce.set(p.position.x, p.position.y);
	ofVec2f diff	= position - posOfForce;
	float length	= diff.length();
	bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
	if (bAmCloseEnough == true){
		float pct = 1 - (length / radius);
		diff.normalize();
		force.x = force.x - diff.x * scale * pct;
        force.y = force.y - diff.y * scale * pct;
		p.force.x = p.force.x + diff.x * scale * pct;
        p.force.y = p.force.y + diff.y * scale * pct;
    }
}


