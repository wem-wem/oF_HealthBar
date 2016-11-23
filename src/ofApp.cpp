
#include "ofApp.h"


void ofApp::setup() {
  bar_.setup();
}

void ofApp::update() {}

void ofApp::draw() {
  bar_.draw();
}

void ofApp::keyPressed(int key) {
  if (key == 'd') {
    bar_.remnant(25);
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
