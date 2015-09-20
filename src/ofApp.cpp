#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    vidDefault.loadMovie("intaraction_hugu_default.mov");
    vidAction.loadMovie("intaraction_hugu_action.mov");
    
    vidDefault.play();
//    vidAction.play();
    
    // ループをOFFに設定
    vidAction.setLoopState(OF_LOOP_NONE);

}

//--------------------------------------------------------------
void ofApp::update(){
    vidDefault.update();
    vidAction.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    vidAction.draw(0, 0); //1280*720
    vidDefault.draw(0, 0);
    if (bDrawMode) {
        vidAction.draw(0, 0);
    }
    
    ofNoFill();
    ofRect(ofGetWidth()/2, ofGetHeight()/2-100, 250, 250);
    center = ofPoint(ofGetWidth()/2 + 250/2, ofGetHeight()/2-100 + 250/2);
    ofCircle(center, 10);
    ofLine(mouse, center);
    ofCircle(mouse, 10);
    
    // エリア内に入ったときに、頭からアニメーション再生、ロープOFFなので、１回で終了。エリア外になったときに、フレーム最初に戻してあげてる
    if (dist < 150) {
        if(!vidAction.getIsMovieDone()){
            // 動画が終わった時は、何もしない。
            vidAction.play();
        }
        bDrawMode = true;
    }else{
        // イベントに応じてframe指定してあげればどこからでも再生出来る。setPositionとどっちがいいかは検証次第
        vidAction.setFrame(0);
        bDrawMode = false;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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
