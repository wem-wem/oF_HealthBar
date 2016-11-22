
#pragma once
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxXmlSettings.h"


class HealthBar {
protected:
  float currentHealth_[2]; // ÇgÇoÉoÅ[ÇÃå≥ÇÃí∑Ç≥

  ofxPanel gui_;
  ofParameter<ofVec2f> barScale_;
  ofxButton save_;
  ofxButton load_;
public:
  void setup();
  void draw(ofEventArgs &args);

  void drawLeft();
  void drawRight();

  void guiSetup();
  void saveFile();
  void loadFile();
};
