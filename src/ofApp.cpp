
#include "ofApp.h"


void ofApp::setup() {
  ofSetFrameRate(60);
  player_.setup(1, 500);
  bar_.setup(player_);
}

void ofApp::update() {}

void ofApp::draw() {
  bar_.draw(player_);
}

void ofApp::keyPressed(int key) {
  if (key == 'd') {
    player_.damage(25);
  }
}

void ofApp::keyReleased(int key) {}

void ofApp::mouseMoved(int x, int y) {}

void ofApp::mouseDragged(int x, int y, int button) {}

void ofApp::mousePressed(int x, int y, int button) {}

void ofApp::mouseReleased(int x, int y, int button) {}

void ofApp::mouseEntered(int x, int y) {}

void ofApp::mouseExited(int x, int y) {}

void ofApp::windowResized(int w, int h) {}

void ofApp::gotMessage(ofMessage msg) {}

void ofApp::dragEvent(ofDragInfo dragInfo) {}
