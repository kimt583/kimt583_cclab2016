
#include <stdio.h>

#include "particle.h"

//initializing constructor, and initializing the variables inside of it
Particle::Particle(ofVec2f position):mPosition(position),mSpeed(ofRandom(-2.f,2.f),ofRandom(-2.f,2.f)),mDirection(ofVec2f(0)),mLifeSpan(255.f){};
//update function
void Particle::update(float multiplier){
    //apply acceleration to velocity
    mSpeed += mDirection;
    mPosition += mSpeed*multiplier;
    
    //decrese life span
    if(mLifeSpan>0){
        mLifeSpan-=2.f;
    }
}
//draw function
void Particle::draw(){
    if(mLifeSpan>100){
        //make it brighter
        ofSetColor(mLifeSpan);
    }else if (mLifeSpan<=100){
        ofSetColor(ofRandom(0,255));
    }
    
    //if particle is closer, it's smaller
    ofDrawCircle(mPosition, 3.f*ofMap(mLifeSpan,0,255.f,0,1.f));
}

//apply force function
void Particle::applyForce(ofVec2f force){
    mDirection+=force;
}
//reset forces
void Particle::resetForces(){
    mDirection*=0;
}
