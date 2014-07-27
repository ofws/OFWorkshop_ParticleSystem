#include "Particle.h"

Particle::Particle(){
    friction = 0.01;
    bFixed = false;
    radius=22;

}

void Particle::setup(ofVec2f _position, ofVec2f _velocity){
    // 位置を設定
    position = _position;
    // 初期速度を設定
    velocity = _velocity;

}
void Particle::setup(float positionX, float positionY, float velocityX, float velocityY){
    // 位置を設定
    position = ofVec2f(positionX, positionY);
    // 初期速度を設定
    velocity = ofVec2f(velocityX, velocityY);
    
}

// 力をリセット
void Particle::resetForce(){
    force= ofVec2f(0, -0.2);
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
    noises.x=sin(ofNoise(position.x,0))*agePct*100;
    noises.y=cos(ofNoise(position.y,0))*agePct*100;
    
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
    updateForce();
    updatePos();
    updateDamp();
}



// 描画
void Particle::draw(){
  
    for(int i=0;i<(radius-2);i++){
        ofSetColor(color,(255/(radius-2))*i);
        ofCircle(position, radius-i);
    }
    
    //ofCircle(position, radius);
  //  ofSetColor(255, 0, 0);
}

// 反発する力


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


