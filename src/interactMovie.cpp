//
//  interactMovie.cpp
//  switchVideo_test
//
//  Created by Shin on 2015/10/12.
//
//

#include "interactMovie.h"

interactMovie::interactMovie(){
}

void interactMovie::setup(string _fileName, ofVec2f _center, int _frame, float _speed){
    this->setPixelFormat(OF_PIXELS_RGBA);
    this->loadMovie(_fileName);
    this->play();
    this->setLoopState(OF_LOOP_NONE);
    
    pos = _center - ofVec2f(this->width/2, this->height/2);
    frame = _frame;
    speed = _speed;
}