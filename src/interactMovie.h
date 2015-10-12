//
//  interactMovie.h
//  switchVideo_test
//
//  Created by Shin on 2015/10/12.
//
//

#ifndef __switchVideo_test__interactMovie__
#define __switchVideo_test__interactMovie__

#include <stdio.h>
#include "ofMain.h"

class interactMovie : public ofVideoPlayer{
public:
    interactMovie();
    void setup(string _fileName, ofVec2f _pos, int _frame, float _speed);
    
    ofVec2f pos;
    string name;
    
private:
    int frame;
    float speed;
};

#endif /* defined(__switchVideo_test__interactMovie__) */
