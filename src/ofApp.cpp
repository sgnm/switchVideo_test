#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    
    ofEnableAlphaBlending();
    // 動画読み込む前にフォーマットを指定してあげる必要がある
    intDark.setPixelFormat(OF_PIXELS_RGBA);
    baseDark.setPixelFormat(OF_PIXELS_RGBA);
    intLight.setPixelFormat(OF_PIXELS_RGBA);
    baseLight.setPixelFormat(OF_PIXELS_RGBA);
    
    intDark.loadMovie("1_TDW_movie_intaraction_hugu_default&action.mov");
    baseDark.loadMovie("2_TDW_movie_test_base_1920x1080_rev02.mov");
    intLight.loadMovie("3_TDW_movie_intaraction_hugu_default.mov");
    baseLight.loadMovie("4_TDW_movie_test_light_1920x1080_rev02.mov");
    
    intDark.play();
    baseDark.play();
    intLight.play();
    baseLight.play();
    
    // ループをOFFに設定
    intDark.setLoopState(OF_LOOP_NONE);
    
    thresFrame = 178;
    
    bPlay = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    intDark.update();
    baseDark.update();
    intLight.update();
    baseLight.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    baseLight.draw(0, 0); // 1920*1080
    intLight.draw(0, 0); // 1280*720
    baseDark.draw(0, 0); // 1920*1080
    intDark.draw(0, 0); // 1280*720
    
    center = ofPoint(intDark.width/2, intDark.height/2);
    ofCircle(center, 10);
    ofCircle(mouse, 10);
    ofLine(mouse, center);
    
//    if (bDrawMode) {
//        intLight.draw(0, 0);
//    }
//    
//    ofNoFill();
//    ofRect(ofGetWidth()/2, ofGetHeight()/2-100, 250, 250);
//    center = ofPoint(ofGetWidth()/2 + 250/2, ofGetHeight()/2-100 + 250/2);
//    ofCircle(center, 10);
//    ofCircle(mouse, 10);
//    
//    // エリア内に入ったときに、頭からアニメーション再生、ロープOFFなので、１回で終了。エリア外になったときに、フレーム最初に戻してあげてる
    
//    if (dist < 150) {
//        if(!intLight.getIsMovieDone()){
//            // 動画が終わった時は、何もしない。
//            intLight.play();
//        }
//        bDrawMode = true;
//    }else{
//        // イベントに応じてframe指定してあげればどこからでも再生出来る。setPositionとどっちがいいかは検証次第
//        intLight.setFrame(0);
//        bDrawMode = false;
//    }
    
    if (dist < 150) {
        if (intDark.getIsMovieDone()) {
            cout << "bPlay = false" << endl;
            bPlay = false;
        }
        if (bPlay) {
            if (intDark.getCurrentFrame() == thresFrame) {
                intDark.setFrame(thresFrame + 1);
            }
        }else{
            if (intDark.getCurrentFrame() > thresFrame) {
                cout << "hoge" << endl;
                intDark.setFrame(0);
            }
        }
    }else{
        if (intDark.getCurrentFrame() > thresFrame) {
            intDark.setFrame(0);
        }
        bPlay = true;
    }
    
    ofDrawBitmapString("correntFrame: " + ofToString(intDark.getCurrentFrame()), 20, 20);
    ofDrawBitmapString("thresFrame: " + ofToString(thresFrame), 20, 40);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
        case '+':
            thresFrame++;
            break;
        case '-':
            thresFrame--;
            break;
        default:
            break;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mouse = ofPoint(x, y);
    dist = ofDist(mouse.x, mouse.y, center.x, center.y);
//    cout << dist << endl;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
