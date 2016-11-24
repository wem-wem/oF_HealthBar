
#pragma once
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxXmlSettings.h"


struct PlayerDate {
  int playerNum;  // ƒvƒŒƒCƒ„[”Ô†
  int health; // Œ»İ‚g‚o
  int maxHealth;  // Å‘å‚g‚o
  float currentBarScale; // Œ»İ‚Ì‚g‚oƒo[‚Ì’·‚³
  float maxBarScale;  // Œ³X‚Ì‚g‚oƒo[‚Ì’·‚³
};

class HealthBar {
private:
  enum PlayerNumber {
    PlayerOne = 0,
    PlayerTwo = 1,
  };

  PlayerDate player_;

  ofxPanel gui_;
  ofParameter<ofVec2f> barScale_;
  ofxButton save_;
  ofxButton load_;

  void drawLeft();
  void drawRight();
  void guiSetup();
  void saveFile();
  void loadFile();

  bool test = false;
  float damage = 0;
  void drawDamage(float damageCurrent);

public:
  // ‚g‚oƒo[¶¬‚ÉƒvƒŒƒCƒ„[”Ô†‚ÆÅ‘å‚g‚o‚ğó‚¯æ‚é
  HealthBar(const int playerNum, const int maxHealth);

  void setup();
  void draw();
  void remnant(int damage);
};
