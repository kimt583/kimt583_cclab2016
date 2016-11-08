

#ifndef particleSystem_hpp
#define particleSystem_hpp

#include <stdio.h>

#endif /* particleSystem_hpp */


#pragma once
#include "ofMain.h"
#include "particle.h"

class ParticleSystem{
public:
    ParticleSystem(ofVec2f position);
    void update(ofVec2f force);
    void draw();
    vector<Particle> mParticleList;//vector<t> nameofVector, vectors are like a fancy, high-end array
    ofVec2f mPosition;
    int mEmitRate;
    bool mIsAddingParticles;
};
