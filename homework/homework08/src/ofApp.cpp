#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(0, 0, 0);
    
    // set initial circle radius
    mCircleRadius = 50;
    
    // set initial position
    mPos = ofVec2f(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
    
    // set friction
    mFriction = 0.99;
    
    // no velocity at the beginning
    mVelocity = ofVec2f(0);
    
    // no force at beginning
    mAcceleration = ofVec2f(0);
    
    r=255;
    g=255;
    b=255;
}

//--------------------------------------------------------------
void ofApp::update(){
    // reduce velocity according to friction
    if(mVelocity.length() > 0) {
        mVelocity *= ofVec2f(mFriction);
        
        // when velocity is too small, we don't want to update our velocity
        if (mVelocity.length() < MIN_VELOCITY) {
            mVelocity = ofVec2f(0);
        }
    }

    // update position of ball according to velocity
    if (mVelocity.length() > 0) {
        mPos += mVelocity;
        
        // circle size represent velocity
        mCircleRadius = 30 + mVelocity.length();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(r,g,b);
    ofSetCircleResolution(50);
    ofDrawCircle(mPos, mCircleRadius);
    
    if(particle==true){
        ofDrawCircle(mPos.x, mPos.y, ofRandom(5,10));
        ofDrawCircle(mPos.x+10, mPos.y+10, ofRandom(5,10));
        ofDrawCircle(mPos.x-10, mPos.y-10, ofRandom(5,10));
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
if(key==32)
{
    
    //calculate acceleration
    mAcceleration.x = mPos.x * ofRandom(-50,50);
    mAcceleration.y = mPos.y * ofRandom(-30,30);
    
    //normalize acceleration
    mAcceleration = mAcceleration.getNormalized();
    
    //apply acceleration(direction) to velocity
    mVelocity += mAcceleration;
}
    if(mPos.x<=0)
    {
        mPos.x=mCircleRadius;
    }
    if(mPos.x>=ofGetWindowWidth())
    {
        mPos.x=ofGetWindowWidth()-mCircleRadius;
    }
    if(mPos.y<=0)
    {
        mPos.y=mCircleRadius;
    }
    if(mPos.y>=ofGetWindowHeight())
    {
        mPos.y=ofGetWindowHeight()-mCircleRadius;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key==32)
    {
        r=ofRandom(0,200);
        g=ofRandom(100,200);
        b=ofRandom(100,255);
        
        particle=true;
    }

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
   
    
    ofVec2f mousePos = ofVec2f(x, y);
    
    mPos.x=mousePos.x;
    mPos.y=mousePos.y;

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    ofVec2f mousePos = ofVec2f(x, y);
    
    mPos.x=mousePos.x;
    mPos.y=mousePos.y;
    
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
   

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
