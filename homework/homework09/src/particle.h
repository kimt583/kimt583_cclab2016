

#ifndef particle_h
#define particle_h


#endif /* particle_h */


#pragma once
#include "ofMain.h"

class Particle{
public:
    //create constructor, constructors initialize classes they can take arguments, but they don't have a return type, because they return classes themselves
    Particle(ofVec2f pos);
    
    void update(float multiplier);
    void draw();
    void applyForce(ofVec2f force);
    void resetForces();
    
    ofVec2f mPosition, mSpeed, mDirection;
    float mLifeSpan;
    
};
