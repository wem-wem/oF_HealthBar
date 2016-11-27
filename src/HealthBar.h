
#pragma once
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxXmlSettings.h"
#include "player.h"

class HealthBar {
private:
  enum PlayerNumber {
    PlayerOne = 0,
    PlayerTwo = 1,
  };
  Player* player_;
  float currentScale; // Œ»İ‚g‚oƒo[‚Ì’·‚³
  float tempHealth; // ƒ_ƒ[ƒW‚ğó‚¯‚é‘O‚Ì‚g‚o‚ğ“ü‚ê‚Ä‚¨‚­” 
  float damageScale;

  ofxPanel gui_;
  ofParameter<ofVec2f> barScale_;
  ofxButton save_;
  ofxButton load_;

  void drawLeft();
  void drawRight();
  void guiSetup();
  void saveFile();
  void loadFile();
  float remnant();
  void setDamageScale();
  void updateLeft();
  void updateRight();
public:
  void setup(Player *player);
  void update(ofEventArgs &args);
  void draw();
};
